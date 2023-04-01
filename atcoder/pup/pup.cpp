#include <bits/stdc++.h>

using namespace std;

struct segm{
    vector<long long> t;
    int k{1};

    segm(int n){
        while(k<=n) k*=2;
        t.resize(2*k);
    }
    void refresh(int v){
        if(!v) return;
        t[v]=t[2*v]+t[2*v+1];
        refresh(v/2);
    }

    void add(int x, int val){
        x+=k;
        t[x]+=val;
        refresh(x/2);
    }

    long long query(int v, int first, int last, int a, int b){
        if(a>b) return 0;
        if(first >= a && last <= b){
            
            return t[v];
        }
        int mid = (first+last)/2;
        long long ans{0};
        if(a <= mid) ans+=query(2*v, first, mid, a,b);
        if(b > mid) ans+=query(2*v+1,mid+1, last, a, b);
        return ans;
    }
};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s; cin>>s;

    queue<int> left[26];
    queue<int> right[26];
    vector<int> counter(26);
    vector<int> inv(s.size());
    for(int i=0;i<s.size();++i){
        left[s[i]-'a'].push(i);
        counter[s[i]-'a']++;
    }
    int odd{0};
    for(auto i : counter) if(i%2) odd++;
    if(odd>1){
        cout<<-1;
        return 0;
    }
    for(int i = s.size()-1; i>=0; --i) right[s[i]-'a'].push(i);
    int start = 0, end = s.size()-1;
    int n1=1, n2=s.size();
    while(n1 <= n2){
        int dist=INT_MAX;
        pair<int,int> pr;
        int c;
        int x;
        for(int i=0;i<26;++i){
            if(counter[i] >= 1){
                if(dist > (x=left[i].front() + end-right[i].front())){
                    dist = x;
                    pr = {left[i].front(), right[i].front()};
                    c = i;
                }
            }
        }
        counter[c]-=2;
        left[c].pop();
        right[c].pop();
        inv[pr.first] = n1++;
        inv[pr.second] = n2--; 
    }
    //for(auto i : inv) cerr<< i << " ";
    segm sg(s.size()+1);
    vector<pair<int,int>> inv2(inv.size());
    for(int i=0; i<inv2.size();++i) inv2[i]={inv[i],i};
    sort(inv2.begin(),inv2.end());
    long long ans{0};
    for(int i=0; i<inv2.size(); ++i){
        sg.add(inv2[i].second,1);
        long long q  = sg.query(1, 0, sg.k-1, inv2[i].second+1, s.size());
        ans+=q;
    }
    
    cout<<ans;

    return 0;
}