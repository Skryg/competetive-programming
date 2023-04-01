#include <bits/stdc++.h>

using namespace std;

int main(){
	int *tab = new int[1'000'000'00];
	int var=0;
	while(clock() <= 2 * CLOCKS_PER_SEC){
		for(int i=0;i<1'000'000'00; ++i){
			tab[i]=var;
		}
		var++;
	}
	cout<<tab[0];
	
	delete [] tab;

	return 0;
}
