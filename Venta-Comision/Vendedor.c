#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Arraylist.h"
#include "Vendedor.h"
#include "Parser.h"

#define LIBRE 0
#define OCUPADO 1

//CONSTRUCTOR

eVendedor* newVendedor()
{
    eVendedor* nuevoVendedor = (eVendedor*)malloc(sizeof(eVendedor));

    if(nuevoVendedor != NULL)
    {
        nuevoVendedor->id = 0;
        strcpy(nuevoVendedor->nombre, "");
        nuevoVendedor->nivel = 0;
        nuevoVendedor->cant_prod_vendidos = 0;
        nuevoVendedor->monto_vendido = 0;
        nuevoVendedor->comision = 0;
        nuevoVendedor->isEmpty = LIBRE;
    }

    return nuevoVendedor;
}

//CONSTRUCTOR PARAMETRIZADO

eVendedor* newVendedorParametrizado(int _id, char* _nombre, int nivel, int _cant_prod_vendidos, float _monto_vendido)
{
    eVendedor* nuevoVendedor = (eVendedor*)malloc(sizeof(eVendedor));

    if(nuevoVendedor != NULL)
    {
        nuevoVendedor->id = _id;
        strcpy(nuevoVendedor->nombre, _nombre);
        nuevoVendedor->nivel = 0;
        nuevoVendedor->cant_prod_vendidos = _cant_prod_vendidos;
        nuevoVendedor->monto_vendido = _monto_vendido;
        nuevoVendedor->comision = 0.0;
        nuevoVendedor->isEmpty = OCUPADO;
    }

    mostrarVendedor(nuevoVendedor);

    return nuevoVendedor;
}

//SETTERS

int set_id(eVendedor* unVendedor, int valor)
{
    int ret = 0;
    if(unVendedor!=NULL && valor>0)
    {
        unVendedor->id= valor;
        ret = 1;
    }
    return ret;
}

int set_nombre(eVendedor* unVendedor, char* _nombre)
{
    int ret = 0;
    if(unVendedor!=NULL && _nombre!=NULL)
    {
        strcpy(unVendedor->nombre, _nombre);
        ret = 1;
    }
    return ret;
}

int set_nivel(eVendedor* unVendedor, int valor)
{
    int ret = 0;
    if(unVendedor!=NULL && valor>0)
    {
        unVendedor->nivel= valor;
        ret = 1;
    }
    return ret;
}

int set_cant_prod_vendidos(eVendedor* unVendedor, int valor)
{
    int ret = 0;
    if(unVendedor!=NULL && valor>0)
    {
        unVendedor->cant_prod_vendidos= valor;
        ret = 1;
    }
    return ret;
}

int set_monto_vendido(eVendedor* unVendedor, float valor)
{
    int ret = 0;
    if(unVendedor!=NULL && valor>0)
    {
        unVendedor->monto_vendido= valor;
        ret = 1;
    }
    return ret;
}

int set_comision(eVendedor* unVendedor, float valor)
{
    int ret = 0;
    if(unVendedor!=NULL && valor>0)
    {
        unVendedor->comision= valor;
        ret = 1;
    }
    return ret;
}

int set_isEmpty(eVendedor* unVendedor, int valor)
{
    int ret = 0;
    if(unVendedor!=NULL && valor>0)
    {
        unVendedor->isEmpty= valor;
        ret = 1;
    }
    return ret;
}

//GETTERS
int get_id(eVendedor* unVendedor)
{
    int valor = -1;
    if(unVendedor!=NULL)
    {
        valor= unVendedor->id;
    }
    return valor;
}

char* get_nombre(eVendedor* unVendedor)
{
    char* _nombre;
    if(unVendedor!=NULL)
    {
       _nombre= unVendedor->nombre;
    }
    return _nombre;
}

int get_nivel(eVendedor* unVendedor)
{
    int valor = -1;
    if(unVendedor!=NULL)
    {
        valor= unVendedor->nivel;
    }
    return valor;
}

char* cargarDescripcion(int valor)
{
    char* descrip;
    switch(valor)
    {
        case 0:
            descrip= "Experto";
            break;
        case 1:
            descrip= "Estandar";
            break;
        case 2:
            descrip= "Junior";
            break;
    }

    return descrip;
}

int get_cant_prod_vendidos(eVendedor* unVendedor)
{
    int valor = -1;
    if(unVendedor!=NULL)
    {
        valor= unVendedor->cant_prod_vendidos;
    }
    return valor;
}

