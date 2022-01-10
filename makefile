AR=ar
CC=gcc 
FLAGS= -Wall -g
all:  graph.o graph

graph:  graph.o 
	$(CC) $(FLAGS) -o graph graph.o 	

graph.o: graph.c  graph.h
	$(CC) $(FLAGS) -c graph.c

.PHONY: clean all
clean:
	rm -f *.a *.so *.o graph