#include <bits/stdc++.h>
using namespace std;


constexpr __int128 N=12LL*3600LL*1000000000LL;


pair<__int128,__int128>EXCD(__int128 a, __int128 b){
    if (b==0) return {1,0};
    auto [x,y]= EXCD(b, a%b);
    return {y, x-(__int128)(a/b)*y}; }



int main() {
   // cin.tie(0);
  //  cout.tie(0);
  //  ios_base::sync_with_stdio(0);
    int q;
    cin>>q;

  
    for (int _t=1; _t<=q; _t++){
        long long DANE[3];
        long long t, h, m, s, ns;
        pair<__int128, __int128>wsp=EXCD(11,N);
        cin>>DANE[0]>>DANE[1]>>DANE[2];

        vector<int> v(3);
        for (int i=0; i<=2; i++)
            v[i]=i;

        int n=3;
        do{
           h=DANE[v[0]];      //A=t
           m=DANE[v[1]];      //B=11t
           s=DANE[v[2]];      //C=719t

           

           __int128 p=(m-h+N)%N;
           __int128 q=(s-h+N)%N;


            __int128 k=((__int128)(wsp.first)*(__int128)(p));
            while(k<0) k+=N;
            k%=N;
            t=(long long)(k);

            if ((719*t)%N == q && (11*t)%N==p) {
                ns=t%(1'000'000'000LL);
                t/=1'000'000'000LL;
                s=t%60;
                t/=60;
                m=t%60;
                t/=60;
                h=t;
                cout<<"CASE #"<<_t<<": "<<h<<" "<<m<<" "<<s<<" "<<ns<<"\n";
                break;

            }
        } while(next_permutation(v.begin(),v.end()));
    }
}
