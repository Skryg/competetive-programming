#include <bits/stdc++.h>

#define ST first
#define ND second

using namespace std;

struct segm{
    vector<int> t, lazy;
    int k{1};
    segm(int n){
        while(k<=n) k<<=1;
        t.resize(k<<1);
        lazy.resize(k<<1);
    }
    void push(int v){
        t[v]=max(t[v], lazy[v]);
        if(v>=k) return;
        
        lazy[2*v] = max(lazy[v]/2, lazy[2*v]);
        lazy[2*v+1] = max(lazy[v]/2, lazy[2*v+1]);
    }

    void insert(int v, int first, int last, int a, int b){
        if(first >= a && last <= b){
            lazy[v] = last-first+1;
            push(v);
            return;
        }
        push(v); 
        int mid = (first+last)/2;
        if(a<=mid) insert(2*v, first, mid, a, b);
        if(b>mid) insert(2*v+1, mid+1, last, a, b);
        t[v] = t[2*v]+t[2*v+1]; 
    }

    int query(int v, int first, int last, int a, int b){
        if(first >= a && last <= b){
            push(v); 
            return t[v];
        }
        push(v);
        int mid = (first+last)/2;
        int ans{0};
        if(a<=mid) ans+=query(2*v, first, mid, a, b);
        if(b>mid) ans+=query(2*v+1, mid+1, last, a, b);
        return ans;
    }

};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,m; cin>>n>>m;
    vector<pair<int,int>> cond(m);
    for(auto &[a,b] : cond) cin>>a>>b;
    sort(cond.begin(), cond.end(), [](const pair<int,int> &p1, const pair<int, int> &p2)->bool{
        if(p1.ND-p1.ST != p2.ND-p2.ST) return p1.ND-p1.ST < p2.ND-p2.ST;
        return p1.ST < p2.ST;
    });
    segm s(n);

    for(auto [a,b] : cond){
        int dest = (b-a+1)/2, act = s.query(1, 1, s.k, a,b), des = dest-act;
        int first = a, last = b, x = (first+last)/2, w;
        if(!des) continue;
        while((w = (b-x+1)-s.query(1, 1, s.k, x, b))!=des){
            if(w > des) first = x+1;
            else last = x-1;

            x = (first+last)/2;
        }
        s.insert(1, 1, s.k, x, b);
    }

    for(int i=1;i<=n;++i) cout<<s.query(1, 1, s.k, i,i);


    return 0;
}