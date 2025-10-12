// PADRÕES
// NOMEAMENTO DE VARIAVEIS E STRUCTS = snake_case
// NOMEAMENTO DE CONSTANTES = SCREAMING_SNAKE_CASE
// NOMEAMENTO DE FUNÇÕES = canonCase

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "controller.h"

int main(){
    let coco = str("merda");
    // Ta funfando p-p

    let lista_generica = newList();
    lAppend(lista_generica, coco);
    let lista_generica2 = newList();
    lAppend(lista_generica2, str("gato"));
    lAppend(lista_generica2, str("cao"));

    lAppend(lista_generica,lista_generica2); // lista dentro da lista pra testar a eficácia
    print(1,lista_generica);

    return 0;
}