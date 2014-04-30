/*******************************************************************************
** PedirExpresion.cpp: muestra la ventana donde se introduce la expresion a
**               buscar en la solapa de microdatos.
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

#include "PedirExpresion.h"



TFrmPedirExpresion::TFrmPedirExpresion(QWidget* parent, const char* name, Qt::WindowFlags fl):QFrame(parent, fl)
    {
      if (this->objectName().isEmpty())
        this->setObjectName(QString::fromUtf8("TFrmPedirExpresion"));
      QSize size(600, 600);
      Texto = new QLabel(this);
      Texto->setObjectName(QString::fromUtf8("Texto"));
      Texto->setGeometry(QRect(2, 2, 150, 25));
      EdtExpresion = new QLineEdit(this);
      EdtExpresion->setObjectName(QString::fromUtf8("EdtExpresion"));
      EdtExpresion->setGeometry(QRect(158, 2, 100, 25));
      ButAceptar = new QPushButton(this);
      ButAceptar->setObjectName(QString::fromUtf8("ButAceptar"));
      ButAceptar->setGeometry(QRect(2, 30, 81, 25));
      ButCancelar = new QPushButton(this);
      ButCancelar->setObjectName(QString::fromUtf8("ButCancelar"));
      ButCancelar->setGeometry(QRect(136, 30, 73, 25));

      this->setWindowTitle(QApplication::translate("TFrmPedirExpresion", "Petici\303\263n de expresi\303\263n", 0));
      Texto->setText(QApplication::translate("TFrmPedirExpresion", "Introduzca la expresi\303\263n ", 0));
      EdtExpresion->setToolTip(QApplication::translate("TFrmPedirExpresion", "Expresi\303\263n para visualizar unos determinados registros", 0));
      ButAceptar->setText(QApplication::translate("TFrmPedirExpresion", "&Aceptar", 0));
      ButCancelar->setText(QApplication::translate("TFrmPedirExpresion", "&Cancelar", 0));

      QMetaObject::connectSlotsByName(this);
    }

    QString TFrmPedirExpresion::getExpresion()
    {
        return EdtExpresion->text();
    }

