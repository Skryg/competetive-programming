#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

constexpr ll mod=1'000'000'007LL;

bool good_num(ll num){
	if(num%mod%2) return false;
	return true;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n; cin>>n;
	vector<ll> input(n);
	for(auto &i : input){
		cin>>i;
	}
	vector<ll> pref_sums(n+1);
	vector<ll> pref_ans(n+1);
	for(int i=1;i<=n;++i){
		pref_sums[i] = pref_sums[i-1]+input[i-1];
	}
	pref_ans[0]=1;
	for(int i=1;i<=n;++i){
		if(!pref_ans[i-1]) continue;
		for(int j=i;j<=n;++j){
			if(good_num(pref_sums[j]-pref_sums[i-1])){
				pref_ans[j]+=pref_ans[i-1];
				pref_ans[j]%=mod;
			}
		}
	}
	cout<<pref_ans[n];
	return 0;
}
