#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t; cin>>t;
	while(t--){
		int n; cin>>n;
		vector<ll> nums(n);
		ll sum{0}, mx{0},ans{0};
		for(auto &i : nums){
			cin>>i;
			sum+=i;
			mx = max(mx, i);
		}
		if(!sum) ans=0;
		else{
			sum-=mx;
			
			mx-=(sum);
			
			ans=(max(mx,1LL));
		}
		
		cout<<ans<<"\n";

	}

	
	return 0;
}
