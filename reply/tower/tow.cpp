#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t; cin>>t;
    for(int t2=1; t2<=t; ++t2){
        int n,level,p; cin>>n>>level>>p;
        vector<vector<int>> dp(n, vector<int>(p+1));
        vector<vector<vector<vector<pair<int,int>>>>> prev_a(n);
        for(int i=0;i<n;++i){
            int id, s, l;
            cin>>id>>s>>l;
            vector<vector<vector<int>>> distances(s+1,vector<vector<int>>(s+2, vector<int>(p+2, INT_MAX)));
            prev_a[id] = vector<vector<vector<pair<int,int>>>>(s+1,
                vector<vector<pair<int,int>>>(s+2, vector<pair<int,int>>(p+2)));
            auto &prev = prev_a[id]; 
            vector<vector<char>> tab(s+2,vector<char>(s+2));
            pair<int,int> first,end;
            for(int j=1;j<=s; ++j){
                for(int k=1;k<=s;++k){
                    cin>>tab[j][k];
                    if(tab[j][k]=='I') first = {j,k};
                    if(tab[j][k]=='O') end = {j,k};
                }
            }
            //x, y, monsters, distance, prev
            queue<tuple<int,int,int,int,pair<int,int>>> que;
            que.push({first.first, first.second, 0, 0, {-1,-1}});

            while(que.size()){
                auto [x, y, mon, dist, pre] = que.front();
                que.pop();
                if(x<=0 || x>s || y<=0 || y>s) continue;
                if(tab[x][y] == 'M') mon++;

                if(distances[x][y][mon] <= dist) continue;
                distances[x][y][mon] = dist;
                prev[x][y][mon] = pre;

                if(end.first == x && end.second == y){ 
                    dp[id][mon] = min(dp[id][mon], dist);
                    continue;
                }
                if(dist >= p) continue;
                
                que.push({x+1,y, mon, dist+1, {x,y}});
                que.push({x-1,y, mon, dist+1, {x,y}});
                que.push({x,y+1, mon, dist+1, {x,y}});
                que.push({x,y-1, mon, dist+1, {x,y}});

            }
            for(auto &d : dp[id]){
                if(d!=INT_MAX) d*=l;
            }  

        }


        string ans;
        cout<<"Case #"<<t2<<": "<< ans<<"\n";
    }

    return 0;
}