#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        cout<<s<<" ";
        while(s != "4" && s!= "1")
        {
            ll sum{0};
            for(int i=0;i<s.size();++i)
            {
                int l{s[i]-'0'};
                sum+=(l*l); 
            }
            cout<<sum<<" ";
            s = to_string(sum);
        }
        

        cout<<"\n";
    }

    return 0;
}