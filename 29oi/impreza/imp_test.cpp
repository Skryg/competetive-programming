#include <bits/stdc++.h>
#define st first
#define nd second
#define vt vector
#define ll long long
#define MOD 1000000007LL
#define rep(x) for(int i=0; i<x;++i)
using namespace std;
struct Kras{
    struct Elem{
        pair<bool, bool> act;
        bool state{false};
        int num, state_num;
        bool connected(){
            if(act.st == false || act.nd == false) return false;
            return true;
        }
        void disact(){
            act={false, false};
        }
        int is_one_active(){
            if((act.st==false && act.nd==false)||(act.st==true && act.nd==true)) return 0;
            if(act.st == true) return 1;
            else return 2;
        }
    
    };
    vt<Elem> e;
    Kras(int n){
        e.resize(n, {{true, true},false});
        e[0].act.st = false;
        e[n-1].act.nd = false;
    }
    void set_state(int i, int val){
        if(i>0){
            if(e[i-1].act.nd && e[i-1].num == val) e[i-1].disact();
            else e[i-1].act.nd = false;
        }
        if(i<e.size()-1){
            if(e[i+1].act.st && e[i+1].num == val) e[i+1].disact();
            else e[i+1].act.st = false;
        }
        e[i].state = true;
        e[i].state_num=val;
        if(i>0 && e[i-1].is_one_active())set_state(i-2, e[i-1].num);
        if(i<e.size()-1 && e[i+1].is_one_active())set_state(i+2, e[i+1].num);
        
    }
};

ll solution(int n, vt<int> &input){
    vt<int> exist(n+1);
    //vt<int> input(n+1);
    Kras k(n);
    ll added{0};
    for(int i=1; i<=n;++i){
        //int c; cin>>c;
        k.e[i-1].num=input[i];
        //input[i]=c;
        int c = input[i];
        if(exist[c]>0){
            if(exist[c]==1 && input[i-2]==input[i]){
                ++added;
                k.set_state(i-2, c);
            }
            else {
                return 0;
            }
        }
        exist[c]++;
    }
    if(k.e[0].is_one_active()) k.set_state(1, k.e[0].num);
    if(k.e[k.e.size()-1].is_one_active()) k.set_state(k.e.size()-2, k.e[k.e.size()-1].num);
    if(k.e[0].num != k.e[1].state_num){
        cout<<0; return 0;
    }
    int sze = k.e.size();
    if(k.e[sze-1].num != k.e[sze-2].state_num){ return 0;}
    for(int i=1; i<k.e.size()-2;++i){
        if(k.e[i-1].state && k.e[i+1].state && k.e[i-1].state_num != k.e[i].num && k.e[i+1].state_num != k.e[i].num){
            return 0;
        }
    }
    vt<vt<ll>> dp(n, vt<ll>(3));
    if(k.e[0].state) dp[0][0]=1;
    else dp[0][2]=1;
    if(k.e[1].act.st) dp[0][1]=1;
    dp[1][0]=1;
    ll ans=1;
    for(int i=2;i<n;++i){
        if(k.e[i-1].connected()){
            if(k.e[i-1].act.nd) dp[i][0] = dp[i-2][0]+ dp[i-2][2];
            if(i<k.e.size()-1 && k.e[i+1].act.st) dp[i][1] = dp[i-2][1];
            dp[i][2]=dp[i-2][1];
        }
        else{
            ans *= (dp[i-2][0]+dp[i-2][1]+dp[i-2][2])%MOD;
            ans%=MOD;
            if(k.e[i].state) dp[i][0]=1;
            else{
                dp[i][2]=1;
                if(i<k.e.size()-1 && k.e[i+1].act.first) dp[i][1]=1;
            }
        }
        

    }
    ans *= (dp[sze-1][0]+dp[sze-1][1]+dp[sze-1][2])%MOD;
    ans%=MOD;
    ans *= (dp[sze-2][0]+dp[sze-2][1]+dp[sze-2][2])%MOD;
    ans%=MOD;
    for(ll i=1;i<=added;++i){
        ans*=i;
        ans%=MOD;
    }
    return ans;
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n; cin>>n;
    vector<int> inp(n+1);
    for(int i=1;i<=n;++i){
        cin>>inp[i];
    }
    cout<<solution(n, inp)<<"\n";
    
    return 0;

}