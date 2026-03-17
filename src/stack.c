#include <stdio.h>
#include <stdlib.h>

typedef struct staticStack {
    char* array;
    int size;
    int last;
} staticStack;

staticStack* createStaticStack(int size){
    staticStack* stack = (staticStack*)malloc(sizeof(staticStack));
    stack->size = size;
    stack->array = (char*)malloc(size * sizeof(char));
    stack->last = 0;
    return stack;
}

char pushStaticStack(staticStack* stack, char elm){
    if (stack->last == stack->size){
        printf("Stack overflowed!\n");
        return -1;
    }

    stack->array[stack->last] = elm;
    stack->last++;
    return 0;
}

char popStaticStack(staticStack* stack){
    if (stack->last == 0){
        printf("Stack empty!\n");
        return ' ';
    }

    stack->last--;
    return stack->array[stack->last];
}

void printStaticStack(staticStack* stack){
    for(int i = stack->last - 1; i >= 0; --i){
        printf("%c --> ", stack->array[i]);
    }
    printf("NULL\n");
}

void freeStaticStack(staticStack* stack){
    if (stack != NULL){
        free(stack->array);
        free(stack);
    }
}

//  Динамичный стек
struct dynamicStack {
    char data;
    struct dynamicStack *ptr_next;
};

void pushDynamicStack(struct dynamicStack **head, const char symb)
{
    struct dynamicStack *new_ptr = (struct dynamicStack*)malloc(sizeof(struct dynamicStack));
    if (new_ptr == NULL) {
        printf("Memory allocation error!\n");
        return;
    }

    new_ptr->data = symb;
    new_ptr->ptr_next = *head;
    *head = new_ptr;
}

char popDynamicStack(struct dynamicStack **head)
{
    if (*head == NULL) {
        printf("dynamicStack is empty\n");
        return 1;
    }

    struct dynamicStack *temp = *head;
    char value  = temp->data;
    *head = temp->ptr_next;
    free(temp);

    return value;
}

void printDynamicStack(struct dynamicStack *head)
{
    struct dynamicStack *curr = head;
    while (curr != NULL) {
        printf("%c --> ", curr->data);
        curr = curr->ptr_next;
    }
    printf("NULL\n");
}

void freeDynamicStack(struct dynamicStack **head)
{
    while (*head != NULL) {
        struct dynamicStack *temp = *head;
        *head = temp->ptr_next;
        free(temp);
    }
}