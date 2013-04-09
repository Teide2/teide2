/*******************************************************************************
** TablaModel.cpp: tabla microdatos.
**
** author: M-S Hernández-García
*******************************************************************************/

#include <QAbstractTableModel>
#include <QStringList>
#include <QVector>
#include <QColor>
#include <QFont>
#include <QLinearGradient>
#include <QRadialGradient>
#include "Global.h"
class TablaModel: public QAbstractTableModel
{   
public:
  TablaModel(QObject *parent, QString ** &vec, QStringList &cabecH, QStringList &cabecV);
  
  void setCurrencyMap(QString ** &map);

  int rowCount(const QModelIndex & parent) const ;

  int columnCount(const QModelIndex & parent)   const ;

  QVariant data(const QModelIndex &index, int role) const;

  bool setData(const QModelIndex &index, const QVariant &value, int role);

  QVariant headerData(int section, Qt::Orientation orientation, int role) const;

  bool setHeaderData(int section, Qt::Orientation orientation, const QVariant & value, int role);

private:
  QStringList cabeceraH;
  QStringList cabeceraV;
  QString ** distances;  
};
