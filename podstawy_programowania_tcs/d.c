#include <stdio.h>
#define satori int z; scanf("%d", &z ); while(z--)

const __int128 ten_ten = 10000000000LL;

int main(){
    satori{
        int d;
        __int128 first = 1*ten_ten, last = 220*ten_ten;
        __int128 k = (first+last)/2;

        scanf("%d", &d);
        __int128 a = (d*ten_ten)*ten_ten*ten_ten;
        int precision = 128;
        __int128 num = k*(k*(k-ten_ten)+ten_ten*ten_ten);
        while(precision--){
            num = k*(k*(k-ten_ten)+ten_ten*ten_ten);
            if(num > a){
                last = k-1;
                k = (first + last)/2;
            }
            if(num < a){
                first = k+1;
                k = (first + last)/2;
            }
            if(num == a){
                break;
            }
        }
        __int128 floor = k/ten_ten;
        __int128 ceil;
        if(floor*ten_ten < k) ceil = floor+1;
        else ceil = floor;
        printf("%0.10Lf %d %d\n", (long double)k/ten_ten, (int)floor, (int)ceil);

    }
    return 0;   
}