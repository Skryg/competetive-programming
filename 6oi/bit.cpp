#include <bits/stdc++.h>

using namespace std;

vector<bool> visited;
vector<int> number;
vector<vector<int>> graph;

queue<pair<int,int>> bfsQ;

int n,m;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    string tab[n];
    for(int i=0;i<n;++i)
    {
        cin>>tab[i];
    }
    visited.resize(n*m);
    number.resize(n*m);
    graph.resize(n*m);

  
    
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<m;++j)
        {
            int n=tab[i][j]-'0';
            if(n==1) bfsQ.push({i*m+j,0});
        }
    }
    for(int i=0;i<n*m;++i)
    {
        //right
        if(i+1<n*m && i%m!=m-1) graph[i].push_back(i+1);
        //left
        if(i-1>=0 && i%m!=0) graph[i].push_back(i-1);
        //up
        if(i-m>= 0) graph[i].push_back(i-m);
        //down
        if(i+m<n*m) graph[i].push_back(i+m);
    }
    pair<int,int> curr;
    while(!bfsQ.empty())
    {
        curr = bfsQ.front();
        bfsQ.pop();
        if(visited[curr.first]) continue;
        visited[curr.first] = true;
        number[curr.first] = curr.second;
        for(int i=0;i<graph[curr.first].size();++i)
        {
            if(!visited[graph[curr.first][i]])
                bfsQ.push({graph[curr.first][i],curr.second+1});
        }
    }
    for(int i=0;i<n*m;++i)
    {
        if(i!=0&& i%m==0) cout<<"\n";
        cout<<number[i]<<" ";
    }

}

