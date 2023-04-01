#include <bits/stdc++.h>

using namespace std;

int n,m;

struct vertex
{
    int sccNum=0, next=0;
    vertex(int n){next=n;}
};

vector<vector<int>> graph;
vector<vector<int>> reversedGraph;
vector<bool> visited;
vector<bool> visitedSCC;
vector<int> sccNum;
vector<int>sccCount;
vector<long long> sum;
stack<int> scc;
vector<vector<int>> sccGraph;
void loadData()
{
    cin>>n>>m;
    graph.resize(n+1);
    reversedGraph.resize(n+1);
    for(int i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;
        graph[a].push_back(b);
        reversedGraph[b].push_back(a);

    }
}

void DFSback(int v)
{
    visited[v] = true;
    for(int i=0;i<reversedGraph[v].size();i++)
    {
        if(!visited[reversedGraph[v][i]])
        {
            DFSback(reversedGraph[v][i]);
        }
    }
    scc.push(v);
}

void DFS1(int v, int it)
{
    visited[v]=true;
    sccNum[v]=it;
    for(int i=0;i<graph[v].size();i++)
    {
        if(!visited[graph[v][i]])
        {
            DFS1(graph[v][i],it);
        }
    }
}

void findSCC()
{
    int i=0;
    while(!scc.empty())
    {
        int v = scc.top();
        scc.pop();
        if(!visited[v])
        {
            DFS1(v,++i);
        }
    }
    sccGraph.resize(i+1);
    sccCount.resize(i+1,0);
    visitedSCC.resize(i+1,0);
    sum.resize(i+1,0);
    for(int i=1;i<graph.size();i++)
    {
        for(int j=0;j<graph[i].size();j++)
        {
            if(sccNum[i]!=sccNum[graph[i][j]])
            {
                sccGraph[sccNum[i]].push_back(sccNum[graph[i][j]]);
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        sccCount[sccNum[i]]++;
    }
}

void DFSonSCC(int v)
{
    visitedSCC[v]=true;
    long long s=0;
    for(int i=0;i<sccGraph[v].size();i++)
    {
        if(!visitedSCC[sccGraph[v][i]])
        {
            DFSonSCC(sccGraph[v][i]);
        }
        s+=sum[sccGraph[v][i]];
    }
    s+=sccCount[v];
    sum[v]=s;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    loadData();
    visited.resize(n+1,false);
    sccNum.resize(n+1,0);
    
    for(int i=1;i<=n;i++)
    {
        if(!visited[i])
            DFSback(i);
    }
    fill(visited.begin(),visited.end(),0);
    findSCC();

    for(int i=1;i<sccGraph.size();i++)
    {
        if(!visitedSCC[i])
            DFSonSCC(i);
    }
    for(int i=1;i<=n;i++)
    {
        long long write = sum[sccNum[i]]-1;
        cout << write <<"\n";
    }

    return 0;
}