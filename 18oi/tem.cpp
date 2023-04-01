#include <bits/stdc++.h>

using namespace std;



int n;
vector<pair<int,int>> temps;
struct monoQue
{
    deque<pair<int,int>> q;

    monoQue(){}

    void add(int a, int id)
    {
        while(!q.empty()&&q.back().first <= a)
        {
            q.pop_back();
        }
        q.push_back({a,id});
    }

    void pop(int id)
    {
        if(q.front().second == id)
            q.pop_front();
    }

    int val()
    {
        return q.front().first;
    }

};
void loadData();

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    loadData();
    monoQue mono;

    int first=0,last=0, len=1;
    

    for(last=0;last<temps.size();++last)
    {
        mono.add(temps[last].first,last);
        while(mono.val()>temps[last].second)
        {
            mono.pop(first++);
        }
        len = max(len, last-first+1);
    }
    cout<<len;
    return 0;
}

void loadData()
{
    cin>>n;
    for(int i=0;i<n;++i)
    {
        int a,b;
        cin>>a>>b;
        temps.push_back({a,b});
    }
}

