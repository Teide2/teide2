/*******************************************************************************
** NuevoMetafile.h: muestra la ventana para crear el nuevo metafile.
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

#ifndef NUEVOMETAFILE_H
#define NUEVOMETAFILE_H

#include <QtCore/QVariant>
#include <QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QFrame>
#include <QtGui/QGroupBox>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QTextEdit>
#include <QtGui/QWidget>

#include <QFile>
#include <QTextStream>
#include <QFileDialog>
#include <QMessageBox>
//#include "Global.h"
#include "CheckPoblacion.h"



class TFrmNuevoMetafile : public QWidget
{
    Q_OBJECT

private:	// User declarations

    QString NombreFichero;

public:

    QGroupBox *GbxEditorMetafile;
    QTextEdit *MemMetafile;
    QGroupBox *GbxNombreMetafile;
    QLineEdit *EdtNombreMetafile;
    QPushButton *ButNombreMetafile;
    QFrame *PanDecision;
    QPushButton *ButAceptar;
    QPushButton *ButCancelar;
    QFrame *PanTags;
    QPushButton *ButNom;
    QPushButton *ButMd1;
    QPushButton *ButMd2;
    QPushButton *ButRbd;
    QPushButton *ButVar;
    QPushButton *ButMd3;
    QPushButton *ButEdt;
    QPushButton *ButMis;
    QPushButton *ButKey;

    TFrmNuevoMetafile(QWidget* parent, const char* name, Qt::WindowFlags fl);


public slots:

    void ButAceptarClick();

    void ButNombreMetafileClick();

    void ButCancelarClick();

    void ButNomClick();

    void ButRbdClick();

    void ButVarClick();

    void ButMd1Click();

    void ButMd2Click();

    void ButMd3Click();

    void ButEdtClick();

    void ButMisClick();
    void ButKeyClick();

};

#endif // NUEVOMETAFILE_H
