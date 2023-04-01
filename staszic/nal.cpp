#include <bits/stdc++.h>

using namespace std;

vector<vector<pair<int,int>>> tab;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    tab.resize(n+1,vector<pair<int,int>>(m+1));
    vector<int> ns(n+1),ms(m+1);
    for(int i=1;i<=n;++i){
        cin>>ns[i];
    }
    for(int i=1;i<=m;++i){
        cin>>ms[i];
    }
    
    tab[0][0]={0,0};
    for(int i=0;i<=n;++i){
        for(int j=0;j<=m;++j){
            if(i==0 && j==0) tab[i][j]={0,0};
            else if(i==0) tab[i][j]={tab[i][j-1].second+ms[j],tab[i][j-1].first};
            else if(j==0) tab[i][j]={tab[i-1][j].second+ns[i],tab[i-1][j].first};
            else{
                if(tab[i][j-1].second+ms[j]>tab[i-1][j].second+ns[i]){
                    tab[i][j]={tab[i][j-1].second+ms[j], tab[i][j-1].first};
                }
                else tab[i][j]={tab[i-1][j].second+ns[i],tab[i-1][j].first};
            }
        }
    }
    
    //cout<<(((n+m)%2) ? /*tab[n][m].second*/tab[n][m].first : tab[n][m].second/*tab[n][m].first*/);
    cout<< tab[n][m].first;
    return 0;
}