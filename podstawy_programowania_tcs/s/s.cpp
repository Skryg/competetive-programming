#include <bits/stdc++.h>

#define satori int z; cin>>z; while(z--)

using namespace std;

int sum[32]={0};
int tab[32][32]={0};
int tabd1[32][32]={0};
int tabd2[32][32]={0};
pair<int, int> pos[32];
int n,m;

void set_position(int x, int y, int val){
    for(int i=0;i+x<n;++i){
        int s = 0, s2 = 0;
        if(y+i < m){
            s = max({tab[x+i][y+i], tabd1[x+i][y+i], tabd2[x+i][y+i]});
            tabd1[x+i][y+i]=val;
            s2 = max({tab[x+i][y+i], tabd1[x+i][y+i], tabd2[x+i][y+i]});
            sum[x+i]+=(s2-s);
        }
        if(y-i >= 0){
            s = max({tab[x+i][y-i], tabd1[x+i][y-i], tabd2[x+i][y-i]});
            tabd2[x+i][y-i]=val;
            s2 = max({tab[x+i][y-i], tabd1[x+i][y-i], tabd2[x+i][y-i]});
            sum[x+i]+=(s2-s);

        }
        s = max({tab[x+i][y], tabd1[x+i][y], tabd2[x+i][y]});
        tab[x+i][y]=val;
        s2 = max({tab[x+i][y], tabd1[x+i][y], tabd2[x+i][y]});
        sum[x+i]+=(s2-s);
    }
}

bool queen(int x, int s, int id){
    if(s==0) return true;
    int sums = 0;
    for(int i=x;i<n;++i){
        if(sum[i]==m) sums++;
    }
    if(s>n-x+1+sums) return false;
    for(int j=x;j<n;++j){
        if(s>n-j+1) return false;

        for(int i=0;i<m;++i){
            if(!tab[j][i] && !tabd1[j][i] && !tabd2[j][i]){
                set_position(j, i, 1);
                pos[id]={j,i};
                bool ok = false;
                if(queen(j+1, s-1, id+1)) ok = true;
                set_position(j,i, 0);
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
        if(s>3) n=m=min(size, s);
        if(queen(0,s, 0)){
            cout<<"TAK\n";  
            for(int i=0;i<s;++i) cout<<pos[i].first+1<<' '<<pos[i].second+1<<'\n';           
        }
        else cout<<"NIE\n";


    }

    return 0;
}