#include <stdio.h>

int main(){
	unsigned long long x = 1;
	printf("%llu\n",x<<63);
	printf("%lld",-(long long)(x<<63));
	return 0;
}
