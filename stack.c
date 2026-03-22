#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct staticStack {
    int* array;
    int size;
    int last;
} staticStack;

staticStack* createStaticStack(int size){
    staticStack* stack = (staticStack*)malloc(sizeof(staticStack));
    stack->size = size;
    stack->array = (int*)malloc(size * sizeof(int));
    stack->last = 0;
    return stack;
}

int pushStaticStack(staticStack* stack, int elm){
    if (stack->last == stack->size){
        printf("Stack overflowed!\n");
        return -1;
    }

    stack->array[stack->last] = elm;
    stack->last++;
    return 0;
}

int popStaticStack(staticStack* stack){
    if (stack->last == 0){
        printf("Stack empty!\n");
        return ' ';
    }

    stack->last--;
    return stack->array[stack->last];
}

void printStaticStack(staticStack* stack){
    for(int i = stack->last - 1; i >= 0; --i){
        printf("%d --> ", stack->array[i]);
    }
    printf("NULL\n");
}

void freeStaticStack(staticStack* stack){
    if (stack != NULL){
        free(stack->array);
        free(stack);
    }
}

void testEfficiencyStaticStack(staticStack* stack, int size){
    clock_t start = clock();
    for (int i = 0; i < size; i++) {
        pushStaticStack(stack, 10);
    }
    for (int i = 0; i < size+1; i++) {
        popStaticStack(stack);
    }
    clock_t end = clock();
    double time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Время выполнения: %f сек\n", time_used);
}


//  Динамичный стек
typedef struct dynamicStack {
    int data;
    struct dynamicStack *ptr_next;
} dynamicStack;

void pushDynamicStack(dynamicStack **head, int symb)
{
    dynamicStack *new_ptr = (struct dynamicStack*)malloc(sizeof(struct dynamicStack));
    if (new_ptr == NULL) {
        printf("Memory allocation error!\n");
        return;
    }

    new_ptr->data = symb;
    new_ptr->ptr_next = *head;
    *head = new_ptr;
}

int popDynamicStack(dynamicStack **head)
{
    if (*head == NULL) {
        printf("dynamicStack is empty\n");
        return 1;
    }

    dynamicStack *temp = *head;
    int value  = temp->data;
    *head = temp->ptr_next;
    free(temp);

    return value;
}

void printDynamicStack(struct dynamicStack *head)
{
    struct dynamicStack *curr = head;
    while (curr != NULL) {
        printf("%d --> ", curr->data);
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

void testEfficiencyDynamicStack(struct dynamicStack **head) {
    clock_t start = clock();
    for (int i = 0; i < 10000000; i++) {
        pushDynamicStack(head, 10);
    }
    for (int i = 0; i < 10000001; i++) {
        popDynamicStack(head);
    }
    clock_t end = clock();
    double time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Время выполнения: %f сек\n", time_used);
}