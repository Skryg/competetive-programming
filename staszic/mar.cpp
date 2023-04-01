#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct Max{
    vector<ll> t;
    vector<ll> to_add;
    int k{1};

    Max(){}
    Max(int i){
        while(k<i)k*=2;
        t.resize(2*k);
        to_add.resize(2*k);
    }
    void refresh(int v){
        if(v==0) return;
        t[v]=max(t[v*2],t[v*2+1]);
        refresh(v/2);
    }
    void add(int v,  ll hm){
        if(t[v]==0) return;
        to_add[v]+=hm;
        t[v]+=hm;
    }

    void set(int v, ll hm){
        t[v]=hm;
    }

    void push(int v){
        add(2*v, to_add[v]);
        add(2*v+1, to_add[v]);
        to_add[v]=0;
    }

    void insert(int v, ll val, int first, int last, int a, int b, char ex, char st){
        if(first >= a && last<= b){
            if(st) set(v,val);
            else if(ex || t[v]!=0) add(v,val);
            
            refresh(v/2);
            return;
        }
        if(!ex && t[v]==0) return;
        push(v);
        int mid = (last+first)/2;
        if(a<=mid) insert(2*v, val, first, mid, a,b,ex,st);
        if(b>mid) insert(2*v+1, val, mid+1, last, a, b,ex,st);
        
    }

    ll del(int v, ll val, int first, int last){
        if(first == last){
            t[v] = 0;
            refresh(v/2);
            return first;
        }
        push(v);
        int mid = (first+last)/2;
        if(t[2*v]==val) return del(2*v,val,first, mid);
        else return del(2*v+1, val, mid+1, last);
    }

};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m, g2, g1;
    cin>>n>>m>>g2>>g1;
    ll stage1{0},stage2{0};
    Max max1 = Max(n);
    Max max2 = Max(n);
    for(int i=max1.k;i<n+max1.k;++i){
        ll a;
        cin>>a;
        max1.set(i,a);
    }
    for(int i=max1.k-1;i>0;--i){
        max1.t[i] = max(max1.t[2*i],max1.t[2*i+1]);
    }
    for(int i=0; i<m; ++i){
        int a,b;
        ll x;
        cin>>a>>b>>x;
        max1.insert(1,1,1, max1.k,1,max1.k,false,false);
        max2.insert(1,1,1, max2.k,1,max2.k,false,false);
        max1.insert(1,x,1, max1.k,a,b,false,false);
        max2.insert(1,x,1, max2.k,a,b,false,false);
        while(max1.t[1]>=g2){
            ll d = max1.t[1];
            int pos = max1.del(1,d, 1, max1.k);
            ++stage1;
            max2.insert(1,d,1,max2.k,pos,pos, true,true);
        }
        while(max2.t[1]>=g1){
            ll d = max2.t[1];
            int pos = max2.del(1,d,1,max2.k);
            ++stage2;
            --stage1;
        }
        cout<<stage2<<" "<<stage1<<"\n";
    }
    return 0;
}