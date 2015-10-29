# Makefile for RingBuffer
#
#

GuitarHero: RingBuffer.o GuitarString.o main.o
	g++ -o GuitarHero main.o GuitarString.o RingBuffer.o -lsfml-system -lsfml-audio -lsfml-graphics -lsfml-window

main.o: RingBuffer.hpp GuitarString.hpp main.cpp
	g++ -c main.cpp -ansi -pedantic -Wall -Werror

GuitarString.o: RingBuffer.hpp GuitarString.hpp GuitarString.cpp
	g++ -c GuitarString.cpp -ansi -pedantic -Wall -Werror

RingBuffer.o: RingBuffer.hpp RingBuffer.cpp
	g++ -c RingBuffer.cpp -ansi -pedantic -Wall -Werror

clean:
	rm -f *.o *~ GuitarHero
