#include <bits/stdc++.h>

using namespace std;

constexpr int INF=1e9;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; cin>>n;
    vector<vector<int>> tree(n+1);
    for(int i=0;i<n-1;++i){
        int a,b; cin>>a>>b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    vector<pair<int,int>> nums(n+1, {-INF, INF});
    vector<bool> vis(n+1), color(n+1);

    int k; cin>>k;
    while(k--){
        int v,p; cin>>v>>p;
        color[v]=true;
        nums[v]={p,p};
    }

    auto dfs = [&](auto &self, int v)->bool{
        if(vis[v]) return true;
        vis[v]=true;

        for(auto w : tree[v]){
            if(nums[w].first != -INF && (nums[w].first+INF)%2 != (nums[v].first-1+INF)%2) return false;
            if(nums[v].first > nums[w].second+1 || nums[v].second < nums[w].first-1) return false;
            nums[w] = { max(nums[v].first-1, nums[w].first),
                        min(nums[v].second+1, nums[w].second)};

            if(color[w]==false && !self(self, w)) return false;
            nums[v] = { max(nums[v].first, nums[w].first-1),
                        min(nums[v].second, nums[w].second+1)};
        }

        return true;
    };
    bool ok = true;
    for(int i=1;i<=n;++i){
        if(color[i]){
            if(!dfs(dfs,i)){
                cout<<"No";
                ok = false;
                break;
            }
        } 
    }
    vector<int> ans(n+1);
    fill(vis.begin(),vis.end(),0);
    auto dfs2 = [&](auto &self, int v, int p)->void{
        if(vis[v]) return;
        vis[v]=true;
        if(!p) ans[v] = nums[v].first;
        else{
            auto [a,b] = nums[v];
            int x = ans[p]-1, y = ans[p]+1;
            if(x >= a && x<= b) ans[v]=x;
            else if(y >= a && y<= b) ans[v]=y;
        }
        for(auto i : tree[v]){
            if(i==p || color[i]) continue;
            self(self, i, v);
        }
    };

    if(ok){
        for(int i=1;i<=n;++i) if(color[i]) dfs2(dfs2, i, 0);
        cout<<"Yes\n";
        for(int i=1;i<=n;++i){
            cout<<ans[i]<<"\n";
        }
    }


    return 0;
}