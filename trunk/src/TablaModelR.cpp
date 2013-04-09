/*******************************************************************************
** TablaModelR.cpp: tabla evaluacion de rangos.
**
** author: M-S Hernández-García
*******************************************************************************/

#include "TablaModelR.h"

  TablaModelR::TablaModelR(QObject *parent, QString ** &vec, QStringList &cabecH, QStringList &cabecV):QAbstractTableModel(parent)
  {
    distances = vec;
    cabeceraH = cabecH.replaceInStrings(".", ",");
    cabeceraV = cabecV.replaceInStrings(".", ",");
	Todos = true;    
  }

  void TablaModelR::setCurrencyMap(QString ** &map)   // cuando modifiquemos la matriz
  {
     distances = map;     
     reset();
  }
  
  void TablaModelR::setCurrencyCabec(QStringList &cabecH, QStringList &cabecV)   // cuando modifiquemos las cabeceras
  {
     cabeceraH = cabecH.replaceInStrings(".", ",");
     cabeceraV = cabecV.replaceInStrings(".", ",");
     reset();
  }
  void TablaModelR::setCurrencyCabecV(QStringList &cabecV)   // cuando modifiquemos la cabecera vertical
  {
     cabeceraV = cabecV;
     reset();
  }
  void TablaModelR::setCurrencyCabecH(QStringList &cabecH)   // cuando modifiquemos la cabecera vertical
  {
     cabeceraH = cabecH;
     reset();
  }
  void TablaModelR::setVectorTotalesPorFilas(unsigned *v) { VectorTotalesPorFilas = v;}
  void TablaModelR::setVectorExclusionRegistros(bool *v1) { VectorExclusionRegistros = v1;}
  void TablaModelR::setVectorExclusionVariables(bool *v2) { VectorExclusionVariables = v2;}
  void TablaModelR::setVectorPosReg(int *v3, bool todos) { Todos = todos; VectorPosReg = v3;}

  int TablaModelR::rowCount(const QModelIndex & /*parent*/) const
  {
    return cabeceraV.size();
  }

  int TablaModelR::columnCount(const QModelIndex & /*parent*/)   const
  {
    return cabeceraH.size();
  }

  QStringList TablaModelR::GetcabeceraV() { return cabeceraV; }

  QColor TablaModelR::pintar(int i, int j, QModelIndex index) const
  {
    QColor color;

        if (VectorExclusionRegistros[i]) {
            color = Qt::red;
            color.setRgb(255, 144, 16);
            color.setHsv (32, 239, 255);   // naranja
            return color;
        }else
          if (VectorExclusionVariables[j]) {
            color = Qt::red;
            color.setRgb(255, 144, 16);
            color.setHsv (32, 239, 255);   // naranja
            return color;
          }else
            if (VectorTotalesPorFilas[i] == 0) {
              color = Qt::red;
              color.setRgb(85, 170, 255);
              color.setHsv (210, 170, 255);      // azul claro
              return color;
            }else
               if (distances[index.row()][index.column()] == "False")
                  return Qt::red;         // rojo
                else
                  if ((index.row() % 2) != 0)
                    return Qt::white;       // blanco
                  else {
                    color = Qt::blue;
                    color.setRgb(212, 254, 204);
                    color.setHsv (111, 50, 254);
                    return color;            // verde claro
                  }
  }

  QVariant TablaModelR::data(const QModelIndex &index, int role) const
  {
    if (!index.isValid())
      return QVariant();
    if (role == Qt::TextAlignmentRole)
      return int(Qt::AlignCenter);
    if (role == Qt::DisplayRole)
      return distances[index.row()][index.column()];
    if (role == Qt::BackgroundRole) {
      if ((index.row() == 0) || (index.column() == 0))
        return QColor(Qt::green);
      if (Todos)
        return QColor(pintar(index.row()-1, index.column()-1, index));
      else
        return QColor(pintar(VectorPosReg[index.row()]-1, index.column()-1, index));
    }
    return QVariant();
  }

  QVariant TablaModelR::headerData(int section, Qt::Orientation orientation , int role) const
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

  bool TablaModelR::setHeaderData(int section, Qt::Orientation orientation, const QVariant & value, int role)
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

  bool TablaModelR::setData(const QModelIndex &index, const QVariant &value, int role)
  {
    if (index.isValid() && role == Qt::EditRole) {
      distances[index.row()][index.column()] = value.toString();
      emit dataChanged(index, index);
      return true;
    }    
    return false;
  }  
