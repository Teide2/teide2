/*******************************************************************************
** TablaModelV.cpp: tabla de variables.
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

#include "TablaModelV.h"

  TablaModelV::TablaModelV(QObject *parent, QString ** &vec, QStringList &cabecH, QStringList &cabecV):QAbstractTableModel(parent)
  {
    distances = vec;
    cabeceraH = cabecH;
    cabeceraV = cabecV;
  }

  void TablaModelV::setCurrencyMap(QString ** &map)   // cuando modifiquemos la matriz
  {
     beginResetModel();
     distances = map;
     endResetModel();     
  }

  QStringList TablaModelV::getCabeceraV()
  {
      return cabeceraV;
  }

  int TablaModelV::rowCount(const QModelIndex & /*parent*/) const
  {
    return cabeceraV.size();
  }

  int TablaModelV::columnCount(const QModelIndex & /*parent*/)   const
  {
    return cabeceraH.size();
  }

  void TablaModelV::setVectorMappingExiste(QStringList m) { VectorMappingExiste = m;}
  void TablaModelV::setListaVariables(QStringList * lv) { LVariables = lv;}

  QVariant TablaModelV::data(const QModelIndex &index, int role) const
  {
    if (!index.isValid())
      return QVariant();
    if (role == Qt::TextAlignmentRole)
      return int(Qt::AlignCenter);
    if (role == Qt::DisplayRole)
      return distances[index.row()][index.column()];
    if (role == Qt::BackgroundRole) {
      if (!LVariables->contains(distances[index.row()][0])) {
        QColor color = Qt::green;
        color.setHsv (74, 231, 193);
        color.setRgb(172, 253, 157);
        return QColor(color);
      }
      if ((index.row() % 2) != 0)
        return QColor(Qt::white);
      else {
        QColor color = Qt::blue;
        color.setRgb(212, 254, 204);
        color.setHsv (111, 50, 254);
        return QColor(color);        
      }
    }
    if (role == Qt::ForegroundRole) {
      if (index.data(Qt::DisplayRole) == "False")
        return QColor(Qt::red);
      if ((cabeceraH[index.column()] == "MAPPING") && (!VectorMappingExiste.contains(index.data().toString())))
        return QColor(Qt::red);
      return QColor(Qt::black);
    }
    return QVariant();
  }
  
  QVariant TablaModelV::headerData(int section, Qt::Orientation orientation , int role) const
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

    return QVariant();
  }

  bool TablaModelV::setHeaderData(int section, Qt::Orientation orientation, const QVariant & value, int role)
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

  bool TablaModelV::setData(const QModelIndex &index, const QVariant &value, int role)
  {
    if (index.isValid() && role == Qt::EditRole) {
      distances[index.row()][index.column()] = value.toString();
      emit dataChanged(index, index);
      return true;
    }
    return false;
  }

