
//
// Created by Noe on 14/04/24.
//
#include <stdio.h>
int main(){
    float notaUno,notaDos,notaTres, promedio;
    printf("ingrese el valor de la primera nota: \n");
    scanf("%f",&notaUno);
    printf("ingrese el valor de la segunda nota: \n");
    scanf("%f",&notaDos);
    printf("ingrese el valor de la tercera nota: \n");
    scanf("%f",&notaTres);
    promedio= (notaUno+notaDos+notaTres)/3;
    printf("el promedio de de las calificaciones es: %.2f", promedio);

    return 0;
}