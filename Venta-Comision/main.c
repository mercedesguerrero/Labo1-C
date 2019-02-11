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
            respuesta= seleccionarNivel();

            switch(respuesta)
            {
                case 0:
                    if(guardarArchivoVendedores("EXPERTOS.csv", lista->filter(lista, filtrarPorExperto))==1)
                    {
                        mostrarVendedores(lista->filter(lista, filtrarPorExperto));
                        printf("\n\n Se creo el archivo de vendedores nivel EXPERTO\n");
                    }
                    break;
                case 1:
                    if(guardarArchivoVendedores("ESTANDARD.csv", lista->filter(lista, filtrarPorEstandard))==1)
                    {
                        mostrarVendedores(lista->filter(lista, filtrarPorEstandard));
                        printf("\n\n Se creo el archivo de vendedores nivel ESTANDARD\n");
                    }
                    break;
                case 2:
                    if(guardarArchivoVendedores("JUNIOR.csv", lista->filter(lista, filtrarPorJunior))==1)
                    {
                        mostrarVendedores(lista->filter(lista, filtrarPorJunior));
                        printf("\n\n Se creo el archivo de vendedores nivel JUNIOR\n");
                    }
                    break;
            }

            presionarContinuar();
            break;
        case 5:
            if(agregarVendedor(lista)==1)
            {
                printf("\n");
                printf("\nSe agrego vendedor\n");
                guardarArchivoVendedores("DATA.csv", lista);
            }
            else
            {
                printf("\nError\n");
            }
            presionarContinuar();
            break;
        case 6:
            modificarVendedor(lista);
            guardarArchivoVendedores("DATA.csv", lista);
            presionarContinuar();
            break;
        case 7:
            eliminarVendedor(lista);
            guardarArchivoVendedores("DATA.csv", lista);
            presionarContinuar();
            break;
        case 8:
            newVendedorParametrizado(123, "Marcelo", ESTANDARD, 120, 2485.67);
            //agregarVendedor(lista, 3);
            presionarContinuar();
            break;
        case 9:
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
    printf("   5- ALTA vendedor\n");
    printf("   6- MODIFICAR vendedor-\n");
    printf("   7- ELIMINAR vendedor-\n");
    printf("   8- Hardcodear vendedor-\n");
    printf("   9- Salir\n");
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
