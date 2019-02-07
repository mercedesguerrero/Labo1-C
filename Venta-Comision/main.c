#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "ArrayList.h"
#include "Vendedor.h"
#include "Parser.h"

#define JUNIOR 3
#define ESTANDARD 2
#define EXPERTO 1

#define LIBRE 0
#define OCUPADO 1

int menu();
void presionarContinuar();

int main()
{
    char seguir = 's';
    ArrayList* lista = al_newArrayList();

    if(lista == NULL)
    {
        printf("\nError: can't allocate memory");
        exit(1);
    }

    parsearVendedores("DATA.csv", lista);

    do
    {
        switch(menu())
        {

        case 1:
            newVendedorParametrizado(123, "Marcelo", ESTANDARD, 120, 2485.67, 25.3, OCUPADO);
            //agregarVendedor(lista, 3);
            presionarContinuar();
            break;
        case 2:
            mostrarVendedores(lista);
            presionarContinuar();
            break;
        case 3:

            break;
        case 4:

            system("pause");
            break;
        case 5:

            system("pause");
            break;
        case 6:

            system("pause");
            break;
        case 7:

            system("pause");
            break;
        case 8:

            system("pause");
            break;
        case 10:
            seguir = 'n';
            //guardarEmpleados("vendedores.csv", lista);
            break;
        }

    }while(seguir == 's');

    return 0;
}

int menu()
{
    int opcion;
    system("cls");
    printf("\n      ***Menu de Opciones***\n\n");
    printf("   1- Alta\n");
    printf("   2- Baja\n");
    printf("   3- Modificar\n");
    printf("   4- Listar\n");
    printf("   5- Listar todos los empleados de un sector\n");
    printf("   6- Ordenar empleados por sector y dentro del sector por nombre\n");
    printf("   7- Mostrar los datos de el o los empleados que mas ganan por sector\n");
    printf("   8- Crear Arraylist con empleados de Sistemas\n");
    printf("  10- Salir\n");
    printf("\n   Ingrese opcion: ");
    fflush(stdin);
    scanf("%d", &opcion);

    return opcion;
}

void presionarContinuar()
{
    printf("\nPresione cualquier tecla para continuar ");
    getch();
}
