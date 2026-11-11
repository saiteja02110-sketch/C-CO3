#include <iomanip>
#include <iostream>
class Money {
    long long paise;
public:
    Money(long long rupees=0,int p=0):paise(rupees*100+p){}
    Money operator+(const Money& rhs) const { return Money(0, static_cast<int>(paise+rhs.paise)); }
    bool operator==(const Money& rhs) const { return paise==rhs.paise; }
    Money operator-(const Money& rhs) const { return Money(0, static_cast<int>(paise-rhs.paise)); }
    Money& operator+=(const Money& rhs){ paise+=rhs.paise; return *this; }
    bool operator<(const Money& rhs) const { return paise<rhs.paise; }
    friend std::ostream& operator<<(std::ostream& os,const Money& m){
        long long v=m.paise; if(v<0) os<<"-Rs "<<(-v)/100<<'.'<<std::setw(2)<<std::setfill('0')<<(-v)%100;
        else os<<"Rs "<<v/100<<'.'<<std::setw(2)<<std::setfill('0')<<v%100;
        return os;
    }
};
int main(){ Money a(120,75),b(79,25); Money c=a+b; std::cout<<c<<'\n'<<std::boolalpha<<(c==Money(200))<<'\n'; std::cout<<(Money(0,75)+Money(0,50))<<'\n'; }