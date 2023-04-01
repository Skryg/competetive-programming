#include <bits/stdc++.h>

using namespace std;


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout<<31<<"\n";
    for(int i=2;i<32;++i)
        cout<<i<<" ";
    for(int i=0;i<16;++i)
        cout<<0<<" "<<0<<"\n";
    cout<<30<<"\n";
    for(int i=16;i<31;++i)
    {
        cout<<i<<" "<<i+1<<" "<<i+1<<" "<<i<<"\n";
    }
    return 0;
}