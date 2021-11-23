all: main.out

main.out: main.o arn.o node.o element.o
	g++ -g -W -Wall main.o arn.o node.o element.o -o main.out

main.o: main.cpp arn.h node.h element.h collection.h
	g++ -g -W -Wall -c main.cpp

arn.o: arn.h arn.cpp node.h element.h
	g++ -g -W -Wall -c arn.cpp -o arn.o

abr.o : abr.cpp abr.h
	g++ -g -W -Wall -c abr.cpp

node.o: node.h node.cpp
	g++ -g -W -Wall -c node.cpp

element.o: element.h element.cpp
	g++ -g -W -Wall -c element.cpp

clean:
	rm *.o

veryclean: clean
	rm *.out