#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct staticDeque {
    int* array;
    int size;
    int head;
    int tail;
} staticDeque;

staticDeque* createStaticDeque(int size){
    staticDeque* deque = (staticDeque*)malloc(sizeof(staticDeque));
    deque->size = size + 1;
    deque->array = (int*)malloc(deque->size * sizeof(int));
    deque->head = 0;
    deque->tail = 0;
    return deque;
}

int pushHeadStaticDeque(staticDeque* deque, int elm){
    if ((deque->head - deque->tail + deque->size + 1) % deque->size == 0){
        printf("deque overflowed!\n");
        return -1;
    }
    deque->head = (deque->head + 1) % deque->size;
    deque->array[deque->head] = elm;
    return 0;
}

int pushTailStaticDeque(staticDeque* deque, int elm){
    if ((deque->head - deque->tail + deque->size + 1) % deque->size == 0){
        printf("deque overflowed!\n");
        return -1;
    }
    deque->array[deque->tail] = elm;
    deque->tail = (deque->tail - 1 + deque->size) % deque->size;
    return 0;
}

int popHeadStaticDeque(staticDeque* deque){
    if (deque->head == deque->tail){
        printf("deque empty!\n");
        return ' ';
    }

    int smbl = deque->array[deque->head];
    deque->head = (deque->head - 1 + deque->size) % deque->size;
    return smbl;
}

int popTailStaticDeque(staticDeque* deque){
    if (deque->head == deque->tail){
        printf("deque empty!\n");
        return ' ';
    }

    deque->tail = (deque->tail + 1) % deque->size;
    int smbl = deque->array[deque->tail];
    return smbl;
}

void printStaticDeque(staticDeque* deque){
    if (deque->head != deque->tail){
        printf("NULL --> ");
        int i = deque->head;
        while (i != deque->tail) {
            printf("%d -> ", deque->array[i]);
            
            i = (i - 1 + deque->size) % deque->size;
        }
    }
    printf("NULL\n");
}

void freeStaticDeque(staticDeque* deque){
    if (deque != NULL){
        free(deque->array);
        free(deque);
    }
}

void testEfficiencyStaticDeque(staticDeque* deque, int size){
    clock_t start = clock();
    for (int i = 0; i < size; i++) {
        pushTailStaticDeque(deque, 10);
    }
    for (int i = 0; i < size+1; i++) {
        popTailStaticDeque(deque);
    }
    clock_t end = clock();
    double time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Время выполнения: %f сек\n", time_used);
}

//  Динамичный Дек

typedef struct dynamicDeque {
    int data;
    struct dynamicDeque *prev;
    struct dynamicDeque *next;
} dynamicDeque;

typedef struct coord {
    struct dynamicDeque *head;
    struct dynamicDeque *tail;
} coord;

void pushFrontDynamicDeque(struct coord *dq, const int value)
{
    struct dynamicDeque *new_ptr = (struct dynamicDeque*)malloc(sizeof(struct dynamicDeque));
    if (new_ptr == NULL) {
        printf("Memory allocation error!\n");
        return;
    }

    new_ptr->data = value;
    new_ptr->prev = NULL;
    new_ptr->next = dq->head;

    if (dq->head == NULL) {
        dq->tail = new_ptr;
    }
    else {
        dq->head->prev = new_ptr;
    }
    dq->head = new_ptr;
}

void pushBackDynamicDeque(struct coord *dq, const int value)
{
    struct dynamicDeque *new_ptr = (struct dynamicDeque*)malloc(sizeof(struct dynamicDeque));
    if (new_ptr == NULL) {
        printf("Memory allocation error!\n");
        return;
    }

    new_ptr->data = value;
    new_ptr->next = NULL;
    new_ptr->prev = dq->tail;

    if (dq->head == NULL) {
        dq->head = new_ptr;
    }
    else {
        dq->tail->next = new_ptr;
    }
    dq->tail = new_ptr;

}

int popFrontDynamicDeque(struct coord  *dq)
{
    if (dq->head == NULL) {
        printf("deque is empty\n");
        return -1;
    }

    struct dynamicDeque *temp = dq->head;
    int value = temp->data;
    dq->head = dq->head->next;
    if (dq->head == NULL) {
        dq->tail = NULL;
    }
    else {
        dq->head->prev = NULL;
    }
    free(temp);

    return value;
}

int popBackDynamicDeque(struct coord *dq)
{
    if (dq->head == NULL) {
        printf("deque is empty\n");
        return -1;
    }

    struct dynamicDeque *temp = dq->tail;
    int value = temp->data;
    dq->tail = dq->tail->prev;
    if (dq->tail == NULL) {
        dq->head = NULL;
    }
    else {
        dq->tail->next = NULL;
    }
    free(temp);

    return value;
}

void printDynamicDeque(struct coord *dq)
{
    struct dynamicDeque *curr = dq->head;
    if (dq->head != NULL){
        printf("NULL --> ");
        while (curr != NULL) {
            printf("%d --> ", curr->data);
            curr = curr->next;
    }
    }
    printf("NULL\n");
}

void freeDynamicDeque(struct coord *dq)
{
    while (dq->head != NULL) {
        struct dynamicDeque *temp = dq->head;
        dq->head = temp->next;
        free(temp);
    }
    dq->tail = NULL;
}

void testEfficiencyDynamicDeque(struct coord *dq)
{
    clock_t start = clock();
    for (int i = 0; i < 10000000; i++) {
        pushBackDynamicDeque(dq, 10);
    }
    for (int i = 0; i < 10000001; i++) {
        popBackDynamicDeque(dq);
    }
    clock_t end = clock();
    double time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Время выполнения: %f сек\n", time_used);
}