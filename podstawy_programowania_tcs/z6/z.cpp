#include <bits/stdc++.h>
#define satori int z; cin>>z; while(z--)
#define INT_MX 1'000'0000
#define INT_MI -1'000'0000
using namespace std;

constexpr int h = 100010;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    satori{
        vector<int> mi(h+1,INT_MX), mx(h+1,INT_MI);
        int n; cin>>n;
        for(int i=1;i<=n;++i){
            int x; cin>>x;
            mi[x] = min(i, mi[x]);
            mx[x-1] = max(i, mx[x-1]);
            //cerr<<mi[x]<< ' '<<mx[x]<<'\n';
        }
        

        for(int x=2;x<=h;++x){
            mi[x] = min(mi[x], mi[x-1]);
        }
        for(int x=h;x>=2;--x){
            mx[x-1] = max(mx[x-1],mx[x]);
        }

        /*for(int x=1;x<10;++x) 
            cerr<<mi[x]<< ' '<<mx[x]<<'\n';*/


        int val = 0;
        int first, last;
        for(int i=1;i<=h;++i){
            if(mx[i]-mi[i]>val){
                first = mi[i];
                last = mx[i];
                val = mx[i]-mi[i];
                
            }
            else if(mx[i]-mi[i]==val && mi[i] < first){
                first = mi[i];
                last = mx[i];
            }
        }
        if(val > 0 && val <= 1000000) cout<<first-1<<' '<<last-1<<'\n';
        else cout<<"NIE\n";
    }

    return 0;
}