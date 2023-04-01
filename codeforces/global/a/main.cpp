#include <bits/stdc++.h>

#define satori int t; cin>>t; while(t--)

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    satori{
        string n; cin>>n;
        bool ok{false};
        for(int i=0;i<n.size();++i){
            if((n[i]-'0')%2 == 0){
                ok = true;
            }
        }
        if(!ok){
            cout<<-1<<"\n";
            continue;
        }

        if((n[n.size()-1]-'0')%2 ==0 ) cout<<0<<"\n";
        else if((n[0]-'0')%2 ==0) cout<<1<<"\n";
        else cout<<2<<"\n";

    }

    return 0;
}