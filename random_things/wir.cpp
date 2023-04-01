#include <bits/stdc++.h>

using namespace std;

int check(vector<int>& s)
{
    if(s[0]==1 && s[1]==1 && s[2]==1 && s[3]==1 && s[4]==1 && s[5]==1) return 1;
    else return 0;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    vector<int> chars(6);
    for(int i=0;i<n;++i)
    {
        fill(chars.begin(),chars.end(),0);
        string s;
        int ans{0};
        cin>>s;
        for(int i=0; i<s.length() && i<6;++i)
        {
            if(s[i]-'A'>=0 && s[i]-'A'<=5)
                ++chars[s[i]-'A'];
        }
        ans+=check(chars);
        for(int i=6;i<s.length();++i)
        {
            if(s[i]-'A'>=0 && s[i]-'A'<=5)
                ++chars[s[i]-'A'];
            if(s[i-6]-'A'>=0 && s[i-6]-'A'<=5)
                --chars[s[i-6]-'A'];
            ans+=check(chars);
        }
        cout<<ans<<"\n";
    }

    return 0;

}