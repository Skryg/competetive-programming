#include <bits/stdc++.h>

#define ioscin ios_base::sync_with_stdio(0);cin.tie(0)
#define rep(n) for(int i=0; i<n;++i)
#define pb push_back
using namespace std;

struct Video{
    int time{0}, dead{-1};
    int id{-1};
};

struct Segm{
    struct Vx{
        int min{INT_MAX}, minus{0};
    };
    vector<Vx> t;
    int k{1};
    Segm(int n){
        while(k<n) k*=2;
        t.resize(k*2);
    }
    void refresh(int v){
        if(v==0) return;
        t[v].min = min(t[2*v].min-t[2*v].minus,t[2*v+1].min-t[2*v+1].minus);
        refresh(v/2);
    }

    void insert(int v, int a, int b, int x, int y, int val){
        if(a>=x && b<=y){
            t[v].minus+=val;
            refresh(v/2);
            return;
        }
        int mid = (a+b)/2;
        if(x<=mid) insert(2*v, a, mid, x,y,val);
        if(y>mid) insert(2*v+1, mid+1, b, x,y,val);
    }

    int mi(int v, int a, int b, int x, int y){
        if(a>=x && b<=y){
            return t[v].min - t[v].minus;
        }
        int mid = (a+b)/2;

        int mini{INT_MAX};
        if(y>mid) mini = mi(2*v+1, mid+1, b, x,y);
        if(x<=mid) mini = min(mini, mi(2*v, a, mid, x,y));
        mini-=t[v].minus;
        return mini;
    }
};

bool sort_vid_time(Video v1, Video v2){
    if(v1.time == v2.time) return v1.dead<v2.dead;
    return v1.time<v2.time;
}
bool sort_vid_dead(Video v1, Video v2){
    if(v1.dead == v2.dead) return v1.time<v2.time;
    return v1.dead<v2.dead;
}
int main(){
    ioscin;
    int n; cin>>n;
    vector<Video> vids(n);
    rep(n){
        int a,b;
        cin>>a>>b;
        vids[i] = {a,b,i+1};
    }

    vector<Video> v_time = vids;
    sort(v_time.begin(), v_time.end(), sort_vid_time);
    sort(vids.begin(), vids.end(), sort_vid_dead);
    vector<int> id_to_dead(n+1);
    rep(n){id_to_dead[vids[i].id] = i;}
    Segm s = Segm(n);
    int count_good{0};
    rep(n){
        Video v = v_time[i];
        int id = id_to_dead[v.id];
        s.t[s.k+id].min = v.dead;
        s.refresh((s.k+id)/2);
        
        int min = s.mi(1, 0, s.k-1, id, s.k-1);
        if(min>=v.time){
            s.insert(1, 0, s.k-1, id,s.k-1, v.time);
            ++count_good;
        }
        else{
            s.t[s.k+id].min = INT_MAX;
            s.refresh((s.k+id)/2);
        }
    }
    vector<Video> final;
    final.reserve(count_good);
    for(int i=0;i<n;++i){
        if(s.t[s.k+i].min!=INT_MAX){
            final.pb(vids[i]);
        }
    }
    
    cout<<count_good<<"\n";
    int position{1};
    /*
    for(auto i : final){
        cout<< i.id<<" "<<position<<"\n";
        position+=i.time;
    }*/
    return 0;
}

