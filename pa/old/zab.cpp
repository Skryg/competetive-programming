#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    string a,b;
    cin>>n>>a>>b;

    string even[2];
    int count[2][26]={{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}};
    string odd[2];
    int evenNum=0;
    int oddNum=0;
    for(int i=0;i<n;i++)
    {
        if(i%2 ==0)
        {
            even[0]+=a[i];
            even[1]+=b[i];
            evenNum++;
        }
        else
        {
            odd[0]+=a[i];
            odd[1]+=b[i];
            oddNum++;
        }
        
    }
    for(int i=0;i<evenNum;i++)
    {
        count[0][even[1][i]-'a']++;
    }
    for(int i=0;i<oddNum;i++)
    {
        count[1][odd[1][i]-'a']++;
    }
    int i=0;
    bool ok=true;
    while(evenNum!=0)
    {
        if(count[0][even[0][i]-'a']>0)
        {
            count[0][even[0][i]-'a']--;
            evenNum--;
        }
        else
        {
            ok=false;
            break;
        }
        i++;
            
    }
    i=0;
    while(ok && oddNum!=0)   
    {
        if(count[1][odd[0][i]-'a']>0)
        {
            count[1][odd[0][i]-'a']--;
            oddNum--;
        }
        else
        {
            ok=false;
            break;
        }
        i++;    
    }
    if(ok)
        cout<<"TAK";
    else cout<<"NIE";
    return 0;
}