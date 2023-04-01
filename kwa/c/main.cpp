#include<bits/stdc++.h>

using namespace std;

#define satori int t;cin>>t;while(t--)
#define vt vector
#define pr pair
#define st first
#define nd second
typedef long long ll;
typedef tuple<int, ll, ll> MIN;
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	satori{
		int n; cin>>n;
		vt<MIN> mins(n);
		vt<vt<int>> graph();
		int it{1};
		for(auto &i : mins){
			auto& [id, pos, dist] = i;
			cin>>pos>>dist;
			id=it++;
		}
	}

	return 0;
}
