#include <stdio.h>
#include <stdlib.h>

typedef struct staticDeque {
    char* array;
    int size;
    int head;
    int tail;
} staticDeque;

staticDeque* createStaticDeque(int size){
    staticDeque* deque = (staticDeque*)malloc(sizeof(staticDeque));
    deque->size = size + 1;
    deque->array = (char*)malloc(deque->size * sizeof(char));
    deque->head = 0;
    deque->tail = 0;
    return deque;
}

char pushHeadStaticDeque(staticDeque* deque, char elm){
    if ((deque->head - deque->tail + deque->size + 1) % deque->size == 0){
        printf("deque overflowed!\n");
        return -1;
    }
    deque->head = (deque->head + 1) % deque->size;
    deque->array[deque->head] = elm;
    return 0;
}

char pushTailStaticDeque(staticDeque* deque, char elm){
    if ((deque->head - deque->tail + deque->size + 1) % deque->size == 0){
        printf("deque overflowed!\n");
        return -1;
    }
    deque->array[deque->tail] = elm;
    deque->tail = (deque->tail - 1 + deque->size) % deque->size;
    return 0;
}

char popHeadStaticDeque(staticDeque* deque){
    if (deque->head == deque->tail){
        printf("deque empty!\n");
        return ' ';
    }

    char smbl = deque->array[deque->head];
    deque->head = (deque->tail - 1 + deque->size) % deque->size;
    return smbl;
}

char popTailStaticDeque(staticDeque* deque){
    if (deque->head == deque->tail){
        printf("deque empty!\n");
        return ' ';
    }

    deque->tail = (deque->tail + 1) % deque->size;
    char smbl = deque->array[deque->tail];
    return smbl;
}

void printStaticDeque(staticDeque* deque){
    if ((deque->head - deque->tail + deque->size + 1) % deque->size != 1){
        printf("NULL --> ");
        for(int i = deque->head; i != deque->tail; i = (i - 1 + deque->size) % deque->size){
            printf("%c --> ", deque->array[i]);
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

//  Динамичный Дек

typedef struct dynamicDeque {
    char data;
    struct dynamicDeque *prev;
    struct dynamicDeque *next;
} dynamicDeque;

typedef struct coord {
    struct dynamicDeque *head;
    struct dynamicDeque *tail;
} coord;

void pushFrontDynamicDeque(struct coord *dq, const char value)
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

void pushBackDynamicDeque(struct coord *dq, const char value)
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

char popFrontDynamicDeque(struct coord  *dq)
{
    if (dq->head == NULL) {
        printf("deque is empty\n");
        return -1;
    }

    struct dynamicDeque *temp = dq->head;
    char value = temp->data;
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

char popBackDynamicDeque(struct coord *dq)
{
    if (dq->head == NULL) {
        printf("deque is empty\n");
        return -1;
    }

    struct dynamicDeque *temp = dq->tail;
    char value = temp->data;
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
            printf("%c --> ", curr->data);
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