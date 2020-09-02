#include "fechas.h"  //SI ESTA ENTRE CORCHETES ES PORQUE EL PATH YA ESTA CONFIGURADO EN EL IDE


int esFechaValida(Fecha f)
{
    if(f.anio > 1600)
    {
        if(f.mes >= 1 && f.mes <= 12)
            if(f.dia >= 1 && f.dia <= cantDiaMes(f.mes,f.anio))
                return  1;
    }
    return 0;
}


int cantDiaMes(int mes, int anio)
{
    static const int vCantDias[] = {0, 31,28,31,30,31,30,31,31,30,31,30,31};
    if(mes == 2 && esBiciesto(anio))
        return 29;


    return vCantDias[mes];
}


int esBiciesto(int anio)
{
    return (anio%4 == 0 && anio%100 != 0) || anio%400 == 0;
}
