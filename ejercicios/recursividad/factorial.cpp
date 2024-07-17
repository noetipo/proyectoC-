//
// Created by Noe on 14/04/24.
//
#include <stdio.h>
int factorial(int numero){
    if(numero<=1){
        return 1;
    } else{
        printf("%i",numero);
        return (numero* factorial(numero-1));
    }
}
int main(){
    int resultado;
    resultado= factorial(5);
    printf("El resultado del factorial es %i",resultado);
    return 0;
}