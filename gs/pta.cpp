#include <bits/stdc++.h>

using namespace std;

int n,q;
vector<int> trees;
vector<int> birds;

struct tr
{
    int height=0, cost=0;
};

list<tr> a,b;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin>> n;
    for(int i=0;i<n;i++)
    {
        int d;
        cin >>d;
        trees.push_back(d);
    }
    for(int i=0;i<q;i++)
    {
        int c;
        cin>>c;
        birds.push_back(c);
    }

    

    return 0;
}