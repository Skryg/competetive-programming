#include <bits/stdc++.h>
#define satori int z; cin>>z; while(z--)
#define vi vector<int>
#define vp vector<pair<int,int>>
using namespace std;

vp twoEnds;
vi oneEnd;

void dfs(int v, vi &mxLen, vi &mxAct, vp& tree, vi& neiNum){
    if(v==-1) return;
    int x = tree[v].first;

    int end1, end2;

    int actMax1=0,actMax2=0;
    if(x==-1){
        mxLen[v] = 1;
        mxAct[v] = 1;

        oneEnd[v] = v;
        twoEnds[v]={v,v};
    }
    while(x!=-1){
        dfs(x,mxLen,mxAct,tree,neiNum);
        if(mxLen[x] > mxLen[v]) twoEnds[v] = twoEnds[x];
        mxLen[v] = max(mxLen[v], mxLen[x]);
        if(mxAct[x] > actMax1){
            actMax2 = actMax1;
            actMax1 = mxAct[x];
            oneEnd[v] = oneEnd[x];

            end2 = end1;
            end1 = oneEnd[x];
        }
        else if(mxAct[x] > actMax2){
            actMax2 = mxAct[x];
            end2 = oneEnd[x];
        }
        x = tree[x].second;
    }    
    mxAct[v] = max(neiNum[v], actMax1+neiNum[v]-2);
    if(neiNum[v] >=  actMax1+neiNum[v]-2) oneEnd[v] = v;
    if(mxAct[v] > mxLen[v]){
        twoEnds[v] = {oneEnd[v], v};
        mxLen[v] = mxAct[v];
    }
    if(actMax1+actMax2+neiNum[v]-4 > mxLen[v]){
        twoEnds[v] = {end1, end2};
        mxLen[v] = actMax1+actMax2+neiNum[v]-4;
    }
    
}

vi path;
bool add = true;
void dfs(int v, int p, int find, vp& tree, vi& parent){
    if(v==-1) return;
    if(!add) return;
    if(add) path.push_back(v);
    if(v==find) add=false;
    int x = tree[v].first;
    while(x!=-1){
        if(x!=p) dfs(x, v,find, tree,parent);
        x = tree[x].second;
    }
    if(parent[v]!=p) dfs(parent[v], v,find, tree, parent);
    if(add) path.pop_back();

}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    satori{
        add = true;
        path.clear();
        int n; cin>>n;
        twoEnds.resize(n);
        oneEnd.resize(n);
        vector<pair<int,int>> tree(n);
        for(auto &[a,b] : tree){
            cin>>a>>b;
        }
        vi parent(n,-1);
        vector<int> neighNum(n);
        for(int i=0;i<n;++i){
            int x = tree[i].first;
            if(x==-1) continue;
            do{
                parent[x]=i;
                ++neighNum[x];
                ++neighNum[i];
                x = tree[x].second;
            } while(x!=-1);
        }
        vector<int> mxLen(n);
        vector<int> mxAct(n);

        dfs(0, mxLen,mxAct, tree, neighNum);
        pair<int, int> ends = twoEnds[0];
        dfs(ends.first,-1, ends.second, tree,parent);

        if(n!=1){
            cout << mxLen[0] << '\n';
            cout << path.size();
            for(auto i : path) cout<< ' '<<i;
        }
        else cout<<"0\n1 0";
        
        cout<<'\n';

    }

    return 0;
} 