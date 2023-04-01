#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    vector<int> first;
    first.reserve(1000);
    vector<bool> tab(1001);
    for(int i=2;i<1001;++i){
        if(!tab[i]){
            first.push_back(i);
            for(int j=2*i; j<1001; j+=i){
                tab[j]=true;
            }
        }
    }
    int t; cin>>t;
    while(t--){
        int num; cin>>num;
        for(int i=0;i<first.size();++i){
            while(num != 1 && !(num%first[i])){
                cout<<first[i]<<" ";
                num/=first[i];
            }
            
        }
        if(num!=1) cout<< num;
        cout<<"\n";
    }
}