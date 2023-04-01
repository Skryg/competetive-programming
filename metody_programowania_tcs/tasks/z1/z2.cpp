#include <bits/stdc++.h>

using namespace std;

bool check(int n, int m, vector<pair<int,int>> &planks, vector<int> &nails, int d, int val){
    int pref[d+2]={0};
    int suf[d+2]={0};
    bool nail[d+2]={false};
    for(auto [a,b] : planks){
        pref[a]++;
        suf[b+1]++;
    }
    for(int i=0;i<val;++i) nail[nails[i]]=true;
    
    int sufElim = 0;
    for(int i=1;i<d+2;++i){
        if(sufElim){
            if(suf[i]>=sufElim){
                suf[i]-=sufElim;
                sufElim = 0;
            }
            else{
                sufElim-=suf[i];
                suf[i]=0;
            }
        }

        suf[i]+=suf[i-1];
        pref[i]+=pref[i-1];

        if(nail[i]){
            int num  = pref[i]-suf[i];
            pref[i]-=num;
            sufElim+=num;
        }
        cerr<<"PREF: "<<pref[i] << ' '<<"SUF: "<<suf[i]<<'\n';

    }   


    return !pref[d+1];

}

int howMany(int n, int m, vector<pair<int,int>> &planks, vector<int> &nails){
    int d = 0;
    for(auto [a,b] : planks) d = max(d, b);
    
    int first = 1, last = m;
    int ans = -1;
    while(first<=last){
        int mid = (first+last)/2;
        cerr<<"CHECK "<<mid << "\n";
        
        if(check(n,m,planks,nails,d,mid)){
            ans = mid;
            last = mid-1;

        }
        else first = mid+1;
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n=4, m=5;
    vector<pair<int,int>> p(4);
    p = {{1,4},{4,5},{5,9},{8,10}};
    vector<int> nails(5);
    nails = {4,6,7,10,2};
    cout<<howMany(n,m,p,nails);

    return 0;
}