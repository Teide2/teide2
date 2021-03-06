/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Fichero de cabecera para el getter de coeficientes de ecuaciones de regresión.
// 20 de Junio de 2005.
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
#ifndef RegAnaH
#define RegAnaH
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// STL - Standard C++ Template Library
#include <map>
#include <QMap>
#include <QString>
using namespace std;
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
bool GetValoresDeRegresion(char* EcRegresion, QMap<QString,double> *MappingCoef);
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#endif
