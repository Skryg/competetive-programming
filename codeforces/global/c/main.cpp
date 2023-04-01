#include <bits/stdc++.h>

#define satori int t; cin>>t; while(t--)
#define vt vector
#define pr pair
#define pb push_back
#define st first
#define nd second

using namespace std;

void make_output(list<int>& op, list<int> a){
    while(!a.empty()){
        if(a.front() > a.back()){
            int x = a.front();
            a.pop_front();
            op.push_front(x);
        }
        else{
            int x = a.back();
            a.pop_back();
            op.pb(x);
        }
        
    }
}

int reverse(list<int>& op, list<int> a){
    while(a.size()>1){
        if(a.front() < a.back()){
            int x = a.front();
            a.pop_front();
            op.push_front(x);
        }
        else{
            int x = a.back();
            a.pop_back();
            op.pb(x);
        }

    }
    return a.front();
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    satori{
        int n; cin>>n;
        list<int> a(n);
        list<int> output;
        for(auto &i : a){
            cin>>i;
        }
        make_output(output,a);
        list<int> check;
        int x = reverse(check,output);
        bool bad{false};
        if(check.size()>0){
            if(a.front()!=check.front()){
                check.push_front(x);
            }
            else check.push_back(x);
            auto it = a.begin();
            auto it2 = check.begin();

            while(it != a.end()){
                if((*it)!=(*it2)){
                    cout<<-1<<"\n";
                    bad = true;
                    break;
                }
                it++;
                it2++;
            }
            if(bad) continue;

        }

        for(auto i : output){
            cout<<i<<" ";
        }
        cout<<"\n";

    }

    return 0;
}