//#include "funcoes.c"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*

void criarString(char *c){
    struct string valor = {99,"joaocomprapao1234567890"}
}

*/

int len;

char* criarString(char string[]){

    len = strlen(string);
    char *valor;
    valor = malloc(sizeof(strlen));
    return valor;
}

int main(){

    char* coco = criarString("merda");
    printf("%s",coco);

    return 0;
}