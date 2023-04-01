#include <iostream>
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
        
        queue q(4*n*m+n+m);
        
        int **tab;
        tab = new int*[n+2];
        for(int i=0;i<n+2;++i) tab[i] = new int[m+2];
        for(int i=0;i<=n+1;++i){
            for(int j=0;j<=m+1;++j){ 
                if(i==0 || i == n+1 || j == 0 || j==m+1){
                    tab[i][j]=-1;
                }
                else{
                    //cout<<i<< ' '<< j << "  ";
                    cin>>tab[i][j];
                    tab[i][j]=-tab[i][j];
                }
            }
            //cout<<'\n';
        }
        int x=-1,y=-1,v=0;
        for(int i=1;i<=n;++i){
            if(x!=-1) break;
            for(int j=1;j<=m;++j){
                if(tab[i][j]<-3){
                    if(!tab[i+1][j]) {
                        tab[i+1][j]=1;
                        q.enqueue({i+1, j});
                    }
                    else if(tab[i+1][j]==-3){
                        x = i+1, y=j;
                        tab[i+1][j]=1;
                        v=1;
                        break;
                    }
                    if(!tab[i-1][j]){
                        tab[i-1][j]=1;
                        q.enqueue({i-1,j});
                    }
                    else if(tab[i-1][j]==-3){
                        x = i-1, y=j;
                        tab[i-1][j]=1;
                        v=1;
                        break;
                    }
                    if(!tab[i][j+1]){
                        tab[i][j+1]=1;
                        q.enqueue({i,j+1});
                    }
                    else if(tab[i][j+1]==-3){
                        x= i,y=j+1;
                        tab[i][j+1]=1;
                        v=1;
                        break;
                    }
                    if(!tab[i][j-1]){
                        tab[i][j-1]=1;
                        q.enqueue({i,j-1});
                    }
                    else if(tab[i][j-1]==-3){
                        x=i,y=j-1;
                        tab[i][j-1]=1;
                        v=1;
                        break;
                    }
                }
            }
        }
        if(x==-1){
            while(!q.empty()){
                point p = q.dequeue();
                int a = p.getX(), b = p.getY();
                //cout<<a<<' '<<b<<'\n';
                if(!tab[a+1][b]){
                    tab[a+1][b]=tab[a][b]+1;
                    q.enqueue({a+1,b});
                }
                else if(tab[a+1][b]==-3){
                    x = a+1, y=b;
                    tab[a+1][b]=tab[a][b]+1;
                    v=tab[a+1][b];
                    break;
                }
                if(!tab[a-1][b]){
                    tab[a-1][b]=tab[a][b]+1;
                    q.enqueue({a-1,b});
                }
                else if(tab[a-1][b]==-3){
                    x = a-1, y=b;
                    tab[a-1][b]=tab[a][b]+1;
                    v=tab[a-1][b];
                    break;
                }
                if(!tab[a][b+1]){
                    tab[a][b+1]=tab[a][b]+1;
                    q.enqueue({a,b+1});
                }
                else if(tab[a][b+1]==-3){
                    x= a,y=b+1;
                    tab[a][b+1]=tab[a][b]+1;
                    v=tab[a][b+1];
                    break;
                }
                if(!tab[a][b-1]){
                    tab[a][b-1]=tab[a][b]+1;
                    q.enqueue({a,b-1});
                }
                else if(tab[a][b-1]==-3){
                    x=a,y=b-1;
                    tab[a][b-1]=tab[a][b]+1;
                    v=tab[a][b-1];
                    break;
                }
            }
        }
        
        if(x==-1){
            cout<<-1<<' '<<-1<<'\n';
        }
        else{
            v = tab[x][y];
            //cout<<x << ' '<< y<<'\n';
            for(int val=v-1;val>=0; val--){
                if(tab[x-1][y]==val || ((!val) && tab[x-1][y]<-3)) x=x-1;
                else if(tab[x+1][y]==val || ((!val) && tab[x+1][y]<-3)) x=x+1;
                else if(tab[x][y+1]==val || ((!val) && tab[x][y+1]<-3)) y=y+1;
                else if(tab[x][y-1]==val || ((!val) && tab[x][y-1]<-3)) y=y-1;
            }
            cout<<-tab[x][y]<<' '<<v<<'\n';
        }
        
        for(int i=0;i<n+2;++i) delete[] tab[i];
        delete[] tab;
    }


    return 0;
}