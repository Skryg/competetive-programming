#include <bits/stdc++.h>

using namespace std;

#define vt vector
#define pb push_back

typedef long long ll;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n,k; cin>>n>>k;
	vt<int> start(n+1), mark(n+1);
	vt<int> out;
	for(int i=1;i<=n;++i){
		cin>>start[i];
		if(!mark[start[i]]) mark[start[i]] = i;
		else if(i<=k){
			out.pb(i);
		}
	}
	sort(mark.begin(), mark.end());
	auto ub = upper_bound(mark.begin(), mark.end(), k);
	int it{1};
	ll cost{0};
	while(it<= out.size() && ub != mark.end()){
		cost+=((*ub)-it-k);
		it++;
		ub++;
	}
	if(it<= out.size() && ub == mark.end()){
		cout<<-1;
		return 0;
	}
	sort(out.begin(), out.end());
	it--;
	for(int i=out.size()-1; i>=0;--i){
		cost+=(k-out[i]+it);
		it--;
	}
	cout<<cost;
	return 0;
}
