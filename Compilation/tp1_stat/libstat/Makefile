default: libstat.so

libstat.so: mean.o variance.o 
	gcc -shared $^ -o $@ -lm

#
# À compléter ...
#

%.o: %.c
	gcc -Wall -fPIC -c -o $@ $<

mean.o: mean.c mean.h
	gcc -c -Wall  $< -o mean.o

variance.o: variance.c variance.h
	gcc -c -Wall $< -o variance.o

clean:
	rm *.o libstat.so