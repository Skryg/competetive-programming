#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, X;
    cin>>n>>X;
    int **tab = new int*[n];
    for(int i=0;i<n;i++)
    {
        tab[i]=new int[3];
        cin>>tab[i][0]>>tab[i][1]>>tab[i][2];
    }
    string ans="";
    if(n==0||tab[n-1][1]+1>=tab[n-1][2])
    {
        if(n==0)
            ans=to_string(0);
        else ans="NIE";
    }
    else
    {
         //od tylu kontrolujemy
        for(int i=n-1; i>0;i--)
        {
            int dist = tab[i][0]-tab[i-1][0];
            if(tab[i][1]-dist > tab[i-1][1])
                tab[i-1][1]=tab[i][1]-dist;
            if(tab[i][2]+dist < tab[i-1][2])
                tab[i-1][2] = tab[i][2]+dist;
            if(tab[i-1][1]+1>=tab[i-1][2])
                ans = "NIE";

        }
        //od przodu
        if(1+tab[0][0] < tab[0][2])
            tab[0][2]=1+tab[0][0];
        if(-1-tab[0][0] > tab[0][1])
            tab[0][1] = -1-tab[0][0];

        for(int i=0; i<n-1;i++)
        {
            int dist = tab[i+1][0]-tab[i][0];
            if(tab[i][1]-dist > tab[i+1][1])
                tab[i+1][1]=tab[i][1]-dist;
            if(tab[i][2]+dist < tab[i+1][2])
                tab[i+1][2] = tab[i][2]+dist;
            

        }
        if(tab[0][1]-tab[0][0]>=0 || tab[0][2]+tab[0][0]<=0)
        {
            ans = "NIE";
        }
        if(ans!="NIE")
        {
            int last = 0;
            if((tab[0][0]+abs(tab[0][1]+1))%2==1)
            {
                if(tab[0][1]+2<tab[0][2])
                {
                    last = tab[0][1]+2;
                }
                else ans="NIE";
            }
            else last = tab[0][1]+1;
            if(ans!="NIE")
            {
                for(int i=1;i<n;i++)
                {
                    int dist = tab[i][0]-tab[i-1][0];
                    int ydist = abs(last - tab[i][1]-1);
                    if((dist+ydist)%2 ==1)
                    {
                        if(tab[i][1]+2<tab[i][2])
                        {
                            last = tab[i][1]+2;
                        }
                        else 
                        {
                            ans="NIE";
                            break;
                        }

                    }
                    else
                        last = tab[i][1]+1;

                }
                if(ans!="NIE")
                {
                    long long int a;
                    a = (tab[n-1][0]+last)/2;
                    ans = to_string(a);
                }
            }
            
        }
    }
    cout<<ans;

    for(int i=0; i<n;i++)
    {
        delete[] tab[i]; 
    }
    delete[] tab;
    return 0;
}