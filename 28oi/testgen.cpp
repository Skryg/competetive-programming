#include <iostream>
#include <random>

using namespace std;

int r(int x, int y) {
    return rand()%(y-x+1)+x; }

int main()
{
    srand(time(NULL));
    for(int i=0;i<10;i++) rand();
    int n = r(1,1000);
    cout<<n<<"\n";
 
    return 0;
}