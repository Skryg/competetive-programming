#include <stdio.h>

#define satori int z; scanf("%d", &z); while(z--)
#define DIV 30

int main(){
    int workers[300][10000/DIV+1];
    char text[10001];
    int spec[300]={0};
    satori{
        int n,m,t,u,tasks;
        scanf("%d %d %d %d %d", &n, &m, &t, &u, &tasks);

        for(int i=0;i<n;++i){
            scanf("%s", text);
            for(int j=0;j<m;++j){
                workers[i][j/DIV] += (text[j]-'0')*(1LL<<(j%DIV));
            }
        }

        for(int i=0;i<n;++i){
            for(int k=i+1;k<n;++k){
                int count = 0;
                for(int j=0;j<m;j+=DIV){
                    long long x = workers[i][j/DIV]&workers[k][j/DIV];
                    count+=__builtin_popcount(x);
                    /*for(int l=0;l<DIV;++l){
                        if((x>>l)&1LL==1LL) count++;
                    }*/
                }
                if(count >= t) {
                    spec[i]++;
                    spec[k]++;
                }
            }

        }
        int universal=0, ans=1, ans1;
        for(int i=0;i<n;++i) if(spec[i]>=u) universal++;
        ans1 = universal;
        //num of workers^tasks
        for(int i=0;i<31;++i){
            if((1<<i)&tasks){
                ans*=universal;
                ans%=1000;    
            }
            universal = (universal*universal)%1000;
        }
        printf("%d %.3d\n",ans1,ans);

        for(int i=0;i<n;++i){
            spec[i]=0;
            for(int j=0;j<m;j+=DIV){
                workers[i][j/DIV]=0;
            }
        }
    }

    return 0;
}