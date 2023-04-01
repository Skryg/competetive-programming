//Oskar Krygier
#include <bits/stdc++.h>

using namespace std;

int n,X,z;



vector<int> onBeach;
vector<int> distances;
int maxK=0;
struct query{
    int id=-1,amount=0; pair<int,int> value={0,0};
    query(){}
};
vector<query> queries;
bool sortByAm(query q1,query q2){return q1.amount<q2.amount;}
bool sortById(query q1,query q2){return q1.id<q2.id;}

void loadData()
{
    cin>>n>>X>>z;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        
        onBeach.push_back(x);
    }
    for(int i=1;i<n;i++)
    {
        distances.push_back(onBeach[i]-onBeach[i-1]);
    }
   
    for(int i=0;i<z;i++)
    {
        query x;
        cin>>x.amount;
        x.id = i;
        maxK= max(maxK,x.amount);
        queries.push_back(x);
    }

}

struct diva
{
    pair<int,int> cm;
    int dividedBy=1;
    int iteration=1;
    int valA, valB;
    diva(){}
};
queue<diva> que;

float equealValue(int valueA,int valueB)
{
    return (float)valueA/(float)valueB;
}



struct vertex
{
    int id=0, valueA=0, valueB=1,count =0;
    int vA=-1,vB=-1;

    vertex(){}
};

struct tree
{
    vector<vertex> t;
    int valuesInTree=0;
    void refreshV(int v)
    {
        if(v==0)
            return;
        if(equealValue(t[2*v].valueA,t[2*v].valueB)>equealValue(t[2*v+1].valueA,t[2*v+1].valueB))
        {
            t[v]=t[2*v];
            
        }
        else t[v] = t[2*v+1];

        refreshV(v/2);
    }

    tree()
    {
        int k=1;
        while(k<distances.size())
        {
            k*=2;
        }
        for(int i=0;i<2*k;i++)
        {
            vertex v;
            t.push_back(v);
        }
        valuesInTree = distances.size();
        for(int i=0;i<distances.size();i++)
        {
            t[k+i].valueA = distances[i];
            t[k+i].valueB = 1;
            t[k+i].id = i;
            t[k+i].count =1;
            t[k+i].vA = onBeach[i];
            t[k+i].vB = onBeach[i+1];
        }
        for(int i=k-1;i>=1;i--)
        {
            if(equealValue(t[2*i].valueA,t[2*i].valueB)>equealValue(t[2*i+1].valueA,t[2*i+1].valueB))
            {
                t[i]=t[2*i];
                
            }
            else t[i] = t[2*i+1];
        }
    }
    void forwardValue(int id)
    {
        
        int k=t.size()/2;

        diva d;
        d.cm = {t[id+k].vA,t[id+k].vB};
        t[id+k].valueB*=2;
        int g = __gcd(t[id+k].valueA,t[id+k].valueB);
        t[id+k].valueA/=g;
        t[id+k].valueB/=g;
        d.dividedBy = 2;
        d.iteration =1;
        d.valA = t[id+k].valueA;
        d.valB = t[id+k].valueB;
        
        que.push(d);
        t[id+k].count=0;
        t[id+k].valueB=1;
        t[id+k].valueA=0;
        refreshV((id+k)/2);
    }

    vertex maxVal()
    {
        return t[1];
    }

};
tree tr;
void prepareTree()
{
    tr = tree();

}

pair<int,int> valueOfFirstQue()
{
    return {que.front().valA,que.front().valB};
}

pair<int,int> takeOneFromQue()
{
    int a = que.front().valA;
    int b = que.front().valB;

    que.front().valA*=2;
    que.front().valB*=2;
    b *=2;
    
    a+= (que.front().valA*que.front().iteration);
    
    int g= __gcd(a,b);
    a/=g;
    b/=g;

    ++que.front().iteration;
    if(que.front().iteration == que.front().dividedBy)
    {
        diva d;
        d=que.front();
        d.iteration=0;
        d.valB*=2;
        d.dividedBy*=2;
        que.pop();
        que.push(d);
    }
    return {a,b};
}

int main()
{
    ios_base::sync_with_stdio();
    cin.tie(0);
    loadData();
    prepareTree();
    sort(queries.begin(),queries.end(),sortByAm);
    int it=1;
    int queryIt=0;
    while(it <= maxK)
    {
        if(que.empty()||equealValue(tr.maxVal().valueA,tr.maxVal().valueB)>=equealValue(valueOfFirstQue().first,valueOfFirstQue().second))
        {
            int a = tr.maxVal().valueA;
            int b = tr.maxVal().valueB;
            int g = __gcd(a,b);
            a/=g;
            b/=g;
            a+=tr.maxVal().vA*b;
            if(it==queries[queryIt].amount)
            {
                queries[queryIt].value = {a,b};
                ++queryIt;
            }
            tr.forwardValue(tr.maxVal().id);
            
        }
        else
        {
           pair<int,int> p =  takeOneFromQue();
           if(it==queries[queryIt].amount)
            {
                queries[queryIt].value = p;
                ++queryIt;
            }
        }
        ++it;
    }
    sort(queries.begin(),queries.end(),sortById);
    for(int i=0;i<queries.size();i++)
    {
        cout<<queries[i].value.first<<'/'<<queries[i].value.second<<"\n";
    }
    return 0;
}