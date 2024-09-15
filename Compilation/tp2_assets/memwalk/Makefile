CFLAGS = -O1 -Wall -g

all: memwalk

memwalk: memwalk.o shuffle.o
	gcc $^ -o $@

memwalk.o: memwalk.c shuffle.h 
	gcc $(CFLAGS) -c $< -o $@

shuffle.o: shuffle.c shuffle.h 
	gcc $(CFLAGS) -c $< -o $@

clean:
	rm -f *.o memwalk
