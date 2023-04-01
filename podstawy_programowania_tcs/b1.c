#include <stdio.h>
#define SIZE 10000001

int sieve[SIZE];
int pref[SIZE];
long long primes[10001];
int id=0; 

int find_smallest_div(int num){
    long long i;
    for(i=0; primes[i]*primes[i]<=num;++i){
        if(num%primes[i]==0) return primes[i];
    }
    return 0;
}

int main(){
    int z;
    scanf("%d", &z);
    long long i,j;
    for(i=0;i<SIZE;++i){
        sieve[i]=1;
    }

    for(i=2; i<SIZE;++i){
        pref[i]=pref[i-1]+sieve[i];
        if(!sieve[i]) continue;
        if(id<=10000) primes[id++]=i;
        for(j=i*i; j<SIZE; j+=i){
            sieve[j]=0;
        }
    }

    for(i=0;i<z;++i){
        int a,b;
        scanf("%d %d",&a,&b);
        int a_div = (sieve[a] ? a : find_smallest_div(a));
        int b_div = (sieve[b] ? b : find_smallest_div(b));
        printf("%d %d %d\n", pref[b]-pref[a-1], a_div, b_div);

    }

    return 0;
}