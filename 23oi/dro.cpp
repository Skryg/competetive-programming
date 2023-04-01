#include <bits/stdc++.h>

using namespace std;

int n,m;
vector<vector<int>> graph,reversedGraph;
vector<bool> visited;
vector<int> sccNum;
vector<vector<int>> graphSCC, reversedSCC;
vector<int> topoSorted;
vector<int> lParent,revParent;
bitset<500001> bit;
vector<int> vs;
vector<int> answer;
struct minTree
{
    int k=1;
    vector<pair<int,int>> tr;
    minTree(int n)
    {

        while(k<n)
        {
            k*=2;
        }
        tr.resize(k*2,{INT_MAX,-1});

    }

    void refreshMin(int v)
    {
        if(v==0) return;
        tr[v].first=min(tr[v*2].first,tr[v*2+1].first);
        refreshMin(v/2);
    }

    void refreshMax(int v)
    {
        if(v==0) return;
        tr[v].second=max(tr[v*2].second,tr[v*2+1].second);
        refreshMax(v/2);
    }

    void changeMin(int id, int value)
    {
        tr[id+k].first=value;
        refreshMin((id+k)/2);

    }

    void changeMax(int id, int value)
    {
        tr[id+k].second=value;
        refreshMax((id+k)/2);

    }

    int minimal()
    {
        return tr[1].first;
    }
    int maximal()
    {
        return tr[1].second;
    }
};



void loadData()
{
    cin>>n>>m;
    graph.resize(n+1);
    visited.resize(n+1);
    sccNum.resize(n+1);
    
    reversedGraph.resize(n+1);
    for(int i=0;i<m;++i)
    {
        int a,b;
        cin>>a>>b;
        graph[a].push_back(b);
        reversedGraph[b].push_back(a);
    }
}

stack<int> st;

void DFS(int v)
{
    visited[v]=true;
    for(int i=0;i<graph[v].size();++i)
    {
        if(!visited[graph[v][i]])
        {
            DFS(graph[v][i]);
        }
    }
    st.push(v);

}

void DFSback(int v,int it)
{
    visited[v]=true;
    for(int i=0;i<reversedGraph[v].size();++i)
    {
        if(!visited[reversedGraph[v][i]])
            DFSback(reversedGraph[v][i], it);
    }
    sccNum[v]=it;
}

void SCC()
{
    for(int i=1;i<=n;++i)
    {
        if(!visited[i])
        {
            DFS(i);
        }
    }
    fill(visited.begin(),visited.end(),0);
    int it =0;
    while(!st.empty())
    {
        if(!visited[st.top()])
            DFSback(st.top(),++it);
        st.pop();
    }
    vs.resize(it+1);
    graphSCC.resize(it+1);
    reversedSCC.resize(it+1);
    lParent.resize(it+1,-1);
    lParent[0]=INT_MAX;
    revParent.resize(it+1);
    for(int i=1;i<=n;++i)
    {
        for(int j=0;j<graph[i].size();++j)
        {
            if(sccNum[i]!=sccNum[graph[i][j]])
            {
                graphSCC[sccNum[i]].push_back(sccNum[graph[i][j]]);
                reversedSCC[sccNum[graph[i][j]]].push_back(sccNum[i]);
            }
        }
    }
    
}

void topoDFS(int v)
{
    visited[v]=true;
    for(int i=0;i<graphSCC[v].size();++i)
    {
        if(!visited[graphSCC[v][i]]) topoDFS(graphSCC[v][i]);
    }
    st.push(v);
}

void topoSort()
{
    fill(visited.begin(),visited.end(),0);
    for(int i=1;i<graphSCC.size();++i)
    {
        if(!visited[i]) topoDFS(i);
    } 
    while(!st.empty())
    {
        topoSorted.push_back(st.top());
        st.pop();
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    loadData();
    SCC();
    topoSort();
    for(int i=0;i<topoSorted.size();++i)
    {
        for(int j=0; j<graphSCC[topoSorted[i]].size();++j)
        {
            lParent[graphSCC[topoSorted[i]][j]]=i;
        }
    }
    for(int i=topoSorted.size()-1; i>=0; --i)
    {
        for(int j=0; j<reversedSCC[topoSorted[i]].size();++j)
        {
            revParent[reversedSCC[topoSorted[i]][j]]=i;
        }
    }
    for(int i=1;i<revParent.size();++i)
    {
        if(revParent[i]==0)
        {
            revParent[i]=INT_MAX;
        }
    }
    minTree mt = minTree(lParent.size());
    for(int i=1;i<lParent.size();++i)
    {
        mt.changeMin(i,lParent[i]);
    }
    for(int i=1;i<lParent.size();++i)
    {
        mt.changeMin(i,INT_MAX);
        if(mt.minimal()>=i-1 && mt.minimal()!=-1) ++vs[topoSorted[i-1]];
    }
   
    for(int i=revParent.size()-1;i>0;--i)
    {
        mt.changeMax(i,revParent[i]);
    }
    for(int i=revParent.size()-1;i>0;--i)
    {
        mt.changeMax(i,-1);
        if(mt.maximal()<=i-1 && mt.maximal()!=INT_MAX) ++vs[topoSorted[i-1]];
    }

    for(int i=1;i<=n;++i)
    {
        if(vs[sccNum[i]]==2) answer.push_back(i);
    }
    cout<<answer.size()<<"\n";
    for(int i=0;i<answer.size();++i)
    {
        cout<<answer[i]<<" ";
    }

    return 0;
}