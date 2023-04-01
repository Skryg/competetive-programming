#include <bits/stdc++.h>

using namespace std;

bool check(vector<int> &p, int l, vector<int> &rep){
    int last = l;
    fill(rep.begin(), rep.end(),0);
    rep[l] = l;
    for(int i = l; i<p.size();++i){
        if(i - last > l) return false;
        if(rep[p[i]]==l){
            last = i;
            rep[i] = rep[p[i]];
        }
    }
    if(last == p.size()-1) return true;
    return false;
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s; cin>>s;
    s = ' '+s;
    vector<int> p(s.size());
    p[0] = p[1] = 0;
    for(int i=2; i<s.size(); ++i){
        int pref = p[i-1];
        while(pref > 0 && s[pref+1] != s[i])
            pref = p[pref];
        if(s[pref+1] == s[i]) pref++;
        p[i] = pref;
    }

    vector<bool> tpl(s.size());
    vector<int> rep(s.size());
    int q = s.size()-1;
    tpl[q] = true;
    int mini = q;
    while(p[q]!=0){
        if((tpl[q] && q>= p[q] && p[q]>=ceil(q/2)) ||  check(p, p[q],rep)){
            tpl[p[q]] = true;
            mini = p[q];
        }
        q = p[q];
    }
    cout<<mini;
    
    return 0;
}