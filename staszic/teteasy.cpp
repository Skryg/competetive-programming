#include <bits/stdc++.h>

#define ST first
#define ND second
#define LT last
using namespace std;

typedef long long ll;

struct MaxT{
    struct Vert{
        int first{1000000001}, last{1000000001};
        ll val{0};
    };
    int k{1};
    vector<Vert> t;
    vector<ll> to_add;
    MaxT(){}
    MaxT(int i){
        while(i>k) k*=2;
        t.resize(2*k);
        to_add.resize(2*k);
    }

    void add(int v, ll hm){
        to_add[v]=hm;
        t[v].val = max(t[v].val, hm);
    }

    void push(int v){
        if(to_add[v]==0) return;
        add(2*v, to_add[v]);
        add(2*v+1, to_add[v]);       
        to_add[v]=0;
    }

    void refresh(int v){
        if(v==0) return;
        t[v].val = max(t[v].val, max(t[v*2].val, t[2*v+1].val));
        refresh(v/2);
    }

    void insert(int v, ll val, int a, int b){
        if(t[v].ST >= a && t[v].LT <= b){
            add(v, val);
            refresh(v/2);
            return;
        }
        push(v);
        if(a <= t[2*v].LT) insert(2*v, val, a,b);
        if(b>= t[2*v+1].ST) insert(2*v+1, val, a,b);
    }

    ll query(int v, int a, int b){
        if(t[v].ST >= a && t[v].LT <= b){
            return t[v].val;
        }
        push(v);
        ll ans{0LL};
        if(a <= t[2*v].LT) ans = max(ans, query(2*v, a,b));
        if(b>= t[2*v+1].ST) ans = max(ans, query(2*v+1,a,b));
        return ans;
    }
};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    set<int> inter;
    
    int d,n;
    cin>>d>>n;
    vector<pair<int, pair<int,int>>> queries(n);
    for(int i=0;i<n;++i){
        int a,b;
        cin>>a>>b;
     
        queries[i].ND = {b,a+b-1};
        inter.insert(b);
        inter.insert(b+a);
    }
    MaxT mxt = MaxT(inter.size());
    auto it = inter.begin();
    auto it2 = inter.end();
    --it2;
    int v{mxt.k};
    while(it != it2){
        mxt.t[v].first = *it;
        ++it;
        mxt.t[v].last = *it-1;
        ++v;
    }
    for(int i=mxt.k-1;i>0;--i){
        mxt.t[i].ST = mxt.t[2*i].ST;
        mxt.t[i].LT  = mxt.t[2*i+1].LT;
    }
    for(int i=0;i<queries.size();++i){
        ll h = mxt.query(1,queries[i].ND.ST, queries[i].ND.ND);
        mxt.insert(1, h+1, queries[i].ND.ST, queries[i].ND.ND);
    }
    cout<<mxt.t[1].val;
    return 0;
}