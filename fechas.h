#ifndef FECHAS_H_INCLUDED
#define FECHAS_H_INCLUDED


typedef struct {
    int dia,
        mes,
        anio;
}
Fecha;


int esFechaValida(Fecha f);
int cantDiaMes(int mes, int anio);
int esBiciesto(int anio);



#endif // FECHAS_H_INCLUDED
