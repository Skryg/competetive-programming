#include <bits/stdc++.h>

using namespace std;

struct Inter{
    pair<int, int> in;
    int val;
};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); 
    map<int, int> nums_n, nums_m;
    int n,m; cin>>n>>m;
    vector<int> ns(n+1),ms(m+1);
    vector<int> prev_a(n+1), prev_b(m+1);
    for(int i=1;i<=n;++i){
        cin>>ns[i];
    }
    for(int i=1;i<=m;++i){
        cin>>ms[i];
    }
    
    for(int i=1;i<=n;++i){
        if(nums_n.find(ns[i])!=nums_n.end()){
            prev_a[i]=nums_n[ns[i]];
        }
        nums_n[ns[i]]=i;
    }
    for(int i=1;i<=m;++i){
        if(nums_m.find(ms[i])!=nums_m.end()){
            prev_b[i]=nums_m[ms[i]];
        }
        nums_m[ms[i]]=i;
    }
    vector<int> gcs[2];
    gcs[0].resize(m+1);
    gcs[1].resize(m+1);
    vector<int> memo(m+1);
    for(int j=0;j<=m;++j){
        gcs[0][j] = memo[j] = 0;
    }
    for(int i=1;i<=n;++i){
        gcs[i%2][0]=0;
        for(int j=1;j<=m;++j){
            if(ns[i]==ms[j] && prev_a[i]>0 && prev_b[j]>0) gcs[i%2][j] = memo[prev_b[j]]+2;
            else gcs[i%2][j]=0;
            gcs[i%2][j] = max({gcs[i%2][j], gcs[(i-1)%2][j], gcs[i%2][j-1]});
        }
        for(int j=1;j<=m;++j){
            if(ns[i]==ms[j])
                memo[j] = gcs[(i-1)%2][j-1];
        }
        
    }
    cout<<gcs[n%2][m];
    return 0;
}