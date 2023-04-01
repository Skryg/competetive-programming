#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007

int z;

struct pwid
{
    int first{0},second{0}, id{0};
    pwid(){}
};

vector<pwid> pairs;
vector<pwid> pairs2;
bitset<1000000> bits;
bool pairSort(pwid p1,pwid p2)
{
    return p1.first<p2.first;
}
bool pairSort2(pwid p1,pwid p2)
{
    return p1.second<p2.second;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin>>z;
    for(int i=0;i<z;++i)
    {
        bits.reset();
        pairs.clear();
        pairs2.clear();
        int a,b;
        cin>>a>>b;
        for(int j=0;j<b;++j)
        {
            pwid p;
            cin>>p.first>>p.second;
            p.id = j;
            pairs.push_back(p);
        }
        sort(pairs.begin(),pairs.end(),pairSort);
        pairs2 = pairs;
        sort(pairs2.begin(),pairs2.end(),pairSort2);
        int ans=0;
        int x=0;
        for(int j=0;j<b;++j)
        {
            if(!bits.test(pairs2[j].id))
            {
                ans++;
                while(x<pairs.size()&&pairs[x].first<pairs2[j].second)
                {
                    bits.set(pairs[x].id);
                    ++x;
                }
            }
        }
        cout<<ans<<" "<< 0<<"\n";

    }

    return 0;
}