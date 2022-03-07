cmake_minimum_required(VERSION 3.21)
project(TesteUnion C)

set(CMAKE_C_STANDARD 99)

add_executable(TesteUnion linkedlistmain.c linkedlist.c linkedlist.h arraylist.c arraylistmain.c arraylist.h printfunc.h printfunc.c)
