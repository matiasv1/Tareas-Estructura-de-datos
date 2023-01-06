#include<iostream>
#include<fstream>
#include <cstdio>
#include "fx.hpp"
using namespace std;


int main(){
	int valores;
	int contador,contador2=0;
	int sacar_valores[9];
	int matriz[5][5];
	ifstream archivo("numeros.txt");
	if (archivo.is_open()){
		while(archivo>>valores){
			sacar_valores[contador]=valores;
			contador++;
			
		}
	}
	for(int i=0;i<5;i++){ 
		matriz[0][i]=sacar_valores[i];
	}
	for(int i=5;i<10;i++){ 
		matriz[1][contador2]=sacar_valores[i];
		contador2++;
	}
	
	sumar_arreglo(matriz);
	resta_arreglo(matriz);
	multiplicar_arreglo(matriz);
	print_resultado(matriz);
	
	return 0;
}
