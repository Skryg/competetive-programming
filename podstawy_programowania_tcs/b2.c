#include <stdio.h>

#define SZE 10000001


int main(){
   char sieve[SZE], halfprime_s[SZE];
int primes[SZE/10];
int id=0;
int pref_sum[SZE];
int pref_cnt[SZE][2]; /* 0 - len 2; 1 - len 3*/


    long long i,j;
    for(i=2;i<SZE;++i){
        sieve[i]=1;
        halfprime_s[i] = pref_sum[i] = pref_cnt[i][0] = pref_cnt[i][1]=0;
    }
    for(i=2;i<SZE;++i){
        if(!sieve[i]) continue;
        primes[id++]=i;
        for(j=i*i;j<SZE;j+=i){
            sieve[j]=0;
        }
    }

    for(i=0; i<id;++i){
        for(j=i; (long long)primes[i]*primes[j]<SZE && j<id;++j){
            halfprime_s[(long long)primes[i]*primes[j]]=1;
        }       
    }
    pref_sum[0] = 0;
    for(i=1;i<SZE;++i) pref_sum[i] = pref_sum[i-1]+halfprime_s[i];
    for(i=1;i<SZE;++i) pref_cnt[i][0] = pref_cnt[i-1][0] + ((halfprime_s[i] && halfprime_s[i-1]) ? 1 : 0);
    for(i=2;i<SZE;++i) pref_cnt[i][1] = pref_cnt[i-1][1] + ((halfprime_s[i] && halfprime_s[i-1] && halfprime_s[i-2]) ? 1 : 0);
    
    int sz[3];

    int z;
    scanf("%d", &z);
    while(z--){
        int a,b;
        scanf("%d %d", &a,&b);
        sz[0] = pref_sum[b]-pref_sum[a-1];
        sz[1] = pref_cnt[b][0]-pref_cnt[a][0];
        sz[2] = pref_cnt[b][1]-pref_cnt[a+1][1];

        int d=0;
        if(sz[0]) d=1;
        if(sz[1]) d=2;
        if(sz[2] && b-a>0) d=3;

        printf("%d %d\n", sz[0], d);
    }
    
    return 0;
}