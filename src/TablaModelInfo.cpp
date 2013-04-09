/*******************************************************************************
** TablaModelInfo.cpp: tabla de informacion variables.
**
** author: M-S Hernández-García
*******************************************************************************/

#include "TablaModelInfo.h"

  TablaModelInfo::TablaModelInfo(QObject *parent, QString * &vec, QStringList &cabecH, QStringList &cabecV):QAbstractTableModel(parent)
  {
    distances = vec;
    cabeceraH = cabecH;
    cabeceraV = cabecV;
  }

  void TablaModelInfo::setCurrencyMap(QString * &map)   // cuando modifiquemos la matriz
  {
     distances = map;     
     reset();
  }
  void TablaModelInfo::setCabeceraV(QStringList &cabecV)   // cuando modifiquemos la cabecera vertical
  {
     cabeceraV = cabecV;     
     layoutChanged();
  }
  int TablaModelInfo::rowCount(const QModelIndex & /*parent*/) const
  {
    return cabeceraV.size();
  }

  int TablaModelInfo::columnCount(const QModelIndex & /*parent*/)   const
  {
    return cabeceraH.size();
  }

  void TablaModelInfo::setVectorPintar(QString *p) {VectorPintar = p; }

  QVariant TablaModelInfo::data(const QModelIndex &index, int role) const
  {
    if (!index.isValid())
      return QVariant();
    if (role == Qt::TextAlignmentRole)
      return int(Qt::AlignCenter);
    if (role == Qt::DisplayRole)
      return distances[index.column()];
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
        QColor color = Qt::blue;
        color.setRgb(212, 254, 204);
        color.setHsv (111, 50, 254);
        return QColor(color);
    }
    return QVariant();
  }  
  
  QVariant TablaModelInfo::headerData(int section, Qt::Orientation orientation , int role) const
  {
    if (role == Qt::FontRole) {
      QFont font;
      font.setFamily(("Tahoma"));
      font.setPointSize( 8 );
      return QFont(font);
    }
    if (role == Qt::ForegroundRole)
      return QColor(Qt::white);
    if (role == Qt::DisplayRole) {
      if (orientation == Qt::Horizontal){
        return cabeceraH[section];
      }else
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
    return QVariant();
  }

  bool TablaModelInfo::setHeaderData(int section, Qt::Orientation orientation, const QVariant & value, int role)
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
    emit headerDataChanged(orientation, section, section);
    return false;
  }

  bool TablaModelInfo::setData(const QModelIndex &index, const QVariant &value, int role)
  {
    if (index.isValid() && role == Qt::EditRole) {
      distances[index.column()] = value.toString();
      emit dataChanged(index, index);
      return true;
    }    
    return false;
  }

