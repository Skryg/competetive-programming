#include <iostream>
#include <algorithm>

#define satori int z; cin>>z; while(z--)

using namespace std;

class point{
    int x,y;
public:
    point();
    point(int x, int y);

    int getX();
    int getY();
    void print();
};

point::point(){
    x=0,y=0;
}
point::point(int x, int y){
    this->x=x, this->y=y;
}
int point::getX(){
    return x;
}
int point::getY(){
    return y;
}
void point::print(){
    cout<<x<<' '<<y<<'\n';
}

class queue{
    int size;
    int first,last;
    point *tab;
public:
    queue();
    queue(int n);
    ~queue();
    void enqueue(const point& x);
    point dequeue();
    point front();
    bool empty();
    bool full();
    void clear();
    void resize(int n);
};

queue::queue(int n){
    first=last=0;
    size=n;
    tab = new point[n];
}
queue::queue() : queue(15){}
queue::~queue(){
    delete[] tab;
}
void queue::enqueue(const point& x){
    if(full()) throw string("ENQUEUE");
    if(last == size){
        for(int i=first; i<last;++i)
            tab[i-first] = tab[i];
        last-=first;
        first=0;
    }
    tab[last++]=x;
}
point queue::dequeue(){
    if(empty()) throw string("DEQUEUE");
    return tab[first++];
}
bool queue::empty(){
    return first==last;
}
point queue::front(){
    if(empty()) throw string("FRONT");
    return tab[first];
}
bool queue::full(){
    return (last==size && first==0);
}
void queue::clear(){
    last=first=0;
}

void queue::resize(int n){
    if(n<=size) return;
    point *nt = new point[n];
    size=n;

    for(int i=first;i<last;++i){
        nt[i-first]=tab[i];
    }
    last-=first;
    first=0;
    delete[] tab;
    tab = nt;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    satori{
        int n,m;
        cin>>n>>m;
        const int m_v=m+2;
        
        queue q(4*(n*m+n+m));
        
        int **tab;
        tab = new int*[n+2];
        for(int i=0;i<n+2;++i) tab[i] = new int[m+2];
        for(int i=0;i<=n+1;++i){
            for(int j=0;j<=m+1;++j){ 
                if(i==0 || i == n+1 || j == 0 || j==m+1){
                    tab[i][j]=-2;
                }
                else{
                    //cout<<i<< ' '<< j << "  ";
                    cin>>tab[i][j];
                    tab[i][j]=-tab[i][j];
                    if(tab[i][j]<-3){
                        q.enqueue({(i-1)*m_v+j,1});
                        q.enqueue({(i+1)*m_v+j,1});
                        q.enqueue({i*m_v+j-1,1});
                        q.enqueue({i*m_v+j+1,1});
                    }
                }
            }
            //cout<<'\n';
        }
        int x,y;
        x=y=-1;
        while(!q.empty()){
            point p = q.dequeue();
            int a = p.getX()/m_v, b = p.getX()%m_v;
            int val = p.getY();
            if(tab[a][b]==-3){
                x=a,y=b;
                tab[a][b]=val;
                break;
            }
            //cout<<a<<' '<<b<< "xd\n";
            if(tab[a][b]) continue;
            tab[a][b] = val;

            q.enqueue({(a-1)*m_v+b, val+1});
            q.enqueue({(a+1)*m_v+b, val+1});
            q.enqueue({a*m_v+b-1, val+1});
            q.enqueue({a*m_v+b+1, val+1});
        }
        int ans0=-1, val0=-1;
        if(x!=-1 || y!=-1){
            val0 = tab[x][y];
            tab[x][y]=-3;

            for(int v = val0-1; v; v--){
                if(v == tab[x-1][y]) x--;
                else if(v == tab[x+1][y]) x++;
                else if(v == tab[x][y-1]) y--;
                else if(v == tab[x][y+1]) y++;
                //cout<<x<< ' '<<y<<'\n';
            }

            if(tab[x-1][y] < -3) ans0 = -tab[x-1][y]; 
            if(tab[x+1][y] < -3) ans0 = -tab[x+1][y]; 
            if(tab[x][y-1] < -3) ans0 = -tab[x][y-1]; 
            if(tab[x][y+1] < -3) ans0 = -tab[x][y+1];
             

        }
        while(!q.empty()) q.dequeue();
        x=y=-1;
        for(int i=0;i<n+2;++i){
            for(int j=0;j<m+2;++j){
                if(tab[i][j]==-1 || (tab[i][j]<-3 && tab[i][j]%2==0) || tab[i][j]>0) tab[i][j]=0;
                if(tab[i][j]<-3){
                        q.enqueue({(i-1)*m_v+j,1});
                        q.enqueue({(i+1)*m_v+j,1});
                        q.enqueue({i*m_v+j-1,1});
                        q.enqueue({i*m_v+j+1,1});
                }
                //cout<<tab[i][j]<<' ';
            }
            //cout<<'\n';
        }
        while(!q.empty()){
            point p = q.dequeue();
            int a = p.getX()/m_v, b = p.getX()%m_v;
            int val = p.getY();
            if(tab[a][b]==-3){
                x=a,y=b;
                tab[a][b]=val;
                break;
            }
            
            //cout<<a<<' '<<b<< "xd\n";
            if(tab[a][b]) continue;
            tab[a][b] = val;

            q.enqueue({(a-1)*m_v+b, val+1});
            q.enqueue({(a+1)*m_v+b, val+1});
            q.enqueue({a*m_v+b-1, val+1});
            q.enqueue({a*m_v+b+1, val+1});
        }
        int ans1=-1, val1=-1;
        if(x != -1  || y != -1){
            val1 = tab[x][y];

            for(int v = val1-1; v; v--){
                if(v == tab[x-1][y]) x--;
                else if(v == tab[x+1][y]) x++;
                else if(v == tab[x][y-1]) y--;
                else if(v == tab[x][y+1]) y++;
                //cout<<x<< ' '<<y<<'\n';
            }
        
            if(tab[x-1][y] < -3) ans1 = -tab[x-1][y]; 
            if(tab[x+1][y] < -3) ans1 = -tab[x+1][y]; 
            if(tab[x][y-1] < -3) ans1 = -tab[x][y-1]; 
            if(tab[x][y+1] < -3) ans1 = -tab[x][y+1];
        }

        if(val1 == -1 && val0 == -1) cout<<-1<< ' '<<-1<<'\n';
        else{
            if(val0 == -1) val0 = 1000000;
            if(val1 == -1) val1 = 1000000;
            if(val1>val0){
                cout<<ans0<<' '<<val0<<'\n';
            }
            else cout<< ans1<<' '<<val1<<'\n';
        }
        
        
        for(int i=0;i<n+2;++i) delete[] tab[i];
        delete[] tab;
    }


    return 0;
}