#include <bits/stdc++.h>
#define satori int z; cin>>z; while(z--)

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    vector<pair<long long,long long>> input(100000);
    satori{
        long long left_dist=0, left_cars=0,left_sum=0;
        long long right_dist=0, right_cars=0,right_sum=0;
        long long min_sum = LLONG_MAX;
        int n; cin>>n;
        for(int i=0;i<n;++i) {
            auto &[a,b] = input[i];
            cin>>a>>b;
        }

        for(int i=n-1; i; --i){
            auto [car,dist] = input[i];
            left_dist+=dist;
            left_sum+=car*left_dist;
            left_cars+=car;
        }
//        cout<<left_sum <<' '<<right_sum << "\n\n";
        //cout << left_cars << endl;
        int del_edge = 0;
        for(int i=0;i<n;++i){
            //i - number of first city
            int next_edge = (del_edge+1)%n;
            //long long rdist= right_dist+input[del_edge].second;
            //long long rsum = right_sum +rdist*input[next_edge].first;
           // long long ldist = left_dist - input[next_edge].second;
            //long long lsum = left_sum  - left_dist*input[next_edge].first;
            min_sum = min(min_sum, left_sum+right_sum);
 //           cout<<left_sum <<' '<<right_sum << '\n';

            while(input[next_edge].first*(right_dist+input[del_edge].second)-left_dist*input[next_edge].first <= 0){
                right_dist+=input[del_edge].second;
                right_sum+= right_dist*input[next_edge].first;
                right_cars+=input[next_edge].first;
                left_sum -= left_dist*input[next_edge].first;
                left_dist -= input[next_edge].second;
                left_cars -= input[next_edge].first;
       //         cout<<left_sum <<' '<<right_sum << '\n';
                //cout << left_sum << " " << right_sum << endl;
                min_sum = min(min_sum, left_sum+right_sum);

                del_edge = next_edge;
                next_edge = (next_edge+1)%n;
            }
     //       cout<<"X"<<left_sum <<' '<<right_sum << "\n";
   //         cout<<"W"<<left_cars + right_cars + input[i].first << ' ' <<right_dist + left_dist + input[del_edge].second<<"\n\n";
            min_sum = min(min_sum, left_sum+right_sum);
            
            left_dist+=input[i].second;
            left_cars+=input[i].first;
            left_sum+=(left_cars*input[i].second);
            int next = (i+1)%n;
            right_sum-=(input[i].second*right_cars);
            right_cars-=input[next].first;
            right_dist-=input[i].second;
            cout << "money: " << min_sum << "\n";
        }
        cout<<min_sum<<"\n";
    }

    return 0;
}