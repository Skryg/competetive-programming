#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct mono
{
    deque<pair<int,ll>> min;
    deque<pair<int,ll>> max;
    int first{0}, last{0};
    void addNext(int id, ll val)
    {
        while(!min.empty()&&min.back().second >= val)
        {
            min.pop_back();
        }
        while(!max.empty()&&max.back().second <= val)
        {
            max.pop_back();
        }
        max.push_back({id, val});
        min.push_back({id,val});
        ++last;
    }

    void frontNext()
    {
        if(first == max.front().first)
            max.pop_front();
        if(first == min.front().first)
            min.pop_front();

    }

    ll minim(){return min.front().second;}
    ll maxim(){return max.front().second;}


};
vector<ll> ts;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll t,n;
    cin>>t>>n;
    ts.resize(n);
    for(int i=0;i<n;++i)
    {
        cin>>ts[i];
    }
    
    mono m;
    int ans{1};
    for(m.first = 0; m.first < n-1; ++m.first)
    {
        while(m.last < n &&(m.min.empty()|| m.maxim()-m.minim()<=t))
        {
            ans = max(ans, m.last - m.first);
            m.addNext(m.last,ts[m.last]);
            
        }
        if(!m.min.empty()&& m.maxim()-m.minim()<=t) ans = max(ans, m.last - m.first);
        m.frontNext();

    }
    cout<<ans;
    return 0;
}