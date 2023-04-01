#include <bits/stdc++.h>

using namespace std;

struct segm{
    vector<int> tree;

    int k{1};

    segm(int n){
        while(n>=k) k*=2;
        tree.resize(2*k);

    }

    void push(int v){
        tree[2*v] = max(tree[2*v], tree[v]);
        tree[2*v+1] = max(tree[2*v+1], tree[v]);
    }

    void insert(int v, int first, int last, int a, int b, int val){
        if(first >= a && last <= b){
            tree[v] = max(tree[v],val);
            return;
        }
        push(v);
        int mid = (first+last)/2;
        if(a<=mid) insert(2*v, first, mid, a, b, val);
        if(b>mid) insert(2*v+1, mid+1, last, a,b,val);
    }

    int query(int v, int first, int last, int pos){
        if(first == pos && last == pos) return tree[v];
        int mid = (first+last)/2;
        push(v);
        if(pos <= mid) return query(2*v, first, mid, pos);
        else return query(2*v+1, mid+1, last, pos);
    }
};


void ans(int a){
    if(!a){
        cout<<"NO\n";
        return;
    }
    cout << (a == 1 ? "N/A" : "YES") << "\n";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,q; cin>>n>>q;

    set<int> st;
    vector<pair<int,int>> inter;
    for(int i=0;i<=n+1;++i) st.insert(i);
    auto comp = [](const pair<int,int> &p1, const pair<int,int> p2) {
        if(p1.first != p2.first) return p1.first < p2.first;
        return p1.second < p2.second;
    };
    map<pair<int,int>, int, decltype(comp)> mp(comp);
    vector<tuple<int,int,int,int>> query(q);

    //preprocessing

    for(auto &[a,b,c,d] : query){
        cin>>a;
        if(!a){
            cin>>b>>c>>d;
            mp[{b,c}]=0;
        }
        if(a) cin>>b;

    }
    int g = 0;  
    for(auto &[a,b] : mp){
        b = ++g; 
    }

    segm first(n+1), end(n+1);
    
    // main part

    for(int i=0;i<q;++i){
        auto [type,l,r,x] = query[i];
        if(!type){
            if(!x){
                auto it = st.lower_bound(l);
                while(it != st.end() && *it <= r){
                    st.erase(it);
                    it = st.lower_bound(l);
                }
            }
            else{
                int num = mp[{l,r}];
                first.insert(1, 0, first.k-1, l, first.k-1, num);
                end.insert(1, 0, end.k-1, r, end.k-1, num);

            }
            
        }
        else{
            if(st.size()){
                auto x = st.lower_bound(l);
                if(x == st.end() || *x != l) ans(0);
                else{
                    auto f = x; f--; 
                    auto s = x; s++;
                    if(end.query(1, 0, end.k-1, (*s)-1) > first.query(1, 0, first.k-1, *f)) ans(2);
                    else ans(1);

                }

            }
            else ans(0);
        }
    }

    return 0;
}

