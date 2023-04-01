#include <bits/stdc++.h>

using namespace std;

vector<int> rep;
vector<int> hm;

int find(int a){
	if(a!=rep[a]) rep[a] = find(rep[a]);
	return rep[a];
}

void uni(int a, int b){
	a = find(a), b = find(b);
	if(a==b) return;
	if(hm[a]>hm[b]) swap(a,b);
	hm[b]+=hm[a];
	rep[a]=b;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n,m; cin>>n>>m;

	rep.resize(n*m);
	hm.resize(n*m,1);
	for(int i=0;i<n*m;++i) rep[i]=i;

	vector<string> vert(n), hor(n-1);
	for(auto &s : vert) cin>>s;
	for(auto &s : hor) cin>>s;
	
	vector<string> vert_ans(n, string(vert[0].size(),'Z')), 
					hor_ans(n-1, string(hor[0].size(), 'Z'));
	
	auto set_rep = [&](char c)->void{
		for(int i=0; i<vert.size(); ++i){
			auto &s = vert[i];
			for(int j=0; j<s.size();++j){
				if(s[j]==c){
					int x = i*m+j;
					if(find(x)!=find(x+1)){
						uni(x, x+1);
						vert_ans[i][j]='.';
					}
				}
			}
		}
		for(int i=0; i<hor.size();++i){
			auto &s = hor[i];
			for(int j=0;j<s.size();++j){
				if(s[j]==c){
					int x = i*m+j;
					if(find(x)!=find(x+m)){
						uni(x, x+m);
						hor_ans[i][j]='.';
					}
				}
			}
		}
	};

	set_rep('T');
	set_rep('C');

	int mx{0}, mx_c{0};

	for(int i=0; i<hor.size();++i){
		for(int j=0; j<hor[i].size(); ++j){
			if(hor_ans[i][j]=='Z'){
				mx++;
				if(hor[i][j]=='C') mx_c++;
			}
		}
	}
	
	for(int i=0; i<vert.size();++i){
		for(int j=0; j<vert[i].size(); ++j){
			if(vert_ans[i][j]=='Z'){
				mx++;
				if(vert[i][j]=='C') mx_c++;
			}
		}
	}

	cout<<mx<<' '<<mx_c<<'\n';
	for(auto &s : vert_ans) cout<<s<<'\n';
	for(auto &s : hor_ans) cout<<s<<'\n';


	return 0;
}
