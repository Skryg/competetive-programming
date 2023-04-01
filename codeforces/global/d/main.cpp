#include <bits/stdc++.h>
using namespace std;

#define satori int t; cin>>t; while(t--)

#define pb push_back
#define vt vector

vt<vt<int>> graph;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    satori{
        int n; cin>>n;
        vt<int> anc(n+1);
        vt<bool> visited(n+1);
        int root{0};
        for(int i=1;i<=n;++i){
            int a; cin>>a;
            anc[i]=a;
            if(i==a) root = a;
        }
        vt<int> permut(n);
        vt<int> costs(n+1);
        vt<int> costs_sum(n+1);
        for(auto &i : permut){
            cin>>i;
        }
        int act_cost{0};
        if(permut[0]==root){
            visited[root]=true;
            costs[root]=0;
        }
        else {cout<<"-1\n"; continue;}
        bool bad{false};
        for(int i=1;i<n;++i){
            if(visited[anc[permut[i]]]){
                act_cost++;
                costs[permut[i]] = act_cost-costs_sum[anc[permut[i]]];
                costs_sum[permut[i]]= act_cost;
                visited[permut[i]]=true;
            }
            else { bad=true; break;}
        }
        if(bad){
            cout<<"-1\n"; continue;
        }
        for(int i=1;i<costs.size();++i){
            cout<<costs[i]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}