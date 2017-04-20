CC=g++
CFLAGS=-g -Wall

default: ttt

ttt: Main.o Tree.o Node.h
	$(CC) $(CFLAGS) -o ttt Main.o Tree.o

main.o: Main.cpp Node.h Tree.h
	$(CC) $(CFLAGS) -c Main.cpp

tree.o: Tree.cpp Tree.h
	$(CC) $(CFLAGS) -c Tree.cpp

clean:
	$(RM) ttt *.o *~
