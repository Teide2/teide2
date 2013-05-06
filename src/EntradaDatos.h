/*******************************************************************************
** EntradaDatos.h:
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

#ifndef ENTRADADATOS_H
#define ENTRADADATOS_H

#include <QtCore/QVariant>
#include <QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

#include "Global.h"

class TFrmEntradaDatos : public QWidget
{   

private:	// User declarations

public:

    QLabel *LabEntradaDatos1;
    QLineEdit *EdtEntradaDatos1;
    QPushButton *ButAceptar;
    QPushButton *ButCancelar;

    TFrmEntradaDatos(QWidget* parent, const char* name, Qt::WindowFlags fl);
    
    void FijarEtiqueta1(QString Texto);
    
    void FijarEntrada1(QString Texto);
    
    QString GetEntrada1();
    
   
public slots:

};

extern TFrmEntradaDatos *FrmEntradaDatos; 

#endif // ENTRADADATOS_H
