#include <bits/stdc++.h>
#define MOD 1'000'000'007LL

using namespace std;

typedef long long ll;

struct Edge{
    int a{0},b{0};
    ll w{0};

    static bool sortW(Edge e1, Edge e2){
        return e1.w < e2.w;
    }
};

int m,n,h;
vector<int> rep;
vector<int> hm;
vector<ll> hei;
vector<ll> opt;
vector<Edge> edges;

int find(int a){
    if(rep[a]!=a) rep[a] = find(rep[a]);
    return rep[a];
}

void f_union(int a, int b){
    if(hm[find(b)]>hm[find(a)]) swap(a,b);

    opt[find(a)] = opt[find(a)]*opt[find(b)]%MOD;
    rep[find(b)]=find(a);
    hm[find(a)]+=hm[find(b)];

}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> m >> n >> h;
    hei.resize(n*m+1, 0);
    rep.resize(n*m+1);
    hm.resize(n*m+1,1);
    opt.resize(n*m+1,1);
    for(int i=1;i<=n*m;++i){
        rep[i]=i;
    }
    for(int i=0;i<m;++i){
        for(int j=1;j<n;++j){
            ll z;
            cin>>z;
            edges.push_back({j+i*n,j+1+i*n,z});
 
        }
        
    }
    for(int i=0; i<m-1;++i){
        for(int j=1; j<=n;++j){
            ll z;
            cin>>z;
            edges.push_back({i*n+j,(i+1)*n+j,z});
          
        }
    }
    sort(edges.begin(),edges.end(),Edge::sortW);

    for(Edge e : edges){
        if(find(e.a)==find(e.b)) continue;
        opt[find(e.a)] += (e.w - hei[find(e.a)]);
        opt[find(e.a)]%=MOD;
        opt[find(e.b)] += (e.w - hei[find(e.b)]);
        opt[find(e.b)]%=MOD;
        hei[find(e.a)] = e.w;
        hei[find(e.b)] = e.w;
        f_union(e.a,e.b);
    }
    opt[find(edges[0].a)]+= (h - hei[find(edges[0].a)]);
    opt[find(edges[0].a)]%=MOD;
    cout<<opt[find(edges[0].a)];
    return 0;
}