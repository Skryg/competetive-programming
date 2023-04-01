#include <bits/stdc++.h>

using namespace std;

vector<int> m1(26),m2(26);

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string a,b;
    cin>>a>>b;
    for(int i=0;i<a.size();++i){
        ++m1[a[i]-'a'];
    }
    for(int i=0;i<b.size();++i){
        ++m2[b[i]-'a'];
    }
    bool good{false};
    int all{0};
    for(int i=0;i<26;++i){
        int m = min(m1[i],m2[i]);
        m1[i]=m;
        m2[i]=m;
        if(m!=0) good = true;
        all+=m;
    }
    if(!good){
        cout<<"BRAK";
        return 0;
    }
    cout<<all<<"\n";
    for(int i=0;i<a.size();++i){
        if(m1[a[i]-'a']>0){
            --m1[a[i]-'a'];
            cout<<a[i];
        }
    }
    cout<<"\n"<<all<<"\n";
    for(int i=0;i<b.size();++i){
        if(m2[b[i]-'a']>0){
            --m2[b[i]-'a'];
            cout<<b[i];
        }
    }
    return 0;
}