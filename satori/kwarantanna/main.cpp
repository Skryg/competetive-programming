#include <bits/stdc++.h>

using namespace std;
#define satori int t; cin>>t; while(t--)
#define vt vector
#define pb push_back
typedef vt<vt<int>> graph;

void dfs(int v, const graph &g, stack<int> &sta, vt<bool> &vis){
    if(vis[v]) return;
    vis[v] = true;

    for(auto w : g[v]){
        dfs(w, g, sta, vis);
    }
    sta.push(v);
}

void rdfs(int v, const graph &rg, stack<int> &sta, vt<int> &scc, vt<pair<int,int>> &count, int c){
    if(scc[v]!=-1) return;

    scc[v] = c;
    count[c].first++;

    for(auto w : rg[v]){
        rdfs(w, rg, sta, scc, count, c);
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    satori{
        int n; cin>>n;
        graph g(n+1);
        graph rev_g(n+1);
        vt<bool> vis(n+1);
        vt<int> scc(n+1,-1);
        vt<pair<int,int>> scc_c;
        stack<int> sta;
    
        for(int man=1; man<=n;++man){
            int c; cin>>c;
            for(int i=0; i<c; ++i){
                int x; cin>>x;
                g[man].pb(x);
                rev_g[x].pb(man);
            }
        }

        for(int i=1;i<=n;++i){
            dfs(i, g, sta, vis);
        }
        int count{0};
        while(!sta.empty()){
            int top = sta.top(); sta.pop();
            if(scc[top]==-1){
                scc_c.pb({0, count});
                rdfs(top, rev_g, sta, scc, scc_c, count++);
            }
        }
        vt<bool> ok(scc_c.size(),true);
        for(int v=1; v<=n; ++v){
            for(auto w : g[v]){
                if(scc[v] != scc[w]) ok[scc[v]] = false;
            }
        }
        int mi{INT_MAX}, mi_id{0};
        for(auto id : scc_c){
            if(ok[id.second] && mi > id.first){
                mi = id.first;
                mi_id = id.second;
            }
        }
        cout<<mi<<"\n";
        for(int v=1; v<=n;++v){
            if(scc[v] == mi_id) cout<<v<<" "; 
        }
        cout<<"\n";
    }

    return 0;
}