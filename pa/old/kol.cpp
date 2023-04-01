#include <bits/stdc++.h>

using namespace std;

int comp(pair<int,int> pair1,pair<int,int>pair2)
{
    return pair1.first < pair2.first;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin>>n>>m;

    vector<pair<int,int> > c[3];
    int col,l,r;
    for(int i=0;i<m;i++)
    {
        cin>>l>>r>>col;
        if(col==1)
            c[0].push_back({l,r});
        else if(col==2)
            c[1].push_back({l,r});
        else if(col==3)
            c[2].push_back({l,r});
    }
    
    sort(c[0].begin(),c[0].end(),comp);
    sort(c[1].begin(),c[1].end(),comp);
    sort(c[2].begin(),c[2].end(),comp);
    list<pair<int,int> > cl[3];
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<c[i].size();j++)
        {
            cl[i].push_back(c[i].at(j));
        }
    }

    list<pair<int,int> >::iterator itMain,itSecond;
    bool end;
    int maxi=0;
    for(int i=0;i<3;i++)
    {
        end=false;
        itMain = cl[i].begin();
        itSecond = itMain;
        itSecond++;
        while(itMain != cl[i].end() && itSecond != cl[i].end())
        {
            if(itSecond != cl[i].end()&&(*itMain).second +1 >= (*itSecond).first)
            {
                if((*itSecond).second > (*itMain).second)
                    (*itMain).second = (*itSecond).second;
                itSecond = cl[i].erase(itSecond);

            }
            else
            {
                itMain++;
                itSecond = itMain;
                itSecond++;
            }
            
        }
        maxi = max(cl[i].back().second,maxi);
    }
    
    bitset<1000001> colors[3];
    list<pair<int,int> >::iterator it;
    for(int i=0;i<3;i++)
    {
       for(it = cl[i].begin(); it!=cl[i].end();it++)
       {
           for(int j=(*it).first;j<=(*it).second; j++)
           {
               colors[i].set(j);
           }
       }
    }
    cout<<((colors[0] &colors[1])& (~colors[2])).count();

    return 0;
}