#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t; cin>>t;
	while(t--){
		string s; cin>>s;
		char c; cin>>c;
		bool ok =false;
		for(int i=0;i<s.size();++i){
			if(s[i] == c && ((i+1)%2)) ok=true;
		}
		cout<< (ok ? "YES\n" : "NO\n");
	}
	return 0;
}
