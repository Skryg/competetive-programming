#include <stdio.h>
#include <stdlib.h>
#define satori int z; scanf("%d",&z); while(z--)

char convert(char c){
    if(c >= 'a') return c;
    return c-'A'+'a';
}

int is_letter(char c){
    if(c>='a' && c<='z') return 1;
    return 0;
}

void swap(char** p1, char** p2){
    char* buf = *p1;
    *p1 = *p2;
    *p2 = buf;
}

int depth;
int compare(const void *x1, const void *x2){
    const char *p1 = *(const char **)x1;
    const char *p2 = *(const char **)x2;
    if(is_letter(p1[depth])==0 && is_letter(p2[depth])==0) return 0;
    if(is_letter(p2[depth])==0) return 1;
    if(is_letter(p1[depth])==0) return -1;

    if(p1[depth] < p2[depth]) return -1;
    if(p1[depth] > p2[depth]) return 1;
    return 0;
}
char** string;

void sort(int a, int b, int depth1){
    if(b-a==1) return;
    depth = depth1;
    qsort(string+a, b-a, sizeof(string[a]), compare);
    /*
    for(int i=a; i<b;++i){
        for(int j=i; j>a; --j){
            if(is_letter(string[j][depth])==0||(string[j-1][depth] > string[j][depth]))
                swap(&string[j], &string[j-1]);
            else break;
        }
    }
    */
    char curr = string[a][depth1];
    int x = a;
    for(int i = a; i<b;++i){
        if(curr != string[i][depth1]){
            if(is_letter(curr)) sort(x, i, depth1+1);
            x=i;
            curr = string[i][depth1];
        }
    }
    sort(x, b, depth+1);
}

struct Count{
    int cnt;
    char* str;
};
struct Count count[20000];

int main(){
    string = (char**)malloc(sizeof(char*)*20000);
    for(int i=0;i<20000;++i) string[i] = (char*)malloc(sizeof(char)*1001);
    satori{
        int n; scanf("%d", &n);
        for(int i=0;i<n;++i){
            scanf("%s", string[i]);
            for(int j=0;string[i][j]!='\0';++j) string[i][j] = convert(string[i][j]);
        }
        sort(0, n, 0);
        /*for(int i = 0;i<n;++i){
            printf("%s\n", string[i]);
        }*/

        int x = 0;
        count[x].str = string[0];
        count[x].cnt = 1;
        for(int i=1;i<n;++i){
            for(int j=0;j<=1000;j++){
                if(string[i][j] == '\0' && string[i-1][j] == '\0') break;
                if(string[i][j] != string[i-1][j]){
                    count[++x].str = string[i];
                    count[x].cnt = 0;
                    break;
                }        
            }
            count[x].cnt++;
        }

        printf("%d\n", x+1);

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
        for(int i=0;i<=x;++i){
            printf("%s %d\n", count[i].str, count[i].cnt);
        }

        for(int i=0;i<n;++i) for(int j=0;string[i][j]!='\0';++j) string[i][j]='\0';
        
    }
    for(int i=0;i<20000;++i) free(string[i]);
    free(string);
    
    return 0;
}