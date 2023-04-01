#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n,k; cin>>n>>k;
	int nums[121]={0};
	for(int i=0;i<n;++i){
		int a; cin>>a;
		nums[a]++;
	}
	int sum{0};
	for(int i=120; i>0 && sum < k;--i){
		sum+=nums[i];
	}
	cout<<sum;
	return 0;
}
