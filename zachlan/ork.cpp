#include <bits/stdc++.h>

using namespace std;

int main()
{
    int m,n,k;
    cin>>k>>m>>n;
    
    int **field = new int*[n];
    for(int i=0;i<n;i++)
    {
        field[i] = new int[m];
        for(int j=0;j<m;j++)
        {
            cin>>field[i][j];
        }
    }

    int **prefX = new int*[n];
    for(int i=0;i<n;i++)
    {
        prefX[i] = new int[m+1];
        prefX[i][0]=0;
        for(int j=1; j<=m;j++)
        {
            prefX[i][j]=prefX[i][j-1]+field[i][j-1];

        }

    }
    int **prefY = new int*[m];

    for(int i=0;i<m;i++)
    {
        prefY[i]=new int[n];
        prefY[i][0]=0;
        for(int j=1; j<=n;j++)
        {
            prefY[i][j]=prefY[i][j-1]+field[j-1][i];

        }
  
    }

    int idprefX[2];
    idprefX[0]=0;
    idprefX[1]=m;
    int idprefY[2];
    idprefY[0]=0;
    idprefY[1]=n;
    int c=0;
    bool end=false;
    int g[4];
    while(!end)
    {
        
        g[0] = prefX[idprefY[0]][idprefX[1]]-prefX[idprefY[0]][idprefX[0]]; //up
        g[1] = prefX[idprefY[1]-1][idprefX[1]]-prefX[idprefY[1]-1][idprefX[0]]; //down
        g[2] = prefY[idprefX[0]][idprefY[1]]-prefY[idprefX[0]][idprefY[0]]; //left
        g[3] = prefY[idprefX[1]-1][idprefY[1]]-prefY[idprefX[1]-1][idprefY[0]]; //right
        int max=INT_MAX;
        int maxid=-1;
        int longest=0;
        for(int i=0;i<4;i++)
        {
            if(g[i]<=k)
            {
                
                int p;
                if(i>1)
                {
                    p = idprefY[1]-idprefY[0];
                }
                else
                {
                    p=idprefX[1]-idprefX[0];
                    
                }
                if(p>=longest)
                {  
                    if(p>longest||g[i]<max)
                    {
                        longest = p;
                        
                        maxid=i;
                        max=g[i];
                    }
                          
                } 
                
            }
        }
        if(maxid==0)   
        { 
            idprefY[0]++;
        }
        else if(maxid==1)
        {  
            idprefY[1]--;
        }
        else if(maxid==2)
        {   
            idprefX[0]++;
        }
        else if(maxid==3)
        { 
            idprefX[1]--;
        }
        c++;
        if(idprefY[0]==idprefY[1] || idprefX[0]==idprefX[1])
            end=true;
    }
    cout<<c;
    for(int i=0; i<m;i++)
    {
        delete[] prefY[i];
    }
    for(int i=0;i<n;i++)
    {
        delete[] field[i];
        delete[] prefX[i];
    }
    delete[] prefY;
    delete[] field;
    delete[] prefX;
    return 0;
}