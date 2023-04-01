#include <iostream>
#include <vector>
using namespace std;

struct pathElement
{
    int near;
    int biciak;
    pathElement(int n, int b)
    {
        near=n;
        biciak=b;
    }
    pathElement()
    {
        near=-1;
        biciak=-1;
    }
};

void setPath(int **path, pathElement **V, int now, int later,int *size)
{

    for(int i=0; i<size[now];i++)
    {
        //cout<<"Later "<<later<<" Now "<<now<<" ";
        if(V[now][i].near!=later)
        {
            //cout<<"Wyslano dane do "<<V[now].at(i).road<<" z "<<now<<" "<<endl;
            setPath(path,V,V[now][i].near,now,size);
        }
        else
        {
            path[now][0]=later;
            path[now][1]=V[now][i].biciak;
            //cout<<"Hololo";

        }

    }
}

int getNum(bool *where,int **pathp, int which)
{
    if(which==1)
        return 0;
    int is=0;
    if(where[pathp[which][1]]==false)
    {
        where[pathp[which][1]]=true;
        is++;
        //cout<<"Dobra nie bylo jeszcze: "<<pathp[which].biciak<<"\n";
    }
    return is+getNum(where,pathp,pathp[which][0]);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,m,z;
    cin>>n>>m>>z;
    int **road = new int*[n-1];
    for(int i=0;i<n-1;i++)
    {
        road[i]=new int[3];
    }

    vector<pathElement> *neigh = new vector<pathElement>[n+1];


    vector<int> ans;
    for(int i=0;i<n-1;i++)
    {
        cin>>road[i][0]>>road[i][1]>>road[i][2];
        neigh[road[i][0]].push_back(pathElement(road[i][1],road[i][2]));
        neigh[road[i][1]].push_back(pathElement(road[i][0],road[i][2]));

    }

    pathElement **nei = new pathElement*[n+1];
    int *size = new int [n+1];

     int **path= new int*[n+1];
     for(int i=0;i<n+1;i++)
    {
        nei[i]= new pathElement[neigh[i].size()];
        size[i]=neigh[i].size();
        for(int j=0;j<neigh[i].size();j++)
        {
            nei[i][j]=neigh[i][j];
        }
        path[i]=new int[2];
    }
     setPath(path,nei,1,0,size);
/*
    for(int i=0;i<n+1;i++)
    {
        for(int j=0; j<neigh[i].size();j++)
        {
            cout<<neigh[i][j].road<<" ";
        }
        cout<<endl;
    }

    for(int i=0; i<n+1;i++)
    {
        cout<<path[i].road<<" "<<path[i].biciak<<endl;
    }*/

    bool *tab = new bool[m+1];
    for(int i=0;i<z;i++)
    {
        char type;
        cin>>type;
        if(type =='Z')
        {
            for(int i=0;i<m+1;i++)
            {
                tab[i]=false;
            }
            int z;
            cin>>z;
            ans.push_back(getNum(tab,path,z));
        }
        else if(type == 'B')
        {
            int r,c;
            cin>>r>>c;
            if(path[road[r-1][0]][0]==road[r-1][1])
            {
                path[road[r-1][0]][1]=c;
            }
            else path[road[r-1][1]][1]=c;
        }
    }

    for(int i=0; i<ans.size();i++)
    {
        cout<<ans[i]<<"\n";
    }
    

    delete[] neigh;
    delete[] tab;
    for(int i=0;i<n+1;i++)
    {
        delete[] path[i];
        delete[] nei[i];
    }
    delete[] size;
    delete[] nei;
    delete[] path;
    
    for(int i=0;i<n-1;i++)
    {
        delete[] road[i];
    }
    delete[] road;
    return 0;
}
