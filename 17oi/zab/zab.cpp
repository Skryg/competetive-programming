#include <bits/stdc++.h>
#define debug(x) cerr << x << '\n'; 

typedef long long ll;

using namespace std;

vector<pair<int,int>> get_nxt(ll k, vector<ll> &st){
    int first = 0, last = k;
    vector<pair<int,int>> nxt(st.size(),{-1,-1});
    for(int i = 0; i < st.size(); ++i){
        while(last+1 < st.size()
         && abs(st[last+1]-st[i]) < abs(st[first]-st[i])){
            first++;
            last++;
        }
        if(abs(st[first]-st[i]) >= abs(st[last]-st[i])) nxt[i].second = first;
        else nxt[i].second = last;
    }
    return nxt;
}

void update_jmp(vector<pair<int,int>> &tab){
    for(auto &[a,b] : tab){
        a = b;
        b = -1;
    }
    for(int i=0;i<tab.size();++i) tab[i].second = tab[tab[i].first].first;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n,k,m; cin>>n>>k>>m;
    vector<ll> stones(n);
    for(auto &s : stones) cin>>s;

    vector<pair<int,int>> next = get_nxt(k, stones);
    // for(auto [_,i] : next) debug(i);
    vector<int> ans(n);
    for(int i=0; i<n; ++i) ans[i]=i;
    for(int i=0; i<63;++i){
        if(m & (1LL<<i)){
            debug("m when i");debug(i);
            for(int j=0; j<n;++j){
                ans[j] = next[ans[j]].second;
            }
        }
        update_jmp(next);
    }

    for(auto a : ans) cout << a+1 << " ";
    return 0;
}