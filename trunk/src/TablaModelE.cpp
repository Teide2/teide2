/*******************************************************************************
** TablaModelE.cpp: tabla reglas.
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

#include "TablaModelE.h"

  TablaModelE::TablaModelE(QObject *parent, QString ** &vec, QStringList &cabecH, QStringList &cabecV):QAbstractTableModel(parent)
  {
    distances = vec;
    cabeceraH = cabecH;
    cabeceraV = cabecV;
  }

  void TablaModelE::setCurrencyMap(QString ** &map)   // cuando modifiquemos la matriz
  {
      beginResetModel();
      distances = map;
      endResetModel();      
  }
  void TablaModelE::setCabeceraV(QStringList &cabecV)   // cuando modifiquemos la cabeceraV
  {
      beginResetModel();
      cabeceraV = cabecV;
      endResetModel();      
  }
  void TablaModelE::removeListaV(int i)
  {
      beginResetModel();
      cabeceraV.removeAt(i);
      endResetModel();      
  }
  void TablaModelE::addListaV(QString s)
  {
      beginResetModel();
      cabeceraV.append(s);
      endResetModel();      
  }
  void TablaModelE::setVectorEditCorrecto(bool *e) { VectorEditCorrecto = e; }

  int TablaModelE::rowCount(const QModelIndex & /*parent*/) const
  {
    return cabeceraV.size();
  }

  int TablaModelE::columnCount(const QModelIndex & /*parent*/)   const
  {
    return cabeceraH.size();
  }

  QVariant TablaModelE::data(const QModelIndex &index, int role) const
  {
    if (!index.isValid())
      return QVariant();    
    if (role == Qt::DisplayRole)
      return distances[index.row()][index.column()];
    if (role == Qt::BackgroundRole) {
      if (!VectorEditCorrecto[index.row()])
        return QColor(Qt::red);
      if ((index.row() % 2) != 0)
        return QColor(Qt::white);
      else {
        QColor color = Qt::blue;
        color.setRgb(212, 254, 204);
        color.setHsv (111, 50, 254);
        return QColor(color);
      }
    }
    return QVariant();
  }

  QVariant TablaModelE::headerData(int section, Qt::Orientation orientation , int role) const
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

  bool TablaModelE::setHeaderData(int section, Qt::Orientation orientation, const QVariant & value, int role)
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

  bool TablaModelE::setData(const QModelIndex &index, const QVariant &value, int role)
  {
    if (index.isValid() && role == Qt::EditRole) {
      distances[index.row()][index.column()] = value.toString();
      emit dataChanged(index, index);
      return true;
    }
    return false;
  }

