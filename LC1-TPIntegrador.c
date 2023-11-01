#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estrucura para Cliente
struct Cliente
{
    int DNI;
    char pass[10];
    char nombre[50];
    float saldo;
    int estado;
};

// Declaración de funciones
int iniciarSesion(struct Cliente clientes[], int num_clientes, int *cliente_actual);
void mostrarMenu(struct Cliente clientes[], int cliente_actual);

int main()
{
    // Crear una lista de clientes de ejemplo
    struct Cliente clientes[] = {
        {12345678, "rambado678", "MRambado", 565000.0, 1},
        {23456789, "garcia789", "NGarcia", 784000.0, 1},
        {34567890, "Ramirez890", "RDCarlos", 295500.0, 1},
        {45678901, "123456", "Cliente10", 300000.0, 0}, // Cliente bloqueado
        {56789012, "123456", "Cliente15", 350000.0, 1}};
    int num_clientes = 5;

    int cliente_actual = -1;
    int intentos = 0;
    
    while (intentos < 3)
    {
        if (iniciarSesion(clientes, num_clientes, &cliente_actual) == 1)
        {
            printf("Inicio de sesión exitoso.\n");
            if (clientes[cliente_actual].estado == 1)
            {
                mostrarMenu(clientes, cliente_actual);
            }
            else
            {
                printf("Su cuenta está bloqueada; comuníquese con la entidad bancaria.\n");
            }
            break; // Sale del bucle si el inicio de sesión es exitoso
        }
        else
        {
            intentos++;
            if (intentos < 3)
            {
                printf("Número de DNI o contraseña incorrecta. Intento %d de 3.\n", intentos);
            }
            else
            {
                printf("No se permiten más intentos. Su cuenta ha sido bloqueada; comuníquese con la entidad bancaria.\n");
            }
        }
    }

    return 0;
}

int iniciarSesion(struct Cliente clientes[], int num_clientes, int *cliente_actual)
{
    int DNI;
    char pass[10];

    printf("Número de DNI: ");
    scanf("%d", &DNI);
    printf("Contraseña: ");
    scanf("%s", pass);

    for (int i = 0; i < num_clientes; i++)
    {
        if (clientes[i].DNI == DNI && strcmp(clientes[i].pass, pass) == 0)
        {
            *cliente_actual = i;
            return 1;
        }
    }

    // Si no se encuentra el cliente
    return 0;
}

void mostrarMenu(struct Cliente clientes[], int cliente_actual)
{
    // Mostrar el menú
    printf("Menú:\n");
    printf("1. Realizar un Depósito\n");
    printf("2. Realizar una Extracción\n");
    printf("3. Consultar el Saldo de la Cuenta\n");
    printf("4. Realizar una Transferencia entre Cuentas\n");
    printf("5. Mostrar cantidad de Operaciones Realizadas y Saldo Actual\n");
    printf("6. Salir de la Sesión\n");
}