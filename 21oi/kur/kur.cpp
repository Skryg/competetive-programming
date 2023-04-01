#include <bits/stdc++.h>

using namespace std;

constexpr int RND = 30;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,m; cin>>n>>m;
    srand(2137);
    vector<int> nums(n+1);
    vector<int> counter(n+1);

    vector<int> semi_ans(m);
    vector<pair<int,int>> ans(m);
    vector<pair<int,int>> iv(m);
    vector<vector<int>> randoms(m,vector<int>(RND));
    vector<tuple<int,int,bool,int>> points;


    for(int i=1;i<=n;++i) cin >> nums[i];
    
    for(int i=0;i<m;++i){
        auto &[a,b] = iv[i]; 
        cin>>a>>b;
        
        for(auto &x : randoms[i]){
            x = nums[(rand()%(b-a+1) + a)];
        }
    }

    for(int i=0;i<RND; ++i){
        
        fill(counter.begin(),counter.end(),0);
        fill(semi_ans.begin(),semi_ans.end(),0);
        for(int j=0;j<m;++j){
            auto [a,b] = iv[j];
            //iv end/start; random number; is closing; num of iv;
            points.emplace_back(a-1, randoms[j][i], false, j);
            points.emplace_back(b, randoms[j][i], true, j);
        }

        sort(points.begin(),points.end());

        int x = 0;
        int st = get<0>(points[x]);
        for(int j=0;j<=n;++j){
            counter[nums[j]]++;
            while(x < points.size() && st == j){
                auto [a,rand,close,id] = points[x];
                semi_ans[id]+= (close ? counter[rand] : -counter[rand]);
                x++;
                if(x < points.size()) st = get<0>(points[x]);
            }

        }
        for(int j=0;j<m;++j){
            if(semi_ans[j] > ans[j].first){
                ans[j] = {semi_ans[j], randoms[j][i]};
            }
        }

    }

    for(int i=0;i<m;++i){
        auto [a,b] = iv[i];
        int len = (b-a+1)/2;
        auto [x,y] = ans[i];
        cout<< (x > len ? y : 0)<<"\n";

    }

    return 0;
}