#include <stdio.h>
#include <stdlib.h>
#include "fechas.h"

int hayReingreso();

int main()
{
    Fecha f;
    do{
    puts("INGRESE UNA FECHA [D/M/A]: \n");
    fflush(stdin);
    scanf("%d/%d/%d", &f.dia, &f.mes, &f.anio); //el salto de linea en windows son dos caracteres y en linux es uno solo

    if(esFechaValida(f))
        printf("La fecha %d/%d/%d es Valida", f.dia,f.mes,f.anio);
    else
        printf("La fecha %d/%d/%d NO es Valida", f.dia,f.mes,f.anio);
    }while(hayReingreso());
    return 0;
}


int hayReingreso()
{
    char res;

    puts("\nDesea ingresar otra fecha?");
    fflush(stdin);
    scanf("%c", &res);

    return res == 's';
}
