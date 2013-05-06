/*******************************************************************************
** PedirExpresion.h: muestra la ventana donde se introduce la expresion a
**               buscar en la solpapa de microdatos.
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

#ifndef PEDIREXPRESION_H
#define PEDIREXPRESION_H

#include <QtCore/QVariant>
#include <QAction>
#include <QtGui/QApplication>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QLabel>
#include <QtGui/QWidget>
#include <QMessageBox>

class TFrmPedirExpresion : public QFrame
{
    Q_OBJECT

public:

    QLabel *Texto;
    QLineEdit *EdtExpresion;
    QPushButton *ButAceptar;
    QPushButton *ButCancelar;    

    TFrmPedirExpresion(QWidget* parent, const char* name, Qt::WindowFlags fl);
    QString getExpresion();

public slots:

private:

};

#endif // PEDIREXPRESION_H
