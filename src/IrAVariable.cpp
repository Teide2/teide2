/*******************************************************************************
** IrAVariable.cpp: abre la ventana donde permite indicar los datos para acceder
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

#include "IrAVariable.h"



    TFrmIrAVariable::TFrmIrAVariable(QWidget* parent, const char* name, Qt::WindowFlags fl, QStringList *ListaVariables)
    {
      unsigned i, NumVariables;

      if (this->objectName().isEmpty())
        this->setObjectName(QString::fromUtf8("TFrmIrAVariable"));
      this->resize(361, 181);

      RgpMetodo = new QGroupBox(this);
      RgpMetodo->setObjectName(QString::fromUtf8("RgpMetodo"));
      RgpMetodo->setGeometry(QRect(8, 72, 105, 65));
      Rbnombre = new QRadioButton(RgpMetodo);
      Rbnombre->setObjectName(QString::fromUtf8("Rbnombre"));
      Rbnombre->setGeometry(QRect(10, 20, 95, 21));
      Rbnumero = new QRadioButton(RgpMetodo);
      Rbnumero->setObjectName(QString::fromUtf8("Rbnumero"));
      Rbnumero->setGeometry(QRect(10, 40, 95, 21));
      GbxPorNombre = new QGroupBox(this);
      GbxPorNombre->setObjectName(QString::fromUtf8("GbxPorNombre"));
      GbxPorNombre->setGeometry(QRect(8, 8, 169, 57));
      CbxPorNombre = new QComboBox(GbxPorNombre);
      CbxPorNombre->setObjectName(QString::fromUtf8("CbxPorNombre"));
      CbxPorNombre->setGeometry(QRect(8, 24, 153, 21));
      CbxPorNombre->setEditable(true);
      GbxPorNumero = new QGroupBox(this);
      GbxPorNumero->setObjectName(QString::fromUtf8("GbxPorNumero"));
      GbxPorNumero->setGeometry(QRect(184, 8, 169, 57));
      CbxPorNumero = new QComboBox(GbxPorNumero);
      CbxPorNumero->setObjectName(QString::fromUtf8("CbxPorNumero"));
      CbxPorNumero->setGeometry(QRect(8, 24, 153, 21));
      PanResultado = new QFrame(this);
      PanResultado->setObjectName(QString::fromUtf8("PanResultado"));
      PanResultado->setGeometry(QRect(120, 80, 233, 57));
      PanResultado->setFrameShape(QFrame::Panel);
      PanResultado->setFrameShadow(QFrame::Raised);
      ButAplicar = new QPushButton(PanResultado);
      ButAplicar->setObjectName(QString::fromUtf8("ButAplicar"));
      ButAplicar->setGeometry(QRect(24, 16, 73, 25));
      ButCancelar = new QPushButton(PanResultado);
      ButCancelar->setObjectName(QString::fromUtf8("ButCancelar"));
      ButCancelar->setGeometry(QRect(128, 16, 73, 25));

      this->setWindowTitle(QApplication::translate("TFrmIrAVariable", "Ir a una variable...", 0));
      RgpMetodo->setTitle(QApplication::translate("TFrmIrAVariable", "M\303\251todo", 0));
      Rbnombre->setText(QApplication::translate("TFrmIrAVariable", "Por nombre", 0));
      Rbnumero->setText(QApplication::translate("TFrmIrAVariable", "Por n\303\272mero", 0));
      GbxPorNombre->setTitle(QApplication::translate("TFrmIrAVariable", "Por nombre", 0));
      GbxPorNumero->setTitle(QApplication::translate("TFrmIrAVariable", "Por n\303\272mero", 0));
      ButAplicar->setText(QApplication::translate("TFrmIrAVariable", "Aplicar", 0));
      ButCancelar->setText(QApplication::translate("TFrmIrAVariable", "Cancelar", 0));

      QObject::connect(Rbnombre, SIGNAL(clicked()), this, SLOT(RgpMetodoNombreClick()));
      QObject::connect(Rbnumero, SIGNAL(clicked()), this, SLOT(RgpMetodoNumeroClick()));

      QMetaObject::connectSlotsByName(this);

      CbxPorNombre->addItems(*ListaVariables);
      CbxPorNombre->setInsertPolicy(QComboBox::NoInsert);
      NumVariables = ListaVariables->count();
      for (i = 0; i < NumVariables; i++)
        CbxPorNumero->addItem(QString::number(i + 1, 10));

      Rbnombre->setChecked(true);
      CbxPorNombre->setCurrentIndex(0);
      CbxPorNumero->setCurrentIndex(0);
      CbxPorNombre->setEnabled(true);
      CbxPorNumero->setEnabled(false);
    }

    unsigned TFrmIrAVariable::GetVariableSeleccionada()
    { 
      return VariableSeleccionada;
    }

    QPushButton *TFrmIrAVariable::GetButAplicar()
    {
      return ButAplicar;
    }

    QPushButton *TFrmIrAVariable::GetButCancelar()
    {
      return ButCancelar;
    }

    QRadioButton *TFrmIrAVariable::GetRbnombre()
    {
      return Rbnombre;
    }
    
    QRadioButton *TFrmIrAVariable::GetRbnumero()
    {
      return Rbnumero;
    }

    QComboBox *TFrmIrAVariable::GetCbxPorNombre()
    {
      return CbxPorNombre;
    }

    QComboBox *TFrmIrAVariable::GetCbxPorNumero()
    {
      return CbxPorNumero;
    }

    void TFrmIrAVariable::SetVariableSeleccionada(unsigned vs)
    {
      VariableSeleccionada = vs;
    }


    void TFrmIrAVariable::RgpMetodoNombreClick()
    {
      CbxPorNombre->setEnabled(true);
      CbxPorNumero->setEnabled(false);
    }
    
    void TFrmIrAVariable::RgpMetodoNumeroClick()
    {
      CbxPorNombre->setEnabled(false);
      CbxPorNumero->setEnabled(true);
    }

