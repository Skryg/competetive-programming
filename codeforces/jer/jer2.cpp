#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t; cin>>t;
    while(t--){
        int k; cin>>k;
        vector<vector<pair<int,int>>> g(2*k+1);
        for(int i=0; i<2*k-1;++i){
            int a,b,c;
            cin>>a>>b>>c;
            g[a].push_back({b,c});
            g[b].push_back({a,c});
        }
        vector<int> sz(2*k+1);
        long long ans_max{0}, ans_min{0};

        
        auto dfs = [&](auto &dfs, int v, int p)->void{
            sz[v]++;
            for(auto [w, e] : g[v]){
                if(w==p) continue;
                dfs(dfs, w,v);
                sz[v]+=sz[w];
                ans_max += (long long)(min(2*k-sz[w], sz[w]))*e;
                ans_min += (sz[w]%2 ? e : 0);

            }
        };
        dfs(dfs, 1, 0);

        cout<< ans_min << " " << ans_max << "\n";

    }
}