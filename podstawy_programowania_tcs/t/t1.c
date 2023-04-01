#include <stdio.h>
#include <string.h>
#define SIZE 1000000

char ch_format(char c){
    if(c>='a'&&c<='z') return c;
    if(c>='A' && c<='Z') return c-'A'+'a';
    if(c>='0' && c<= '9') return c;
    if(c=='\n') return c;
    return 0;
}
char str[SIZE];
int str_id=0;

int letter(char c){
    if(c>='a'&&c<='z') return 1;
    if(c>='A' && c<='Z') return 1;
    return 0;
}

int number(char c){
    return c>='0'&&c<='9';
}

int check(char* word, char* good){
    int w=0, g=0;
    int matching = 0;
    while(word[w]!='\0' && good[g]!='\0'){
        if(word[w] == good[g]) matching++;
        w++, g++;
    }
    if(word[w]=='\0' && good[g] == '\0' && matching >=g-1) return 1;

    g=w=0;
    int add = 1;
    while(word[w]!='\0'){
        if(word[w]!=good[g]){
            if(!add) break;
            w++;
            add--;
        }
        else{
            w++,g++;
        }
    }
    if(word[w]=='\0' && good[g]=='\0') return 1;
    
    g=w=0;
    add=1;
    while(good[g]!='\0'){
        if(word[w]!=good[g]){
            if(add==0) break;
            g++;
            add--;
        }
        else{
            w++,g++;
        }
    }
    if(word[w]=='\0' && good[g]=='\0') return 1;
    return 0;

}

int main(int argc, char* argv[]){
    if(argc<3) return 0;
    FILE *input = fopen(argv[1],"r");
    FILE *output = fopen(argv[2],"w");
    for(int i=0;argv[3][i]!='\0';++i){
        argv[3][i] = ch_format(argv[3][i]);
    }

    if(input != NULL && output != NULL){
        int slash_mode = 0, star_mode=0;
        int comment=0;
        while(!feof(input)){
            char c = getc(input);
            
            if(!comment && (!number(c) || (str_id>0 && str[str_id-1]!=0 && str[str_id-1]!='\n'))){
                str[str_id++]=ch_format(c);
            }

            if(slash_mode){
                if(c == '*'){
                    if(!comment) str_id-=2;
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
        char word[SIZE];
        int word_size = 0;
        int ws=0,gd=0;
        int line =1;
        for(int i=0;i<SIZE;++i){
            int res=0;
            if(str[i] == 0){
                word[word_size]='\0';
                res = check(word, argv[3]);
                if(res) fprintf(output, "Linia %d: %s\n", line, word);
                if(word_size){
                    if(res) gd++;
                    ws++;
                }
                word_size=0;

            }
            else if(str[i]=='\n'){
                word[word_size]='\0';
                res = check(word, argv[3]);
                if(res) fprintf(output, "Linia %d: %s\n", line, word);
                line++;
                if(word_size){
                    if(res) gd++;
                    ws++;
                }
                word_size=0;
            }
            else{
                word[word_size++] = str[i];
            }
        }
        fprintf(output, "Wyrazy: %d\nWyrazy specjalne: %d\n", ws,gd);
        //for(int i=0;i<str_id;++i) printf("%c", str[i]);

    }
    if(input!=NULL) fclose(input);
    if(output!= NULL )fclose(output);
    return 0;
}