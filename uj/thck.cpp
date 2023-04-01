#include <bits/stdc++.h>

using namespace std;



bool loadOutFile(string fileName, vector<pair<int,int>> &x)
{
    //
    ofstream file;

    file.open(fileName.c_str());
    if(!file.good())
        return false;

    for(int i=0; i<x.size();i++)
    {
        file<<x[i].first<<" "<<x[i].second<<endl;
    }

    file.close();
    return true;
}
bool loadFile(string fileName, vector<pair<int,int>> & v)
{
    //Ladowanie danych z pliku
    ifstream file;

    file.open(fileName.c_str());
    if(!file.good())
        return false;
    while(!file.eof())
    {
        string s;
        getline(file,s);
        int g=1;
        int num=0, num1=0,num2=0;
        for(int i=s.length()-1; i>=-1;i--)
        {
            if(i>=0&&s[i]!=' '&s[i]-'0'>=0&&s[i]-'0'<10)
            {
                num+=(g*(s[i]-'0'));
                g*=10;
            }
            else
            {
                if(num2==0)
                    num2=num;
                else num1=num;

                g=1;
                num=0;
            }
            
        }
        v.push_back(make_pair(num1,num2));

    }
    file.close();
    return true;
}
int main()
{
    vector<pair<int,int>> v;
    loadFile("in.txt",v);
    int s=v.size();
    for(int i=0; i<s;i++)
    {
        v.push_back({v.at(i).first-1,v.at(i).second-1});
        v.push_back({v.at(i).first-1,v.at(i).second});
        v.push_back({v.at(i).first-1,v.at(i).second+1});
        v.push_back({v.at(i).first,v.at(i).second-1});
        v.push_back({v.at(i).first,v.at(i).second+1});
        v.push_back({v.at(i).first+1,v.at(i).second-1});
        v.push_back({v.at(i).first+1,v.at(i).second});
        v.push_back({v.at(i).first+1,v.at(i).second+1});
    }
    loadOutFile("out.txt",v);
    return 0;
}