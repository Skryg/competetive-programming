#include <bits/stdc++.h>

#define satori int z; cin>>z; while(z--)

using namespace std;

bool tab[32]={0};
bool tabd1[64]={0};
bool tabd2[64]={0};
pair<int, int> pos[32];
int n,m;

void set_position(int x, int y, bool val){
    tab[y] = val;
    tabd1[x-y+32]=val;
    tabd2[x+y]=val;
}

bool queen(int x, int s, int id){
    if(s==0) return true;
        
    for(int i=0;i<m;++i){
        if(!tab[i] && !tabd1[x-i+32] && !tabd2[x+i]){
            pos[id]={x,i};
            set_position(x,i,1);
            bool ok = queen(x+1, s-1, id+1);
            set_position(x,i, 0);
            if(ok) return true;
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
        bool swapped = false;
        if(n>m){
            swap(n,m);
            swapped = true;
        }

        if(queen(0,s, 0)){
            cout<<"TAK\n";  
            for(int i=0;i<s;++i){
                if(swapped) swap(pos[i].first, pos[i].second);

                cout<<pos[i].first+1<<' '<<pos[i].second+1<<'\n';
            }
        }
        else cout<<"NIE\n";
    }
    return 0;
}