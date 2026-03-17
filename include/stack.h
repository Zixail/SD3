#include <stdio.h>
#include <stdlib.h>

typedef struct staticStack {
    int* array;
    int size;
    int last;
} staticStack;

staticStack* createStaticStack(int size);

char pushStaticStack(staticStack* stack, char elm);

char popStaticStack(staticStack* stack);

void printStaticStack(staticStack* stack);

void freeStaticStack(staticStack* stack);


typedef struct dynamicStack {
    char data;
    struct dynamicStack *ptr_next;
} dynamicStack;

void pushDynamicStack(struct dynamicStack **head, const char symb);

char popDynamicStack(struct dynamicStack **head);

void printDynamicStack(struct dynamicStack *head);

void freeDynamicStack(struct dynamicStack **head);