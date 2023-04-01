#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin>>n;
    int d[n],p[n], r[n], sum[n][4],ct[3]={0,0,0},k[3]={0,0,0};
    bool is[3] = {false, false, false};
    long long int result=0;
    for(int i=0;i<n;i++)
    {

        cin>>d[i]>>p[i]>>r[i];
        k[0]+=d[i];
        k[1]+=p[i];
        k[2]+=r[i];
        int s=0;
        sum[i][0]=p[i]+r[i];
        sum[i][1]=d[i]+r[i];
        sum[i][2]=d[i]+p[i];
        s=sum[i][0];
        sum[i][3]=0;
        //cout<<"Drozdzowa; reszta: "<<sum[i][0]<<endl;
        if(sum[i][1]<s)
        {
            s=sum[i][1];
            sum[i][3]=1;
           //cout<<"Paczek; reszta: "<<sum[i][1]<<endl;

        }
        if(sum[i][2]<s)
        {
            s=sum[i][2];
            sum[i][3]=2;
        //    cout<<"Rogal; reszta: "<<sum[i][2]<<endl;
        }
        is[sum[i][3]]=true;
       // cout<< "Dodaje... "<<sum[i][sum[i][3]]<<endl;
        ct[sum[i][3]]++;
    }
    for(int i=0;i<3;i++) if(k[i]==0) is[i]=true;
    if((ct[0]==1||ct[1]==1||ct[2]==1)&&(ct[0]==0||ct[1]==0||ct[2]==0))
    {
        int idtoadd;
        int l=0;
        for(int i=0;i<3;i++)
        {
            if(ct[i]==1)
                is[i]=false;
            if(ct[i]>l)
            {
                l=ct[i];
                idtoadd=i;
            }

        }
        for(int i=0; i<n;i++)
        {
            sum[i][3]=idtoadd;
            result+=sum[i][idtoadd];
          //  cout<<"Dodaje "<< sum[i][idtoadd]<<endl;
        }
    }
    else
    {
        for(int i=0;i<n;i++)
        {
            result+=sum[i][sum[i][3]];
        }
    }

    if(is[0]==false || is[1]==false||is[2]==false)
    {
        vector<int> noteqist;

        long long int dif[2][3] = {{LLONG_MAX,LLONG_MAX,LLONG_MAX},{LLONG_MAX,LLONG_MAX,LLONG_MAX}};
        int id[2][3]={{-1,-1,-1},{-1,-1,-1}};
        for(int i=0;i<3;i++)
        {if(!is[i]) noteqist.push_back(i);}
        for(int i=0; i<n;i++)
        {
            for(int j=0; j<3;j++)
            {
                //cout<<"dla j="<<j<<" ";
                if(is[j]==false)
                {
                   // cout<<" is[j] jest falszywy ";
                    if(sum[i][j]-sum[i][sum[i][3]]<=dif[0][j])
                    {
                        //cout<<"i do tego zaszedl warunek ze roznica sum jest mniejsza niz dif"<<endl;
                        dif[1][j]=dif[0][j];
                        dif[0][j]=sum[i][j]-sum[i][sum[i][3]];
                        id[1][j]=id[0][j];
                        id[0][j]=i;
                    }
                    else if(sum[i][j]-sum[i][sum[i][3]]<=dif[1][j])
                    {
                        dif[1][j]=sum[i][j]-sum[i][sum[i][3]];
                        id[1][j]=i;
                    }
                }
            }
        }
        if(noteqist.size()==1)
        {
            result+= dif[0][noteqist[0]];
           // cout<<"Zostal jeden, dodano "<<dif[0][noteqist[0]]<< " dla notexist rownego "<<noteqist[0]<<endl;;
        }
        else
        {
            if(id[0][noteqist[0]]==id[0][noteqist[1]])
            {
                result += min(dif[0][noteqist[0]]+dif[1][noteqist[1]],dif[0][noteqist[1]]+dif[1][noteqist[0]]);
             //   cout<<"Difference dodany: "<<dif[0][noteqist[0]]<<"+"<<dif[1][noteqist[1]]<<" lub "<<dif[0][noteqist[1]]<<"+"<<dif[1][noteqist[0]]<<endl;
            }
            else
            {
                result += (dif[0][noteqist[0]]+dif[0][noteqist[1]]);
                //cout<<"Difference dodany: "<<(dif[0][noteqist[0]]+dif[0][noteqist[1]])<<endl;
            }
        }
    }
    cout << result;

    return 0;
}
