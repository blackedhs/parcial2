#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Ventas.h"
/** \brief Guarda los datos del linkedList en modo texto
 * \param pFile FILE* puntero al archivo destino
 * \param pArrayListEmployee LinkedList* puntero a linkedlist
 * \return 0 todo bien -1 error
 */
int save_EmployeesAsText(FILE* pFile,LinkedList* this){
/*  int retorno=-1;
    int i=0;
    int len;
    Venta* pVenta;
    int bufferId;
    char bufferFecha[50];
    char bufferCodigo[50];
    int bufferCantidad;
    float bufferPrecio;
    char bufferCuit[50];
    if(pFile!=NULL && this!= NULL){
        fprintf(pFile,"ID_Venta,Fecha_Venta,Codigo_Producto,Cantidad,Precio_Unitario,CUIT_Cliente\n");
        len=ll_len(this);
        do{
            pVenta=(Venta*)ll_get(this,i);
            Ventas_getId_Venta(pVenta,&bufferId);
            Ventas_getCantidad(pVenta,&bufferCantidad);
            Ventas_getCodigo_Producto(pVenta,bufferCodigo);
            Ventas_getCuit_Cliente(pVenta,bufferCuit);
            Ventas_getFecha_Venta(pVenta,bufferFecha);
            Ventas_getPrecio_Unitario(pVenta,&bufferPrecio);
            fprintf(pFile,"%d;%s;%s;%d;%.2f;%s\n",bufferId,bufferFecha,bufferCodigo,bufferCantidad,bufferPrecio,bufferCuit);
            i++;
        }while(i<len);
        if(i==len){
            retorno=0;
        }
  }
  */
  int retorno=-1;
  int cantidadVendidas;
  int cantidadVantasMayores10k;
  int cantidadVantasMayores20k;
  int cantidadTVoLCD;
  if(pFile!=NULL && this!= NULL){
        cantidadVendidas=ll_count(this,Ventas_UnidadesVendidas);
        cantidadVantasMayores10k=ll_count(this,Ventas_MontoMayor10k);
        cantidadVantasMayores20k=ll_count(this,Ventas_MontoMayor20k);
        cantidadTVoLCD=ll_count(this,Ventas_TVLCD);
        fprintf(pFile,"***************************\nInforme de ventas\n**************************\n");
        fprintf(pFile,"-Cantidad de unidades vendidas totales: %d\n",cantidadVendidas);
        fprintf(pFile,"-Cantidad de ventas por un monto mayor a 10000: %d\n",cantidadVantasMayores10k);
        fprintf(pFile,"-Cantidad de ventas por un monto mayor a 20000: %d\n",cantidadVantasMayores20k);
        fprintf(pFile,"-Cantidad de TVs LCD vendidas: %d\n",cantidadTVoLCD);
        fprintf(pFile,"********************************");
        retorno=0;
  }
    return retorno;
}
