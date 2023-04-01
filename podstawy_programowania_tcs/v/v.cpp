#include <iostream>

using namespace std;

class stack{
    int size;
    int element;
    long long *tab;
public:
    stack();
    stack(int size);
    ~stack();
    void push(const long long &x);
    long long pop();
    long long top();
    bool empty();
    bool full();
    void clear();
    void resize(int n);
};

class point{
    int x,y;
public:   
    point();
    point(int x, int y);

    int getX();
    int getY();
    void print();
};

class queue{
    int size;
    int first,last;
    point *tab;
public:
    queue();
    queue(int n);
    ~queue();
    void enqueue(const point& x);
    point dequeue();
    point front();
    bool empty();
    bool full();
    void clear();
    void resize(int n);
};

// STACK

stack::stack(int size){
    this->size = size, element = 0;
    tab = new long long[size];
}
stack::stack() : stack(15){}
stack::~stack(){
    delete[] tab;
}
void stack::push(const long long &x){
    if(full()) throw string("PUSH");
    tab[element++]=x;
}
long long stack::pop(){
    if(empty()) throw string("POP");
    return tab[--element];
}
long long stack::top(){
    if(empty()) throw string("TOP");
    return tab[element-1];
}
bool stack::empty(){
    return (element==0);
}
bool stack::full(){
    return element==size;
}
void stack::clear(){
    element=0;
}
void stack::resize(int n){
    if(n<=size) return;
    size = n;
    long long *nt = new long long[n];
    for(int i=0;i<element;++i){
        nt[i] = tab[i];
    }
    delete[] tab;
    tab = nt;
}   

// POINT
point::point(){
    x=0,y=0;
}
point::point(int x, int y){
    this->x=x, this->y=y;
}
int point::getX(){
    return x;
}
int point::getY(){
    return y;
}
void point::print(){
    cout<<x<<' '<<y<<'\n';
}

//QUEUE
queue::queue(int n){
    first=last=0;
    size=n;
    tab = new point[n];
}
queue::queue() : queue(15){}
queue::~queue(){
    delete[] tab;
}
void queue::enqueue(const point& x){
    if(full()) throw string("ENQUEUE");
    if(last == size){
        for(int i=first; i<last;++i) 
            tab[i-first] = tab[i];
        last-=first;
        first=0;
    }
    tab[last++]=x;
}
point queue::dequeue(){
    if(empty()) throw string("DEQUEUE");
    return tab[first++];
}
bool queue::empty(){
    return first==last;
}
point queue::front(){
    if(empty()) throw string("FRONT");
    return tab[first];
}
bool queue::full(){
    return (last==size && first==0);
}
void queue::clear(){
    last=first=0;
}

void queue::resize(int n){
    if(n<=size) return;
    point *nt = new point[n];
    size=n;
    
    for(int i=first;i<last;++i){
        nt[i-first]=tab[i];
    }
    last-=first;
    first=0;
    delete[] tab;
    tab = nt;
}
