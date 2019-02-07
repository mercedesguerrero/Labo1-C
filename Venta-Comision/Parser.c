#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "Vendedor.h"
#include "Parser.h"

#define LIBRE 0
#define OCUPADO 1

void parsearVendedores(char* path, ArrayList* listaVendedores)
{

    FILE* f;
    eVendedor* nuevoVendedor;

    int cant;
    char buffer[6][128];

    f = fopen(path, "r");

    if(f != NULL && listaVendedores != NULL)
    {

        fscanf(f,"%[^,],%[^,],%[^,],%[^,],%s\n", buffer[0],buffer[1],buffer[2],buffer[3],buffer[4]);

        while( !feof(f))
        {

            cant =  fscanf(f,"%[^,],%[^,],%[^,],%[^,],%s\n", buffer[0],buffer[1],buffer[2],buffer[3],buffer[4]);

            if(cant == 6)
            {
                nuevoVendedor = newVendedor();

                if(nuevoVendedor != NULL)
                {
                    nuevoVendedor->id = atoi(buffer[0]);
                    strcpy(nuevoVendedor->nombre, buffer[1]);
                    nuevoVendedor->nivel = atoi(buffer[2]);
                    nuevoVendedor->cant_prod_vendidos =  atoi(buffer[3]);
                    nuevoVendedor->monto_vendido = atof(buffer[4]);

                    nuevoVendedor->comision = set_comision(nuevoVendedor, 2.3);
                    nuevoVendedor->isEmpty = set_isEmpty(nuevoVendedor, OCUPADO);

                    listaVendedores->add(listaVendedores, nuevoVendedor);// si

                    //al_add(listaVendedores, nuevoVendedor); no
                }
            }
            else
            {
                break;
            }
        }

        fclose(f);
    }



}

void guardarVendedores(char* path, ArrayList* listaVendedores)
{

    FILE* f;

    f = fopen(path, "w");
    eVendedor* unVendedor;

    if(f != NULL)
    {

        fprintf(f, "ID,Nombre,Nivel,Cant prod vendidos,Monto vendido\n");

        for(int i=0; i < listaVendedores->len(listaVendedores); i++)
        {
            unVendedor = (eVendedor*)listaVendedores->get(listaVendedores, i);
            fprintf(f,"%d,%s,%d,%d,%.2f\n", unVendedor->id, unVendedor->nombre, unVendedor->nivel, unVendedor->cant_prod_vendidos, unVendedor->monto_vendido);
        }

        fclose(f);

    }

}