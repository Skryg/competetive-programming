#include <bits/stdc++.h>
#define satori int z; cin>>z; while(z--)
#define cerr if(0) cerr
using namespace std;


class cmp{
    int dial[26];
public:
    cmp(vector<char> &dialect){
        for(int i = 0; i<dialect.size();++i){
            dial[dialect[i]-'a']=i;
        }
    }

    bool operator() (const pair<string,string> &s1, const pair<string,string> &s2) const{
        
        for(int i=0;i<min(s1.first.size(), s2.first.size());++i){
            char c1 = tolower(s1.first[i]), c2 = tolower(s2.first[i]);
            if(c1!=c2){
                return dial[c1-'a'] < dial[c2-'a'];
            }
        }
        if(s1.first.size()!=s2.first.size()) return s1.first.size()<s2.first.size();

        for(int i=0;i<min(s1.second.size(), s2.second.size());++i){
            char c1 = tolower(s1.second[i]), c2 = tolower(s2.second[i]);
            if(c1!=c2){
                if(c1 == ' ' || c2 == ' ') return c1<c2;
                return dial[c1-'a'] < dial[c2-'a'];
            }
        }
        if(s1.second.size()!=s2.second.size()) return s1.second.size()<s2.second.size();
    }
};

class counter{
    int *count;
    string author;

public:
    counter(const string &s, int& cnt){
        count = &cnt;
        author = s;
        for(int i=0;i<author.size();++i){
            author[i] = tolower(author[i]);
        }
    }

    void operator() (const pair<string,string> &s){
        string pref="";
        for(int i=0;s.first[i]!=' ' && i<s.first.size();++i){
            pref+=tolower(s.first[i]);
        }
        if(author == pref) ++(*count);
    }
};

class title{
    string author;
public:
    title(const string &s){
        author = s;
        for(int i=0;i<author.size();++i){
            author[i] = tolower(author[i]);
        }
    }

    bool operator() (const pair<string,string> &s){
        int i=0;
        string pref="";
        for(i=0;s.first[i]!=' ' && i<s.first.size();++i){
            pref+=tolower(s.first[i]);
        }
        if(author == pref){
            return true;
        }
        return false;
    }
};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    satori{
        int n,k; cin>>n>>k;
        vector<pair<string,string>> books(n);
        vector<char> dialect(26);
        for_each(books.begin(),books.end(),[](pair<string,string> &s){cin>>s.first;getline(cin>>ws,s.second);while(s.second.back()==' ') s.second.pop_back();});
         cerr<<"BOOKS ";
            for(auto x : books){
                cerr<<x.first<<' '; 
            }


        for(int i=0;i<k;++i){
            for_each(dialect.begin(), dialect.end(), [](char &s){cin>>s;});
            cerr<<"DIAL ";
            for(auto x : dialect){
                cerr<<x<<' '; 
            }
            sort(books.begin(), books.end(), cmp(dialect));

            for_each(books.begin(), books.end(), [](const pair<string, string> &s){cout<<s.first<<' '<<s.second<< '\n';});
            
            string a,b; cin>>a>>b;
            int cnt=0;
            /*for(char i='a'; i<'a'+26;++i){
                dialect[i-'a']=i;
            }*/
            //sort(books.begin(), books.end(), cmp(dialect));
            for_each(books.begin(), books.end(), counter(a, cnt));
            auto it = find_if(books.begin(), books.end(), title(b));
            cout<<cnt<< ' ';
            if(it != books.end()){
                cout<<it->second;
            }
            else cout<<"BRAK";
            cout<<'\n';

        }       
    }

    return 0;
}