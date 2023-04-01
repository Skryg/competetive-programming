#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t; cin>>t;
	while(t--){
		int n,m; cin>>n>>m;
		vector<tuple<int,int,int>> points(m);
		int x=0;
		for(auto &[a,b,c] : points){
			cin>>b>>a;
			c = ++x;
		} 
		sort(points.begin(), points.end());
		while(points.size() > 2*n) points.pop_back();
		for(auto &[a,b,c] : points) swap(a,b);
		sort(points.begin(), points.end());
		vector<pair<int,int>> ans(n);
		long long an{0};
		for(int i=0;i<n;++i){
			auto [a1,b1,c1] = points[i];
			auto [a2,b2,c2] = points[points.size()-1-i];
			ans[i] = {c1,c2};
			an+=b1;
			an+=b2;
		}
		cout<<an<<"\n";
		for(auto [a,b] : ans) cout<<a<< " "<< b<< "\n";
		cout<<"\n";
		
	}

	return 0;
}
