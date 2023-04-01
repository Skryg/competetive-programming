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
        queue<pr<int, pr<int,bool>>> bfs_q;
        vt<int> visited(n+1);
        for(int i=0;i<k;++i){
            bfs_q.push({fr_pos[i],{i,false}});
           // visited[fr_pos[i]]=true;
        }
        bfs_q.push({1, {INT_MAX,true}});
        //visited[1]=true;
        bool ended{false};
        while(!bfs_q.empty()){

            auto x = bfs_q.front();
            bfs_q.pop();
            if(x.nd.nd && graph[x.st].size()==1 && x.st!=1){
                cout<<"-1\n";
                ended=true;
                break;
            }
            if(visited[x.st]) continue;
            if(x.nd.nd) visited[x.st]=INT_MAX;
            else visited[x.st]=x.nd.st+1;
            for(auto i : graph[x.st]){
                if(!visited[i]) bfs_q.push({i, x.nd});
            }
        }
        set<int> guys;
        if(!ended){
            for(int i=1;i<=n;++i){
                if(visited[i]!=INT_MAX) continue;
                for(auto j :graph[i]){
                    if(visited[j]!=INT_MAX) guys.insert(visited[j]);
                }
            }
            cout<<guys.size()<<"\n";
        } 
        

    }
    return 0;
}