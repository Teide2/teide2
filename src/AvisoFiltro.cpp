/*******************************************************************************
** AvisoFiltro.cpp: abre la ventana que indica si hay algún filtro que no permite
**                  el NO_PROCEDE.
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

#include "AvisoFiltro.h"

TFrmAvisoFiltro::TFrmAvisoFiltro(QWidget* parent, const char* name, Qt::WindowFlags fl, QString Aviso, QAction *objeto):QWidget(parent, fl)
    {
          if (this->objectName().isEmpty())
        this->setObjectName(QString::fromUtf8("TFrmAvisoFiltro"));
    this->resize(403, 384);
    QFont font;
    font.setFamily(QString::fromUtf8("Tahoma"));
    this->setFont(font);

    ButOk = new QPushButton(this);
    ButOk->setObjectName(QString::fromUtf8("ButOk"));
    ButOk->setGeometry(QRect(186, 355, 113, 25));
    MemInfo = new QTextEdit(this);
    MemInfo->setObjectName(QString::fromUtf8("MemInfo"));
    MemInfo->setGeometry(QRect(2, 2, 390, 272));
    MemInfo->setReadOnly(true);
    ButMasDetalle = new QPushButton(this);
    ButMasDetalle->setObjectName(QString::fromUtf8("ButMasDetalle"));
    ButMasDetalle->setGeometry(QRect(308, 355, 91, 25));

    this->setWindowTitle(QApplication::translate("TFrmAvisoFiltro", "Informaci\303\263n...", 0, QApplication::UnicodeUTF8));
    ButOk->setText(QApplication::translate("TFrmAvisoFiltro", "OK", 0, QApplication::UnicodeUTF8));
    ButMasDetalle->setText(QApplication::translate("TFrmAvisoFiltro", "m\303\241s detalles", 0, QApplication::UnicodeUTF8));
    MemInfo->append(QApplication::translate("TFrmAvisoFiltro", "TEIDE ha detectado variables que no admiten el NO_PROCEDE y tienen filtro.\nEstas variables son:\n", 0, QApplication::UnicodeUTF8));
    MemInfo->append(Aviso);
    MemInfo->append(QApplication::translate("TFrmAvisoFiltro", "\nTEIDE ha modificado estas variables para que si admitan el NO_PROCEDE.", 0, QApplication::UnicodeUTF8));

    QObject::connect(ButOk, SIGNAL(clicked()), this, SLOT(ButOkClick()));
    QObject::connect(ButMasDetalle, SIGNAL(clicked()), this, SLOT(ButMasDetalleClick()));
    connect(objeto, SIGNAL(triggered()), this, SLOT(CerrarMetafileClick()));
    QMetaObject::connectSlotsByName(this);     
    }

    void TFrmAvisoFiltro::ButOkClick()
    {
      hide();
    }
    void TFrmAvisoFiltro::CerrarMetafileClick()
    {
      hide();
    }
    void TFrmAvisoFiltro::ButMasDetalleClick()
    {
       MemInfo->append(QApplication::translate("TFrmAvisoFiltro", "\nCuando una variable no admite el NO_PROCEDE y trae una condici\303\263n dentro de su campo FILTRO, esto es equivalente a que la condici\303\263n sea una regla.", 0, QApplication::UnicodeUTF8));
       MemInfo->append(QApplication::translate("TFrmAvisoFiltro", "Si realmente es esto lo que usted quiere, le recomendamos que quite el filtro de la variable afectada y lo ponga en la tabla REGLA como regla.", 0, QApplication::UnicodeUTF8));
    }

