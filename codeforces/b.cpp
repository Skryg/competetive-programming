#include <bits/stdc++.h>

using namespace std;


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {   
        int x;
        cin>>x;
        bool is{false};
        while(x>=0)
        {
            if(x%11==0) 
            {
                is=true;
                break;
            }
            x-=111;
        }
        if(is) cout<<"YES\n";
        else cout<<"NO\n";
        
    }


    return 0;
}