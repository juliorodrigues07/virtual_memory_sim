all: main.o
	gcc main.o -o tp2virtual

main.o: utilities.h 
	gcc -c main.c

clean:
	rm -rf *.o

run:
	./tp2virtual lru ../Instances/matriz.log 8 16384
