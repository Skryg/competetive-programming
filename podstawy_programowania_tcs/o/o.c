#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define satori int z; scanf("%d", &z); while(z--)

struct Hobbit{
    int x,y;
    char name[11];
};

int cmp(const void *p1, const void *p2){
    return ((struct Hobbit *)p1)->x - ((struct Hobbit *)p2)->x; 
}

int main(){
    satori{
        int n; scanf("%d", &n);
        struct Hobbit *hobbits = malloc(sizeof(struct Hobbit)*n);
        for(int i=0;i<n;++i){
            scanf("%d %d %s", &hobbits[i].x, &hobbits[i].y, hobbits[i].name);
        }
        qsort(hobbits, n, sizeof(struct Hobbit), cmp);
        //for(int i=0;i<n;++i) printf("%d %d %s\n",hobbits[i].x, hobbits[i].y, hobbits[i].name);
        int cand1, cand2;
        int pos1=0, pos2;
        int best = INT_MAX;
        int last_x=hobbits[0].x, last_y=abs(hobbits[0].y);

        for(int i=1;i<n;++i){
            int x = hobbits[i].x;
            int y = abs(hobbits[i].y);
            int dist = x-last_x;
            if(dist+last_y+y < best){
                best = dist+last_y+y;
                pos2=i;
                cand1 = pos1;
                cand2 = pos2;
            }
            if(dist+last_y > y){
                pos1=i;
                last_x = x;
                last_y = y;
            }
                        
        }

        printf("%d\n%s %s\n", hobbits[cand2].x-hobbits[cand1].x+abs(hobbits[cand1].y)+abs(hobbits[cand2].y), 
            hobbits[cand1].name,hobbits[cand2].name);

        free(hobbits);
    }   

    return 0;
}