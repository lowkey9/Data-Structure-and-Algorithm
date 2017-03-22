CC=g++
CFLAGS=-g -Wall

default: bst

bst: Main.o Tree.o Node.o
	$(CC) $(CFLAGS) -o bst Main.o Tree.o Node.o

main.o: Main.cpp Node.h Tree.h
	$(CC) $(CFLAGS) -c Main.cpp

tree.o: Tree.cpp Tree.h
	$(CC) $(CFLAGS) -c Tree.cpp

node.o: Node.cpp Node.h
	$(CC) $(CFLAGS) -c Node.cpp

clean:
	$(RM) bst *.o *~
