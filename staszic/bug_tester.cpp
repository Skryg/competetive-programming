#include <bits/stdc++.h>

using namespace std;

void base(){
    cout<<"7 3\n7 4\n3 6\n7 8\n4 1\n3 5\n5 10\n3 9\n3 2\n";
}

void add(int i){
    printf("%d 3\n%d 11\n%d 9\n%d 8\n%d 7\n%d 6\n%d 1\n",i+1,i+2,i+3,i+4,i+5,i+6,i+7);
}

int main(){
    int n;
    cin>>n;
    int b{10};
   
    switch(n){
        case 0:
            cout<<"10\n";
            base();
            break;
        case 1:
            while(b<20){b+=7;}
            cout<<b<<"\n";
            base();
            b=10;
            while(b<20){add(b);b+=7;}
            break;

        case 2:
            while(b<150){b+=7;}
            cout<<b<<"\n";
            base();
            b=10;
            while(b<150){add(b);b+=7;}
            break;
        case 3:
            while(b<1000){b+=7;}
            cout<<b<<"\n";
            base();
            b=10;
            while(b<1000){add(b);b+=7;}
            break;

           
        
        case 4:
            while(b<500000){b+=7;}
            cout<<b<<"\n";
            base();
            b=10;
            while(b<500000){add(b);b+=7;}
            break;
        
    }
    
    return 0;
}