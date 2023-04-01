#include <bits/stdc++.h>

using namespace std;

const int rozmiar =10e6+9;
int kmp[rozmiar];
int w, t;
string text;
string wz="ABCDEF";
int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0); 
	cin>>t;

	while (t--) {
        cin>>text;
        string slowo='$'+wz+'#'+text+text;
        kmp[0]=-1;
        int spr_poz;
        int dl_wz=wz.size();
        int wynik=0;
        for (int akt_poz=2; akt_poz<slowo.size()-text.size()+wz.size(); akt_poz++) {
            spr_poz=kmp[akt_poz-1];
            while (spr_poz >=0 && slowo[akt_poz]!=slowo[spr_poz+1])
                spr_poz=kmp[spr_poz];

            kmp[akt_poz]=spr_poz+1;
            if (kmp[akt_poz]==dl_wz)
                wynik++; }
        cout<<wynik<<"\n"; }

        }