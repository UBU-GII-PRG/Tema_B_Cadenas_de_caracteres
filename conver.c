/*
Programa:	conver.c
Sinopsis:	Introducción a la búsqueda de información en cadenas (strings)
		Leemos un fichero que contiene números y lo pasamos a un vector
		si la conversión numérica es correcta (atof)
@autor:		Paco González Moya
@date:		Abr 2018
@version:	1.0
*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAX_LINEA 80
#define MAX_NUMEROS 10
#define FICHERO "misdatos.txt"

int main() {
	FILE *fich;
	char linea[MAX_LINEA];	//línea de texto leída de fichero
	double numeros[MAX_NUMEROS];	//vector de números leídos de forma correcta
	int ok;	//valor de control para fscanf
	int numeros_validos=0;	//número de valores correctamente convertidos
	double valor;		//valor leído en cada momento
	int i;			//variable de control de bucle 

	//Por higiene, inicializamos el vector
	for (i=0;i<MAX_NUMEROS;i++) {
		numeros[i]=0.0;
	}

	//Comenzamos
	printf("-------------------------\n");
	printf("Contenido del fichero\n");
	printf("-------------------------\n");
	

	//Abrimos fichero (paso 1 del vals)
	fich=fopen(FICHERO, "r");
	if (!feof(fich)) {	//Comprobamos eof
		ok=fscanf(fich, "%s", linea);	//Lectura adelantada (paso 2)
		while (!feof(fich)) {	//comprobamos EOF
			//Si no hay EOF, procesamos
			if (ok>0) {
				printf("Leido: %s\n", linea);
				valor=atof(linea);
				if (valor==0) {
					printf("Imposible convertir %s\n", linea);
				} else {
					//Valor correcto
					if (numeros_validos < MAX_NUMEROS) {
						numeros[numeros_validos]=valor;
						//incrementamos el contador
						numeros_validos++;	
					} else {
						//No podemos almacenar más números
						printf("Valor %f correcto, no almacenable en vector\n", valor);


					}
				}		
			}
			//Lectura (paso 2 del vals)
			ok=fscanf(fich, "%s", linea);	//Lectura adelantada

		}
		//Paso 3 del vals: cierre
		ok=fclose(fich);

		//Mostramos el vector:
		printf("-------------------------\n");
		printf("Contenido del vector\n");
	 	printf("-------------------------\n");

		for (i=0;i<MAX_NUMEROS;i++) {
			printf("numeros[%d]=%f\n", i, numeros[i]);
		}
		

	}

	return 0;
}
