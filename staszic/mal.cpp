#include <bits/stdc++.h>

using namespace std;

struct Segm{
    struct Vert{
        int val{0};
        bool red{false}, change{false};
        int first{INT_MAX},last{INT_MAX};
    };

    int k{1};
    vector<Vert> t;
    Segm(){}

    void refresh(int v){
        if(v==0) return;
        t[v].val = t[2*v].val + t[2*v+1].val;
        
        refresh(v/2);
    }

    Segm(int n){
        while(k<n) k*=2;
        t.resize(2*k);

        
    }
    void prepare(){
        for(int i=k; i<2*k;++i){
            t[i].val = t[i].last - t[i].first +1;
            refresh(i/2);
        }
    }

    void add(int v, int l){
        t[v].red = !t[v].red;
        t[v].change = !t[v].change;
        t[v].val = l-t[v].val;
    
    }

    void push(int v){
        if(t[v].change){
            t[v].change = false;
            add(2*v, t[v*2].last - t[v*2].first+1);
            add(2*v+1,t[2*v+1].last - t[v*2+1].first+1);
        }
    }

    void insert(int v, int a, int b){
        if(t[v].first >= a && t[v].last <= b){
            add(v, t[v].last-t[v].first+1);
            refresh(v/2);
            return;
        }

        push(v);

        
        if(a<=t[2*v].last) insert(2*v, a, b);
        if(b>=t[2*v+1].first) insert(2*v+1, a,b); 
    }
    int query(int v, int a, int b){
        if(t[v].first >= a && t[v].last <= b){
            return t[v].val;
        }

        push(v);
        int ans{0};
      
        if(a<=t[2*v].last) ans+=query(2*v, a, b);
        if(b>=t[2*v+1].first) ans+=query(2*v+1, a,b);
        return ans; 
    }

};

struct Q{
    char c;
    int a,b;
};
set<int> it;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    
    vector<Q> queries;
    queries.resize(m);

    for(int i=0;i<m;++i){
        
        cin>>queries[i].c>>queries[i].a>>queries[i].b;
        it.insert(queries[i].a);
        it.insert(queries[i].b+1);

    }
    Segm s = Segm(it.size());
    auto ite = it.begin();
    auto endit = it.end();
    --endit;
    int vx{s.k};
    while(ite != endit){
        s.t[vx].first = *ite;
        ++ite;
        s.t[vx].last = *ite -1;
        ++vx;
    }
    for(int i=s.k-1; i>0; --i){
        s.t[i].first = s.t[2*i].first;
        s.t[i].last = s.t[2*i+1].last;
    }
    s.prepare();
    for(int i=0;i<m;++i){
        if(queries[i].c=='?'){
            cout << s.query(1, queries[i].a, queries[i].b) << "\n";
        }
        else {
            s.insert(1, queries[i].a, queries[i].b);
        }
    }
    return 0;
}