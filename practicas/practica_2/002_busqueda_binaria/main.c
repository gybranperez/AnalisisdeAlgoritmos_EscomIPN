//*****************************************************************
/*Elaborado por:
	Pérez Juarez Carlos Gybran
	Pérez Sereno Ricardo Erick
	Ramirez Flores Juan
*/
//M. EN C. EDGARDO ADRIÁN FRANCO MARTÍNEZ
//Curso: Análisis de algoritmos
//ESCOM-IPN
//Ejemplo de medición de tiempo en C y recepción de parametros en C bajo UNIX
//Compilación: "gcc main.c tiempo.c
//Ejecución: "./script.sh
//*****************************************************************

//*****************************************************************
//LIBRERIAS INCLUIDAS
//*****************************************************************
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tiempo.h"
//*****************************************************************
//DEFINICION DE CONSTANTES DEL PROGRAMA
//*****************************************************************

//********************************************************************************
//DECLARACION DE ESTRUCTURAS
//********************************************************************************

//*****************************************************************
//DECLARACIÓN DE FUNCIONES
//*****************************************************************
int BusquedaBinaria(int A[], int numeros, int n);
//*****************************************************************
//VARIABLES GLOBALES
//*****************************************************************

//*****************************************************************
//PROGRAMA PRINCIPAL
//*****************************************************************
int main(int argc, char *argv[])
{
	//******************************************************************
	//Variables del main
	//******************************************************************
	int n;				   //n determina el tamaño del algorito dado por argumento al ejecutar
	int i, j, bandera = 0; //Variables para loops
	int *A;
	int numeros[20] = {322468, 14700764, 3128036, 6337399, 61396, 10393545, 2147445644, 129539003, 450057883, 187645041, 1980098116, 152503, 5000, 1493283650, 214826, 1843349527, 1360839354, 2109248666, 2147470852, 0};
	n = atoi(argv[1]);

	int encontrados;
	//******************************************************************
	//Recepción y decodificación de argumentos
	//******************************************************************
	A = (int *)malloc(n * sizeof(int));
	for (i = 0; i < n; i++)
	{
		scanf("%d", &A[i]);
	}

	//******************************************************************
	//Algoritmo
	//******************************************************************
	for (i = 0; i < 20; i++)
	{
		double utime0, stime0, wtime0, utime1, stime1, wtime1; //Variables para medición de tiempos
		uswtime(&utime0, &stime0, &wtime0);
		encontrados = BusquedaBinaria(A, numeros[i], n);

		if (encontrados != -1)
		{
			printf("Se encontro el numero %d\n", numeros[i]);
		}
		else
		{
			printf("NO se encontro %d", numeros[i]);
		}

		//******************************************************************
		//Evaluar los tiempos de ejecución
		//******************************************************************
		uswtime(&utime1, &stime1, &wtime1);

		//Cálculo del tiempo de ejecución del programa
		printf("\n");
		printf("real (Tiempo total)  %.10f s\n", wtime1 - wtime0);
		printf("user (Tiempo de procesamiento en CPU) %.10f s\n", utime1 - utime0);
		printf("sys (Tiempo en acciónes de E/S)  %.10f s\n", stime1 - stime0);
		printf("CPU/Wall   %.10f %% \n", 100.0 * (utime1 - utime0 + stime1 - stime0) / (wtime1 - wtime0));
		printf("\n");

		//Mostrar los tiempos en formato exponecial
		printf("\n");
		printf("real (Tiempo total)  %.10e s\n", wtime1 - wtime0);
		printf("user (Tiempo de procesamiento en CPU) %.10e s\n", utime1 - utime0);
		printf("sys (Tiempo en acciónes de E/S)  %.10e s\n", stime1 - stime0);
		printf("CPU/Wall   %.10f %% \n", 100.0 * (utime1 - utime0 + stime1 - stime0) / (wtime1 - wtime0));
		printf("\n");
		//******************************************************************
		printf("-------------------------------------------------------------------------------------------------------");
		//Terminar programa normalmente
	}
	//******************************************************************
	return 0;
}

//************************************************************************
//Esta función recibe un arreglo de enteros, un numero a buscar y el tamaño del arreglo
//Devuelve -1 si no se encontro el numero.
//************************************************************************
int BusquedaBinaria(int A[], int numeros, int n)
{
	int inferior = 0, superior = n - 1, centro = 0;

	while (inferior <= superior)
	{
		centro = (superior + inferior) / 2;
		if (A[centro] == numeros)
		{
			return centro;
		}
		else if (numeros < A[centro])
			superior = centro - 1;
		else
			inferior = centro + 1;
	}
	return -1;
}
