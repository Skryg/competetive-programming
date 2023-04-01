#include <iostream>

#define satori int z; cin>>z; while(z--)
#define MAX 1000000

using namespace std;

class Mono{
    long long value, deg;
    Mono *next, *prev;
public:
    Mono(long long val = 0, long long deg = 0){
        next = nullptr;
        prev = nullptr;
        value = val;
        this->deg = deg;
    }  

    friend class Poly;
};

class Poly{
    Mono *head, *tail;

    void insertAfter(Mono *mon, long long val, long long deg){
        Mono *nxt = mon->next;
        mon->next = new Mono(val, deg);
        mon->next->next = nxt;
        mon->next->prev = mon;
        nxt->prev = mon->next;
    }

    void remove(Mono *mon){
        mon->next->prev = mon->prev;
        mon->prev->next = mon->next;
        delete mon;
    }

    void refresh(){
        if(zero()) return;
        Mono *mon = head->next;
        while(mon!=tail){
            Mono *nxt = mon->next;
            if(mon->value == 0) remove(mon);
            mon = nxt;
        }

    }

    bool addMono(long long a,long long b, Mono *mon){
        if(b==0) return true;
        if(mon->deg < a && mon->next->deg > a){
            insertAfter(mon, b,a);
            return true;
        }
        else if(mon->deg == a){
            mon->value+=b;   
            return true;
        }
        return false;
    }

public:
    Poly(){
        head = new Mono(-1,-1);
        tail = new Mono(-1,MAX);
        head->next = tail;
        tail->prev = head;
    }
    
    bool zero(){
        return head->next == tail;
    }

    Mono* getHead(){
        return head;
    }
    Mono* getTail(){
        return tail;
    }

    void clean(){
        
        Mono *mon = head->next;
        while(mon->next !=nullptr){
            mon = mon->next;
            delete mon->prev;
        }
        head->next = tail;
        tail->prev = head;

    }

    void printAsc(){
        if(zero()) throw string("EMPTY");
        Mono *mon = head->next;
        if(mon->value < 0) cout<<'-';
        if(mon->deg == 0 || abs(mon->value) != 1) cout<<abs(mon->value);
        if(mon->deg > 0) cout<<'x';
        if(mon->deg >1) cout<<'^'<<mon->deg;
        mon = mon->next;
        while(mon->deg < MAX){
            if(mon->value > 0) cout<<'+';
            else cout<<'-';
            if(mon->deg == 0 || abs(mon->value) != 1)cout<<abs(mon->value);
            if(mon->deg > 0) cout<<'x';
            if(mon->deg >1) cout<<'^'<<mon->deg;

            mon = mon->next;
        }
        cout<<'\n';
    }

    void printDesc(){
        if(zero()) throw string("EMPTY");
        Mono *mon = tail->prev;
        if(mon->value<0) cout<<'-';
        if(mon->deg == 0 || abs(mon->value) != 1) cout<<abs(mon->value);
        if(mon->deg > 0) cout<<'x';
        if(mon->deg >1) cout<<'^'<<mon->deg;
        mon = mon->prev;
        while(mon->deg >= 0){
            if(mon->value > 0) cout<<'+';
            else cout<<'-';
            if(mon->deg == 0 || abs(mon->value) != 1) cout<<abs(mon->value);
            if(mon->deg > 0) cout<<'x';
            if(mon->deg >1) cout<<'^'<<mon->deg;

            mon = mon->prev;
        }
        cout<<'\n';
    }

    long long min(){
        if(zero()) throw string("ERROR");
        return head->next->value;
    }

    long long max(){
        if(zero()) throw string("ERROR");
        return tail->prev->value;
    }

    void addMono(long long a,long long b){
        Mono *mon = head;
        while(mon!= tail){
            if(addMono(a,b,mon)){
                if(mon->value == 0){
                    remove(mon);
                }
                break;
            }
            mon = mon->next;
        }
    }

    void derivative(){
        Mono *mon = head->next;
        while(mon!=tail){
            long long add = mon->deg*mon->value;
            addMono(mon->deg-1,add, mon->prev);
            mon->value = 0;
            mon = mon->next;
        }
        refresh();
    }

    void addPoly(Poly& p){
        Mono* mon1 = head;
        Mono* mon2 = p.getHead()->next;
        while(mon2->next != nullptr){
            long long val2 = mon2->value;
            long long deg2 = mon2->deg;

            while (mon1!=tail){
                if(addMono(deg2,val2, mon1)){
                    //mon1 = mon1->next;
                    break;  
                }
                mon1 = mon1->next;
            }
            mon2 = mon2->next;
        }
        refresh();
    }

