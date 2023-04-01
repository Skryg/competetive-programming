#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    vector<ll> fib;
    fib.push_back(0);
    fib.push_back(1);
    for(int i=2;i<90;++i)
    {
        fib.push_back(fib[i-1]+fib[i-2]);
    }
    int p;
    cin>>p;
    for(int i=0;i<p;++i)
    {
        ll k;
        ll it=0;
        cin>>k;
        vector<ll>::iterator upper, lower;
        while(k!=0)
        {
            
            upper=upper_bound(fib.begin(),fib.end(),abs(k));
            lower=upper;
            if(upper!=fib.begin())--upper;
            if(k>0)
            {
                ll dif1 = abs(k-(*lower));
                ll dif2 = abs(k-(*upper));
                if(dif1>dif2)
                    k=dif2;
                else k=dif1;
            }
            else 
            {
                ll dif1 = abs(k+(*lower));
                ll dif2 = abs(k+(*upper));
                if(dif1>dif2)
                    k=dif2;
                else k=dif1;
            }
            ++it;
        }
        cout<<it<<"\n";

    }
    return 0;
}