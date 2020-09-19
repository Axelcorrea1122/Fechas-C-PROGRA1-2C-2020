#include "fechas.h"  //SI ESTA ENTRE CORCHETES ES PORQUE EL PATH YA ESTA CONFIGURADO EN EL IDE


int esFechaValida(const Fecha* f)
{
    if(f->anio > ANIO_BASE)
    {
        if(f->mes >= 1 && f->mes <= 12)
            if(f->dia >= 1 && f->dia <= cantDiaMes(f->mes,f->anio))
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


Fecha sumarDias(const Fecha* f1, int dias)
{
    Fecha  fSuma = *f1;
    fSuma.dia += dias;

    int cantDiasM;

    while( fSuma.dia > (cantDiasM = cantDiaMes(fSuma.mes, fSuma.anio) ) ){
        fSuma.dia -= cantDiasM;
        fSuma.mes++;

        if( fSuma.mes == 13){
            fSuma.mes = 1;
            fSuma.anio++;
        }
    }

    return fSuma;
}

int difEnDiasEntreFechas(const Fecha* f1, const Fecha* f2)
{

    int dif = diaDelAnio(f2) - diaDelAnio(f1);

    for(int anioAct = f1->anio ; anioAct < f2->anio ; anioAct++){
        dif +=  cantDiasAnioM(anioAct);
    }

    return dif;
}

int diaDelAnio(const Fecha* f)
{
    static int acumDias[2][14] =
    {
        {0,0,31,59,90,120,151,181,212,243,273,304,334,365},
        {0,0,31,60,91,121,152,182,213,244,274,305,335,366}
    };

    return acumDias[esBiciesto(f->anio)? 1 : 0][f->mes] +f->dia;
}

int cantDiasAnio(int anio)
{
    return esBiciesto(anio)? 366:365;
}

int diaDeLaSemana(const Fecha* f)
{
    Fecha fbase = {1,1,ANIO_BASE};

    int dif = difEnDiasEntreFechas(&fbase, f);

    return dif%7;
}
