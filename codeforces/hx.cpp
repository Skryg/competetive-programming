#include <bits/stdc++.h>
using namespace std;
#define KP                            \
	ios_base::sync_with_stdio(false); \
	cin.tie(NULL);
#define ll long long int
#define rep(i, a, b) for (ll i = a; i < b; i++)
#define inp(a,n) rep(i,0,n) cin>>a[i];
#define out(a,n) rep(i,0,n) cout<<a[i]<<" ";
#define MIN -1e9
#define MAX 1e9
#define endl "\n"
#define vi vector<ll>
#define pb push_back
#define all(v) v.begin(), v.end()
#define output(x) cout << (x ? "YES" : "NO") << endl;
bool sortbysecdesc(const pair<ll, ll> &a, const pair<ll, ll> &b)
{
	return a.second > b.second;
}
 
void solve()
{
	ll n, m;
	cin >> n;
 
	vi a(2 * n);
	inp(a, 2 * n);
	sort(all(a));
	vi b = a;
	sort(all(b), greater<int>());
 
	ll x = 0, y = 0;
	rep(i, 0, 2 * n)
	{
		if (i % 2)
			cout << b[y] << " ", y++;
		else
			cout << a[x] << " ", x++;
	}
	cout << endl;
}
 
int main()
{
	KP;

 
	ll tt = 1;
	cin >> tt;
	while (tt--)
		solve();
 
	 cout << "\n\n"
	      << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " seconds.\n";
 
	return 0;
}