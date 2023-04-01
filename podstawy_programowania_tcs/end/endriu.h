#include <iostream>
#include <ostream>
#include <stdio.h>
#include <string.h>
using namespace std;
class vector{
    private:
    string*tab=nullptr;
    int capacity;
    int size;
    public:
    vector(int a=4, int b=0, string c="")
    {
        if(a<=0) a=4;
        if(b>a) b=a;
        if(tab==nullptr)tab = new string[a];
        size=b;
        capacity=a;
        for(int i=0; i<size; i++)
        {
            tab[i] = c;
        }
    }
    vector(const vector& A)
    {
        if(&A==this) return;
        copyVector(A);
    }
    ~vector()
    {
        if(tab!=nullptr) delete []tab;
    }
    void add(string x)
    {
        while(size>=capacity) changeCap(capacity*2);
        tab[size] = x;
        size++;
        return;
    }
    int getSize()
    {
        return size;
    }
    void changeCap(int s)
    {
        string*newTab = new string[s];
        capacity=s;
        for(int i=0; i<size && i<capacity; i++)
        {
            newTab[i] = tab[i];
        }
        delete[] tab;
        tab = newTab;
        return;
    }
    void resize(int s)
    {
        while(s>=capacity) changeCap(2*capacity);
        for(int i=size; i<s; i++)
        {
            tab[i] = "";
        }
        size=s;
    }
    void clear()
    {
        size=0;
    }
    void insert(int i, string x)
    {
        if(i>size) return;
        while(size>=capacity) changeCap(2*capacity);
        for(int j=size; j>i;j--)
        {
            tab[j] = tab[j-1];
        }
        tab[i] = x;
        size++;
        return;
    }
    void erase(int i)
    {
        if(i>=size ) return;
        for(int j=i; j<size; j++)
        {
            tab[j] = tab[j+1];
        }
        size--;
    }
    string& operator[](int i)
    {
        if(i>=size)
        {
            if(size==0) return tab[size];
            return tab[size-1];
        } 
        return tab[i];
    }
    friend ostream &operator<<(ostream &stream, const vector &A)
    {
        for(int i=0; i<A.size; i++)
        {
            stream<<A.tab[i]<<" ";
        }
        return stream;
    }
    void copyVector(const vector&A)
    {
        size=A.size;
        capacity=A.capacity;
        if(tab==nullptr) tab = new string[capacity];
        for(int i=0; i<size ; i++)
        {
            tab[i] = A.tab[i];
        }
        return;
    }
    vector operator=(const vector& A)
    {
        if(&A==this) return *this;
        delete []tab;
        tab=nullptr;
        copyVector(A);
        return *this;
    }
    friend istream &operator>>(istream &stream,  vector &A)
    {
        for(int i=0; i<A.size; i++)
        {
            stream>>A.tab[i];
        }
        return stream;
    }
    operator bool()
    {
        if(size!=0) return true;
        return false;
    }
    bool operator !()
    {
        if(size==0) return true;
        return false;
    }
};