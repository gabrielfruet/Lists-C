//
// Created by micro on 02/03/2022.
//
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "linkedlist.h"
#include "printfunc.h"

typedef struct node{
    struct node* NEXT;
    struct node* PREVIOUS;
    void* DATA;
}Node;
typedef struct linklist{
    Node* head;
    Node* foot;
    int size;
    size_t DATASIZE;
    void (*PRINT)(void*);
}LinkedList;
void** listToArray(LinkedList* list){
    void** arr = malloc(sizeof(list->DATASIZE)*list->size);
    Node* current = list->head;
    for(int i = 0; i < list->size; i++){
        arr[i] = current->DATA;
        current = current->NEXT;
    }
    return arr;
}
LinkedList* listAll(LinkedList* list, void* DATA){
    LinkedList* listed = initLinkedList(printInt, sizeof(int));
    Node* current = list->head;
    for(int i = 0; i < list->size; i++){
        if(!memcmp(DATA, current->DATA, list->size)){
            listAdd(listed,&i);
        }
        current = current->NEXT;
    }
    return listed;
}
int getListSize(LinkedList* list){
    return list->size;
}
int listContains(LinkedList* list, void* DATA){
    Node* current = list->head;
    void* currentData;
    do{
        currentData = current->DATA;
        if(!memcmp(DATA, currentData, list->size)){
            return 1;
        }
        current = current->NEXT;
    }while(current != NULL);
    return 0;
}
void* getFirstData(LinkedList* list){
    return list->head->DATA;
}
void* getLastData(LinkedList* list){
    return list->foot->DATA;
}
Node* listSearch(LinkedList* list, int index){
    Node* current;
    if(index < list->size / 2){
        current = list->head;
        for(int i = 0; i < index; i++){
            current = current->NEXT;
        }
    }else{
        current = list->foot;
        for(int i = list->size - 1; i > index; i--){
            current = current->PREVIOUS;
        }
    }
    return current;
}
void listAdd(LinkedList* list, void* DATA){
    void* CPYDATA = malloc(list->DATASIZE);
    memcpy(CPYDATA, DATA, list->DATASIZE);
    if(list->size == 0){
        list->head = initNode(CPYDATA);
        list->foot = list->head;
    }else{
        list->foot->NEXT = initDefinedNode(CPYDATA, NULL, list->foot);
        list->foot = list->foot->NEXT;
    }
    list->size++;
}
void listAddFirst(LinkedList* list, void* DATA){
    void* CPYDATA = malloc(list->DATASIZE);
    memcpy(CPYDATA, DATA, list->DATASIZE);
    if(list->size == 0){
        list->head = initNode(CPYDATA);
        list->foot = list->head;
    }else{
        list->head->PREVIOUS = initDefinedNode(CPYDATA, NULL, list->foot);
        list->head = list->head->PREVIOUS;
    }
    list->size++;
}
void listAddAt(LinkedList* list, void* DATA, int index){
    void* CPYDATA = malloc(list->DATASIZE);
    memcpy(CPYDATA, DATA, list->DATASIZE);
    if(list->size == 0){listAdd(list, DATA);return;}
    if(index == 0){ listAddFirst(list, DATA);return;}
    if(index == list->size - 1){ listAdd(list, DATA);return;}
    Node* addNext = listSearch(list, index - 1);
    Node* toAdd = initDefinedNode(DATA, addNext->NEXT, addNext);
    addNext->NEXT->PREVIOUS = toAdd;
    addNext->NEXT = toAdd;
    list->size++;
}
LinkedList* initLinkedList(void (*printptr)(void*), size_t dataSize){
    LinkedList* list = (LinkedList*)malloc(sizeof(LinkedList));
    list->head = NULL;
    list->foot = NULL;
    list->size = 0;
    list->PRINT = printptr;
    list->DATASIZE = dataSize;
    return list;
}
Node* initNode(void* DATA){
    Node* node = (Node*)malloc(sizeof(Node));
    node->DATA = DATA;
    node->NEXT = NULL;
    node->PREVIOUS = NULL;
    return node;
}
Node* initDefinedNode(void* DATA, Node* next, Node* previous){
    Node* node = (Node*)malloc(sizeof(Node));
    node->DATA = DATA;
    node->NEXT = next;
    node->PREVIOUS = previous;
    return node;
}
void* removeLast(LinkedList* list){
    if(list->size == 0){return NULL;}
    Node* temp = list->foot;
    list->foot = list->foot->PREVIOUS;
    void* data = temp->DATA;
    free(temp);
    list->foot->NEXT = NULL;
    list->size--;
    return data;
}
void* removeFirst(LinkedList* list){
    if(list->size == 0){return NULL;}
    Node* temp = list->head;
    list->head = list->head->NEXT;
    void* data = temp->DATA;
    free(temp);
    list->head->PREVIOUS = NULL;
    list->size--;
    return data;
}
void* removeFrom(LinkedList* list, int index){
    if(list->size == 0){return NULL;}
    if(index == 0){return removeFirst(list);}
    if(index == list->size - 1){return removeLast(list);}
    Node* toDelete = listSearch(list, index);
    void* data = toDelete->DATA;
    toDelete->PREVIOUS->NEXT = toDelete->NEXT;
    toDelete->NEXT->PREVIOUS = toDelete->PREVIOUS;
    free(toDelete);
    list->size--;
    return data;
}
void* getDataAt(LinkedList* list, int index){
    return listSearch(list, index)->DATA;
}
void printList(LinkedList* list){
    printf("[");
    Node* current = list->head;
    list->PRINT(current->DATA);
    current = current->NEXT;
    while(current != NULL){
        printf(",");
        list->PRINT(current->DATA);
        current = current->NEXT;
    }
    puts("]");

}



