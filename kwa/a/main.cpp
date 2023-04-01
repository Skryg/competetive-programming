#include<bits/stdc++.h>

using namespace std;

#define satori int t;cin>>t;while(t--)

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	satori{
		string s;
		cin>>s;
		string pas="";
		for(int i=0;i<s.size();++i){
			pas+=(char)(((s[i]-'a')+13)%26+'a');
		}
		cout<<pas<<"\n";
	}

	return 0;
}
