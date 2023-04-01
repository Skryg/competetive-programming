#include <bits/stdc++.h>

#define satori int t; cin>>t; while(t--)
#define vt vector
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    satori{
       int a,b; cin>>a>>b;
       int sum{(a+b)/4};
       cout<<min({sum, a,b})<<"\n";
    }

    return 0;
}