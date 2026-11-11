#include <iostream>
#include <stdexcept>
#include <string>
class Time {
public: int h,m,s;
    Time(int hh=0,int mm=0,int ss=0):h(hh),m(mm),s(ss){ normalize(); }
    void normalize(){ int total=h*3600+m*60+s; if(total<0) total=0; h=total/3600; m=(total%3600)/60; s=total%60; }
    Time& operator++(){ ++s; normalize(); return *this; }
    Time operator++(int){ Time old=*this; ++(*this); return old; }
    bool operator==(const Time& x)const{return h==x.h&&m==x.m&&s==x.s;}
    bool operator<(const Time& x)const{return h*3600+m*60+s<x.h*3600+x.m*60+x.s;}
};
class Playlist {
    std::string* tracks; int n;
public:
    explicit Playlist(int count):tracks(new std::string[count]),n(count){}
    ~Playlist(){delete[] tracks;}
    Playlist(const Playlist&)=delete; Playlist& operator=(const Playlist&)=delete;
    std::string& operator[](int i){if(i<0||i>=n) throw std::out_of_range("track index"); return tracks[i];}
    const std::string& operator[](int i)const{if(i<0||i>=n) throw std::out_of_range("track index"); return tracks[i];}
};
int main(){ Time t(0,59,59); Time a=t++; Time b=++t; std::cout<<a.h<<':'<<a.m<<':'<<a.s<<' '<<b.h<<':'<<b.m<<':'<<b.s<<' '<<t.h<<':'<<t.m<<':'<<t.s<<'\n'; Playlist p(2); p[0]="Intro"; p[1]="Finale"; std::cout<<p[0]<<' '<<p[1]<<'\n'; try{std::cout<<p[2];}catch(const std::out_of_range& e){std::cout<<"Range error: "<<e.what()<<'\n';}}
