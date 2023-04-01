#include <bits/stdc++.h>

using namespace std;
typedef long long ll;


int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n,m; cin>>n>>m;
	vector<vector<int>> tab(n,vector<int>(m));
	for(int i=0;i<n;++i){
		for(int j=0;j<m;++j) cin >> tab[i][j];
	}
	vector<ll> counter(100001);
	ll ans{0};
	vector<int> last(100001);
	vector<ll> answer(100001);
	vector<ll> prev(100001);
	for(int i=0;i<n;++i){
		for(int j=0;j<m;++j){
			int col = tab[i][j];
			ll add = i-last[col];
			ans+=(add * counter[col]+prev[col]);
			answer[col] = add*counter[col]+prev[col];
			
		}
		for(int j=0;j<m;++j){
			int col = tab[i][j];
			prev[col] = answer[col];
			counter[col]++;
			last[col] = i;
			
		}
	}
	fill(counter.begin(),counter.end(),0);
	fill(last.begin(),last.end(),0);
	fill(answer.begin(),answer.end(),0);
	fill(prev.begin(),prev.end(),0);
	for(int i=0;i<m;++i){
		for(int j=0;j<n;++j){
			int col = tab[j][i];
			ll add = i-last[col];
			ans+=(add * counter[col] + prev[col]);
			answer[col] = add*counter[col]+prev[col];
		}
		
		for(int j=0;j<n;++j){
			int col = tab[j][i];
			prev[col] = answer[col];
			counter[col]++;
			last[col] = i;
			
		}
		
	}
	cout<<ans;
	return 0;
}
