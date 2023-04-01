#include <bits/stdc++.h>
#define satori int z; cin>>z; while(z--)

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    satori{
        int n, r; cin>>n>>r;
        vector<pair<int,int>> tree(n+1);
        for(int i=1;i<=n;++i){
            auto &[a,b] = tree[i];
            cin>>a>>b;
        }

        int p = r;
        int q = -1;
        
        while(p != -1){
            if(!p){
                p = q;
                q = 0;
            }
            else{
                if(tree[p].first != 0) cout<<p<<' ';
                int tmp = tree[p].first;
                tree[p].first = tree[p].second;
                tree[p].second = q;
                q = p;
                p = tmp;
            }
        }
        cout<<'\n';
    }

    return 0;
}