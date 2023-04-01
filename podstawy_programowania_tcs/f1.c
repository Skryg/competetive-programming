#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#define satori int z; scanf("%d", &z); while(z--)
#define SIZE 1001

struct Count{
    int cnt, index;
};
int main(){
    char **string;
    //char temp[SIZE];
    string = (char**)malloc(sizeof(char*)*20000);
    for(int i=0;i<20000;++i) string[i] = (char*)malloc(sizeof(char)*SIZE);
    struct Count count[20000];

    satori{
        int n; scanf("%d", &n);
        for(int i=0;i<n;++i){
            scanf("%s",string[i]);
            for(int j=0;string[i][j]!='\0';++j) string[i][j] = tolower(string[i][j]);
        }
        for(int i=1;i<n;++i){
            for(int j=i; j; --j){
                if(strcmp(string[j-1], string[j])>0){
                    char* temp = string[j-1];
                    string[j-1] = string[j];
                    string[j] = temp;
                }
                else break;
            }
        }
        //for(int i=0;i<n;++i) printf("%s\n", string[i]);

        int x = 0;
        count[x].index = 0;
        count[x].cnt = 1;
        for(int i=1;i<n;++i){
            if(strcmp(string[i], string[count[x].index]) != 0){
                count[++x].index = i;
                count[x].cnt = 0;
            }
            count[x].cnt++;
        }
        for(int i=1;i<=x;++i){
            for(int j=i; j;--j){
                if(count[j].cnt > count[j-1].cnt){
                    struct Count buf = count[j-1];
                    count[j-1] = count[j];
                    count[j] = buf;
                }
                else break;
            }
        }
        printf("%d\n", x+1);
        for(int i=0;i<=x;++i) 
            printf("%s %d\n",string[count[i].index],count[i].cnt);

    }
    for(int i=0;i<20000;++i) free(string[i]);
    free(string);
    return 0;
}