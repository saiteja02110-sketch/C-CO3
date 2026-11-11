#include <cmath>
#include <iostream>
#include <stdexcept>
class Complex {
    double re,im;
public:
    Complex():re(0),im(0){}
    Complex(double r):re(r),im(0){}
    Complex(double r,double i):re(r),im(i){}
    double real()const{return re;} double imag()const{return im;}
    double magnitude()const{return std::hypot(re,im);}
    Complex operator+(const Complex& z)const{return {re+z.re,im+z.im};}
    Complex operator-(const Complex& z)const{return {re-z.re,im-z.im};}
    Complex operator*(const Complex& z)const{return {re*z.re-im*z.im,re*z.im+im*z.re};}
    Complex operator/(const Complex& z)const{double d=z.re*z.re+z.im*z.im;if(d==0)throw std::domain_error("division by zero impedance");return {(re*z.re+im*z.im)/d,(im*z.re-re*z.im)/d};}
    bool operator==(const Complex& z)const{return re==z.re&&im==z.im;}
    friend std::ostream& operator<<(std::ostream& os,const Complex& z){return os<<z.re<<(z.im<0?" - j":" + j")<<std::abs(z.im);}
};
int main(){
    const double R=10.0, XL=5.0, XC=8.0;
    Complex zr(R), zl(0,XL), zc(0,-XC);
    Complex series=zr+zl+zc;
    Complex parallel=(zr*zl)/(zr+zl);
    std::cout<<"Series RLC: "<<series<<" |Z|="<<series.magnitude()<<'\n';
    std::cout<<"Parallel R-L: "<<parallel<<" |Z|="<<parallel.magnitude()<<'\n';
    try{std::cout<<(zr/Complex())<<'\n';}catch(const std::domain_error& e){std::cout<<"Safe error: "<<e.what()<<'\n';}
}