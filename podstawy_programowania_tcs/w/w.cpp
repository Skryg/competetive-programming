#include <iostream>
#define satori int z; cin>>z; while(z--)

using namespace std;

constexpr int STACK_MAX = 100000;

class stack{
    int size;
    int element;
    long long *tab;
public:
    stack();
    stack(int size);
    ~stack();
    void push(const long long &x);
    long long pop();
    long long top();
    bool empty();
    bool full();
    void clear();
    void resize(int n);
};


stack::stack(int size){
    this->size = size, element = 0;
    tab = new long long[size];
}
stack::stack() : stack(15){}
stack::~stack(){
    delete[] tab;
}
void stack::push(const long long &x){
    if(full()) throw string("PUSH");
    tab[element++]=x;
}
long long stack::pop(){
    if(empty()) throw string("POP");
    return tab[--element];
}
long long stack::top(){
    if(empty()) throw string("TOP");
    return tab[element-1];
}
bool stack::empty(){
    return (element==0);
}
bool stack::full(){
    return element==size;
}
void stack::clear(){
    element=0;
}
void stack::resize(int n){
    if(n<=size) return;
    size = n;
    long long *nt = new long long[n];
    for(int i=0;i<element;++i){
        nt[i] = tab[i];
    }
    delete[] tab;
    tab = nt;
}


int op(char c){
    if(c=='*' || c=='/') return 1;
    if(c=='+' || c=='-') return 0;
    if(c=='^') return 2;
    return -1;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long nums[26];
    satori{
        for(int i=0;i<26;++i) cin>>nums[i];
    
        int n; cin>>n;
        stack vars(STACK_MAX);

        for(int i=0;i<n;++i){
            string s;
            cin>>s;
            string onp;
            s = '('+s+')';
            for(int j=0;j<s.size();++j){
                if(s[j]>='a' && s[j]<='z') onp+=s[j];
                else if(s[j]=='(') vars.push('(');
                else if(s[j]==')'){
                    while(!vars.empty() && vars.top()!='('){
                        onp+=vars.pop();
                    }
                    vars.pop();
                }
                else{
                    while(!vars.empty() && op(s[j])<=op(vars.top())){
                        onp+=vars.pop();
                    }
                    vars.push(s[j]);
                }
            }
            while(!vars.empty()) onp+=vars.pop();
            cout<<onp<<'\n';

            for(int j=0;j<onp.size();++j){
                char c = onp[j];
                if(c>='a' && c<='z'){
                    vars.push(nums[c-'a']);
                }
                else{
                    long long arg2=vars.pop(),arg1=vars.pop();
                    long long x;
                    if(c=='+') x=arg1+arg2;
                    if(c=='-') x=arg1-arg2;
                    if(c=='*') x=arg1*arg2;
                    if(c=='/') x=(arg2 != 0 ? arg1/arg2 : 0);
                    if(c=='^'){
                        x=1;
                        for(int i=0;i<arg2;++i) x*=arg1;                        
                    }
                    vars.push(x);
                }
            }
            cout<<vars.pop()<<'\n';
        }

    }

    return 0;
}