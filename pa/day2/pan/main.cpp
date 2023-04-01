#include <bits/stdc++.h>

using namespace std;

#define st first
#define nd second
#define vt vector
#define satori int t; cin>> t; while(t--)

bool interval_comp(pair<int,int> &p1, pair<int,int> &p2){
	int d1 = (p1.nd - p1.st-1)/2;
	int d2 = (p2.nd - p2.st-1)/2;
	if(d1 == d2) return d1+((p1.nd - p1.st-1)%2)<d2+((p2.nd - p2.st-1)%2);
	return d1<d2;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	satori{
		int n; cin>>n;
		string s; cin>>s;

		vt<bool> visited(n);
		vt<pair<int,int>> inter(n);
		int x{-1};
		for(int i=0;i<n;++i){
			if(s[i]=='1') x=i;
			inter[i].st = x;
		}
		x=-1;
		for(int i=n-1;i>=0;--i){
			if(s[i]=='1') x=i;
			inter[i].nd = x;
		}
		queue<pair<int,int>> que;
		stack<pair<int,bool>> sta; 
		for(int  i = 0; i<n;++i){
			if(s[i]=='1') que.push({i,1});
		}
		int it=1;
		queue<pair<int, int>> inv;
		while(!que.empty()){
			while((!que.empty()) && que.front().nd == it){
				auto v = que.front();
				que.pop();
				if(visited[v.st]) continue;

				// is end
				if(v.st==0){
					
					inv.push({inter[v.st].nd, false});
				}
				else if (v.st==n-1){
					inv.push({inter[v.st].st, true});
				}	
				else if (visited[v.st-1]&&visited[v.st+1]){
					if((inter[v.st].nd - inter[v.st].st -1)%2 ){
						sta.push({inter[v.st].st, true});
						sta.push({inter[v.st].nd, false});
					}
					else{
						inv.push({inter[v.st].st, true});
						inv.push({inter[v.st].nd, false});
					}
					
					
				}

				visited[v.st]=true;
				if(v.st>0 && !visited[v.st-1]) que.push({v.st-1, v.nd+1});
				if(v.st<n-1 && !visited[v.st+1]) que.push({v.st+1,v.nd+1});

			}
			while(!inv.empty()){
				sta.push(inv.front());
				inv.pop();
			}
			it++;
			
		}
		vt<bool> vaccin(n);
		fill(visited.begin(), visited.end(), false);
		queue<pair<int,int>> q2;
		int ans{0};
		for(int  i = 0; i<n;++i){
			if(s[i]=='1') q2.push({i,1});
		}
		it=1;
		while(!sta.empty()){

			while((!q2.empty())&&q2.front().nd == it){
				auto v = q2.front();
				q2.pop();
				if(visited[v.st] || vaccin[v.st]) continue;

				visited[v.st]=true;
				ans++;
				if(v.st>0 && (!visited[v.st-1]) && (!vaccin[v.st-1])) q2.push({v.st-1, v.nd+1});
				if(v.st<n-1 && (!visited[v.st+1]) && (!vaccin[v.st+1])) q2.push({v.st+1, v.nd+1});
			}
			auto s = sta.top();
			sta.pop();
			if(s.nd){
				if(s.st+it<n)vaccin[s.st+it]=true;
			}
			else{
				if(s.st-it >=0)vaccin[s.st-it]=true;
			}
			it++;

		}
		cout<<ans<<"\n";


	}
	return 0;
}
