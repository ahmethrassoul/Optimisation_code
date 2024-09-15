#include <stdio.h>
#include <stdlib.h>
#include "foo1.h"
#include "foo2.h"
#include "foo3.h"

int main (int argc, char * argv[]){
    printf("%s - %s /n" , __DATE__ , __TIME__ );
    foo1();
    foo2();
    foo3();
    return 0 ;
}

/*
 gcc -c foo1.c -o foo1.o
 gcc -c foo2.c -o foo2.o
 gcc -c foo3.c -o foo3.o
 gcc -c exemple.c -o exemple.o
 gcc foo1.o foo2.o foo3.o exemple.o -o exemple.exe
*/