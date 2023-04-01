#include <bits/stdc++.h>

using namespace std;

#define satori int t; cin>>t; while(t--)
#define vt vector
#define pb push_back

bool dfs(int v, vt<vt<int>> &graph, vt<bool> &vis, string &act_st, string &dest_st, string act_loc, string dest_loc){
	if(vis[v]) return false;
	vis[v]=true;
	act_loc += act_st[v-1];
	dest_loc += dest_st[v-1];
	if(graph[v].size()==1 && act_loc.size()!=1){
		char first = dest_loc[0];
		char last = dest_loc[dest_loc.size()-1];
		int st=0, en=act_loc.size()-1;
		while(st < act_loc.size() && first != act_loc[st]) st++;
		while(en >= st && last != act_loc[en]) en--;

		int c1{0},c2{0};
		char lll='x';
		for(st; st<=en; st++){
			if(act_loc[st]!= lll) c1++;
			lll=act_loc[st];
		}
		lll='x';
		for(int i=0;i<dest_loc.size();++i){
			if(dest_loc[i]!=lll) c2++;
			lll=dest_loc[i];
		}
		if(c1>=c2) return true;



	}
	for(auto i : graph[v]){
		if(dfs(i, graph, vis, act_st, dest_st, act_loc, dest_loc)) 
			return true;
	}
	return false;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	satori{
		int n; cin>>n;
		string act, des;
		cin>>act>>des;
		vt<vt<int>> tree(n+1);
		vt<int> leaves;
		vt<bool> vis(n+1,false);
		for(int i=1;i<n;++i){
			int a,b;
			cin>>a>>b;
			tree[a].pb(b);
			tree[b].pb(a);

		}
		for(int i=1; i<tree.size();++i){
			if(tree[i].size()==1) leaves.pb(i);
		}
		bool flag{false};
		for(auto i : leaves){
			fill(vis.begin(),vis.end(),false);
			if(!dfs(i, tree,vis, act,des,"", "")) flag = true;
		}
		cout<<(flag ? "NIE\n" : "TAK\n");

	}
	return 0;
}
