/*******************************************************************************
** TareasComunes.h: tareas comunes.
**
** author: M-S Hernández-García
*******************************************************************************/

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#ifndef TareasComunesH
#define TareasComunesH
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#include "Global.h"
#include "MicroDatos.h"
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
typedef
  struct
  {
    int IndiceRegistro;
    double DistanciaAlfa;
    double DistanciaBeta1;
    double DistanciaBeta2;
    double DistanciaGamma;
    double Distancia;
  } TipoRegistroDonante;
  
typedef
  struct
  {
    unsigned IndiceVariable;
    double Peso;
  } TipoPesoVariable;  

int ordfun(const void *A, const void *B);

double CalcularMedia(double *v, unsigned n);

double CalcularMediana(double *v, unsigned n);

double CalcularMediaR(double *v, unsigned n, unsigned rec);

double CalcularModa(double *v, unsigned n);

QString GetValorTag(QString NombreMetafile, QString tag);

int OrdenacionMatrizRegistrosDonantes(const void *A, const void *B);

int OrdenacionPesosVariablesDescendente(const void *A, const void *B);

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#endif
 
