#include <bits/stdc++.h>

using namespace std;

int n,s;

int isSbetween(int begin, int end)
{
    if(s>=begin && s<= end) return 1;
    return 0;
}

vector<pair<int,int>> jump;
vector<int> times;
long long ans=0;
vector<int> answers;
vector<int> ids;
vector<bool> is;
stack<int> help;
int leftPosit,rightPosit;
int ite=0;
int actualPos;
void stackToAns()
{
    while(!help.empty())
    {
        answers.push_back(help.top());
        if(answers[(int)answers.size()-1]>answers[(int)answers.size()-2])
        {
            ans+=jump[ite].second;
        }
        else ans+= jump[ite].first;
        help.pop();
        ite++;
    }
}

void setOnRight(int d)
{
    while(d >0)
    {
        if(!is[rightPosit])
        {
            is[rightPosit]=true;
            d--;
            help.push(rightPosit);
            actualPos = rightPosit;
        }
        rightPosit--;
    }
    stackToAns();
}

void setOnLeft(int d)
{
    while(d >0)
    {
        if(!is[leftPosit])
        {
            is[leftPosit]=true;
            d--;
            help.push(leftPosit);
            actualPos = leftPosit;
        }
        leftPosit++;
    }
    stackToAns();
}

int main()
{ 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>s;
    for(int i=0;i<n-1;i++)
    {
        int a,b;
        cin>>a>>b;
        jump.push_back({a,b});

    }
    answers.push_back(s);
    for(int i=0;i<=n;i++) is.push_back(false);
    is[s]=true;
    int i=0;
    leftPosit = 1;
    rightPosit = n;
    actualPos = s;
    while(i<n-1)
    {
        times.clear();
        ids.clear();
        int sign=0;
        times.push_back(jump[i].first-jump[i].second);
        ids.push_back(i);
        if(jump[i].first-jump[i].second > 0) sign = 1;
        if(jump[i].first-jump[i].second < 0) sign = -1;
        
        while(i<n-2)
        {
            if((sign == 1 || sign == 0) && jump[i+1].first-jump[i+1].second > 0)
            {
                times.push_back(jump[i+1].first-jump[i+1].second);
                ids.push_back(i+1);
                i++; 

            }
            else if((sign == -1 || sign == 0) && jump[i+1].first-jump[i+1].second < 0)
            {
                times.push_back(jump[i+1].first-jump[i+1].second);
                ids.push_back(i+1);
                i++;

            }
            else if(jump[i+1].first-jump[i+1].second == 0)
            {
                times.push_back(jump[i+1].first-jump[i+1].second);
                ids.push_back(i+1);
                i++;
            }
            else break;
        }
        if(sign == 1)
        {
            if((int)(actualPos + times.size())>rightPosit)
            {
                int miniL=INT_MAX;
                int id;
                for(int j=0;j<rightPosit - actualPos+1-isSbetween(actualPos+1,rightPosit); j++)
                {
                    if(miniL>=times[j])
                    {
                        miniL = times[j];
                        id = j;
                    }

                }
                jump[ids[id]].second=INT_MAX;
                i = ids[id]-1;
                setOnRight(id);
                /*if(times.size()-id-1!=0)
                {
                    setOnLeft(1);
                    setOnRight(times.size()-id-1);
                }
                else
                {
                    i--;
                    jump[id].second = INT_MAX;
                }
                */
            }
            else
            {
                setOnRight(times.size());
            }

        }
        else if(sign == -1)
        {
            if((int)(actualPos-times.size()) < leftPosit)
            {
                int miniR = INT_MIN;
                int id;
                for(int j=0;j< actualPos-leftPosit+1-isSbetween(leftPosit,actualPos-1); j++)
                {
                    if(miniR<=times[j])
                    {
                        miniR = times[j];
                        id = j;
                    }

                }
                jump[ids[id]].first=INT_MAX;
                i = ids[id]-1;
                setOnLeft(id);
                /*if(times.size()-id-1!=0)
                {
                    setOnRight(1);
                    setOnLeft(times.size()-id-1);
                }
                else
                {
                    i--;
                    jump[id].first = INT_MAX;
                }*/
            }
            else setOnLeft(times.size());
            
        }
        else if(sign == 0)
            setOnRight(times.size());
        i++;
    }
    cout<<ans<<"\n";
    for(int i=0;i<answers.size();i++)   cout<<answers[i]<<" ";

    return 0;
}