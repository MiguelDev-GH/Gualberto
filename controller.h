#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <limits.h>
// Variáveis, Função e Structs

#define TYPE_STR 0
#define TYPE_SHORT 1
#define TYPE_INT 2
#define TYPE_LONG 3
#define TYPE_LONG_LONG 4
#define TYPE_FLOAT 5
#define TYPE_BOOL 6
#define TYPE_NULL 7
#define TYPE_LIST 8
#define true 1
#define false 0

// DADO INTELIGENTE QUE SABE O SEU PRÓPRIO VALOR
typedef struct data{
    short type;
    void* value;
} gen_data;
typedef gen_data* let;


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

// # DADOS INTELIGENTES E DINÂMICOS
// ## TIPO STRING
let str(char string[]);
// ## TIPO INT (DO SHORT ATÉ O LONG)
let integer(long long num);

// ALTERAR VALOR DE UMA VARÍAVEL INTELIGENTE
void nv(let var, let newValue);

let newList();
void print(int num_de_args,...);
typedef char* string;
void lAppend(let list_value, let data_value);
struct element* lPop(let list_value);
