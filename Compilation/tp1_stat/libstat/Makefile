default: libstat.so

CC = gcc
CFLAGS = -Wall -ansi -pedantic


libstat.so: mean.o variance.o 
	$(CC) -shared $^ -o $@ -lm

#
# À compléter ...
#

%.o: %.c
	$(CC) -Wall -fPIC -shared -c -o $@ $<

mean.o: mean.c mean.h
#	$(CC) -c -Wall  $< -o mean.o

variance.o: variance.c variance.h
#	$(CC) -c -Wall $< -o variance.o

clean:
	rm *.o libstat.so