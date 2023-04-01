#include <bits/stdc++.h>
#define rep(x) for(int i=0;i<x;++i)
#define vt vector
#define ll long long
#define MOD 1'000'000'007LL
#define st first
#define nd second
#define ep emplace_back
#define pb push_back
using namespace std;

bool comp(vt<int>& smaller, vt<int>& bigger){
    int s{0};
    for(int i=0;i<bigger.size();++i){
        if(bigger[i] && !smaller[i]) return false;
        if(bigger[i] && smaller[i] ){
            if(!(bigger[i]%smaller[i])){
                if(!s) s = bigger[i]/smaller[i];
                else if (s*smaller[i] != bigger[i]) return false;
            }
            else return false;
        }
    }
    return true;
}

char temp_char(vt<string> &t, int pos, bool horizon){
    if(horizon) return t[0][pos];
    return t[pos][0];
}

bool is_single(vt<int> &alphabet){
    int no_zero{0};
    for(auto i : alphabet){
        if(i) no_zero++;
    }
    if(no_zero == 1) return true;
    return false;
}

void extend(vt<bool> &tab, int &last, int &first, int length, int &bads){
    
    for(first = last; first >= 0 && first > last - length; --first){
        if(tab[first]) bads++;
    }
    
}

void set_vert(vt<vt<bool>> &tab,int length, int height, int act_height, int horizon, bool &messed, vt<string> &str, bool temp_horizont){
    for(int i=0;i<length;++i){
        if(act_height+i >= height){ messed = true; return;}
        if(str[act_height+i][horizon]==temp_char(str, i, temp_horizont))
            tab[act_height+i][horizon] = true;
        else {messed=true; return;}
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    set<int> divisors, answers;
    //input
    int n,m; cin>>n>>m;
    vector<string> tab(n);
    rep(n){
        cin>>tab[i];
    }
    //divisors
    rep(n){if(!(n%(i+1))) divisors.insert(i+1);}
    rep(m){if(!(m%(i+1))) divisors.insert(i+1);}
    //hashes
    vt<ll> p1(1001),p2(1001);
    p1[0]=1; p2[0]=1;
    rep(1000){
        p1[i+1]=p1[i]*29%MOD;
        p2[i+1]=p2[i]*31%MOD;
    }
    vt<vt<ll>> hash1,hash2;
    vt<ll> hash1v(n),hash2v(n);
    hash1.resize(n, vt<ll>(m));
    hash2.resize(n, vt<ll>(m));
    hash1v[0]=tab[0][0]-'a'+1;
    hash2v[0]=tab[0][0]-'a'+1;
    for(int i=1;i<n;++i){
        int num{tab[i][0]-'a'+1};
        hash1v[i]=(p1[i]*num%MOD+hash1v[i-1])%MOD;
        hash2v[i]=(p2[i]*num%MOD+hash2v[i-1])%MOD;
    }
    rep(n){
        hash1[i][0] = tab[i][0]-'a'+1;
        hash2[i][0] = tab[i][0]-'a'+1;
        for(int j=1;j<m;++j){
            int num{tab[i][j]-'a'+1};
            hash1[i][j]=(p1[j]*num%MOD+hash1[i][j-1])%MOD;
            hash2[i][j]=(p2[j]*num%MOD+hash2[i][j-1])%MOD;
        }
        
    }
    //alphabet elimination
    vector<int> number(26);
    rep(n){
        for(int j=0;j<m;++j){
            number[tab[i][j]-'a']++;
        }
    }
    vector<int> txt(26);
    vector<pair<int,bool>> to_check;
    for(auto i : divisors){
        fill(txt.begin(),txt.end(),0);
        if(m>=i){
            for(int j=0;j<i;++j) txt[tab[0][j]-'a']++;
            if(comp(txt, number)) to_check.ep(i, true);
        }
        
        fill(txt.begin(),txt.end(),0);
        if(n>=i){
            for(int j=0;j<i;++j) txt[tab[j][0]-'a']++;
            if(comp(txt, number)) to_check.ep(i, false);
        }
        
    }
    bool no_check = is_single(number);

    for(auto q : to_check){
        vt<pair<int,int>> news;
        bool bad{false};
        int number{q.st};
        bool horizon{q.nd};
        if(no_check){
            answers.insert(number);
            continue;
        }
        vt<vt<bool>> blocked(n, vt<bool>(m));
        if(answers.find(number)!=answers.end()) continue;
        int streak{0}, final{-1};
        rep(n){
            if(streak!=0){
                if(final==-1) final = streak;
                else final = __gcd(final, streak);
                streak = 0;
            }
            int bad_num{0};
            int last{m-1};
            int first{last};
            if(last-number+1>=0) extend(blocked[i], last, first, number, bad_num);
            while(last>=0){
                ll hash_t1{0},hash_t2{0};
                if(horizon){
                    hash_t1 = hash1[0][number-1];
                    hash_t2 = hash2[0][number-1];
                }
                else{
                    hash_t1 = hash1v[number-1];
                    hash_t2 = hash2v[number-1];
                }
                ll h1,h2;
                if(first==-1){ h1 = hash1[i][last]; h2 = hash2[i][last];}
                else{
                    h1= (hash1[i][last]-hash1[i][first]+MOD)%MOD;
                    h2=(hash2[i][last]-hash2[i][first]+MOD)%MOD;
                }
                
                if(first+1 >=0 && bad_num == 0 && h1==hash_t1*p1[first+1]%MOD && h2==hash_t2*p2[first+1]%MOD){
                    last = first;
                    extend(blocked[i],last, first, number, bad_num);
                    streak++;
                }
                else {
                    if(streak!=0){
                        if(final==-1) final = streak;
                        else final = __gcd(final, streak);
                        streak = 0;
                    }

                    if(i==0 || !(blocked[i-1][last])) news.pb({i,last});
                    if(!blocked[i][last]){set_vert(blocked, number, n, i, last, bad, tab, horizon); bad_num++;}
                    if(first >=0 && blocked[i][first]) bad_num++;
                    if(blocked[i][last]) bad_num--;
                    last--;
                    first--; 
                }
                if(bad) break;

                
                
            }

            if(bad) break;
            
        }
        if(bad) continue;
        if(final != 1){
            for(int j=0;j<news.size();++j){
                pair<int,int> p = news[j];
                int z{0};
                int strea{0};
                while(p.st+z+number-1 < n){
                    if(blocked[p.st+z][p.nd] && blocked[p.st+z+number-1][p.nd]) strea++;
                    else break;
                    z+=number;
                }
                if(final == -1) final = strea;
                else final = __gcd(final, strea);
                //cout<<strea<<" ";
                
            }
        }
        if(final != 1){

            for(auto j : to_check){
                if(j.st%number==0 &&(number*final)% j.st == 0){
                    answers.insert(j.st);
                }
            }
        }
        answers.insert(number);

    }
    cout<<answers.size()<<"\n";
    for(auto i : answers) cout<<i<<" ";
    return 0;
}
