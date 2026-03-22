#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "deque.h"
#include "stack.h"

enum Program{
    PROG_EXIT = 0,
    STATIC_STACK_TEST = 1,
    DYNAMIC_STACK_TEST = 2,
    STATIC_DEQUE_TEST = 3,
    DYNAMIC_DEQUE_TEST = 4,
    PROG_NEED_CHOICE = 5
};

enum StackOperation{
    STACK_EXIT = 0,
    STACK_PUSH = 1,
    STACK_POP = 2,
    STACK_PRINT = 3,
    STACK_TEST = 4,
    STACK_NEED_CHOICE = 5
};

enum DequeOperation{
    DEQUE_EXIT = 0,
    DEQUE_PUSH_FRONT = 1,
    DEQUE_PUSH_BACK = 2,
    DEQUE_POP_FRONT = 3,
    DEQUE_POP_BACK = 4,
    DEQUE_PRINT = 5,
    DEQUE_TEST = 6,
    DEQUE_NEED_CHOICE = 7
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
        printf("\t|  4. Test               |\n");
        printf("\t|  0. Exit               |\n");
        printf("\t--------------------------\n");
        printf("Select: ");
        scanf("%d", &choice);

        if (choice < 0 || choice > 4) choice = 5;
        op = choice;
        
        switch(op){
            case (STACK_EXIT):
                freeStaticStack(stack);
                return;
            case (STACK_NEED_CHOICE):
                break;
            case (STACK_PUSH):
                int smbl;
                printf("Push: ");
                scanf(" %d", &smbl);
                pushStaticStack(stack, smbl);
                break;
            case (STACK_POP):
                int elm = popStaticStack(stack);
                printf("Pop: %d\n", elm);
                break;
            case (STACK_PRINT):
                printStaticStack(stack);
                break;
            case (STACK_TEST):
                testEfficiencyStaticStack(stack, size);
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
        printf("\t|  4. Test               |\n");
        printf("\t|  0. Exit               |\n");
        printf("\t--------------------------\n");
        printf("Select: ");
        scanf("%d", &choice);

        if (choice < 0 || choice > 4) choice = 5;
        op = choice;
        
        switch(op){
            case (STACK_EXIT):
                freeDynamicStack(&head);
                return;
            case (STACK_NEED_CHOICE):
                break;
            case (STACK_PUSH):
                int smbl;
                printf("Push: ");
                scanf(" %d", &smbl);
                pushDynamicStack(&head, smbl);
                break;
            case (STACK_POP):
                int elm = popDynamicStack(&head);
                printf("Pop: %d\n", elm);
                break;
            case (STACK_PRINT):
                printDynamicStack(head);
                break;
            case (STACK_TEST):
                testEfficiencyDynamicStack(&head);
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
        printf("\t|  6. Test               |\n");
        printf("\t|  0. Exit               |\n");
        printf("\t--------------------------\n");
        printf("Select: ");
        scanf("%d", &choice);

        if (choice < 0 || choice > 6) choice = 7;
        op = choice;
        
        switch(op){
            case (DEQUE_EXIT):
                freeStaticDeque(deque);
                return;
            case (DEQUE_NEED_CHOICE):
                break;
            case (DEQUE_PUSH_FRONT):
                int smblf;
                printf("Push: ");
                scanf(" %d", &smblf);
                pushHeadStaticDeque(deque, smblf);
                break;
            case (DEQUE_PUSH_BACK):
                int smblb;
                printf("Push: ");
                scanf(" %d", &smblb);
                pushTailStaticDeque(deque, smblb);
                break;
            case (DEQUE_POP_FRONT):
                int elmf = popHeadStaticDeque(deque);
                printf("Pop: %d\n", elmf);
                break;
            case (DEQUE_POP_BACK):
                int elmb = popTailStaticDeque(deque);
                printf("Pop: %d\n", elmb);
                break;
            case (DEQUE_PRINT):
                printStaticDeque(deque);
                break;
            case (DEQUE_TEST):
                testEfficiencyStaticDeque(deque, size);
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
        printf("\t|  6. Test               |\n");
        printf("\t|  0. Exit               |\n");
        printf("\t--------------------------\n");
        printf("Select: ");
        scanf("%d", &choice);

        if (choice < 0 || choice > 6) choice = 7;
        op = choice;
        
        switch(op){
            case (DEQUE_EXIT):
                freeDynamicDeque(&dq);
                return;
            case (DEQUE_NEED_CHOICE):
                break;
            case (DEQUE_PUSH_FRONT):
                int smblf;
                printf("Push: ");
                scanf(" %d", &smblf);
                pushFrontDynamicDeque(&dq, smblf);
                break;
            case (DEQUE_PUSH_BACK):
                int smblb;
                printf("Push: ");
                scanf(" %d", &smblb);
                pushBackDynamicDeque(&dq, smblb);
                break;
            case (DEQUE_POP_FRONT):
                int elmf = popFrontDynamicDeque(&dq);
                printf("Pop: %d\n", elmf);
                break;
            case (DEQUE_POP_BACK):
                int elmb = popBackDynamicDeque(&dq);
                printf("Pop: %d\n", elmb);
                break;
            case (DEQUE_PRINT):
                printDynamicDeque(&dq);
                break;
            case(DEQUE_TEST):
                testEfficiencyDynamicDeque(&dq);
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
        printf("\t|  2. Dynamic stack      |\n");
        printf("\t|  3. Static deque       |\n");
        printf("\t|  4. Dynamic deque      |\n");
        printf("\t|  0. Exit               |\n");
        printf("\t--------------------------\n");
        printf("Select: ");
        scanf("%d", &choice);

        if (choice < 0 || choice > 4) choice = 5;
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
        }
        op = PROG_NEED_CHOICE;
    }

    return 0;
}