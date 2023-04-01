#include <bits/stdc++.h>

#define satori int z; cin>>z; while(z--)

using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	satori{
		int n; cin>>n;
		vector<int> num(n);
		for(auto &i : num){
			cin>>i;
		}
		vector<int> even, odd;
		for(int i=0;i<n;++i){
			if(num[i]%2) odd.push_back(i+1);
			else even.push_back(i+1);
		}

		if(odd.size()>=3){
			cout<<"YES\n";
			cout<<odd[0]<< ' '<<odd[1]<< ' '<<odd[2]<<'\n';
		}
		else if(even.size()>=2 && odd.size()>=1){
			cout<<"YES\n";
			cout<<odd[0]<<' '<<even[0]<< ' ' <<even[1]<<'\n';
		}
		else cout<<"NO\n";
	}
	return 0;
}
