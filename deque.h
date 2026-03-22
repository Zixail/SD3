#ifndef DEQUE_H
#define DEQUE_H

typedef struct staticDeque {
    int* array;
    int size;
    int head;
    int tail;
} staticDeque;

staticDeque* createStaticDeque(int size);

int pushHeadStaticDeque(staticDeque* deque, int elm);

int pushTailStaticDeque(staticDeque* deque, int elm);

int popHeadStaticDeque(staticDeque* deque);

int popTailStaticDeque(staticDeque* deque);

void printStaticDeque(staticDeque* deque);

void freeStaticDeque(staticDeque* deque);

void testEfficiencyStaticDeque(staticDeque* deque, int size);


typedef struct dynamicDeque {
    int data;
    struct dynamicDeque *prev;
    struct dynamicDeque *next;
} dynamicDeque;

typedef struct coord {
    struct dynamicDeque *head;
    struct dynamicDeque *tail;
} coord;

void pushFrontDynamicDeque(struct coord *dq, const int value);

void pushBackDynamicDeque(struct coord *dq, const int value);

int popFrontDynamicDeque(struct coord  *dq);

int popBackDynamicDeque(struct coord *dq);

void printDynamicDeque(struct coord *dq);

void freeDynamicDeque(struct coord *dq);

void testEfficiencyDynamicDeque(struct coord *dq);

#endif