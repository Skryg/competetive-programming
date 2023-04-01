#include <bits/stdc++.h>

using namespace std;

char num_to_char(int n){
	char c;
	switch(n){
		case 3:
			c = 'a';
			break;
		case 4:
			c = 'e';
			break;
		case 5:
			c = 'm';
			break;
		case 6:
			c = 'o';
			break;
	}
	return c;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n; cin>>n;
	string s; cin>>s;
	string ans="";
	int ones{0};
	int full{n*8};
	int mi{3*n}, mx{6*n};
	for(auto i : s){
		if(i=='1') ones++;
	}
	if(ones > mx || ones < mi) {
		cout<<"NIE";
		return 0;
	}
	while(n){
		int minus = (ones/n + (ones%n ? 1 : 0));
		ans+=num_to_char(minus);
		ones-= minus;
		n--;
	}
	cout<<ans;
	return 0;
}
