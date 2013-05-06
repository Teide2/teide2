/*******************************************************************************
** pintar.h: contiene la clase para crear la tabla.
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

#ifndef MITABLA_H
#define MITABLA_H


#include <QPainter>
#include <QRect>
#include <QMessageBox>
#include <QSet>
#include <QTableView>
#include <QMouseEvent>
#include <QHeaderView>

class MiTabla: public QTableView
{
    Q_OBJECT

public:
     bool botonderecho;

     MiTabla(QWidget *parent);

     void mousePressEvent(QMouseEvent *event);

     void keyPressEvent(QKeyEvent *event);

     void keyReleaseEvent ( QKeyEvent * event );

     void emitirSennal();

     bool boton();
     
     void rowResized ( int i, int viejo, int nuevo);

public slots:

     void pruebaV(int logindex);

     void pruebaH(int logindex);


protected:

protected slots:

};


#endif // MITABLA_H
