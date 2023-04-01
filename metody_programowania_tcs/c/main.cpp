#include<iostream>
#include<string>
using namespace std;
#include "solution.h"

class CmpInt {
   public:
      bool operator()(const int & a, const int & b) {return abs(a) < abs(b);  }
};

class CmpString {
   public:
      bool operator()(const string& a, const string& b)  {
        if (a.size() == b.size())  return a < b;
        return a.size() < b.size();
      }
};

int main() {
   ios_base::sync_with_stdio(false);
   int z, n;
   string s, t;

   cin >> z;
   while (z--) {
       cin >> n >> s >> t;
       if (t == "STACK") {
      switch(s[0]) {
         case 'I': { stackMin<int, CmpInt> S;    solveStack(S, n); break; }
         case 'S': { stackMin<string, CmpString> S; solveStack(S, n); break; }
         case 'D': { stackMin<double, greater<double> > S; solveStack(S, n); break; }
      }
       }
       else {      //if (t == "QUEUE")
      switch(s[0]) {
         case 'I': { queueMin<int, CmpInt> Q;    solveQueue(Q, n); break; }
         case 'S': { queueMin<string, CmpString> Q; solveQueue(Q, n); break; }
         case 'D': { queueMin<double, greater<double> > Q; solveQueue(Q, n); break; }
      }
       }
   }
   return 0;
}

