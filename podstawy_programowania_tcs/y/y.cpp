#include <iostream>
#define satori int z; cin>>z; while(z--)

using namespace std;

class person{
    string name;
    int age, p;
    person *next;

    void reverse(){
        if(next == nullptr) return;
        person *n = next->next;
        next->next = this;
        next = n;
    }

public:
    person(){
        name = "", age=-1, p=-1, next = nullptr;
    }
    person(string name, int age, int p){
        this->name = name;
        this->age = age;
        this->p = p;
        next = nullptr;
    }

    void print(){
        cout<<name<<' '<<age<<' '<<p<<'\n';
    }
    friend class list;
};


class list{
    person *head;

    void push(person *nxt, person p){
        if(nxt->next == nullptr) nxt->next = new person(p);
        else{
            person *help = nxt->next;
            nxt->next = new person(p);
            nxt->next->next = help;
        }
    }

    void pop(person *nxt){
        if(nxt->next == nullptr) throw string("ERROR");
        person *help = nxt->next->next;
        nxt->next->next = nullptr;
        delete nxt->next;
        nxt->next = help;
    }

    void rev(person *p){
        if(p->next != nullptr) rev(p->next);
        p->reverse();
    }

public:
    list(){
        head = new person();
    }
    ~list(){
        clean();
        delete head;
    }

    bool empty(){
        return head->next == nullptr;
    }

    void push_back(person p){
        person *next = head;
        while(next->next != nullptr) next = next->next;
        next->next = new person(p);
    }

    void push_front(person p){
        push(head,p);
    }

    void insert(int posit, person p){
        person *nxt = head;
        while(--posit){
            if(nxt->next == nullptr) throw string("ERROR");
            nxt = nxt->next;
        }
        push(nxt, p);
    }

    person* back(){
        person *next = head;
        while(next->next != nullptr) next = next->next;
        return next;
    }

    void pop_front(){
        pop(head);
    }

    void pop(string name, int age){
        person *nxt = head;
        int cnt=0;
        while(nxt->next != nullptr){
            if(nxt->next->name == name && nxt->next->age == age){
                pop(nxt);
                cnt++;
            }
            else nxt = nxt->next;
        }
        if(!cnt) throw string("ERROR");
    }
    void pop(int p){
        person *nxt = head;
        while(nxt->next != nullptr){
            if(nxt->next->p == p) pop(nxt);
            else nxt = nxt->next;
        }
    }


    void pop_back(){
        if(empty()) throw string("ERROR");
        person *next = head;
        while(next->next->next != nullptr) next = next->next;
        pop(next);
    }

    void print(){
        if(empty()) throw string("EMPTY");
        person *help = head;
        while(help->next!=nullptr){
            help->next->print();
            help = help->next;
        }
    }

    void age(person *p,int a){
        if(empty()) return;
        if(p->next->next != nullptr) age(p->next, a);
        if(p->next->age >= a){
            person x = *(p->next);
            x.next = nullptr;
            push_front(x);
            pop(p);
        } 
    }

    void age(int a){
        push_front(person("",-1,200000));
        age(head, a);
        pop(200000);
    }

    void reverse(){
        if(empty()) throw string("EMPTY");
        push_back(person());
        person *bck = back();
        rev(head);
        head = bck;
        pop_back();
    }
    void clean(person *p){
        if(p->next!=nullptr) clean(p->next);
        delete p;
    }
    void clean(){
        if(head->next!=nullptr) clean(head->next);
        head->next = nullptr;
    }
};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    satori{
        int n,w; cin>>n>>w;
        list l;

        while(n--){
            string command;
            cin>>command;
            try{
                if(command == "NEW"){
                    string name; cin>>name;
                    int age, p; cin>>age>>p;

                    if(age>=w) l.push_front(person(name,age,p));
                    else l.push_back(person(name,age,p));
                }
                else if(command == "INSERT"){
                    string name;
                    int age, number, p; 
                    cin>>name>>age>>number>>p;
                    l.insert(number, person(name, age, p));
                }
                else if(command == "BUYING"){
                    l.pop_front();
                }
                else if(command == "RESIGNATION"){
                    l.pop_back();
                }
                else if (command == "DELETE"){
                    string name; int age;
                    cin>>name>>age;
                    l.pop(name, age);
                }
                else if(command == "PRINT"){
                    l.print();
                }
                else if(command == "REVERSE"){
                    l.reverse();
                }
                else if(command == "CHANGE"){
                    int age; cin>>age;
                    if(age <= w){ 
                        l.age(age); 
                    }
                    w=age;
                }
                else if(command == "LACK"){
                    int p; cin>>p;
                    l.pop(p);
                }
                else if(command == "CLEAN"){
                    l.clean();
                }
            }
            catch(string e){
                cout<<e<<'\n';
            }
        }
    }

    return 0;
}