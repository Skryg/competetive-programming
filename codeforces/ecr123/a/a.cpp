#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int rgb[3],RGB[3];
	string s;
	int t; cin>>t;
	while(t--){
		for(int i=0;i<3;++i){
			rgb[i]=0;
			RGB[i]=0;
		}
		bool ok=true;
		cin>>s;
		for(int i=0;i<s.size();++i){
			if(s[i]=='r'){
				rgb[0]++;
			}
			if(s[i]=='g'){
				rgb[1]++;
			}
			if(s[i]=='b'){
				rgb[2]++;
			}
			if(s[i]=='R'){
				if(rgb[0]){
					rgb[0]--;
				}
				else{
					ok = false;
					break;
				}
			}
			if(s[i]=='G'){
				if(rgb[1]){
					rgb[1]--;
				}
				else{
					ok = false;
					break;
				}
			}
			if(s[i]=='B'){
				if(rgb[2]){
					rgb[2]--;
				}
				else{
					ok = false;
					break;
				}
			}
		}
		cout<< (ok ? "YES" : "NO")<<"\n";
		

	}

	return 0;
}
