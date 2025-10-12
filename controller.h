#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

// Variáveis, Função e Structs

#define TYPE_INT 1
#define TYPE_STR 0
#define TYPE_FLOAT 2
#define TYPE_BOOL 3
#define TYPE_NULL 4
#define TYPE_LIST 5
#define true 1
#define false 0
typedef struct data{
    int type;
    void* value;
}* let;

struct element{
    // Elemento anterior da lista
    struct element *last;
    // Próximo elemento da lista
    struct element *next;
    // Valor do Elemento
    let data;
};

// mds tem programação orientada a objetos em C .-.
typedef struct lista{
    // Elemento no topo da lista
    struct element *head;
    // Elemento no começo da lista
    struct element *tail;
    int length;
} list;

let str(char string[]);

list newList();
typedef char* string;
void lAppend(list* l_instance, let value);
struct element* lPop(list* l_instance);
string lView();