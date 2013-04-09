/*******************************************************************************
** CambiarMicrodato.cpp: permite modificar el microdato manualmente. Abre una
**                       ventana para realizar la modificación.
**
** author: M-S Hernández-García
*******************************************************************************/

#include "CambiarMicrodato.h"


TFrmCambiarMicrodato::TFrmCambiarMicrodato(QWidget* parent)
    {

      if (this->objectName().isEmpty())
        this->setObjectName(QString::fromUtf8("TFrmCambiarMicrodato"));
      this->resize(267, 258);
      QFont font;
      font.setFamily(QString::fromUtf8("Tahoma"));
      this->setFont(font);
      LabTitulo = new QLabel(this);
      LabTitulo->setObjectName(QString::fromUtf8("LabTitulo"));
      LabTitulo->setGeometry(QRect(8, 8, 226, 18));
      LabVariable = new QLabel(this);
      LabVariable->setObjectName(QString::fromUtf8("LabVariable"));
      LabVariable->setGeometry(QRect(8, 48, 114, 18));
      ShpRibete1 = new QFrame(this);
      ShpRibete1->setObjectName(QString::fromUtf8("ShpRibete1"));
      ShpRibete1->setGeometry(QRect(8, 24, 245, 5));
      ShpRibete1->setMinimumSize(QSize(16, 5));
      ShpRibete1->setFrameShape(QFrame::HLine);
      ShpRibete1->setFrameShadow(QFrame::Raised);
      LabRegistro = new QLabel(this);
      LabRegistro->setObjectName(QString::fromUtf8("LabRegistro"));
      LabRegistro->setGeometry(QRect(8, 80, 121, 18));
      LabValorAntiguoMicrodato = new QLabel(this);
      LabValorAntiguoMicrodato->setObjectName(QString::fromUtf8("LabValorAntiguoMicrodato"));
      LabValorAntiguoMicrodato->setGeometry(QRect(8, 128, 161, 18));
      ShpRibete2 = new QFrame(this);
      ShpRibete2->setObjectName(QString::fromUtf8("ShpRibete2"));
      ShpRibete2->setGeometry(QRect(8, 104, 245, 5));
      ShpRibete2->setMinimumSize(QSize(16, 5));
      ShpRibete2->setFrameShape(QFrame::HLine);
      ShpRibete2->setFrameShadow(QFrame::Raised);
      LabValorNuevoMicrodato = new QLabel(this);
      LabValorNuevoMicrodato->setObjectName(QString::fromUtf8("LabValorNuevoMicrodato"));
      LabValorNuevoMicrodato->setGeometry(QRect(8, 160, 151, 18));
      ShpRibete3 = new QFrame(this);
      ShpRibete3->setObjectName(QString::fromUtf8("ShpRibete3"));
      ShpRibete3->setGeometry(QRect(8, 184, 245, 5));
      ShpRibete3->setMinimumSize(QSize(16, 5));
      ShpRibete3->setFrameShape(QFrame::HLine);
      ShpRibete3->setFrameShadow(QFrame::Raised);
      EdtVariable = new QLineEdit(this);
      EdtVariable->setObjectName(QString::fromUtf8("EdtVariable"));
      EdtVariable->setGeometry(QRect(130, 40, 121, 23));
      EdtVariable->setReadOnly(true);
      EdtRegistro = new QLineEdit(this);
      EdtRegistro->setObjectName(QString::fromUtf8("EdtRegistro"));
      EdtRegistro->setGeometry(QRect(130, 72, 121, 23));
      EdtRegistro->setReadOnly(true);
      EdtValorAntiguoMicrodato = new QLineEdit(this);
      EdtValorAntiguoMicrodato->setObjectName(QString::fromUtf8("EdtValorAntiguoMicrodato"));
      EdtValorAntiguoMicrodato->setGeometry(QRect(170, 120, 81, 23));
      EdtValorAntiguoMicrodato->setReadOnly(true);
      EdtValorNuevoMicrodato = new QLineEdit(this);
      EdtValorNuevoMicrodato->setObjectName(QString::fromUtf8("EdtValorNuevoMicrodato"));
      EdtValorNuevoMicrodato->setGeometry(QRect(170, 152, 81, 23));
      ButAceptar = new QPushButton(this);
      ButAceptar->setObjectName(QString::fromUtf8("ButAceptar"));
      ButAceptar->setGeometry(QRect(32, 208, 75, 25));
      ButCancelar = new QPushButton(this);
      ButCancelar->setObjectName(QString::fromUtf8("ButCancelar"));
      ButCancelar->setGeometry(QRect(144, 208, 75, 25));

      this->setWindowTitle(QApplication::translate("TFrmCambiarMicrodato", "Cambiar Microdato", 0, QApplication::UnicodeUTF8));
      LabTitulo->setText(QApplication::translate("TFrmCambiarMicrodato", "Introduzca el nuevo valor del microdato", 0, QApplication::UnicodeUTF8));
      LabVariable->setText(QApplication::translate("TFrmCambiarMicrodato", "Variable a modificar", 0, QApplication::UnicodeUTF8));
      LabRegistro->setText(QApplication::translate("TFrmCambiarMicrodato", "Registro a modificar", 0, QApplication::UnicodeUTF8));
      LabValorAntiguoMicrodato->setText(QApplication::translate("TFrmCambiarMicrodato", "Valor antiguo del microdato", 0, QApplication::UnicodeUTF8));
      LabValorNuevoMicrodato->setText(QApplication::translate("TFrmCambiarMicrodato", "Valor nuevo del microdato", 0, QApplication::UnicodeUTF8));
      ButAceptar->setText(QApplication::translate("TFrmCambiarMicrodato", "Aceptar", 0, QApplication::UnicodeUTF8));
      ButCancelar->setText(QApplication::translate("TFrmCambiarMicrodato", "Cancelar", 0, QApplication::UnicodeUTF8));

      QMetaObject::connectSlotsByName(this);
    }

    void TFrmCambiarMicrodato::FijarParametros(QString NombreVariable, unsigned IndiceRegistro, double ValorAntiguo)
    {

      EdtVariable->setText(NombreVariable);
      EdtRegistro->setText(QString::number(IndiceRegistro, 10));
      EdtValorAntiguoMicrodato->setText(QString::number(ValorAntiguo, 'f', 1).replace(".", ","));
      EdtValorNuevoMicrodato->setText(QString::number(ValorAntiguo, 'f', 1).replace(".", ","));
      EdtValorNuevoMicrodato->setFocus();
    }
    
    QPushButton *TFrmCambiarMicrodato::GetButAceptar() { return ButAceptar; }
    QPushButton *TFrmCambiarMicrodato::GetButCancelar() { return ButCancelar; }
    
    double TFrmCambiarMicrodato::GetValorNuevo() 
    { 
      ValorNuevo = EdtValorNuevoMicrodato->text().toDouble();
      return ValorNuevo; 
    }


