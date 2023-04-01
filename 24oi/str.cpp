#include <bits/stdc++.h>

using namespace std;


int n,m;
int ans{1};

struct v
{
    
    bool a{true},visited{false};
    int ch{0};
    
    vector<int> neigh;
    v(){}
};

vector<v> tree;
vector<int> anc;


vector<int> queries;
vector<int> answers;


void loadData()
{
    cin>>n;
    tree.resize(n+1);
    anc.resize(n+1,0);
    for(int i=0;i<n-1;++i)
    {
        int a,b;
        cin>>a>>b;
        tree[a].neigh.push_back(b);
        tree[b].neigh.push_back(a);
    }
    tree[1].ch = tree[1].neigh.size();

    for(int i=2;i<=n;++i)
    {
        tree[i].ch = tree[i].neigh.size()-1;
    }
    cin>>m;
    for(int i=0;i<m;++i)
    {
        int a;
        cin>>a;
        queries.push_back(a);
    }
    answers.resize(m);
}

void DFS(int v, int a)
{
    anc[v] = a;
    tree[v].visited = true;
    for(int i=0;i<tree[v].neigh.size();i++)
    {
        if(!tree[tree[v].neigh[i]].visited)
        {
            DFS(tree[v].neigh[i],v);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    loadData();
    DFS(1,0);
    tree[0].a = false;
    for(int i=0;i<m;++i)
    {
        int a = queries[i];
        if(a<0)
        {
            a=-a;
            tree[a].a = true;
            if(tree[anc[a]].a)
                --ans;
            ++tree[anc[a]].ch;
            ans-=(tree[a].ch-1);
        }
        else
        {
            if(tree[anc[a]].a)
                ++ans;
            --tree[anc[a]].ch;
            tree[a].a = false;
            ans+=(tree[a].ch-1);

        }
        answers[i]=ans;
    }
    for(auto i : answers)
    {
        cout<<i<<"\n";
    }
    
    return 0;
}