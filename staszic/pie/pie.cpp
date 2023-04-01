#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
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
    for(int i=1;i<p.size();++i){
        cout<< (p[i] ? 1 : 0);
    }

    return 0;
}