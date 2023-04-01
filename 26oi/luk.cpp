#include <bits/stdc++.h>

using namespace std;

int n;

struct vTree
{
    int id=0, parent=0, distance=0, d=0;

    vTree()
    {

    }
};
vector<vTree> vs;
vector<vector<int>> tree;
vector<vTree> vsSorted;

void loadData()
{

    cin>>n;
    tree.resize(n+1);
    vs.resize(n+1);

    for(int i=0;i<vs.size();i++)
    {
        vs[i].id = i;
    }

    for(int i=0;i<n-1;i++)
    {
        int a,b;
        cin >> a >>b;
        tree[a].push_back(b);
        tree[b].push_back(a);

    }
    vs[1].distance=0;
    vs[1].parent = 0;
}


queue<int> bfsQueue; 
vector<bool> visited;
void BFS(int v)
{
    visited.resize(n+1);
    
    bfsQueue.push(v);
    while(!bfsQueue.empty())
    {
        int w = bfsQueue.front();
        bfsQueue.pop();
        visited[w] = true;
        for(int i=0;i<tree[w].size();i++)
        {
            if(!visited[tree[w][i]])
            {
                bfsQueue.push(tree[w][i]);
                vs[tree[w][i]].parent=w;
                vs[tree[w][i]].distance = vs[w].distance+1;
            } 
        }
    }
    
}

bool treeDisComp(vTree t1, vTree t2)
{
    if(t1.distance == t2.distance)
        return t1.id > t2.id;
    return t1.distance > t2.distance;
}

void orderByDis()
{
    vsSorted = vs;
    sort(vsSorted.begin(),vsSorted.end(),treeDisComp);
}

bool check(int k)
{
    for(int i=0;i<=n;i++)
    {
        if(vsSorted[i].id == 1 || tree[vsSorted[i].id].size()!=1)
        {
            int sum = 0;
            
            for(int j=0;j<tree[vsSorted[i].id].size();j++)
            {
            
                if(vsSorted[i].parent!=tree[vsSorted[i].id][j])
                {
                    sum+=(vs[tree[vsSorted[i].id][j]].d+1);
                }
            }
            vs[vsSorted[i].id].d = max(sum-k, 0);
            

        }
    }
    if(vs[1].d>0) return false;
    else return true;
}

int binSearch()
{
    int first = 1, last = n,k=0;
    while(first != last)
    {
        int mid = (first+last)/2;
        if(check(mid))
        {//git
            k=mid;
            last = mid;
        }
        else
            first = mid+1; 
    }

    return k;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    loadData();
    BFS(1);
    orderByDis();
   
    
    int wyn= binSearch();;
    cout<<wyn;
    
    return 0;
}