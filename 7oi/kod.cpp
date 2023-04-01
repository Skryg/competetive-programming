#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<ll> c(21);

struct stTr
{
    vector<int> t;
    int k{1};
    stTr(int i)
    {
        while(k<i)
        {
            k=k<<1;
        }
        t.resize(2*k);

    }
    int sum(int where, int first, int second, int x, int y)
    {
        if(x<= first && y>= second)
        {
            return t[where];
        }
        int mid = (first+second)/2;
        int ans{0};
        if(x<= mid) ans+= sum(2*where, first, mid, x,y);
        if(y> mid) ans+= sum(2*where+1,mid+1, second, x, y);
        return ans;
    }
    void refresh(int v)
    {
        if(v==0) return;
        t[v] = t[v*2]+t[2*v+1];
        refresh(v/2);
    }
    void set(int i, int val)
    {
        t[i+k]=val;
        refresh((i+k)/2);
    }
    int num(int i)
    {
        return t[i+k];
    }
};


ll find(stTr & tree, string & s, int mid ,int min, int max, ll value)
{
    int rsum=tree.sum(1,0,tree.k-1,mid,max);
    ll x=value/c[rsum];
    ll y = value %c[rsum];
    int lsum=tree.sum(1,0,tree.k-1, min,mid);
    if(lsum)
    {
        int mid2{0};
        for(int i=mid;i>=min;--i)
        {
            if(tree.num(i))
                mid2=i;
        }
        int it{0};
        for(int i=min; i<=mid;++i)
        {
            
            
            if(tree.num(i))
            {
                if(x>=c[it]*c[lsum-it-1]) 
                {
                    x -= c[it]*c[lsum-it-1];
                    for(int j=i+1;j<=mid;++j)
                    {
                        if(tree.num(j))
                        {
                            mid2=j;
                            break;
                        }
                            
                    }
                    
                    
                }
                else break;
                ++it;
                
            }
        }
        s += (char)(mid2+'a');
        tree.set(mid2,0);
        find(tree,s,mid2,min,mid,x);
    }
    if(rsum)
    {
        int mid2{0};
        for(int i=max;i>=mid;--i)
        {
            if(tree.num(i))
                mid2=i;
        }
        int it{0};
        for(int i=mid; i<=max;++i)
        {
            
            
            if(tree.num(i))
            {
                if(y>=c[it]*c[rsum-it-1]) 
                {
                    y -= c[it]*c[rsum-it-1];
                    for(int j=i+1;j<=max;++j)
                    {
                        if(tree.num(j))
                        {
                            mid2=j;
                            break;
                        }
                            
                    }
                }
                else break;
                ++it;
                
            }
        }
        s += (char)(mid2+'a');
        tree.set(mid2,0);
        find(tree,s,mid2,mid,max,y);
    }
    return x;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    c[0]=1;

    string st;
    for(int i=1;i<21;++i)
    {
        c[i]=c[i-1]*2*(2*(i-1)+1)/((i-1)+2);
    }
    ll k,n;
    cin>>n>>k;
    --n;
    stTr t = stTr(k);
    for(int i=0;i<k;++i)
    {
        t.set(i,1);
    }
    string ans="";
    int it{0};
    for(int i=0;i<k;++i)
    {
        if(n>=c[i]*c[k-i-1]) 
        {
            n -= c[i]*c[k-i-1];
            ++it;
        }
        else break;
    }
    ans += (char)(it+'a');
    t.set(it,0);
    find(t, ans, it, 0,k-1, n);
    cout<<ans;
    return 0;
}
