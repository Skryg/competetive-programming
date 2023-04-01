#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; cin>>n;
    vector<vector<int>> g(n+1);
    for(int i=1;i<n;++i){
        int a,b; cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    vector<int> nim(n+1);

    auto dfs = [&](auto &self, int v, int p)->void{
        for(auto i : g[v]){
            if(i==p) continue;
            self(self,i,v);
            nim[v]^=(nim[i]+1);
        }
    };
    dfs(dfs,1,0);

    cout<< (nim[1] ? "Alice" : "Bob");
    return 0;
}
