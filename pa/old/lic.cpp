#include <bits/stdc++.h>

using namespace std;
long long int powe10[19]={1,10,100,1000,10000,100000,1000000,10000000,100000000,1000000000,10000000000,100000000000,1000000000000,10000000000000,100000000000000,1000000000000000,10000000000000000,100000000000000000,1000000000000000000};


void add(short* num, int & position)
{
    num[position]++;
    if(num[position]>9)
    {
        num[position]=1;
        position++;
        add(num,position);
    }
}

long long int allNum(short* num)
{
    long long int number=0;
    for(int i=0;i<19;i++)
    {
        number+=num[i]*powe10[i];
    }
    return number;
}

bool check(short* num,int div)
{
    switch (div)
    {
    case 1:
        return true;
        break;
    case 2:
        if(num[0]%2==0)
            return true;
        break;
    case 3:
    {
        int m=0;
        for(int i=0;i<19;i++)
        {
            m+=num[i];
        }
        if(m%3==0)
            return true;  
        break; 
    }
    case 4:
        if((num[0]+(num[1]*10))%4==0)
            return true;
        break;
    case 5:
        if(num[0]==5)
            return true;
        break;
    case 6:
    {
        int m=0;
        for(int i=0;i<19;i++)
        {
            m+=num[i];
        }
        if(m%3==0 && num[0]%2==0)
            return true;  
        break; 
    }   
    case 7:
    {
        
        if(allNum(num)%7==0)
            return true;
        break;
    }
    case 8:
        if((num[0]+(num[1]*10)+(num[2]*100))%8==0)
            return true;
        break;
    case 9:
    {
        int m=0;
        for(int i=0;i<19;i++)
        {
            m+=num[i];
        }
        if(m%9==0)
            return true;  
        break; 
    }    
    default:
        break;
    }
    return false;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long int l,r,ans=0;
    cin>>l>>r;
    short num[19];
    for(int i=0;i<18;i++)
    {
        num[i]=(l%powe10[i+1])/powe10[i];

    }
    num[18]=l/powe10[18];
    int last0;
    for(int i=18; i>=0;i--)
    {
        if(num[i]==0)
            last0=i;
        else break;
    }

    bool yes=true;
    int posit=0;
    bool checked[10]={false,false,false,false,false,false,false,false,false,false};
    while(allNum(num)<=r)
    {
        //cout<<allNum(num)<<"\n";
        for(int i=1;i<10;i++)
        {
            checked[i]=false;
        }
        posit=0;
        yes=true;
        for(int i=0;i<19;i++)
        {
            if(last0 <=i && num[i]==0)
            {
                break;
            }
            else if(num[0]==0)
            {
                yes=false;
                break;
            }
                
            if(checked[num[i]]==true)
                continue;
            if(!check(num,num[i]))
            {
                yes=false;
                break;
            }
            else checked[num[i]]=true;
        }
        if(yes)
        {
            ans++;
            //cout<<allNum(num)<<" ";
        }
            
        add(num,posit);
    }
    cout<<ans;
    return 0;
}