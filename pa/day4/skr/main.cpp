#include <bits/stdc++.h>

using namespace std;

#define vt vector

typedef long long ll; 

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n,m,q;
	cin>>n>>m>>q;
	vt<vt<string>> s(n,vt<string>(m));
	for(int i=0;i<n;++i){
		for(int j=0;j<m;++j){
			cin>>s[i][j];
		}
	}
	while(q--){
		ll t; cin>>t;
		
	}


	return 0;
}
