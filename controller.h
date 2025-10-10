#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Variáveis, Função e Struct

void pinto();

struct value{
    int valueInt;
    float valueFloat;
    struct string valueStr;
}

struct element{
    // Elemento anterior da lista
    struct element *last;
    // Próximo elemento da lista
    struct element *next;
    // Valor do Elemento
    struct value value;
}

struct lista{
    // Elemento no topo da lista
    struct element head;
    // Elemento no começo da lista
    struct element tail;
}
