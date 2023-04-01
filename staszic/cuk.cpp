#include <bits/stdc++.h>

#define ST first
#define ND second

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,k;
    cin>>n>>k;
    vector<int> dp(1001);
    vector<pair<int,int>> cookie(n);
    int mx{0};
    for(int i=0;i<n;++i){
        cin>>cookie[i].ST>>cookie[i].ND;
    }
    for(int i=0;i<n;++i){
        for(int j=k-cookie[i].ST;j>=0;--j){
            if((dp[j]!=0 || j==0)&&dp[j+cookie[i].ST]<dp[j]+cookie[i].ND){
                dp[j+cookie[i].ST]=dp[j]+cookie[i].ND;
                mx = max(mx, dp[j+cookie[i].ST]);
            }
        }
    }
    cout<<mx;
    return 0;
}