#include<bits/stdc++.h>
#define ST first
#define ND second
using namespace std;

typedef long long ll;

struct Segm{
    vector<ll> t;
    int k{1};
    Segm(){}
    Segm(int i){
        while(i>k) k*=2;
        t = vector<ll>(2*k); 
    }

    void refresh(int v){
        if(!v) return;
        t[v] = min(t[2*v],t[2*v+1]);
    }

    void refreshAll(){
        for(int i=k-1; i>0; --i){
            t[i] = min(t[2*i],t[2*i+1]);
        }
    }

    void add(int v, ll val){
        v+=k;
        t[v]=val;
    }
    
    ll num(int v){
        return t[v+k];
    }

    pair<ll,int> query(int v, int first, int last, int a, int b){
        if(first >= a && last <= b){
            return {t[v],v-k};
        }
        int mid = (first+last)/2;
        pair<ll,int> ans{5'000'000'000'000'000'000LL, 0};
        if(a<=mid){
            pair<ll,int> x = query(2*v, first, mid, a, b);
            if(ans.ST > x.ST) ans = x; 
        } 
        if(b>mid)
        {
            pair<ll,int> x = query(2*v+1, mid+1, last, a, b);
            if(ans.ST > x.ST) ans = x;
        }  
        return ans;
    }

};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    vector<int> num(n*2+1);
    for(int i=1;i<=n;++i){
        cin>>num[i];
    }
    for(int i=n+1;i<=2*n;++i){
        num[i]=num[i-n];
    }
    Segm s = Segm(n*2+1);
    for(int i=1;i<=2*n;++i){
        s.add(i,s.num(i-1)+num[i]);
    }
    s.refreshAll();
    ll ans{-5'000'000'000'000'000'000LL};
    pair<ll, int> sm=s.query(1,0,s.k-1,0,0);
    for(int i=1;i<=2*n;++i){
    
        if(sm.ST > s.num(i-1)) sm = {s.num(i-1),i-1};
        if(sm.ND < i-n) sm =s.query(1,0,s.k-1,max(1,i-n),i-1);
        
        ans = max(ans, s.num(i) - sm.ST);
    }
    cout<<ans;
    return 0;
}