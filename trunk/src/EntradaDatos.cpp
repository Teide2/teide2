/*******************************************************************************
** EntradaDatos.cpp: nos pide los datos para almacenar los datos en la BBDD.
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

#include "EntradaDatos.h"


TFrmEntradaDatos::TFrmEntradaDatos(QWidget* parent, const char* name, Qt::WindowFlags fl)
    {
      if (this->objectName().isEmpty())
        this->setObjectName(QString::fromUtf8("TFrmEntradaDatos"));
      this->resize(313, 97);

      LabEntradaDatos1 = new QLabel(this);
      LabEntradaDatos1->setObjectName(QString::fromUtf8("LabEntradaDatos1"));
      LabEntradaDatos1->setGeometry(QRect(8, 8, 227, 18));
      EdtEntradaDatos1 = new QLineEdit(this);
      EdtEntradaDatos1->setObjectName(QString::fromUtf8("EdtEntradaDatos1"));
      EdtEntradaDatos1->setGeometry(QRect(8, 25, 297, 23));
      ButAceptar = new QPushButton(this);
      ButAceptar->setObjectName(QString::fromUtf8("ButAceptar"));
      ButAceptar->setGeometry(QRect(8, 56, 120, 25));
      ButCancelar = new QPushButton(this);
      ButCancelar->setObjectName(QString::fromUtf8("ButCancelar"));
      ButCancelar->setGeometry(QRect(184, 56, 120, 25));

      this->setWindowTitle(QApplication::translate("TFrmEntradaDatos", "Entrada de Datos", 0));
      LabEntradaDatos1->setText(QApplication::translate("TFrmEntradaDatos", "Introduzca el nombre base de la tabla", 0));
      ButAceptar->setText(QApplication::translate("TFrmEntradaDatos", "Aceptar", 0));
      ButCancelar->setText(QApplication::translate("TFrmEntradaDatos", "Cancelar", 0));
    }
    
    void TFrmEntradaDatos::FijarEtiqueta1(QString Texto)
    {
      LabEntradaDatos1->setWindowTitle(Texto);
    }
    
    void TFrmEntradaDatos::FijarEntrada1(QString Texto)
    {
      EdtEntradaDatos1->setText(Texto);
    }
    
    QString TFrmEntradaDatos::GetEntrada1()
    { 
      return EdtEntradaDatos1->text();
    }

