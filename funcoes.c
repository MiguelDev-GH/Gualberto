#include "controller.h"

char* str(char string[]){
    int len;
    len = strlen(string);
    char *valor = malloc(len+1*sizeof(char));

    // Basicamente só faltava a gente passar o valor pra string ...
    strcpy(valor, string );
    return valor;
}

list newList(){
    list temp = {NULL,NULL, 0};
    return temp;
}

string lView(list* lInstance){
    struct element* el= lInstance->tail;
    for(int i=0; i<lInstance->length-1;i++){
        void* value = el->value;
    }
}

void lAppend(list* lInstance, void* value, int type){
    struct element *newElement = malloc(sizeof(struct element));
    if(newElement == NULL){
        return;
    }
    newElement->value = value;
    newElement->next = NULL;
    newElement->last = lInstance->head;

    lInstance->head = newElement;
    if(lInstance->tail==NULL){
        lInstance->tail = newElement;
    }
    lInstance->length = lInstance->length + 1;
}

struct element* lPop(list* lInstance){
    struct element* newHead = lInstance->head->last;
    void* lastHead = lInstance->head->value;
    if (lInstance->tail == lInstance->head){
        lInstance->tail == NULL;
    }
    free(lInstance->head);
    lInstance->head = newHead;
    lInstance->length = lInstance->length -1;
    return lastHead;
}