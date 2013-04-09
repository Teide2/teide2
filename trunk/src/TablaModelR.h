/*******************************************************************************
** TablaModelR.h: tabla evaluacion de rangos.
**
** author: M-S Hernández-García
*******************************************************************************/

#include <QAbstractTableModel>
#include <QStringList>
#include <QVector>
#include <QColor>
#include <QFont>
#include <QLinearGradient>
class TablaModelR: public QAbstractTableModel
{  
public:
  TablaModelR(QObject *parent, QString ** &vec, QStringList &cabecH, QStringList &cabecV);
  void setCurrencyMap(QString ** &map);
  void setCurrencyCabec(QStringList &cabecH, QStringList &cabecV);
  void setCurrencyCabecV(QStringList &cabecV);
  void setCurrencyCabecH(QStringList &cabecH);
  void setVectorTotalesPorFilas(unsigned *v);
  void setVectorExclusionRegistros(bool *v1);
  void setVectorExclusionVariables(bool *v2);
  void setVectorPosReg(int *v3, bool todos);

  int rowCount(const QModelIndex & parent) const ;

  int columnCount(const QModelIndex & parent)   const ;
  QStringList GetcabeceraV();
  QColor pintar(int i, int j, QModelIndex index) const;

  QVariant data(const QModelIndex &index, int role) const;

  bool setData(const QModelIndex &index, const QVariant &value, int role);

  QVariant headerData(int section, Qt::Orientation orientation, int role) const;

  bool setHeaderData(int section, Qt::Orientation orientation, const QVariant & value, int role);

private:  
  QStringList cabeceraH;
  QStringList cabeceraV;
  QString ** distances;
  unsigned *VectorTotalesPorFilas;
  bool *VectorExclusionRegistros;
  bool *VectorExclusionVariables;
  int *VectorPosReg;
  bool Todos;
};
