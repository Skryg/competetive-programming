#include <bits/stdc++.h>

using namespace std;

pair<int,int> centroid(vector<vector<pair<int,int>>> &g){
    vector<int> sz(g.size());
    int first;
    for(int i=1;i<g.size();++i) if(g[i].size()==1) first = i;
    pair<int,int> cent;

    auto dfs = [&](auto &self, int v, int p)->void{
        sz[v]++; 
        for(auto [w,_] : g[v]){
            if(w==p) continue;
            self(self, w, v);
            sz[v]+=sz[w];
        }
    };
    dfs(dfs, first, 0);

    auto find_centr = [&](auto &cen, int v, int p, int prev)->void{
        int mx=0,x=0;
        bool ok = true;
        
        if(prev > (g.size()-1)/2) ok = false;
        for(auto [w,_] : g[v]){
            if(w==p) continue;
            if(sz[w] > (g.size()-1)/2) ok = false;
            prev+=sz[w];
            if(sz[w] > mx){
                mx = sz[w];
                x = w;
            }
        }
        prev++;
        prev-=mx;
        if(ok){
            if(cent.first) cent.second = v;
            else cent.first = v;
        }
        if(x) cen(cen, x, v, prev);
    };    
    find_centr(find_centr, first,  0, 0);
    return cent;
}



int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t; cin>>t;
    while(t--){
        int k; cin>>k;
        vector<vector<pair<int,int>>> tree(2*k+1);
        for(int i=0;i<2*k-1;++i){
            int a,b,t;
            cin>>a>>b>>t;
            tree[a].push_back({b,t});
            tree[b].push_back({a,t});
        }
        auto cent= centroid(tree);
        
        vector<int> mx(2*k+1), mi(2*k+1);
        long long ans_mx{0}, ans_min{0};
        auto dfs = [&](auto &dfs, int v, int p)->void{
            int local_mx{1}; 
            int local_min{1};
            
            for(auto [w, e] : tree[v]){
                if(w==p || w == cent.first || w == cent.second) continue;
                dfs(dfs,w,v);
                ans_mx += (long long)mx[w]*e;
                ans_min += (long long)mi[w]*e;

                local_mx += mx[w];
                local_min = abs(local_min - mi[w]);
            }
            mx[v] = local_mx;
            mi[v] = local_min;

        };
        dfs(dfs, cent.first,0);
        dfs(dfs, cent.second, 0);

        if(cent.first && cent.second){
            for(auto [w,e] : tree[cent.first]){
                if(w==cent.second){
                    ans_mx += (long long)k*e;
                    if(k%2) ans_min += (long long)e;
                }
            }
        }

        cout << ans_min << " " << ans_mx << "\n";

    }

    return 0;
}