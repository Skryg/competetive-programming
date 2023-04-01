#include <bits/stdc++.h>

using namespace std;
vector<vector<int>> dup;


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string n1, n2,s;
    cin>>n1>>n2;
    dup.resize(n1.size()+1, vector<int>(n2.size()+1,0));
    for(int i=1;i<=n1.size();++i){
        for(int j=1;j<=n2.size();++j){
            if(n1[i-1]==n2[j-1]){
                dup[i][j] = dup[i-1][j-1]+1;
            }
            else
                dup[i][j] = max(dup[i-1][j],dup[i][j-1]);
        }
    }
    int i{(int)n1.size()},j{(int)n2.size()};

    while(i>0 && j>0){
        if(n1[i-1]==n2[j-1]){
           
            --i;
            --j;
            s+=n1[i];
            
        }
        else if(dup[i][j-1]>dup[i-1][j]){
            --j;
        }
        else --i;
    }
    cout<<dup[n1.size()][n2.size()]<<"\n";
    for(string::iterator t = s.end()-1; t>=s.begin();--t){
        cout<<*t;
    }
    
    return 0;
}