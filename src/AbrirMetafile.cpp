/*******************************************************************************
** AbrirMetafile.cpp: abre la ventana que permite abrir un fichero metafile.
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

#include "AbrirMetafile.h"

TFrmAbrirMetafile::TFrmAbrirMetafile(QWidget* parent, const char* name, Qt::WindowFlags fl):QWidget(parent, fl)
    {
      if (this->objectName().isEmpty())
        this->setObjectName(QString::fromUtf8("TFrmAbrirMetafile"));
      QSize size(689, 494);
      size = size.expandedTo(this->minimumSizeHint());
      this->resize(size);

      GbxMetafile = new QGroupBox(this);
      GbxMetafile->setObjectName(QString::fromUtf8("GbxMetafile"));
      GbxMetafile->setGeometry(QRect(8, 8, 673, 177));

      MemMetafile = new QTextEdit(GbxMetafile);
      MemMetafile->setObjectName(QString::fromUtf8("MemMetafile"));
      MemMetafile->setGeometry(QRect(2, 19, 669, 155));
      MemMetafile->setReadOnly(true);

      GbxSeleccionMetafile = new QGroupBox(this);
      GbxSeleccionMetafile->setObjectName(QString::fromUtf8("GbxSeleccionMetafile"));
      GbxSeleccionMetafile->setGeometry(QRect(8, 192, 673, 289));

      LabNumRegistros = new QLabel(GbxSeleccionMetafile);
      LabNumRegistros->setObjectName(QString::fromUtf8("LabNumRegistros"));
      LabNumRegistros->setGeometry(QRect(8, 55, 156, 18));

      LabPorcCont = new QLabel(GbxSeleccionMetafile);
      LabPorcCont->setObjectName(QString::fromUtf8("LabPorcCont"));
      LabPorcCont->setGeometry(QRect(8, 130, 266, 18));

      Label2 = new QLabel(GbxSeleccionMetafile);
      Label2->setObjectName(QString::fromUtf8("Label2"));
      Label2->setGeometry(QRect(60, 150, 11, 18));

      LabCondicionLectura = new QLabel(GbxSeleccionMetafile);
      LabCondicionLectura->setObjectName(QString::fromUtf8("LabCondicionLectura"));
      LabCondicionLectura->setGeometry(QRect(8, 185, 248, 18));

      QString start = QCoreApplication::applicationDirPath();
      QString meta = QDir::toNativeSeparators("/images/interrogacion.bmp");
      ButAyudaCond = new QPushButton(GbxSeleccionMetafile);
      ButAyudaCond->setObjectName(QString::fromUtf8("ButAyudaCond"));
      ButAyudaCond->setGeometry(QRect(259, 185, 20, 20));
      ButAyudaCond->setIcon(QPixmap(start+meta, 0, Qt::AutoColor));

      menu = new QMenu(ButAyudaCond);
      menu->setTitle("Consejos a tener en cuenta");
      menu->addAction( QApplication::translate("TFrmAbrirMetafile", "S\303\263lo se puede poner condici\303\263n de lectura si la base de datos consta de una sola tabla de datos", 0));
      menu->addSeparator();
      menu->addAction(QObject::tr("Se debe tener en cuenta el tipo de variable: "));
      menu->addAction(QObject::tr("  Si es texto, poner comillas(') Ej: varTexto = 'esd'"));
      menu->addAction(QApplication::translate("TFrmAbrirMetafile", "  Si es un n\303\272mero, no poner comillas(') Ej: varnum = 10", 0));

      FlbFichero = new QLineEdit(GbxSeleccionMetafile);
      FlbFichero->setObjectName(QString::fromUtf8("FlbFichero"));
      FlbFichero->setGeometry(QRect(8, 24, 560, 19));
      FlbFichero->setReadOnly(true);

      ButExaminar = new QPushButton(GbxSeleccionMetafile);
      ButExaminar->setObjectName(QString::fromUtf8("ButExaminar"));
      ButExaminar->setGeometry(QRect(570, 22, 97, 25));

      ButAceptar = new QPushButton(GbxSeleccionMetafile);
      ButAceptar->setObjectName(QString::fromUtf8("ButAceptar"));
      ButAceptar->setGeometry(QRect(230, 245, 97, 25));
      ButCancelar = new QPushButton(GbxSeleccionMetafile);
      ButCancelar->setObjectName(QString::fromUtf8("ButCancelar"));
      ButCancelar->setGeometry(QRect(430, 245, 97, 25));

      EdtNumRegistros = new QLineEdit(GbxSeleccionMetafile);
      EdtNumRegistros->setObjectName(QString::fromUtf8("EdtNumRegistros"));
      EdtNumRegistros->setGeometry(QRect(8, 75, 113, 21));

      ChbContaminar = new QCheckBox(GbxSeleccionMetafile);
      ChbContaminar->setObjectName(QString::fromUtf8("ChbContaminar"));
      ChbContaminar->setGeometry(QRect(8, 110, 151, 17));

      EdtPorcentajeContaminacion = new QSpinBox(GbxSeleccionMetafile);
      EdtPorcentajeContaminacion->setObjectName(QString::fromUtf8("EdtPorcentajeContaminacion"));
      EdtPorcentajeContaminacion->setGeometry(QRect(8, 150, 46, 23));
      EdtPorcentajeContaminacion->setEnabled(false);

      EdtCondicionLectura = new QLineEdit(GbxSeleccionMetafile);
      EdtCondicionLectura->setObjectName(QString::fromUtf8("EdtCondicionLectura"));
      EdtCondicionLectura->setGeometry(QRect(8, 205, 649, 21));

      this->setWindowTitle(QApplication::translate("TFrmAbrirMetafile", "Abrir Metafile", 0));
      GbxMetafile->setTitle(QApplication::translate("TFrmAbrirMetafile", "&Vista previa del Metafile", 0));
      MemMetafile->setToolTip(QApplication::translate("TFrmAbrirMetafile", "Visualizaci\303\263n previa del contenido del metafile seleccionado. ", 0));
      GbxSeleccionMetafile->setToolTip(QApplication::translate("TFrmAbrirMetafile", "Selecci\303\263n del directorio de trabajo", 0));
      GbxSeleccionMetafile->setTitle(QApplication::translate("TFrmAbrirMetafile", "Selecci\303\263n del Metafile", 0));
      LabNumRegistros->setText(QApplication::translate("TFrmAbrirMetafile", "Num. registros a cargar", 0));
      LabPorcCont->setText(QApplication::translate("TFrmAbrirMetafile", "Porcentaje de contaminaci\303\263n por registro", 0));
      Label2->setText(QApplication::translate("TFrmAbrirMetafile", "%", 0));
      LabCondicionLectura->setText(QApplication::translate("TFrmAbrirMetafile", "Condici\303\263n de lectura en base de datos", 0));
      FlbFichero->setToolTip(QApplication::translate("TFrmAbrirMetafile", "Ruta del metafile seleccionado.", 0));
      ButExaminar->setText(QApplication::translate("TFrmAbrirMetafile", "&Examinar", 0));
      ButAceptar->setText(QApplication::translate("TFrmAbrirMetafile", "&Aceptar", 0));
      ButCancelar->setText(QApplication::translate("TFrmAbrirMetafile", "&Cancelar", 0));
      ChbContaminar->setText(QApplication::translate("TFrmAbrirMetafile", "Contaminar datos", 0));
      ButAyudaCond->setToolTip(QApplication::translate("TFrmAbrirMetafile", "Informaci\303\263n sobre cuando se puede poner condici\303\263n de lectura", 0));

      connect(ButExaminar, SIGNAL(clicked()), this, SLOT(ButExaminarClick()));
      connect(ButCancelar, SIGNAL(clicked()), this, SLOT(ButCancelarClick()));
      connect(ChbContaminar, SIGNAL(clicked()), this, SLOT(ChbContaminarClick()));
      connect(ButAyudaCond, SIGNAL(clicked()), this, SLOT(VisualizarAyudaClick()));
      QMetaObject::connectSlotsByName(this);

      EdtNumRegistros->setText(NUM_REGISTROS_A_CARGAR);
      mrOK = false;
      QObject::connect(ButAceptar, SIGNAL(clicked()), parent, SLOT(ButAceptarMetafileClick()));      
    }

    QString TFrmAbrirMetafile::GetNombreMetafile() { return NombreMetafile; }
    
    bool TFrmAbrirMetafile::GetmrOK() { return mrOK; }

    bool TFrmAbrirMetafile::ContaminarMicrodatos() { return ChbContaminar->isChecked (); }

    int TFrmAbrirMetafile::GetPorcentajeContaminacion() { return EdtPorcentajeContaminacion->value(); }

    //int TFrmAbrirMetafile::GetNumRegistros() { return EdtNumRegistros->text().toInt(); }

    void TFrmAbrirMetafile::ButExaminarClick()
    {
      QString start = QCoreApplication::applicationDirPath() + "/metafiles";
      QString line;
      NombreMetafile = QFileDialog::getOpenFileName(this, tr("Abrir fichero metafile"), start, "VME (*.vme)");
      FlbFichero->setText(NombreMetafile);
      MemMetafile->setText("");
      if (!NombreMetafile.isEmpty()) {
        QFile file(NombreMetafile);
        if ( file.open( QIODevice::ReadOnly ) ) {
          QTextStream in( &file );
          while (!in.atEnd()) {
             line = in.readLine();
             QString string(line);
             MemMetafile->insertPlainText(string + "\n");
          }
          file.close();
        }
      }
    }
    bool TFrmAbrirMetafile::MetafileCorrrecto()
    {        
        QString cadena = MemMetafile->toPlainText();

        if (!cadena.contains("<NOM>", Qt::CaseSensitive))
        {
            QMessageBox::warning(this, "Warning",  QApplication::translate("", "No ha introducido el tab <NOM>", 0), "&Ok");
            return false;
        }
        if (!cadena.contains("<RBD>", Qt::CaseSensitive))
        {
            QMessageBox::warning(this, "Warning",  QApplication::translate("", "No ha introducido el tab <RBD>", 0), "&Ok");
            return false;
        }
        if (!cadena.contains("<VAR>", Qt::CaseSensitive))
        {
            QMessageBox::warning(this, "Warning",  QApplication::translate("", "No ha introducido el tab <.", 0) + "VAR>", "&Ok");
            return false;
        }
        if (!cadena.contains("<MD1>", Qt::CaseSensitive))
        {
            QMessageBox::warning(this, "Warning",  QApplication::translate("", "No ha introducido el tab <MD1>", 0), "&Ok");
            return false;
        }
        if (!cadena.contains("<EDT>", Qt::CaseSensitive))
        {
            QMessageBox::warning(this, "Warning",  QApplication::translate("", "No ha introducido el tab <EDT>", 0), "&Ok");
            return false;
        }
        if (!cadena.contains("<MIS>", Qt::CaseSensitive))
        {
            QMessageBox::warning(this, "Warning",  QApplication::translate("", "No ha introducido el tab <MIS>", 0), "&Ok");
            return false;
        }
        if (!cadena.contains("<KEY>", Qt::CaseSensitive))
        {
            QMessageBox::warning(this, "Warning",  QApplication::translate("", "No ha introducido el tab <KEY>", 0), "&Ok");
            return false;
        }
        return true;
    } 

    void TFrmAbrirMetafile::ButCancelarClick()
    {      
      NombreMetafile = "";
      mrOK = false;
      hide();
    }

    void TFrmAbrirMetafile::ChbContaminarClick()
    {
      if (ChbContaminar->isChecked())
        EdtPorcentajeContaminacion->setEnabled(true);
      else {
        EdtPorcentajeContaminacion->setEnabled(false);
        EdtPorcentajeContaminacion->setValue(0);
      }
    }

    void TFrmAbrirMetafile::VisualizarAyudaClick()
    {
        menu->popup(QCursor::pos());
    }

