CC=g++
CFLAGS=-g -Wall

default: rbt

rbt: Main.o RBT.o Node.o
	$(CC) $(CFLAGS) -o rbt Main.o RBT.o Node.o

main.o: Main.cpp Node.h RBT.h
	$(CC) $(CFLAGS) -c Main.cpp

tree.o: RBT.cpp RBT.h
	$(CC) $(CFLAGS) -c RBT.cpp

node.o: Node.cpp Node.h
	$(CC) $(CFLAGS) -c Node.cpp

clean:
	$(RM) rbt *.o *~
