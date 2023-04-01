#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n; cin>>n;
	string s; cin>>s;

	vector<vector<int>> alpha_list(26);
	for(int i=0;i<s.size();++i){
		alpha_list[s[i]-'a'].push_back(i);
	}
	int ans{0};
	for(int i=0;i<26;++i){
		for(int j=0; j<26;++j){
			vector<int> n_list;
			int x{0}, y{0};
			while(x!=alpha_list[i].size() || y!=alpha_list[j].size()){
				if(x==alpha_list[i].size()){
					n_list.push_back(-1);
					y++;
					continue;
				}
				if(y==alpha_list[j].size()){
					n_list.push_back(1);
					x++;
					continue;
				}
				if(alpha_list[i][x] < alpha_list[j][y]){
					n_list.push_back(1);
					x++;
				}
				else{
					n_list.push_back(-1);
					y++;
				}
			}
			int sum{0}, l_min_sum{0}, mini{INT_MAX};

			for(auto z : n_list){
				sum+=z;
				if(z==-1){
					mini = min(mini, l_min_sum);
					l_min_sum = sum;
				}
				ans = max(ans, sum-mini);

			}

		}

	}
	cout<<ans;
	return 0;
}

