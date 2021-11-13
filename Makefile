all: main.out

main.out: main.o abr.o node.o element.o
	g++ -g -W -Wall main.o abr.o node.o element.o -o main.out

main.o: main.cpp abr.h node.h element.h
	g++ -g -W -Wall -c main.cpp

abr.o: abr.h abr.cpp node.h element.h
	g++ -g -W -Wall -c abr.cpp -o abr.o

node.o: node.h node.cpp
	g++ -g -W -Wall -c node.cpp

element.o: element.h element.cpp
	g++ -g -W -Wall -c element.cpp

clean:
	rm *.o

veryclean: clean
	rm *.out