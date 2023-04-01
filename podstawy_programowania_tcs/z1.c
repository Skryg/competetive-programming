#include <stdio.h>

#define SIZE 2*300001
#define satori int z; scanf("%d", &z); while(z--)

int sieve[SIZE];
int primes[SIZE];
int sequence[SIZE];
int checked[2*SIZE];
int prime_id=0;
int sequence_id=2;
int position[SIZE];


int main(){
	long long i,j;
	for(i=0;i<SIZE;++i){
		sieve[i] = 1;
		primes[i]=0;
	}
	for(i=0;i<2*SIZE;++i) checked[i]=0;
	sieve[0]=sieve[1]=0;
	checked[1]=checked[2]=1;
	for(i=2;i<SIZE;++i){
		if(!sieve[i]) continue;
		for(j=i*i; j<SIZE; j+=i){
			sieve[j]=0;
		}
		sieve[i]=++prime_id;

	}
	primes[1]=1;
	sequence[0]=1;
	sequence[1]=2;
	int current_prime = 2;
	int candidate;
	int mini;
	while(sequence_id != SIZE){
		candidate = current_prime;
		int number_check = primes[sieve[candidate]];
		while(checked[candidate*(primes[sieve[candidate]]+1)]) primes[sieve[candidate]]++;
		
		mini = candidate*(primes[sieve[candidate]]+1);
		if(sieve[number_check]){
			while(checked[number_check*(primes[sieve[number_check]]+1)]) primes[sieve[number_check]]++;

			if(mini > number_check*(primes[sieve[number_check]]+1)){
				mini = number_check*(primes[sieve[number_check]]+1);
				candidate = number_check;
			}
		}
		else{
			for(int i=2;i*i<=number_check;++i){
				
				if(number_check%i!=0) continue;
				while(number_check%i==0) number_check/=i;

				while(checked[i*(primes[sieve[i]]+1)]) primes[sieve[i]]++;
				int x = primes[sieve[i]];
				if(mini > i*(x+1)){
					mini = i*(x+1);
					candidate = i;
				}
			}
			if(number_check!=1){
				int i = number_check;
				while(number_check%i==0) number_check/=i;

				while(checked[i*(primes[sieve[i]]+1)]) primes[sieve[i]]++;
				int x = primes[sieve[i]];
				if(mini > i*(x+1)){
					mini = i*(x+1);
					candidate = i;
				}
			}
			

		}
		sequence[sequence_id++]=mini;
		checked[mini]=1;
		primes[sieve[candidate]]++;
		current_prime = candidate;
	}
	//for(int i=0;i<300;++i) printf("%d\n", sequence[i]);


	for(int i=0;i<SIZE;++i)
		if(sequence[i] < SIZE) position[sequence[i]]=i+1;
	satori{
		int x;
		scanf("%d", &x);
		printf("%d\n", position[x]);
	}

	return 0;
}

