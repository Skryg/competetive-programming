#include <bits/stdc++.h>

using namespace std;

struct vp
{
    int next, prev;
    vp()
    {
        next=0;
        prev=0;
    }
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    vector<int> *v= new vector<int>[n];
    bool *first = new bool[n];
    int *a = new int[n];
    int *r = new int[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i]>>r[i];
        first[i] = true;
    }
    int zr,zl;
    for(int i=0;i<n;i++)
    {
        zr=i+1;
        zl=i-1;
        while(zr<n && a[zr]<=a[i]+r[i])
        {
            v[i].push_back(zr);
            first[zr] = false;
            zr++;
            
        }
        while(zl>=0 && a[zl]>=a[i]-r[i])
        {
            v[i].push_back(zl);
            first[zl] = false;
            zl--;
            
        }
    }
    


    delete[] first,v,a,r;
    
    
    return 0;
}