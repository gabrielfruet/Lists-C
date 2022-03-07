//
// Created by micro on 03/03/2022.
//

#ifndef TESTEUNION_ARRAYLIST_H
#define TESTEUNION_ARRAYLIST_H
#include <stdlib.h>
typedef struct arrlist ArrayList;

ArrayList* initArrayList(void (*PRINT)(void*), size_t DATASIZE);
void allocatesArr(ArrayList* list);
void listPush(ArrayList * list, void* DATA);
void printArrayList(ArrayList* list);
#endif //TESTEUNION_ARRAYLIST_H
