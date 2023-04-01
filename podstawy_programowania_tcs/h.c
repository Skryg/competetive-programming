#include <stdio.h>
#include <string.h>

#define satori int z; scanf("%d",&z); while(z--)

char contestants[1000000][13];
char candidates[1000000][13];

int main(){
    char candidate[13]="";
    char master[13] = "";
    char arch[13] = "";
    satori{
        strcpy(master, "BRAK");
        strcpy(candidate,"BRAK");
        strcpy(arch, "BRAK");

        int n; scanf("%d", &n);
        for(int i=0;i<n;++i) scanf("%s",contestants[i]);
        int leader_id=0;
        for(int i=0;i<n;++i){
            if(strcmp(contestants[i], candidate)==0){
                leader_id++;
            }
            else{
                if(!leader_id){
                    strcpy(candidate, contestants[i]);
                    leader_id = 1;
                }
                else{
                    leader_id--;
                }
            }
            if(leader_id) strcpy(candidates[i], candidate);
            else strcpy(candidates[i], "BRAK");
        }
        int cnt=0;
        for(int i=0;i<n;++i) if(strcmp(contestants[i], candidate)==0) cnt++;
        if(n/2 < cnt) strcpy(master, candidate);

        strcpy(candidate,"BRAK");
        leader_id=0;
        for(int i=0;i<n;++i){
            if(strcmp(candidates[i], candidate)==0){
                leader_id++;
            }
            else{
                if(!leader_id){
                    strcpy(candidate, candidates[i]);
                    leader_id=1;
                }
                else{
                    leader_id--;
                }
            }
        }
        cnt = 0;
        int cnt2 = 0;
        for(int i=0;i<n;++i){
            if(strcmp(candidate, contestants[i])==0) cnt2++;
            if((i+1)/2 < cnt2) cnt++; 
        }
        if(n/2 < cnt){
            strcpy(arch, candidate);
        }
        printf("%s %s\n", master, arch);

    }
    return 0;
}