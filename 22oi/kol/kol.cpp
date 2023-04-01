#include <bits/stdc++.h>
#include "ckollib.h"

using namespace std;

void add(int *tab, int val){
    for(int i=0;i<32;++i){
        if(val&(1<<i)) tab[i]++;
    }
}

int extract(int *tab){
    int val = 0;
    for(int i=0; i<32; ++i){
        if(tab[i]){
            val += (1<<i);
        }
    }
    return val;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int tab[32] = {0};
    pair<int,int> vals, cnt;
    int x;
    while(x = karta()){
        add(tab, x);

        if(vals.first == x) cnt.first++;
        else if(vals.second == x) cnt.second++;
        else if(!vals.first){
            vals.first = x;
            cnt.first++;
        }
        else if(vals.first && !vals.second){
            vals.second = x;
            cnt.second++;
        }
    }
    int mx = max(cnt.first, cnt.second);
    for(auto &i : tab) i%=mx;
    if(vals.first && !vals.second) odpowiedz(vals.first);
    else odpowiedz(extract(tab));

    return 0;
}