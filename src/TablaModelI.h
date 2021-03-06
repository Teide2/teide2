/*******************************************************************************
** TablaModelI.h: tabla imputacion.
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

#ifndef TABLAMODELI_H
#define TABLAMODELI_H

#include <QAbstractTableModel>
#include <QStringList>
#include <QSet>
#include <QColor>
#include <QFont>
#include <QLinearGradient>
#include "Variables.h"
#include "MicroDatos.h"
class TablaModelI: public QAbstractTableModel
{  
public:
  //TablaModelI(QObject *parent, QString ** &vec, QStringList &cabecH, QStringList &cabecV);
  TablaModelI(QObject *parent, QString ** &vec, QStringList &cabecH, QStringList &cabecV, TFmeMicroDatos *FmeMDAsociados);
  
  void setCurrencyMap(QString ** &map);
  void setCurrencyCabec(QStringList &cabecV);
  void setMatrizImputacion(bool **m);
  void setConjuntoRegistrosDonantes(QSet<unsigned> crd);
  void setVectorExclusionVariables(bool *v);
  void setConjuntoRegistrosExcluidos(QSet<unsigned> cre);
  void setConjuntoRegistrosIncorrectos(QSet<unsigned> cri);
  void setVariablesAImputar(QSet<unsigned> vai, unsigned reg);
  void inicVariablesAImputar(int n);
  void getVariablesAsociadas(TFmeVariables *FvA);

  int rowCount(const QModelIndex & parent) const ;

  int columnCount(const QModelIndex & parent)   const ;

  QStringList GetcabeceraV();

  QVariant data(const QModelIndex &index, int role) const;

  bool setData(const QModelIndex &index, const QVariant &value, int role);

  QVariant headerData(int section, Qt::Orientation orientation, int role) const;

  bool setHeaderData(int section, Qt::Orientation orientation, const QVariant & value, int role);

private:
  int offsetOf(int row, int column) const;
  QStringList cabeceraH;
  QStringList cabeceraV;
  QString ** distances;
  bool **MatrizImputacion;
  QSet<unsigned> ConjuntoRegistrosDonantes;
  bool *VectorExclusionVariables;
  QSet<unsigned> ConjuntoRegistrosExcluidos;
  QSet<unsigned> ConjuntoRegistrosIncorrectos;
  QSet<unsigned> *VariablesAImputar;
  TFmeVariables *FmeVariablesAsociadas;
  TFmeMicroDatos *FmeMicroDatosAsociados;
};

#endif
