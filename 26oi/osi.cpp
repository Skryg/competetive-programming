#include <bits/stdc++.h>

using namespace std;

int n,m;

struct pathInput
{
    int first=0, second=0;
    bool swapped=false, toRight= false,used=false, blocked = false;
    int id;
};

vector<pathInput> inp;
vector<vector<int>> sta;
vector<vector<int>> graph;
vector<vector<int>> reversedGraph;
vector<bool> visited;
stack<int> order;



bool pathInputComp(pathInput p1, pathInput p2)
{
    if(p1.first< p2.first) return true;
    if(p1.first == p2.first)
    {
        return (p1.second < p2.second);
    }
    else return false;
}

bool sortById(pathInput p1, pathInput p2)
{
    return p1.id < p2.id;
}

int binarySearch(pair<int,int> toSeek)
{
    int first=0,last=m-1;
    
    while(last != first)
    {
        int mid = (first+last)/2;
        if(toSeek.first < inp[mid].first)
            last = mid-1;
        else if(toSeek.first == inp[mid].first)
        {
            if(toSeek.second < inp[mid].second)
                last = mid-1;
            else if(toSeek.second == inp[mid].second) last = mid;

            else first = mid+1;

        }
        else first = mid+1;
    }
    return first;
    
}

/*void buildGraph()
{
    graph.resize(n+1);

    graph[inp[0].first].push_back(inp[0].second);
    graph[inp[0].second].push_back(inp[0].first);
    for(int i=1; i<m;i++)
    {
        if(inp[i-1].first!=inp[i].first||inp[i-1].second!=inp[i].second)
        {
            graph[inp[i].first].push_back(inp[i].second);
            graph[inp[i].second].push_back(inp[i].first);
        }
    }
}*/

void setGraph(int id)
{
    //dfs
    while(!sta[id].empty())
    {
        int next = sta[id].back();
        int a = sta[id].back();
        int b = id;
        if(a>b) swap(a,b);
        sta[id].pop_back();
        int d=binarySearch({a,b});
        if(inp[d].used && d<m-1 && inp[d+1].first == inp[d].first && inp[d+1].second == inp[d].second) d++;
        if(!inp[d].used)
        {
            inp[d].used = true;
            graph[id].push_back(next);
            setGraph(next);
        }
        
    }

}

void reverseGraph()
{
    reversedGraph.resize(n+1);
    for(int i=1;i<graph.size();i++)
    {
        for(int j=0;j<graph[i].size();j++)
        {
            reversedGraph[graph[i][j]].push_back(i);
        }
    }
}

void DFSback(int id)
{
    
    visited[id]=true;
    for(int i=0;i<graph[id].size();i++)
    {
        if(!visited[graph[id][i]])
        {
            DFSback(graph[id][i]);
        }
    }
    order.push(id);
}

void SCC(int id)
{
    visited[id]=true;
    for(int i=0;i<reversedGraph[id].size();i++)
    {
        if(!visited[reversedGraph[id][i]]) SCC(reversedGraph[id][i]);
    }
}

void loadData()
{
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        pathInput p;
        cin>>p.first>>p.second;
        p.id = i;
        if(p.first > p.second)
        {
            swap(p.first, p.second);
            p.swapped=true;
        }
        inp.push_back(p);
    
    }
    sort(inp.begin(),inp.end(),pathInputComp);

    sta.resize(n+1);
    for(int i=0;i<m;i++)
    {
        sta[inp[i].first].push_back(inp[i].second);
        sta[inp[i].second].push_back(inp[i].first);
   
    }
    visited.resize(n+1, false);
    graph.resize(n+1);
    for(int i=1;i<=n;i++)
    {
        setGraph(i);
    }
    
}



int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    loadData();

    vector<vector<int>>().swap(sta);
    for(int i=1;i<=n;i++)
    {
        if(!visited[i]) DFSback(i);
    }
    fill(visited.begin(),visited.end(),false);
    reverseGraph();
    int iteration=0;
    while(!order.empty())
    {

        int id = order.top();
        if(!visited[id])
        {
            SCC(id);
            iteration++;
        }
        order.pop();
    }
    stack<int>().swap(order);
    for(int i=0;i<m;i++)
    {
        inp[i].used=false;
    }
    cout<< iteration<<"\n";

    for(int i=1;i<inp.size();i++)
    {
        if(!inp[i-1].blocked && !inp[i].blocked && inp[i].first == inp[i-1].first && inp[i].second == inp[i-1].second)
        {
            inp[i].blocked = true;
            inp[i-1].blocked = true;
            inp[i].toRight = true;
            inp[i-1].toRight = false;
        }
    }

    for(int i=1;i<graph.size();i++)
    {
        for(int j=0;j<graph[i].size();j++)
        {
            int a=i,b=graph[i][j];
            if(a>b) swap(a,b);
            int find = binarySearch({a,b});
            /*if(blocked && inp[find].used)
            {
                if((inp[find].swapped && (!inp[find+1].swapped))||((!inp[find].swapped) && (inp[find+1].swapped)))
                    inp[find+1].toRight = inp[find].toRight;
                else
                    inp[find+1].toRight = !inp[find].toRight; 
            }*/
            if(!inp[find].blocked)
            {
                inp[find].used = true;
                if(i<graph[i][j]) inp[find].toRight=true;
                else inp[find].toRight = false;
            }
        }
        
        
    }
    sort(inp.begin(),inp.end(),sortById);

    for(int i=0;i<inp.size();i++)
    {
        char toWrite='<';
        if((inp[i].toRight&&!inp[i].swapped) || (!inp[i].toRight&&inp[i].swapped))
            toWrite = '>';
        cout<<toWrite;
    }

    return 0;
}