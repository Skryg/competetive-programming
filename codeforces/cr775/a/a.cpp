#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int t; cin>>t;
	while(t--){
		int n; cin>>n;
		int cost{0};
		int ans{0};
		vector<int> nums(n);
		for(auto &i : nums) cin>>i;
		int x=0,y=n-1;
		while(x<n && nums[x]){
			x++;
		}
		while(y>=0 && nums[y]){
			y--;
		}
		if(x==n) ans=0;
		else{
			x--;
			y++;
			ans = y-x;
		}
		cout<<ans<<"\n";
	}
	
	return 0;
}
