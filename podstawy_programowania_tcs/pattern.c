int x = -1;
long long suma = 0;
for(int i=0;i<n;++i){
    while(x+1<n && (input[x+1]%k==0 || b>0 || x<i-1)){
        x++;
        if(input[x]%k!=0) b--;
        suma+=input[x];      
        
        //zmiana max jesli potrzeba
    }
    suma-=(long long)input[i];
    if(input[i]%k!=0) b++;
}
