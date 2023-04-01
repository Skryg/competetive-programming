#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {   
        int n;
        cin>>n;
        vector<int> nums(2*n);
        vector<int> b;
        for(int i=0;i<2*n;++i)
        {
            cin>>nums[i];
        }
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;++i)
        {
            cout<<nums[i]<<" "<<nums[n+i]<<" ";
        }
        cout<<"\n";
    }


    return 0;
}