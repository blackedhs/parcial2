
#include "Ventas.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Venta* Ventas_new()
{
    Venta* this;
    this=malloc(sizeof(Venta));
    return this;
}

void Ventas_delete(Venta* this)
{
    free(this);
}

Venta* Ventas_newConParametros(int id_Venta,char*fecha_Venta,char* codigo_Producto,int cantidad,float precio_Unitario,char*cuit_Cliente)
{
    Venta* this;
    this=Ventas_new();

    if(
    !Ventas_setId_Venta(this,id_Venta)&&
    !Ventas_setFecha_Venta(this,fecha_Venta)&&
    !Ventas_setCodigo_Producto(this,codigo_Producto)&&
    !Ventas_setCantidad(this,cantidad)&&
    !Ventas_setPrecio_Unitario(this,precio_Unitario)&&
    !Ventas_setCuit_Cliente(this,cuit_Cliente))
        return this;

    Ventas_delete(this);
    return NULL;
}

int Ventas_setId_Venta(Venta* this,int id_Venta)
{
    int retorno=-1;
    if(this!=NULL)
    {
        this->id_Venta=id_Venta;
        retorno=0;
    }
    return retorno;
}

int Ventas_getId_Venta(Venta* this,int* id_Venta)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *id_Venta=this->id_Venta;
        retorno=0;
    }
    return retorno;
}

int Ventas_setFecha_Venta(Venta* this,char*fecha_Venta)
{
    int retorno=-1;
    if(this!=NULL)
    {
        strcpy(this->fecha_Venta,fecha_Venta);
        retorno=0;
    }
    return retorno;
}

int Ventas_getFecha_Venta(Venta* this,char* fecha_Venta)
{
    int retorno=-1;
    if(this!=NULL)
    {
        strcpy(fecha_Venta,this->fecha_Venta);
        retorno=0;
    }
    return retorno;
}

int Ventas_setCodigo_Producto(Venta* this,char*codigo_Producto)
{
    int retorno=-1;
    if(this!=NULL)
    {
        strcpy(this->codigo_Producto,codigo_Producto);
        retorno=0;
    }
    return retorno;
}

int Ventas_getCodigo_Producto(Venta* this,char* codigo_Producto)
{
    int retorno=-1;
    if(this!=NULL)
    {
        strcpy(codigo_Producto,this->codigo_Producto);
        retorno=0;
    }
    return retorno;
}

int Ventas_setCantidad(Venta* this,int cantidad)
{
    int retorno=-1;
    if(this!=NULL)
    {
        this->cantidad=cantidad;
        retorno=0;
    }
    return retorno;
}

int Ventas_getCantidad(Venta* this,int* cantidad)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *cantidad=this->cantidad;
        retorno=0;
    }
    return retorno;
}

int Ventas_setPrecio_Unitario(Venta* this,float precio_Unitario)
{
    int retorno=-1;
    if(this!=NULL)
    {
        this->precio_Unitario=precio_Unitario;
        retorno=0;
    }
    return retorno;
}

int Ventas_getPrecio_Unitario(Venta* this,float* precio_Unitario)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *precio_Unitario=this->precio_Unitario;
        retorno=0;
    }
    return retorno;
}

int Ventas_setCuit_Cliente(Venta* this,char* cuit_Cliente)
{
    int retorno=-1;
    if(this!=NULL)
    {
        strcpy(this->cuit_Cliente,cuit_Cliente);
        retorno=0;
    }
    return retorno;
}

int Ventas_getCuit_Cliente(Venta* this,char* cuit_Cliente)
{
    int retorno=-1;
    if(this!=NULL)
    {
        strcpy(cuit_Cliente,this->cuit_Cliente);
        retorno=0;
    }
    return retorno;
}
void Ventas_Mostrar(void* pVenta){
    int bufferId;
    char bufferFecha[50];
    char bufferCodigo[50];
    int bufferCantidad;
    float bufferPrecio;
    char bufferCuit[50];
    if(pVenta!=NULL){
        Ventas_getId_Venta(pVenta,&bufferId);
        Ventas_getCantidad(pVenta,&bufferCantidad);
        Ventas_getCodigo_Producto(pVenta,bufferCodigo);
        Ventas_getCuit_Cliente(pVenta,bufferCuit);
        Ventas_getFecha_Venta(pVenta,bufferFecha);
        Ventas_getPrecio_Unitario(pVenta,&bufferPrecio);
        printf("%d -%s - %s -%d-%.2f-%s\n",bufferId,bufferFecha,bufferCodigo,bufferCantidad,bufferPrecio,bufferCuit);
    }
}
int Ventas_UnidadesVendidas(void* pElement){
    int retorno;
    if(pElement!=NULL){
        Ventas_getCantidad(pElement,&retorno);
    }
    return retorno;
}
int Ventas_MontoMayor10k(void* pElement){
    int retorno;
    float aux;
    if(pElement!=NULL){
        Ventas_getPrecio_Unitario(pElement,&aux);
        if(aux>max){
            retorno=1;
        }else
            retorno=0;
    }
    return retorno;
}
/** \brief compara el precio del elemento si es mayor a 20k
 * \param void* pElemento elemento a comparar
 * \return 1 si es mayor 0 si no.
 */
int Ventas_MontoMayor(void* pElement, void* max){
    int retorno;
    int auxmax;
    float aux;
    if(pElement!=NULL){
        Ventas_getPrecio_Unitario(pElement,&aux);
        auxmax=   *((int*)max);
        if(aux>auxmax){
            retorno=1;
        }else
            retorno=0;
    }
    return retorno;
}
/** \brief compara el valor del codigo del producto con el texto lcd_tv
 * \param void* pElemento elemento a comparar
 * \return 1 si coinside 0 si no.
 */
int Ventas_TVLCD(void* pElement){
    int retorno=0;
    char aux[50];
    if(pElement!=NULL){
        Ventas_getCodigo_Producto(pElement,aux);
        if(!strcmp(aux,"LCD_TV")){
            retorno=1;
        }
    }
    return retorno;
}
