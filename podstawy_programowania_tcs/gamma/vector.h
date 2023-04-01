#include <iostream>

using namespace std;

class vector{
    string *tab=nullptr;
    int capacity;
    int size;
public:
    vector(int a = 4, int b = 0, string c = ""){
        if(a<1) a=1;
        if(b<0) b=0;
        tab = new string[a];
        capacity = a;
        size = b;
        for(int i=0;i<b;++i) tab[i]=c;
    }

    vector(const vector &x){
        capacity = x.capacity;
        size = x.size;
        tab = new string[capacity];
        for(int i=0;i<capacity;++i) tab[i]=x.tab[i];
    }

    ~vector(){
        if(tab!=nullptr) delete[] tab;
        tab = nullptr;
    }

    void resize(int n){
        if(n<0) n=0;
        if(capacity < n){
            while(capacity < n){
                capacity *= 2;
            }
            string *temp = new string[capacity];
            for(int i=0; i<size;++i){
                temp[i] = tab[i];
            }
            delete[] tab;
            tab = temp;
        }
        for(int i=size; i<n;++i){
            tab[i]="";
        }
        size = n;

    }

    void add(string s){
        resize(size+1);
        tab[size-1]=s;
    }

    int getSize(){
        return size;
    }

    void clear(){
        size=0;
    }

    void insert(int i, string s){
        if(i>size) return;
        resize(size+1);
        for(int j = size-1; j>i;--j){
            tab[j]=tab[j-1];
        }
        tab[i]=s;
    }

    void erase(int i){
        if(i>=size) return;
        for(int j=i; j<size-1; j++){
            tab[j]=tab[j+1];
        }
        resize(size-1);
    }

    string& operator[](int index){
        if(index >= size) return tab[size-1];
        return tab[index];
    }

    void operator=(const vector &v){
        if(this->tab == v.tab) return;
        if(tab!=nullptr) delete[] tab;
        size = v.size;
        capacity = v.capacity;
        tab = new string[capacity];
        for(int i=0;i<size;++i){
            tab[i]=v.tab[i];
        }

    }

    operator bool(){
        return size!=0;
    }

    bool operator!(){
        return size==0;
    }
    
    friend ostream& operator<<(ostream &stream, const vector &v);
    friend istream& operator>>(istream &stream, const vector &v);
};

ostream& operator<<(ostream &stream, const vector &v){
    for(int i=0;i<v.size;++i){
        stream<<v.tab[i]<<' ';
    }
    return stream;
}

istream& operator>>(istream &stream, const vector &v){
    for(int i=0;i<v.size;++i){
        stream>>v.tab[i];
    }
    return stream;
}

