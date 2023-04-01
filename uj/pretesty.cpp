#include <bits/stdc++.h>
using namespace std;


constexpr long long N=12LL*3600LL*1000000000LL;
long long DANE[3];
long long A,B,C, h, m, s, ns, t;

vector<int>v;
pair<long long,long long>EXCD(long long a, long long b){
    if (b==0) return {1,0};
    auto [x,y]= EXCD(b, a%b);
    return {y, x-(long long)(a/b)*y}; }


int q;
int main() {
   // cin.tie(0);
  //  cout.tie(0);
  //  ios_base::sync_with_stdio(0);

    cin>>q;

    for (int i=1; i<=3; i++)
        v.push_back(i);

    for (int _t=1; _t<=q; _t++){
        cin>>DANE[0]>>DANE[1]>>DANE[2];

        int n=3;
        do{
           h=DANE[v[0]-1];      //A=t
           m=DANE[v[1]-1];      //B=11t
           s=DANE[v[2]-1];      //C=719t

           pair<long long, long long>wsp=EXCD(11,N);

           long long p=(m-h)%N;
           long long q=(s-h)%N;


           if (p<0) {
                p+=N;}
           if (q<0) {
                q+=N;  }

            __int128 k=((__int128)(wsp.first)*(__int128)(p))%N;
            if (k<0)
                k+=N;
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




                    }
            while(next_permutation(v.begin(),v.end()));}


}
