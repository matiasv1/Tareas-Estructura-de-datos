tarea3: tarea3.o fx.o
	g++ tarea3.o fx.o -o tarea3

fx.o: fx.cpp fx.hpp
	g++ -c fx.cpp

tarea2.o: tarea3.cpp
	g++ -c tarea3.cpp

clean:
	rm *.o tarea3