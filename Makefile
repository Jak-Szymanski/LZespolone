TRGDIR=.
OBJ=./obj
SRC=./src
INC=./inc
TESTS=./tests
TBIN=./tests/bin
FLAGS= -Wall -pedantic -std=c++14 -iquote inc

${TRGDIR}/test_arytm_zesp: ${OBJ} ${OBJ}/main.o ${OBJ}/LZespolona.o\
                     ${OBJ}/WyrazenieZesp.o ${OBJ}/BazaTestu.o ${OBJ}/BazaTestu.o ${OBJ}/Statystyki.o
	g++ -o ${TRGDIR}/test_arytm_zesp ${OBJ}/main.o ${OBJ}/LZespolona.o\
                     ${OBJ}/WyrazenieZesp.o ${OBJ}/BazaTestu.o ${OBJ}/Statystyki.o

${OBJ}:
	mkdir ${OBJ}

${OBJ}/main.o: ${SRC}/main.cpp inc/LZespolona.hh inc/BazaTestu.hh
	g++ -c ${FLAGS} -o ${OBJ}/main.o ${SRC}/main.cpp

${OBJ}/LZespolona.o: ${SRC}/LZespolona.cpp inc/LZespolona.hh
	g++ -c ${FLAGS} -o ${OBJ}/LZespolona.o ${SRC}/LZespolona.cpp

${OBJ}/BazaTestu.o: ${SRC}/BazaTestu.cpp inc/BazaTestu.hh inc/WyrazenieZesp.hh\
                       inc/LZespolona.hh
	g++ -c ${FLAGS} -o ${OBJ}/BazaTestu.o ${SRC}/BazaTestu.cpp

${OBJ}/WyrazenieZesp.o: ${SRC}/WyrazenieZesp.cpp inc/WyrazenieZesp.hh\
                       inc/LZespolona.hh
	g++ -c ${FLAGS} -o ${OBJ}/WyrazenieZesp.o ${SRC}/WyrazenieZesp.cpp

${OBJ}/Statystyki.o: ${SRC}/Statystyki.cpp inc/Statystyki.hh
	g++ -c ${FLAGS} -o ${OBJ}/Statystyki.o ${SRC}/Statystyki.cpp

${TBIN}/test_1: ${TBIN} ${OBJ}/LZespolona.o 
	g++ -o ${TESTS}/bin/test_1 ${FLAGS} -I${TESTS}/doctest ${TESTS}/test1.cpp ${OBJ}/LZespolona.o

${TBIN}/test_2: ${TBIN} ${OBJ}/LZespolona.o 
	g++ -o ${TESTS}/bin/test_2 ${FLAGS} -I${TESTS}/doctest ${TESTS}/test2.cpp ${OBJ}/LZespolona.o


${TBIN}:
	mkdir ${TBIN}

test:  ${TBIN}/test_1 ${TBIN}/test_2
	${TBIN}/test_1 
	${TBIN}/test_2
run:
	${TRGDIR}/test_arytm_zesp latwy

clean:
	rm -f ${TRGDIR}/test_arytm_zesp ${OBJ}/* ${TBIN}/*
