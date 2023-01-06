#include <iostream>
#include <sstream>
#include "fx.hpp"
using namespace std;

int main(){
	nodo *p_hubert,*p_javiera,*p_john;
	nodo *head,*tail;
	bool x=true,prendida=false;
	char palabras[100];
	iniciar_pila(p_hubert,p_javiera,p_john);
	crear(head,tail);
	while (x){
		cout<<"";
		cin.getline(palabras,100,'\n');
		principal(palabras,x,prendida,p_hubert,p_javiera,p_john,head,tail);
	}
	return 0;
}
