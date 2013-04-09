/*******************************************************************************
** TablaModelE.h: tabla edits.
**
** author: M-S Hernández-García
*******************************************************************************/

#include <QAbstractTableModel>
#include <QStringList>
#include <QVector>
#include <QColor>
#include <QFont>
#include <QLinearGradient>
class TablaModelE: public QAbstractTableModel
{   
public:
  TablaModelE(QObject *parent, QString ** &vec, QStringList &cabecH, QStringList &cabecV);
  
  void setCurrencyMap(QString ** &map);
  void setCabeceraV(QStringList &cabecV);
  int rowCount(const QModelIndex & parent) const ;
  void removeListaV(int i);
  void addListaV(QString s);
  void setVectorEditCorrecto(bool *e);

  int columnCount(const QModelIndex & parent)   const ;

  QVariant data(const QModelIndex &index, int role) const;

  bool setData(const QModelIndex &index, const QVariant &value, int role);

  QVariant headerData(int section, Qt::Orientation orientation, int role) const;

  bool setHeaderData(int section, Qt::Orientation orientation, const QVariant & value, int role);
  

private:
  QStringList cabeceraH;
  QStringList cabeceraV;
  QString ** distances;
  bool *VectorEditCorrecto;
};
