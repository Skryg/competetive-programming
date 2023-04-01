#include <bits/stdc++.h>
#define ST first
#define ND second

using namespace std;

struct Segm{
    struct Vert{
        int first{0}, second{0}, third{0}, fourth{0}, fifth{0},sixth{0};
        
    };


    vector<Vert> t;
    int k{1};
    Segm(){}
    Segm(int i){
        while(k<i) k*=2;
        t.resize(2*k);

    }

    void refresh(int v){
        if(v==0) return;
        t[v] = {.ST = 0  ,.ND = t[2*v].ND + t[2*v+1].ND, .third = t[2*v].third + t[2*v+1].third, .fourth = t[2*v].fourth + t[2*v+1].fourth, .fifth = t[2*v].fifth + t[2*v+1].fifth, .sixth = t[2*v].sixth + t[2*v+1].sixth };
        refresh(v/2);
    }

    void add(int v, int val){
        t[v+k].ST += val;
        t[v+k].ND = (t[v+k].ST % 1==0 ? 1 : 0);
        t[v+k].third = (t[v+k].ST % 2==0 ? 1 : 0);
        t[v+k].fourth = (t[v+k].ST % 3==0 ? 1 : 0);
        t[v+k].fifth = (t[v+k].ST % 4==0 ? 1 : 0);
        t[v+k].sixth = (t[v+k].ST % 5==0 ? 1 : 0);

        refresh((v+k)/2);
    }

    int query(int v, int first, int last, int a, int b, int g){
        if(a<= first && last <= b){
            int ans{0};
            switch(g){
                case 1:
                    ans = t[v].ND;
                    break;
                case 2:
                    ans = t[v].third;
                    break;
                case 3:
                    ans = t[v].fourth;
                    break;
                case 4:
                    ans = t[v].fifth;
                    break;
                case 5:
                    ans = t[v].sixth;
                    break;
            }
            return ans;

        }

        int mid = (first+last)/2;
        int ans{0};
        if(a<= mid) ans+=query(2*v, first, mid, a, b,g);
        if(b>mid) ans+=query(2*v+1, mid+1, last, a, b,g);
        
        return ans;
    }
};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, q;
    cin>>n>>q;
    Segm s = Segm(n);
    for(int i=0;i<n;++i){
        s.add(i,0);
    }
    for(int i=0;i<q;++i){
        string ac;
        cin>>ac;
        if(ac == "DODAJ"){
            int a,b;
            cin>>a>>b;
            s.add(a-1, b);
        }
        else{
            int a,b,c;
            cin>>a>>b>>c;
            cout<< s.query(1, 0, s.k-1, a-1,b-1,c)<<"\n";
        }
    }
    return 0;
}