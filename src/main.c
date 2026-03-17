#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "stack.h"
#include "deque.h"

enum Program{
    PROG_EXIT = 0,
    STATIC_STACK_TEST = 1,
    DYNAMIC_STACK_TEST = 2,
    STATIC_DEQUE_TEST = 3,
    DYNAMIC_DEQUE_TEST = 4,
    CART_COLLECTOR = 5,
    PROG_NEED_CHOICE = 6
};

enum StackOperation{
    STACK_EXIT = 0,
    STACK_PUSH = 1,
    STACK_POP = 2,
    STACK_PRINT = 3,
    STACK_NEED_CHOICE = 4
};

enum DequeOperation{
    DEQUE_EXIT = 0,
    DEQUE_PUSH_FRONT = 1,
    DEQUE_PUSH_BACK = 2,
    DEQUE_POP_FRONT = 3,
    DEQUE_POP_BACK = 4,
    DEQUE_PRINT = 5,
    DEQUE_NEED_CHOICE = 6
};

void testStaticStack(){
    int size;
    printf("Select stack size: ");
    scanf("%d", &size);
    staticStack* stack = createStaticStack(size);

    enum StackOperation op = STACK_NEED_CHOICE;
    while(op == STACK_NEED_CHOICE){
        int choice;
        printf("\t--------------------------\n");
        printf("\t|  Choose option         |\n");
        printf("\t|  1. Push               |\n");
        printf("\t|  2. Pop                |\n");
        printf("\t|  3. Print              |\n");
        printf("\t|  0. Exit               |\n");
        printf("\t--------------------------\n");
        printf("Select: ");
        scanf("%d", &choice);

        if (choice < 0 || choice > 3) choice = 4;
        op = choice;
        
        switch(op){
            case (STACK_EXIT):
                freeStaticStack(stack);
                return;
            case (STACK_NEED_CHOICE):
                break;
            case (STACK_PUSH):
                char smbl;
                printf("Push: ");
                scanf(" %c", &smbl);
                pushStaticStack(stack, smbl);
                break;
            case (STACK_POP):
                char elm = popStaticStack(stack);
                printf("Pop: %c\n", elm);
                break;
            case (STACK_PRINT):
                printStaticStack(stack);
                break;
        }
        op = STACK_NEED_CHOICE;
    }
}

void testDynamicStack(){
    dynamicStack *head = NULL;

    enum StackOperation op = STACK_NEED_CHOICE;
    while(op == STACK_NEED_CHOICE){
        int choice;
        printf("\t--------------------------\n");
        printf("\t|  Choose option         |\n");
        printf("\t|  1. Push               |\n");
        printf("\t|  2. Pop                |\n");
        printf("\t|  3. Print              |\n");
        printf("\t|  0. Exit               |\n");
        printf("\t--------------------------\n");
        printf("Select: ");
        scanf("%d", &choice);

        if (choice < 0 || choice > 3) choice = 4;
        op = choice;
        
        switch(op){
            case (STACK_EXIT):
                freeDynamicStack(&head);
                return;
            case (STACK_NEED_CHOICE):
                break;
            case (STACK_PUSH):
                char smbl;
                printf("Push: ");
                scanf(" %c", &smbl);
                pushDynamicStack(&head, smbl);
                break;
            case (STACK_POP):
                char elm = popDynamicStack(&head);
                printf("Pop: %c\n", elm);
                break;
            case (STACK_PRINT):
                printDynamicStack(head);
                break;
        }
        op = STACK_NEED_CHOICE;
    }
}

