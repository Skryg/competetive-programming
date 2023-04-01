#include <bits/stdc++.h>
#define vp vector<vector<pair<int,int>>>
using namespace std;

struct Edge{
    int id{0},a{0},b{0},w{0};
    bool is{false};
};

int n,m;
vp graph;
vector<Edge> es;
vector<int> rep;
vector<int> hm;
bool sortEdgeW(Edge d1, Edge d2){
    return d1.w < d2.w;
}

bool sortEdgeId(Edge d1, Edge d2){
    return d1.id < d2.id;
}

int find(int a){
    if(rep[a] != a) rep[a] = find(rep[a]);
    return rep[a];
}

void funion(int a, int b){
    if(hm[find(a)] > hm[find(b)]) swap(a,b);
    rep[find(a)] = find(b);
    hm[find(b)] += hm[find(a)];
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
   
    rep.resize(n+1);
    hm.resize(n+1, 1);
    es.resize(m);
    
    for(int i=0;i<m;++i){
        int a,b,c;
        cin>>a>>b>>c;
        if(a>b) swap(a,b);
        es[i]={i,a,b,c,false};
      
    }
    for(int i=1;i<=n;++i){
        rep[i]=i;
    }

    sort(es.begin(),es.end(),sortEdgeW);
    int wei{0};
    int j{0};
    for(int i=0;i<m;++i){
        if(es[i].w != wei){
            wei = es[i].w;
            for(j; j<i;++j){
                if(find(es[j].a)!=find(es[j].b))
                    funion(es[j].a,es[j].b);
            }
        }

        if(find(es[i].a)!=find(es[i].b)){
            
            es[i].is = true;
        }
            
    }
    sort(es.begin(),es.end(), sortEdgeId);
    for(auto i : es){
        cout<<(i.is ? "TAK\n" : "NIE\n");
    }

    return 0;
}