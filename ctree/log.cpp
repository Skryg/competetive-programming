#include <bits/stdc++.h>

using namespace std;

int n,m;
vector<int> values;

struct query{
    char type;
    long long int first, second;
};

vector<query> queries;
int* drivers;
struct treeElement{
    pair<int,int> posit={-1,-1};
    long long int value=0;
    long long int valueSecond=0;
    
};
vector<treeElement> tree;

unordered_map<int,int> umap;
void reloadTree(int w)
{
    w=w/2;
    if(w>0)
    {
        tree[w].value=tree[2*w].value+tree[2*w+1].value;
        tree[w].valueSecond=tree[2*w].valueSecond+tree[2*w+1].valueSecond;
        reloadTree(w);
    }
}

void addElementTree(int which, int size, int hm){
    if(which==0) return;
    tree[which].valueSecond+=hm;
    tree[which].value=tree[which].valueSecond*tree[which].posit.first;
    reloadTree(which);
};

long long int findTreeFirstValue(int first, int second, int vertex)
{
    if((tree[vertex].posit.first>=first) && (tree[vertex].posit.second<=second))
        return tree[vertex].value;
    else if(tree[vertex].posit.first > second || tree[vertex].posit.second < first)
        return 0;
    else if((tree[vertex].posit.first<=second &&tree[vertex].posit.second >= second )||(tree[vertex].posit.second >= first && tree[vertex].posit.first <= first))
        return findTreeFirstValue(first,second, vertex*2)+findTreeFirstValue(first,second, vertex*2+1);

    return 0;
};
long long int findTreeSecondValue(int first, int second, int vertex)
{
    if(tree[vertex].posit.first>=first && tree[vertex].posit.second<=second)
        return tree[vertex].valueSecond;
    if(tree[vertex].posit.first > second || tree[vertex].posit.second < first)
        return 0;
    if((tree[vertex].posit.first<=second &&tree[vertex].posit.second >= second )||(tree[vertex].posit.second >= first && tree[vertex].posit.first <= first))
        return findTreeSecondValue(first,second, vertex*2)+findTreeSecondValue(first,second, vertex*2+1);

    return 0;
};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin>>n>>m;
    drivers = new int[n+1];
    for(int i=0; i<=n;i++) drivers[i]=0;
    for(int i=0;i<m;i++){
        query q;
        queries.push_back(q);
        cin>>queries[i].type>>queries[i].first>>queries[i].second;
        values.push_back(queries[i].second);
    }
    sort(values.begin(),values.end());
    int k=1;
    for(int i=0;i<values.size();i++){
        
        umap[values[i]]=0;
    }
    while(k<umap.size()){
        k*=2;
    }
    for(int i=0;i<2*k;i++)
    {
        treeElement t;
        tree.push_back(t);
    }

    int incr=0;
    for(int i=0;i<values.size();i++){
        
        int d= umap[values[i]];
        
        if(d==0){
            umap[values[i]]=incr+k;
            tree[incr+k].posit.first=values[i];
            tree[incr+k].posit.second = values[i];
            incr++;
        } 
    }

    for(int i=k-1;i>0;i--){
        tree[i].posit.first=tree[2*i].posit.first;
        tree[i].posit.second=max(tree[2*i].posit.second,tree[2*i+1].posit.second);
    }
    for(int i=0;i<queries.size();i++)
    {
        if(queries[i].type == 'U')
        {
            int l=umap[drivers[queries[i].first]];
            addElementTree(l, k,-1);
        
            drivers[queries[i].first]=queries[i].second;
            l=umap[drivers[queries[i].first]];
            addElementTree(l, k,1);
        }
        else
        {
            if((long long)queries[i].first * (long long)queries[i].second <= findTreeFirstValue(1, queries[i].second,1)+(findTreeSecondValue(queries[i].second+1, 1000000000,1)*queries[i].second)) cout<<"TAK\n";
            //if((long long)queries[i].first * (long long)queries[i].second <= findTreeFirstValue(1, queries[i].second,1)+(findTreeSecondValue(queries[i].second+1, 1000000000,1)*queries[i].second)) cout<<"TAK "<< queries[i].first * queries[i].second <<" <= "<<findTreeFirstValue(1, queries[i].second,1)<<"+"<<findTreeSecondValue(queries[i].second+1, 1000000000,1)*queries[i].second<<"\n";
            else cout<<"NIE\n";
            //else cout<<"NIE "<< queries[i].first * queries[i].second <<" <= "<<findTreeFirstValue(1, queries[i].second,1)<<"+"<<findTreeSecondValue(queries[i].second+1, 1000000000,1)*queries[i].second<<"\n";
        }
        

    }

    delete drivers;
    return 0;
}