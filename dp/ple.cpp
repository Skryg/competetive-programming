#include <bits/stdc++.h>

using namespace std;

struct bottle
{
    int t,a,w;
    bottle()
    {
        t=0,a=0,w=0;
    }
    bottle(int r,int g, int c)
    {
        t=r,a=g,w=c;
    }
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t,a,n;
    cin>>t>>a>>n;
    vector<bottle> bot;
    int d,e,f;
    int DP[t+1][a+1];
    for(int i=0;i<=t;i++)
    {
        for(int j=0;j<=a;j++)
        {
            DP[i][j]=1000000;
        }
    }
    DP[0][0]=0;
    for(int i=0;i<n;i++)
    {
        cin>>d>>e>>f;
        bot.push_back(bottle(d,e,f));
    }
    for(int i=0;i<n;i++)
    {
        for(int j=t;j>=0;j--)
        {
            for(int k=a;k>=0;k--)
            {

                DP[min(t,j+bot[i].t)][min(a,k+bot[i].a)] = min(DP[min(t,j+bot[i].t)][min(a,k+bot[i].a)],DP[j][k]+bot[i].w);
            }
        }
    }
    cout<<DP[t][a];
    return 0;
}