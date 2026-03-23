#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "deque.h"
#include "stack.h"

typedef struct Rails{
    int capacity;
    int count;
    staticDeque* cars;
} Rails;

typedef struct Train{
    dynamicStack* cars;
    int countCur;
    int countPlan;
    int* plan;
} Train;

typedef struct Station{
    Train train;
    Rails* rails;
    int count;
} Station;


Station* initStation(const char* path){
    Station* station = (Station*)malloc(sizeof(Station));

    FILE* fp = fopen(path, "r");

    fscanf(fp, "%d", &station->count);

    station->rails = (Rails*)malloc(station->count * sizeof(Rails));

    for(int i = 0; i < station->count; ++i){
        fscanf(fp, "%d", &station->rails[i].capacity);
        fscanf(fp, "%d", &station->rails[i].count);
        station->rails[i].cars = createStaticDeque(station->rails[i].capacity);

        for(int j = 0; j < station->rails[i].count; ++j){
            int tmp;
            fscanf(fp, "%d", &tmp);
            pushTailStaticDeque(station->rails[i].cars, tmp);
        }
    }

    station->train.cars = NULL;
    fscanf(fp, "%d", &station->train.countPlan);
    station->train.countCur = 0;
    station->train.plan = (int*)malloc(station->train.countPlan * sizeof(int));
    for(int i = 0; i < station->train.countPlan; ++i){
        fscanf(fp, "%d", &station->train.plan[i]);
    }

    fclose(fp);

    return station;
}

char isFormed(Station* station){
    if (station->train.countCur == station->train.countPlan){
        char flag = 1;
        for(int i = 0; i < station->train.countPlan; ++i){
            dynamicStack* ptr = station->train.cars;
            while(ptr != NULL){
                if (station->train.plan[i] == ptr->data){
                    flag = 1;
                    break;
                }
                else{
                    ptr = ptr->ptr_next;
                    flag = 0;
                }
            }
            if (flag == 0) return 0;
        }
        return 1;
    }
    return 0;
}

int getSide(Rails* rails, Train* train) {
    if (rails->cars->head == rails->cars->tail) return 0;

    int fromHead = -1;
    int fromTail = -1;
    int totalCount = 0;

    int i = rails->cars->head;
    int currentStep = 1;

    while (i != rails->cars->tail) {
        char isNeeded = 0;
        for (int j = 0; j < train->countPlan; j++) {
            if (rails->cars->array[i] == train->plan[j]) {
                isNeeded = 1;
                break;
            }
        }

        if (isNeeded) {
            if (fromHead == -1) fromHead = currentStep;
            fromTail = currentStep; 
        }

        i = (i - 1 + rails->cars->size) % rails->cars->size;
        currentStep++;
    }
    
    totalCount = currentStep - 1;

    if (fromHead == -1) return 0;

    int distFromTail = (totalCount - fromTail) + 1;

    if (fromHead <= distFromTail) {
        return fromHead;
    } else {
        return -distFromTail;
    }
}

int main(int argc, char* argv[]){

    char verbose;
    if (argc < 2) return 0;
    if (argc == 2) verbose = 0;
    verbose = atoi(argv[2]) > 0;\

    int LINE_ADD = 0;
    int LINE_REMOVE = 0;
    int TRAIN_ADD = 0;
    int TRAIN_REMOVE = 0;

    Station* station = initStation(argv[1]);
    
    while(!isFormed(station)){
        for(int i = 0; i < station->count; ++i){
            int k = getSide(&station->rails[i], &station->train);

            if (k > 0){
                for(int l = 0; l < k; ++l){
                    int car = popHeadStaticDeque(station->rails[i].cars);
                    LINE_REMOVE++;
                    station->rails[i].count--;
                    pushDynamicStack(&station->train.cars, car);
                    TRAIN_ADD++;
                    station->train.countCur++;
                    if (verbose) printf("CART_%d LINE_%d<S> TRAIN\n", car, i + 1);
                }
            }

            if (k < 0){
                for(int l = 0; l < -k; ++l){
                    int car = popTailStaticDeque(station->rails[i].cars);
                    LINE_REMOVE++;
                    station->rails[i].count--;
                    pushDynamicStack(&station->train.cars, car);
                    TRAIN_ADD++;
                    station->train.countCur++;
                    if (verbose) printf("CART_%d LINE_%d<E> TRAIN\n", car, i + 1);
                }
            }
        }

        for(int i = 0; i < station->count && station->train.countCur != 0; ++i){
            while(station->rails[i].capacity != station->rails[i].count && station->train.countCur != 0){
                int car = popDynamicStack(&station->train.cars);
                TRAIN_REMOVE++;
                station->train.countCur--;
                char isNeeded = 0;
                for(int j = 0; j < station->train.countPlan; ++j){
                    if (station->train.plan[j] == car){
                        isNeeded = 1;
                        break;
                    }
                }
                if (isNeeded){
                    pushHeadStaticDeque(station->rails[i].cars, car);
                    LINE_ADD++;
                    station->rails[i].count++;
                    if (verbose) printf("CART_%d TRAIN LINE_%d<S>\n", car, i + 1);
                }
                else{
                    pushTailStaticDeque(station->rails[i].cars, car);
                    LINE_ADD++;
                    station->rails[i].count++;
                    if (verbose) printf("CART_%d TRAIN LINE_%d<E>\n", car, i + 1);
                }
            }
        }

        for(int i = 0; i < station->count; ++i){
            char isNeeded = 1;
            if(station->rails[i].count == 0) continue;
            while(isNeeded){
                for(int j = 0; j < station->train.countPlan; ++j){
                    isNeeded = 1;
                    if (station->train.plan[j] != station->rails[i].cars->array[station->rails[i].cars->head]){
                        isNeeded = 0;
                    }
                    else{
                        int car = popHeadStaticDeque(station->rails[i].cars);
                        LINE_REMOVE++;
                        station->rails[i].count--;
                        pushDynamicStack(&station->train.cars, car);
                        TRAIN_ADD++;
                        if (verbose) printf("CART_%d LINE_%d<S> TRAIN\n", car, i + 1);
                        station->train.countCur++;
                    }
                }
            }
        }

    }

    int TOTAL = LINE_ADD + LINE_REMOVE + TRAIN_ADD + TRAIN_REMOVE;
    printf("LINE_ADD: %d\n", LINE_ADD);
    printf("LINE_REMOVE: %d\n", LINE_REMOVE);
    printf("TRAIN_ADD: %d\n", TRAIN_ADD);
    printf("TRAIN_REMOVE: %d\n", TRAIN_REMOVE);
    printf("TOTAL: %d\n", TOTAL);

    free(station->train.plan);
    free(station->rails);
    free(station);



    return 0;
}