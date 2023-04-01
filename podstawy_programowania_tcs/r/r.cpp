#include <bits/stdc++.h>
 
#define satori int z; cin>>z; while(z--)
 
using namespace std;
 
vector<vector<int>> tab;
stack<pair<int,int>> path;
 
bool good(int x, int y, bool line){
    return tab[x][y] == 0 || (tab[x][y] == 2 && line);
}
 
bool dfs(int x, int y, tuple<int,int> tup, bool line, tuple<int, int> dest){
    auto [a,b] = tup;
    if(!tab[x][y]) tab[x][y]=1;
    else if(tab[x][y]==2) line = false;
    else return false;
 
    bool ok = false;
    auto [x1, y1] = dest;
    if(x==x1 && y==y1) ok=true;
    if(!ok && good(x+a, y+b, line)) ok = dfs(x+a, y+b, {a, b}, line,dest);
    else{
        if(!ok && good(x+1, y, line)) ok = dfs(x+1, y, {1, 0},line,dest);
        if(!ok && good(x-1, y, line)) ok = dfs(x-1, y, {-1,0},line,dest);
        if(!ok && good(x, y+1, line)) ok = dfs(x, y+1, {0, 1},line,dest);
        if(!ok && good(x, y-1, line)) ok = dfs(x, y-1, {0,-1},line,dest);
    }
 
    if(ok){
        path.push({x,y});
    }
    if(tab[x][y]==1) tab[x][y]=0;
    return ok;
}
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
 
    satori{
        int n,m; cin>>n>>m;
        tab  = vector<vector<int>>(n+2, vector<int>(m+2, 1));
        int x,y,x1,y1; cin>>x>>y>>x1>>y1;
 
        for(int i=1;i<=n;++i){
            for(int j=1;j<=m;++j){
                cin >> tab[i][j];
            }
        }
        bool git = dfs(x,y, {0,0}, true, {x1,y1});
        if(git){
            cout<<"TAK "<<path.size() <<'\n';
            auto [a,b] = path.top();
            cout<<a<<' '<<b;
            path.pop();
            while(!path.empty()){
                auto [a,b] = path.top();
                cout<<", "<<a<<' '<<b;
                path.pop();
            }
            cout<<'\n';
        }
        else cout<<"NIE\n";
        while(!path.empty()) path.pop();
        tab.clear();
 
    }
 
 
    return 0;
}
