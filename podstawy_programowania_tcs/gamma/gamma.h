#include <iostream>
#include <stdlib.h>
using namespace std;
class vector{
    private:
    public:
        string *tab;
        int capacity;
        int size;
    public:
        vector(int a=4, int b=0, string c=""){
            capacity=a;
            size=b;
            tab=new string[a];
            for(int i=0;i<b;i++){
                tab[i]=c;
            }
        }
        vector(const vector &nowy){
            size=nowy.size;
            capacity=nowy.capacity;
            tab=new string[capacity];
            for(int i=0;i<size;i++){
                tab[i]=nowy.tab[i];
            }
        }
        ~vector(){
            delete [] tab;
        }
        void add(string x){
            if(size<capacity){
                tab[size]=x;
                size++;
            }
            else{
                if(capacity==0)
                    capacity=1;
                else{
                    capacity=capacity*2;
                }
                string *pom;
                pom=new string[capacity];
                for(int i=0;i<size;i++){
                    pom[i]=tab[i];
                }
                pom[size]=x;
                size++;
                delete [] tab;
                tab=pom;
            }
        }
        int getSize(){
            return size;
        }
        void resize(int s){
            if(s==0){
                capacity=0;
                size=0;
                return;
            }
            if(s<size){
                string *pom;
                pom= new string[s];
                for(int i=0;i<s;i++){
                    pom[i]=tab[i];
                }
                delete [] tab;
                tab=pom;
            }
            if(s>size){
                string *pom;
                pom= new string[s];
                for(int i=0;i<size;i++){
                    pom[i]=tab[i];
                }
                for(int i=size;i<s;i++){
                    pom[i]="";
                }
                delete [] tab;
                tab=pom;
            }
            capacity=s;
            size=s;
        }
        void clear(){
            size=0;
        }
        void insert(int i, string x){
            if(i>size)
                return;
            add("");
            for(int j=size-1;j>i;j--){
                tab[j]=tab[j-1];
            }
            tab[i]=x;
        }
        void erase(int i){
            if(i>=size){
                return;
            }
            for(int j=i;j<size-1;j++){
                tab[j]=tab[j+1];
            }
            size--;
        }
        string& operator[](int i){
            if(i>=size){
                return tab[size-1];
            }
            return tab[i];
        }
        vector& operator=(const vector &nowy){
            if(this==&nowy)
                return *this;
            delete [] tab;
            capacity=nowy.capacity;
            size=nowy.size;
            tab= new string[capacity];
            for(int i=0;i<size;i++){
                tab[i]=nowy.tab[i];
            }
            return *this;
        }
     
        operator bool(){
            return (size!=0);
        }
        bool operator!(){
            return (size==0);
        }
};


istream& operator>>(istream& stream, vector& a){
    // cout<<"CINSTART"<<endl;
    for(int i=0;i<a.size;i++){
        // cout<<"CIN"<<i<<endl;
        stream>>a.tab[i];
        // cout<<"CINL"<<endl;
    }
    return stream;
}
ostream& operator<<(ostream& stream, vector& a){
    for(int i=0;i<a.size;i++){
        stream<<a.tab[i]<<" ";
    }
    return stream;
}