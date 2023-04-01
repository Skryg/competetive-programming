#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,m; cin>>n>>m;
    vector<pair<int,int>> rb(n+1);
    for(int i=0;i<m;++i){
        int x,y; cin>>x>>y;
        rb[x].first++;
        rb[y].first++;
    }
    for(int i=1;i<=n;++i){
        rb[i].second = n-1-rb[i].first;
    }

    int all = n*(n-1)*(n-2)/6;
    int dif = 0;
    for(int i=1;i<=n;++i) dif+=(rb[i].first*rb[i].second);
    dif/=2;
    cout<<all-dif;
    return 0;
    

}