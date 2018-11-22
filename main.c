#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Controller.h"
#include "utn.h"
#include "Ventas.h"

void main_menu(int* option);

int main(void)
{
    int option;
    LinkedList* listaVentas;
    int flagTexto=0;
    do{
        system("clear");
        main_menu(&option);
        switch(option)
        {
            case 1:
                if(!flagTexto){
                    listaVentas = ll_newLinkedList();
                    controller_loadFromText("data.csv",listaVentas);
                    printf("\nLos datos fueron cargados correctamente..");
                    getchar();
                    flagTexto=1;
                }else{
                    system("clear");
                    printf("Los datos de ventas ya fueron cargados..");
                    getchar();
                }
                break;
            case 2:
               /* system("clear");
                mapeo(listaVentas,Ventas_Mostrar);*/
                printf("%d",ll_count(listaVentas,Ventas_UnidadesVendidas,0));
                printf("\n");
                int i=10000:
                printf("%d",ll_count(listaVentas,Ventas_MontoMayor10k,&i));
                printf("\n");
                printf("%d",ll_count(listaVentas,Ventas_MontoMayor20k,20000));
                printf("\n");
                printf("%d",ll_count(listaVentas,Ventas_TVLCD,"TV_LCD"));
                getchar();
                controller_saveAsText("Informe.txt",listaVentas);
                break;
        }
    }while(option != 3);
    return 0;
}
void main_menu(int* option){
    printf("\n****************************************************\nMenu:\n\
1. Cargar los datos de venta desde el archivo data.csv (modo texto).\n\
2. Informes\n\
3. Salir\n\
*****************************************************/\n");
    utn_getEntero(option,3,"INGRESE UNA OPCION :  ","Error...Ingrese una opion valida",1,3);
}



