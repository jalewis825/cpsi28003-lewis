program: main.o Node.o doublylinkedlist.o
	g++ main.o Node.o doublylinkedlist.o -o program

main.o: main.cpp doublylinkedlist.h Node.h
	g++ -c main.cpp

Node.o: Node.cpp Node.h
	g++ -c Node.cpp

doublylinkedlist.o: doublylinkedlist.cpp doublylinkedlist.h Node.h
	g++ -c doublylinkedlist.cpp

clean:
	rm *.o program