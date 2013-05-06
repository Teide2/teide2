/*******************************************************************************
** TablaModelInfoR.h: tabla de informacion registros.
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
