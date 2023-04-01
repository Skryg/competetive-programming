#include <bits/stdc++.h>
#define ST first
#define ND second
using namespace std;

typedef long long ll;

vector<ll> cost;
vector<vector<pair<int,ll>>> graph;
vector<vector<pair<int,ll>>> reversed;
int n,m;

vector<ll> dijkstra(int v, vector<vector<pair<int,ll>>> &g){
    vector<ll> d(n+1, 10000000000LL);
    priority_queue<pair<ll, int>> pq;
    vector<bool> visited(n+1);
    d[v]=0;
    pq.push({0,v});
    while(!pq.empty()){
        int vx{pq.top().ND};
       
        pq.pop();
        
        visited[vx]=true;
        for(auto i : g[vx]){
           
            if(d[i.first] > d[vx]+i.ND){
                pq.push({-i.ND,i.ST});
                d[i.first]=min(d[i.ST], d[vx]+i.ND);
            }
                
        }
    }
    return d;

}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin>>n;
    cost.resize(n+1);
    graph.resize(n+1);
    reversed.resize(n+1);
    for(int i=1;i<=n;++i){
        cin>>cost[i];
    }
    cin>>m;
    for(int i=0;i<m;++i){
        int a,b;
        ll c;
        cin>>a>>b>>c;
        graph[a].push_back({b,c});
        reversed[b].push_back({a,c});
    }
    vector<ll> s1 = dijkstra(1,graph);
    vector<ll> s2 = dijkstra(1,reversed);
    ll ans{100000000000LL};
    for(int i=1;i<=n;++i){
        ans = min(ans, s1[i]+s2[i]+(cost[i]/2));
    }
    cout<<ans;
    return 0;
}