    void multiply(long long a){
        Mono *mon = head->next;
        if(a==0){
            clean();
            return;
        }
        while(mon!=tail){
            mon->value*=a;
            mon = mon->next;
        }
    }

    void multiply(Poly &p){
        Poly mamSerdecznieDosycJuzTegoZadaniaIWcaleSieDobrzeNieBawilemRadzacSobieZTLE_AczkolwiekJakJuzWeszloToJestemCalkiemZadowolony;
        Mono* startGuest = mamSerdecznieDosycJuzTegoZadaniaIWcaleSieDobrzeNieBawilemRadzacSobieZTLE_AczkolwiekJakJuzWeszloToJestemCalkiemZadowolony.getHead();
        Mono* mon1 = head->next;
        bool checked = false;
        while(mon1 != tail){
            checked = false;
            Mono* guest = startGuest;
            Mono* mon2 = p.getHead()->next;
            long long v1 = mon1->value;
            long long d1 = mon1->deg;

            while(mon2->next != nullptr){
                long long vans = v1*mon2->value;
                long long dans = d1+mon2->deg;
                
                while(guest->next != nullptr){
                    if(addMono(dans, vans, guest)){
                        if(!checked){
                            checked = true;
                            startGuest = guest;
                        }
                        break;
                    }

                    guest = guest->next;
                }

                mon2=mon2->next; 
            }

            mon1 = mon1->next;
        }
        clean();
        head->next = mamSerdecznieDosycJuzTegoZadaniaIWcaleSieDobrzeNieBawilemRadzacSobieZTLE_AczkolwiekJakJuzWeszloToJestemCalkiemZadowolony.getHead()->next;
        head->next->prev = head;
        tail->prev = mamSerdecznieDosycJuzTegoZadaniaIWcaleSieDobrzeNieBawilemRadzacSobieZTLE_AczkolwiekJakJuzWeszloToJestemCalkiemZadowolony.getTail()->prev;
        tail->prev->next = tail;
        mamSerdecznieDosycJuzTegoZadaniaIWcaleSieDobrzeNieBawilemRadzacSobieZTLE_AczkolwiekJakJuzWeszloToJestemCalkiemZadowolony.getHead()->next = mamSerdecznieDosycJuzTegoZadaniaIWcaleSieDobrzeNieBawilemRadzacSobieZTLE_AczkolwiekJakJuzWeszloToJestemCalkiemZadowolony.getTail();
        mamSerdecznieDosycJuzTegoZadaniaIWcaleSieDobrzeNieBawilemRadzacSobieZTLE_AczkolwiekJakJuzWeszloToJestemCalkiemZadowolony.getTail()->prev = mamSerdecznieDosycJuzTegoZadaniaIWcaleSieDobrzeNieBawilemRadzacSobieZTLE_AczkolwiekJakJuzWeszloToJestemCalkiemZadowolony.getHead();
    
        refresh();
    }   

    ~Poly(){
        clean();
        delete head;
        delete tail;
    }

};

int idPoly(char x){
    return x-'A';
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    satori{
        Poly *polynoms = new Poly[26];
        int n; cin>>n;

        while(n--){
            string op;
            cin>>op;
            char c; cin>>c;
            int id=idPoly(c);

            try{
                if(op == "PRINT_ASC")
                    polynoms[id].printAsc();
                else if(op == "PRINT_DESC")
                    polynoms[id].printDesc();
                else if(op == "MIN")
                    cout<<polynoms[id].min()<<'\n';
                else if(op == "MAX")
                    cout<<polynoms[id].max()<<'\n';
                else if(op == "CLEAN"){
                    if(polynoms[id].zero()) throw string("EMPTY");
                    polynoms[id].clean();
                    cout<<"CLEAN OK\n";
                }
                else if(op == "ADD_MONO"){
                    int a,b; cin>>a>>b;
                    polynoms[id].addMono(a,b);
                    cout<<"ADD OK\n";
                }
                else if(op == "DERIVATIVE")
                    polynoms[id].derivative();
                else if(op == "ADD"){
                    char c2; cin>>c2;
                    int id2 = idPoly(c2);
                    polynoms[id].addPoly(polynoms[id2]);
                    cout<<"ADD OK\n";
                }
                else if(op == "MULTI_CONST"){
                    long long num; cin>>num;
                    polynoms[id].multiply(num);
                    cout<<"MULTI OK\n";
                }
                else if(op == "MULTI"){
                    char c2; cin>>c2;
                    int id2 = idPoly(c2);
                    polynoms[id].multiply(polynoms[id2]);
                    cout<<"MULTI OK\n";
                }

            }
            catch(string s){
                cout<<s<<'\n';
            }  
        }

        delete[] polynoms;
    }

    return 0;
}