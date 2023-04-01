#include<bits/stdc++.h>

using namespace std;

#define satori int t;cin>>t;while(t--)
typedef long long ll;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	satori{
		int n; cin>>n;
		int prev{0}, act{0};
		ll ans{0};
		cin>> act;
		ans+=act;
		prev = act;
		for(int i=2;i<=n;++i){
			cin>>act;
			if(prev < act){
				ans+=(act-prev);
			}
			prev=act;
		}
		cout<<ans<<"\n";
	}

	return 0;
}
