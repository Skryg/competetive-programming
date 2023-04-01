#include <bits/stdc++.h>

using namespace std;

#define vt vector
typedef long long ll;
typedef tuple<int,int,int> VAL;

void reset(ll &time, int *tab, int *first){
	for(int i=0;i<3;++i) tab[i]=first[i];
	time = 0;
}

void update(ll time, vt<int> tab, vt<ll> &tab2){
	for(int i=0;i<3;++i) tab2[tab[i]]=min(time, tab2[tab[i]]);
} 
//from b1 to b2
vt<int> pour(int b1, int b2, vt<int> tab, int *mx){
	int add = min(mx[b2]-tab[b2], tab[b1]);
	tab[b1]-=add;
	tab[b2]+=add;
	return tab;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int mx[3], sta[3];
	vt<int> act(3);
	for(int i=0;i<3;++i) cin>>mx[i];
	for(int i=0;i<3;++i){
		cin>>act[i];
		sta[i]=act[i];
	}

	vt<ll> times(mx[2]+1, LLONG_MAX);
	queue<pair<vt<int>,ll>> bfs;
	bfs.push({act,0});
	map<vector<int>, ll> mp; 
	while(!bfs.empty()){
		auto emp = bfs.front();
		bfs.pop();
		if(mp.find(emp.first)!=mp.end()) continue;
		ll time = emp.second;
		mp[emp.first]=time;
		update(time, emp.first, times);

		bfs.push({pour(0,1,emp.first,mx),time+1});
		bfs.push({pour(1,0,emp.first,mx),time+1});
		bfs.push({pour(1,2,emp.first,mx),time+1});
		bfs.push({pour(2,1,emp.first,mx),time+1});
		bfs.push({pour(0,2,emp.first,mx),time+1});
		bfs.push({pour(2,0,emp.first,mx),time+1});

		
	}
	

	for(auto i : times) cout<<(i == LLONG_MAX ? -1 : i)<<" ";

	return 0;
}
