/*
Autor:			Jorge David Chinchilla
Fecha:			03-05-2022
Compilador:			gcc (Ubuntu 9.3.0-17ubuntu1~20.04) 9.3.0
Compilar:			gcc -o MC.out MC.c
Librerias:			stdio, math, stdlib
Resumen:			Metodo de minimos cuadrados para una serie de datos
*/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
//Declaracion de vectores iniciales
float x[]={1,3,8,11,14,18}, y[]={2.1,3.0,5.2,7.1,9.2,10.1};
//Obtencion del tamanio del vector
int n = sizeof(x)/sizeof(x[0]);


//Declaracion de funciones
void imprimir(float datos[]);
float suma(float datos[]);
float sumaMulti(float datos1[], float datos2[]);

//Declaracion de variables y creacion de los calculos para obtener la recta por
//minimos cuadrados y la aproximacion de la velocidad a un valor dado
//Tambien se crea el archivo de datos para la recta obtenida por M. C.
void main(){
	float b, m, x1, x2, x3, y1, y2, y3;
	m = (n*sumaMulti(x,y)-(suma(x)*suma(y)))/(n*sumaMulti(x,x)-(suma(x)*suma(x)));
	b = (suma(y)-m*suma(x))/n;
	x1 = 0;
	x2 = 20;
	x3 = 15;
	y1 = m*x1 + b;
	y2 = m*x2 + b;
	y3 = m*x3 + b;
	FILE* fichero;
	fichero = fopen("MC", "wt");
	fprintf(MC, "%f\t%f\n", x1, y1);
	fprintf(MC, "%f\t%f\n", x2, y2);
	fclose(fichero);
	return 0;
	
}

//Presentacion de resultados
void imprimir(float datos[]){
	puts("\nLos datos de la recta son:\n");
	printf("La pendiente (aceleracion) = %f y la constante b = %f\n", m, b);
	printf("La velocidad a los 15 segundos será aproximadamente de %f m/s.", y3);
	puts("\nFin");
}

//Funcion suma
float suma(float datos[]){
	float resp = 0;
	for (int i = 0; i < n; i++){
		resp += datos[i];
	}
	return resp;
}
//Funcion multiplicacion
float sumaMulti(float datos1[], float datos2[]){
	float resp = 0;
	for (int i = 0; i < n; i++){
		resp += datos1[i]*datos2[i];
	}
	return resp;
}
