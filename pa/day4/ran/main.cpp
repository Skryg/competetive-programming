#include <bits/stdc++.h>

using namespace std;

#define vt vector
#define st first
#define nd second
typedef long long ll;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n; cin>>n;
	vt<int> input(n+1);
	vt<int> ids(n+1);

	for(int i=1;i<=n;++i){
		cin>>input[i];
		ids[input[i]]=i;
	}
	
	cout<<2*n+1<<" ";
	int l,r;
	l=r=ids[n];
	ll ans{0};
	int it1{l},it2{l};
	for(int len=1; len <= n; ++len){
		if(len%2){
			it2 = it1;
		}
		else{
			it1 = ids[input[it2]-1];
			if(it1 < l) l = it1;
			if(it1 > r) r = it1;
		}
		if(len < r-l+1) continue;
		int mx_len = len-r+l;
		if(r-len<0) mx_len += (r-len);
		if(n+1-l-len<0) mx_len += (n+1-l-len);
		ans+=mx_len;

	}
	cout<<ans;

	return 0;
}
