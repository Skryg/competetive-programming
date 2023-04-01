#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    vector<int> first;
    first.reserve(100000);
    vector<bool> tab(1000001);
    for(int i=2;i<1000001;++i){
        if(!tab[i]){
            first.push_back(i);
            for(int j=2*i; j<1000001; j+=i){
                tab[j]=true;
            }
        }
    }
    int t; cin>>t;
    while(t--){
        int a,b; cin>>a>>b;
        auto st = lower_bound(first.begin(),first.end(),a);
        auto nd = upper_bound(first.begin(),first.end(),b);
        nd--;
        cout<<nd-st+1<<"\n";
    }
    return 0;
}