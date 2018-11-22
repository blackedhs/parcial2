#include "save.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "utn.h"
#include "parser.h"



/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char* nombre del archivo a cargar
 * \param this LinkedList* puntero a linkedlist
 * \return int 0 todo ok -1 hubo un error
 *
 */
int controller_loadFromText(char* path , LinkedList* this)
{
    FILE*pArchivo;
    int retorno=-1;
    if(path != NULL && this != NULL){
        pArchivo=fopen(path,"r");
        if(pArchivo != NULL){
            parser_VentasFromText(pArchivo,this);
            fclose(pArchivo);
            retorno=0;
        }else{
            printf("No se pudo abrir el archivo...");
        }
    }
    return retorno;
}

/** \brief Guarda un informe en el archivo informe.csv (modo texto).
 *
 * \param path char* nombre del archivo a cargar
 * \param this LinkedList* puntero a linkedlist
 * \return int 0 todo ok -1 hubo un error
 *
 */
int controller_saveAsText(char* path , LinkedList* this)
{
    FILE*pArchivo;
    int retorno=-1;
    if(path != NULL && this != NULL){
        pArchivo=fopen(path,"w");
        if(pArchivo != NULL && !save_EmployeesAsText(pArchivo,this)){
            fclose(pArchivo);
            printf("Guardado exitoso");
            getchar();
            retorno=0;
        }else{
            printf("No se pudo abrir el archivo...");
        }
    }
    return retorno;
}

