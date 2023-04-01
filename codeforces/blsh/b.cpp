#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n; cin>>n;
    vector<int> nums(n);
    for(auto &i : nums) cin>>i;
    long long ans{0};
    priority_queue<int> pq;
    for(auto val : nums){
        val = -val;
        pq.push(val);
        if(pq.size() && pq.top()>val){
            ans+=pq.top()-val;
            pq.push(val);
            pq.pop();
        }
    }
    cout<<ans;

    return 0;
}
