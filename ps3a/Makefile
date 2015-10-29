# Makefile for nbody
#
#

all:
	make NBody

NBody: main.o Body.o
	g++ -o NBody main.o Body.o -lsfml-graphics -lsfml-system -lsfml-window -ansi -pedantic -Wall -Werror

main.o: Body.hpp main.cpp
	g++ -c main.cpp -ansi -pedantic -Wall -Werror

Body.o: Body.hpp Body.cpp
	g++ -c Body.cpp -ansi -pedantic -Wall -Werror

clean:
	rm -f *.o *~ NBody
