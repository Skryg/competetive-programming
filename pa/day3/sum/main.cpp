#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n; cin>>n;
	vector<pair<ll,int>> nums(n);
	int it{0};
	for(auto &i : nums){
		cin>>i.first;
		i.second = it++;
	}
	sort(nums.begin(),nums.end());
	vector<ll> pref(n+1);
	vector<bool> ok(n);
	for(int i=1;i<=n;++i){
		pref[i] = pref[i-1] + nums[i-1].first;
	}
	ll smallest{nums[0].first};
	for(int i=1;i<=n && smallest==nums[i-1].first;++i){
		pref[i]=smallest;
	}
	it=n-2;
	while(nums[it].first!=smallest){
		if(nums[it].first == nums[it+1].first){
			pref[it+1]=pref[it+2];
		}
		it--;
	}
	bool f{false};
	if(nums[n-1].first!=smallest) ok[nums[n-1].second]=true;
	else f = true;
	for(int i=n-1;i>0;--i){
		if(f) continue;
		if(pref[i]>nums[i].first){
			ok[nums[i-1].second]=true;
		}
		else f=true;
	}
	for(auto i : ok){
		cout<< (i ? 'T' : 'N');
	}

	return 0;
}
