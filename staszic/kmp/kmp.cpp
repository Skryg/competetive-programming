#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,m; cin>>n>>m;
    string a,b; cin>>a>>b;
    string fin = ' '+a+'#'+b;
    vector<int> p(fin.size());
    p[0]=p[1]=0;
    for(int i=2;i<fin.size();i++){
        int pref = p[i-1];
        while(pref > 0 && fin[pref+1]!=fin[i]) pref = p[pref];
        if(fin[pref+1] == fin[i]) pref++;
        p[i]=pref;
    }

    int minus = 2*n;

    for(int i=n+2; i<fin.size();++i){
        if(p[i] == n) cout<<i-minus<<"\n";
    }

    return 0;
}