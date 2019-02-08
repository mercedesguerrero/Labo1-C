#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "Arraylist.h"
#include "Vendedor.h"
#include "Parser.h"

#define JUNIOR 2
#define ESTANDARD 1
#define EXPERTO 0

#define LIBRE 0
#define OCUPADO 1

int menu();
void presionarContinuar();
int getInt(char* mensaje);

int main()
{
    char seguir = 's';
    ArrayList* lista = al_newArrayList();

    int respuesta;

    if(lista == NULL)
    {
        printf("\nError: can't allocate memory");
        exit(1);
    }

    do
    {
        switch(menu())
        {

        case 1:
            parsearVendedores("DATA.csv", lista);
            printf("\nSe cargaron los vendedores\n");
            presionarContinuar();
            break;
        case 2:
            mostrarVendedores(lista);
            presionarContinuar();
            break;
        case 3:
            lista->map(lista, calcularComision);
            mostrarVendedores(lista);
            presionarContinuar();
            break;
        case 4:
            system("cls");
            printf("  1- EXPERTO |   2- ESTANDARD |   3- JUNIOR\n\n");
            respuesta= getInt("Ingrese el numero asociado al nivel para el que desea generar la lista: ");

            switch(respuesta)
            {
                case 1:
                    mostrarVendedores(lista->filter(lista, filtrarPorExperto));
                    break;
                case 2:
                    mostrarVendedores(lista->filter(lista, filtrarPorEstandard));
                    break;
                case 3:
                    mostrarVendedores(lista->filter(lista, filtrarPorJunior));
                    break;
            }

            presionarContinuar();
            break;
        case 5:
            newVendedorParametrizado(123, "Marcelo", ESTANDARD, 120, 2485.67);
            //agregarVendedor(lista, 3);
            presionarContinuar();
            break;
        case 6:

            presionarContinuar();
            break;
        case 7:

            presionarContinuar();
            break;
        case 8:

            presionarContinuar();
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
    printf("   1- Cargar archivo\n");
    printf("   2- Imprimir vendedores\n");
    printf("   3- Calcular comisiones\n");
    printf("   4- Generar archivo de comisiones para nivel\n");
    printf("   5- Vendedor hardcodeado\n");
    printf("   6- -\n");
    printf("   7- -\n");
    printf("   8- -\n");
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

int getInt(char* mensaje)
{
    int auxiliar;
    printf("%s",mensaje);
    scanf("%d",&auxiliar);

    return auxiliar;
}