float get_monto_vendido(eVendedor* unVendedor)
{
    float valor = -1;
    if(unVendedor!=NULL)
    {
        valor= unVendedor->monto_vendido;
    }
    return valor;
}

float get_comision(eVendedor* unVendedor)
{
    float valor = -1;
    if(unVendedor!=NULL)
    {
        valor= unVendedor->comision;
    }
    return valor;
}

int get_isEmpty(eVendedor* unVendedor)
{
    int valor = -1;
    if(unVendedor!=NULL)
    {
        valor= unVendedor->isEmpty;
    }
    return valor;
}

//----------------------------------------------------------------------------------

void agregarVendedor(ArrayList* vendedores, int _nivel)
{
    eVendedor* nuevoVendedor;

    int esta;
    int id;

    system("cls");
    printf("\n   *** Alta Vendedor ***\n\n");


    printf(" Ingrese id: ");
    scanf("%d", &id);

    esta = buscarVendedor(vendedores, id);

        if(esta != -1)
        {
            printf("Existe un Vendedor con el id %d\n", id);
            //mostrarVendedor((eVendedor*)vendedores->get(vendedores,esta));
        }
        else
        {
            nuevoVendedor = newVendedor();

            if(nuevoVendedor != NULL){

            nuevoVendedor->id = id;

            printf(" Ingrese nombre: ");
            fflush(stdin);
            gets(nuevoVendedor->nombre);

            printf(" Ingrese cantidad de productos vendidos: ");
            fflush(stdin);
            scanf("%d", &nuevoVendedor->cant_prod_vendidos);

            printf(" Ingrese monto vendido: ");
            fflush(stdin);
            scanf("%f", &nuevoVendedor->monto_vendido);

            nuevoVendedor->nivel = _nivel;

            nuevoVendedor->isEmpty = 1;

            vendedores->add(vendedores, nuevoVendedor);

            }
    }
    printf("\n");

}

void mostrarVendedor(eVendedor* unVendedor)
{
    //printf("%f\n", unVendedor->comision);
    if(get_comision(unVendedor)== 0)
    {
        printf(" %4d  %14s  %12s    %12d     %12.2f     %12s\n\n", get_id(unVendedor), get_nombre(unVendedor), cargarDescripcion(unVendedor->nivel), get_cant_prod_vendidos(unVendedor), get_monto_vendido(unVendedor), "No se calcula");
    }
    else
    {
        printf(" %4d  %14s  %12s    %12d     %12.2f     %12.2f\n\n", get_id(unVendedor), get_nombre(unVendedor), cargarDescripcion(unVendedor->nivel), get_cant_prod_vendidos(unVendedor), get_monto_vendido(unVendedor), unVendedor->comision);
    }
}

void mostrarVendedores(ArrayList* lista)
{
    eVendedor* unVendedor;
    system("cls");
    printf("---------------------------------------------------------------------------------------------\n");
    printf("   ID   |     Nombre    |    Nivel    | Prods Vendidos |   Monto Vendido    |    Comision\n");
    printf("---------------------------------------------------------------------------------------------\n\n");
    for(int i=0; i< lista->len(lista); i++)
    {
        unVendedor = (eVendedor*) lista->get(lista, i);
        if( unVendedor->isEmpty == OCUPADO)
        {
            mostrarVendedor(unVendedor);
        }
    }
    printf("---------------------------------------------------------------------------------------------\n\n");
}

int buscarVendedor(ArrayList* lista, int id)
{
    int indice = -1;
    eVendedor* unVendedor;

    for(int i=0; i < lista->len(lista); i++)
    {
        unVendedor = (eVendedor*)lista->get(lista, i);
        if( unVendedor->id == id && unVendedor->isEmpty == 1)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

int calcularComision(eVendedor* unVendedor)
{
    float comision;
    int ret_aux=-1;

    switch(get_nivel(unVendedor))
    {
        case 2:
            comision= get_monto_vendido(unVendedor)*2/100;
            ret_aux=1;
            break;
        default:
            if(get_cant_prod_vendidos(unVendedor)>100)
            {
                comision= get_monto_vendido(unVendedor)*5/100;
                ret_aux=1;
                break;
            }
            else
            {
                comision= get_monto_vendido(unVendedor)*3.5/100;
                ret_aux=1;
            }
            break;
    }

    if(ret_aux==1)
    {
        set_comision(unVendedor, comision);
    }

    return ret_aux;
}

int filtrarPorNivel(eVendedor* unVendedor)
{

}

