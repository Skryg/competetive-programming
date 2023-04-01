//Oskar Krygier
#include <bits/stdc++.h>

using namespace std;

unsigned long long k;

vector<vector<unsigned long long>> board;
vector<bitset<101>> vBit;
void loadData()
{
    cin>>k;
}

void boardPrepare()
{
    vBit.resize(101);
    board.resize(101);
    for(int i=1;i<=100;i++)
    {
        board[i].resize(101,0);
    }
    for(int i=1;i<=100;i++)board[1][i]=1;
    for(int i=1;i<=100; i++)board[i][1]=1;
    for(int i=2;i<=100;i++)
    {
        for(int j=2;j<=100;j++)
        {
            board[i][j]=min(board[i-1][j]+board[i][j-1],(unsigned long long)9000000000000000001);
        }
    }
}

void write()
{
    cout<<100<<"\n";
    for(int i=1;i<=100;i++)
    {
        for(int j=1;j<=100;j++)
        {
            if(vBit[i].test(j)) cout<<'#';
            else cout<< '.';
        }
        cout<<"\n";
    }
}

pair<int,int> findTheLowest()
{
    int a=0,b=0;
    unsigned long long minimal=LLONG_MAX;
    for(int i=1;i<=100;i++)
    {
        for(int j=1;j<=100;j++)
        {
            if(board[i][j]>=k && board[i][j] < minimal)
            {
                minimal = board[i][j];
                a=i;b=j;
            }
        }
    }
    for(int i=a+1;i<=100;i++)
    {
        vBit[i].set();
    }
    for(int i=1;i<=a;i++)
    {
        for(int j=b+1;j<=100;j++)
        {
            vBit[i].set(j);
        }
    }
    vBit[a].reset();
    for(int i=a+1;i<=100;i++)
    {
        vBit[i].reset(100);
    }
    return {a,b};
}


int main()
{
    ios_base::sync_with_stdio();
    cin.tie(0);
    loadData();

    boardPrepare();
    pair<int,int> f = findTheLowest();

    
    

    write();
    return 0;
}