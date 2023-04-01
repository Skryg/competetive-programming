#include <stdio.h>
#include <stdlib.h>

#define satori int z; scanf("%d", &z); while(z--)
#define SIZE 1000001

struct Elem{
    int id, val;
};

int cmp(const void *p1, const void *p2){
    int val1 = ((struct Elem *)p1)->val;
    int val2 = ((struct Elem *)p2)->val;
    if(val2!=val1) return val1 - val2;

    int id1 = ((struct Elem *)p1)->id;
    int id2 = ((struct Elem *)p2)->id;
    return id1 - id2;
}

int main(){
    
    satori{
        int m;
        scanf("%d", &m);

        struct Elem *tab= malloc(sizeof(struct Elem)*m);
        for(int i=0;i<m;++i){
            struct Elem *point = tab+i;
            scanf("%d", &point->val);
            point->id = i;
        }
        qsort(tab, m, sizeof(struct Elem), cmp);

        int n; scanf("%d", &n);
        
        for(int i=0;i<n;++i){
            int m1; scanf("%d", &m1);
            int ok = 1;
            if(m1 > m) ok=0;
            int pos = -1;
            for(int j=0;j<m1;++j){
                int inp; scanf("%d", &inp);
                int candidate=-1;
                int first=0, last = m-1;
                while(first<=last){
                    int mid=(first+last)/2;
                    struct Elem *point = tab+mid;
                    //printf("POINT VAL %d ID %d\n",point->val, point->id);
                    
                    if((*point).val > inp) last = mid-1;
                    else if((*point).val < inp) first = mid+1;
                    else{
                        if(pos < (*point).id){ //git
                            candidate = (*point).id;
                            last = mid-1;
                        } 
                        else{
                            first = mid+1;
                        }
                    }
                }
                if(candidate != -1){
                    pos = candidate;
                    //printf("%d ", pos);
                }
                else ok=0;
            }
            printf((ok ? "TAK\n" : "NIE\n"));
        }
        
        free(tab); 
    }
    return 0;
}