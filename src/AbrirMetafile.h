/*******************************************************************************
** AbrirMetafile.h: abre la ventana que permite abrir un fichero metafile.
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

#ifndef ABRIRMETAFILE_H
#define ABRIRMETAFILE_H

#include <QtCore/QVariant>
#include <QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QComboBox>
#include <QtGui/QGroupBox>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpinBox>
#include <QtGui/QTextEdit>
#include <QtGui/QTreeView>
#include <QtGui/QWidget>
#include <QMenu>
#include <QFileDialog>
#include <QMessageBox>
#include <QFile>
#include <QTextStream>
#include <QDirModel>
#include <QTreeView>
#include "NuevoMetafile.h"


class TFrmAbrirMetafile : public QWidget
{
    Q_OBJECT

private:	// User declarations
    QString NombreMetafile;
    bool mrOK;    

public:

    QGroupBox *GbxMetafile;
    QTextEdit *MemMetafile;
    QGroupBox *GbxSeleccionMetafile;
    QLabel *LabNumRegistros;
    QLabel *LabPorcCont;
    QLabel *Label2;
    QLabel *LabCondicionLectura;
    QPushButton *ButAyudaCond;
    QMenu *menu;    
    QPushButton *ButExaminar;
    QLineEdit *FlbFichero;
    QPushButton *ButAceptar;    
    QPushButton *ButCancelar;
    QLineEdit *EdtNumRegistros;
    QCheckBox *ChbContaminar;
    QSpinBox *EdtPorcentajeContaminacion;
    QLineEdit *EdtCondicionLectura;

    TFrmAbrirMetafile(QWidget* parent, const char* name, Qt::WindowFlags fl);

    QString GetNombreMetafile();
    
    bool GetmrOK();

    bool ContaminarMicrodatos();

    int GetPorcentajeContaminacion();

    //int GetNumRegistros();

    bool MetafileCorrrecto();

public slots:

    void ButExaminarClick();

    //void ButAceptarClick();

    void ButCancelarClick();    

    void ChbContaminarClick();

    void VisualizarAyudaClick();

};

#endif // ABRIRMETAFILE_H
