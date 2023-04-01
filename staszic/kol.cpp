#include <bits/stdc++.h>
#define ST first
#define ND second
using namespace std;

int n;

vector<int> rep;
vector<int> hm;
vector<int> wei;
vector<pair<int,int>> iq;

int find(int a){
    if(a!=rep[a]) return find(rep[a]);
    return a;
}

void f_union(int a, int b){
    if(hm[find(b)]>hm[find(a)]) swap(a,b);
    hm[find(a)]+=hm[find(b)];
    wei[find(a)]+=wei[find(b)];
    iq[find(a)].ST = min(iq[find(a)].ST, iq[find(b)].ST);
    iq[find(a)].ND = max(iq[find(a)].ND, iq[find(b)].ND);

    rep[find(b)] = rep[a];

}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    rep.resize(n+1);
    hm.resize(n+1,1);
    wei.resize(n+1);
    iq.resize(n+1);
    for(int i=1; i<=n;++i){
        rep[i]=i;
    }
    for(int i=1;i<=n;++i){
        int a,b;
        cin>>a>>b;
        wei[i] = a;
        iq[i]={b,b};
    }
    while(!cin.eof()){
        string type;
        int a,b;
        cin>>type;
        if(type == "MASA"){
            cin>>a;
            cout<<wei[find(a)]<<"\n";
        }
        if(type == "JOIN"){
            cin>>a>>b;
            if(find(a)!=find(b)) f_union(a,b);
        }
        if(type == "IQ_MIN"){
            cin>>a;
            cout<< iq[find(a)].ST<<"\n";
        }
        if(type == "IQ_MAX"){
            cin>>a;
            cout<< iq[find(a)].ND<<"\n";
        }
        
    }
    return 0;
}