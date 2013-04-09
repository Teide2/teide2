/*******************************************************************************
** TablaModelInfoR.h: tabla de informacion registros.
**
** author: M-S Hernández-García
*******************************************************************************/

#include <QAbstractTableModel>
#include <QStringList>
#include <QVector>
#include <QColor>
#include <QFont>
#include <QLinearGradient>
class TablaModelInfoR: public QAbstractTableModel
{

public:
  TablaModelInfoR(QObject *parent, QString * &vec, QStringList &cabecH, QStringList &cabecV);
  
  void setCurrencyMap(QString * &map);
  void setCabeceraV(QStringList &cabecV);
  int rowCount(const QModelIndex & parent) const ;

  int columnCount(const QModelIndex & parent)   const ;
  
  void setVectorPintar(QString *p);
  
  QVariant data(const QModelIndex &index, int role) const;

  bool setData(const QModelIndex &index, const QVariant &value, int role);

  QVariant headerData(int section, Qt::Orientation orientation, int role) const;

  bool setHeaderData(int section, Qt::Orientation orientation, const QVariant & value, int role);
  

private:
  QString *VectorPintar;
  QStringList cabeceraH;
  QStringList cabeceraV;
  QString * distances;
};
