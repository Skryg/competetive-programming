#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int n;
vector<ll> nums;
vector<ll> sum;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    nums.resize(n+1);
    sum.resize(n+1);
    ll mx{0};

    for(int i=1; i<=n;++i){
        cin>>nums[i];
    }
    for(int i=1;i<=n;++i){
        sum[i]=mx+nums[i];
        mx = max(mx, sum[i-1]);
    }
    mx = max(mx, sum[n]);
    cout<<mx;

    return 0;
}