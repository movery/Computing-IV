# Makefile for RingBuffer
#
#

all:
	make ps5a

ps5a: RingBuffer.o test.o
	g++ test.o RingBuffer.o -o ps5a -lboost_unit_test_framework

test.o:	RingBuffer.hpp test.cpp
	g++ -c test.cpp -ansi -pedantic -Wall -Werror

RingBuffer.o: RingBuffer.hpp RingBuffer.cpp
	g++ -c RingBuffer.cpp -ansi -pedantic -Wall -Werror

clean:
	rm -f *.o *~ ps5a
