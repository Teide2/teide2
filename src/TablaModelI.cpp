/*******************************************************************************
** TablaModelI.cpp: tabla imputacion.
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

#include "TablaModelI.h"

  TablaModelI::TablaModelI(QObject *parent, QString ** &vec, QStringList &cabecH, QStringList &cabecV, TFmeMicroDatos *FmeMDAsociados):QAbstractTableModel(parent)
  {
    distances = vec;
    cabeceraH = cabecH;
    cabeceraV = cabecV;
    FmeMicroDatosAsociados = FmeMDAsociados;
  }
  void TablaModelI::setCurrencyMap(QString ** &map)   // cuando modifiquemos la matriz
  {
     distances = map;     
     reset();
  }
  void TablaModelI::setCurrencyCabec(QStringList &cabecV)   // cuando modifiquemos las cabeceras
  {
     cabeceraV = cabecV;
     reset();
  }
  void TablaModelI::setMatrizImputacion(bool **m) { MatrizImputacion = m;}
  void TablaModelI::setConjuntoRegistrosDonantes(QSet<unsigned> crd) { ConjuntoRegistrosDonantes = crd;}
  void TablaModelI::setVectorExclusionVariables(bool *v) { VectorExclusionVariables = v;}
  void TablaModelI::setConjuntoRegistrosExcluidos(QSet<unsigned> cre) { ConjuntoRegistrosExcluidos = cre;}
  void TablaModelI::setConjuntoRegistrosIncorrectos(QSet<unsigned> cri) { ConjuntoRegistrosIncorrectos = cri;}
  void TablaModelI::setVariablesAImputar(QSet<unsigned> vai, unsigned reg) { VariablesAImputar[reg].unite(vai);}
  void TablaModelI::inicVariablesAImputar(int n) { VariablesAImputar = new QSet<unsigned>[n]; }
  void TablaModelI::getVariablesAsociadas(TFmeVariables *FvA) { FmeVariablesAsociadas = FvA; }

  int TablaModelI::rowCount(const QModelIndex & /*parent*/) const
  {
    return cabeceraV.size();
  }

  int TablaModelI::columnCount(const QModelIndex & /*parent*/)   const
  {
    return cabeceraH.size();
  }
  QStringList TablaModelI::GetcabeceraV() { return cabeceraV; }

  QVariant TablaModelI::data(const QModelIndex &index, int role) const
  {
    if (!index.isValid())
      return QVariant();
    if (role == Qt::TextAlignmentRole)
      return int(Qt::AlignCenter);
    if (role == Qt::DisplayRole)
      return distances[index.row()][index.column()]/*.replace(",0", "")*/;
    if (role == Qt::BackgroundRole) {
      int fila = FmeMicroDatosAsociados->GetposID(cabeceraV.at(index.row()));
      QColor color;
      if (index.column() == 0)
        return QColor(Qt::green);
      if (ConjuntoRegistrosExcluidos.contains(fila)) {     // si es un registro excluido
        color = Qt::red;
        color.setRgb(255, 144, 16);
        color.setHsv (32, 239, 255);   // naranja
        return QColor(color);
      }
      if (VectorExclusionVariables[index.column()-1]) {     // variable excluida
        color = Qt::red;
        color.setRgb(255, 144, 16);
        color.setHsv (32, 239, 255);   // naranja
        return QColor(color);
      }
      if (ConjuntoRegistrosIncorrectos.contains(fila)) {
        if ((VariablesAImputar[fila].contains(index.column()-1))  && (!FmeVariablesAsociadas->EsVariableImputable(index.column()-1)))
          return QColor(Qt::magenta); // magenta
        return QColor(Qt::red);      // rojo
      }
      if (MatrizImputacion[fila][index.column()-1])  return QColor(Qt::yellow);    // amarillo
      if (ConjuntoRegistrosDonantes.contains(fila)) {
        color = Qt::cyan;
        color.setRgb(87, 205, 255);
        color.setHsv (198, 168, 255);      // azul imputacion
        return QColor(color);
      }else   return QColor(Qt::white);    // blanco
    }
    //QWidget::setStyleSheet("selection-color: black;selection-background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 red, stop: 1 gray);");
    return QVariant();
  }

  int TablaModelI::offsetOf(int row, int column) const
  {
    if (row < column)
      qSwap(row, column);
    return (row * (row - 1) / 2) + column;
  }

  QVariant TablaModelI::headerData(int section, Qt::Orientation orientation , int role) const
  {
    if (role == Qt::DisplayRole) {
      if (orientation == Qt::Horizontal)
        return cabeceraH[section];
      else
        return cabeceraV[section];
    }
    if (role == Qt::BackgroundRole) {
      if (orientation == Qt::Horizontal){
        QLinearGradient gradiant(5, 0, 25, 25);
        gradiant.setColorAt(0, QColor::fromRgb(13, 249, 0, 255));
        gradiant.setColorAt(0.05, QColor::fromRgb(12, 232, 0, 255));
        gradiant.setColorAt(0.36, QColor::fromRgb(11, 204, 0, 255));
        gradiant.setColorAt(0.6, QColor::fromRgb(9, 179, 0, 255));
        gradiant.setColorAt(0.75, QColor::fromRgb(8, 150, 0, 255));
        gradiant.setColorAt(0.79, QColor::fromRgb(6, 122, 0, 255));
        gradiant.setColorAt(0.86, QColor::fromRgb(5, 97, 0, 255));
        gradiant.setColorAt(0.935, QColor::fromRgb(3, 71, 0, 255));
        return QBrush(gradiant);
      }else {
        return QBrush(QColor::fromRgb(0, 11, 234, 255), Qt::SolidPattern);
      }
    }
    if (role == Qt::ForegroundRole)
      return QColor(Qt::white);
    if (role == Qt::FontRole) {
      QFont font;
      font.setFamily(("Tahoma"));
      font.setPointSize( 8 );      
      return QFont(font);
    }
    return QVariant();
  }

  bool TablaModelI::setHeaderData(int section, Qt::Orientation orientation, const QVariant & value, int role)
  {
    if (role == Qt::EditRole) {
      if (orientation == Qt::Horizontal) {
       cabeceraH[section] = value.toString();
       emit headerDataChanged(Qt::Horizontal, section, section);
      }else {
       cabeceraV[section] = value.toString();
       emit headerDataChanged(Qt::Vertical, section, section);
      }
      return true;
    }
    return false;
  }

  bool TablaModelI::setData(const QModelIndex &index, const QVariant &value, int role)
  {
    if (index.isValid() && role == Qt::EditRole) {
      distances[index.row()][index.column()] = value.toString();
      emit dataChanged(index, index);
      return true;
    }
    return false;
  }  
