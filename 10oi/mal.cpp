#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define rh rep,hm
int find(int a, vi& rep, vi& hm)
{
    if(rep[a]!=a) rep[a] = find(rep[a],rep,hm);
    return rep[a];
}

void uni(int a, int b, vi& rep, vi& hm, vector<vector<int>>& list)
{
    
    if(hm[a] > hm[b]) swap(a,b);

    rep[a]=b;
    hm[b] += hm[a];
    
    
    for(int i=0;i<list[a].size();++i)
    {
        list[b].push_back(list[a][i]);
    }
    list[a].clear();
}

void uni(int a, int b, vi& rep, vi& hm, vector<vector<int>>& list, int time, vi& ans)
{
    if(hm[a] > hm[b]) swap(a,b);
    bool fl{false};
    if(find(b,rep,hm)==find(1,rep,hm)) fl=true;
    if(find(a, rep, hm)==find(1, rep,hm))
    {
        for(int i=0;i<list[b].size();++i)
        {
            ans[list[b][i]] = time;
        }
    }
    int x = find(a,rh);
    int y = find(b,rh);

    rep[a]=find(b,rh);
    hm[b] += hm[a];
    
    
    for(int i=0;i<list[x].size();++i)
    {
        list[y].push_back(list[x][i]);
        if(fl) ans[list[x][i]] = time;
    }
    list[x].clear();
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,m;

    cin>>n>>m;
    vector<pair<int,int>> mon(n+1);
    vector<pair<int,int>> monFull;
    vector<int> rep(n+1);
    vector<int> hm(n+1,1);
    vector<int> ans(n+1,-1);
    for(int i=1;i<=n;++i) rep[i]=i;

    vector<vector<int>> lists(n+1);
    for(int i=1;i<n+1;++i)
    {
        lists[i].push_back(i);
    }

    for(int i=1;i<=n;++i)
    {
        cin>>mon[i].first>>mon[i].second;
    }
    monFull = mon;
    vector<pair<int,int>> queries(m);
    for(int i=0;i<m;++i)
    {
        int a,b;
        cin>>a>>b;
        queries[i]={a,b};
        if(b==1) mon[a].first=-1;
        if(b==2) mon[a].second=-1;
    } 
    for(int i=1;i<=n;++i)
    {
        if(mon[i].first!=-1 && find(i,rh)!=find(mon[i].first,rh)) uni(find(i,rh), find(mon[i].first,rh), rep, hm, lists);
        if(mon[i].second!=-1 && find(i,rh)!=find(mon[i].second,rh)) uni(find(i,rh), find(mon[i].second,rh), rep, hm, lists);
    }

    while(m--)
    {
        int help;
        if(queries[m].second==2) help = monFull[queries[m].first].second;
        if(queries[m].second==1) help = monFull[queries[m].first].first; // help malpa ktora podlaczyc

        if(find(queries[m].first,rh)!=find(help,rh)) uni(find(help,rh), find(queries[m].first,rh), rep, hm, lists,m,ans);


    }
    for(int i=1;i<ans.size();++i)
    {
        cout<<ans[i]<<"\n";
    }
    return 0;
}