#include <bits/stdc++.h>
#define satori int z; cin>>z; while(z--)

using namespace std;

bool check_num(int people, vector<int> &vt, int checking){
    for(auto t : vt){
        people -= (t/checking);
        people -= (t%checking ? 1 : 0);
        if(people < 0) return false;
    }
    return true;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    satori{
        int n,m; cin>>n>>m;
        vector<int> teams(n);
        for(auto &i : teams) cin>>i;
        int ans = -1;
        long long first = 1, last = 2'000'000'000;
        while(first<=last){
            long long mid = (first+last)/2LL;
            if(check_num(m, teams, mid)){
                ans = mid;
                last = mid-1;
            }
            else{
                first = mid+1;
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}