#ifndef VENTAS_H_INCLUDED
#define VENTAS_H_INCLUDED

typedef struct{
    int id_Venta;
    char fecha_Venta[50];
    char codigo_Producto[50];
    int cantidad;
    float precio_Unitario;
    char cuit_Cliente[50];
}Venta;

Venta* Ventas_new();
void Ventas_delete();
Venta* Ventas_newConParametros(int id_Venta,char*fecha_Venta,char* codigo_Producto,int cantidad,float precio_Unitario,char*cuit_Cliente);

int Ventas_setId_Venta(Venta* this,int id_Venta);
int Ventas_getId_Venta(Venta* this,int* id_Venta);

int Ventas_setFecha_Venta(Venta* this,char*fecha_Venta);
int Ventas_getFecha_Venta(Venta* this,char* fecha_Venta);

int Ventas_setCodigo_Producto(Venta* this,char* codigo_Producto);
int Ventas_getCodigo_Producto(Venta* this,char* codigo_Producto);

int Ventas_setCantidad(Venta* this,int cantidad);
int Ventas_getCantidad(Venta* this,int* cantidad);

int Ventas_setPrecio_Unitario(Venta* this,float precio_Unitario);
int Ventas_getPrecio_Unitario(Venta* this,float* precio_Unitario);

int Ventas_setCuit_Cliente(Venta* this,char* cuit_Cliente);
int Ventas_getCuit_Cliente(Venta* this,char* cuit_Cliente);

void Ventas_Mostrar(void* pElement);
int Ventas_UnidadesVendidas(void* pElement);
int Ventas_MontoMayor10k(void* pElement);
int Ventas_MontoMayor20k(void* pElement);
int Ventas_TVLCD(void* pElement);
#endif // VENTAS_H_INCLUDED
