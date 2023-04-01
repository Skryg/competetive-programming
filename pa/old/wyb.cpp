#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin>>n;
    int tab[5][3]={{1,1,1},{1,1,1},{1,1,1},{1,1,1},{2,2,2}};
    int full = 18;
    string s;
    for(int i=0;i<n;i++)
    {
        cin>>s;
        switch(s[1])
        {
            case 'A':
                if(tab[s[0]-'0'-1][0]>0)
                {
                    tab[s[0]-'0'-1][0]--;
                    full--;
                }
                
                break;
            case 'B':
                if(tab[s[0]-'0'-1][1]>0)
                {
                    tab[s[0]-'0'-1][1]--;
                    full--;
                }
                break;
            case 'C':
                if(tab[s[0]-'0'-1][2]>0)
                {
                    tab[s[0]-'0'-1][2]--;
                    full--;
                }
                break;
        }
        if(full==0) break;
    }
    if(full<=0)
    {
        cout<<"TAK";
    }
    else cout<<"NIE";
    return 0;
}