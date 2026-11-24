structs: main.o func.o figures.o
	g++ main.o func.o figures.o -o structs

main.o: main.cpp structs.h figures.h func.h
	g++ -c main.cpp

func.o: func.cpp structs.h
	g++ -c func.cpp

figures.o: figures.cpp structs.h
	g++ -c figures.cpp

