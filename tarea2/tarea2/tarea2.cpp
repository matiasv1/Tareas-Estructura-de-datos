#include "listasTDA.hpp"
#include<iostream>
#include <sstream>
#include <string>
#include<fstream>
#include<stdlib.h>
using namespace std;

int main(int argc,char *argv[]){
	nodo *iniciador=NULL;
	string valores;
	string palabra_fin="nada";
	int contador=0;
	valores_archivo(iniciador,contador,argv[1]);
	do{
		char palabras[100];
		cout<<"";
		cin.getline(palabras,100,'\n');
		ingreso_usuario(palabras,iniciador,contador,palabra_fin,argv[1]);
	}while(palabra_fin!="exit");
	delete(iniciador);
	return 0;
};