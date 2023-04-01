#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct Leaf
{
    int v;
    pair<ll,ll> e;
    Leaf(){}
    Leaf(ll v, pair<ll,ll> ext)
    {
        this->v = v;
        this->e = ext;
    }
};

vector<Leaf> leaves;
vector<vector<int>> tree;
vector<bool> visited;
vector<ll> gr;
const ll MAX{1000000010};

void DFS(int v, ll mi, ll mx)
{
    visited[v]=true;
    if(tree[v].size()==1)
    {
        leaves.push_back(Leaf(v,{mi,mx}));
    }
    for(int i=0;i<tree[v].size();++i)
    {
        if(!visited[tree[v][i]])
            DFS(tree[v][i],min((ll)(tree[v].size()-1)*mi, MAX), min(mx*(ll)(tree[v].size()-1)+(ll)(tree[v].size()-2),MAX));
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n,g,k;
    ll ans{0};
    cin>>n>>g>>k;
    tree.resize(n+1);
    visited.resize(n+1);
    gr.resize(g);
    for(int i=0;i<g;++i)
    {
        cin>>gr[i];
    }
    sort(gr.begin(),gr.end());

    ll a,b;
    cin>>a>>b;
    tree[a].push_back(b);
    tree[b].push_back(a);
    pair<ll,ll> ante{a,b};

    for(ll i=1;i<n-1;++i)
    {
        ll a,b;
        cin>>a>>b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    visited[ante.second]=true;
    DFS(ante.first, k, k);
    visited[ante.second]=false;
    DFS(ante.second, k, k);


    for(auto i : leaves)
    {
        vector<ll>::iterator mm = lower_bound(gr.begin(),gr.end(),i.e.first);
        vector<ll>::iterator mx = upper_bound(gr.begin(),gr.end(),i.e.second);
        ll dif = mx-mm;
        ans = ans + dif;
    }
    ans = ans * k;
    cout<<ans;

    return 0;
}