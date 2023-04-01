#include <bits/stdc++.h>

using namespace std;

struct road
{
    int id, disPrev, energy;

    road()
    {
        id=-1, disPrev = 0, energy=0;
    }

    road(int i,int d, int e)
    {
        id=i;
        disPrev=d;
        energy=e;
    }
};

bool comp(road r1, road r2)
{
    return (r1.disPrev>r2.disPrev);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin>>n;
    int *a = new int[n+1];
    a[0]=0;

    vector<road> elements;
    cin>>a[1];
    int maxR=0;
    elements.push_back(road(1,0,a[1]));
    for(int i=2;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]!=0)
        {
            elements.push_back(road(i,i-elements.back().id,a[i]));
            maxR+=(elements.back().disPrev);
        }

        
    }
    sort(elements.begin(),elements.end(), comp);
    long long int *pref = new long long int[n+1];
    pref[0]=0;
    for(int i=1; i<=n;i++)
    {
        pref[i]=pref[i-1]+a[i];
    }
    if(pref[n]-pref[0]<0)
    {
        cout<<-1;
    }
    else
    {
        set<int> s;
        s.insert(1);
        s.insert(n+1);
        set<int>::iterator it;
        for(int i=0;i<elements.size();i++)
        {
            it = s.upper_bound(elements[i].id);
            if(pref[*it -1]-pref[elements[i].id-1]>=0)
            {
                it--;
                if(pref[elements[i].id-1]-pref[*it -1]>=0)
                {
                    maxR-=elements[i].disPrev;
                    s.insert(elements[i].id);
                }
            }
        }

        cout<<maxR;
    }
    
    
 
    delete[] a;
    delete[] pref;
    return 0;
}