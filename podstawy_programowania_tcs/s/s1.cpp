#include <bits/stdc++.h>

#define satori int z; cin>>z; while(z--)

using namespace std;


pair<int, int> pos[32];
int n,m;

bool check_pos(int x, int y, int id){
    for(int i=0;i<id;++i){
        auto [x1, y1] = pos[i];
        if(x-x1 == 0 || y-y1==0) return false;
        if(y-x == y1-x1 || x+y == x1+y1) return false;
    }
    return true;
}
bool queen(int x, int s, int id){
    if(s==0) return true;
    for(int j=x;j<n;++j){
        if(s>n-j+1) return false;

        for(int i=0;i<m;++i){
            if(check_pos(j,i,id)){
                pos[id]={j,i};
                bool ok = false;
                if(queen(j+1, s-1, id+1)) ok = true;
                if(ok) return true;
            }
        }
    }
    
    return false;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    satori{
        int s; cin>>n>>m>>s;
        int size = min(n,m);
        if((n==2 && m ==2 && s==2)||(n==3 && m==3 && s==3)||size<s){
            cout<<"NIE\n";
            continue;
        }
        if(size >3) n=m=size;
        if(queen(0,s, 0)){
            cout<<"TAK\n";  
            for(int i=0;i<s;++i) cout<<pos[i].first+1<<' '<<pos[i].second+1<<'\n';           
        }
        else cout<<"NIE\n";


    }

    return 0;
}