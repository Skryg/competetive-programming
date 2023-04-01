#include <bits/stdc++.h>

using namespace std;

int n=0,q=0,k=0;

struct treeElement{
    pair<int,int> numsStarts={-1,-1};
    pair<int,int> numsEnd = {-1,-1};
    bool xx=false,xy=false,yx=false,yy=false; 
};

vector<treeElement> tree;

void reloadTree(int i)
{
    i/=2;
    if(i != 0)
    {
        tree[i].numsStarts=tree[2*i].numsStarts;
        tree[i].numsEnd = tree[2*i+1].numsEnd;
        if(i>=k/2)
        {
            tree[i].xx= (tree[i].numsStarts.first <= tree[i].numsEnd.first);
            tree[i].xy = (tree[i].numsStarts.first <= tree[i].numsEnd.second);
            tree[i].yx  = (tree[i].numsStarts.second <= tree[i].numsEnd.first);
            tree[i].yy = (tree[i].numsStarts.second <= tree[i].numsEnd.second);     
        }
        else
        {
            tree[i].xx = ((tree[2*i].numsEnd.first <= tree[2*i+1].numsStarts.first && tree[2*i].xx&& tree[2*i+1].xx )||(tree[2*i].numsEnd.first<= tree[2*i+1].numsStarts.second&&tree[2*i].xx&&tree[2*i+1].yx)||(tree[2*i].numsEnd.second <= tree[2*i+1].numsStarts.first && tree[2*i].xy && tree[2*i+1].xx )||(tree[2*i].numsEnd.second <= tree[2*i+1].numsStarts.second && tree[2*i].xy && tree[2*i+1].yx));
            tree[i].xy = ((tree[2*i].numsEnd.first <= tree[2*i+1].numsStarts.first && tree[2*i].xx&& tree[2*i+1].xy )||(tree[2*i].numsEnd.first<= tree[2*i+1].numsStarts.second&&tree[2*i].xx&&tree[2*i+1].yy)||(tree[2*i].numsEnd.second <= tree[2*i+1].numsStarts.first && tree[2*i].xy && tree[2*i+1].xy )||(tree[2*i].numsEnd.second <= tree[2*i+1].numsStarts.second && tree[2*i].xy && tree[2*i+1].yy));
            tree[i].yx = ((tree[2*i].numsEnd.first <= tree[2*i+1].numsStarts.first && tree[2*i].yx&& tree[2*i+1].xx )||(tree[2*i].numsEnd.first<= tree[2*i+1].numsStarts.second&&tree[2*i].yx&&tree[2*i+1].yx)||(tree[2*i].numsEnd.second <= tree[2*i+1].numsStarts.first && tree[2*i].yy && tree[2*i+1].xx )||(tree[2*i].numsEnd.second <= tree[2*i+1].numsStarts.second && tree[2*i].yy && tree[2*i+1].yx));
            tree[i].yy = ((tree[2*i].numsEnd.first <= tree[2*i+1].numsStarts.first && tree[2*i].yx&& tree[2*i+1].xy )||(tree[2*i].numsEnd.first<= tree[2*i+1].numsStarts.second&&tree[2*i].yx&&tree[2*i+1].yy)||(tree[2*i].numsEnd.second <= tree[2*i+1].numsStarts.first && tree[2*i].yy && tree[2*i+1].xy )||(tree[2*i].numsEnd.second <= tree[2*i+1].numsStarts.second && tree[2*i].yy && tree[2*i+1].yy));
        }
        

        reloadTree(i);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    k=1;
    while(k<n)
    {
        k*=2;
    }
    for(int i=0;i<k*2;i++)
    {
        treeElement element;
        tree.push_back(element);
    }
    for(int i=k;i<n+k;i++)
    {
        int first, second;
        cin>>first>>second;
        tree[i].numsStarts={first,second};
        tree[i].numsEnd= {first,second};
        tree[i].xx=true;
        tree[i].xy=true;
        tree[i].yx=true;
        tree[i].yy=true;

    }
    for(int i=k+n; i<2*k;i++)
    {
        tree[i].numsStarts= {100000000,100000000};
        tree[i].numsEnd= {100000000,100000000};
        tree[i].xx=true;
        tree[i].xy = true;
        tree[i].yx=true;
        tree[i].yy=true;
    }

    for(int i=k-1;i>=k/2;i--)
    {
        tree[i].numsStarts=tree[2*i].numsStarts;
        tree[i].numsEnd = tree[2*i+1].numsEnd;
        tree[i].xx= (tree[i].numsStarts.first <= tree[i].numsEnd.first);
        tree[i].xy = (tree[i].numsStarts.first <= tree[i].numsEnd.second);
        tree[i].yx  = (tree[i].numsStarts.second <= tree[i].numsEnd.first);
        tree[i].yy = (tree[i].numsStarts.second <= tree[i].numsEnd.second);
    }

    for(int i=k/2-1;i>0;i--)
    {
        tree[i].numsStarts=tree[2*i].numsStarts;
        tree[i].numsEnd = tree[2*i+1].numsEnd;
        tree[i].xx = ((tree[2*i].numsEnd.first <= tree[2*i+1].numsStarts.first && tree[2*i].xx&& tree[2*i+1].xx )||(tree[2*i].numsEnd.first<= tree[2*i+1].numsStarts.second&&tree[2*i].xx&&tree[2*i+1].yx)||(tree[2*i].numsEnd.second <= tree[2*i+1].numsStarts.first && tree[2*i].xy && tree[2*i+1].xx )||(tree[2*i].numsEnd.second <= tree[2*i+1].numsStarts.second && tree[2*i].xy && tree[2*i+1].yx));
        tree[i].xy = ((tree[2*i].numsEnd.first <= tree[2*i+1].numsStarts.first && tree[2*i].xx&& tree[2*i+1].xy )||(tree[2*i].numsEnd.first<= tree[2*i+1].numsStarts.second&&tree[2*i].xx&&tree[2*i+1].yy)||(tree[2*i].numsEnd.second <= tree[2*i+1].numsStarts.first && tree[2*i].xy && tree[2*i+1].xy )||(tree[2*i].numsEnd.second <= tree[2*i+1].numsStarts.second && tree[2*i].xy && tree[2*i+1].yy));
        tree[i].yx = ((tree[2*i].numsEnd.first <= tree[2*i+1].numsStarts.first && tree[2*i].yx&& tree[2*i+1].xx )||(tree[2*i].numsEnd.first<= tree[2*i+1].numsStarts.second&&tree[2*i].yx&&tree[2*i+1].yx)||(tree[2*i].numsEnd.second <= tree[2*i+1].numsStarts.first && tree[2*i].yy && tree[2*i+1].xx )||(tree[2*i].numsEnd.second <= tree[2*i+1].numsStarts.second && tree[2*i].yy && tree[2*i+1].yx));
        tree[i].yy = ((tree[2*i].numsEnd.first <= tree[2*i+1].numsStarts.first && tree[2*i].yx&& tree[2*i+1].xy )||(tree[2*i].numsEnd.first<= tree[2*i+1].numsStarts.second&&tree[2*i].yx&&tree[2*i+1].yy)||(tree[2*i].numsEnd.second <= tree[2*i+1].numsStarts.first && tree[2*i].yy && tree[2*i+1].xy )||(tree[2*i].numsEnd.second <= tree[2*i+1].numsStarts.second && tree[2*i].yy && tree[2*i+1].yy));

    }
    cin>>q;

    for(int i=0;i<q;i++)
    {
        int first, second;
        cin>>first>>second;
        swap(tree[first-1+k], tree[second-1+k]);

        reloadTree(first-1+k);
        reloadTree(second-1+k);
        if(tree[1].xx || tree[1].xy || tree[1].yx|| tree[1].yy)
            cout<< "TAK\n";
        else cout << "NIE\n";
    }

    return 0;
}