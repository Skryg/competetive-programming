#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n, m; cin>>n>>m;

    vector<ll> best_num(n+1);
    best_num[1]=1;
    best_num[2]=n-1;
    best_num[2]%=m;
    ll best = (n*(n-1)/2)%m;
    for(ll i=3; i<=n; ++i){
        best = (((n-i+1)*best)%m + (((n-i+1)*(n-i+2)/2)%m+((n-i+1)*(i-2))%m)%m * best_num[i-1]%m)%m;
        best_num[i] = (best_num[i-1]*(n-i+1))%m;
    }
    ll fact=1;
    for(ll i=1;i<n;++i){
        fact*=i;
        fact%=m;
    }
    ll sum{0};
    for(ll i=1;i<=n;++i){
        ll hm = fact-best_num[i];
        while(hm<0) hm+=m;
        ll norm = (best+((hm*i)%m*(n-1))%m)%m;
        ll minus = ((best_num[i]*(n-i)%m)*(n-1))%m;
        norm-=minus;
        while(norm<0) norm+=m;
        sum+=norm;
        sum%=m;
    }
    sum%=m;
    cout<<sum;

    return 0;
}
