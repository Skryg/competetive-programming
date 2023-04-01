#include <bits/stdc++.h>

using namespace std;

bool check(tuple<int,int,int,int> q, long long fuel, vector<int> &dist){
    long long full = fuel;
    auto [start, finish, cons, refuel] = q;
    
    while(start!=finish){
        if((long long)dist[start+1]*cons <= fuel){
            fuel -= (long long)dist[start+1]*cons;
            start++;
        }
        else if((long long)dist[start+1]*cons > fuel && refuel){
            refuel--;
            fuel = full;
        }
        else return false;
    }

    return true;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n,m; cin>>n>>m;
    vector<int> cities(n), dist(n);
    vector<tuple<int,int,int,int>> queries(m);

    for(auto &i : cities) cin>>i;
    for(auto &[a,b,c,d] : queries){
        cin>>a>>b>>c>>d;
        a--;
        b--;
    }
    for(int i=1;i<n;++i) dist[i] = cities[i]-cities[i-1];
    
    random_shuffle(queries.begin(), queries.end());
    long long fuel = 1;
    for(auto [st,fin,cons,ref] : queries){
        if(!check({st,fin,cons,ref}, fuel, dist)){
            long long first = 1, last = 1e18;

            while(first <= last){
                long long mid = (first+last)/2;
                if(check({st,fin,cons,ref}, mid, dist)){
                    last = mid-1;
                    fuel = mid;
                }
                else first = mid+1;
            }

        }
    }    
    cout<<fuel;

    return 0;
}