# Makefile for ps2a
#
#

all:
	make PhotoMagic
	make PhotoMagicDelux

PhotoMagicDelux: PhotoMagicDelux.o LFSR.o
	g++ -o PhotoMagicDelux PhotoMagicDelux.o LFSR.o -lsfml-graphics -lsfml-system -lsfml-window -ansi -pedantic -Wall -Werror

PhotoMagic: PhotoMagic.o LFSR.o
	g++ -o PhotoMagic PhotoMagic.o LFSR.o -lsfml-graphics -lsfml-system -lsfml-window -ansi -pedantic -Wall -Werror

PhotoMagicDelux.o: LFSR.hpp PhotoMagicDelux.cpp
	g++ -c PhotoMagicDelux.cpp -ansi -pedantic

PhotoMagic.o: LFSR.hpp PhotoMagic.cpp
	g++ -c PhotoMagic.cpp -ansi -pedantic -Wall -Werror

LFSR.o: LFSR.hpp LFSR.cpp
	g++ -c LFSR.cpp -ansi -pedantic -Wall -Werror

clean:
	rm -f *.o *~ PhotoMagic PhotoMagicDelux
