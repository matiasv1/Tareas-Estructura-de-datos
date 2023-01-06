main: main.o fx.o
	g++ main.o fx.o -o main

main.o: main.cpp
	g++ -c main.cpp

fx.o: fx.cpp fx.hpp
	g++ -c fx.cpp

clean:
	rm *.o main