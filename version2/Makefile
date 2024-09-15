 
all : exemple
clobber : clean
	rm -f *~ \#*\# core

clean : 
	rm -f exemple *.o

CC = gcc
CFLAGS = -Wall -ansi -pedantic


exemple : foo1.o foo2.o foo3.o exemple.o
	$(CC) -o $@ $< foo2.o foo3.o exemple.o
 
foo1.o : foo1.c foo1.h
	$(CC) -c  -o $@ $<
foo2.o : foo2.c foo2.h
	$(CC) -c -o $@ $<
foo3.o : foo3.c foo3.h
	$(CC) -c  -o $@ $<
exemple.o : exemple.c 
	$(CC) -c -o $@ $< 

 
