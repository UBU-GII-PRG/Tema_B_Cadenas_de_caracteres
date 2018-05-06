/*
Programa:	compara.c
Sinopsis:	Introducción a la búsqueda de información en cadenas (strings)
@autor:		Paco González Moya
@date:		Abr 2018
@version:	1.0
*/
#include<stdio.h>
#include<string.h>
#define MAX 10

int main() {
	char cadena1[MAX]="afd8cRt98b";	//cadena para pruebas
	char *resul; //subcadena resultante de la busqueda. 
		    //Observa esta declaración. ¿Tamaño?
	int longitud;

	//Cadena original
	printf("Cadena    : %s\n", cadena1);


	//Buscamos la posición del primer 8 y obtenemos la subcadena que encabeza
	resul=strchr(cadena1, '8');
	printf("Resultado1: %s\n", resul);

	//Buscamos la última subcadena encabezada por 8 
	resul=strrchr(cadena1, '8');
	printf("Resultado2: %s\n", resul);

	//podemos usar también memchr, que permite iniciar la búsqueda en los primeros n caracteres. ¿Por qué no lo encuentra?
	resul=memchr(cadena1, '8', 3);
	printf("Resultado3: %s\n", resul);

	//usamos strcspn para encontrar la primera 
	//posición hasta encontrar la secuencia 8c
	longitud=strcspn(cadena1, "8c");
	printf("Resultado4: %d\n", longitud);




	return 0;
}
