#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define satori int z; scanf("%d", &z); while(z--)

struct point{
    int x,y;
};

struct person{
    char name[16];
    int salary;
};

void* load1(int n){
    int* tab = malloc(sizeof(int)*n);
    for(int i=0;i<n;++i) scanf("%d", &tab[i]);
    return tab;
}
void* load2(int n){
    struct point* tab = malloc(sizeof(struct point)*n);
    for(int i=0;i<n;++i) scanf("%d %d", &tab[i].x, &tab[i].y);
    return tab;
}
void* load3(int n){
    struct person* tab = malloc(sizeof(struct person)*n);
    for(int i=0;i<n;++i) scanf("%s %d", tab[i].name, &tab[i].salary);
    return tab;
}

void output1(int n, void* pointer){
    int* point = pointer;
    printf("%d", point[0]);
    for(int i=1;i<n;++i){
        printf(", %d", point[i]);
    }
    printf("\n");
}
void output2(int n, void* pointer){
    struct point* point1 = pointer;
    printf("%d %d", point1[0].x, point1[0].y);
    for(int i=1;i<n;++i){
        printf(", %d %d", point1[i].x, point1[i].y);
    }
    printf("\n");
}
void output3(int n, void* pointer){
    struct person *point1 = pointer;
    printf("%s %d", point1[0].name, point1[0].salary);
    for(int i=1;i<n;++i){
        printf(", %s %d", point1[i].name, point1[i].salary);
    }
    printf("\n");
}

int cmp0(  void* p1,   void* p2){
    int x1 = *(int*)p1, x2 = *(int*)p2;
    return x1<=x2;
}

int cmp1(void* p1, void* p2){
    int x1 = *(int*)p1, x2 = *(int*)p2;
    return x1>=x2;
}

int cmp2(void* p1, void* p2){
    int x1 = *(int*)p1, x2 = *(int*)p2;
    if(abs(x1) == abs(x2)) return x1<=x2;
    return abs(x1)<=abs(x2);
}

int cmp3(void* p1, void* p2){
    int x1 = *(int*)p1, x2 = *(int*)p2;
    if(abs(x1) == abs(x2)) return x1>=x2;
    return abs(x1)>=abs(x2);
}

int cmp4(void* p1, void* p2){
    struct point x1 = *(struct point*)p1, x2 = *(struct point*)p2;
    if(x1.x == x2.x) return x1.y <= x2.y;
    return x1.x <= x2.x;
}

int cmp5(void* p1, void* p2){
    struct point x1 = *(struct point*)p1, x2 = *(struct point*)p2;
    if(x1.x == x2.x) return x1.y >= x2.y;
    return x1.x >= x2.x;
}
int cmp6(void* p1, void* p2){
    struct point x1 = *(struct point*)p1, x2 = *(struct point*)p2;
    if(x1.y == x2.y) return x1.x <= x2.x;
    return x1.y <= x2.y;
}
int cmp7(void* p1, void* p2){
    struct point x1 = *(struct point*)p1, x2 = *(struct point*)p2;
    if(x1.y == x2.y) return x1.x >= x2.x;
    return x1.y >= x2.y;
}

int cmp8(void* p1, void* p2){
    struct person x1 = *(struct person*)p1, x2 = *(struct person*)p2;
    if(x1.salary == x2.salary) return strcmp(x1.name, x2.name)<=0;
    return x1.salary <= x2.salary;
}

int cmp9(void* p1, void* p2){
    struct person x1 = *(struct person*)p1, x2 = *(struct person*)p2;
    if(x1.salary == x2.salary) return strcmp(x1.name, x2.name)>=0;
    return x1.salary >= x2.salary;
}

void swap(void *a, void *b){
    char *x1 = a, *x2 = b; 
    char p = *x1;
    *x1 = *x2;
    *x2 = p;
}

void sort( void *tab, int n, int size, int (*cmp) (void*, void*) ){
    for(int i=0;i<n;++i){
        for(int j=i; j>0; --j){
            int pos1=(j-1)*size, pos2 =j*size;
            if(!cmp(tab+pos1,tab+pos2)){
                for(int k=0;k<size;++k){
                    swap(tab+pos1+k, tab+pos2+k);
                }
            }
        }
    }
}

int main(){
    void* (*load[3])(int) = {load1, load2, load3};
    void (*output[3])(int, void*) = {output1, output2, output3};
    int size[3] = {sizeof(int), sizeof(struct point), sizeof(struct person)};
    int (*cmp[10])(void*, void*) = {cmp0,cmp1,cmp2,cmp3,cmp4,cmp5,cmp6,cmp7,cmp8,cmp9};
    satori{
        int n,d; scanf("%d %d", &n, &d);
        void* tab = load[d/4](n);
        sort(tab, n, size[d/4], cmp[d]);

        output[d/4](n, tab);
        free(tab);
    }

    return 0;
}