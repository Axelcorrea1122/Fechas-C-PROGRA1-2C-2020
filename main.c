#include <stdio.h>
#include <stdlib.h>
#include "fechas.h"


int hayReingreso();
Fecha ingresarFecha(const char* mensaje);

int main()
{
    Fecha fecha1, fecha2, fechaSuma;
    int dias;
    char diasSem[7][10] = {"Lunes", "Martes", "Miercoles", "Jueves", "Viernes", "Sabado", "Domingo"};

    do
    {

        fecha1 = ingresarFecha("Ingrese la fecha 1(D/M/A):");
        fecha2 = ingresarFecha("Ingrese la fecha 2(D/M/A):");

        int difDias = difEnDiasEntreFechas(&fecha1, &fecha2);
        printf("La diferencia entre %d/%d/%d y %d/%d/%d es de %d dias", fecha1.mes, fecha1.mes, fecha1.anio, fecha2.dia, fecha2.mes, fecha2.anio, difDias);

        puts("\nIngrese los dias a sumar: ");
        scanf("%d", &dias);
        fechaSuma = sumarDias(&fecha1, dias);
        printf("La fecha %d/%d/%d + %d es %d/%d/%d\n", fecha1.dia, fecha1.mes, fecha1.anio, dias, fechaSuma.dia, fechaSuma.mes, fechaSuma.anio);

        int diaSemana = diaDeLaSemana(&fecha1);

        printf("El dia de la semana de la fecha %d/%d/%d es: %s",fecha1.dia, fecha1.mes, fecha1.anio,  diasSem[diaSemana]);
    }
    while(hayReingreso());

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


Fecha ingresarFecha(const char* mensaje)
{
    Fecha f;
    puts(mensaje);
    scanf("%d/%d/%d", &f.dia, &f.mes, &f.anio);

    while(!esFechaValida(&f))
    {
        puts("Fecha invalida...  Reingresela nuevamenete");
        scanf("%d/%d/%d", &f.dia, &f.mes, &f.anio);
    }

    return f;
}
