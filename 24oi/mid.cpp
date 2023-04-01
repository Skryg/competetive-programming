#include <bits/stdc++.h>

#define ST first
#define ND second

using namespace std;

typedef long long ll;

vector<pair<int, int>> tr, tr2;
vector<int> scale;
vector<int> dep;
vector<vector<int>> anc;
void dfs2(int v, int vt2)
{
    if(v==0) return;
    scale[v] = vt2;
    if(tr[v].ST != 0)
    {
        if(tr2[vt2].ST == 0)
        {
            tr2[vt2].ST = tr2.size();
            tr2.push_back({0,0});
        }
        
        dfs2(tr[v].ST, tr2[vt2].ST);
    }
    if(tr[v].ND != 0)
    {
        if(tr2[vt2].ND == 0)
        {
            tr2[vt2].ND = tr2.size();
            tr2.push_back({0,0});
        }

        dfs2(tr[v].ND, tr2[vt2].ND);
    }
    
    

}

void dfs1(int v)
{
    if(tr[v].ND != 0)
    {
        if(tr2.size()==1) tr2.push_back({0,0});
        dfs2(tr[v].ND,1);
        
    } 
    if(tr[v].ST != 0) dfs1(tr[v].ST);
}

void depth(int v, int d)
{
    if(v==0) return;

    dep[v]=d;
    depth(tr2[v].ST, d+1);
    depth(tr2[v].ND, d+1);
    
}

void makean(int v, int a)
{
    if(v==0) return;
    anc[v][0] = a;
    for(int i=1;i<=20;++i)
    {
        anc[v][i] = anc[anc[v][i-1]][i-1];
    }
    makean(tr2[v].ST, v);
    makean(tr2[v].ND, v);
}

int lca(int a, int b)
{
    if(dep[a] != dep[b])
    {
        if(dep[b]<dep[a]) swap(a,b);
        for(int i=20;i>=0;--i)
            if(dep[anc[b][i]]>= dep[a]) b  = anc[b][i];
        if(a == b) return a;
    }
    for(int i=20;i>=0; --i)
    {
        if(anc[a][i]!=anc[b][i])
        {
            a = anc[a][i];
            b = anc[b][i];
        }
    }
    return anc[a][0];

}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin>>n;

    tr.resize(n+1);
    scale.resize(n+1);
    for(int i=1;i<=n;++i)
    {
        cin >> tr[i].ST >> tr[i].ND;
    }
    tr2.push_back({0,0});
    dfs1(1);
    if(tr2.size()>1)
    {
        anc.resize(tr2.size(), vector<int>(21));
        dep.resize(tr2.size());
        fill(anc[1].begin(),anc[1].end(),1);
        makean(1,1);
        depth(1,1);
    }
    int z;
    cin>>z;
    while(z--)
    {
        int a,b;
        cin>>a>>b;
        if(scale[b]==0)
        {
            cout<<"TAK\n";
            continue;
        }
        if(scale[b]!= 0 && scale[a]==0)
        {
            cout<<"NIE\n";
            continue;
        }
        if(dep[scale[a]] == dep[scale[b]])
        {
            if(scale[a]==scale[b]) {
                cout<<"TAK\n";
                continue;
            }
            int lc = lca(scale[a],scale[b]);
            cout <<(lca(tr2[lc].ND,scale[a]) == tr2[lc].ND || scale[a] == tr2[lc].ND ? "TAK\n": "NIE\n");
            
        }
        else
        {
            cout<< (dep[scale[a]] > dep[scale[b]] ? "TAK\n" : "NIE\n"); 
        }
    }


    return 0;
}