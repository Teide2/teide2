/*******************************************************************************
** TareasComunes.h: tareas comunes.
**
** author: M-S Hernández-García
**
**  This file is part of TEIDE2.
**
**  TEIDE2 is free software: you can redistribute it and/or modify
**  it under the terms of the GNU General Public License as published by
**  the Free Software Foundation, either version 3 of the License, or
**  (at your option) any later version.
**
**  Foobar is distributed in the hope that it will be useful,
**  but WITHOUT ANY WARRANTY; without even the implied warranty of
**  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
**  GNU General Public License for more details.
**
**  You should have received a copy of the GNU General Public License
**  along with Foobar.  If not, see <http://www.gnu.org/licenses/>.
**
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
 
