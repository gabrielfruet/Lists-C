//
// Created by micro on 03/03/2022.
//
#include <stdio.h>
#include "printfunc.h"

void printInt(void* i){
    printf("%d", *(int*)i);
}
void printChar(void* c){
    printf("%c", *(char*)c);
}
void printDouble(void* db){
    printf("%lf", *(double*)db);
}
void printString(void* str){
    printf("%s", (char**)str);
}
void printFloat(void* fl){
    printf("%lf", *(float*)fl);
}