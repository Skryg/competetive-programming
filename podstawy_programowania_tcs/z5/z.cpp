#include <bits/stdc++.h>
#define satori int z; cin>>z; while(z--)

using namespace std;

constexpr int plusval = 1'000'000;
int posit[2'000'001];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    satori{
        string s; cin>>s;
        vector<pair<int,int>> intervals(2);
        vector<pair<char,char>> chars(1);
        chars[0].first = s[0];
        int cnt=0;
        for(int i=1;i<s.size();++i){
            if(!chars[cnt].second && s[i]!=chars[cnt].first) chars[cnt].second = s[i];
            if(chars[cnt].first != s[i] && chars[cnt].second != s[i]){
                intervals[cnt].second = i-1;
                intervals.push_back({0,0});
                cnt++;
                chars.push_back({s[i-1], s[i]});
            }
            if(s[i]!=s[i-1]) intervals[cnt+1].first = i;
        }
        intervals[cnt].second = s.size()-1;

        int mx = 0;
        for(int i=0;i<=cnt;++i){
            auto [first, last] = intervals[i];
            auto [char1,char2] = chars[i];
            //j+2
            int val=0;
            for(int j=first;j<=last;++j){
                if(posit[val+plusval] == 0) posit[val+plusval] = j+1;
                if(s[j]==char1) val++;
                else val--;
                if(posit[val+plusval]) mx = max(mx,j+2-posit[val+plusval]);
                
            }
            val=0;
            for(int j=first;j<=last;++j){
                posit[val+plusval]=0;
                if(s[j]==char1) val++;
                else val--;                
            }
        }
        cout<<mx<<'\n';

    }



    return 0;
}