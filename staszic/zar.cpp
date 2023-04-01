#include <bits/stdc++.h>

using namespace std;

struct Segm{
    vector<bool> t;
    int k{1};
    Segm(){}
    Segm(int i){
        while(k<i) k*=2;
        t.resize(2*k,false);
    }
    void set(int v, bool val){
        t[v+k] = val;
    }

    void change(int v, int first, int last, int a, int b){
        if(first >= a && last <= b){
            t[v]=!t[v];
            return;
        }

        int mid = (first+last)/2;
        if(a<= mid) change( v*2, first, mid, a,b);
        if(b>mid) change(2*v+1,mid+1, last, a, b);
    }

    bool query(int v, int val, int first, int last, bool ans){
        if(t[v]){
           ans = !ans; 
        }
        if(first == last) return ans;
        int mid = (first+last)/2;
        if(val<=mid) ans = query(2*v,val,first,mid,ans);
        if(val > mid) ans = query(2*v+1, val, mid+1, last,ans);
        return ans;
    }
};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    string z;
    cin>>n>>m>>z;
    Segm s(n);
    for(int i=0; i<n;++i){
        if(z[i]=='o') s.set(i,true);
    }
    
    for(int i=0;i<m;++i){
        char q;
        cin>>q;
        if(q=='Q'){
            int a;
            cin>>a;
            cout<< (s.query(1, a, 1,s.k,false) ? "ON" : "OFF")<< "\n";
        }
        else{
            int a,b;
            cin>>a>>b;
            s.change(1,1,s.k,a,b);
        }
    }

    return 0;
}