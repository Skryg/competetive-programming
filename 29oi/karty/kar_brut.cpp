#include <bits/stdc++.h>

using namespace std;

bool is_sorted(list<int> &l){
    int start{1};
    for(auto i : l){
        if(i == start) start++;
        else return false;
    }
    return true;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n; cin>>n;
    vector<int> perm(n);
    vector<int> nums(10000);
    vector<int> costs(n+1);
    vector<int> ans;
    for(int i=0;i<n;++i) perm[i]=i+1;
    int count{0};
    int iter{0};
    do {
        vector<int> costs2(n+1);
        int sum{0};
        list<int> lst;
        for(auto i : perm) lst.push_back(i);
        int times{0},times2{0};
        while(!is_sorted(lst)){
            int find{(*lst.begin())-1};
            if(!find) find = lst.size();
            for(auto i = lst.begin(); i != lst.end(); i++){
                if(*i == find){
                    lst.erase(i);
                    lst.push_front(find);
                    costs[times2]++;
                    costs2[times2]++;
                    sum+=times2;
                    times2=0;
                    break;
                }
                else {times++; times2++;}
            }
            
            
        }
        //cout<<"1st: " <<times<<"\n";
        //ans.push_back(times);
        nums[times]++;
        count+=times; 
        iter++;
        


    } while(next_permutation(perm.begin(), perm.end()));
    //sort(ans.begin(), ans.end());
 
    cout<<count;
   
    
    return 0;
}