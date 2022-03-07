//
// Created by micro on 03/03/2022.
//

#ifndef TESTEUNION_PRINTFUNC_H
#define TESTEUNION_PRINTFUNC_H

enum dataSizes{
    INT_SIZE = sizeof(int*),
    CHAR_SIZE = sizeof(char*),
    STR_SIZE = sizeof(char)*256,
    DOUB_SIZE = sizeof(double*),
    FL_SIZE = sizeof(float*)
};

void printFloat(void* fl);
void printString(void* str);
void printDouble(void* db);
void printChar(void* c);
void printInt(void* i);

#endif //TESTEUNION_PRINTFUNC_H
