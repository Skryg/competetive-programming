#include <stdio.h>
#include <stdlib.h>

typedef long long int ll;

ll a,b;
ll p=1;
ll mnozenie(ll a,ll b);
int main()
{
    printf("Podaj podstawe potegi:\n");
    scanf("%lld",&a);
    printf("Podaj wykladnik potegi\n");
    scanf("%lld",&b);
    if(b==1)
        p=a;
    else if(b==0)
        p=1;

    else
    {
        for(int i=0;i<b;i++)
        {
            p=mnozenie(p,a);
        }
    }
    printf("%lld",p);
    return 0;
}

ll mnozenie(ll a, ll b)
{
    ll s=0;
    for(int i=0; i<b;i++)
        s=s+a;
    return s;
}