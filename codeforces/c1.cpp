#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    vector<int> v(n);
    vector<int> need(n);
    priority_queue<int> pq;
    
    for(int i=0;i<n;++i)
    {
        cin>>v[i];
    }
    ll hp{0};
    int ans{0};
    int potions{0};
    for(int i =0;i <n;++i)
    {
        hp+=v[i];
        ++potions;
        if(v[i]<0) pq.push(-v[i]);
        while(hp<0) 
        {
            hp += pq.top();
            --potions;
            pq.pop();
        }
        ans = max(ans, potions);
    }
    cout<<potions;

    return 0;
}