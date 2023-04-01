#include <bits/stdc++.h>

using namespace std;

int main(){
    cout<<1<<'\n'<<2<<'\n';
    vector<int> seq;
    bool used[601]={false};
    int last_used=2;
    for(int i=2;i<300;++i){
        vector<int> dif;
        used[1]=used[2]=true;
        for(int j=2; j*j<=last_used;++j){
            if(last_used%j==0) dif.push_back(j);
            while(last_used%j==0) last_used/=j;
        }
        if(last_used!=1) dif.push_back(last_used);

        for(int j=2;j<600;++j){
            bool d=false;
            for(auto x : dif){
                if(j%x==0){
                    d =true;
                    break;
                }
            }
            if(d && !used[j]){
                used[j]=true;
                seq.push_back(j);
                last_used = j;
                break;
            }
        }
    }
    for(auto x : seq) cout<<x<<'\n';
    return 0;
}