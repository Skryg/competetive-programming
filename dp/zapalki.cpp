#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    vector<bool> z;
    cin>>n;
    int l;
    for(int i=0;i<n;i++)
    {
        cin>>l;
        z.push_back(l);
 
    }
    int *pref = new int[n+1];
    int *suf = new int[n+1];
    pref[0]=0;
    suf[n]=0;
    for(int i=1;i<=n;i++)
    {
        pref[i]=pref[i-1]+1-z[i-1];
    }
    for(int i=n-1;i>=0;i--)
    {
        suf[i]=suf[i+1]+z[i];
    }
    int ans = INT_MAX;

    for(int i=0;i<=n;i++)
    {
        ans = min(ans, pref[i]+suf[i]);
    }
    cout<<ans;
    delete[] pref,suf;
    return 0;
}