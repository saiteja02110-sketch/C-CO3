#include <iostream>
#include <string>
class Event {
    int rows, seats;
    char** map;
public:
    Event(int r,int s):rows(r),seats(s),map(r>0?new char*[r]:nullptr){
        for(int i=0;i<rows;++i){ map[i]=new char[seats]; for(int j=0;j<seats;++j) map[i][j]='.'; }
        std::cout<<"Created "<<rows<<"x"<<seats<<'\n';
    }
    Event(const Event&)=delete; Event& operator=(const Event&)=delete;
    ~Event(){ for(int i=0;i<rows;++i) delete[] map[i]; delete[] map; std::cout<<"Closed "<<rows<<"x"<<seats<<'\n'; }
    bool book(int r,int s){ if(r<0||r>=rows||s<0||s>=seats||map[r][s]=='X') return false; map[r][s]='X'; return true; }
    bool cancel(int r,int s){ if(r<0||r>=rows||s<0||s>=seats||map[r][s]!='X') return false; map[r][s]='.'; return true; }
};
int main(){
    Event local(2,3); local.book(0,1); local.cancel(0,1);
    { Event block(1,2); block.book(0,0); }
    Event* heap=new Event(2,2); heap->book(1,1); delete heap;
    Event zero(0,5);
}