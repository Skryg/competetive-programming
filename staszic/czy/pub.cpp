#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n; cin>>n;
    string s; cin>>s;
    s = ' '+s;
    vector<int> p(s.size());
    p[0]=p[1]=0;
    for(int i=2;i<s.size();++i){
        int pref = p[i-1];
        while(pref > 0 && s[pref+1]!=s[i])
            pref = p[pref];
        if(s[pref+1]==s[i]) pref++;
        p[i] = pref;
    }

    int find = p.back();
    if(find == 0){
        cout<<0; return 0;
    }
    for(int i=2;i<s.size()-1; ++i){
        if(p[i]==find){
            cout<<find;
            return 0;
        }
    }
    cout<<0;
    return 0;
}