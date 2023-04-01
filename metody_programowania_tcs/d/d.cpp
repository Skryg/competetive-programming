#include <bits/stdc++.h>
#define satori int z; cin>>z; while(z--)

using namespace std;

template<typename T>
class node{
public:
    node<T> *p[2]={nullptr, nullptr};
    T value;

    node<T>(){}

    node<T>(T value){
        this->value = value;
    }
};

template<typename T>
class doubleList{
    node<T> *begin,*end;
    string name;

    node<T>* detach(node<T> *element){
        int a = (element->p[0]->p[0] != element); // p[0] has this element in p[a]
        int b = (element->p[1]->p[0] != element); // p[1] has this element in p[b]
        assert(a==0 || a==1);
        assert(b==0 || b==1);

        element->p[0]->p[a]=element->p[1];
        element->p[1]->p[b]=element->p[0];

        element->p[0]=nullptr;
        element->p[1]=nullptr;
        return element;
    }

    void attachBeginEnd(node<T> *begin, node<T> *n){
        int a = (begin->p[0]->p[0]!=begin);
        n->p[0]=begin;
        n->p[1]=begin->p[0];
        begin->p[0]->p[a] = n;
        begin->p[0]=n;
    }

public:
    doubleList<T>(){
        begin = new node<T>();
        end = new node<T>();
        begin->p[0]=end;
        end->p[0]=begin;
    }

    doubleList<T>(string name) : doubleList<T>{}{
        this->name = name;
    }

    ~doubleList<T>(){
        delete begin;
        delete end;
    }

    string getName(){
        return name;
    }

    node<T> *getBegin(){
        return begin;
    }

    node<T> *getEnd(){
        return end;
    }

    void addFirst(T& name){
        node<T> *n = new node<T>(name);
        attachBeginEnd(begin, n);

    }
    void addFirst(node<T>& n){
        //detach(&n);
        attachBeginEnd(begin, &n);
    }
    void addLast(T& name){
        node<T> *n = new node<T>(name);
        attachBeginEnd(end, n);
    }
    void addLast(node<T>& n){
        //detach(&n);
        attachBeginEnd(end, &n);
    }
    node<T>* detachFront(){
        return detach(begin->p[0]);
    }
    node<T>* detachLast(){
        return detach(end->p[0]);
    }
    void reverse(){
        int a = (begin->p[0]->p[0] != begin); // begin is in p[a] of the next
        int b = (end->p[0]->p[0] != end); // end is in p[b] of the previous

        swap(begin->p[0]->p[a], end->p[0]->p[b]);
        swap(begin->p[0], end->p[0]);

    }
    void unionn(doubleList<T>& L){
        int a = (end->p[0]->p[0] != end); // end is in p[a] of the previous
        int b = (L.begin->p[0]->p[0] != L.begin); // L.begin is in p[b] of the next

        end->p[0]->p[a] = L.begin->p[0];
        L.begin->p[0]->p[b] = end->p[0];

        swap(end, L.end);
        L.begin->p[0] = L.end;
        L.end->p[0] = L.begin;
    }
    void clean(){
        while(begin->p[0] != end){
            node<T> *n = detach(begin->p[0]);
            delete n;
        }
    }

    bool empty(){
        return begin->p[0] == end;
    }

};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    satori{
        int n; cin>>n;  
        doubleList<string> *lists[20]={nullptr};
        while(n--){
            string command, train1;
            cin>>command>>train1;

            if(command=="NEW"){
                string person; cin>>person;
                int i=-1;
                while(lists[++i] !=nullptr){}
                lists[i] = new doubleList<string>(train1);
                lists[i]->addFirst(person);
            }
            else if(command=="BACK"){
                string person; cin>>person;
                int i=-1;
                while(lists[++i]==nullptr || lists[i]->getName()!=train1){}
                lists[i]->addLast(person);
            }
            else if(command=="FRONT"){
                string person; cin>>person;
                int i=-1;
                while(lists[++i]==nullptr || lists[i]->getName()!=train1){}
                lists[i]->addFirst(person);
            }
            else if(command=="PRINT"){
                int i=-1;
                while(lists[++i]==nullptr || lists[i]->getName()!=train1){}
                node<string> *prev = lists[i]->getBegin();
                node<string> *act = prev->p[0];
                node<string> *end = lists[i]->getEnd();
                cout<<'"'<<lists[i]->getName()<<"\":\n";
                while(act!=end){
                    cout<<act->value;
                    node<string> *oldAct = act;

                    act =act->p[(prev == act->p[0])];
                    prev = oldAct;
                    if(act != end) cout<<"<-";
                }
                cout<<'\n';

            }
            else if(command == "REVERSE"){
                int i=-1;
                while(lists[++i]==nullptr || lists[i]->getName()!=train1){}
                lists[i]->reverse();
            }
            else if(command == "UNION"){
                string train2; cin>>train2;
                int i=-1;
                while(lists[++i]==nullptr || lists[i]->getName()!=train1){}
                int j=-1;
                while(lists[++j]==nullptr || lists[j]->getName()!=train2){}
                lists[i]->unionn(*lists[j]);
                delete lists[j];
                lists[j] = nullptr; 
            }
            else if(command == "DELFRONT"){
                string train2; cin>>train2;
                int j=-1;
                while(lists[++j]==nullptr || lists[j]->getName()!=train2){}
                node<string> *n = lists[j]->detachFront();
                if(lists[j]->empty()){
                    delete lists[j];
                    lists[j] = nullptr;
                }
                int i=-1;
                while(lists[++i] !=nullptr){}
                lists[i] = new doubleList<string>(train1);
                lists[i]->addFirst(*n);
            }
            else if(command == "DELBACK"){
                string train2; cin>>train2;
                int j=-1;
                while(lists[++j]==nullptr || lists[j]->getName()!=train1){}
                node<string> *n = lists[j]->detachLast();
                if(lists[j]->empty()){
                    delete lists[j];
                    lists[j] = nullptr;
                }
                int i=-1;
                while(lists[++i] !=nullptr){}
                lists[i] = new doubleList<string>(train2);
                lists[i]->addFirst(*n);
            }

        }
        for(int i=0;i<20;++i){
            if(lists[i]==nullptr) continue;

            lists[i]->clean();
            delete lists[i];
            lists[i] = nullptr;
        }        

    }

    return 0;
}