/*******************************************************************************
** TablaModel.cpp: tabla microdatos.
**
** author: M-S Hernández-García
*******************************************************************************/

#include "TablaModel.h"

  TablaModel::TablaModel(QObject *parent, QString ** &vec, QStringList &cabecH, QStringList &cabecV):QAbstractTableModel(parent)
  {
    distances = vec;
    cabeceraH = cabecH;
    cabeceraV = cabecV;    
  }

  void TablaModel::setCurrencyMap(QString ** &map)   // cuando modifiquemos la matriz
  {
     distances = map;     
     reset();
  }

  int TablaModel::rowCount(const QModelIndex & /*parent*/) const
  {
    return cabeceraV.size();
  }

  int TablaModel::columnCount(const QModelIndex & /*parent*/)   const
  {
    return cabeceraH.size();
  }

  QVariant TablaModel::data(const QModelIndex &index, int role) const
  {
    if (!index.isValid())
      return QVariant();
    if (role == Qt::TextAlignmentRole)
      return int(Qt::AlignCenter);
    if (role == Qt::DisplayRole)
      return distances[index.row()][index.column()]/*.replace(",0", "")*/;
    if (role == Qt::BackgroundRole) {     
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


  QVariant TablaModel::headerData(int section, Qt::Orientation orientation , int role) const
  {
    if (role == Qt::DisplayRole) {
      if (orientation == Qt::Horizontal)
        return cabeceraH[section];
      else
        return cabeceraV[section];
    }
    if (role == Qt::ForegroundRole)
      return QColor(Qt::white);
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
    return QVariant();
  }

  bool TablaModel::setHeaderData(int section, Qt::Orientation orientation, const QVariant & value, int role)
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

  bool TablaModel::setData(const QModelIndex &index, const QVariant &value, int role)
  {
    if (index.isValid() && role == Qt::EditRole) {
      distances[index.row()][index.column()] = value.toString();
      emit dataChanged(index, index);
      return true;
    }
    return false;
  }

