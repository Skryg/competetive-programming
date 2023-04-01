#include <bits/stdc++.h>

using namespace std;

int findGreater(int T[], int n,int val){
    int first = 0, last = n-1;
    int ans = -1;
    while(first<=last){
        int mid = (first+last)/2;
        if(T[mid] > val){
            last = mid-1;
            ans = mid;
        }
        else first = mid+1;
    }
    return ans;
}

bool check(int T[], int n, int k, int len){
    int pos = -1;
    
    while(k--){
        pos = findGreater(T,n,pos) + 2*len;;
        if(pos >= T[n-1]) return true; 
    }
    return false;
}

int search(int T[], int n, int k){
    int first = 0, last, ans = 0;

    int mx=0;
    for(int i=0;i<n;++i) mx = max(mx, T[i]);
    last = mx/k+1;


    while(first<=last){
        int mid = (first+last)/2;
        if(check(T,n,k,mid)){
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


    return 0;
}