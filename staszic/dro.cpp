#include <bits/stdc++.h>
#define ST first
#define ND second

#define MOD 1000000
using namespace std;

int n;
vector<vector<short int>> matrix;
vector<vector<int>> ans;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin>>n;
    matrix.resize(n+1,vector<short int>(n+1));
    ans.resize(n+1,vector<int>(n+1));
    for(int i=1;i<=n; ++i){
        for(int j=1;j<=n;++j){
            cin >> matrix[i][j];
        }
    }
    queue<pair<int,int>> q;
    ans[1][1]=1;
    
    
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j){
            if(i==1 && j == 1) continue;
            if(!matrix[i][j]){
                ans[i][j] = (ans[i-1][j] + ans[i][j-1]) % MOD;
            }
        }
    }
    cout<<ans[n][n];
    return 0;
}