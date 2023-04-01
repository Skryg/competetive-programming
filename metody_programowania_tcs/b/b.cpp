#include <bits/stdc++.h>
#define satori int z; cin>>z; while(z--)
using namespace std;
long double squareLength(vector<tuple<int,int,int,int>> &v, long double time){
    long double ver_min=1000000000, ver_max=-1000000000;
    long double hor_min=1000000000, hor_max=-1000000000;

    for(auto &[a,b,c,d] : v){
        ver_min = min(ver_min, b+d*time);
        ver_max = max(ver_max, b+d*time);

        hor_min=min(hor_min,a+c*time);
        hor_max=max(hor_max,a+c*time);
    }
    return max(hor_max-hor_min, ver_max-ver_min);
}
bool isIncreasing(vector<tuple<int,int,int,int>> &v, long double time){
    long double epsilon = 0.00001;
    return squareLength(v,time) < squareLength(v,time+epsilon); 
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    satori{
        int n; cin>>n;
        vector<tuple<int,int,int,int>> cyklonb(n);
        for(auto &[a,b,c,d] : cyklonb) cin>>a>>b>>c>>d;

        long double seconds = 1000;
        long double act_time=0;
        int times = 10000;
        while(times--){
            if(!isIncreasing(cyklonb,act_time+seconds)) act_time+=seconds;
            //cerr<<"koniec ";
            seconds/=2.;
        }
        cout<<setprecision(10)<<fixed<<squareLength(cyklonb, act_time)<<' '<<act_time<<'\n';

    }
    return 0;
}