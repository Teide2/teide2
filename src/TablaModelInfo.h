/*******************************************************************************
** TablaModelInfo.cpp: tabla de informacion variables.
**
** author: M-S Hernández-García
*******************************************************************************/

#include <QAbstractTableModel>
#include <QStringList>
#include <QVector>
#include <QColor>
#include <QBrush>
#include <QBitmap>
#include <QApplication>
#include <QLinearGradient>
#include <QRadialGradient>
#include <QConicalGradient>
#include <QFont>
#include <qdir.h>
#include "Global.h"
class TablaModelInfo: public QAbstractTableModel
{   
public:
  TablaModelInfo(QObject *parent, QString * &vec, QStringList &cabecH, QStringList &cabecV);
  
  void setCurrencyMap(QString * &map);
  void setCabeceraV(QStringList &cabecV);
  int rowCount(const QModelIndex & parent) const ;

  int columnCount(const QModelIndex & parent)   const ;
  
  void setVectorMappingExiste(bool *m);
  
  void setVectorPintar(QString *p);

  QVariant data(const QModelIndex &index, int role) const;

  bool setData(const QModelIndex &index, const QVariant &value, int role);

  QVariant headerData(int section, Qt::Orientation orientation, int role) const;

  bool setHeaderData(int section, Qt::Orientation orientation, const QVariant & value, int role);  

private:  
  bool *VectorMappingExiste;
  QStringList cabeceraH;
  QStringList cabeceraV;
  QString * distances;
  QString *VectorPintar;
};
