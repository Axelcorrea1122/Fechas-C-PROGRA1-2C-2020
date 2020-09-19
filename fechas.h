#ifndef FECHAS_H_INCLUDED
#define FECHAS_H_INCLUDED

#define ANIO_BASE 1601
#define cantDiasAnioM(anio) esBiciesto(anio)? 366 : 365

typedef struct {
    int dia,
        mes,
        anio;
}
Fecha;


int esFechaValida(const Fecha* f);
int cantDiaMes(int mes, int anio);
int esBiciesto(int anio);
Fecha sumarDias(const Fecha* f1, int dias);
int difEnDiasEntreFechas(const Fecha* f1, const Fecha* f2);
int diaDelAnio(const Fecha* f);
int cantDiasAnio(int anio);
int diaDeLaSemana(const Fecha* f);



#endif // FECHAS_H_INCLUDED
