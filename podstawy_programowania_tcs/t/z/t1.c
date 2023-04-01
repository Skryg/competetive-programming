#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

int Same(char *wordG, char * tab, int size){
    int diff = 0;
    for(int i = 0; i < size; i++){
        if(wordG[i] != tab[i])
            diff++;
        if(diff > 1)
            return 0;
    }
    return 1;
}

int plusOne(char *wordG, char * tab, int size){
    int diff = 0, i = 0, j = 0;
    while(i < size && j < size+1){
        if(wordG[i] != tab[j]){
            diff++;
            j++;
            if(diff > 1)
                return 0;
        }
        else{
            i++;
            j++;
        }
        
    }
    return 1;
}

int minusOne(char *wordG, char * tab, int size){
    int diff = 0, i = 0, j = 0;
        while(i < size && j < size-1){
            if(wordG[i] != tab[j]){
                diff++;
                i++;
                if(diff > 1)
                    return 0;
            }
            else{
                i++;
                j++;
            }
            
        }
        return 1;
}

int Good(char *wordG, char * tab, int i, int size){
    if(i == size)
       return Same(wordG, tab, size);
    if(i == size + 1)
        return plusOne(wordG, tab, size) ;
    if(i == size - 1)
        return minusOne(wordG, tab, size);
    return 0;
}


int main(int n, char ** t){
    FILE* fileRead = fopen(t[1], "r");
    FILE* fileWrite = fopen(t[2], "w");
    if (fileRead == NULL)
        return 1;
    char *tab = malloc(40*sizeof(char));
    char temp, oldTemp = 0, word = 0;
    int i = 0, j = 0, size = 0, enter = 1, com = 0, howMany = 0, goodWord = 0, howManyGood = 0;
    while(t[3][j] != '\0'){
        t[3][j] = tolower(t[3][j]);
        size++;
        j++;
    }
    while(!feof(fileRead)){

        temp = fgetc(fileRead);

        //na male literki

        //komentarze
        if(temp == '*' && oldTemp == '/'){
            com++;
            //printf("\n%c %c wololo\n", temp, oldTemp);
            oldTemp = 0;
            continue;
        }
        if( com > 0 && oldTemp == '*' && temp == '/'){
            com--;
            oldTemp = 0;
            continue;
        }

        //pomin wszystko jesli kompetarz
        if(com != 0){
            oldTemp = temp;
            continue;
        }
        
        if(temp == '\n') 
            enter++;
        
        temp = tolower(temp);
        
        //koniec slowa
        if(word == 1 && !('a' <= temp && temp <= 'z') && !('0' <= temp && temp <= '9')){
            oldTemp = temp;
            char nie=0;
            if(!feof(fileRead)){
                nie = fgetc(fileRead);
                ungetc(nie, fileRead);
            }
            if(temp == '/' && nie == '*')
                continue;
            tab[i]='\0';
            //printf("%s ", tab);
            goodWord = Good(t[3], tab, i, size);
            //printf("%s ", tab);
            if(goodWord == 1){
                howManyGood++;
                fprintf(fileWrite, "Linia %d: %s\n", enter, tab);
            }
            i = 0;
            word = 0;
            continue;
        }


        //czy slowo sie zaczyna
        if(word == 0){
            oldTemp = temp;
            if('a' <= temp && temp <= 'z'){
                word = 1;
                tab[i] = temp;
                i++;
                howMany++;
                continue;
            }
        }

        //zliczanie słowa na razie ignorujemy znaki
        if(word == 1){
            tab[i] = temp;
            i++;
            oldTemp = temp;
        }
        
    }
    fprintf(fileWrite, "Wyrazy: %d\n", howMany);
    fprintf(fileWrite, "Wyrazy specjalne: %d\n", howManyGood);
    free(tab);
    fclose(fileRead);
    fclose(fileWrite);
}