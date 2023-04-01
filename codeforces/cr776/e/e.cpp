#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t; cin>>t;
	while(t--){
		int n,d; cin>>n>>d;
		vector<int> date(n+1);
		for(int i=1;i<=n;++i) cin>> date[i];

		int id, mi{INT_MAX};
		int id_mx, mx{INT_MIN};
		for(int i=1;i<=n;++i){
			if(date[i]-date[i-1]-1 < mi){
				id = i;
				mi = date[i]-date[i-1]-1;
			} 
			
		}
		date.erase(date.begin()+id);
		for(int i=1;i<=n;++i){
			if(date[i]-date[i-1]-1 > mx){
				id_mx = i;
				mx = date[i]-date[i-1]-1;
			} 
			
		}

		int ans{0};

		if(date.back()!=d){
			int mim = INT_MAX;
			date.push_back(d);
			for(int i=1;i<=n;++i){
				mim = min(mim, date[i]-date[i-1]-1);
			}
			ans = max(ans, mim);
			date.pop_back();
		}
		int a = date[id_mx];
		int b = date[id_mx-1];
		date.insert(date.begin()+id_mx, (a+b)/2);
		int mim = INT_MAX;
		for(int i=1;i<=n;++i){
			mim = min(mim, date[i]-date[i-1]-1);
		}
		ans = max(ans, mim);

		cout<<ans<<"\n";
	}

	return 0;
}
