CC=gcc
AR=ar
OBGECT_LIB_CLASS_REC_A= algo.o nodes.o edges.o graph.o 
OBGECT_LIB_CLASS_REC_SO= algo.o nodes.o edges.o graph.o
FLAGS=-g -Wall
all: recursives loopd graph maindrec


recursives: libclassrec.a
loopd:libclassrec.so

libclassrec.a:$(OBGECT_LIB_CLASS_REC_A)
	$(AR) -rcs libclassrec.a $(OBGECT_LIB_CLASS_REC_A)

libclassrec.so:$(OBGECT_LIB_CLASS_REC_SO) 
	$(CC) -shared -o libclassrec.so $(OBGECT_LIB_CLASS_REC_SO)

algo.o: algo.c algo.h
	$(CC) $(FLAGS) -c algo.c
nodes.o: nodes.c nodes.h 
	$(CC) $(FLAGS) -c nodes.c
edges.o: edges.c edges.h 
	$(CC) $(FLAGS) -c edges.c
graph.o: graph.c graph.h
	$(CC) $(FLAGS) -c graph.c 
graph: main.o libclassrec.a 
	$(CC) $(FLAGS) -o graph main.o libclassrec.a
maindrec: main.o libclassrec.so
	$(CC) $(FLAGS) -o maindrec main.o ./libclassrec.so

main.o: main.c graph.h algo.h nodes.h edges.h 
	$(CC) $(FLAGS) -c main.c

.PHONY: clean all

clean:
	rm -f *.o *.a *.so graph maindrec