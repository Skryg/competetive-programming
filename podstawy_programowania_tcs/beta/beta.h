#include <iostream>
#define cerr if(0) cerr
#define MAX 202
using namespace std;

class number{
    long long num[MAX]={0};
    int up;
    bool minus=false;
    void normalize(){
        for(int i=0; i<MAX;++i){
            if(num[i]) up = i+1;
        }
        for(int i=0;i<=up;++i){
            if(num[i] >= 0){
                if(i==up && num[i]) up++;
                if(num[i]/10){
                    num[i+1]+=num[i]/10;
                    num[i]%=10;
                }
            }
            else{
                long long hm = num[i]/10;
                if(num[i]%10) hm--;
                num[i+1]+=hm;
                num[i]+=(-hm)*10;
            }
        }
        while(up && !num[up-1]){
            up--;
        }
        if(up == 0) minus = 0;
        
    }

public:
    bool isZero() const{
        return up==0;
    }

    number abs(number n){
        n.minus = 0;
        return n;
    }

    number(string s = ""){
        if(s.size()==0){
            up = 0;
            return;
        }
        if(s[0]=='-') minus = 1;
        up = (minus ? s.size()-1 : s.size());
    
        for(int i=0;i<up;++i){
            num[i] = s[s.size()-1-i]-'0';
        } 
        normalize();    
    }

    number operator+=(const number &A){
        if(minus != A.minus){
            //cerr<< *this<< ' '<<A<<'\n';
            if((abs(*this)<abs(A)) == -1){
                //mniejesze lewe
                cerr<<"LEFT\n";

                number x = *this;
                number y = A;
                for(int i=0;i<max(y.up, x.up);++i){
                    y.num[i]-=x.num[i];
                }
                //y.minus = !y.minus;
                (*this) = y;

            
            }
            else{
                //lewy wiekszy
                for(int i=0;i<max(A.up, up);++i){
                    num[i]-=A.num[i];
                }
            }
            
        }
        else{
            for(int i=0;i<max(A.up, up); ++i){
                num[i]+=A.num[i];
            }
        }
        normalize();   
        return *this;     
    }

    number operator-=(const number &A){
        number x  = A;
        x.minus = !x.minus;
        (*this)+=x;
        return *this;
    }


    number operator++(){
        if(minus){
            num[0]--;
        }
        else num[0]++;

        normalize();
        return *this;
    }

    number operator++(int){
        number n = *this;
        if(minus){
            num[0]--;
        }
        else num[0]++;
        normalize();
        return n;
    }

    number operator--(){
        if(isZero()){
            minus=1;
        }
        if(minus){
            num[0]++;
        }
        else num[0]--;

        normalize();
        return *this;
    }
    
    number operator--(int){
        number n = *this;
        cerr<<this->up<<'\n';
        if(isZero()){
            minus=1;
            cerr<<"ZERO " << n<<'\n';
        }
        if(minus){
            num[0]++;
        }
        else num[0]--;
        normalize();
        return n;
    }


    friend int operator<(const number &A, const number &B);
    friend number operator*(const number &A, const number &B);
    friend ostream& operator<<(ostream &stream, const number &A);
    friend istream& operator>>(istream &stream, const number &A);
    
};

int operator<(const number &A, const number &B){
    if(A.minus){
        if(!B.minus) return -1;
        else{
            //both minus, if A > B, return -1 else if eq return 0 else return 1
            if(A.up > B.up) return -1;
            if(A.up < B.up) return 1;
            
            for(int i=A.up; i>=0; --i){
                if(A.num[i]!=B.num[i]){
                    if(A.num[i]>B.num[i]) return -1;
                    else return 1;
                }
            }
            return 0;
        }
    }
    else{
        if(B.minus) return 1;
        else{
            //both >0, if A < B return -1.. etc
            if(A.up < B.up) return -1;
            if(A.up > B.up) return 1;
            
            for(int i=A.up; i>=0;--i){
                if(A.num[i]!=B.num[i]){
                    if(A.num[i]<B.num[i]) return -1;
                    else return 1;
                }
            }
            return 0;
        }   
    }
}   
number operator*(const number &A, const number &B){
    number x;
    if(A.minus != B.minus) x.minus = 1;
    else x.minus = 0;
    for(int i=0;i<A.up;++i){
        for(int j=0;j<B.up;++j){
            x.num[i+j]+=A.num[i]*B.num[j];
        }
    }
    x.normalize();
    return x;
}
ostream& operator<<(ostream &stream, const number &A){
    if(A.isZero()) stream<<0;
    else{
        if(A.minus) stream<<'-';
        for(int i=A.up-1;i>=0; i--){
            stream<<A.num[i];
        }
    }
    return stream;
}
istream& operator>>(istream &stream, number &A){
    string s; stream>>s;
    A = number(s);
    return stream;
}

