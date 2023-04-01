#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); 

    int n;
    cin>>n;

    int* tab = new int[2000000+1];
    int* tab2 = new int[2000000+1];
    for(int i=0;i<=2000000;i++)
    {
        tab[i]=0;
        tab2[i]=0;
    }
    
    int x,a,b;
    for(int i=0;i<n;i++)
    {
        cin>>x>>a>>b;
        if(x==1)
        {
            tab[a-b+1000000]++;
        }
        else
            tab2[a-b+1000000]++;
    }
    int ans=0;

    for(int i=0;i<=2000000;i++)
    {
        ans+=min(tab[i],tab2[i]);
    }
    cout<<ans;
    delete[] tab;
    delete[] tab2;
    return 0;
}