#include <iostream>
#include <string>
#define satori int z; cin>>z; while(z--)


using namespace std;

class vector{
    string *tab=nullptr;
    int capacity;
    int size;
public:
    vector(int a = 4, int b = 0, string c = ""){
        if(a<1) a=1;
        if(b<0) b=0;
        tab = new string[a];
        capacity = a;
        size = b;
        for(int i=0;i<b;++i) tab[i]=c;
    }

    vector(const vector &x){
        capacity = x.capacity;
        size = x.size;
        tab = new string[capacity];
        for(int i=0;i<capacity;++i) tab[i]=x.tab[i];
    }

    ~vector(){
        if(tab!=nullptr) delete[] tab;
        tab = nullptr;
    }

    void resize(int n){
        if(n<0) n=0;
        if(capacity < n){
            while(capacity < n){
                capacity *= 2;
            }
            string *temp = new string[capacity];
            for(int i=0; i<size;++i){
                temp[i] = tab[i];
            }
            delete[] tab;
            tab = temp;
        }
        for(int i=size; i<n;++i){
            tab[i]="";
        }
        size = n;

    }

    void add(string s){
        resize(size+1);
        tab[size-1]=s;
    }

    int getSize(){
        return size;
    }

    void clear(){
        size=0;
    }

    void insert(int i, string s){
        if(i>size) return;
        resize(size+1);
        for(int j = size-1; j>i;--j){
            tab[j]=tab[j-1];
        }
        tab[i]=s;
    }

    void erase(int i){
        if(i>=size) return;
        for(int j=i; j<size-1; j++){
            tab[j]=tab[j+1];
        }
        resize(size-1);
    }

    string& operator[](int index){
        if(index >= size) return tab[size-1];
        return tab[index];
    }

    void operator=(const vector &v){
        if(this->tab == v.tab) return;
        if(tab!=nullptr) delete[] tab;
        size = v.size;
        capacity = v.capacity;
        tab = new string[capacity];
        for(int i=0;i<size;++i){
            tab[i]=v.tab[i];
        }

    }

    operator bool(){
        return size!=0;
    }

    bool operator!(){
        return size==0;
    }

    void insertionSort() {
        for(int a = 1; a < getSize(); ++a){
            int x = a;
            for(;x > 0; x--){
                if(tab[x-1]>tab[x]){
                    swap(tab[x], tab[x-1]);
                }
                else break;
            }
        }
    }

    void sort(int x){
        if(getSize()<=1) return;
        if(getSize() <= 30){
            insertionSort();
            return;
        }
        vector vtors[26];
        vector blank;
        for(int i=0;i<getSize();++i){
            if(tab[i].size()<=x) blank.add(tab[i]); 
            else vtors[tab[i][x]-'A'].add(tab[i]);
        } 
        for(int i=0;i<26;++i){
            if(vtors[i].getSize()>1) vtors[i].sort(x+1);
        }
        int k=0;
        for(int i=0;i<blank.getSize();++i){
            tab[k++]=blank[i];
        }
        for(int i=0;i<26;++i){
            for(int j=0;j<vtors[i].getSize();++j){
                tab[k++]=vtors[i][j];
            }
        }
    }
    
    friend ostream& operator<<(ostream &stream, const vector &v);
    friend istream& operator>>(istream &stream, const vector &v);
};

ostream& operator<<(ostream &stream, const vector &v){
    for(int i=0;i<v.size;++i){
        stream<<v.tab[i]<<' ';
    }
    return stream;
}

istream& operator>>(istream &stream, const vector &v){
    for(int i=0;i<v.size;++i){
        stream>>v.tab[i];
    }
    return stream;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    satori{
        int n; cin>>n;
        vector tab(n,n);
        cin>>tab; 
        //cout<<tab<<'\n';
        tab.sort(0);
        cout<<tab<<'\n';
    }

    return 0;
}