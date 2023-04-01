#include <iostream>
#include "beta.h"

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  string s;
  number C;
  number D("123");
  cout << C << " " << D << endl;

  int z;
  cin >> z;
  while (z--) {
     cin >> s;
     if ( (s[0] >= '0' && s[0] <= '9') || (s.size()>0 && s[1] >= '0' && s[1] <= '9')) {
        number A(s);
        cin >> s;
        if (s[0] == '+') cout << ++A << endl;
        else cout << --A << endl;
     }
   else {
      number A;
      number B;
      cin >> A;

      if (s.size() == 1) {
         cin >> B;
         switch (s[0]) {
            case '+' : A += B;  cout << A << endl; break;
            case '-' : A -= B;  cout << A << endl; break;
            case '*' : C = A * B;  cout << C << endl; break;
            case '<' : cout << (A < B) << endl;
         }
      }
      else
         switch (s[0]) {
           case '+' : cout << A++ << " "; cout << A << endl; break;
           case '-' : cout << A-- << " "; cout << A << endl; break;
        }
      }
  }
}
