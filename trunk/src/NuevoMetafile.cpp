/*******************************************************************************
** NuevoMetafile.cpp: muestra la ventana para crear el nuevo metafile.
**
** author: M-S Hernández-García
*******************************************************************************/

#include "NuevoMetafile.h"



TFrmNuevoMetafile::TFrmNuevoMetafile(QWidget* parent, const char* name, Qt::WindowFlags fl):QWidget(parent, fl)
    {
      if (this->objectName().isEmpty())
        this->setObjectName(QString::fromUtf8("TFrmNuevoMetafile"));
      QSize size(767, 357);
      size = size.expandedTo(this->minimumSizeHint());
      this->resize(size);
      GbxEditorMetafile = new QGroupBox(this);
      GbxEditorMetafile->setObjectName(QString::fromUtf8("GbxEditorMetafile"));
      GbxEditorMetafile->setGeometry(QRect(8, 8, 577, 281));
      MemMetafile = new QTextEdit(GbxEditorMetafile);
      MemMetafile->setObjectName(QString::fromUtf8("MemMetafile"));
      MemMetafile->setGeometry(QRect(2, 19, 573, 260));
      GbxNombreMetafile = new QGroupBox(this);
      GbxNombreMetafile->setObjectName(QString::fromUtf8("GbxNombreMetafile"));
      GbxNombreMetafile->setGeometry(QRect(8, 296, 505, 57));
      EdtNombreMetafile = new QLineEdit(GbxNombreMetafile);
      EdtNombreMetafile->setObjectName(QString::fromUtf8("EdtNombreMetafile"));
      EdtNombreMetafile->setGeometry(QRect(24, 24, 353, 21));
      ButNombreMetafile = new QPushButton(GbxNombreMetafile);
      ButNombreMetafile->setObjectName(QString::fromUtf8("ButNombreMetafile"));
      ButNombreMetafile->setGeometry(QRect(392, 23, 91, 23));
      PanDecision = new QFrame(this);
      PanDecision->setObjectName(QString::fromUtf8("PanDecision"));
      PanDecision->setGeometry(QRect(528, 296, 233, 57));
      PanDecision->setFrameShape(QFrame::Panel);
      PanDecision->setFrameShadow(QFrame::Raised);
      ButAceptar = new QPushButton(PanDecision);
      ButAceptar->setObjectName(QString::fromUtf8("ButAceptar"));
      ButAceptar->setGeometry(QRect(24, 16, 81, 25));
      ButCancelar = new QPushButton(PanDecision);
      ButCancelar->setObjectName(QString::fromUtf8("ButCancelar"));
      ButCancelar->setGeometry(QRect(136, 16, 73, 25));
      PanTags = new QFrame(this);
      PanTags->setObjectName(QString::fromUtf8("PanTags"));
      PanTags->setGeometry(QRect(592, 16, 169, 273));
      PanTags->setFrameShape(QFrame::Panel);
      PanTags->setFrameShadow(QFrame::Raised);
      ButNom = new QPushButton(PanTags);
      ButNom->setObjectName(QString::fromUtf8("ButNom"));
      ButNom->setGeometry(QRect(8, 8, 153, 25));
      ButMd1 = new QPushButton(PanTags);
      ButMd1->setObjectName(QString::fromUtf8("ButMd1"));
      ButMd1->setGeometry(QRect(8, 92, 153, 25));
      ButMd2 = new QPushButton(PanTags);
      ButMd2->setObjectName(QString::fromUtf8("ButMd2"));
      ButMd2->setGeometry(QRect(8, 120, 153, 25));
      ButRbd = new QPushButton(PanTags);
      ButRbd->setObjectName(QString::fromUtf8("ButRbd"));
      ButRbd->setGeometry(QRect(8, 36, 153, 25));
      ButVar = new QPushButton(PanTags);
      ButVar->setObjectName(QString::fromUtf8("ButVar"));
      ButVar->setGeometry(QRect(8, 64, 153, 25));
      ButMd3 = new QPushButton(PanTags);
      ButMd3->setObjectName(QString::fromUtf8("ButMd3"));
      ButMd3->setGeometry(QRect(8, 148, 153, 25));
      ButEdt = new QPushButton(PanTags);
      ButEdt->setObjectName(QString::fromUtf8("ButEdt"));
      ButEdt->setGeometry(QRect(8, 176, 153, 25));
      ButMis = new QPushButton(PanTags);
      ButMis->setObjectName(QString::fromUtf8("ButMis"));
      ButMis->setGeometry(QRect(8, 204, 153, 25));
      ButKey = new QPushButton(PanTags);
      ButKey->setObjectName(QString::fromUtf8("ButKey"));
      ButKey->setGeometry(QRect(8, 232, 153, 25));

      this->setWindowTitle(QApplication::translate("TFrmNuevoMetafile", "Nuevo Metafile", 0, QApplication::UnicodeUTF8));
      GbxEditorMetafile->setTitle(QApplication::translate("TFrmNuevoMetafile", "Editor del Metafile", 0, QApplication::UnicodeUTF8));
      MemMetafile->setToolTip(QApplication::translate("TFrmNuevoMetafile", "Introduzca texto libre con la especificaci\303\263n del metafile ", 0, QApplication::UnicodeUTF8));
      GbxNombreMetafile->setTitle(QApplication::translate("TFrmNuevoMetafile", "Nombre del Metafile", 0, QApplication::UnicodeUTF8));
      EdtNombreMetafile->setToolTip(QApplication::translate("TFrmNuevoMetafile", "Indique el nombre del metafile.", 0, QApplication::UnicodeUTF8));
      ButNombreMetafile->setToolTip(QApplication::translate("TFrmNuevoMetafile", "Pulse aqu\303\255 para seleccionar el metafile de destino. ", 0, QApplication::UnicodeUTF8));
      ButNombreMetafile->setText(QApplication::translate("TFrmNuevoMetafile", "&Seleccionar...", 0, QApplication::UnicodeUTF8));
      ButAceptar->setText(QApplication::translate("TFrmNuevoMetafile", "&Aceptar", 0, QApplication::UnicodeUTF8));
      ButCancelar->setText(QApplication::translate("TFrmNuevoMetafile", "&Cancelar", 0, QApplication::UnicodeUTF8));
      ButNom->setToolTip(QApplication::translate("TFrmNuevoMetafile", "Pulse aqu\303\255 para a\303\261adir un tag de nombre del conjunto.", 0, QApplication::UnicodeUTF8));
      ButNom->setText(QApplication::translate("TFrmNuevoMetafile", "Nombre del conjunto", 0, QApplication::UnicodeUTF8));
      ButMd1->setToolTip(QApplication::translate("TFrmNuevoMetafile", "Pulse aqu\303\255 para a\303\261adir un tag de nombre de tabla Microdatos 1. ", 0, QApplication::UnicodeUTF8));
      ButMd1->setText(QApplication::translate("TFrmNuevoMetafile", "Tabla de Microdatos 1", 0, QApplication::UnicodeUTF8));
      ButMd2->setToolTip(QApplication::translate("TFrmNuevoMetafile", "Pulse aqu\303\255 para a\303\261adir un tag de nombre de tabla de Microdatos 2.", 0, QApplication::UnicodeUTF8));
      ButMd2->setText(QApplication::translate("TFrmNuevoMetafile", "Tabla de Microdatos 2", 0, QApplication::UnicodeUTF8));
      ButRbd->setToolTip(QApplication::translate("TFrmNuevoMetafile", "Pulse aqu\303\255 para a\303\261adir un tag de ruta de la base de datos. ", 0, QApplication::UnicodeUTF8));
      ButRbd->setText(QApplication::translate("TFrmNuevoMetafile", "Ruta de la base de datos", 0, QApplication::UnicodeUTF8));
      ButVar->setToolTip(QApplication::translate("TFrmNuevoMetafile", "Pulse aqu\303\255 para a\303\261adir un tag de nombre de tabla de Variables.", 0, QApplication::UnicodeUTF8));
      ButVar->setText(QApplication::translate("TFrmNuevoMetafile", "Tabla de Variables", 0, QApplication::UnicodeUTF8));
      ButMd3->setToolTip(QApplication::translate("TFrmNuevoMetafile", "Pulse aqu\303\255 para a\303\261adir un tag de nombre de tabla de Microdatos 3.", 0, QApplication::UnicodeUTF8));
      ButMd3->setText(QApplication::translate("TFrmNuevoMetafile", "Tabla de Microdatos 3", 0, QApplication::UnicodeUTF8));
      ButEdt->setToolTip(QApplication::translate("TFrmNuevoMetafile", "Pulse aqu\303\255 para a\303\261adir un tag de nombre de tabla de Reglas.", 0, QApplication::UnicodeUTF8));
      ButEdt->setText(QApplication::translate("TFrmNuevoMetafile", "Tabla de Reglas", 0, QApplication::UnicodeUTF8));
      ButMis->setToolTip(QApplication::translate("TFrmNuevoMetafile", "Pulse aqu\303\255 para a\303\261adir un tag de nombre de tabla de Missing.", 0, QApplication::UnicodeUTF8));
      ButMis->setText(QApplication::translate("TFrmNuevoMetafile", "Tabla de Missing", 0, QApplication::UnicodeUTF8));
      ButKey->setToolTip(QApplication::translate("TFrmNuevoMetafile", "Pulse aqu\303\255 para a\303\261adir un tag de la variable indentificadora (Key).", 0, QApplication::UnicodeUTF8));
      ButKey->setText(QApplication::translate("TFrmNuevoMetafile", "Key", 0, QApplication::UnicodeUTF8));

      QObject::connect(ButNombreMetafile, SIGNAL(clicked()), this, SLOT(ButNombreMetafileClick()));
      QObject::connect(ButAceptar, SIGNAL(clicked()), this, SLOT(ButAceptarClick()));
      QObject::connect(ButCancelar, SIGNAL(clicked()), this, SLOT(ButCancelarClick()));
      QObject::connect(ButNom, SIGNAL(clicked()), this, SLOT(ButNomClick()));
      QObject::connect(ButMd1, SIGNAL(clicked()), this, SLOT(ButMd1Click()));
      QObject::connect(ButMd2, SIGNAL(clicked()), this, SLOT(ButMd2Click()));
      QObject::connect(ButMd3, SIGNAL(clicked()), this, SLOT(ButMd3Click()));
      QObject::connect(ButMis, SIGNAL(clicked()), this, SLOT(ButMisClick()));
      QObject::connect(ButEdt, SIGNAL(clicked()), this, SLOT(ButEdtClick()));
      QObject::connect(ButVar, SIGNAL(clicked()), this, SLOT(ButVarClick()));
      QObject::connect(ButRbd, SIGNAL(clicked()), this, SLOT(ButRbdClick()));
      QObject::connect(ButKey, SIGNAL(clicked()), this, SLOT(ButKeyClick()));

      QMetaObject::connectSlotsByName(this);
    }


    void TFrmNuevoMetafile::ButAceptarClick()
    {
      if (NombreFichero == "")
        QMessageBox::warning(this, "Warning",  QApplication::translate("", "No ha introducido ning\303\272n fichero", 0, QApplication::UnicodeUTF8), "&Ok");
      else  {
        QString text = MemMetafile->toPlainText ();
        QFile f( NombreFichero );
        if ( !f.open( QIODevice::WriteOnly ) )
          QMessageBox::warning(this, "Warning", QString( tr("No se puede escribir en el fichero %1") ).arg( NombreFichero ), "&Ok");
        else {
          QTextStream t( &f );
          t << text;
          f.close();
          hide();
        }
      }
    }

    void TFrmNuevoMetafile::ButNombreMetafileClick()
    {
      QString start = QCoreApplication::applicationDirPath();
      QString meta = QDir::convertSeparators("/metafiles");
      NombreFichero = QFileDialog::getSaveFileName(this, tr("Guardar fichero metafile"), start+meta, "VME (*.vme)");
      EdtNombreMetafile->setText(NombreFichero);

    }

    void TFrmNuevoMetafile::ButCancelarClick()
    {      
      hide();
    }

    void TFrmNuevoMetafile::ButNomClick()
    {
      MemMetafile->append(QApplication::translate("", "<NOM> \"Escriba aqu\303\255 el valor del tag\"", 0, QApplication::UnicodeUTF8));
    }

    void TFrmNuevoMetafile::ButRbdClick()
    {      
      MemMetafile->append(QApplication::translate("", "<RBD> \"Escriba aqu\303\255 el valor del tag\"", 0, QApplication::UnicodeUTF8));
    }

    void TFrmNuevoMetafile::ButVarClick()
    {
      MemMetafile->append( "<VAR");
      MemMetafile->insertPlainText(QApplication::translate("", "> \"Escriba aqu\303\255 el valor del tag\"", 0, QApplication::UnicodeUTF8));
    }

    void TFrmNuevoMetafile::ButMd1Click()
    {
      MemMetafile->append(QApplication::translate("", "<MD1> \"Escriba aqu\303\255 el valor del tag\"", 0, QApplication::UnicodeUTF8));
    }

    void TFrmNuevoMetafile::ButMd2Click()
    {
      MemMetafile->append(QApplication::translate("", "<MD2> \"Escriba aqu\303\255 el valor del tag\"", 0, QApplication::UnicodeUTF8));
    }

    void TFrmNuevoMetafile::ButMd3Click()
    {
      MemMetafile->append(QApplication::translate("", "<MD3> \"Escriba aqu\303\255 el valor del tag\"", 0, QApplication::UnicodeUTF8));
    }

    void TFrmNuevoMetafile::ButEdtClick()
    {
      MemMetafile->append(QApplication::translate("", "<EDT> \"Escriba aqu\303\255 el valor del tag\"", 0, QApplication::UnicodeUTF8));
    }

    void TFrmNuevoMetafile::ButMisClick()
    {
      MemMetafile->append(QApplication::translate("", "<MIS> \"Escriba aqu\303\255 el valor del tag\"", 0, QApplication::UnicodeUTF8));

    }
    void TFrmNuevoMetafile::ButKeyClick()
    {
      MemMetafile->append(QApplication::translate("", "<KEY> \"Escriba aqu\303\255 el valor del tag\"", 0, QApplication::UnicodeUTF8));

    }

