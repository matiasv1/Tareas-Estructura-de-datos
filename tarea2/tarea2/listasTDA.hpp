#ifndef FX_HPP
#define FX_HPP
#include<string>

struct datos{
	std::string letra;
	std::string nombre;
	int duracion;
};
struct nodo{
	datos valores_todos;
	nodo *siguiente;
};
void insertar_final(nodo *&iniciador,std::string letra,std::string nombre,int duracion);
void info(nodo *iniciador,int contador);
void print(nodo *iniciador);
void inserta_puesto(nodo *iniciador,std::string letra1,std::string nombre1,int duracion1);
void add_i(nodo *iniciador,int index,std::string letra,std::string nombre,int duracion,int &contador);
void remover_por_index(nodo *puntero_antes);
void remover(nodo *iniciador,int index,int &contador);
void remover_principal(nodo*&cabecera);
void eliminar(nodo*&cabecera);
void exit(nodo*&iniciador,std::string texto);
void ingreso_usuario(char palabras_ingresadas[],nodo *&iniciador,int &contador,std::string &palabra_true,std::string text);
void valores_archivo(nodo *&iniciador,int &contador,std::string texto);

#endif