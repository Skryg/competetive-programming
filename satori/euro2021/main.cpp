#include <bits/stdc++.h>

using namespace std;

typedef vector<vector<int>> graph;
#define satori int t; cin>>t; while(t--)
#define vt vector
#define pb push_back

void dfs(const graph &g, vt<bool> &vis, int v, stack<int> &sta){
    if(vis[v]) return;
    vis[v] = true;

    for(auto u : g[v]){
        dfs(g, vis, u, sta);
    }
    sta.push(v);
}

void rdfs(const graph &rg, vt<bool> &vis, int v, vt<int> &scc,  int c){
    if(vis[v]) return;
    vis[v] = true;
    scc[v] = c;
    for(auto u : rg[v]){
        rdfs(rg, vis, u, scc, c);
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    satori{
        int n,m; cin>>n>>m;
        graph g(n+1), rev_g(n+1);
        vt<int> scc(n+1,-1);
        vt<bool> vis(n+1);

        for(int i=0; i<m; ++i){
            int a,b; cin>>a>>b;
            g[a].pb(b);
            rev_g[b].pb(a);
        }

        stack<int> s;
        for(int v=1;v<=n;++v){
            dfs(g, vis, v, s);
        }
        fill(vis.begin(), vis.end(), false);
        int count{0};
        while(!s.empty()){
            int top = s.top(); s.pop();
            if(vis[top]) continue;
            rdfs(rev_g, vis, top, scc, count++);
        }

        int k; cin>>k;
        for(int i=0;i<k;++i){
            int a,b; cin>>a>>b;
            cout << (scc[a] == scc[b] ? "TAK\n" : "NIE\n"); 
        }

    }

    return 0;
}
