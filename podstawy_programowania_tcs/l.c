#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int cmd_code(char cmd[]){
    if(strcmp("NULL", cmd)==0) return 0;
    if(strcmp("STOP", cmd)==0) return 1;
    if(strcmp("LOAD", cmd)==0) return 2;
    if(strcmp("STORE", cmd)==0) return 3;
    if(strcmp("JUMP", cmd)==0) return 4;
    if(strcmp("JNEG", cmd)==0) return 5;
    if(strcmp("JZERO", cmd)==0) return 6;
    if(strcmp("ADD", cmd)==0) return 8;
    if(strcmp("SUB", cmd)==0) return 9;
    if(strcmp("AND", cmd)==0) return 12;
    if(strcmp("OR", cmd)==0) return 13;
    if(strcmp("NOT", cmd)==0) return 14;
    if(strcmp("XOR", cmd)==0) return 15;
    if(strcmp("SHL", cmd)==0) return 10;
    if(strcmp("SHR", cmd)==0) return 11;    
}

int type_code(char c){
    if(c == '.') return 0;
    if(c == '@') return 1;
    if(c == '*') return 2;
    if(c == '+') return 3;
}

int sign_num(int code){
    return (code >> 15);
}

int command_num(int code){
    return ((code >> 11)&15);
}

int type_num(int code){
    return ((code >> 9)&3);
}

int address_num(int code){
    return (code&((1<<9)-1));
}

int commands[512];
int cmd_bool[512];
int wow[512];
void pmc(){
    int PC=0,AC=0,OP=0;
    while(PC < 512 && PC >= 0){
        int code = commands[PC];
        ++PC;
        int sign = sign_num(code), cmd = command_num(code),
        type = type_num(code), address = address_num(code);
        //printf("%d ", cmd);
        if(cmd == 0) continue;
        if(cmd == 1) return;
        if(sign) address = -address;
        if(type == 0) OP = address;
        else if(type == 1) OP = commands[address];
        else if(type == 2) OP = commands[commands[address]];
        else OP = commands[AC+address];

        if(cmd == 2) AC = OP;
        if(cmd == 3){
            commands[OP] = AC;
            cmd_bool[OP] = 0;
        }
        if(cmd == 4) PC = OP;
        if(cmd == 5 && AC < 0) PC = OP;
        if(cmd == 6 && AC == 0) PC = OP;
        if(cmd == 8) AC+=OP;
        if(cmd == 9) AC-=OP;
        if(cmd == 12) AC&=OP;
        if(cmd == 13) AC|=OP;
        if(cmd == 14) AC=(~AC);
        if(cmd == 15) AC^=OP;
        if(cmd == 10) AC<<=OP;
        if(cmd == 11) AC>>=OP;
        
    }
    //printf("\n");
}


int main(){
    int buf_size = 256;
    char buffer[buf_size];
    
    char* buf = buffer;
    

    char command[10], c; 
    int z; 
    scanf("%d", &z);       
    while(z--){
        for(int i=0;i<512;++i){
            commands[i]=0;
            cmd_bool[i]=0;
            wow[i]=0;
        }

        int n,k; scanf("%d %d",&n,&k);
        int num, address;
        
        for(int i=0;i<n;++i){
            scanf("%d: %s", &num, command);
            int code = 0;
            if (command[0]>='A' && command[0] <= 'Z'){
                scanf(" %c %d%*[^\n]",&c, &address);
                //printf("%d: %s %c %d\n", num, command, c, address);
                if(address < 0) code++;
                code <<= 4;
                code += cmd_code(command);
                code <<= 2;
                code += type_code(c);
                code <<= 9;
                code += (address < 0 ? -address : address);
                cmd_bool[num] = 1;
            }
            else{
                scanf("%*[^\n]");
                code = atoi(command); 
                //printf("%d: %d\n", num, code);
            }
            commands[num] = code;
            
        }
        
        for(int i=0;i<k;++i){
            scanf("%d", &num);
            //printf("%d ", num);
            wow[num] = 1;
        }
        

        pmc();
        for(int i=0;i<512;++i){
            if(wow[i]) printf("%d ",commands[i]);
        }
        printf("\n");
    }   
    
    return 0;
}