void testStaticDeque(){
    int size;
    printf("Select stack size: ");
    scanf("%d", &size);
    staticDeque* deque = createStaticDeque(size);

    enum DequeOperation op = DEQUE_NEED_CHOICE;
    while(op == DEQUE_NEED_CHOICE){
        int choice;
        printf("\t--------------------------\n");
        printf("\t|  Choose option         |\n");
        printf("\t|  1. Push Front         |\n");
        printf("\t|  2. Push Back          |\n");
        printf("\t|  3. Pop Front          |\n");
        printf("\t|  4. Pop Back           |\n");
        printf("\t|  5. Print              |\n");
        printf("\t|  0. Exit               |\n");
        printf("\t--------------------------\n");
        printf("Select: ");
        scanf("%d", &choice);

        if (choice < 0 || choice > 5) choice = 6;
        op = choice;
        
        switch(op){
            case (DEQUE_EXIT):
                freeStaticDeque(deque);
                return;
            case (DEQUE_NEED_CHOICE):
                break;
            case (DEQUE_PUSH_FRONT):
                char smblf;
                printf("Push: ");
                scanf(" %c", &smblf);
                pushHeadStaticDeque(deque, smblf);
                break;
            case (DEQUE_PUSH_BACK):
                char smblb;
                printf("Push: ");
                scanf(" %c", &smblb);
                pushTailStaticDeque(deque, smblb);
                break;
            case (DEQUE_POP_FRONT):
                char elmf = popHeadStaticDeque(deque);
                printf("Pop: %c\n", elmf);
                break;
            case (DEQUE_POP_BACK):
                char elmb = popTailStaticDeque(deque);
                printf("Pop: %c\n", elmb);
                break;
            case (DEQUE_PRINT):
                printStaticDeque(deque);
                break;
        }
        op = DEQUE_NEED_CHOICE;
    }
}

void testDynamicDeque(){
    coord dq;
    dq.head = NULL;
    dq.tail = NULL;

    enum DequeOperation op = DEQUE_NEED_CHOICE;
    while(op == DEQUE_NEED_CHOICE){
        int choice;
        printf("\t--------------------------\n");
        printf("\t|  Choose option         |\n");
        printf("\t|  1. Push Front         |\n");
        printf("\t|  2. Push Back          |\n");
        printf("\t|  3. Pop Front          |\n");
        printf("\t|  4. Pop Back           |\n");
        printf("\t|  5. Print              |\n");
        printf("\t|  0. Exit               |\n");
        printf("\t--------------------------\n");
        printf("Select: ");
        scanf("%d", &choice);

        if (choice < 0 || choice > 5) choice = 6;
        op = choice;
        
        switch(op){
            case (DEQUE_EXIT):
                freeDynamicDeque(&dq);
                return;
            case (DEQUE_NEED_CHOICE):
                break;
            case (DEQUE_PUSH_FRONT):
                char smblf;
                printf("Push: ");
                scanf(" %c", &smblf);
                pushFrontDynamicDeque(&dq, smblf);
                break;
            case (DEQUE_PUSH_BACK):
                char smblb;
                printf("Push: ");
                scanf(" %c", &smblb);
                pushBackDynamicDeque(&dq, smblb);
                break;
            case (DEQUE_POP_FRONT):
                char elmf = popFrontDynamicDeque(&dq);
                printf("Pop: %c\n", elmf);
                break;
            case (DEQUE_POP_BACK):
                char elmb = popBackDynamicDeque(&dq);
                printf("Pop: %c\n", elmb);
                break;
            case (DEQUE_PRINT):
                printDynamicDeque(&dq);
                break;
        }
        op = DEQUE_NEED_CHOICE;
    }
}

int main(void){
    enum Program op = PROG_NEED_CHOICE;
    while(op == PROG_NEED_CHOICE){

        int choice;
        printf("\t--------------------------\n");
        printf("\t|  Choose option         |\n");
        printf("\t|  1. Static stack       |\n");
        printf("\t|  2. Dinamic stack      |\n");
        printf("\t|  3. Static deque       |\n");
        printf("\t|  4. Dinamic deque      |\n");
        printf("\t|  5. Cart collector     |\n");
        printf("\t|  0. Exit               |\n");
        printf("\t--------------------------\n");
        printf("Select: ");
        scanf("%d", &choice);

        if (choice < 0 || choice > 5) choice = 6;
        op = choice;
        
        switch(op){
            case (PROG_EXIT):
                return 0;
            case (PROG_NEED_CHOICE):
                break;
            case (STATIC_STACK_TEST):
                testStaticStack();
                break;
            case (DYNAMIC_STACK_TEST):
                testDynamicStack();
                break;
            case (STATIC_DEQUE_TEST):
                testStaticDeque();
                break;
            case (DYNAMIC_DEQUE_TEST):
                testDynamicDeque();
                break;
            case (CART_COLLECTOR):
                break;
        }
        op = PROG_NEED_CHOICE;
    }

    return 0;
}