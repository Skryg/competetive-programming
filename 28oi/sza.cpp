//Oskar Krygier
#include <bits/stdc++.h>

using namespace std;

int n;
map<string,int> mapp;

struct neigh
{
    int v=0;
    char name='0';
    neigh(int a, char b){
        v = a;
        name =b;
    }
};
vector<vector<neigh>> graph;
vector<bool> visited;




void loadData()
{
    cin>>n;
    graph.resize(n+1);
    visited.resize(n+1,false);
    for(int i=0;i<n;i++)
    {
        int a,b;
        char c;
        cin>>a>>b>>c;
        graph[a].push_back(neigh(b,c));
        graph[b].push_back(neigh(a,c));


    }
}

void DFS(int v, string s)
{
    visited[v]=true;
  
}



int main()
{
    ios_base::sync_with_stdio();
    cin.tie(0);
    
   // loadData();
  
    for(int i=1;i<=n;i++)
    {

    }

    return 0;
}