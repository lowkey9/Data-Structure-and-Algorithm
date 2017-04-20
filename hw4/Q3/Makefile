CXX=g++
CXXFLAGS=-g -std=c++11 -Wall

default: rbt

rbt: Main.o RBT.o Node.o
	$(CXX) $(CXXFLAGS) -o rbt Main.o RBT.o Node.o

main.o: Main.cpp Node.h RBT.h
	$(CXX) $(CXXFLAGS) -c Main.cpp

tree.o: RBT.cpp RBT.h
	$(CXX) $(CXXFLAGS) -c RBT.cpp

node.o: Node.cpp Node.h
	$(CXX) $(CXXFLAGS) -c Node.cpp

clean:
	$(RM) rbt *.o *~
