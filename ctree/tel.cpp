#include <bits/stdc++.h>

using namespace std;


int n, m;

struct vertex
{
    long long sum=0, lazyA=0,lazyS=0;
    int first=0, last=0;
    vertex()
    {

    }
};

struct tree
{
    vector<vertex> t;

    tree(){}
    int k= 1;
    tree(int i)
    {
        

        while(k<i)
        {
            k*=2;
        }
        t.resize(2*k);
        for(int i=k;i<t.size();i++)
        {
            t[i].first = (i-k+1);
            t[i].last = (i-k+1);
        }
        for(int i=k-1;i>=0;i--)
        {
            t[i].first = t[2*i].first;
            t[i].last = t[2*i+1].last;
        }

    }
    void insert(int v, long long a, long long s, int x,int y)
    {
        if(t[v].first>=x && t[v].last <=y)
        {
            t[v].lazyA +=a;
            t[v].lazyS+=(s+(t[v].first-x)*a);
            int d = (t[v].last-t[v].first+1);
            t[v].sum += (a*(d-1)*d/2 + d*(s+(t[v].first-x)*a)) ;
            return;
        }
        if(v<k)
        {
            push(v);
            if((t[v].first <=y && t[v].last >=y) || (x >= t[v].first && t[v].last >= x))
            {
                insert(2*v,a,s,x,y);
                insert(2*v+1,a,s,x,y);
            }
            int d = (t[v].last-t[v].first+1);
            t[v].sum = t[v*2].sum + t[v*2+1].sum + t[v].lazyS + (t[v].lazyA*(d-1)*d/2 + d*t[v].lazyS);
        }   

        
    }
    void push(int v)
    {
        t[v*2].lazyA+=t[v].lazyA;
        t[v*2].lazyS+=t[v].lazyS;
        int d = (t[v*2].last-t[v*2].first+1);
        t[v*2].sum += (t[v].lazyA*(d-1)*d/2 + d*t[v].lazyS);

        t[v*2+1].lazyA += t[v].lazyA;
        t[v*2+1].lazyS += (t[v].lazyS + (t[v*2+1].first-t[v].first)*t[v].lazyA);
        d=(t[v*2+1].last-t[v*2+1].first+1);
        t[v*2+1].sum += (t[v].lazyA*(d-1)*d/2 + d*(t[v].lazyS + (t[v*2+1].first-t[v].first)*t[v].lazyA));

        t[v].lazyA=0;
        t[v].lazyS=0;

    }
    long long query(int v, int x, int y)
    {
        if(x<= t[v].first && y>=t[v].last)
            return t[v].sum;
        push(v);
        long long s=0;
        int mid = (t[v].last + t[v].first)/2;
        if(x<= mid && y>=t[v].first) s += query(2*v,x,y);
        if(y>mid && x<=t[v].last) s+= query(2*v+1,x,y);
        int d = (t[v].last-t[v].first+1);
        t[v].sum = t[v*2].sum + t[v*2+1].sum + t[v].lazyS + (t[v].lazyA*(d-1)*d/2 + d*t[v].lazyS);
        return s;
    }


    
};
tree tr;
vector<pair<int,int>> tel;

void add(int x, long long s, long long a)
{
    if(a>s)
        a=s;
    tel[x].first=s;
    tel[x].second = a;

    int g =s/a;
    int l = s%a;
    int bonus =0;
    int start = x-g;
    if(start<1)
    {
        bonus = abs(-start)+1;
        start = 1;
    } 
    tr.insert(1,a,l+bonus*a,start,x);

    start = x+1;
    int last;
    if(x+1<=n)
    {
        l=s-a;
        
        g=l/a;
        last = start+g;
        if(last>n)
            last = n;
        tr.insert(1,-a,l,start,last);
    }
}

void del(int x)
{
    int s = tel[x].first, a = tel[x].second;

    tel[x]={0,0};

    int g =s/a;
    int l = s%a;
    int bonus =0;
    int start = x-g;
    if(start<1)
    {
        bonus = abs(-start)+1;
        start = 1;
    } 
    tr.insert(1,-a,-l-bonus*a,start,x);

    start = x+1;
    int last;
    if(x+1<=n)
    {
        l=s-a;
        
        g=l/a;
        last = start+g;
        if(last>n)
            last = n;
        tr.insert(1,a,-l,start,last);
    }

}

long long query(long long x1, long long x2)
{
    long long s=tr.query(1,x1,x2);
    long long b = (x2-x1+1);
    s/=b;
    return s;
}

void loadData()
{
    cin>>n>>m;
    
}

void queries()
{
    for(int i=0;i<m;i++)
    {
        char type;
        int id, arg1, arg2;
        cin>>type;
        switch(type)
        {
            case 'P':
                cin>>id>>arg1>>arg2;
                add(id, arg1, arg2);
                break;
            case 'U':
                cin>>id;
                del(id);
                break;
            case 'Z':
                cin>>arg1>>arg2;
                cout<<query(arg1,arg2)<<"\n";
                break;
                
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    loadData();
    tel.resize(n+1,{0,0});
    tr = tree(n);
    queries();
    return 0;
}