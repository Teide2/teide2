/*******************************************************************************
** scrollarea.h: permite que cuando no este
**               maximizada la ventana se muestre los scroll para ver complata
**               la informacion de la ventana.
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

#ifndef SCROLLAREA_H
#define SCROLLAREA_H

#include <QScrollArea>
#include <QScrollBar>
#include <QApplication>
#include <QDesktopWidget>
#include <QMessageBox>
#include <QScreen>

class Scrollarea : public QScrollArea
{
    Q_OBJECT
private:
   QWidget* hij;
   int WidthMax;
   int HeightMax;

public:

    Scrollarea( QWidget* parent, QWidget* hijo);

    ~Scrollarea() ;  

    void resizeEvent ( QResizeEvent * event );
    void actualizartitulo(QString titulo);

public slots:
    void mensaje();

signals:
    void miSignal();
   // void porl();
    /*void Scrollarea::miSignal()
    {
        QMessageBox::warning(0, "Warning",  "ancho " + QString::number(hij->width(),10) + " alto " + QString::number(hij->height(),10), "&Ok");
    };*/
   
};
#endif


