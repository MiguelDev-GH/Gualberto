#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Variáveis, Função e Structs

#define TYPE_INT = 1;
#define TYPE_STR = 0;
#define TYPE_FLOAT = 2;
#define TYPE_BOOL = 3;
#define TYPE_NULL = 4;
struct element{
    // Elemento anterior da lista
    struct element *last;
    // Próximo elemento da lista
    struct element *next;
    // Valor do Elemento (um ponteiro que não precisa especificar o tipo da varíavel q ele aponta)
    void *value;
};

struct lista{
    // Elemento no topo da lista
    struct element *head;
    // Elemento no começo da lista
    struct element *tail;
    int length;
};
typedef struct lista list;

char* str(char string[]);

list newList();
typedef char* string;
void lAppend(list* lInstance, void* value, int type);
struct element* lPop(list* lInstance);
string lView();