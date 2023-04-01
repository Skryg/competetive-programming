#include <iostream>
#include <cassert>

using namespace std;

template<typename T>
class Container{
protected:
    int size=0, capacity;
    int begin = 0,end = 0;
    T* tab;
public: 
    Container(int capacity = 4){
        this->capacity = capacity;
        tab = new T[capacity];
    }

    ~Container(){
        delete[] tab;
    }

protected:
    void resize(int n, bool front=false){
        if(n>capacity){
            int cap = capacity;
            while(n>capacity) capacity<<=1;
            T* temp = new T[capacity];
            for(int i=0, j=begin; i<size; ++i, ++j, j%=cap){
                temp[i] = tab[j];
            }
            delete[] tab;
            tab = temp;
            begin = 0; end = n;
        }
        else{
            int diff = n-size;
            if(!front){
                if(diff>0){
                    for(int i=end, j=0; j<diff; ++i, i%=capacity, ++j) tab[i] = T();
                }
                end = (end+diff+capacity)%capacity;
            }
            else{
                int beginNew = (begin-diff+capacity)%capacity;
                if(diff>0){
                    for(int i = beginNew, j=0; j<diff; ++i, i%=capacity, ++j) tab[i]=T();
                }
                begin = beginNew;
            }
        }
        size = n;
    }
    
    void push_back(T &t){
        resize(size+1);
        tab[(end-1+capacity)%capacity] = t;
        
    }

    bool pop_back(){
        if(empty()) return false; 
        resize(size-1);
        return true;
    }
public:
    int getSize(){
        return size;
    }

    bool empty(){
        return size==0;
    }

    void clear(){
        resize(0);
    }
};

template<typename T> 
class Stack : public Container<T> {
public:
    Stack(int n=4) : Container<T>{n} {}

    void push(T &t){
        this->push_back(t);
        
    }

    bool pop(){
        if(this->empty()) return false;
        this->pop_back();
        return true;
    }

    T top(){
        assert(this->size>0);
        return this->tab[((this->end)-1+this->capacity)%this->capacity];
    }
};

template<typename T>
class Queue : public Container<T> {
public:
    Queue(int n=4) : Container<T>{n} {}

    void enqueue(T &t){
        this->push_back(t);
    }

    bool dequeue(){
        if(this->empty()) return false; 
        this->resize(this->size-1,true);
        return true;
    }

    bool pop_back(){
        return Container<T>::pop_back();
    }

    T front(){
        return this->tab[this->begin];
    }

    T back(){
        return this->tab[(this->end-1+this->capacity)%this->capacity];
    }

};

template<typename C, typename O>
class stackMin{
    Stack<C> *s, *sMin;
public:
    stackMin(int a=4){
        s = new Stack<C>(a);
        sMin = new Stack<C>(a);
    }

    ~stackMin(){
        delete s;
        delete sMin;
    }

    void push(C x){
        s->push(x);
        
        C top;
        O o;
        if(sMin->empty() || (!sMin->empty() && !o(top = sMin->top(),x))){
            sMin->push(x);
        }
    }

    C top(){
        return s->top();
    }

    C min(){
        return sMin->top();
    }

    void clear(){
        s->clear();
        sMin->clear();
    }

    bool pop(){
        if(!s->empty() && !sMin->empty() && s->top() == sMin->top()){
            s->pop();
            sMin->pop();
            return true;
        }
        return s->pop();
    }

    bool empty(){
        return s->empty();
    }

    int size(){
        return s->getSize();
    }
};

template<typename C, typename O>
class queueMin{
    Queue<C> *que, *queMin;

public:
    queueMin(int a=4){
        que = new Queue<C>(a);
        queMin = new Queue<C>(a);
    }

    ~queueMin(){
        delete que;
        delete queMin;
    }

    void enqueue(C x){
        que->enqueue(x);
        
        C back;
       // if(!queMin->empty()) back = queMin->back();
        O o;
        while(!queMin->empty() && o(x, back = queMin->back())){
            //cout<<" back "<<back;
            queMin->pop_back();
        }
        queMin->enqueue(x);
    }

    bool dequeue(){
        if(!queMin->empty() && !que->empty() && queMin->front() == que->front()){
            queMin->dequeue();
            que->dequeue();
            return true;
        }
        return que->dequeue();
    }

    C front(){
        return que->front();
    }

    C min(){
        return queMin->front();
    }

    void clear(){
        que->clear();
        queMin->clear();
    }

    bool empty(){
        return que->empty();
    }


};

template<typename C>
class myPair{
public:
    C first, second;
};

template<typename C, typename O>
void solveStack(stackMin<C,O> &S, int n){
    while(n--){
        string s; cin>>s;
        if(s=="push"){
            C c;
            cin>>c;
            S.push(c);
        }
        else if(s=="pop"){
            if(S.empty()) cout<<"ERROR\n";
            else{
                cout<<S.top()<<'\n';
                S.pop();
            }
        }
        else if(s=="top"){
            if(S.empty())
                cout<< "EMPTY\n";
            else
                cout<<S.top() << '\n';
        }
        else if(s=="min"){
            if(S.empty())
                cout<<"EMPTY\n";
            else 
                cout<<S.min()<<'\n';
        }
        else if(s=="clear"){
            S.clear();
        }
        else if(s=="empty"){
            cout << (S.empty() ? "YES" : "NO") << '\n';
        }
    }
}

template<typename C, typename O>
void solveQueue(queueMin<C,O> &S, int n){
    while(n--){
        string s; cin>>s;
        if(s=="enqueue"){
            C c;
            cin>>c;
            S.enqueue(c);
        }
        else if(s=="dequeue"){
            if(S.empty()) cout<<"ERROR\n";
            else{
                cout<<S.front()<<'\n';
                S.dequeue();
            }
        }
        else if(s=="front"){
            if(S.empty())
                cout<< "EMPTY\n";
            else cout<< S.front() << '\n';
        }
        else if(s=="min"){
            if(S.empty())
                cout<< "EMPTY\n";
            else cout<<S.min()<<'\n';
        }
        else if(s=="clear"){
            S.clear();
        }
        else if(s=="empty"){
            cout << (S.empty() ? "YES" : "NO") << '\n';
        }
    }
}