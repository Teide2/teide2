/*******************************************************************************
** Gobal.h: contiene variables globales.
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
#ifndef GlobalH
#define GlobalH
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#include <QObject>
#include <QApplication>
#include <QColor>
#include <QString>
#include <math.h>
#include <QMap>
#include <QList>
#include <QDate>
#include <QTime>
#include <QDir>
//#include "pintar.h"
#include "MiTabla.h"
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// STL - Standard C++ Template Library
#include <list>
#include <set>
#include <stack>
#include <map>
#include <queue>
#include <iterator>
using namespace std;  
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#define LANG_SP     // descomentar para idioma español
//#define LANG_EN     // descomentar idioma inglés
//#define SHAREWARE   // versión shareware de la aplicación
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
typedef
	enum {T_CONTINUO, T_DISCRETO, T_MIXTO, T_IGNORABLE} TTipoVariable;

// T_CONTINUO: Variable contínua (valores reales) entre un máximo y un mínimo especificados
// T_DISCRETO: Variable discreta dentro de una lista de valores concretos especificados
// T_MIXTO: Variable discreta (valores enteros) entre un máximo y un mínimo especificados

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
typedef
  enum {T_VARIABLES, T_MICRODATOS, T_EDITS, T_TEST, T_TEST_RANG, T_IMPUTACION, T_ESTADISTICAS} TTipoVentana;
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
typedef
  enum {T_NO_PROCEDE, T_NO_SABE, T_NO_CONTESTA, T_NS_NC} TTipoMissing;
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
typedef
  enum {T_BASICA, T_EXTENDIDA, T_EXTENDIDA_LARGA, T_CORRECTA} TTipoVariableAImputar;
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
typedef
  enum {FASE_INICIAL = 0, FASE_RANGOS = 1, FASE_TEST = 2, FASE_IMPUTACION = 3, FASE_ESTADISTICAS = 4, FASE_FINAL = 5} TTipoFase;
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
typedef
  enum {ATR_NOMBRE, ATR_INFO_VARIABLE, ATR_RANGO, ATR_FILTRO, ATR_INFO_FILTRO, ATR_SENTIDO_FILTRO, ATR_IMPUTABLE, ATR_TIPO, ATR_PESO, ATR_MAPPING, ATR_IMP_NUM} TTipoAtributo;
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
typedef
  enum {MPV_PROPIO_PESO, MPV_ALEATORIO} TTipoMetodoPesosVariables;
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
typedef
  enum {T_NO_CORREGIDO, T_CORREGIDO_NO_WARNING, T_CORREGIDO_WARNING} TTipoImputacionRegistro;
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
typedef
  enum {T_DONANTE, T_REGRESION, T_MEDIA, T_MEDIANA, T_MEDIA_R, T_MODA} TTipoImputacionVariable;
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
typedef enum {SI=0, NO=1} errorW;
//enum DetailButtonLabel2 { ShowLabel = 0, HideLabel = 1 };
const QString my_date = __DATE__;
#define YEAR ((((__DATE__ [7] - '0') * 10 + (__DATE__ [8] - '0')) * 10 \
              + (__DATE__ [9] - '0')) * 10 + (__DATE__ [10] - '0'))

#define MONTH (__DATE__ [2] == 'n' ? 0 \
               : __DATE__ [2] == 'b' ? 1 \
               : __DATE__ [2] == 'r' ? (__DATE__ [0] == 'M' ? 2 : 3) \
               : __DATE__ [2] == 'y' ? 4 \
               : __DATE__ [2] == 'n' ? 5 \
               : __DATE__ [2] == 'l' ? 6 \
               : __DATE__ [2] == 'g' ? 7 \
               : __DATE__ [2] == 'p' ? 8 \
               : __DATE__ [2] == 't' ? 9 \
               : __DATE__ [2] == 'v' ? 10 : 11)

#define DAY ((__DATE__ [4] == ' ' ? 0 : __DATE__ [4] - '0') * 10 + (__DATE__ [5] - '0'))

const QStringList mes = (QStringList() << "Ene" << "Feb" << "Mar" << "Abr" << "May" << "Jun" << "Jul" << "Ago" << "Sep" << "Oct" << "Nov" << "Dic");
//const QString my_time = __TIME__;
//int NUM_VALORES_MISSING = 4;
const QStringList NOPROCEDE = (QStringList() << "NO_PROCEDE" << "No_Procede" << "NoProcede");
const int ANCHO_IDS = 30;
const int ANCHO_KEY = 130;
const int ANCHO_VARIABLES_CORTAS = 100;
const int ANCHO_VARIABLES_LARGAS = 150;
const int ANCHO_VARIABLES_EXTRALARGAS = 800;
const int ENLACE_VACIO = -1;   
const QString ERROR_METAFILE =  "__ERROR_METAFILE__";
const unsigned MAX_EDITS = 100;
const QString RUTA_ICONO_BIEN = QDir::toNativeSeparators("/images/right.bmp");
const QString RUTA_ICONO_MAL = QDir::toNativeSeparators("/images/wrong.bmp");
const QColor CL_FALSE = QColor(Qt::red);
const QColor CL_TRUE = QColor(0x00ff99);
const QColor CL_IMPUTACION = Qt::yellow;
const int NUM_ATRIBUTOS_VARIABLE = 11;
const QString ATRIBUTOS_VARIABLE[NUM_ATRIBUTOS_VARIABLE] = {"NOMBRE", "INFO_VARIABLE", "RANGO", "FILTRO", "INFO_FILTRO", "SENTIDO_FILTRO", "IMPUTABLE", "TIPO", "PESO", "MAPPING", "IMP_NUM"};

const QString DESCRIPCION_ATRIBUTOS_VARIABLE[NUM_ATRIBUTOS_VARIABLE] =
{
  QApplication::translate("", "Nombre corto de la variable", 0),
  QApplication::translate("", "Texto libre con explicaci\303\263n de la variable", 0),
  QApplication::translate("", "Posibles valores de la variable", 0),
  QApplication::translate("", "Condici\303\263n para que la variable pueda ser respondida", 0),
  QApplication::translate("", "Texto libre con explicaci\303\263n del filtro", 0),
  QApplication::translate("", "a)if (nofiltro) then (valor=NP) b)if (filtro) then (valor!=NP) c)a y b", 0),
  QApplication::translate("", "Indica si la variable puede ser imputada", 0),
  QApplication::translate("", "Tipo de la variable (0: CONTINUO, 1: DISCRETO EN LISTA, 2: DISCRETO EN RANGO)", 0),
  //QApplication::translate("", "Indica si la variable admite el valor NO_PROCEDE", "", QApplication::UnicodeUTF8),
  //QApplication::translate("", "Indica si la variable admite el valor NO_SABE", "", QApplication::UnicodeUTF8),
  //QApplication::translate("", "Indica si la variable admite el valor NO_CONTESTA", "", QApplication::UnicodeUTF8),
  //QApplication::translate("", "Indica si la variable admite el valor NO_SABE/NO_CONTESTA", "", QApplication::UnicodeUTF8),
  QApplication::translate("", "Ponderaci\303\263n de la variable", 0),
  QApplication::translate("", "Tabla con las correspondencias entre c\303\263digos y literales", 0),
  QApplication::translate("", "Tipo de imp para vbles num. (MEDIANA, MEDIA, MODA, MEDIA_R o una ecuaci\303\263n)", 0)
};  

/*
const QString DESCRIPCION_ATRIBUTOS_VARIABLE[NUM_ATRIBUTOS_VARIABLE] =
{
  "Short name of the variable",
  "Text with variable explanation",
  "Valid values of the variable",
  "Condition necessary for answering variable",
  "Text with filter explanation",
  "a)if (nofilter) then (value=NP) b)if (filter) then (value!=NP) c)a and b",
  "Says if variable can be modified",
  "Type of the variable (0: CONTINUOUS, 1: LIST OF DISCRETE VALUES, 2: RANGE OF DISCRETE VALUES)",  
  "Relevance of the variable",
  "Table that matches codes and literals",
  "Imputation method for numeric variables (MEDIANA, MEDIA, MODA, MEDIA_R or a equation)"
};*/
//const QStringList mes = (QStringList() << "Jan" << "Feb" << "Mar" << "Apr" << "May" << "Jun" << "Jul" << "Aug" << "Sep" << "Oct" << "Nov" << "Dec");
const unsigned ANCHOS_VARIABLE[NUM_ATRIBUTOS_VARIABLE] = {150, 250, 150, 400, 400, 150, 100, 150, 100, 150, 400};
const int NUM_ATRIBUTOS_EDIT = 2;
const QString ATRIBUTOS_EDIT[NUM_ATRIBUTOS_EDIT] = {"CONDICION", "DESCRIPCION"};
const unsigned ANCHOS_EDIT[NUM_ATRIBUTOS_EDIT] = {700, 700};
const QString CARACTER_IMPUTACION = "$";
const QString DIRECTORIO_STATS = "stats";
const QString DIRECTORIO_DATA = "data";
const QString DIRECTORIO_METAFILES = "metafiles";
const unsigned MASCARA_16BITS = 65535;
//QString CADENAS_MISSING[4] = {"NO_PROCEDE", "NO_SABE", "NO_CONTESTA", "NS_NC"};
const QString FICHERO_SALIDA_MICRODATOS = "DATA";
const int NUM_TIPOS_VARIABLE = 4;
const int NUM_COLS_OUT = 7;
const unsigned ANCHO_COLUMNA_ESTANDAR = 100;
const unsigned TAM_INDENTACION = 25;
const unsigned UMBRAL_ENUM_VARIABLES = 10;
const unsigned MAX_PESOS_DISTANCIAS = 100;
const unsigned NUM_SECCIONES_INFORME = 16;
const unsigned MAX_VALORES_ESTADISTICAS = 100;
const unsigned MAX_PESO_IMPUTACION = 100;
const double PORCENTAJE_INICIAL_EXCLUSION_VARIABLES = 1;
const double PORCENTAJE_INICIAL_EXCLUSION_REG_RANGOS = 1;
const double PORCENTAJE_INICIAL_EXCLUSION_EDITS = 1;
const double PORCENTAJE_INICIAL_EXCLUSION_REG_TEST = 1;
const unsigned MAX_REGISTROS_DONANTES = 500;
const double MAX_PESO_VARIABLE = 100;
const int UMBRAL_CC = 1;
const QString NUM_REGISTROS_A_CARGAR = "ALL";
// Para hogares usar la siguiente configuración: ALFA=10, BETA1=100, BETA2=10, GAMMA=5
// Para población usar la siguiente configuración: ALFA=0, BETA1=100, BETA2=0, GAMMA=0
const unsigned PESO_ALFA = 10;
const unsigned PESO_BETA1 = 100;
const unsigned PESO_BETA2 = 10;
const unsigned PESO_GAMMA = 5;
const unsigned PORC_CONTAM = 1;
const QString SUFIJOENTRADA = "IN";
const QString SUFIJOSALIDA = "OUT";
const QString TITULOAPP = "Teide 2.0";
const unsigned DONANTES_NUMERICOS = 10;
const unsigned VALORES_RECORTADOS = 2;

const QString EXTRATITULO = "";

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#define MIN(x,y) (((x) <= (y)) ? (x) : (y))
#define MAX(x,y) (((x) >= (y)) ? (x) : (y))
#define ROUND(x) (((x) - floor(x) < 0.5) ? floor(x) :  ceil(x)) 

#define STR0024 "VARIABLES"
#define STR0026 "REGLAS"
#define STR0028 "EVAL. DE OTRAS REGLAS"
#define STR0031 "Contaminación"
#define STR0049 "Variable"
#define STR0053 "Variables"


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#endif


