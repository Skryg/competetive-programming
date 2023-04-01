#include <bits/stdc++.h>

using namespace std;

typedef long long ll;



int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    vector<int> matrix(n+1, 0);
    vector<int> a(n+1),b(n+1);
    for(int i=1;i<=n;++i){
        cin>>a[i];
    }
    for(int i=1;i<=n;++i){
        cin>>b[i];
    }
    for(int i=1;i<=n;++i){
        for(int j=n;j>0;--j){
            if(a[i]==b[j]) matrix[j]=matrix[j-1]+b[j];
        }
        for(int j=1; j<=n;++j){
            if(matrix[j-1]>matrix[j]){
                matrix[j] = matrix[j-1];
            }
        }
    }
    
    cout<<matrix[n];
    return 0;
}