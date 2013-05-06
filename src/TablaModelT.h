/*******************************************************************************
** TablaModelT.h: tabla evaluacion de edits.
**
** author: M-S Hernández-García
**
**  This file is part of TEIDE2.
**
**  TEIDE2 is free software: you can redistribute it and/or modify
**  it under the terms of the GNU General Public License as published by
**  the Free Software Foundation, either version 3 of the License, or
**  (at your option) any later version.
**
**  Foobar is distributed in the hope that it will be useful,
**  but WITHOUT ANY WARRANTY; without even the implied warranty of
**  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
**  GNU General Public License for more details.
**
**  You should have received a copy of the GNU General Public License
**  along with Foobar.  If not, see <http://www.gnu.org/licenses/>.
**
*******************************************************************************/

#include <QAbstractTableModel>
#include <QStringList>
#include <QVector>
#include <QColor>
#include <QFont>
#include <QLinearGradient>
class TablaModelT: public QAbstractTableModel
{

public:
  TablaModelT(QObject *parent, QString ** &vec, QStringList &cabecH, QStringList &cabecV);
  
  void setCurrencyMap(QString ** &map);
  void setCurrencyCabec(QStringList &cabecH, QStringList &cabecV);
  void setCurrencyCabecV(QStringList &cabecV);
  void setCurrencyCabecH(QStringList &cabecH);
  void setVectorTotalesPorFilas(unsigned *v);
  void setVectorExclusionRegistros(bool *v1);
  void setVectorExclusionEdits(bool *v2);
  void setVectorPosReg(int *v3, bool todos);

  int rowCount(const QModelIndex & parent) const ;

  int columnCount(const QModelIndex & parent)   const ;
  QStringList GetcabeceraV();
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
  bool *VectorExclusionEdits;
  int *VectorPosReg;
  bool Todos;
};
