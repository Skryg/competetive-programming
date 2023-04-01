#include <bits/stdc++.h>

using namespace std;

int n,m;

struct Query{
    int a{0},b{0},w{0}, id{0};

};

bool sortByWeight(Query d1, Query d2){
    return d1.w < d2.w;
}

vector<Query> queries;

vector<int> rep;
vector<int> hm;



int find(int a){
    if(rep[a]!=a) rep[a] = find(rep[a]);
    return rep[a];
}

void f_union(int a, int b){
    if(hm[a]>hm[b]) swap(a,b);
    rep[find(a)] = find(b);
    hm[find(b)] += hm[find(a)];

}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin>>n>>m;
    queries.resize(m);
    rep.resize(n+1);
    hm.resize(n+1,1);

    for(int i=1;i<=n;++i){
        rep[i]=i;
    }

    for(int i=0;i<m;++i){
        cin>>queries[i].a>> queries[i].b >> queries[i].w;
        queries[i].id = i+1;
    }
    sort(queries.begin(),queries.end(),sortByWeight);
    for(auto i : queries){
        if(find(i.a) != find(i.b) ){
            cout<<i.id <<"\n";
            f_union(i.a, i.b);
        }
    }

    return 0;
}