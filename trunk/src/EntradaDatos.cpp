/*******************************************************************************
** EntradaDatos.cpp: nos pide los datos para almacenar los datos en la BBDD.
**
** author: M-S Hernández-García
*******************************************************************************/

#include "EntradaDatos.h"


TFrmEntradaDatos::TFrmEntradaDatos(QWidget* parent, const char* name, Qt::WindowFlags fl)
    {
      if (this->objectName().isEmpty())
        this->setObjectName(QString::fromUtf8("TFrmEntradaDatos"));
      this->resize(313, 97);
      QFont font;
      font.setFamily(QString::fromUtf8("Tahoma"));
      this->setFont(font);
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

      this->setWindowTitle(QApplication::translate("TFrmEntradaDatos", "Entrada de Datos", 0, QApplication::UnicodeUTF8));
      LabEntradaDatos1->setText(QApplication::translate("TFrmEntradaDatos", "Introduzca el nombre base de la tabla", 0, QApplication::UnicodeUTF8));
      ButAceptar->setText(QApplication::translate("TFrmEntradaDatos", "Aceptar", 0, QApplication::UnicodeUTF8));
      ButCancelar->setText(QApplication::translate("TFrmEntradaDatos", "Cancelar", 0, QApplication::UnicodeUTF8));
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

