/*
Programa:	compara.c
Sinopsis:	Introducción a la comparación de cadenas (strings)
@autor:		Paco González Moya
@date:		Abr 2018
@version:	1.0
*/
#include<stdio.h>
#include<string.h>
#define MAX 10

int main() {
	char cadena1[MAX]="Paco";
	char cadena2[MAX]="Antonio";
	int compara=-9;

	//Deberá ofrecer 1, dado que cadena1 > cadena2
	compara=strcmp(cadena1, cadena2);
	printf("Resultado comparación: %d\n", compara);

	//En este caso, la comparación ofrece -1 porque cadena1 < cadena2
	strcpy(cadena2, "Rosalia");
	compara=strcmp(cadena1, cadena2);
	printf("Resultado comparación: %d\n", compara);

	//Caso peculiar: cuidado con las mayúsculas. ¿Debería dar cero?
	strcpy(cadena2, "paco");
	compara=strcmp(cadena1, cadena2);
	printf("Resultado comparación: %d\n", compara);
	
	//Caso peculiar: cuidado con los espacios. ¿Debería dar cero?
	strcpy(cadena2, "Paco "); //termina en espacio en blanco
	compara=strcmp(cadena1, cadena2);
	printf("Resultado comparación: %d\n", compara);

	//Caso peculiar: cuidado con los caracteres acentuados. ¿Debería dar cero?
	strcpy(cadena2, "Páco"); // á
	compara=strcmp(cadena1, cadena2);
	printf("Resultado comparación: %d\n", compara);

	//Caso peculiar: ¿Por qué da cero?
	strcpy(cadena2, "Pacó"); // ó
	compara=strncmp(cadena1, cadena2, 3);
	printf("Resultado comparación: %d\n", compara);

	//strncmp es útil cuando pretendemos encontrar "prefijos"
	//en lugar de concidencias exactas
	strcpy(cadena1, "Burgalés");
	strcpy(cadena2, "Burgatti");
	compara=strncmp(cadena1, cadena2, 4);
	printf("Resultado comparación 'Burg': %d\n", compara);
	
	//la forma efectiva de saber la longitud lógica: strlen
	strcpy(cadena1, "Francisco");
	printf("Longitud lógica : %2d\n", strlen(cadena1));
	printf("Longitud física : %2d\n", sizeof(cadena1));
	
	return 0;

}
