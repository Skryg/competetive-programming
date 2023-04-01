#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define satori int z; scanf("%d", &z); while(z--)


int compute(int k, int* tab, int n, int print){
    int cnt = k;
    int pos = 0;
    if(*tab < *(tab+1)){
        if(print) printf("%d ", pos);
        cnt--;
        pos+=k;
    }
    while(pos < n-1 && cnt){
        if(*(tab+pos) < *(tab+pos+1) && *(tab+pos) < *(tab+pos-1)){
            cnt--;
            if(print) printf("%d ", pos);

            pos+=k;
        }
        else pos++;
    }
    if(pos == n-1 && cnt){
        if(*(tab+pos)<*(tab+pos-1)){
            cnt--;
            if(print) printf("%d ", pos);
        }
    }
    if(cnt) return 0;
    else return 1;

}

int main(){

    satori{
        int n; scanf("%d", &n);
        int *tab = malloc(sizeof(int)*n);
        for(int i=0;i<n;++i) scanf("%d",tab+i);
        
        if(n==1){
            printf("1\n0\n");
            free(tab);
            continue;
        }
        int num=0;
        int first = 0, last = (int)sqrt((double)(n))+1;
        while(first <= last){
            int k = (first+last)/2;
   //         printf("k: %d\n",k);
            int result = compute(k, tab,n,0);
            if(result){
                num = k;
                first = k+1;
            }
            else{
                last = k-1;
            }
        }

        printf("%d\n", num);
        compute(num,tab,n,1);
        printf("\n");

        free(tab);
    }

    return 0;
}