#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Estrucura para Cliente
struct Cliente {
    int DNI;
    char pass[10];
    char nombre[50];
    float saldo;
    int estado;
};