#include <stdio.h>
#include <limits.h>

#define SIZE 1000002

int trees[SIZE];

int bin_search(int first, int last, int val){ // [first, last]
    int found = 0;
    while(first<=last){
        int mid = (first+last)/2;
        if(trees[mid] > val){
            last = mid-1;
            found = mid;
        }
        else first = mid+1;
    }
    return found;
}

int main(){
    int z;
    scanf("%d",&z);
    trees[0]=0;
    int i;
    for(i=1; i<SIZE;++i) trees[i]=INT_MAX;

    while(z--){
        int i=0, k,val;
        scanf("%d", &k);
        for(i=1;i<=k;++i){
            scanf("%d", &val);
            trees[i]=trees[i-1]+val;
        }

        int q,a;
        scanf("%d", &q);
        while(q--){
            scanf("%d", &a);
            printf("%d\n",bin_search(0, SIZE-1, a)-1);

        }
    }
    return 0;
}