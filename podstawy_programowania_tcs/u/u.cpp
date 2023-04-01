#include <bits/stdc++.h>

#define satori int z; cin>>z; while(z--)

using namespace std;

void output(int **tab, int n, int m){
    cout<<setfill('0');
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            cout<<setw(3)<<tab[i][j]<<' ';
        }
        cout<<'\n';
    }
}

void multiply(int** tab, int n1, int m1, int** tab2, int n2, int m2){
    cout<<setfill('0');
    int* row = new int[m2];

    for(int i=0; i<n1;++i){
        for(int j=0;j<m2;++j) row[j]=0;
        for(int k=0;k<n2;++k){
            for(int j=0;j<m2;++j){
                row[j] += (tab[i][k]*tab2[k][j]);
                row[j]%=1000;
            }
            
        }
        for(int j=0;j<m2;++j) cout<<setw(3)<<row[j]<<' ';
        cout<<'\n';
    }
    delete[] row;
}

void power(int pow, int** tab, int n){
    short int** ptab = new short int*[n];
    for(int i=0;i<n;++i) ptab[i] = new short int[n];
    short int** ptab2 = new short int*[n];
    for(int i=0;i<n;++i) ptab2[i] = new short int[n];
    int* row = new int[n];

    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            ptab[i][j] = (short int)tab[i][j];
            if(i==j) tab[i][j]=1;
            else tab[i][j]=0;
        }
    }
    
    int cnt=30, p=1;
    while(cnt--){
        if(p & pow){
            for(int i=0;i<n;++i){
                for(int j=0;j<n;++j) row[j]=0;
                for(int k=0;k<n;++k){
                    
                    for(int j=0;j<n;++j){
                        row[j] += (tab[i][k]*ptab[k][j]);
                        row[j]%=1000;
                    }
                }
                for(int j=0;j<n;++j) tab[i][j] = row[j];
            }
        }

        for(int i=0;i<n;++i){
            for(int j=0;j<n;++j) row[j] = 0;
            for(int k=0; k<n;++k){
                
                for(int j=0;j<n;++j){
                    row[j] += (int)ptab[i][k]*ptab[k][j];
                    row[j]%=1000;
                }
            }
            for(int j=0;j<n;++j) ptab2[i][j]=(short int)row[j];

        }
        for(int i=0;i<n;++i) for(int j=0;j<n;++j) ptab[i][j] = ptab2[i][j];

        p<<=1;
    }
    for(int i=0;i<n;++i){
        delete[] ptab[i];
        delete[] ptab2[i];
    }
    delete[] ptab;
    delete[] ptab2;
    delete[] row;

    output(tab, n,n);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    satori{
        string s; cin>>s;
        if(s == "MULTIPLY"){
            int n1,m1; cin>>n1>>m1;
            int **tab = new int*[n1];
            for(int i=0;i<n1;++i) tab[i] = new int[m1];    
            for(int i=0;i<n1;++i)
                for(int j=0;j<m1;j++)
                    cin>>tab[i][j];
            //output(tab, n1,m1);
            int n2,m2; cin>>n2>>m2;
            int **tab2 = new int*[n2];
            for(int i=0;i<n2;++i) tab2[i] = new int[m2];
            for(int i=0;i<n2;++i) for(int j=0;j<m2;++j) cin>>tab2[i][j];

            if(m1 == n2) multiply(tab, n1, m1, tab2, n2, m2);
            else cout<<"ERROR MULTIPLY\n";
            

            for(int i=0;i<n1;++i) delete[] tab[i];
            delete[] tab;
            for(int i=0;i<n2;++i) delete[] tab2[i];
            delete[] tab2;
        }
        else{
            int pow; cin>> pow;
            int n,m; cin>>n>>m;
            int **tab = new int*[n];
            for(int i=0;i<n;++i) tab[i] = new int[m];
            for(int i=0;i<n;++i) for(int j=0;j<m;++j) cin>>tab[i][j];
            if(n==m) power(pow, tab, n);
            else cout<<"ERROR POWER\n";

            for(int i=0;i<n;++i) delete[] tab[i];
            delete[] tab;
        }
    }

    return 0;
}