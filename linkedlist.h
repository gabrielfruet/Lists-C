//
// Created by micro on 02/03/2022.
//

#include <stdlib.h>

typedef struct node Node;

typedef struct linklist LinkedList;

//INITIALIZER
LinkedList* initLinkedList(void (*printptr)(void*), size_t dataSize);
Node* initDefinedNode(void* DATA, Node* next, Node* previous);
Node* initNode(void* DATA);
void** listToArray(LinkedList* list);
//GETTERS
void* getDataAt(LinkedList* list, int index);
void* getFirstData(LinkedList* list);
void* getLastData(LinkedList* list);
int getListSize(LinkedList* list);
//FIND
LinkedList* listAll(LinkedList* list, void* DATA);
//CONTAINS
int listContains(LinkedList* list, void* DATA);
//REMOVING
void* removeLast(LinkedList* list);
void* removeFirst(LinkedList* list);
void* removeFrom(LinkedList* list, int index);
//ADDING
void listAdd(LinkedList* list, void* DATA);
void listAddFirst(LinkedList* list, void* DATA);
void listAddAt(LinkedList* list, void* DATA, int index);
//PRINTING
void printList(LinkedList* list);