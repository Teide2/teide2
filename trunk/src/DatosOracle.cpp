/*******************************************************************************
** DatosOracle.cpp: abre la ventana que pide los datos necesarios para abrir una
**                  base de datos Oracle.
**
** author: M-S Hernández-García
*******************************************************************************/

#include "DatosOracle.h"          


DatosOracle::DatosOracle(QWidget* parent, const char* name, Qt::WindowFlags fl, QString NombreBaseDatos)
    {
      if (this->objectName().isEmpty())
        this->setObjectName(QString::fromUtf8("DatosOracle"));
      this->resize(400, 300);
      EdtNombre = new QLineEdit(this);
      EdtNombre->setObjectName(QString::fromUtf8("EdtNombre"));
      EdtNombre->setGeometry(QRect(150, 20, 171, 23));
      EdtUsuario = new QLineEdit(this);
      EdtUsuario->setObjectName(QString::fromUtf8("EdtUsuario"));
      EdtUsuario->setGeometry(QRect(150, 70, 171, 23));
      EdtPassword = new QLineEdit(this);
      EdtPassword->setObjectName(QString::fromUtf8("EdtPassword"));
      EdtPassword->setGeometry(QRect(150, 120, 171, 23));
      EdtPassword->setEchoMode(QLineEdit::Password);
      EdtHost = new QLineEdit(this);
      EdtHost->setObjectName(QString::fromUtf8("EdtHost"));
      EdtHost->setGeometry(QRect(150, 170, 171, 23));
      LbNombre = new QLabel(this);
      LbNombre->setObjectName(QString::fromUtf8("LbNombre"));
      LbNombre->setGeometry(QRect(20, 20, 100, 18));
      LbUsuario = new QLabel(this);
      LbUsuario->setObjectName(QString::fromUtf8("LbUsuario"));
      LbUsuario->setGeometry(QRect(20, 70, 114, 18));
      LbPassword = new QLabel(this);
      LbPassword->setObjectName(QString::fromUtf8("LbPassword"));
      LbPassword->setGeometry(QRect(22, 120, 71, 20));
      LbHost = new QLabel(this);
      LbHost->setObjectName(QString::fromUtf8("LbHost"));
      LbHost->setGeometry(QRect(20, 170, 83, 18));
      ButAceptar = new QPushButton(this);
      ButAceptar->setObjectName(QString::fromUtf8("ButAceptar"));
      ButAceptar->setGeometry(QRect(50, 210, 81, 31));
      ButCancelar = new QPushButton(this);
      ButCancelar->setObjectName(QString::fromUtf8("ButCancelar"));
      ButCancelar->setGeometry(QRect(210, 210, 81, 31));

      this->setWindowTitle(QApplication::translate("DatosOracle", "Origen de la base de datos Oracle", 0, QApplication::UnicodeUTF8));
      LbNombre->setText(QApplication::translate("DatosOracle", "Nombre:", 0, QApplication::UnicodeUTF8));
      LbUsuario->setText(QApplication::translate("DatosOracle", "Usuario:", 0, QApplication::UnicodeUTF8));
      LbPassword->setText(QApplication::translate("DatosOracle", "Password:", 0, QApplication::UnicodeUTF8));
      LbHost->setText(QApplication::translate("DatosOracle", "Host:", 0, QApplication::UnicodeUTF8));
      ButAceptar->setText(QApplication::translate("DatosOracle", "Aceptar", 0, QApplication::UnicodeUTF8));
      ButCancelar->setText(QApplication::translate("DatosOracle", "Cancelar", 0, QApplication::UnicodeUTF8));

      QMetaObject::connectSlotsByName(this);
      NomBaseDatos = NombreBaseDatos;
      QObject::connect(ButAceptar, SIGNAL(clicked()), parent, SLOT(ButAceptarOracle()));
      QObject::connect(ButCancelar, SIGNAL(clicked()), parent, SLOT(ButCancelarOracle()));
    }
    
    QString DatosOracle::getEdtNombre() { return EdtNombre->text(); }
    QString DatosOracle::getEdtUsuario() { return EdtUsuario->text(); }
    QString DatosOracle::getEdtPassword() { return EdtPassword->text(); }
    QString DatosOracle::getEdtHost() { return EdtHost->text(); }
    QString DatosOracle::getNomBaseDatos() {return NomBaseDatos; }


