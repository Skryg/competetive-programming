#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

vector<int> tab, tab2;
int n;


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    tab.resize(n+3);
    tab2.resize(n+3);
    int sum{0};
    for(int i=3;i<=n+2;++i){
        cin>>tab[i];
        sum+=tab[i];
    }
    int ans{0};
    for(int i=3;i<=n+2;++i){
        tab2[i]+=(max(tab2[i-2],tab2[i-3])+9-tab[i]);
        ans = max(ans,tab2[i]);
    }
    cout<<ans+sum;

    return 0;
}