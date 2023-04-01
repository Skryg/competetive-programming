#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int n;
vector<int> a,b;

struct Segm{
    vector<ll> t;
    vector<int> non0;
    int k{1};

    Segm(){}
    Segm(int i){
        while(i>k) k*=2;
        t.resize(2*k);
        non0.resize(2*k,-1);
    }

    void refresh(int v){
        if(!v) return;
        t[v] = t[2*v] + t[2*v+1];
        non0[v] = max(non0[2*v],non0[2*v+1]);
        refresh(v/2);
    }

    int lastNon(int v, int first, int last,int i){
        if(first >= 0 && last<= i){
            return non0[v];
        }
        
        int mid = (first+last)/2;
        int ans{0};
        if(0<=mid) ans = max(ans, lastNon(2*v, first, mid, i));
        if(i>mid) ans = max(ans, lastNon(2*v+1,mid+1, last,i));
        return ans;
    }

    void non0setup(){
        for(int i=k; i<2*k; ++i){
            non0[i]=i-k;
        }
        for(int i=k-1;i>0;--i){
            non0[i] = max(non0[2*i],non0[2*i+1]);
        }
    }


    void add(int v, ll val){
        
        v=v+k;    
        while(val != 0){
            if(v==-1)return;
            if(t[v]<-val){
                val+=t[v];
                t[v]=0;
                non0[v]=-1;
            }
            else{
                t[v]+=val;
                val=0;
                if(t[v]==0) non0[v]=-1;
            }
            refresh(v/2);
            v=lastNon(1,0,k-1,v-k);
            v=v+k;  
        }
        
        return;
        
        
    }

    

    ll query(int v, int first, int last, int a, int b){
        if(a > last) return LLONG_MAX;
        if(first >= a && last <= b){
            return t[v];
        }
        int mid = (first+last)/2;
        ll ans{0};
        if(a <= mid) ans += query(2*v, first, mid, a, b);
        if(b > mid) ans += query(2*v+1, mid+1, last, a, b);
        return ans;
    }

};
Segm s;
priority_queue<pair<ll,int>> pq;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    a.resize(n);
    b.resize(n);
    s = Segm(n);
    for(int i=0;i<n;++i){
        cin>>a[i];
        s.add(i,a[i]);
    }
    for(int i=0;i<n;++i){
        cin>>b[i];
        pq.push({-b[i],i});
    }
    s.non0setup();
    priority_queue<int> pq2;
    int count{0};
    while(!pq.empty()){
        int x{pq.top().second};
        ll val{pq.top().first};
        pq.pop();
        
        
        
        if(s.query(1,0,s.k-1,0,x) >= -val && s.query(1,0,s.k-1,0,s.k-1)+val>=0){
            s.add(x, val);
            pq2.push(-x);
            ++count;
        }
    }
    cout<<count<<"\n";
    while(!pq2.empty()){
        cout << -pq2.top()+1 << " ";
        pq2.pop();
    }
    return 0;
}