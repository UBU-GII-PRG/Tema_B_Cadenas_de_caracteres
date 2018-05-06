/*
Programa:	entrada_salida.c
Sinopsis:	Introducción a la entrada / salida con cadenas (strings)
@autor:		Paco González Moya
@date:		Abr 2018
@version:	1.0
*/
#include<stdio.h>
#include<strings.h>
#define MAX 25
#define ENTRADA "datos.txt"

//Función para ve caracter a caracter la cadena
void inspeccionaCadena(char cadena[MAX]);

//Limpia cadena
void limpiar(char cadena[MAX]) ;

int main() {
	FILE *fich;	//Puntero al buffer
	int ok;		//Resultado de scanf
	char cadena[MAX];	//Cadena de caracteres

	//Leemos el fichero y escribimos sus cadenas
	//Recuerda que scanf finaliza la cadena leída al encontrar
	//el primer delimitador (espacio, intro, tabulador, etc...)
	/*fich=fopen(ENTRADA, "r");
	if (fich!=NULL) {
		ok=fscanf(fich, "%s", cadena);	//Lectura adelantada
		while (!feof(fich)) {
			printf("%s\n", cadena);
			ok=fscanf(fich, "%s", cadena);
		}	
	}
	fclose(fich);
	ok++;
	printf("\n");
*/
	//lo hacemos otra vez, con gets
	//gets admite espacios y otros caracteres en la cadena
	//es aconsejable "limpiar" la cadena de intros -> funcion limpiar
	fich=fopen(ENTRADA, "r");
	if (fich!=NULL) {
		fgets(cadena, 80, fich); //Entendemos que la línea mide 80 car

		limpiar(cadena);		//Limpiamos la cadena
		inspeccionaCadena(cadena);	//Inspeccionamos
		while (!feof(fich)) {
			puts(cadena);
			fgets(cadena, 80, fich);
			limpiar(cadena);
			inspeccionaCadena(cadena);
		}	
	}
	fclose(fich);
	ok++;



	return 0;
}

/**
	inspeccionaCadena (char cadena[MAX])
Objetivo: muestra una cadena caracter a caracter con su código ASCII
@param	E/ cadena	la cadena de caracteres
@return nada
	
*/
void inspeccionaCadena (char cadena[MAX])  {
	int i;

	for (i=0;i<MAX;i++) {
		printf("cadena[%d]-> %c ASCII %d\n", i, cadena[i], cadena[i]);
	
	}
	return;
}

/**
	limpia (char cahdena[MAX])
Objetivo: elimina de la cadena caracteres indeseados (INTRO's, etcc)
@param	E/S cadena		la cadena a limpiar
@return nada

*/

void limpiar(char cadena[MAX]) {
	int i;
	int longitud=0;

	for (i=0;i<MAX;i++) {
		switch (cadena[i]) {
		   case 10: cadena[i]=32;
			    break;	
		   default: longitud++;	
		}
					
	}
	cadena[longitud]='\0';
	return;
	
}


