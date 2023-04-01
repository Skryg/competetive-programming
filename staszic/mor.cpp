#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

vector<vector<int>> graph;
vector<ll> dist;
vector<bool> visited;
vector<bool> result;
struct Q{
    int id{0}, a{0},b{0},val{0};
    bool result{false};
};
vector<Q> queries;

bool sortQA(Q d1, Q d2){
    return d1.a < d2.a;
}
bool sortQId(Q d1, Q d2){
    return d1.id < d2.id;
}

void bfs(int v){
    fill(dist.begin(),dist.end(),LLONG_MAX);
    fill(visited.begin(),visited.end(),false);
    queue<pair<int,int>> q;
    q.push({v,0});
    while(!q.empty()){
        int vert{q.front().first};
        int d{q.front().second};
        q.pop();
        if(visited[vert]) continue;
        visited[vert]=true;
        dist[vert] = d;
        for(int i : graph[vert]){
            q.push({i,d+1});
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,m,k;
    cin>>n>>m>>k;
    graph.resize(2*n+1);
    dist.resize(2*n+1);
    visited.resize(2*n+1);
    for(int i=0;i<m;++i){
        int a,b;
        cin>>a>>b;
        graph[a].push_back(b+n);
        graph[b+n].push_back(a);
        graph[b].push_back(a+n);
        graph[a+n].push_back(b);
    }
    for(int i=0;i<k;++i){
        int a,b,c;
        cin>>a>>b>>c;
        queries.push_back({i,a,b,c,false});
    }
    result.resize(queries.size());
    sort(queries.begin(),queries.end(), sortQA);
    int a{0};
    for(Q q : queries){
        if(a!=q.a) bfs(q.a);
        a = q.a;
        bool f{true};
        if(graph[a].size()==0 && q.val != 0) f=false;
        if(q.val%2 == 0){
            result[q.id] = ((dist[q.b]<=(ll)q.val && f) ? true : false);
        }
        else{
            result[q.id] = ((dist[q.b+n]<=(ll)q.val && f) ? true : false);
        }

    } 
    for(bool r : result){
        cout<< (r ? "TAK\n": "NIE\n");
    }
    return 0;
}