#include <bits/stdc++.h>

using namespace std;

vector<int> t;
int k{1};

void create(vector<int> &tab){ // n - liczba elementów w drzewie / ciągu który chcemy reprezentować na drzewie
    while(tab.size()>=k) k*=2;
    t.resize(2*k);

    for(int i=k; i-k<tab.size();++i){
        t[i] = tab[i-k];
    }
    for(int i=k-1; i; --i){
        t[i] = t[2*i] + t[2*i+1];
    }
}

void update(int v){
    if(v==0) return;
    t[v] = t[2*v]+t[2*v+1];
    update(v/2);
}

void insert(int x, int val){
    t[k+x] = val;
    update((k+x)/2);
}

int query(int v, int first, int last, int a, int b){
    /*
    v - wierzchołek w którym się znajdujemy
    first - początek przedziału w którym aktualnie się znajdujemy
    last - analogicznie
    a - początek przedziału którego szukamy
    b - ...
    */
    if(first >= a && last <= b){
        return t[v];
    }

    int mid = (first+last)/2;
    int sum = 0;
    // [1,8]
    // (1+8)/2  --> 4
    if(a<= mid) sum += query(2*v, first, mid, a, b);
    if(b > mid) sum += query(2*v+1, mid+1, last, a, b);
    //szukamy wartości w przedziałach [1,4] oraz [5,8]
    return sum;
}

int main(){
    vector<int> tb = {1,2,3,4};
    create(tb);
    for(auto x : tb){
        cout<<x<<' ';
    }
    cout<<'\n';
    for(auto x : t){
        cout<<x<<' ';
    }
    insert(0,2);
    cout<<'\n';
    for(auto x : t){
        cout<<x<<' ';
    }
    cout<< '\n';
    cout<< query(1, 1, k, 1, k);

    return 0;
}