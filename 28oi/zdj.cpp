//Oskar Krygier
#include <bits/stdc++.h>

using namespace std;

int n,m;
vector<vector<int>> gr;
vector<bool> visited;
vector<int> dist;
vector<int> hat;
void dfs(int v){
    if(visited[v]) return;
    visited[v] = true;

    for(int i=0;i<gr[v].size();++i){
        dfs(gr[v][i]);
    }
}

int main()
{
    ios_base::sync_with_stdio();
    cin.tie(0);
    cin>>n>>m;
    gr.resize(n+1);
    dist.resize(n+1);
    hat.resize(n+1);
    visited.resize(n+1);
    for(int i=0;i<m;++i){
        int a,b;
        cin>>a>>b;
        gr[a].push_back(b);
        gr[b].push_back(a);

    }
    if(m==0){
        cout<<"TAK\n";
        for(int i=1;i<=n;++i){
            cout<<i<<" ";
        }
        return 0;
    }
    dfs(1);
    if(!visited[2]){
        cout<< "NIE";
        return 0;
    }
    for(int i=1;i<=n;++i){
        if(!visited[i]&&gr[i].size()>0){
            cout<<"NIE";
            return 0;
        }
    }
    queue<pair<int,int>> que;
    bool flag=true;
    fill(visited.begin(),visited.end(), false);
    que.push({2,0});
    while(!que.empty()){
        int v = que.front().first;
        int d = que.front().second;
        que.pop();
        if(visited[v]) continue;
        dist[v]=d;
        visited[v]=true;
        
        for(int i=0; i<gr[v].size();++i){
            if(!visited[gr[v][i]]) que.push({gr[v][i],d+1});
        }
    }
    fill(visited.begin(),visited.end(), false);
    priority_queue<pair<int,int>> pq;
    int h{1};
    pq.push({0,1});
    while(!pq.empty()){
        pair<int, int> p = pq.top();
        pq.pop();
        int v = p.second;
        if(visited[v]) continue;
        visited[v]=true;
        hat[v] = h++;
        int s{(int)gr[v].size()};
        int s2{0};
        for(int i=0;i<gr[v].size();++i){
            if(hat[gr[v][i]]!=0) ++s2;
        }
        if(s/2!=s2 && v!=1 && v!=2){
            flag = false;
        }
        for(int i=0;i<gr[v].size();++i){
            if(!visited[gr[v][i]]){
                int v2 = gr[v][i];
                pq.push({dist[v2], v2});
            }
        }
    }
    for(int i=1;i<=n;++i){
        if(!visited[i]){
            hat[i] = h++;
        }
    }
    if(!flag){
        fill(visited.begin(),visited.end(), false);
        fill(hat.begin(),hat.end(), 0);
        fill(dist.begin(),dist.end(), 0);
        que.push({1,0});
        while(!que.empty()){
            int v = que.front().first;
            int d = que.front().second;
            que.pop();
            if(visited[v]) continue;
            dist[v]=d;
            visited[v]=true;
            
            for(int i=0; i<gr[v].size();++i){
                if(!visited[gr[v][i]]) que.push({gr[v][i],d+1});
            }
        }
        fill(visited.begin(),visited.end(), false);
        priority_queue<pair<int,int>> pq;
        int h{1};
        pq.push({0,2});
        while(!pq.empty()){
            pair<int, int> p = pq.top();
            pq.pop();
            int v = p.second;
            if(visited[v]) continue;
            visited[v]=true;
            hat[v] = h++;
            int s{(int)gr[v].size()};
            int s2{0};
            for(int i=0;i<gr[v].size();++i){
                if(hat[gr[v][i]]!=0) ++s2;
            }
            if(s/2!=s2 && v!=1 && v!=2){
                cout<<"NIE";
                return 0;
                
            }
            for(int i=0;i<gr[v].size();++i){
                if(!visited[gr[v][i]]){
                    int v2 = gr[v][i];
                    pq.push({dist[v2], v2});
                }
            }
        }
        for(int i=1;i<=n;++i){
            if(!visited[i]){
                hat[i] = h++;
            }
        }
    }
    cout<<"TAK\n";
    for(int i=1;i<=n;++i){
        cout<<hat[i]<<" ";
    }
    

    return 0;
}