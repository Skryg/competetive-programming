#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t; cin>>t;
    while(t--){
        long long n,x; cin>>n>>x;
        vector<long long> nums(n);
        map<long long, long long> mp;
        for(auto &i : nums) {
            cin>>i;
            if(mp.find(i)==mp.end()) mp[i]=0;
            mp[i]++;
        }
        int ans{0};
        sort(nums.begin(), nums.end());
        for(auto i : nums){
            if(!mp[i]) continue;
            if(mp.find(x*i)!=mp.end() && mp[x*i]!=0){
                mp[x*i]--;
            }
            else{
                ans++;
            }
            mp[i]--;
        }
        cout<<ans<<"\n";


    }

    return 0;

}