#include <bits/stdc++.h>

using namespace std;
vector<vector<int>> x(40001,vector<int>(3));
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    vector<int> b(n),c(n);
    for(int i=0;i<n;++i){
        cin>>b[i];
    }
    for(int i=0;i<n;++i){
        cin>>c[i];
    }
    int k;
    cin>>k;
    for(int i=n-1;i>=0;--i){
        if(b[i]>k) continue;
        for(int j = 1; j <= c[i]; ++j){
            if(b[i]*j>k) break;
            for(int g = k-b[i]; g>=0; --g){
                if(x[g][0]>0 || g==0){
                    if(x[g+b[i]][0]>x[g][0]+1||x[g+b[i]][0]==0){
                        x[g+b[i]][0] = x[g][0]+1;
                        x[g+b[i]][1] = b[i];
                        x[g+b[i]][2] = i;
                        
                   }
               }
           }
        }
        if(x[k][0]!=0) break; 
    }
    cout<<x[k][0]<<"\n";
    vector<int> ans(n);
    int zz{k};
    while(zz!=0)
    {
        ++ans[x[zz][2]];
        zz-=x[zz][1];
    }
    for(int i : ans){
        cout<<i<<" ";
    }
    return 0;
}