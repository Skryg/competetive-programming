#include <bits/stdc++.h>

using namespace std;

int n,m,l,k;
vector<int> col;
vector<int> bit1,bit2,next1,next2;

void transport(int i1, int i2,vector<int> &saved,vector<int> &n);
void transport2(int i1, int i2, vector<int> &saved,vector<int> &n);

int main()
{  
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>k;
    col.push_back(0);
    vector<int> last(k+1);
    for(int i=0;i<n;++i)
    {
        int d;
        cin>>d;
        col.push_back(d);
    }
    
    cin>>m>>l;
    for(int i=0;i<m;++i)
    {
        int d;
        cin>>d;
        bit1.push_back(d);

    }
    for(int i=0;i<l;++i)
    {
        int d;
        cin>>d;
        bit2.push_back(d);
    }
    next1.resize(n+1);
    next2.resize(n+1);
    for(int i=1;i<=n;++i)
    {
        if(last[col[i]]!=0)
            next2[i]=last[col[i]];
        last[col[i]]=i;
    }
    fill(last.begin(),last.end(),0);
    for(int i=n;i>0;--i)
    {
        if(last[col[i]]!=0)
            next1[i]=last[col[i]];
        last[col[i]]=i;
    }
    vector<int> l1(k+1);
    vector<int> l2(k+1);
    vector<int> savedPos(bit1.size()-1);
    int it{0},it2{2};
    bool end{0};
    while(!end)
    {
        if(savedPos.size()>0&&col[it2]==bit1[it])
        {
            savedPos[it]=it2;
            ++it;
        }
         
       
        if(it==bit1.size()-1)
        {
            end=true;
            l1[col[1]]=it2;
        } 
        if(savedPos.size()==0)
        {
            l1[col[1]]=1;
            end=true;
        }   
        ++it2;
        if(it2>n) break;
        
    }
    if(!end)
    {
        cout<<"0";
        return 0;
    }
    for(int i=2;i<n;++i)
    {
        if(l1[col[i]]==0)
        {
            transport(i,0,savedPos,next1);
            if(savedPos.size()==0) l1[col[i]]=i;
            else l1[col[i]]=savedPos.back();
        }
            
    }
    it=0;
    it2=n-1;
    end=false;
    fill(savedPos.begin(),savedPos.end(),0);
    savedPos.resize(bit2.size()-1);
    while(!end)
    {
        if(savedPos.size()>0&&col[it2]==bit2[it])
        {
            savedPos[it]=it2;
            ++it;
        }
            
       
        if(it==bit2.size()-1)
        {
            end=true;
            l2[col[n]]=it2;
        } 
        if(savedPos.size()==0)
        {
            l2[col[1]]=n;
            end=true;
        }  
        --it2;
        if(it2<1) break;
        
    }
    if(!end)
    {
        cout<<"0";
        return 0;
    }
    for(int i=n-1;i>0;--i)
    {
        if(l2[col[i]]==0)
        {
            transport2(i,0,savedPos,next2);
            if(savedPos.size()==0) l2[col[i]]=i;
            else l2[col[i]]=savedPos.back();
        }
            
    }
    vector<int> begins;
    vector<int> ends;

    for(int i=1;i<=k;++i)
    {
        if(l1[i]<l2[i] && l1[i]!=0 && l2[i]!= 0)
        {
            begins.push_back(l1[i]);
            ends.push_back(l2[i]);
        }
    }
    sort(begins.begin(),begins.end());
    sort(ends.begin(),ends.end());
    int i1{0},i2{0},s{0};
    int sum{0};
    vector<int> ans;
    for(int i=1;i<=n;++i)
    {
        
        while(i2<ends.size()&& ends[i2]==i)
        {
            --s;
            ++i2;
        }
        if(s>0&&col[i]==bit1.back())
        {
            ++sum;
            ans.push_back(i);
        }
        while(i1<begins.size()&&begins[i1]==i)
        {
            ++s;
            ++i1;
        }
        
       

    }
    cout<<sum<<"\n";
    for(int i=0;i<ans.size();++i)
    {
        cout <<ans[i] << " ";
    }
    return 0;
}

void transport(int i1, int i2, vector<int> &saved,vector<int> &n)
{
    bool end{0};
    bool changed=false;
    if(i2>=saved.size()) return;
    while(!end)
    {
        if((saved[i2]<=i1||(i1==0)) && saved[i2]!=0 )
        {
            saved[i2]=n[saved[i2]];
            changed=true;
        }
        else end=true;
        
    }
    if(changed) transport(saved[i2],i2+1,saved,n);
    
}
void transport2(int i1, int i2, vector<int> &saved,vector<int> &n)
{
    bool changed=false;
    bool end{0};
    if(i2>=saved.size()) return;
    while(!end)
    {
        if((saved[i2]>=i1||(i1==0)) && saved[i2]!=0 )
        {
            saved[i2]=n[saved[i2]];
            changed = true;
        }
        else end=true;
        
    }
    if(changed) transport2(saved[i2],i2+1,saved,n);
    
}