#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> graph;
vector<bool> visited;
vector<int> sortedGraph;
vector<vector<int>> reversedGraph;
vector<int> longestStart;
vector<int> longestEnd;
vector<int> idInSort;

struct segmT
{
    vector<int> t;
    int k=1;
    segmT(int e)
    {
        while(k<e)
        {
            k=k<<1;
        }
        t.resize(k*2);
    }
    void add(int v, int a, int b, int st, int en, int val)
    {
        if(a>b) return;
        if(st >= a && en<= b)
        {
            t[v]=max(t[v],val);
            return;
        }
        
        int mid = (st+en)/2;

        if(mid>=a){
            add(2*v,a,b,st,mid, val);
        }
        if(mid<b){
            add(2*v+1,a,b,mid+1,en,val);
        }

    }
    int query(int v, int x, int st, int en)
    {
        int mid = (st+en)/2;
        if(st==x && en==x) return t[v];
        if(mid>=x){
            return max(t[v], query(2*v,x,st,mid));
        }
        else{
            return max(t[v], query(2*v+1,x,mid+1,en));
        }
        
    }
};


void DFSsort(int v, vector<vector<int>> &g)
{
    visited[v]=true;
    for(int i=0;i<g[v].size();++i)
    {
        if(!visited[g[v][i]])
            DFSsort(g[v][i],g);
    }
    sortedGraph.push_back(v);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    graph.resize(n+1);
    visited.resize(n+1);
    reversedGraph.resize(n+1);
    longestStart.resize(n+1);
    longestEnd.resize(n+1);
    idInSort.resize(n+1);
    int longestPath{0};

    for(int i=0;i<m;++i)
    {
        int a,b;
        cin>>a>>b;
        graph[a].push_back(b);
        reversedGraph[b].push_back(a);
    }
    for(int i=1;i<=n;++i)
    {   
        if(!visited[i])
            DFSsort(i,reversedGraph);
    }
    for(int i=0;i<n;++i)
    {
        idInSort[sortedGraph[i]]=i;
    }   
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<reversedGraph[sortedGraph[i]].size();++j)
        {
            longestStart[sortedGraph[i]] = max(longestStart[sortedGraph[i]],longestStart[reversedGraph[sortedGraph[i]][j]]);
        }
        if(reversedGraph[sortedGraph[i]].size()) longestStart[sortedGraph[i]]++;
    }
    for(int i=n-1;i>=0;--i)
    {
        for(int j=0;j<graph[sortedGraph[i]].size();++j)
        {
            longestEnd[sortedGraph[i]]= max(longestEnd[sortedGraph[i]],longestEnd[graph[sortedGraph[i]][j]]);
            
        }
        if(graph[sortedGraph[i]].size())longestEnd[sortedGraph[i]]++;
        longestPath=max(longestEnd[sortedGraph[i]],longestPath);
    }
    segmT largestBypass = segmT(n);

    for(int i=1;i<n;++i)
    {
        for(int j=0;j<graph[i].size();++j)
        {
            largestBypass.add(1,idInSort[i]+1, idInSort[graph[i][j]]-1,0,largestBypass.k-1,longestStart[i]+longestEnd[graph[i][j]]+1);
        }
    }
    vector<int> ans(n+1);
    pair<int,int> idans{0,INT_MAX};
    for(int i=1; i<=n;++i)
    {
        if(longestEnd[i]+longestStart[i]==longestPath)
        {
            ans[i]=max(largestBypass.query(1,idInSort[i],0,largestBypass.k-1),max(longestEnd[i]-1, longestStart[i]-1));
            if(idans.second > ans[i])
                idans={i,ans[i]};
        }
       
    }
    cout<<idans.first<<" "<<idans.second;    


    return 0;
}