#ifndef DEQUE_H
#define DEQUE_H

typedef struct staticDeque {
    char* array;
    int size;
    int head;
    int tail;
} staticDeque;

staticDeque* createStaticDeque(int size);

char pushHeadStaticDeque(staticDeque* deque, char elm);

char pushTailStaticDeque(staticDeque* deque, char elm);

char popHeadStaticDeque(staticDeque* deque);

char popTailStaticDeque(staticDeque* deque);

void printStaticDeque(staticDeque* deque);

void freeStaticDeque(staticDeque* deque);

//  Дина
typedef struct dynamicDeque {
    char data;
    struct dynamicDeque *prev;
    struct dynamicDeque *next;
} dynamicDeque;

typedef struct coord {
    struct dynamicDeque *head;
    struct dynamicDeque *tail;
} coord;

void pushFrontDynamicDeque(struct coord *dq, const char value);

void pushBackDynamicDeque(struct coord *dq, const char value);

char popFrontDynamicDeque(struct coord  *dq);

char popBackDynamicDeque(struct coord *dq);

void printDynamicDeque(struct coord *dq);

void freeDynamicDeque(struct coord *dq);

#endif