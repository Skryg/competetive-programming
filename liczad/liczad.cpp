#include <iostream>
#include <vector>

using namespace std;
const long long int power10[19]={1,10,100,1000,10000,100000,1000000,10000000,100000000,1000000000,10000000000,100000000000,1000000000000,10000000000000,100000000000000,1000000000000000,10000000000000000,100000000000000000,1000000000000000000};

void add(long long num, unsigned long long nums[],int idnums)
{
    nums[idnums]+=num;
    if(nums[idnums]/power10[18]>0)
    {
        nums[idnums]-=power10[18];
        add(1,nums,idnums+1);
    }
}
void subtract(long long num, unsigned long long nums[], int idnums)
{
    if(num*-1>nums[idnums])
    {
        subtract(-1,nums,idnums+1);
        nums[idnums]+=power10[18];
    }
    nums[idnums]+=num;

}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int n,z;
    cin>>n>>z;
    string inner,outer;
    cin>> inner>>outer;
    short int ine[n-1];
    short int oute[n-1];
    vector<int> answers;
    for(int i=0;i<n-1;i++)
    {
        ine[i]=inner[i]-'0';
        oute[i]=outer[i]-'0';
    }
    unsigned long long int nums[n/18+1];
    int g=n-2;
    int bonus=0;
    for(int i=0;i<n/18+1;i++)
    {
        nums[i]=bonus;
        bonus=0;

        for(int j=0;j<18;j++)
        {
            if(g>=0)
            {
                nums[i]+=(ine[g]*power10[j]+oute[g]*power10[j]);
                g--;
            }
            
        }
        if(i+1<n/18+1 && nums[i]/power10[18]>0)
        {
            nums[i]-=power10[18];
            bonus=1;
        }
    }
    
    for(int i=0;i<z;i++)
    {
        char c;
        cin>>c;
        switch (c)
        {
        case 'S':
        {
            int id;
            cin>> id;
            id--;
             
            answers.push_back((nums[id/18]/power10[id%18])%10);

            break;
        }
            
        case 'W':
        {
            int id, newnum;
            cin>>id>>newnum;
            id--;
            int dif = newnum-ine[n-2-id];
            //cout<<"Zmieniono wewnetrzny: id:"<<id<<" na "<<newnum<< " roznica wynosi "<<dif<<"\n";
            ine[n-2-id]=newnum;
            if(dif>0)
                add(dif*power10[id%18],nums,id/18);
            else if(dif<0)
                subtract(dif*power10[id%18],nums,id/18);
            
            break;
        }
            
        case 'Z':
        {
            int id, newnum;
            cin>>id>>newnum;
            id--;
            int dif = newnum-oute[n-2-id];
            //cout<<"Zmieniono zewnetrzny: id:"<<id<<" na "<<newnum<< " roznica wynosi "<<dif<<"\n";

            oute[n-2-id]=newnum;
            if(dif>0)
                add(dif*power10[id%18],nums,id/18);
            else if(dif<0)
                subtract(dif*power10[id%18],nums,id/18);

            break;
        }
            
        }
    }
    for(auto x:answers)
    {
        cout<<x<<"\n";
    }

    return 0;
}