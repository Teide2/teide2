/*******************************************************************************
** DatosChequeo.h:
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

#ifndef DATOSCHEQUEO_H
#define DATOSCHEQUEO_H

#include <QVariant>
#include <QAction>
#include <QApplication>
#include <QButtonGroup>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QWidget>
#include <QDir>

#include "MicroDatos.h"
#include "AyudaChequear.h"

class TFrmDatosChequeo : public QWidget
{   

    //Q_OBJECT

private:	// User declarations


public:

    QFrame *panel1;
    QFrame *panel2;
    QFrame *panel3;
    QFrame *panel4;
    QFrame *panel5;
    QFrame *panel6;
    QLabel *LabBD1;
    QLineEdit *EdtBD1;
    QLabel *LabBD2;
    QLineEdit *EdtBD2;
    QLabel *LabTD1;
    QLineEdit *EdtTD1;
    QLabel *LabTD2;
    QLineEdit *EdtTD2;
    QLabel *LabAux;
    QLabel *LabVar;
    QLineEdit *EdtVar;
    QLabel *LabAux2;
    QLineEdit *EdtVarConteo;
    QLabel *LabVarConteo;
    QPushButton *ButChequear;
    QPushButton *ButCancelar;
    QPushButton *ButAyuda;
    QLabel *LabPorcentaje;
    QLineEdit *EdtPorcentaje;
    QLabel *LabTanto;
    QCheckBox *ChbActC;
    QGroupBox *GbActC;
    QLabel *LabVariablesC;
    QTextEdit *EdtVariablesC;
    QLabel *LabOperadorC;
    QComboBox *CbxOperadorC;
    QLabel *LabValorC;
    QLineEdit *EdtValorC;

    TFrmDatosChequeo(QWidget* parent, const char* name, Qt::WindowFlags fl, bool activar, QString nomBD, QStringList *tablaDatos);
    QString GetEdtBD1();
    QString GetEdtBD2();
    QString GetEdtTD1();
    QString GetEdtTD2();
    QString GetEdtVar();
    QString GetEdtVarConteo();
    //QString GetEdtCondicion();
    QString GetEdtPorcentaje();
    QCheckBox *GetChbActC();
    QGroupBox *GetGbActC();
    QString GetEdtVariablesC();
    QString GetOperadorC();
    QString GetEdtValorC();

public slots:



};

#endif // DATOSCHEQUEO_H
