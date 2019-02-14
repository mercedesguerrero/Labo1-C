#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Arraylist.h"
#include "Vendedor.h"
#include "Parser.h"

#define LIBRE 0
#define OCUPADO 1

#define JUNIOR 2
#define ESTANDARD 1
#define EXPERTO 0

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

int agregarVendedor(ArrayList* vendedores)
{
    eVendedor* nuevoVendedor;

    int esta;
    int id;
    int retorno= -1;
    char aux_nombre[30];
    float aux_float;

    system("cls");
    printf("\n   *** Alta Vendedor ***\n\n");

    id= getInt(" Ingrese id: ");
    fflush(stdin);

    esta = buscarVendedor(vendedores, id);

        if(esta != -1)
        {
            printf("Existe un Vendedor con el id %d\n", id);
            retorno= 0;
        }
        else
        {
            nuevoVendedor = newVendedor();

            if(nuevoVendedor != NULL){

            set_id(nuevoVendedor, id);

            printf(" Ingrese nombre: ");
            gets(aux_nombre);
            fflush(stdin);
            set_nombre(nuevoVendedor, aux_nombre);

            set_cant_prod_vendidos(nuevoVendedor, getInt(" Ingrese cantidad de productos vendidos: "));
            fflush(stdin);

            printf(" Ingrese monto vendido: ");
            fflush(stdin);
            scanf("%f", &aux_float);
            set_monto_vendido(nuevoVendedor, aux_float);

            set_nivel(nuevoVendedor, seleccionarNivel());

            set_isEmpty(nuevoVendedor, 1);

            vendedores->add(vendedores, nuevoVendedor);

            retorno= 1;
            }
    }

    return retorno;
}

int seleccionarNivel()
{
    int opcion;
    int retorno;

    printf("\n ---------------------------------------------------------------------------");
    printf("\n|       1- EXPERTO       |       2- ESTANDARD       |       3- JUNIOR       |");
    printf("\n ---------------------------------------------------------------------------");
    opcion= getInt("\n\nIngrese el numero asociado al nivel para el que desea generar la lista: ");

    switch(opcion)
    {
        case 1:
            retorno= 0;
            break;
        case 2:
            retorno= 1;
            break;
        case 3:
            retorno= 2;
            break;
    }

    return retorno;
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
    printf("   ID   |     Nombre    |    Nivel    | Prods Vendidos |   Monto Vendido  |    Comision\n");
    printf("---------------------------------------------------------------------------------------------\n\n");
    for(int i=0; i< lista->len(lista); i++)
    {
        unVendedor= (eVendedor*)lista->get(lista, i);
        if(unVendedor->isEmpty == OCUPADO)
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

    for(int i=0; i< lista->len(lista); i++)
    {
        unVendedor = (eVendedor*)lista->get(lista, i);
        if( get_id(unVendedor) == id && unVendedor->isEmpty == 1)
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

int filtrarPorExperto(eVendedor* unVendedor)
{
    int ret_aux= -1;
    if(get_nivel(unVendedor)== EXPERTO)
    {
        ret_aux= 1;
    }
    return ret_aux;
}

int filtrarPorEstandard(eVendedor* unVendedor)
{
    int ret_aux= -1;
    if(get_nivel(unVendedor)== ESTANDARD)
    {
        ret_aux= 1;
    }
    return ret_aux;
}

int filtrarPorJunior(eVendedor* unVendedor)
{
    int ret_aux= -1;
    if(get_nivel(unVendedor)== JUNIOR)
    {
        ret_aux= 1;
    }
    return ret_aux;
}

int getInt(char* mensaje)
{
    int auxiliar;
    printf("%s",mensaje);
    scanf("%d",&auxiliar);

    return auxiliar;
}

void eliminarVendedor(ArrayList* vendedores)
{
    int id;
    int esta;
    char borrar;
    eVendedor* unVendedor;
    system("cls");
    printf("\n*** Borrar Vendedor ***\n\n");
    id= getInt("Ingrese id: ");

    esta = buscarVendedor(vendedores, id);

    if(esta == -1)
    {
        printf("\nNo hay ningun Vendedor con el id %d\n", id);
    }
    else
    {
        printf("\nVendedor encontrado!!!\n\n");
        unVendedor = (eVendedor*)vendedores->get(vendedores, id);
        mostrarVendedor(unVendedor);

        printf("\nConfirma borrado?: ");
        fflush(stdin);
        scanf("%c", &borrar);
        if(borrar != 's')
        {
            printf("\nBorrado cancelado\n\n");
        }
        else
        {
            set_isEmpty(unVendedor, LIBRE);
            printf("\nSe ha eliminado el Vendedor\n\n");
        }
    }
}

void modificarVendedor(ArrayList* vendedores)
{
    int id;
    int esta;
    char modificar;
    int nuevoNivel;
    eVendedor* unVendedor;
    system("cls");
    printf("\n*** Modificar vendedor ***\n\n");
    id= getInt("Ingrese id: ");
    fflush(stdin);

    esta= buscarVendedor(vendedores, id);

    if(esta== -1)
    {
        printf("\nNo hay ningun Vendedor con el id %d\n", id);
    }
    else
    {
        unVendedor= (eVendedor*)vendedores->get(vendedores, id);
        mostrarVendedor(unVendedor);

        printf("\nModifica nivel?: s/n ");
        fflush(stdin);
        scanf("%c", &modificar);
        if(modificar != 's')
        {
            printf("Modificacion cancelada\n\n");
        }
        else
        {
            printf("\n ---------------------------------------------------------------------------");
            printf("\n|       1- EXPERTO       |       2- ESTANDARD       |       3- JUNIOR       |");
            printf("\n ---------------------------------------------------------------------------");
            nuevoNivel= getInt("\n\nIngrese el numero asociado al nivel nuevo que desea asociar: ");

            switch(nuevoNivel)
            {
                case 1:
                    set_nivel(unVendedor, 0);
                    break;
                case 2:
                    set_nivel(unVendedor, 1);
                    break;
                case 3:
                    set_nivel(unVendedor, 2);
                    break;
            }
            printf("\nSe ha modificado el nivel con exito\n\n");
        }
    }
}

