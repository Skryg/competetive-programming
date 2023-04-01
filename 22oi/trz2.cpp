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
    int ans{1};
    int id[3]={-1,-1,-1};

    for(int j=0;j<n;++j)
    {
        switch(s[j])
        {
            case 'B':
                if(id[0]==-1) id[0]=j;
                break;
            case 'S':
                if(id[1]==-1) id[1]=j;
                break;
            case 'C':
                if(id[2]==-1) id[2]=j;
                break;
        }
    }

    for(int j=0;j<3;++j) tab[j]=0;

    for(int i=0;i<3;++i)
    {
        if(id[i]==-1) continue;
        for(int j=0;j<3;++j) tab[j]=0;
        for(int j=id[i];j<n;++j)
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
    id[0]=-1;
    id[1]=-1;
    id[2]=-1;
    for(int j=n-1;j>=0;--j)
    {
        switch(s[j])
        {
            case 'B':
                if(id[0]==-1) id[0]=j;
                break;
            case 'S':
                if(id[1]==-1) id[1]=j;
                break;
            case 'C':
                if(id[2]==-1) id[2]=j;
                break;
        }
    }
    for(int i=0;i<3;++i)
    {
        for(int j=0;j<3;++j) tab[j]=0;
        for(int j=id[i];j>=0;--j)
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

