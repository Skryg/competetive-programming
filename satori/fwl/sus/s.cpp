#include <bits/stdc++.h>

using namespace std;

vector<int> factorize(int num){
    vector<int> fact;
    for(int i=1;i*i<=num;++i){
        if(num%i==0){
            fact.push_back(i);
            if(i*i!=num) fact.push_back(num/i);
        }
    }
    return fact;
}

int main(){
    int x; cin>>x;
    vector<int> n = factorize(x);
    sort(n.begin(),n.end());
    for(auto i : n) cout<<i<< " ";
    return 0;
}