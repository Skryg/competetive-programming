#include <bits/stdc++.h>
#define satori int z; cin>>z; while(z--)

using namespace std;

bool check_mid(vector<long long> &v, long long num){
	long long sum=0;
	int cut = 0;
	for(int i=0;i<v.size();++i){
		sum+=v[i];
		if(sum%num==0){
			sum = 0;
			cut++;
		}
	}
	return (sum==0 && cut>1);
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	satori{

		int n; cin>>n;
		vector<long long> nums(n);
		for(auto &i : nums) cin>>i;
		long long ans = 1;
		long long mi=5, mx=5;// mx=1'000'000'000'000'000LL;

		while(mi<=mx){
			long long mid = (mi+mx)/2;
			if(check_mid(nums,mid)){
				ans = max(ans, mid);
				mi = mid+1;
			}
			else{
				mx = mid-1;
			}
		}

		cout<<ans<<'\n';


	}
	
	return 0;
}
