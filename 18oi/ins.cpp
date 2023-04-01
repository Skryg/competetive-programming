#include <bits/stdc++.h>

#define ST first
#define ND second

using namespace std;

typedef long long ll;

vector<vector<int>> tr;
vector<int> snum;
vector<ll> ans;
int n;

int subtree(int v, int a)
{
    int sum{1};
    for(int i=0;i<tr[v].size();++i)
    {
        if(tr[v][i]!=a)
        {
            sum+=subtree(tr[v][i],v);
        }
    }
    snum[v]=sum;
    return sum;

}
int longest(int v, int a, int val)
{
    int mx{0};
    for(int i=0;i<tr[v].size();++i)
    {
        if(tr[v][i]!=a)
        {
            mx = max(mx, longest(tr[v][i],v,val+1));
        }
        
    }
    return max(val,mx);
}

ll dfs(int v, int a, ll sum )
{
    ++sum;

    ll all{sum};
    for(int i=0;i<tr[v].size();++i)
    {
        if(tr[v][i]!=a)
        {
            all += dfs(tr[v][i],v,sum);

        }
    }
    return all;
}

void find_centr(int v, int a)
{
    bool flag{true};
    for(int i=0;i<tr[v].size();++i)
    {
        if(snum[tr[v][i]]>n/2)flag = false;
        if(snum[tr[v][i]]>n/2  && a!=tr[v][i])
        {
            snum[v] -= snum[tr[v][i]];
            snum[tr[v][i]] = n;

            find_centr(tr[v][i],v);
        }
        else if(snum[tr[v][i]]==n/2 && n%2==0 && a!=tr[v][i])
        {
            snum[v] -= snum[tr[v][i]];
            snum[tr[v][i]] = n;

            find_centr(tr[v][i],v);
        }
    }
    if(flag) 
    {
        
        ll p = dfs(v,0,-1);
        int an{0},b{v}, val{0};
        subtree(v,0);
        for(int i=0;i<tr[v].size();++i)
        {
            if(2*snum[tr[v][i]]==n)
            {
                an = v;
                b = tr[v][i];
                val=1;
            }
        }
        if(ans[v]==-1) ans[v] = 2*p-(ll)longest(b,an,val);

    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    tr.resize(n+1);
    snum.resize(n+1);
    ans.resize(n+1,-1);
    for(int i=0;i<n-1;++i)
    {
        int a,b;
        cin>>a>>b;
        tr[a].push_back(b);
        tr[b].push_back(a);
    }
    subtree(1,0);
    find_centr(1,0);
    for(int i=1;i<=n;++i)
    {
        cout<<ans[i]<<"\n";
    }

    return 0;
}