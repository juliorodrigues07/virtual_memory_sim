all: virtual_mem_sim.o
	gcc virtual_mem_sim.o main.c -o tp2virtual

virtual_mem_sim.o: utilities.h 
	gcc -c virtual_mem_sim.c

clean:
	rm -rf *.o

run:
	./tp2virtual lru ../Instances/matriz.log 8 8192
