#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t; cin>>t;
	while(t--){
		int n; cin>>n;
		vector<int> nums(n);
		vector<int> num_pose(n+1); 
		for(int i=0;i<n;++i){
			cin>>nums[i];
			num_pose[nums[i]] = i;
		}
		vector<int> ans(n);
		
		for(int i=n;i;--i){
			int pos = i-1;
			ans[pos] = (num_pose[i]+1)%i;
			for(int j=1;j<=n;++j){
				num_pose[j]-=ans[pos];
				num_pose[j]+=i;
				num_pose[j]%=i;
			}
		}

		for(auto i : ans) cout<<i<<" ";
		cout<<"\n";
	}

	return 0;
}
