#include <bits/stdc++.h>

using namespace std;

char ch_format(char c){
    if(c>='a'&&c<='z') return c;
    if(c>='A' && c<='Z') return c-'A'+'a';
    if(c>='0' && c<= '9') return c;
    if(c=='\n') return c;
    return ' ';
}
int str_id=0;

bool letter(char c){
    if(c>='a'&&c<='z') return true;
    if(c>='A' && c<='Z') return true;
    return true;
}

bool number(char c){
    return c>='0'&&c<='9';
}

int check(string word, string good){
    //cout<<word<< '\n';
    int w=0, g=0;
    int matching = 0;
    while(word.size() !=w && good.size()!=g){
        if(word[w] == good[g]) matching++;
        w++, g++;
    }
    if(w == word.size() && g == good.size() && matching >=g-1) return 1;

    g=w=0;
    int add = 1;
    while(word.size()!=w){
        if(good.size() == g || word[w]!=good[g]){
            if(!add) break;
            w++;
            add--;
        }
        else{
            w++,g++;
        }
    }
    if(word.size()==w && good.size()==g) return 1;
    
    g=w=0;
    add=1;
    while(good.size()!=g){
        if(word.size() == w || word[w]!=good[g]){
            if(add==0) break;
            g++;
            add--;
        }
        else{
            w++,g++;
        }
    }
    if(word.size() == w && good.size() == g) return 1;
    return 0;

}

int main(int argc, char* argv[]){
    if(argc<3) return 0;
    ifstream input(argv[1]);
    ofstream output(argv[2]);

    string str;
    for(int i=0;argv[3][i]!='\0';++i){
        argv[3][i] = ch_format(argv[3][i]);
    }
    string good = argv[3];

    if(input.good() && output.good()){
        int slash_mode = 0, star_mode=0;
        int comment=0;
        while(!input.eof()){
            char c;
            input.get(c);
            
            if(!comment && (!number(c) || (str.size() && str.back()!=' ' && str.back()!='\n'))){
                str+=ch_format(c);
            }

            if(slash_mode){
                if(c == '*'){
                    if(!comment){
                        str.pop_back();
                        str.pop_back();
                    }
                    comment++;

                }
                if(c!='/') slash_mode = 0;
            }
            else if(star_mode){
                if(c == '/' && comment){
                    comment--;
                }
                if(c!='*') star_mode = 0;
            }
            else if(c == '/'){
                slash_mode = 1;
                star_mode =0;
            }
            else if(c == '*'){
                star_mode = 1;
                slash_mode =0;
            }
            else star_mode = slash_mode = 0;            
        }
        //string checking
        string word="";
        int ws=0,gd=0;
        int line =1;
        for(int i=0;i<str.size();++i){
            int res=0;
            if(str[i] == ' '){
                res = check(word, good);
                if(res) output << "Linia "<<line<<": "<<word<<"\n";
                if(word.size()){
                    if(res) gd++;
                    ws++;
                }
                word="";

            }
            else if(str[i]=='\n'){
                res = check(word, good);
                if(res) output << "Linia "<<line<<": "<<word<<"\n";
                line++;
                if(word.size()){
                    if(res) gd++;
                    ws++;
                }
                word="";
            }
            else{
                word+=str[i];
            }
        }
        output << "Wyrazy: "<<ws<<"\nWyrazy specjalne: "<<gd<<"\n";

    }
    if(input.is_open()) input.close();
    if(output.is_open()) output.close();
    return 0;
}