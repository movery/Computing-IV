# Makefile for Edit Distance
#
#

all:
	make ED

ED: main.o ED.o
	g++ -o ED -g main.o ED.o -lsfml-system

main.o: ED.cpp main.cpp
	g++ -c -g main.cpp -ansi -pedantic -Wall -Werror

ED.o: ED.hpp ED.cpp
	g++ -c -g -O2 ED.cpp -ansi -pedantic

clean:
	rm -f *.o *~ ED
