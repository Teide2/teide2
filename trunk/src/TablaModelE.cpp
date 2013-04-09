/*******************************************************************************
** TablaModelE.cpp: tabla reglas.
**
** author: M-S Hernández-García
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
     distances = map;
     reset();
  }
  void TablaModelE::setCabeceraV(QStringList &cabecV)   // cuando modifiquemos la cabeceraV
  {
     cabeceraV = cabecV;
     reset();
  }
  void TablaModelE::removeListaV(int i)
  {
    cabeceraV.removeAt(i);
    reset();
  }
  void TablaModelE::addListaV(QString s)
  {
    cabeceraV.append(s);
    reset();
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
    if (role == Qt::FontRole) {
      QFont font;
      font.setFamily(("Tahoma"));
      font.setPointSize( 8 );      
      return QFont(font);
    }
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

