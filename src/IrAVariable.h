/*******************************************************************************
** IrAVariable.h: abre la ventana donde permite indicar los datos para acceder
**                  directamente a la variable indicada.
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

#ifndef IRAVARIABLE_H
#define IRAVARIABLE_H

#include <QtCore/QVariant>
#include <QAction>
#include <QApplication>
#include <QButtonGroup>
#include <QComboBox>
#include <QFrame>
#include <QGroupBox>
#include <QPushButton>
#include <QRadioButton>
#include <QWidget>

#include "Global.h"

class TFrmIrAVariable : public QWidget
{
    Q_OBJECT

public:

    QGroupBox *RgpMetodo;
    QRadioButton *Rbnombre;
    QRadioButton *Rbnumero;
    QGroupBox *GbxPorNombre;
    QComboBox *CbxPorNombre;
    QGroupBox *GbxPorNumero;
    QComboBox *CbxPorNumero;
    QFrame *PanResultado;
    QPushButton *ButAplicar;
    QPushButton *ButCancelar;

    TFrmIrAVariable(QWidget* parent, const char* name, Qt::WindowFlags fl, QStringList *ListaVariables);

    unsigned GetVariableSeleccionada();

    QPushButton *GetButAplicar();

    QPushButton *GetButCancelar();

    QRadioButton *GetRbnombre();
    
    QRadioButton *GetRbnumero();

    QComboBox *GetCbxPorNombre();

    QComboBox *GetCbxPorNumero();

    void SetVariableSeleccionada(unsigned vs);

   
public slots:

    void RgpMetodoNombreClick();
    
    void RgpMetodoNumeroClick();

private:

    unsigned VariableSeleccionada;

};

#endif // IRAVARIABLE_H
