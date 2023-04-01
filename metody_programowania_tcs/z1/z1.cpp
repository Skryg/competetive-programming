#include <bits/stdc++.h>
#define satori int z; cin>>z; while(z--)

using namespace std;

int n,m,k;
int cnt=0;
int val;
void dfs(vector<vector<int>> &age,vector<vector<bool>> &vis,int x,int y){
    if(vis[x][y] || age[x][y]>val) return;
    vis[x][y]=true;
    cnt++;
    if(cnt == k) return;
    dfs(age,vis,x+1,y);
    dfs(age,vis,x-1,y);
    dfs(age,vis,x,y+1);
    dfs(age,vis,x,y-1);
}

bool check(vector<vector<int>> &age,vector<vector<bool>> &vis){
    for(int i=0;i<vis.size();++i)
        for(int j=0;j<vis[i].size();++j) 
            vis[i][j]=false;
    

    for(int i=1;i<=n;++i){
        for(int j=1;j<=m;++j){
            cnt=0;
            dfs(age,vis,i,j);
            if(cnt >= k) return true;
        }
    }
    return false;

}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    satori{
        cin>>n>>m>>k;

        vector<vector<int>> age(n+2, vector<int>(m+2, INT_MAX));
        vector<vector<bool>> vis(n+2, vector<bool>(m+2, false));
        int mx=0;
        for(int i=1;i<=n;++i){
            for(int j=1;j<=m;++j){
                cin>>age[i][j];
                mx=max(mx,age[i][j]);
            }
        }

        int ans=-1;
        int first = 0, last = mx;
        while(first<=last){
            int mid = (first+last)/2;
            val=mid;
            if(check(age,vis)){
               ans = mid; 
               last = mid-1;
            }
            else first = mid+1;
        }

        cout<<ans<<'\n';
    }

    return 0;
}