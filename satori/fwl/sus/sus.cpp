#include <bits/stdc++.h>
//#define cerr if(0)cerr
typedef long long ll;

using namespace std;

vector<int> factorize(int num){
    vector<int> fact;
    for(int i=1;i*i<=num;++i){
        if(num%i==0){
            fact.push_back(i);
            if(i*i!=num) fact.push_back(num/i);
        }
    }
    return fact;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int z; cin>>z;
    while(z--){
        int n,q; cin>>n>>q;
        vector<int> nums(n);
        vector<ll> pref(n+1);
        for(auto &x : nums){
            cin>>x;
            pref[x]++;
        }
        for(int i=0;i<n;++i){
            pref[i+1]+=pref[i];
        }
        for(int i=1;i<=n;++i) cerr<<pref[i]<<" ";
        vector<ll> sums(n+1);
        for(int i=1;i<=n;++i){
            int x=0;
            for(int j=i; j<=2*n; j+=i){
                sums[i] += (pref[min(j,n)]-pref[min(j-i,n)])*(++x);
            }
        }

        while(q--){
            int type, i; cin>>type>>i;
            if(type==3){
                cout<<sums[i]<<'\n';
            }
            if(type==1){
                vector<int> fact = factorize(nums[i-1]++);

                for(auto f : fact){
                    sums[f]++;
                }
            }
            if(type==2){
                vector<int> fact = factorize(--nums[i-1]);
               
                for(auto f : fact){
                    sums[f]--;
                }
            }
        }

    }

    return 0;
}