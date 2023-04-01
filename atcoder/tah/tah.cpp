#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll n,l,q; cin>>n;
    vector<ll> x(n+1);
    for(int i=1; i<=n;++i) cin>>x[i];
    cin>>l>>q;
    vector<vector<ll>> anc(n+1, vector<ll>(32,0));
    x[0] = -10'000'000'000LL;

    ll first=n;
    for(ll last=n; last; --last){
        while(first >= 0 && x[last]-x[first] <= l){
            first--;
          //  cout<<"min ";
        }
        anc[last][0] = first+1;
        //cout<<"upd ";
    }
    for(int j=1;j<32;++j){
        for(int i=1;i<=n;++i){
            anc[i][j] = anc[anc[i][j-1]][j-1];
        }
    }
    while(q--){
        ll ans{0};
        ll a,b; cin>>a>>b;
        if(a>b) swap(a,b);
        for(int i=31; i>=0; --i){
            if(anc[b][i] > a){
                ans+=(1<<i);
                b = anc[b][i];
            }
        }
        ans++;
        cout<<ans<<"\n";
    }

    return 0;
}