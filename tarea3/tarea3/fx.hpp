#ifndef FX_HPP
#define FX_HPP
#include <iostream>
#include <sstream>
using namespace std;

struct nodo{
	string dato;
	nodo *next;
};

void iniciar_pila(nodo *&pila1,nodo *&pila2,nodo *&pila3);
bool vacia(nodo *pila);
void push(nodo *&pila,string valor);
string top(nodo *pila);
void crear(nodo *&head,nodo *&tail);
bool vacia2(nodo *head);
void insertar(nodo *&head,nodo *&tail,string datito);
void eliminar(nodo *&head);
bool vacia3(nodo *pila1,nodo *pila2,nodo *pila3);
void ingresar_a_cola(nodo *&pila1,nodo*&pila2,nodo*&pila3,nodo*&head,nodo*&tail);
void print(nodo*&head);
void principal(char palabras[],bool &x,bool &prendida,nodo *&pila1,nodo *&pila2,nodo *&pila3,nodo *&head,nodo*&tail);

#endif