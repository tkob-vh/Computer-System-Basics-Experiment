#include <stdio.h>


void printmyid();

void (*myprint)() = printmyid;

void printmyid(){
    printf("U202215545\n");
}
