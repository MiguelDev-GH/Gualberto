#include "controller.h"

let str(char string[]){
    int len;
    len = strlen(string);
    char *valor = malloc(len+1*sizeof(char));

    // Basicamente só faltava a gente passar o valor pra string ...
    strcpy(valor, string );
    let str_data;
    str_data->type = TYPE_STR;
    str_data->value = valor;
    return str_data;
}

list newList(){
    list temp = {NULL,NULL, 0};
    return temp;
}

void print(int num_de_args,...){
    va_list args;
    va_start(args,num_de_args);
    for (int i = 0; i<num_de_args;i++){
        let arg = va_arg(args,let);
        switch (arg->type)
        {
            case TYPE_STR : {
                printf("%s",(char*)arg->value);
                break;
            }
            case TYPE_INT : {
                printf("%i", (int*)arg->value);
                break;
            }
            case TYPE_BOOL : {
                if((int*)arg->value == false){
                    printf("%s","false");
                }else{
                    printf("%s","true");
                }
            }
            case TYPE_LIST : {
                list * this_list = (list*)arg->value;
                struct element * el_current = this_list->tail;
                for (int index=0; index<this_list->length;index++){
                    el_current->data;
                }    
            }
        default:
            break;
        }
    }
}

void lAppend(list* l_instance, let data_value){
    struct element *newElement = malloc(sizeof(struct element));
    if(newElement == NULL){
        return;
    }
    newElement->data = data_value;
    newElement->next = NULL;
    newElement->last = l_instance->head;

    l_instance->head = newElement;
    if(l_instance->tail==NULL){
        l_instance->tail = newElement;
    }
    l_instance->length = l_instance->length + 1;
}

struct element* lPop(list* l_instance){
    struct element* newHead = l_instance->head->last;
    void* lastHead = l_instance->head->data;
    if (l_instance->tail == l_instance->head){
        l_instance->tail == NULL;
    }
    free(l_instance->head);
    l_instance->head = newHead;
    l_instance->length = l_instance->length -1;
    return lastHead;
}