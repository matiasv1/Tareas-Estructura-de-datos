#include"listasTDA.hpp"
#include<iostream>
#include<sstream>
#include<string>
#include<fstream>
#include<stdlib.h>
using namespace std;

void insertar_final(nodo *&iniciador,string letra,string nombre,int duracion){
	nodo *puntero;
	puntero=new (nodo);
	puntero->valores_todos.letra=letra;
	puntero->valores_todos.nombre=nombre;
	puntero->valores_todos.duracion=duracion;
	if (iniciador==NULL){
		puntero->siguiente=iniciador;
		iniciador=puntero;
	}
	else{
		nodo *aux;
		aux=iniciador;
		while(aux->siguiente !=NULL){
			aux=aux->siguiente;
		}
		aux->siguiente=puntero;
		puntero->siguiente=NULL;
	}
};
	
void info(nodo *iniciador,int contador){
	nodo *puntero;
	int suma=0;
	for(puntero=iniciador;puntero!=NULL;puntero=puntero->siguiente){
		suma+=puntero->valores_todos.duracion;
	}
	cout<<contador<<" canciones , "<<suma<<" segundos"<<endl;
};

void print(nodo *iniciador){
	int contador=0;
	for (nodo *it = iniciador; it != NULL; it = it -> siguiente) {
        cout <<contador<<"."<< it->valores_todos.letra<<" by " <<it->valores_todos.nombre<<" ("<<it-> valores_todos.duracion <<" s)"<<endl;
        contador+=1;
    } 
};
void inserta_puesto(nodo *iniciador,string letra1,string nombre1,int duracion1){
	nodo *puntero;
	puntero=new (nodo);
	puntero->valores_todos.letra=letra1;
	puntero->valores_todos.nombre=nombre1;
	puntero->valores_todos.duracion=duracion1;
	puntero->siguiente=iniciador->siguiente;
	iniciador->siguiente=puntero;
};

void add_i(nodo *iniciador,int index,string letra,string nombre,int duracion,int &contador){
	nodo *aux=iniciador;
	if(contador<index){
		insertar_final(iniciador,letra,nombre,duracion);
		++contador;
	}
	else{
		for(int i=1;i<index;i++){
			aux=aux->siguiente;
		}
		inserta_puesto(aux,letra,nombre,duracion);
		++contador;
	}
};
void remover_por_index(nodo *puntero_antes){
	nodo *puntero_remover;
	puntero_remover=puntero_antes->siguiente;
	puntero_antes->siguiente=puntero_remover->siguiente;
	delete (puntero_remover);
	
};
void remover(nodo *iniciador,int index,int &contador){
	nodo *aux=iniciador;
	int x=0;
	if (contador<index){
		x=0;
	}else{
		for(int i=1;i<index;i++){
			aux=aux->siguiente;
		}
		remover_por_index(aux);
		--contador;
	}
};

void remover_principal(nodo*&cabecera){
	nodo *puntero_remover;
	puntero_remover=cabecera;
	cabecera=cabecera->siguiente;
	delete puntero_remover;
	
};
void eliminar(nodo*&cabecera){
	while(cabecera!=NULL){
		remover_principal(cabecera);
	}
};

void exit(nodo*&iniciador,string texto){
	nodo *it;
	ofstream archivo(texto);
	if (archivo.is_open()){
		for (nodo *it = iniciador; it != NULL; it = it -> siguiente) {
        archivo << it->valores_todos.letra<<";" <<it->valores_todos.nombre<<";"<<it-> valores_todos.duracion <<endl;
    	} 
	}
	archivo.close();
	eliminar(iniciador);
};

void ingreso_usuario(char palabras_ingresadas[],nodo *&iniciador,int &contador,string &palabra_true,string text){
	stringstream ss(palabras_ingresadas);
    string add_y_indice;
    getline(ss, add_y_indice, ';');
    stringstream jj(add_y_indice);
    string add;
    getline(jj, add, ' ');
    int indice;
    jj>>indice;
    string espacio;
    getline(jj,espacio, ' ');
    string letra;
    getline(jj,letra, ';');
    string nombre;
    getline(ss,nombre, ';');
    int duracion;
    ss>>duracion;
	if (add_y_indice=="print"){
		print(iniciador);
	}
	else if(add_y_indice=="info"){
		info(iniciador,contador);
	}
	else if(add_y_indice=="exit"){
		exit(iniciador,text);
		palabra_true=add_y_indice;
	}
	else if(add=="remove"){
		remover(iniciador,indice,contador);
	}
	else{
		add_i(iniciador,indice,letra,nombre,duracion,contador);
	}
	
};
void valores_archivo(nodo *&iniciador,int &contador,string texto){
	string valores;
	ifstream archivo(texto);
	if (archivo.is_open()){
		while(getline(archivo,valores)){
			stringstream ss(valores);
         	string letra;
         	getline(ss, letra, ';');
        	string nombre1;
         	getline(ss, nombre1, ';');
        	int num;
        	ss>>num;
        	insertar_final(iniciador,letra,nombre1,num);
         	contador++;
        }
	}
	archivo.close();
};