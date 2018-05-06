/*
Programa:	cadenas.c
Sinopsis:	Introducción a la declaración y uso de cadenas (strings)
@autor:		Paco González Moya
@date:		Abr 2018
@version:	1.0
*/
#include<stdio.h>
#include<string.h>
#define MAX 10

int main () {
	int i;	//Variable de control de bucle

	//Declaración de una cadena de caracteres;
	char nombre[MAX]="Paco";	//Como un array de caracteres
	char apellidos[]="Gonzalez";	//Como un array de dimensión no determinada
	char apodo[MAX];	//Vector de caracteres (no cadena)

	apodo[0]='p';
	apodo[1]='a';
	apodo[2]='c';
	apodo[3]='o';

	//Nótese el uso de comilla doble o simple, según el caso
	
	//Recorremos la primera cadena
	for (i=0;i<MAX;i++) {
		printf("nombre[%d]-> %c ASCII %d\n", i, nombre[i], nombre[i]);
	}
	printf("\n\n");

	//Recorremos el vector de caracteres
	for (i=0;i<MAX;i++) {
		printf("apodo[%d]-> %c ASCII %d\n", i, apodo[i], apodo[i]);
	}
	
	return 0;
}

