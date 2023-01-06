#include <iostream>
#include "fx.hpp"
using namespace std;


void sumar_arreglo(int arr[][5]){
	
	for (int i=0;i<5;i++){
		int suma=0;
		suma=arr[0][i]+arr[1][i];
		arr[2][i]=suma;
	}
}
void resta_arreglo(int arr[][5]){
	
	for (int i=0;i<5;i++){
		int resta=0;
		resta=arr[0][i]-arr[1][i];
		arr[3][i]=resta;
	}
}
void multiplicar_arreglo(int arr[][5]){
	
	for (int i=0;i<5;i++){
		int multiplicar=0;
		multiplicar=arr[0][i]*arr[1][i];
		arr[4][i]=multiplicar;
	}
}

float promedio(int arr[][5]){
	float suma=0;
	for(int i=0;i<5;i++){
		for(int j=0;j<5;j++){
			suma+=arr[i][j];
		}
	}
	return (suma/25);
	
}

void print_resultado(int arr[][5]){
	for(int i=0;i<5;i++){
		for (int j=0;j<5;j++){
			cout<<arr[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<promedio(arr)<<endl;
}
