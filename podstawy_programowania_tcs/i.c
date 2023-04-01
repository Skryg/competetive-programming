#include <stdio.h>
#include <string.h>
#define satori int z; scanf("%d", &z); while(z--)

unsigned long long char_to_dec(char c){
    if(c >= 'A' && c<= 'F') return c-'A'+10;
    return c-'0';
}

char dec_to_char(long long num){
    if(num>=10) return 'A'-10+num;
    return '0'+num;
}

int main(){
    char command[10];
    char number[500];
    long long number2[500];
    //for(int i=0;i<16;++i) printf("%lld ",char_to_dec(dec_to_char(i)));
    //printf("\n");
    satori{
        scanf("%s",command);
        if(strcmp(command, "CONVERT")==0){
            unsigned long long p,q;
            unsigned long long dec = 0;
            scanf("%lld %lld %s", &p, &q, number);
            int x=strlen(number);
            unsigned long long base = 1;
            while(x){
                dec += base*char_to_dec(number[--x]);
                base*=p;
            }
            //printf("%d ",dec);
            while(dec){
                number2[x++] = dec%q;
                dec/=q;
            }
            if(x==0) printf("%d",0);
            for(int i = x-1; i>=0; --i){
                printf("%c", dec_to_char(number2[i]));
            }
            printf("\n");
        }
        else if(strcmp(command, "WRITE")==0){
            long long x,r;
            scanf("%lld %lld", &r, &x); 
            long long test = 0, bad = 0;

            if(x<0) test = 1;
            for(int i=r;i<=64;++i){
                if(((x>>(i-1))&1)!=test) bad = 1;
                //printf("%lld",(x>>(i-1))&1);
            }
            //printf("\n");
            if(bad){
                printf("ERROR\n");
                continue;
            }
            for(int i=r; i; i--){
                printf("%lld", x>>((i-1))&1);
            }
            printf("\n");
        }
        else if(strcmp(command, "READ")==0){
            scanf("%s", number);
            int size = strlen(number);
            unsigned long long two = 1LL<<(size-1);
            long long answer = (number[0]=='1' ? -(long long)two : 0);
            for(int i = 1; two>>1;++i){
                two>>=1;
                if(number[i]=='1') answer+=two;
            }   
            printf("%lld\n", answer);
        }
    }
    return 0;
}