/*
Programa:	asigna.c
Sinopsis:	Introducción a las asignaciones con cadenas (strings)
@autor:		Paco González Moya
@date:		May 2018
@version:	1.0
*/
#include<stdio.h>
#include<string.h>
#define MAX 10

int main() {
	char nombre[MAX]="Paco"; //aquí si se permite inicializar de esta manera
	char nombre_completo[3*MAX]="";
	int ok=0;
	
	//Podríamos asignar de forma "tradicional", pero esto no se permite en C
	//nombre="Francisco";
	
	ok+=printf("Mi nombre: %s\n", nombre); 
	
	//Emplearemos strcpy
	strcpy(nombre, "Francisco");
	ok=printf("Mi nombre: %s\n", nombre); 

	//Me voy a pasar de tamaño: error de ejecución
	//strcpy(nombre, "Francisco Javier");
	//ok=printf("Mi nombre: %s\n", nombre); 
	
	//Asignamos parte de una cadena:
	strcpy(nombre, "          "); //espacios
	strncpy(nombre, "Francisco", 4);
	ok=printf("Mi nombre: %s\n", nombre); 

	//Concatenamos
	strcat(nombre_completo, "Paco ");
	strcat(nombre_completo, "Gonzalez ");
	ok=printf("Mi nombre completo: %s\n", nombre_completo); 

	//Seguimos con strncat
	strncat(nombre_completo, "Moya", 3);
	ok=printf("Mi nombre completo: %s\n", nombre_completo); 

	//¿cómo "reseteo" mi cadena?
	strcpy(nombre, "Francisco");
	ok=printf("Mi nombre: %s\n", nombre); 
	strcpy(nombre, "\0"); //cuidado, como cadena, no como '\0'
	ok=printf("Mi nombre: %s\n", nombre); 


	return 0;
}
