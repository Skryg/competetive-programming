#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n;
vector<ll> x,h;
pair<ll, ll> n1,n2;

struct Interval
{
    int numOf{0};
    ll nextDist{-1};
    ll needed{0};
    Interval(){}
};
vector<Interval> in,rin;

struct CompareIntervalGreater{
    bool operator()(Interval const& i1, Interval const& i2)
    {
        return i1.nextDist<i2.nextDist;
    }
};
struct CompareIntervalLower{
    bool operator()(Interval const& i1, Interval const& i2)
    {
        return i1.nextDist>i2.nextDist;
    }
};

void loadData()
{
    cin>>n;
    for(int i=0;i<n;++i)
    {
        ll a,b;
        cin>>a>>b;
        x.push_back(a);
        h.push_back(b);

    }
    cin>> n1.first >> n1.second >> n2.first>>n2.second;
}

bool check();

ll sum(vector<Interval> &v)
{
    priority_queue<Interval, vector<Interval>, CompareIntervalGreater> cand;
    priority_queue<Interval, vector<Interval>, CompareIntervalLower> toKick;
    ll num=0;
    ll usedBig;

    for(int i=0;i<v.size();++i)
    {
        while(check())
    }

    return 0;
}

void scale(vector<Interval> &v, ll by, ll big)
{
    for(int i=0;i<v.size();++i)
    {
        if(v[i].nextDist != -1)
        {
            v[i].nextDist % by !=0  ? v[i].nextDist = v[i].nextDist/by+1 : v[i].nextDist = v[i].nextDist/by; 
            v[i].needed = v[i].nextDist / big;
            v[i].nextDist = v[i].nextDist % big;
        } 
    }
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    loadData();
    ll mx = -1;
    for(int i=0;i<n;++i)
    {
        if(x[i]>mx)
        {
            if(!in.empty()) in.back().nextDist = x[i]-mx;
            Interval g;
            g.numOf=1;
            in.push_back(g);

        }
        else
        {
            ++in.back().numOf;
            
        }
        mx = max(mx, x[i]+h[i]);
    }
    mx==LLONG_MAX;
    for(int i=n-1;i>=0;--i)
    {
        if(x[i]<mx)
        {
            if(!rin.empty()) rin.back().nextDist = mx-x[i];
            Interval g;
            g.numOf=1;
            rin.push_back(g);

        }
        else
        {
            ++rin.back().numOf;
            
        }
        mx = min(mx, x[i]-h[i]);
    }
    ll scallar,bigger;
    if(n1.second > n2.second) swap(n1,n2);
    scallar = n1.second;
    n2.second /= n1.second;
    n1.second = 1;
    bigger = n2.second;

    scale(in,scallar, bigger);
    scale(rin,scallar, bigger);

    ll ans = max(sum(in),sum(rin));
    cout<< ans;

    return 0;
}