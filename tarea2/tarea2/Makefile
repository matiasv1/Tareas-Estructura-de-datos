main: tarea2.o listasTDA.o
	g++ listasTDA.o tarea2.o -o tarea2

listasTDA.o: listasTDA.hpp listasTDA.cpp
	g++ -c listasTDA.cpp

tarea2.o: tarea2.cpp
	g++ -c tarea2.cpp

clean:
	rm *.o tarea2
