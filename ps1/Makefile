# Makefile for ps1
#
#

all:
	make sierpinski
	make original

original: original.o Rectangle.o
	g++ -o original -Wall -Werror -ansi -pedantic original.o Rectangle.o -lsfml-graphics -lsfml-window -lsfml-system

sierpinski: sierpinski.o Triangle.o
	g++ -o sierpinski -Wall -Werror -ansi -pedantic sierpinski.o Triangle.o -lsfml-graphics -lsfml-window -lsfml-system

original.o: Rectangle.hpp original.cpp
	g++ -c -Wall -Werror -ansi -pedantic original.cpp

Rectangle.o: Rectangle.hpp Rectangle.cpp
	g++ -c -Wall -Werror -ansi -pedantic Rectangle.cpp

sierpinski.o: Triangle.hpp sierpinski.cpp
	g++ -c -Wall -Werror -ansi -pedantic sierpinski.cpp

Triangle.o: Triangle.hpp Triangle.cpp
	g++ -c -Wall -Werror -ansi -pedantic Triangle.cpp

clean: 
	rm -f sfml-app *.o *~ sierpinski original
