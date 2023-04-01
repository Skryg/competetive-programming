#include<bits/stdc++.h>

typedef long long ll;

using namespace std;

void solve(ll m,vector<ll> &fib){
    //for(int i=0;i<fib.size();++i) if(m%fib[i]==0) cout << fib[i]<<"\n";
    int count{0},sum{0};
    if(m==1){
        cout<<1<<"\n";
        return;
        
    }
    
    for(int i=fib.size()-1;i>1;--i){
        if(fib[i]==144 || fib[i]==3 || fib[i]==2 || fib[i]==8) continue;
        while(m%fib[i]==0){
            m/=fib[i];
            ++count;
            sum+=i;
        }
    }
    for(int i=fib.size()-1;i>1;--i){
        
        while(m%fib[i]==0){
            m/=fib[i];
            ++count;
            sum+=i;
        }
    }
    if(m==1) cout << sum+count-1;
    else cout << "NIE";
    cout<<"\n";
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    vector<ll> fib(92);
    fib[0]=1;
    fib[1]=1;
    for(int i=2;i<fib.size();++i){
        fib[i]=fib[i-1]+fib[i-2];
    }
    ll m; cin>>m;
    solve(m, fib);
    
    return 0;
}