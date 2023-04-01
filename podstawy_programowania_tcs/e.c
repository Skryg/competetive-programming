#include <stdio.h>
#define satori int z; scanf("%d",&z); while(z--)

void swap(int* a, int *b){
    int buf; 
    buf = *a;
    *a=*b;
    *b=buf;
}

int tab[100000];

int main(){
    satori{
        int n;
        scanf("%d", &n);
        int i,j,z;
        for(i=0;i<n;++i){
            scanf("%d", &tab[i]);
        }
        for(i=0;i<n;++i){
            for(j=i; j>0;--j){
                if(tab[j]<tab[j-1]) swap(&tab[j],&tab[j-1]);
                else break;
            }
        }
        int done=0;
        for(i=0;i<n;++i){
            z=n-1;
            for(j=i; j<n && j <= z; j++){
                while(tab[i]+tab[j]+tab[z] > 0 && z>j) z--;
                if(tab[i]+tab[j]+tab[z] == 0){
                    done =1;
                    break;
                }
            }
            if(done) break;
        }
        for(int i=0;i<n;++i){
            printf("%d ", tab[i]);
        }
        if(done) printf("\nTAK %d %d %d\n", i, j, z);
        else printf("\nNIE\n");
    }
    return 0;
}   