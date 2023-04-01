#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n; cin>>n;

    vector<vector<int>> tree(n);
    for(int i=0;i<n-1;++i){
        int a,b; cin>>a>>b;
        tree[a].push_back(b);
        tree[b].push_back(a);

    }
    vector<int> dp(n);
    int root=-1;
    for(int i=0;i<n;++i){
        if(tree[i].size()>2){ 
            root = i;
            break;
        }
    }
    if(root == -1){
        cout<<1;
        return 0;
    }

    auto dfs = [&](auto &dfs, int v, int p)->void{
        int mi = INT_MAX;
        for(auto w : tree[v]){
            if(w==p) continue;
            dfs(dfs, w,v);
            dp[v]+=(dp[w] ? dp[w] : 1);
            mi = min(mi, dp[w]);
        }
        if(!mi) dp[v]--;
    };
    dfs(dfs, root, -1);
    cout<<dp[root];

    return 0;
}