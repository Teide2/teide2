/*******************************************************************************
** TablaModelInfoR.cpp: tabla de informacion registros.
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

#include "TablaModelInfoR.h"

  TablaModelInfoR::TablaModelInfoR(QObject *parent, QString * &vec, QStringList &cabecH, QStringList &cabecV):QAbstractTableModel(parent)
  {
    distances = vec;
    cabeceraH = cabecH;
    cabeceraV = cabecV;
  }

  void TablaModelInfoR::setCurrencyMap(QString * &map)   // cuando modifiquemos la matriz
  {
     distances = map;
     reset();
  }
  void TablaModelInfoR::setCabeceraV(QStringList &cabecV)   // cuando modifiquemos la cabecera vertical
  {
     cabeceraV = cabecV;     
     layoutChanged();
  }
  int TablaModelInfoR::rowCount(const QModelIndex & /*parent*/) const
  {
    return cabeceraV.size();
  }

  int TablaModelInfoR::columnCount(const QModelIndex & /*parent*/)   const
  {
    return cabeceraH.size();
  }

  void TablaModelInfoR::setVectorPintar(QString *p) {VectorPintar = p; }

  QVariant TablaModelInfoR::data(const QModelIndex &index, int role) const
  {
    if (!index.isValid())
      return QVariant();
    if (role == Qt::TextAlignmentRole)
      return int(Qt::AlignCenter);
    if (role == Qt::DisplayRole)
      return distances[index.column()]/*.replace(",0", "")*/;
    if (role == Qt::FontRole) {
      QFont font;
      font.setFamily(("Tahoma"));
      font.setPointSize( 8 );
      return QFont(font);
    }
    if (role == Qt::BackgroundRole) {
      if (VectorPintar[index.column()] == "Red")
        return QColor(Qt::red);
      if (VectorPintar[index.column()] == "Blue") {
        QColor color = Qt::red;
        color.setRgb(85, 170, 255);
        color.setHsv (210, 170, 255);
        return QColor(color);
      }
      if (VectorPintar[index.column()] == "Yellow")
        return QColor(Qt::yellow);
      if (VectorPintar[index.column()] == "Orange")  {
        QColor color = Qt::red;
        color.setRgb(255, 144, 16);
        color.setHsv (32, 239, 255);
        return QColor(color);
      }
      QColor color = Qt::blue;
      color.setRgb(212, 254, 204);
      color.setHsv (111, 50, 254);
      return QColor(color);
    }
    return QVariant();
  }
  
  QVariant TablaModelInfoR::headerData(int section, Qt::Orientation orientation , int role) const
  {
    if (role == Qt::FontRole) {
      QFont font;
      font.setFamily(("Tahoma"));
      font.setPointSize( 8 );
      return QFont(font);
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
    if (role == Qt::DisplayRole) {
      if (orientation == Qt::Horizontal)
        return cabeceraH[section];
      else
        return cabeceraV[section];
    }
    return QVariant();
  }

  bool TablaModelInfoR::setHeaderData(int section, Qt::Orientation orientation, const QVariant & value, int role)
  {
    if (role == Qt::EditRole) {
      if (orientation == Qt::Horizontal) {
       cabeceraH[section] = value.toString();
       emit headerDataChanged(Qt::Horizontal, section, section);
      }else {
       cabeceraV[section] = value.toString();
       emit headerDataChanged(Qt::Vertical, section, section);
       reset();
      }
      return true;
    }
    emit headerDataChanged(orientation, section, section);
    return false;
  }

  bool TablaModelInfoR::setData(const QModelIndex &index, const QVariant &value, int role)
  {
    if (index.isValid() && role == Qt::EditRole) {
      distances[index.column()] = value.toString();
      emit dataChanged(index, index);
      return true;
    }
    return false;
  }

