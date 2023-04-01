#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t; cin>>t;
	while(t--){
		long long l,r,a; cin>>l>>r>>a;
		long long x = r/a*a-1;
		long long y = x/a + x%a;
		
		if(x<l) y=0; 
		cout<<max((1-a)*(r/a)+r,  y)<<"\n";
	}

	return 0;
}
