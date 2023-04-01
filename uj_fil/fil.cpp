#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<string> ans;

int main()
{
    int a,b;
    cin>> a>>b;
    bool end=false;
    while(!end)
    {
        string n;
        cin>>n;
        if(n=="end")
            end=true;
        else
        {
            int g= stoi(n,nullptr);
            for(int i=a; i<=b;i++)
            {
                ans.push_back("("+to_string(g)+","+to_string(i)+")");
            }
        }
         
    }
    for(int i=0; i<ans.size();i++)
    {
        cout<<ans[i]<<"\n";
    }
    return 0;
}