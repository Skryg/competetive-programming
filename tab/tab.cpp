#include <iostream>
#include <vector>

using namespace std;

struct tab_element
{
    int x;
    int y;
    bool isOne=false;

    tab_element(int a, int b, bool i)
    {
        x=a;
        y=b;
        isOne=i;
    }
    tab_element()
    {
        x=-1;
        y=-1;
        isOne=false;
    }
    int priority()
    {
        return x+y;
    }
};

class Prior
{
    
    vector<tab_element> tab;
    
    tab_element del()
    {
        tab_element t=tab[0];
        tab[0]=tab.back();
        tab.pop_back();
        rePrior(1);
        return t;
    }
    void rePrior(int i)
    {
        int left = 2*i;
        int right=2*i+1;
        int max=i;
        if(left<=tab.size()&& tab[left-1].priority()> tab[max-1].priority())
            max=left;
        if(right<=tab.size()&& tab[right-1].priority() > tab[max-1].priority())
            max = right;
        if(max>i)
        {
            swap(tab[i-1],tab[max-1]);
            rePrior(max);
        }
    }
    void build()
    {
        for(int i=tab.size()/2; i>=1; i--)
        {
            rePrior(i);
        }
    }
    public :
        Prior(vector<tab_element> t)
        {
            tab = t;
            build();
        }
        int times()
        {
            int toReturn=0;
            while(!tab.empty())
            {
                tab_element d = del();
                if(d.isOne)
                {
                    toReturn++;
                    for(int i=0;i<tab.size();i++)
                    {
                        if(tab[i].x<=d.x && tab[i].y <=d.y)
                            tab[i].isOne = !tab[i].isOne;
                    }   
                }

            }
            return toReturn;
        } 
};
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n,m,q;
    cin>>n>>m>>q;
    vector<tab_element> tab;
    bool points[4][2];
    int ** qs= new int*[q];
    for(int i=0; i<q;i++)
        qs[i]=new int[4];
    int *answers=new int[q];
    for(int i=0; i<q; i++)
    {
        for(int j=0;j<4;j++)
        {
            points[j][0]=true;
            points[j][1]=false;
        }
        int a,b,c,d;
        cin >>a>>b>>c>>d;
        qs[i][0]=a;
        qs[i][1]=b;
        qs[i][2]=c;
        qs[i][3]=d;
        if(a-1==0)
        {
            points[0][0]=false;
            points[1][0]=false;
        }
        if(b-1==0)
        {
            points[0][0]=false;
            points[2][0]= false;
        }
        for(int j=0;j<tab.size();j++)
        {
            if(tab[j].x>=a &&tab[j].x<=c && tab[j].y>=b && tab[j].y<=d)
                tab[j].isOne = !tab[j].isOne;
            if(points[0][0]&&tab[j].x==a-1&&tab[j].y==b-1) points[0][0]=false;
            else if(points[1][0]&&tab[j].x==a-1&&tab[j].y==d) points[1][0]=false;
            else if(points[2][0]&&tab[j].x==c&&tab[j].y==b-1) points[2][0]=false;
            else if(points[3][0]&&tab[j].x==c&&tab[j].y==d) points[3][0]=false;
        }
        if(points[0][0]||points[1][0]||points[2][0]||points[3][0])
        {
            for(int j=0;j<i;j++)
            {
                if(points[0][0] && qs[j][0]<=a-1 && qs[j][2]>=a-1 && qs[j][1]<=b-1 && qs[j][3]>= b-1) points[0][1]=!points[0][1];
                if(points[1][0] && qs[j][0]<=a-1 && qs[j][2]>=a-1 && qs[j][1]<=d && qs[j][3]>=d) points[1][1]=!points[1][1];
                if(points[2][0] && qs[j][0]<=c && qs[j][2]>=c && qs[j][1]<=b-1 && qs[j][3]>= b-1) points[2][1]=!points[2][1];
                if(points[3][0] && qs[j][0]<=c && qs[j][2]>=c && qs[j][1]<=d && qs[j][3]>= d) points[3][1]=!points[3][1];
            }
        }
        if(points[0][0]) tab.push_back(tab_element(a-1,b-1,points[0][1]));
        if(points[1][0]) tab.push_back(tab_element(a-1,d,points[1][1]));
        if(points[2][0]) tab.push_back(tab_element(c,b-1,points[2][1]));
        if(points[3][0]) tab.push_back(tab_element(c,d,!points[3][1]));

        Prior *p = new Prior(tab);       
        answers[i]=p->times();
        delete p;
    }
    
    for(int i=0; i<q;i++)
    {
        delete[] qs[i];
        cout<<answers[i]<<"\n";
    }
        
    delete[] qs;
    delete[] answers;
    return 0;
}