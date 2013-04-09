/*******************************************************************************
** TablaModelV.h: tabla de variables.
**
** author: M-S Hernández-García
*******************************************************************************/

#include <QAbstractTableModel>
#include <QStringList>
#include <QVector>
#include <QColor>
#include <QFont>
#include <QLinearGradient>
class TablaModelV: public QAbstractTableModel
{

public:
  TablaModelV(QObject *parent, QString ** &vec, QStringList &cabecH, QStringList &cabecV);
  
  void setCurrencyMap(QString ** &map);

  QStringList getCabeceraV();

  int rowCount(const QModelIndex & parent) const ;

  int columnCount(const QModelIndex & parent)   const ;
  
  void setVectorMappingExiste(QStringList m);
  void setListaVariables(QStringList * lv);
  
  QVariant data(const QModelIndex &index, int role) const;

  bool setData(const QModelIndex &index, const QVariant &value, int role);

  QVariant headerData(int section, Qt::Orientation orientation, int role) const;

  bool setHeaderData(int section, Qt::Orientation orientation, const QVariant & value, int role);

private:  
  QStringList VectorMappingExiste;
  QStringList cabeceraH;
  QStringList cabeceraV;
  QString ** distances;
  QStringList *LVariables;
};
