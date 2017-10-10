CC = clang++
CFLAGS=-g -Wall -std=c++11 -stdlib=libc++

all: wav

wav: main.o general.o pgm.o algo.o
	@echo "VAI!"
	${CC} ${CFLAGS} -o wav general.o pgm.o algo.o main.o

main.o: main.cpp biblioteca.hpp
	${CC} ${CFLAGS} -c main.cpp

algo.o: algo.cpp algo.hpp base.hpp pgm.hpp general.hpp
	${CC} ${CFLAGS} -c algo.cpp

pgm.o: pgm.cpp pgm.hpp base.hpp
	${CC} ${CFLAGS} -c pgm.cpp

general.o: general.cpp general.hpp base.hpp
	${CC} ${CFLAGS} -c general.cpp

clean:
	/bin/rm -f wav main.o algo.o pgm.o general.o
	/bin/rm -f biblioteca.hpp.gch base.hpp.gch algo.hpp.gch pgm.hpp.gch general.hpp.gch
