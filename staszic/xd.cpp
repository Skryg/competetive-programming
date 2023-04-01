#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct Segm{
	struct Vert{
		int mi{INT_MAX}, mx{INT_MAX}, c{0};
	};
	vector<Vert> t;
	int k{1};
	Segm(){}
	Segm(int n){
		while(k<n) k*=2;
		t.resize(2*k);
	}
	void add(int pos, int val, int co){
		t[pos+k] = (Vert){.mi = val, .mx = val, .c = co};
	}
	void find_del(int v, int val){
		if(t[v].mi == val && t[v].mx == val){
			--t[v].c;
			
			return;
		}
		
		if(t[2*v].mx >= val) find_del(2*v, val);
		else find_del(2*v+1, val);
		t[v].c = t[2*v].c + t[2*v+1].c;
	}
	
	ll query(int v, int a, int b){
		if(t[v].mi >= a && t[v].mx<=b) return t[v].c;
		if(t[v].mi == t[v].mx) return 0;
		ll ans{0};
		if(t[2*v].mx >= a) ans+=query(2*v, a,b);
		if(t[2*v+1].mi <=b ) ans+=query(2*v+1, a,b);
		return ans;
	}
	
	void setup(){
		for(int i=k-1;i>0;--i){
			t[i].mi = t[2*i].mi;
			t[i].mx = t[2*i+1].mx;
			t[i].c = t[2*i].c + t[2*i+1].c;
		}
	}
	
	
};

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	vector<int> nums;
	int n;
	cin>>n;
	nums.resize(n);
	for(int i=0;i<n;++i){
		cin>>nums[i];
	}
	vector<int> copy = nums;
	sort(copy.begin(), copy.end());
	Segm s = Segm(n);
	int count{0};
	int pos{0};
	for(int i=0;i<n;++i){
		++count;
		if(i==n-1 || copy[i]!= copy[i+1]) {
			s.add(pos++, copy[i], count);
			count = 0;
		}
		
	}
	s.setup();
	ll ans{0};
	for(int i=0;i<n;++i){
		s.find_del(1,nums[i]);
		ans += s.query(1,-1000000001,nums[i]-1);
		//cout<<"Found for nums[i]-1 "<<nums[i]-1<<": "<<s.query(1,-1000001,nums[i]-1)<<"\n";
	}
	cout<<ans;
	return 0;
}