/*******************************************************************************
** TablaModelT.cpp: tabla evaluacion de edits.
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

#include "TablaModelT.h"

  TablaModelT::TablaModelT(QObject *parent, QString ** &vec, QStringList &cabecH, QStringList &cabecV):QAbstractTableModel(parent)
  {
    distances = vec;
    cabeceraH = cabecH;
    cabeceraV = cabecV;
    Todos = true;
  }

  void TablaModelT::setCurrencyMap(QString ** &map)   // cuando modifiquemos la matriz
  {
     distances = map;     
     reset();
  }
  void TablaModelT::setCurrencyCabec(QStringList &cabecH, QStringList &cabecV)   // cuando modifiquemos las cabeceras
  {
     cabeceraH = cabecH;
     cabeceraV = cabecV;
     reset();
  }
  void TablaModelT::setCurrencyCabecV(QStringList &cabecV)   // cuando modifiquemos la cabecera vertical
  {
     cabeceraV = cabecV;
     reset();
  }
  void TablaModelT::setCurrencyCabecH(QStringList &cabecH)   // cuando modifiquemos la cabecera vertical
  {
     cabeceraH = cabecH;
     reset();
  }
  void TablaModelT::setVectorTotalesPorFilas(unsigned *v) { VectorTotalesPorFilas = v;}
  void TablaModelT::setVectorExclusionRegistros(bool *v1) { VectorExclusionRegistros = v1;}
  void TablaModelT::setVectorExclusionEdits(bool *v2) { VectorExclusionEdits = v2;}
  void TablaModelT::setVectorPosReg(int *v3, bool todos) { Todos = todos; VectorPosReg = v3;}

  int TablaModelT::rowCount(const QModelIndex & /*parent*/) const
  {
    return cabeceraV.size();
  }

  int TablaModelT::columnCount(const QModelIndex & /*parent*/)   const
  {
    return cabeceraH.size();
  }
  QStringList TablaModelT::GetcabeceraV() { return cabeceraV; }
  QVariant TablaModelT::data(const QModelIndex &index, int role) const
  {
    if (!index.isValid())
      return QVariant();
    if (role == Qt::TextAlignmentRole)
      return int(Qt::AlignCenter);
    if (role == Qt::DisplayRole)
      return distances[index.row()][index.column()];
    if (role == Qt::BackgroundRole) {
      QColor color;
      if ((index.row() == 0) || (index.column() == 0)) {
        color = Qt::blue;
        color.setRgb(0, 64, 0);
        return QColor(Qt::green);
      }
      if (Todos) {
        if (VectorExclusionRegistros[index.row()-1]) {
          color = Qt::red;
          color.setRgb(255, 144, 16);
          color.setHsv (32, 239, 255);   // naranja
          return QColor(color);
        }
      }else {
        if (VectorExclusionRegistros[VectorPosReg[index.row()]-1]) {
          color = Qt::red;
          color.setRgb(255, 144, 16);
          color.setHsv (32, 239, 255);   // naranja
          return QColor(color);
        }
      }
      if (VectorExclusionEdits[index.column()-1]) {
        color = Qt::red;
        color.setRgb(255, 144, 16);
        color.setHsv (32, 239, 255);   // naranja
        return QColor(color);
      }
      if (Todos) {
        if (VectorTotalesPorFilas[index.row()-1] == 0) {
          color = Qt::red;
          color.setRgb(85, 170, 255);
          color.setHsv (210, 170, 255);      // azul claro
          return QColor(color);
        }
      }else {
        if (VectorTotalesPorFilas[VectorPosReg[index.row()]-1] == 0) {
          color = Qt::red;
          color.setRgb(85, 170, 255);
          color.setHsv (210, 170, 255);      // azul claro
          return QColor(color);
        }
      }
      if (index.data(Qt::DisplayRole) == "False")
        return QColor(Qt::red);         // rojo
      if ((index.row() % 2) != 0)
        return QColor(Qt::white);       // blanco
      else {
        color = Qt::blue;
        color.setRgb(212, 254, 204);
        color.setHsv (111, 50, 254);
        return QColor(color);            // verde claro
      }
    }
    return QVariant();
  }  

  QVariant TablaModelT::headerData(int section, Qt::Orientation orientation, int role) const
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

  bool TablaModelT::setHeaderData(int section, Qt::Orientation orientation, const QVariant & value, int role)
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

  bool TablaModelT::setData(const QModelIndex &index, const QVariant &value, int role)
  {
    if (index.isValid() && role == Qt::EditRole) {
      distances[index.row()][index.column()] = value.toString();
      emit dataChanged(index, index);
      return true;
    }
    return false;
  }
