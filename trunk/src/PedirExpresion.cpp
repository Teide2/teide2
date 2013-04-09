/*******************************************************************************
** PedirExpresion.cpp: muestra la ventana donde se introduce la expresion a
**               buscar en la solapa de microdatos.
**
** author: M-S Hernández-García
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

      this->setWindowTitle(QApplication::translate("TFrmPedirExpresion", "Petici\303\263n de expresi\303\263n", 0, QApplication::UnicodeUTF8));
      Texto->setText(QApplication::translate("TFrmPedirExpresion", "Introduzca la expresi\303\263n ", 0, QApplication::UnicodeUTF8));
      EdtExpresion->setToolTip(QApplication::translate("TFrmPedirExpresion", "Expresi\303\263n para visualizar unos determinados registros", 0, QApplication::UnicodeUTF8));
      ButAceptar->setText(QApplication::translate("TFrmPedirExpresion", "&Aceptar", 0, QApplication::UnicodeUTF8));
      ButCancelar->setText(QApplication::translate("TFrmPedirExpresion", "&Cancelar", 0, QApplication::UnicodeUTF8));

      QMetaObject::connectSlotsByName(this);
    }

    QString TFrmPedirExpresion::getExpresion()
    {
        return EdtExpresion->text();
    }

