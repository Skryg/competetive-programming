#include <bits/stdc++.h>

using namespace std;

int tab[3]={0,0,0};
int n;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    string s;
    cin>>s;
    int ans{0};
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<3;++j) tab[j]=0;
        for(int j=i;j<n;++j)
        {
            switch(s[j])
            {
                case 'B':
                    ++tab[0];
                    break;
                case 'S':
                    ++tab[1];
                    break;
                case 'C':
                    ++tab[2];
                    break;
            }
            if((tab[0]!=tab[1]&& tab[0]!=tab[2]&& tab[1]!=tab[2])||(tab[2]==0 && tab[1]==0)||(tab[0]==0&&tab[1]==0)||(tab[0]==0&&tab[2]==0))
                ans=max(ans, tab[0]+tab[1]+tab[2]);
        }
    }
    cout<<ans;
    return 0;
}

