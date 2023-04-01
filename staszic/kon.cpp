#include <bits/stdc++.h>

using namespace std;

struct Segm{
    vector<int> t; 
    int k{1};
    Segm(){}
    Segm(int i){
        while(i>k) k*=2;
        t.resize(2*k);
    }

    void refresh(int v){
        if(v==0) return;
        t[v] = t[2*v]+t[2*v+1];
        refresh(v/2);
    }

    void insert(int v, int val){
        t[v+k]=val;
        refresh((v+k)/2);
    }
    
    int query(int v, int first, int last, int a, int b){
        if(first >= a && last <= b){
            return t[v];
        }

        int mid = (first+last)/2;
        int ans{0};
        if(a<=mid) ans+= query(2*v, first, mid, a, b);
        if(b>mid) ans+= query(2*v+1, mid+1, last, a, b);
        return ans;
    }

};

struct Max{
    

    vector<int> sum;
    vector<int> to_add;
    int k{1};

    Max(){}
    Max(int i){
        while(i>k) k*=2;
        sum.resize(2*k);
        to_add.resize(2*k);

    }

    void add(int v, int hm){
        sum[v] += hm;
        to_add[v]+=hm;
    }

    void push(int v){
        add(2*v, to_add[v]);
        add(2*v+1, to_add[v]);
        to_add[v]=0; 
    }

    void refresh(int v){
        if(v==0) return;
        sum[v] = max(sum[2*v], sum[2*v+1]);
        refresh(v/2);
    }

    int del(int v, int val, int first, int last){
        if(first == last){
            sum[v]=INT_MIN;
            refresh(v/2);
            return first;
        }
        int mid = (first+last)/2;
        push(v);
        if(val==sum[2*v]) return del(2*v, val, first, mid);
        if(val==sum[2*v+1]) return del(2*v+1, val, mid+1, last);
        return 0;
    }

    void insert(int v, int val, int first, int last, int a, int b){
        if(first >= a && last <= b){
            add(v, val);
            refresh(v/2);
            return;
        }
        push(v);
        int mid = (first+last)/2;
        if(a<= mid) insert(2*v, val, first, mid, a, b);
        if(b > mid) insert(2*v+1, val, mid+1, last, a, b);

    }

    
};
Max t_mx;
Segm t_segm;
int k_val{0};
void inicjuj(int n, int k, int *D){
    t_mx = Max(n);
    t_segm = Segm(n);
    k_val = k;
    for(int i=0;i<n;++i){
        t_mx.insert(1, D[i],0, t_mx.k-1,i,i);
    }
}

void podlej(int a, int b){
    t_mx.insert(1, 1, 0, t_mx.k-1, a,b);
}

int dojrzale(int a, int b){
    while(t_mx.sum[1] >= k_val){
        int x = t_mx.sum[1];
        int y = t_mx.del(1,x,0, t_mx.k-1);
        t_segm.insert(y,1);
    }

    return t_segm.query(1, 0, t_segm.k-1, a,b);
}

int main(){
    int D[4]={5,4,3,7};
    inicjuj(4, 6, D);
    cout << dojrzale(2, 3)<< "\n";
    podlej(0, 2);
    cout<< dojrzale(1, 2)<<"\n";
    podlej(2, 3);
    podlej(0, 1);
    cout<< dojrzale(0, 3)<<"\n";
    return 0;
}