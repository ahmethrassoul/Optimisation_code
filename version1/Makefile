 
all : exemple
clobber : clean
	rm -f *~ \#*\# core

clean : 
	rm -f exemple *.o
	 
exemple : foo1.o foo2.o foo3.o exemple.o
	gcc foo1.o foo2.o foo3.o exemple.o -o exemple.exe
 
foo1.o : foo1.c foo1.h
	gcc -c foo1.c -o foo1.o

foo2.o : foo2.c foo2.h
	gcc -c foo2.c -o foo2.o

foo3.o : foo3.c foo3.h
	gcc -c foo3.c -o foo3.o

exemple.o : exemple.c 
	gcc -c exemple.c -o exemple.o

 
