//
// Created by micro on 03/03/2022.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arraylist.h"

typedef struct arrlist{
    int length;
    int size;
    void** arr;
    size_t DATASIZE;
    void (*PRINT)(void*);
}ArrayList;

ArrayList* initArrayList(void (*PRINT)(void*), size_t DATASIZE){
    ArrayList* list = (ArrayList*)malloc(sizeof(ArrayList));
    list->size = 0;
    list->length = 8;
    list->arr = calloc(8,sizeof(void*));
    list->DATASIZE = DATASIZE;
    list->PRINT = PRINT;
    return list;
}

void allocatesArr(ArrayList* list){
    size_t newSize = 2*list->length*list->DATASIZE;
    printf("NEW SIZE: %d", newSize);
    list->arr = realloc(list->arr, newSize);
    list->length = list->length*2;
}

void listPush(ArrayList * list, void* DATA){
    if(list->length == list->size){ allocatesArr(list);}
    void* CPYDATA = malloc(sizeof(list->DATASIZE));
    memcpy(CPYDATA, DATA, sizeof(list->DATASIZE));
    list->arr[list->size] = CPYDATA;
    list->size++;
}
void printArrayList(ArrayList* list){
    void** arr = list->arr;
    printf("[");
    for(int i = 0; i < list->size; i++){
        list->PRINT(arr[i]);
        if(i < list->size - 1){
            printf(",");
        }
    }
    puts("]");
}


