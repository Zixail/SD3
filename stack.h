#ifndef STACK_H
#define STACK_H

typedef struct staticStack {
    int* array;
    int size;
    int last;
} staticStack;

staticStack* createStaticStack(int size);

int pushStaticStack(staticStack* stack, int elm);

int popStaticStack(staticStack* stack);

void printStaticStack(staticStack* stack);

void freeStaticStack(staticStack* stack);

void testEfficiencyStaticStack(staticStack* stack, int size);


typedef struct dynamicStack {
    int data;
    struct dynamicStack *ptr_next;
} dynamicStack;

void pushDynamicStack(dynamicStack **head, int symb);

int popDynamicStack(dynamicStack **head);

void printDynamicStack(struct dynamicStack *head);

void freeDynamicStack(struct dynamicStack **head);

void testEfficiencyDynamicStack(struct dynamicStack **head);

#endif