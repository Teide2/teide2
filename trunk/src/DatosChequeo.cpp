/*******************************************************************************
** DatosChequeo.cpp: chequea los datos en chequear población
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

#include "DatosChequeo.h"


TFrmDatosChequeo::TFrmDatosChequeo(QWidget* parent, const char* name, Qt::WindowFlags fl, bool activar, QString nomBD, QStringList *tablaDatos)
    {
      setGeometry(30, 30, 513, 593);
      if (this->objectName().isEmpty())
        this->setObjectName(QString::fromUtf8("TFrmDatosChequeo"));

      QPalette palette( QApplication::palette() );
      panel1 = new QFrame(this);      
      panel1->setFrameShape(QFrame::Box);
      panel1->setFrameShadow(QFrame::Raised);
      panel1->setGeometry(QRect(1, 1, 510, 98));
      palette.setColor( backgroundRole(), QColor("#D8D8D8"));
      panel1->setPalette(palette);
      panel1->setAutoFillBackground( true );
      panel2 = new QFrame(this);
      panel2->setFrameShape(QFrame::Box);
      panel2->setFrameShadow(QFrame::Raised);
      panel2->setGeometry(QRect(1, 100, 510, 98));
      palette.setColor( backgroundRole(), QColor("#F1D8D8"));
      panel2->setPalette(palette);
      panel2->setAutoFillBackground( true );
      panel3 = new QFrame(this);
      panel3->setFrameShape(QFrame::Box);
      panel3->setFrameShadow(QFrame::Raised);
      panel3->setGeometry(QRect(1, 198, 510, 98));
      palette.setColor( backgroundRole(), QColor("#D8E4D8"));
      panel3->setPalette(palette);
      panel3->setAutoFillBackground( true );
      panel4 = new QFrame(this);
      panel4->setFrameShape(QFrame::Box);
      panel4->setFrameShadow(QFrame::Raised);
      panel4->setGeometry(QRect(1, 296, 510, 68));
      palette.setColor( backgroundRole(), QColor("#D8D8F1"));
      panel4->setPalette(palette);
      panel4->setAutoFillBackground( true );
      panel5 = new QFrame(this);
      panel5->setFrameShape(QFrame::Box);
      panel5->setFrameShadow(QFrame::Raised);
      panel5->setGeometry(QRect(1, 364, 510, 160));
      palette.setColor( backgroundRole(), QColor("#F1F0D8"));
      panel5->setPalette(palette);
      panel5->setAutoFillBackground( true );
      panel6 = new QFrame(this);
      panel6->setFrameShape(QFrame::Box);
      panel6->setFrameShadow(QFrame::Raised);
      panel6->setGeometry(QRect(1, 524, 510, 68));

      LabBD1 = new QLabel(panel1);
      LabBD1->setObjectName(QString::fromUtf8("LabBD1"));
      LabBD1->setGeometry(QRect(8, 8, 227, 18));
      LabBD1->setText(QApplication::translate("TFrmDatosChequeo", "Indicar BD 1", 0));
      EdtBD1 = new QLineEdit(panel1);
      EdtBD1->setObjectName(QString::fromUtf8("EdtBD1"));
      EdtBD1->setGeometry(QRect(8, 27, 500, 23));
      EdtBD1->setText(nomBD.section(QDir::toNativeSeparators("/"), -1));     
      EdtBD1->setReadOnly (true);      
      palette.setColor( QPalette::Active, QPalette::Base, Qt::gray );
      EdtBD1->setPalette(palette);
      LabBD2 = new QLabel(panel1);
      LabBD2->setObjectName(QString::fromUtf8("LabBD2"));
      LabBD2->setGeometry(QRect(8, 52, 227, 18));
      LabBD2->setText(QApplication::translate("TFrmDatosChequeo", "Indicar BD 2", 0));
      EdtBD2 = new QLineEdit(panel1);
      EdtBD2->setObjectName(QString::fromUtf8("EdtBD2"));
      EdtBD2->setGeometry(QRect(8, 72, 500, 23));
      if (!activar)
      {
        EdtBD2->setReadOnly (true);
        EdtBD2->setPalette(palette);
        EdtBD2->setText(nomBD.section(QDir::toNativeSeparators("/"), -1));
      }

      LabTD1 = new QLabel(panel2);
      LabTD1->setObjectName(QString::fromUtf8("LabTD1"));
      LabTD1->setGeometry(QRect(8, 8, 227, 18));
      EdtTD1 = new QLineEdit(panel2);
      EdtTD1->setObjectName(QString::fromUtf8("EdtTD1"));
      EdtTD1->setGeometry(QRect(8, 27, 297, 23));
      EdtTD1->setText(tablaDatos->join(", "));    // al reves QStringList list1 = str.split(",");
      EdtTD1->setReadOnly (true);
      EdtTD1->setPalette(palette);
      LabTD2 = new QLabel(panel2);
      LabTD2->setObjectName(QString::fromUtf8("LabTD2"));
      LabTD2->setGeometry(QRect(8, 52, 227, 18));
      EdtTD2 = new QLineEdit(panel2);
      EdtTD2->setObjectName(QString::fromUtf8("EdtTD2"));
      EdtTD2->setGeometry(QRect(8, 72, 297, 23));
      LabAux = new QLabel(panel2);
      LabAux->setObjectName(QString::fromUtf8("LabAux"));
      LabAux->setGeometry(QRect(308, 64, 227, 30));

      LabVar = new QLabel(panel3);
      LabVar->setObjectName(QString::fromUtf8("LabVar"));
      LabVar->setGeometry(QRect(8, 18, 227, 18));
      EdtVar = new QLineEdit(panel3);
      EdtVar->setObjectName(QString::fromUtf8("EdtVar"));
      EdtVar->setGeometry(QRect(8, 37, 500, 23));
      LabAux2 = new QLabel(panel3);
      LabAux2->setObjectName(QString::fromUtf8("LabAux2"));
      LabAux2->setGeometry(QRect(8, 64, 500, 30));

      LabVarConteo = new QLabel(panel4);
      LabVarConteo->setObjectName(QString::fromUtf8("LabVarConteo"));
      LabVarConteo->setGeometry(QRect(8, 8, 110, 18));
      EdtVarConteo = new QLineEdit(panel4);
      EdtVarConteo->setObjectName(QString::fromUtf8("EdtVarConteo"));
      EdtVarConteo->setGeometry(QRect(128, 8, 380, 23));      
      LabPorcentaje = new QLabel(panel4);
      LabPorcentaje->setObjectName(QString::fromUtf8("LabPorcentaje"));
      LabPorcentaje->setGeometry(QRect(8, 35, 120, 18));
      EdtPorcentaje = new QLineEdit(panel4);
      EdtPorcentaje->setObjectName(QString::fromUtf8("EdtPorcentaje"));
      EdtPorcentaje->setGeometry(QRect(90, 35, 32, 23));
      LabTanto = new QLabel(panel4);
      LabTanto->setObjectName(QString::fromUtf8("LabTanto"));
      LabTanto->setGeometry(QRect(125, 35, 30, 18));

      ChbActC = new QCheckBox(QApplication::translate("TFrmDatosChequeo", "Tipo de encuesta, datos personales de individuo en hogares", 0), panel5);
      ChbActC->setObjectName(QString::fromUtf8("ChbActC"));
      ChbActC->setGeometry(QRect(8, 8, 371, 17));
      GbActC = new QGroupBox(QApplication::translate("TFrmDatosChequeo", "Encuesta especial", 0), panel5);
      GbActC->setObjectName(QString::fromUtf8("GbActC"));
      GbActC->setGeometry(QRect(8, 36, 500, 120));      
      GbActC->setVisible(false);
      LabVariablesC = new QLabel(GbActC);
      LabVariablesC->setObjectName(QString::fromUtf8("LabVariablesC"));
      LabVariablesC->setGeometry(QRect(8, 20, 120, 18));
      EdtVariablesC = new QTextEdit(GbActC);
      EdtVariablesC->setObjectName(QString::fromUtf8("EdtVariablesC"));
      EdtVariablesC->setGeometry(QRect(90, 20, 405, 43));
      LabOperadorC = new QLabel(GbActC);
      LabOperadorC->setObjectName(QString::fromUtf8("LabOperadorC"));
      LabOperadorC->setGeometry(QRect(8, 65, 120, 18));
      CbxOperadorC = new QComboBox(GbActC);
      CbxOperadorC->setObjectName(QString::fromUtf8("CbxOperadorC"));
      CbxOperadorC->setGeometry(QRect(90, 65, 57, 23));
      LabValorC = new QLabel(GbActC);
      LabValorC->setObjectName(QString::fromUtf8("LabValorC"));
      LabValorC->setGeometry(QRect(8, 92, 120, 18));
      EdtValorC = new QLineEdit(GbActC);
      EdtValorC->setObjectName(QString::fromUtf8("EdtValorC"));
      EdtValorC->setGeometry(QRect(90, 92, 280, 23));

      ButChequear = new QPushButton(panel6);
      ButChequear->setObjectName(QString::fromUtf8("ButAceptar"));
      ButChequear->setGeometry(QRect(25, 18, 120, 25));
      ButCancelar = new QPushButton(panel6);
      ButCancelar->setObjectName(QString::fromUtf8("ButCancelar"));
      ButCancelar->setGeometry(QRect(201, 18, 120, 25));
      ButAyuda = new QPushButton(panel6);
      ButAyuda->setObjectName(QString::fromUtf8("ButAyuda"));
      ButAyuda->setGeometry(QRect(376, 18, 120, 25));

      this->setWindowTitle(QApplication::translate("TFrmDatosChequeo", "Datos de Chequeo", 0));
      LabTD1->setText(QApplication::translate("TFrmDatosChequeo", "Indicar tabla Datos 1", 0));
      LabTD2->setText(QApplication::translate("TFrmDatosChequeo", "Indicar tabla Datos 2", 0));
      LabAux->setText(QApplication::translate("TFrmDatosChequeo", "Si es m\303\241s de una tabla separar\npor comas (, )", 0));
      LabVar->setText(QApplication::translate("TFrmDatosChequeo", "Indicar variables a chequear", 0));
      LabAux2->setText(QApplication::translate("TFrmDatosChequeo", "Si es m\303\241s de una variable separar por comas (, )", 0));
      ButChequear->setText(QApplication::translate("TFrmDatosChequeo", "Chequear", 0));
      ButCancelar->setText(QApplication::translate("TFrmDatosChequeo", "Cancelar", 0));
      ButAyuda->setText(QApplication::translate("TFrmDatosChequeo", "Ayuda", 0));
      LabVarConteo->setText(QApplication::translate("TFrmDatosChequeo", "Variable de conteo", 0));
      EdtVarConteo->setToolTip(QApplication::translate("TFrmDatosChequeo", "Comprueba que esa combinaci\303\263n esta en la tabla tanta veces como indica esta variable", 0));
      LabPorcentaje->setText(QApplication::translate("TFrmDatosChequeo", "Porcentaje", 0));
      EdtPorcentaje->setText(QApplication::translate("TFrmDatosChequeo", "100", 0));
      LabTanto->setText(QApplication::translate("TFrmDatosChequeo", "%", 0));
      LabVariablesC->setText(QApplication::translate("TFrmDatosChequeo", "Variables", 0));
      LabOperadorC->setText(QApplication::translate("TFrmDatosChequeo", "Operador", 0));
      CbxOperadorC->clear();
      CbxOperadorC->insertItems(0, QStringList()
       << "<"
       << ">"
       << "<="
       << ">="
       << "!="
       << "="
      );
      LabValorC->setText(QApplication::translate("TFrmDatosChequeo", "Valor", 0));

      connect(ButChequear, SIGNAL(clicked()), parent, SLOT(ButChequearClick()));
      connect(ButCancelar, SIGNAL(clicked()), parent, SLOT(ButCancelarClick()));
      connect(ButAyuda, SIGNAL(clicked()), parent, SLOT(ButAyudaClick()));
      connect(ChbActC, SIGNAL(clicked()), parent, SLOT(ChbActCClick()));
    }
    
    QString TFrmDatosChequeo::GetEdtBD1()
    {
        return EdtBD1->text();
    }

    QString TFrmDatosChequeo::GetEdtBD2()
    {
        return EdtBD2->text();
    }

    QString TFrmDatosChequeo::GetEdtTD1()
    {
        return EdtTD1->text();
    }

    QString TFrmDatosChequeo::GetEdtTD2()
    {
        return EdtTD2->text();
    }

    QString TFrmDatosChequeo::GetEdtVar()
    {
        return EdtVar->text();
    }

    QString TFrmDatosChequeo::GetEdtVarConteo()
    {
        return EdtVarConteo->text();
    }

    QString TFrmDatosChequeo::GetEdtPorcentaje()
    {
        return EdtPorcentaje->text();
    }

    QCheckBox *TFrmDatosChequeo::GetChbActC()
    {
        return ChbActC;
    }

    QGroupBox *TFrmDatosChequeo::GetGbActC()
    {
        return GbActC;
    }

    QString TFrmDatosChequeo::GetEdtVariablesC()
    {
        return EdtVariablesC->toPlainText();
    }

    QString TFrmDatosChequeo::GetOperadorC()
    {
        return CbxOperadorC->currentText() ;
    }

    QString TFrmDatosChequeo::GetEdtValorC()
    {
        return EdtValorC->text();
    }
