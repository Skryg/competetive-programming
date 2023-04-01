#include <bits/stdc++.h>

typedef long long ll;

using namespace std;


int n;
vector<ll> dist;
vector<bool> visited;
vector<int> from;
vector<pair<int, int>> xy;

void prim(int a){
    ll min{LLONG_MAX};
    int idm{0};
    visited[a]=true;
    for(int i=1;i<=n;++i){
        if(!visited[i]){
            ll d{(ll)ceil(sqrt(pow(xy[a].first - xy[i].first,2)+pow(xy[a].second - xy[i].second,2)))};
            if(dist[i]>d){
                dist[i]=d;
                from[i]=a;
            }
            if(min>dist[i]){
                min = dist[i];
                idm = i;
            }
        }
    }
    if(idm) prim(idm);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    xy.resize(n+1);
    visited.resize(n+1);
    from.resize(n+1);
    dist.resize(n+1, LLONG_MAX);

    for(int i=1;i<=n;++i){
        cin>>xy[i].first>>xy[i].second;     
    }
    dist[1]=0;
    prim(1);
    ll mx{0};
    for(int i=1;i<=n;++i){
        mx = max(mx, dist[i]);
    }
    ll ans{mx*(n-1)};
    cout<<ans;

    return 0;
}