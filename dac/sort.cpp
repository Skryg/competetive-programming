#include <bits/stdc++.h>

using namespace std;

void merge(int first, int middle, int end, int *tab, int *help)
{
    for(int i=first; i<=end;i++)
    {
        help[i]=tab[i];
    }
    int a = first, b = middle+1, i = first;

    while(a<=middle && b<=end)
    {
        if(help[a]<=help[b])
        {
            tab[i] = help[a];
            a++;
            i++;
        }
        else
        {
            tab[i] = help[b];
            b++;
            i++;
        }
    }
    while(a<=middle)
    {
        tab[i] = help[a];
        i++;
        a++;
    }
    while(b<=end)
    {
        tab[i] = help[b];
        i++;
        b++;
    }
}

void mergesort(int *tab, int *help, int first, int end)
{
    if(first>=end) return;
    int mid = (first+end)/2;
    mergesort(tab,help,first,mid);
    mergesort(tab,help,mid+1,end);
    merge(first, mid, end, tab, help);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin>>n;
    int tab[n], help[n];

    for(int i=0;i<n;i++)
    {
        cin>> tab[i];
    }
    mergesort(tab, help, 0, n-1);
    for(int i=0;i<n;i++)
    {
        cout<<tab[i]<<" ";
    }
    return 0;
}