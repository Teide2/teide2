/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Fichero de cabecera para el analizador y evaluador de expresiones.
// 14 de Agosto de 2003.
// Sergio Delgado Quintero.
//
// Modificado M-S Hernández-García, Abril 2013
//
//  This file is part of TEIDE2.
//
//  TEIDE2 is free software: you can redistribute it and/or modify
//  it under the terms of the GNU General Public License as published by
//  the Free Software Foundation, either version 3 of the License, or
//  (at your option) any later version.
//
//  Foobar is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU General Public License for more details.
//
//  You should have received a copy of the GNU General Public License
//  along with Foobar.  If not, see <http://www.gnu.org/licenses/>.
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#ifndef ExpAnaH
#define ExpAnaH
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <QString>
#include <QMap>
#include <map>
#include <QMessageBox>
#include <QApplication>
using namespace std;

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
typedef enum {FALSO = 0, VERDADERO = 1, ERROR_SINTACTICO = 2, ERROR_LEXICO = 3, ERROR_SINTACTICO_Y_LEXICO = 4} TResultado;
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
TResultado EvaluarExpresion (char* Expresion, QMap <QString, double> *MapValores);
TResultado EvaluarExpresion (char* Expresion, QMap <QString, double> *MapValores, QMap <QString, double> *MapMissing);
TResultado EvaluarExpresion(char* Expresion, QMap<QString,double> *MapValores, QMap <QString, double> *MapMissing, QString *mensaje);
TResultado EvaluarExpresionFiltros(char* Expresion, QMap<QString,double> *MapValores, QMap <QString, double> *MapMissing);
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#endif
