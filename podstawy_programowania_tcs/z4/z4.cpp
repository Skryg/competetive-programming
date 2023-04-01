#include <bits/stdc++.h>

using namespace std;

string bits[29]={
    "1110",
    "1000111",
    "10111",
    "10000111",
    "1001",
    "1000100",
    "1000110",
    "1000101",
    "1100",
    "111110",
    "00011",
    "1000001",
    "1000000",
    "0101",
    "1010",
    "00010",
    "100001001",
    "0100",
    "11011",
    "11010",
    "111111",
    "100001000",
    "11110",
    "10000101",
    "10110",
    "0010",
    "0111",
    "0110",
    "0011"
};

map<string, char> bchar = {
    {bits[0],'a'},
    {bits[1],'b'},
    {bits[2],'c'},
    {bits[3],'d'},
    {bits[4],'e'},
    {bits[5],'f'},
    {bits[6],'g'},
    {bits[7],'h'},
    {bits[8],'i'},
    {bits[9],'j'},
    {bits[10],'k'},
    {bits[11],'l'},
    {bits[12],'m'},
    {bits[13],'n'},
    {bits[14],'o'},
    {bits[15],'p'},
    {bits[16],'q'},
    {bits[17],'r'},
    {bits[18],'s'},
    {bits[19],'t'},
    {bits[20],'u'},
    {bits[21],'v'},
    {bits[22],'w'},
    {bits[23],'x'},
    {bits[24],'y'},
    {bits[25],'z'},
    {bits[26],' '},
    {bits[27],'.'},
    {bits[28],'\n'}
};

char convert(string s){
    char c=0;
    for(int i=0;i<s.size();++i){
        c<<=1;
        c+=(s[i]-'0');
    }
    return c;
}


int main(int argc, char* argv[]){
    ifstream input(argv[1]);
    ofstream output(argv[2]);
    int type = argv[3][0]-'0';
    //cout<<type;
    if(input.good()&&output.good()){
        if(type == 1){
            char c;
            string holder="";
            while(input.get(c)){
                string add="";
                //cout<<(int)c<<' ';
                //if(c==0) continue;
                if(c == ' ') add = bits[26];
                else if(c=='.') add = bits[27];
                else if(c=='\n') add = bits[28];
                else add = bits[c-'a'];
                //cout<<add<<' ';
                for(int i=0;i<add.size();++i){
                    holder+=add[i];
                    //cout<<holder.size();
                    if(holder.size()==8){
                        char x = convert(holder);
                        //cout<<"x:";
                        //cout<<holder<<' ';
                        output << x;
                        holder="";
                    }
                }
                

            }
            if(holder.size()!=0){
                    while(holder.size()<8) holder+='0';
                    //cout<<holder;
                    char c = convert(holder);
                    output<<c;
            }
        }
        if(type == 2){
            string holder="";
            char c;
            while(input.get(c)){
                
                //if(c==0) continue;
                for(int i=7;i>=0; --i){
                    if((c>>i) & 1) holder+='1';
                    else holder+='0';
                    if(bchar.find(holder)!=bchar.end()){
                        output<<bchar[holder];
                        //cout<<holder<<' ';
                        holder = "";
                    }
                }
            }
        }
    }
    if(input.is_open()) input.close();
    if(output.is_open()) output.close();


    return 0;
}