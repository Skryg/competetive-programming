//Oskar Krygier
#include <bits/stdc++.h>

using namespace std;

int n;
bool flag = true;
vector<int> w;
vector<int> answers;
long long maxi=0;

void loadData()
{
    cin>>n;
    w.push_back(0);
    answers.push_back(0);
    for(int i=0;i<n;i++)
    {
        int g;
        cin>>g;

        maxi+=g;
        w.push_back(g);
        answers.push_back(0);
    }
    

}

int main()
{
    ios_base::sync_with_stdio();
    cin.tie(0);
    loadData();
    for(int i=1;i<=maxi;i++)
    {   
        int su = i;
        int count=0;
        for(int j=1;j<=n;j++)
        {
            if(w[j]<=su)
            {
                su-=w[j];
                count++;
            }
        }
        if(count<=n)
        {
            if(answers[count]==0) answers[count]=i;
            else
                answers[count]=min(i,answers[count]);
        }
            
    }
    for(int i=1;i<=n;i++) cout<<answers[i]<<" ";
    return 0;
}