#include <bits/stdc++.h>

using namespace std;

int main()
{

    const int MAXW = 100;
    int w = 10;
    int n=5;
    int a[n+1];
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    queue<int> q;
    bool DP[MAXW + 1];
    for (int i=1; i<=w; ++i) DP[i] = 0;
                  
    DP[0] = 1;
    for (int i=1; i<=n; ++i)
    {
        while(!q.empty())
        {
            q.pop();
        }
        int k = a[i];
        for (int j=0; j<=w-k; ++j) 
        {
            if (DP[j] == 1)
            {
                if((q.empty()||j != q.front()) && DP[j + k]==0)
                {
                    DP[j+k]=1;
                    q.push(j+k);
                }
                else if(!q.empty()&& DP[j + k]!=0) q.pop();
            }
        }
    }
    cout<<DP[w];                   
    return 0;
}