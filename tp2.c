#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int intentosFallidos[10];

    // Inicializar datos de clientes (esto es un ejemplo, puedes personalizar los datos)

    char numeroCuenta[10][9] = {"12345678", "12345677", "12345676", "12345675", "12345674", "12345673", "12345672", "12345671", "12345670", "12345679"};
    char contrasenia[10][20] = {"pass1", "pass2", "pass3", "pass4", "pass5", "pass6", "pass7", "pass8", "pass9", "pass99"};
    char nombres[10][50] = {"Matias Rambado", "Nair Gracia", "Carlos Ramirez", "Valeria Perez", "Marcelo Denis", "Nicolas Canil", "Cristian Rodriguez", "Celeste Plano", "Leonela Oricain", "Anita Zapata"};
    float saldo[10] = {450000.0, 598000.0, 700000.0, 999000.0, 190000.0, 267000.0, 350987.0, 123000.0, 98000.0, 568098.0};
    char estadoCuenta[10][10] = {"Activo", "Activo", "Activo", "Activo", "Activo", "Activo", "Activo", "Activo", "Activo", "Activo"};

    // Declarar variables adicionales
    int clienteActual;
    int intentosMaximos;
    int operacionesRealizadas = 0;
    float saldoActual;
    int opcion;
    char contraseniaIngresada[20];
    char dniIngresado[10];

    // Mostrar mensaje de bienvenida
    printf("Bienvenido al Cajero Autom%ctico\n", 160);

    // Solicitar número de cuenta
    printf("Ingrese su n%cmero de cuenta: ", 163);
    scanf("%s", dniIngresado);

    // Solicitar contraseña
    printf("Ingrese su contrase%ca: ", 164);
    scanf("%s", contraseniaIngresada);
    
    for (clienteActual = 0; clienteActual < 10; ++clienteActual) 
    {
        if (strcmp(numeroCuenta[clienteActual], dniIngresado) == 0 && strcmp(contrasenia[clienteActual], contraseniaIngresada) == 0) 
        {
            printf("Bienvenido %s", nombres[clienteActual]);
            
            
        }
    }
    
    

    // Verificar credenciales
    //if (clienteActual >= 100 && clienteActual <= 999)
    //{
        //clienteActual = clienteActual - 100;
    //}
    /*if (strcmp(contrasenia[clienteActual], contraseniaIngresada) == 0 && strcmp(estadoCuenta[clienteActual], "Activo") == 0)
    {
        printf("Inicio de sesi%cn exitoso. Bienvenido, %s.\n", 162, nombres[clienteActual]);
        intentosMaximos = 3;
        intentosFallidos[clienteActual] = 0;

        do
        {
            // Mostrar el menú
            printf("1. Realizar un Dep%csito\n", 162);
            printf("2. Realizar una Extracci%cn\n", 162);
            printf("3. Consultar el Saldo de la Cuenta\n");
            printf("4. Realizar una Transferencia entre Cuentas\n");
            printf("5. Mostrar cantidad de Operaciones Realizadas y Saldo Actual\n");
            printf("6. Salir de la Sesi%cn\n", 162);
            printf("Ingrese la opci%cn deseada: ", 162);
            scanf("%d", &opcion);

            // Implementar las operaciones según la opción seleccionada
            switch (opcion)
            {
            case 1:
                // Realizar un depósito
                printf("Ingrese la cantidad a depositar: ");
                float cantidadDeposito;
                scanf("%f", &cantidadDeposito);
                saldo[clienteActual] += cantidadDeposito;
                break;

            case 2:
                // Realizar una extracción
                printf("Ingrese la cantidad a extraer: ");
                float cantidadExtraccion;
                scanf("%f", &cantidadExtraccion);
                if (cantidadExtraccion > saldo[clienteActual])
                {
                    printf("Saldo insuficiente. Operaci%cn cancelada.\n", 162);
                }
                else
                {
                    saldo[clienteActual] -= cantidadExtraccion;
                }
                break;

            case 3:
                // Consultar el saldo de la cuenta
                printf("Su saldo actual es: %.2f\n", saldo[clienteActual]);
                break;

            case 4:
                // Realizar una transferencia
                printf("Ingrese el n%cmero de cuenta destino: ",163);
                int cuentaDestino;
                scanf("%d", &cuentaDestino);

                // Verificar si la cuenta destino es válida
                if (cuentaDestino >= 100 && cuentaDestino <= 999 && cuentaDestino != clienteActual + 100)
                {
                    printf("Ingrese la cantidad a transferir: ");
                    float cantidadTransferir;
                    scanf("%f", &cantidadTransferir);

                    // Verificar si hay suficiente saldo en la cuenta actual
                    if (cantidadTransferir <= saldo[clienteActual])
                    {
                        // Realizar la transferencia
                        saldo[clienteActual] -= cantidadTransferir;
                        saldo[cuentaDestino - 100] += cantidadTransferir;
                        printf("Transferencia exitosa a la cuenta %d.\n", cuentaDestino);
                    }
                    else
                    {
                        printf("Saldo insuficiente para realizar la transferencia.\n");
                    }
                }
                else
                {
                    printf("N%cmero de cuenta destino no v%clido.\n", 163, 160);
                }
                break;

            case 5:
                // Mostrar cantidad de operaciones realizadas y saldo actual
                printf("Operaciones realizadas: %d\n", operacionesRealizadas);
                printf("Saldo actual: %.2f\n", saldo[clienteActual]);
                break;

            case 6:
                // Salir de la sesión
                printf("Sesi%cn finalizada. Gracias por utilizar nuestro cajero autom%ctico.\n", 162, 160);
                break;
            default:
                // Opción no válida
                printf("Opci%cn no v%clida. Int%cntelo de nuevo.\n", 162, 160, 130);
                break;
            }

            operacionesRealizadas++;

            // Verificar límite de operaciones
            if (operacionesRealizadas >= 10)
            {
                printf("Ha alcanzado el l%cmite de operaciones. Gracias.\n", 161);
            }
        } while (opcion != 6);
    }
    else
    {
        printf("N%cmero de cuenta o contrase%ca incorrecta.\n", 163, 164);
        intentosFallidos[clienteActual]++;

        // Verificar límite de intentos fallidos
        if (intentosFallidos[clienteActual] >= intentosMaximos)
        {
            printf("No se permiten m%cs intentos. Su cuenta ha sido bloqueada; comun%cquese con la entidad bancaria.\n", 160, 161);
            sprintf(estadoCuenta[clienteActual], "Bloqueado");
        }
    }*/

    return 0;
    //system("pause");
}