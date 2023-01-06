#include <iostream>
#include <sstream>
#include "fx.hpp"
using namespace std;

void iniciar_pila(nodo *&pila1,nodo *&pila2,nodo *&pila3){
	pila1=NULL;
	pila2=NULL;
	pila3=NULL;
}

bool vacia(nodo *pila){
	if (pila==NULL){
		return true;
	}
	return false;
}

void push(nodo *&pila,string valor){
	nodo *aux=new nodo();
	aux->dato=valor;
	if (!vacia(pila)){
		aux->next=pila;
		pila=aux;
	}else{
		pila=aux;
	}
}

string top(nodo *pila){
	return (pila->dato);
}

void crear(nodo *&head,nodo *&tail){
	head=NULL;
	tail=NULL;
}

bool vacia2(nodo *head){
	if (head==NULL){
		return true;
	}else{
		return false;
	}
}

void insertar(nodo *&head,nodo *&tail,string datito){
	nodo *nuevo=new nodo();
	nuevo->dato=datito;
	nuevo->next=NULL;
	if (vacia(head)){
		head=nuevo;
	}else{
		tail->next=nuevo;
	}
	tail=nuevo;
}

void eliminar(nodo *&head){
	nodo *aux;
	aux=head;
	head=head->next;
	delete aux;
}

bool vacia3(nodo *pila1,nodo *pila2,nodo *pila3){
	if (pila1==NULL){
		if (pila2==NULL){
			if(pila3==NULL){
				return true;
			}
		}
	}
	return false;
}

void ingresar_a_cola(nodo *&pila1,nodo*&pila2,nodo*&pila3,nodo*&head,nodo*&tail){
	while (!vacia3(pila1,pila2,pila3)){
		if (!vacia(pila1)){
			insertar(head,tail,top(pila1));
			eliminar(pila1);
		}if (!vacia(pila2)){
			insertar(head,tail,top(pila2));
			eliminar(pila2);
		}if (!vacia(pila3)){
			insertar(head,tail,top(pila3));
			eliminar(pila3);
		}
	}
}

void print(nodo*&head){
	while(!vacia2(head)){
		cout<<head->dato<<endl;
		eliminar(head);
	}
}

void principal(char palabras[],bool &x,bool &prendida,nodo *&pila1,nodo *&pila2,nodo *&pila3,nodo *&head,nodo*&tail){
	string pal[50];
	int cont=0,contador=1,contador2;
	string c;
	stringstream jj(palabras);
	string cada_palabra;
    while(jj>>cada_palabra){
    	pal[cont]=cada_palabra;
    	cont++;
	}
	if (pal[0]=="turn" && pal[1]=="on" && pal[2]=="printer"){
		cout<<"the printer is on"<<endl;
		prendida=true;
	}
	else if(pal[0]=="read" && pal[1]=="documents"){
		if (prendida){
			ingresar_a_cola(pila1,pila2,pila3,head,tail);
		}else{
			cout<<"the printer is off"<<endl;
		}
		
	}
	else if(pal[0]=="print"){
		if (prendida){
			print(head);
		}else{
			cout<<"the printer is off"<<endl;
		}
		
	}
	else if (pal[0]=="turn" && pal[1]=="off" && pal[2]=="printer"){
		x=false;
	}
	else{
		for (int i=0;i<20;i++){
			if (pal[i]=="to"){
				contador=i;
			}
    	}
		for (int i=1;i<contador;i++){
			c+=pal[i]+" ";
		}
		contador++;
		if(pal[contador]=="hubert"){
			push(pila1,c);
		}else if(pal[contador]=="javiera"){
			push(pila2,c);
		}else if(pal[contador]=="john"){
			push(pila3,c);
		}
	}	
}