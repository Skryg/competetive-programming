#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n,r,q;

struct vertex
{
    int res{0};
    int depth{0};
    int it{0};
    bool visited{false};
    vector<pair<int,ll>> neighs;
    vertex(){}
};

struct query
{
    int m,k,e,id;
    ll ans{LLONG_MAX};
    query(){};
};

bool sortByRestaurant(query q1,query q2)
{
    return q1.e < q2.e;
}
bool sortById(query q1,query q2)
{
    return q1.id<q2.id;
}

vector<vertex> graph;
vector<query> queries;
vector<ll> df;
vector<vector<int>>up;
vector<vector<int>>restaurants;

void loadData()
{
    cin>>n>>r;
    graph.resize(n+1);
    up.resize(n+1);
    df.resize(n+1,0);
    up[0].resize(19);
    restaurants.resize(r+1);

    for(int i=1;i<=n;++i)
    {  
        up[i].resize(19,0);
        cin>>graph[i].res;
        restaurants[graph[i].res].push_back(i);
    }
    for(int i=0;i<n-1;++i)
    {
        int a,b,c;
        cin>>a>>b>>c;
        graph[a].neighs.push_back({b,c});
        graph[b].neighs.push_back({a,c});
    }
    cin>>q;
    for(int i=0;i<q;++i)
    {
        query q;
        cin>>q.m>>q.k>>q.e;
        q.id=i;
        queries.push_back(q);
    }
}    
#define  NEI graph[v].neighs
void DFS(int v, int depth)
{
    graph[v].visited=true;
    graph[v].depth=depth;
    for(int i=0;i<NEI.size();++i)
    {
        if(!graph[NEI[i].first].visited)
        {
            up[NEI[i].first][0]=v;
            df[NEI[i].first]=NEI[i].second + df[v];
            for(int j=1;j<19;j++)
            {
                up[NEI[i].first][j]=up[up[NEI[i].first][j-1]][j-1];
            }
            DFS(NEI[i].first,depth+1);
        }
    }
}

int LCA(int a, int b)
{
    if(graph[a].depth != graph[b].depth)
    {
        if(graph[a].depth > graph[b].depth)
        {
            int dest = graph[b].depth;
            for(int i=18;i>=0;--i)
            {
                if(dest<=graph[up[a][i]].depth)
                {
                    a=up[a][i];
                }
            }
        }
        else
        {
            int dest = graph[a].depth;
            for(int i=18;i>=0;--i)
            {
                if(dest<=graph[up[b][i]].depth)
                {
                    b=up[b][i];
                }
            }
        }
    }

    if(a==b) return a;

    for(int i=18;i>=0;--i)
    {
        if(up[a][i]!=up[b][i])
        {
            b = up[b][i];
            a = up[a][i];
        }
    }
    return up[a][0];
}

ll minDistance(int a, int b, int r)
{
    ll ans =-1;
    if(restaurants[r].size()>0) ans = LLONG_MAX;
    for(int i=0;i<restaurants[r].size();++i)
    {
        int g1 = LCA(a,restaurants[r][i]);
        int g2 = LCA(b,restaurants[r][i]);
        ll cand=2*df[restaurants[r][i]]+df[a]+df[b]-2*df[g1]-2*df[g2];
        ans = min(cand,ans);
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    loadData();
    DFS(1,1);
    sort(queries.begin(),queries.end(),sortByRestaurant);
    for(int i=0;i<queries.size();++i)
    {
        queries[i].ans = min(minDistance(queries[i].m,queries[i].k,queries[i].e),queries[i].ans);
    }
    sort(queries.begin(),queries.end(),sortById);
    for(auto i : queries)
    {
        cout << i.ans<<"\n";
    }
    return 0;
}