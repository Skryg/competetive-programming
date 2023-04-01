#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

struct listEl
{
    long long int next;
    int moves;
    listEl(long long int n, int m)
    {
        next = n;
        moves = m;
    }
    listEl()
    {
        next=-2;
        moves=-2;
    }
};

struct graphEl
{
    long long int id;
    long long int posit;
    graphEl(long long int i, long long int p)
    {
        id=i;
        posit=p;
    }
};



int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, X, z;
    cin>>n>>X>>z;
 
    vector<graphEl> *holes = new vector<graphEl>[n+1];
    //vector<graphEl> holes[n+1];
    long long int id=n+1;

    for(int i=1; i<=n; i++)
    {

        int hm;
        cin>>hm;
        for(int j=0; j<hm;j++)
        {
            int h;
            cin>>h;
            graphEl g = graphEl(id,h);
            holes[i].push_back(g);
            id++;
        }
    }

    vector<listEl> *graph = new vector<listEl>[id];
    //    vector<listEl> graph[id];

    if(holes[1].size()>0)
        graph[1].push_back(listEl(holes[1].at(0).id,0));
    for(int i=2;i<=n;i++)
    {
        if(holes[i-1].size()>0 && ((holes[i].size()>0 &&holes[i-1].at(0).posit < holes[i].at(0).posit)||(holes[i].size()==0)))
            graph[i].push_back(listEl(holes[i-1].at(0).id,0));
        if(holes[i].size()>0)
            graph[i].push_back(listEl(holes[i].at(0).id,0));
        else graph[i].push_back(listEl(0,0));
        
    }
    //tworzenie grafu
    for(int i=0;i<holes[1].size();i++)
    {
        int adding=1;

        if(n>1)
        {
            int st = 0, en = holes[2].size()-1, sol=-1,sr = 0;
            
            while(st<=en)
            {
                sr=(st+en)/2;
                if(holes[2].at(sr).posit>holes[1].at(i).posit)
                {
                    en = sr-1;
                    sol = sr;
                }
                else st = sr+1;
            }
            
            if(sol!=-1)
            {
                graph[holes[1].at(i).id].push_back(listEl(holes[2].at(sol).id,0));
                if(i+1<holes[1].size() && holes[2].at(sol).posit > holes[1].at(i+1).posit)
                    adding=0;

            }
            else graph[holes[1].at(i).id].push_back(listEl(0,0));

        }

        if(i+1<holes[1].size())
        {
            graph[holes[1].at(i).id].push_back(listEl(holes[1].at(i+1).id,adding));
        }
        else
            graph[holes[1].at(i).id].push_back(listEl(0,1));

        
    }

    if(n>1)
    {
        for(int i=0;i<holes[n].size();i++)
        {
            if(i+1<holes[n].size())
            {
                graph[holes[n].at(i).id].push_back(listEl(holes[n].at(i+1).id,1));
            }
            else
                graph[holes[n].at(i).id].push_back(listEl(0,1));

            if(n>1)
            {
                int st = 0, en = holes[n-1].size()-1, sol=-1,sr = 0;
               
                while(st<=en)
                {
                    sr=(st+en)/2;
                    if(holes[n-1].at(sr).posit>holes[n].at(i).posit)
                    {
                        en = sr-1;
                        sol = sr;
                    }
                    else st = sr+1;
                }

                if(sol!=-1&&i+1<holes[n].size()&&holes[n-1].at(sol).posit<holes[n].at(i+1).posit)
                    graph[holes[n].at(i).id].push_back(listEl(holes[n-1].at(sol).id,1));
            }
        }
    }
    
    for(int j=2; j<n; j++)
    {
        for(int i=0; i<holes[j].size();i++)
        {
            int adding=1;

        
            int st = 0, en = holes[j+1].size()-1, sol=-1,sr = 0;
            
            while(st<=en)
            {
                sr=(st+en)/2;
                if(holes[j+1].at(sr).posit>holes[j].at(i).posit)
                {
                    en = sr-1;
                    sol = sr;
                }
                else st = sr+1;
            }
            
            if(sol!=-1)
            {
                graph[holes[j].at(i).id].push_back(listEl(holes[j+1].at(sol).id,0));
                if(i+1<holes[j].size() && holes[j+1].at(sol).posit > holes[j].at(i+1).posit)
                    adding=0;

            }
            else graph[holes[j].at(i).id].push_back(listEl(0,0));

            

            if(i+1<holes[j].size())
            {
                graph[holes[j].at(i).id].push_back(listEl(holes[j].at(i+1).id,adding));
            }
            else
                graph[holes[j].at(i).id].push_back(listEl(0,1));

            st = 0; en = holes[j-1].size()-1; sol=-1;sr = 0;
               
                while(st<=en)
                {
                    sr=(st+en)/2;
                    if(holes[j-1].at(sr).posit>holes[j].at(i).posit)
                    {
                        en = sr-1;
                        sol = sr;
                    }
                    else st = sr+1;
                }

                if(sol!=-1&&i+1<holes[j].size()&&holes[j-1].at(sol).posit<holes[j].at(i+1).posit)
                    graph[holes[j].at(i).id].push_back(listEl(holes[j-1].at(sol).id,1));

        
        }
    }
    for(int i=1;i<=n;i++)
    {
        if(graph[i].size()==0)
        {
            graph[i].push_back(listEl(0,0));
        }
    }

    long long int * it= new long long int[id];
    //long long int it[id];
    for(long long int i=0;i<id;i++){ 
        it[i]=0; 
        }
    for(long long int i=1;i<id;i++)
    {

        for(int j=0; j<graph[i].size();j++)
        {
            it[graph[i].at(j).next]++;
        }
    }


    //sortowanie topologiczne
    long long int *listSorted = new long long int[id];
    //long long int listSorted[id];
    int end = n;
    int first = 0;
    
    for(int i=0;i<n;i++) { listSorted[i]=i+1;}
    for(long long int i=1; i<=id;i++)
    {
        long long int akt = listSorted[first];
        first++;
        for(int j=0; j< graph[akt].size();j++)
        {
            it[graph[akt].at(j).next]--;
            if(it[graph[akt].at(j).next]==0) 
            {
                listSorted[end] = graph[akt].at(j).next;
                end++;
            }
            
        }
    }


    int *answers=new int[z];
    //int answers[z];
    int *m=new int[z];
    //int m[z];

    long long int *d=new long long int[id];
   //long long int d[id];
    long long int *p=new long long int[id];
   //long long int p[id];
    for(int i=0;i<z;i++)
    {
        cin>>m[i];
        for(long long int j=0; j<id;j++)
        {
            d[j]=INT_MAX-1;
            p[j]=-1;
        }
        d[m[i]]=0;

        for(long long int j=m[i]-1;j<id;j++)
        {
            for(int k=0; k<graph[listSorted[j]].size();k++ )
            {
                int w=graph[listSorted[j]].at(k).moves;
                if(d[graph[listSorted[j]].at(k).next] > d[listSorted[j]]+w)
                {
                    d[graph[listSorted[j]].at(k).next]=d[listSorted[j]]+w;
                    p[graph[listSorted[j]].at(k).next]=j;
                }
            }
        }
        answers[i]=d[0];
    }
    for(int i=0;i<z;i++)
    {
        cout<< answers[i]<<"\n";
    }
    delete[] holes;
    delete[] graph;
    delete[] d;
    delete[] p;
    delete[] answers;
    delete[] m;
    delete[] listSorted;
    delete[] it;
    return 0;
}