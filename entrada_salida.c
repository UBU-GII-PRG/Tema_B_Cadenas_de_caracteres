/*
Programa:	entrada_salida.c
Sinopsis:	Introducción a la entrada / salida con cadenas (strings)
@autor:		Paco González Moya
@date:		Abr 2018
@version:	1.0
*/
#include<stdio.h>
#include<strings.h>
#define MAX 10

int main() {
	int i;			//Variable de control de bucle
	char nombre[MAX];	//cadena para el nombre
	char apellido[MAX];	//cadena para el apellido
	int ok;			//variable de resultado de scanf

	printf("Dime tu apellido: ");
	gets(apellido);
	printf("\nTe apellidas: %s\n", apellido);
	
	printf("\ndeletreando:\n");

	//Recorremos la cadena
	for (i=0;i<MAX;i++) {
		printf("apellido[%d]-> %c ASCII %d\n", i, apellido[i], apellido[i]);
	}

	printf("\nDime tu nombre: ");
	ok=scanf("%s", nombre);

	printf("\nResultado: %d deletreando:\n", ok);
	//Recorremos la cadena
	for (i=0;i<MAX;i++) {
		printf("nombre[%d]-> %c ASCII %d\n", i, nombre[i], nombre[i]);
	}
	printf("\n\nTe llamas: %s\n", nombre);



	return 0;

}
