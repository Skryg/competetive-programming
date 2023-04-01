#include <bits/stdc++.h>
#define satori int z; cin>>z; while(z--)
#define graph vector<vector<int>>
using namespace std;

pair<int,int> len(int v, int p, graph &g){
    if(g[v].size() == 1 && g[v][0]==p) return {1, v};
    pair<int,int> pr={0,0};
    for(auto w : g[v]){
        if(w==p) continue;
        pr = max(pr, len(w,v,g));
    }
    ++pr.first;
    return pr;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    satori{
        int n,k; cin>>n>>k;
        graph g;
        g.resize(n+1);
        for(int i=0;i<n-1;++i){
            int a,b; cin>>a>>b;
            g[a].push_back(b);
            g[b].push_back(a);
        }

        int first = len(1,0,g).second;
        int last = len(first,0,g).second;
        vector<bool> vis(n+1);
        vector<int> num(n+1);
        vector<int> dist(n+1);
        int cnt = 0;
        //cout<< 'f'<<first<<" l"<<last<<' ';
                
        auto distance = [&](int v, int p,auto &&dfs){
            if(g[v].size() == 1){
                dist[v] = 1;
                return;
            }
            int mx = 0;
            for(auto w : g[v]){
                if(w==p) continue;
                dfs(w,v,dfs);

                if(dist[w]>=mx){
                    if(mx) ++num[mx];
                    mx = dist[w];
                }
                else{
                    ++num[dist[w]];
                }
            }
            dist[v] = mx+1;
        };

        auto path = [&](int v, auto &&dfs)->bool{
            if(vis[v]) return false;
            vis[v]=true;
            ++cnt;
            if(v == last) return true;

            bool good = false;

            for(auto w : g[v]){
                good = dfs(w,dfs);
                if(good) break;
            }
            if(good){
                for(auto w : g[v]){
                    if(!vis[w]){
                        distance(w,v,distance);
                        ++num[dist[w]];
                    }
                }
                return true;
            }
            
            vis[v] = false;
            --cnt;
            return false;
        };
        path(first, path);
        --k;
        k*=2;
        for(int i=n; i; --i){
            if(k>=num[i]){
                cnt+=num[i]*i;
                k-=num[i];
            }
            else{
                cnt+=k*i;
                k=0;
            }
        }
        cout<<cnt<<'\n';

    }

    return 0;
}