#include <bits/stdc++.h>

using namespace std;

long long n,p,d,val;
int ans=0;
vector<int> nums;
vector<long long> plank;

struct monoQueue
{
    int first, last;
    deque<pair<long long,long long>> mq;

    void push(long long num)
    {
        val+=nums[last];
        while(!mq.empty() && mq.back().first <= num) mq.pop_back();
        last++;
        mq.push_back({num, last-d+1});
    }
    void pop()
    {
        if(first == mq.front().second) mq.pop_front();
        first++;
        if(last<n&&last-first+1<d)
            push(plank[last+1]);
    }
    long long bonus()
    {
        return mq.front().first;
    }
    monoQueue(int startLen)
    {
        first=1;
        last=startLen;
        mq.push_back({plank[startLen],1});
    }
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>p>>d;
    for(int i=0;i<n;i++)
    {
        int k;
        cin>>k;
        nums.push_back(k);
    }
    plank.push_back(0);
    for(int i=1;i<=d;i++)
    {
        plank.push_back(plank[i-1]+nums[i-1]);
    }
    for(int i=d+1;i<=n;i++)
    {
        plank.push_back(plank[i-1]+nums[i-1]-nums[i-1-d]);
    }
    monoQueue mq = monoQueue(d);
    ans= d;
    val = mq.bonus();
    while(mq.last<n)
    {/*
        if(plank[mq.last+1]>mq.bonus())
        {
            mq.push(plank[mq.last+1]);
        }
        if(mq.bonus()+p>=val) ans=max(mq.last - mq.first+1,ans);    */
        if(mq.last < n) 
        {
            if(max(mq.bonus(),plank[mq.last+1])+p>=val+nums[mq.last])
            {
                mq.push(plank[mq.last+1]);
                
            }
            else
            {
                val-=nums[mq.first-1];
                mq.pop();
                
            }
        }
        if(mq.bonus()+p>=val)ans=max(mq.last - mq.first+1,ans);
       
    }
    cout<<ans;
    return 0;
}