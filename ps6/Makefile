# Makefile for MarkovModel
#
#

all:
	make TextGenerator

TextGenerator: MarkovModel.o TextGenerator.o
	g++ -o TextGenerator TextGenerator.o MarkovModel.o -ansi -pedantic -Wall -Werror

TextGenerator.o: MarkovModel.hpp TextGenerator.cpp
	g++ -c TextGenerator.cpp -ansi -pedantic -Wall -Werror

MarkovModel.o: MarkovModel.hpp MarkovModel.cpp
	g++ -c MarkovModel.cpp -ansi -pedantic -Wall -Werror

clean:
	rm -f *.o *~ TextGenerator
