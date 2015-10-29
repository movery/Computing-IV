# Makefile for LFSR
#
#

all:
	make ps2a

ps2a: test.o LFSR.o
	g++ -o ps2a test.o LFSR.o -lboost_unit_test_framework -ansi -pedantic -Wall -Werror

test.o:	test.cpp
	g++ -c test.cpp -ansi -pedantic -Wall -Werror

LFSR.o: LFSR.hpp LFSR.cpp 
	g++ -c LFSR.cpp -ansi -pedantic -Wall -Werror

clean:
	rm -f *.o *~ ps2a
