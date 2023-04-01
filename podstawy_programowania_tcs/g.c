#include <stdio.h>
#include <string.h>

#define satori int z; scanf("%d", &z); while(z--)

int main(){
    char str[] = "%d %.";
    char str2[] = "LF\n";
    char buf[20];
    int tab[1000000];
    satori{
        int n,k,b,d;
        scanf("%d %d %d %d", &n, &k, &b, &d);
        for(int i=0;i<n;++i) scanf("%d", &tab[i]);
        int x = -1;
        int front, back;
        long long max = 0;
        long long sum = 0;
        long double avg = 0;
        for(int i=0;i<n;++i){
            while(x+1<n && (tab[x+1]%k==0 || x<i-1 || b)){
                x++;
                if(tab[x]%k) b--;
                sum += (long long)tab[x];
                int len = x-i+1;
                if(max < len){
                    max = len;
                    avg = (long double)sum/len;
                    front = x;
                    back = i;
                }
                else if (len && max == len && avg <= (long double)sum/len){
                    avg = (long double)sum/len;
                    front = x;
                    back = i;
                }
            }

            sum-=(long long)tab[i];
            if(tab[i]%k) b++;
        }

        if(max){
            sprintf(buf, "%s%d%s",str, d, str2);
           /* avg *= ten[d];
            avg = roundl(avg);
            avg /= ten[d];*/
            printf(buf, max, avg); 
            for(int i=back; i<=front; ++i) printf("%d ",tab[i]);
            printf("\n");
        }
        else printf("NIE\n");
    }

    return 0;
}