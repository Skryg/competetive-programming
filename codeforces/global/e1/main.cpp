#include <bits/stdc++.h>

using namespace std;
#define satori int t; cin>>t; while(t--)
#define vt vector
#define pb push_back
#define pr pair
#define st first
#define nd second 

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    satori{
        int n,k; cin>>n>>k;
        vt<vt<int>> graph(n+1);
        vt<int> fr_pos(k);
        for(auto &i : fr_pos){
            cin>>i;
        }
        for(int i=0;i<n-1;++i){
            int v,u;
            cin>>v>>u;
            graph[v].pb(u);
            graph[u].pb(v);

        }
        queue<pr<int, bool>> bfs_q;
        vt<int> visited(n+1);
        for(int i=0;i<k;++i){
            bfs_q.push({fr_pos[i],false});
           // visited[fr_pos[i]]=true;
        }
        bfs_q.push({1, true});
        //visited[1]=true;
        bool ended{false};
        while(!bfs_q.empty()){

            pr<int, bool> x = bfs_q.front();
            bfs_q.pop();
            if(x.nd && graph[x.st].size()==1 && x.st!=1){
                cout<<"YES\n";
                ended=true;
                break;
            }
            if(visited[x.st]) continue;
            visited[x.st]=true;
            for(auto i : graph[x.st]){
                if(!visited[i]) bfs_q.push({i, x.nd});
            }
        }
        if(!ended) cout<<"NO\n";

    }
    return 0;
}