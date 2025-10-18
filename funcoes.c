#include "controller.h"

// # CRIADO TIPAGEM DE DADO PARA CRIAÇÃO DE VARÍAVEIS DINÂMICAS E LISTAS INTELIGENTES 
// CRIANDO UMA ESTRUTURA MAIS "DINÂMICA" COMO A DO PYTHON POR EXEMPLO ONDE O PRÓPRIO DADO RECONHECE SEU TIPO
// POR ENQUANTO O PONTO DE ATENÇÃO É Q SE QUEM NÃO ESTÁ USANDO NÃO COLOCAR UM FREE VAI FICAR OCUPANDO ESPAÇO DO CÓDIGO

// ## CRIA O TIPO DE DADO STR; AJUSTADO O TAMANHO DINÂMICAMENTE
let str(char string[]){
    int len, size;
    len = strlen(string);
    size = len+1*sizeof(char);
    char *valor = malloc(size);

    // Basicamente só faltava a gente passar o valor pra string ...
    strcpy(valor, string);
    let str_data = malloc(sizeof(gen_data));
    str_data->type = TYPE_STR;
    str_data->value = valor;
    return str_data;
}

// ## CRIANDO O TIPO DE DADO PARA INTEIROS
let integer(){
    // tem que fazer código ainda p-p to cansado dps faço
    // basicamente o objetivo é ver dinamicamente quantos bytes seria necessário para salvar esse valor ex.: int, long int, long long;
}

// ## CRIANDO A LISTA E O TIPO DE DADO DA LISTA
let newList(){
    // Isto gerá a instância da lista
    list* temp = malloc(sizeof(list));
    temp->head = NULL;
    temp->tail = NULL;
    temp->length = 0;
    // Isso garante a tipagem da lista definida
    let l_data = malloc(sizeof(gen_data));
    l_data->type = TYPE_LIST;
    l_data->value = temp; 
    return l_data;
}

// # PRINTS DINÂMICOS
// ELES FUNCIONAM COM DADOS DO TIPO LET 

// ## UM PRINT Q LÊ UM DADO E NÃO PRECISA DE USAR OS PARAMETROS DE TIPO DE DADO ex.: %s,$i
void printCommonData(let data){
    switch (data->type)
    {
        // Auto explicativo
        case TYPE_STR : {
            printf("%s",(char*) data->value);
            break;
        }
        case TYPE_INT : {
            printf("%d",*(int*) data->value);
            break;
        }
        case TYPE_FLOAT : {
            printf("%f",*(float*) data->value);
            break;
        }
        case TYPE_BOOL : {
            if(data->value == false){
                printf("%s","false");
            }else{
                printf("%s","true");
            }
            break;
        }

        case TYPE_LIST : {
            list * this_list = data->value;
            struct element *el_current = this_list->tail;
            printf("%s","[");
            for (int index=0; index<this_list->length;index++){
                int type;
                type = el_current->data->type;
                if(type == TYPE_STR){
                    printf("%c",'"');
                    printCommonData(el_current->data);
                    printf("%c",'"');

                }else{
                    printCommonData(el_current->data);
                }
             
             
                if(index != this_list->length-1){
                    printf("%s", ",");
                }
                el_current = el_current->next;
            }    
            printf("%s","]");
            break;
        }

        default:{
            printf("%s", "Unknown");
        }
    }
}

// ## PRINT SUPREMO: SEMELHANTE AO PRINT DO PYTHON, VOCÊ SÓ PRECISA JOGAR OS DADOS
// NESSE PRINT VOCÊ PRECISA DEFINIR O NÚMERO DE DADOS Q VAI COLOCA
void print(int num_de_args,...){
    // é basicamente o *args de Python
    va_list args;
    va_start(args,num_de_args);
    for (int i = 0; i<num_de_args;i++){
        let arg = va_arg(args,let);
        printCommonData(arg);
    }
    printf("%s","\n");
}

// # FUNÇÕES DE GERENCIAMENTO DE LISTAS

// ## ADICIONAR NOVO ELEMENTO AO FINAL DA LISTA
void lAppend(let list_value, let data_value){
    struct element *newElement = malloc(sizeof(struct element));
    list *l_instance = list_value->value;
    if(newElement == NULL){
        return;
    }
    newElement->data = data_value;
    newElement->next = NULL;
    newElement->last = l_instance->head;
    if(l_instance->head!= NULL){
        l_instance->head->next = newElement;
    }
    l_instance->head = newElement;
    if(l_instance->tail==NULL){ // Se for o primeiro elemento da lista, ele será a tail e a head
        l_instance->tail = newElement;
    }
    l_instance->length = l_instance->length + 1;
}

// ## REMOVER ÚLTIMO ELEMENTO DA LISTA
struct element* lPop(let list_value){
    list* l_instance = list_value->value;
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