#include <cstring>
#include <iostream>
class Text {
    char* data;
public:
    explicit Text(const char* s=""):data(new char[std::strlen(s)+1]){std::strcpy(data,s);}
    Text(const Text& o):data(new char[std::strlen(o.data)+1]){std::strcpy(data,o.data);}
    Text& operator=(const Text& o){if(this!=&o){char* p=new char[std::strlen(o.data)+1];std::strcpy(p,o.data);delete[] data;data=p;}return *this;}
    ~Text(){delete[] data;}
    Text& operator+=(const Text& o){char* p=new char[std::strlen(data)+std::strlen(o.data)+1];std::strcpy(p,data);std::strcat(p,o.data);delete[] data;data=p;return *this;}
    friend Text operator+(const Text& a,const Text& b){Text result(a);result+=b;return result;}
    bool operator==(const Text& o)const{return std::strcmp(data,o.data)==0;}
    bool operator!=(const Text& o)const{return !(*this==o);}
    friend std::ostream& operator<<(std::ostream& os,const Text& t){return os<<t.data;}
};
int main(){Text a("Hello "),b("C++"),c("!"); Text d=a+b+c; std::cout<<d<<'\n'; Text empty; empty=empty; std::cout<<'['<<empty<<"] "<<std::boolalpha<<(a!=b)<<'\n';}
