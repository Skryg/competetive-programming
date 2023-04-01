#include<bits/stdc++.h>

typedef long long ll;

using namespace std;

int n,m;
vector<vector<int>> tab;
vector<vector<ll>> tab2;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    tab = vector<vector<int>>(n+1,vector<int>(m+1));
    tab2 = vector<vector<ll>>(n+1,vector<ll>(m+1, LLONG_MIN));
    for(int i=1;i<=n;++i){
        for(int j=1;j<=m;++j){
            cin >> tab[i][j];
        }
    }
    for(int i=1;i<=n;++i){
        for(int j=1;j<=m;++j){
            if(tab2[i-1][j]==LLONG_MIN && tab2[i][j-1] == LLONG_MIN) tab2[i-1][j]=0;
            tab2[i][j]=max(tab2[i-1][j],tab2[i][j-1])+(ll)tab[i][j];
        }
    }
    cout<<max(tab2[n][m],0LL);

    return 0;
}