// PADRÕES
// NOMEAMENTO DE VARIAVEIS E STRUCTS = snake_case
// NOMEAMENTO DE CONSTANTES = SCREAMING_SNAKE_CASE
// NOMEAMENTO DE FUNÇÕES = canonCase

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "controller.h"

int main(){
    let coco = integer(150000);
    nv(coco,str("valor alterado!")); // trocando uma varíavel com valor inteiro e colocando string... será que isso ainda é c?


    let lista_generica = newList();
    lAppend(lista_generica, coco);
    lAppend(lista_generica,integer(10000000000LL));
    lAppend(lista_generica,boolean(false));
    lAppend(lista_generica, coco);
    nv(coco,str("Alterado 2"));

    let lista_generica2 = newList();
    lAppend(lista_generica2, str("gato"));
    lAppend(lista_generica2, str("cao"));
    lAppend(lista_generica,lista_generica2); // lista dentro da lista pra testar a eficácia
    print(1,lista_generica);
    print(1,lGet(lista_generica,4));
    return 0;
}