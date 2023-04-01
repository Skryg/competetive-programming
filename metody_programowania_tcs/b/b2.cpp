#include <bits/stdc++.h>
#define satori int z; cin>>z; while(z--)
using namespace std;
long double squareLength(vector<tuple<int,int,int,int>> &v, long double time){
    long double ver_min=1e18L, ver_max=-1e18L;
    long double hor_min=1e18L, hor_max=-1e18L;

    for(auto &[a,b,c,d] : v){
        ver_min = min(ver_min, b+d*time);
        ver_max = max(ver_max, b+d*time);

        hor_min=min(hor_min,a+c*time);
        hor_max=max(hor_max,a+c*time);
    }
    return max(hor_max-hor_min, ver_max-ver_min);
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    satori{
        int n; cin>>n;
        vector<tuple<int,int,int,int>> cyklonb(n);
        for(auto &[a,b,c,d] : cyklonb) cin>>a>>b>>c>>d;
        long double first =0, last = 1e12L;
        int times = 120;
        while(times--){
            long double div = (last-first)/3.L;
            if(squareLength(cyklonb,first+div) > squareLength(cyklonb,last-div))first+=div;
            else last-=div;
        }
        cout<<setprecision(10)<<fixed<<squareLength(cyklonb, first)<<' '<<first<<'\n';

    }
    return 0;
}