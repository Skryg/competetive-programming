#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

pair<ll,ll> operator+(const pair<ll,ll>& p1, const pair<ll,ll>& p2){
    return {p1.first + p2.first, p1.second + p2.second};
}

struct segm{
    vector<pair<ll,ll>> t;
    vector<pair<ll,ll>> lazy;
    int k{1};

    segm(int n){
        while(k<=n) k*=2;
        t.resize(2*k);
        lazy.resize(2*k);
    }

    void push(int v){
        t[v] = t[v] + lazy[v];
        if(v<k){
            lazy[2*v] = lazy[2*v]+lazy[v];
            lazy[2*v+1] = lazy[2*v+1]+lazy[v];
        }
        lazy[v]={0,0};
    }

    void insert(int v, int first, int last, int a, int b, pair<ll,ll> val){
        if(a<=first && b>=last){
            lazy[v] = lazy[v]+val;
            return;
        }
        push(v);
        int mid = (first+last)/2;
        if(a <= mid) insert(2*v, first, mid, a, b, val);
        if(b > mid) insert(2*v+1, mid+1, last, a, b, val);
    }

    pair<ll,ll> query(int v, int first, int last, int a, int b){
        if(a<=first && b>=last){
            push(v);
            return t[v];
        }
        push(v);
        int mid = (first+last)/2;
        if(a <= mid) return query(2*v, first, mid, a, b);
        else return query(2*v+1, mid+1, last, a, b);
    }

};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int z; cin>>z;
    while(z--){
        int n,q; cin>>n>>q;
        vector<vector<int>> tree(n+1);
        for(int i=0;i<n-1;++i){
            int x,y;
            cin>>x>>y;
            tree[x].push_back(y);
            tree[y].push_back(x);
        }
        vector<ll> depth(n+1);
        vector<int> post(n+1);
        vector<int> mi(n+1);
        int cnt=0;
        function<void(int,int,int)> dfs = [&](int v, int p, int d){
            depth[v] = d;
            mi[v] = INT_MAX;
            for(auto w : tree[v]){
                if(w==p) continue;
                dfs(w,v,d+1);
                mi[v] = min(mi[v], mi[w]);
            }
            post[v] = ++cnt;
            mi[v] = min(post[v], mi[v]);
        };
        dfs(1,0,1);
        segm seg(n+1);

        while(q--){
            int type; cin>>type;
            if(type==1){
                ll x,d; cin>>x>>d;
                seg.insert(1, 1, seg.k, mi[x], post[x], {d-depth[x]*d,d});
            }
            if(type==2){
                int x; cin>>x;
                auto [a,b] = seg.query(1,1,seg.k,post[x],post[x]);
                cout<<a+b*depth[x]<<"\n";
            }
        }
    }
    return 0;
}