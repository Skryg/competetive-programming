#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    ll ans{0};

    int n; cin>>n;
    vector<ll> hei(n+1);
    vector<vector<int>> tree(n+1);
    for(int i=1; i<=n; ++i) cin>>hei[i];
    for(int i=1; i<n;++i){
        int a,b; cin>>a>>b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    int mx{-1}, root;
    for(int i=1;i<=n;++i){
        if(mx < hei[i]){
            mx = hei[i];
            root = i;
        }
    }

    vector<ll> dp(n+1);

    auto dfs = [&](auto &self ,int v, int p)->void{
        for(auto w : tree[v]){
            if(w==p) continue;
            self(self, w, v);
            dp[v] = max(dp[v], dp[w]);
        }
        if(hei[v] > dp[v] && v!=root){
            ans+=(hei[v]-dp[v]);
            dp[v] = hei[v];
        }
        
    };
    dfs(dfs,root, 0);

    if(tree[root].size()==1){
        ans+=hei[root];
        ans+= (hei[root] - dp[tree[root][0]]);
    }
    else{
        ll first{0}, second{0};
        for(auto v : tree[root]){
            if(dp[v] > first){
                second = first;
                first = dp[v];
            }
            else if(dp[v] > second) second = dp[v];
        }
        ans+=(hei[root] - first);
        ans+=(hei[root] - second);
    }
    cout<<ans;
    return 0;
}