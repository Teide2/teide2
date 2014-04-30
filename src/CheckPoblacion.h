/*******************************************************************************
** CheckPoblacion.h:
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

#ifndef CHECKPOBLACION_H
#define CHECKPOBLACION_H

#include <QtCore/QVariant>
#include <QAction>
#include <QApplication>
#include <QButtonGroup>
#include <QCheckBox>
#include <QLabel>
#include <QLineEdit>
#include <QProgressBar>
#include <QPushButton>
#include <QTextEdit>
#include <QWidget>

#include "MicroDatos.h"
#include "DatosChequeo.h"
#include "DatosOracle.h"

class TFrmCheckPoblacion : public QWidget
{
    Q_OBJECT

private:	// User declarations

    TFrmDatosChequeo *datocheq;

    TFmeMicroDatos *FmeMicroDatosAsociados;
    TFmeVariables *FmeVariablesAsociadas;
    //QSqlQuery *query;
    unsigned NumRegistros;
    //unsigned NumRegistros2;
    unsigned NumVariables;
    QString NombBD1;
    QStringList *TablaDatos1;
    bool DosBD;
    bool Oracle;
    bool Xml;
    bool Excel;
    QWidget *padre;

public:

    //QLabel *LabTabCheck;
    //QLineEdit *EdtTabCheck;
    //QPushButton *ButChequear;
    QTextEdit *MemInfo;
    //QCheckBox *ChbCambioDivisas;
    QProgressBar *PbrProgreso;
    QPushButton *ButGuardarInforme;
    QSqlDatabase *AdqConsulta;
    QSqlDatabase AdqConsulta2;
    DatosOracle *datorac;
    QScrollArea *nuevo;
    TFrmCheckPoblacion(QWidget* parent, const char* name, Qt::WindowFlags fl, QSqlDatabase *AdcConexionBD, TFmeMicroDatos *FmeMicroDatosAsociados, QString BaseDatos, QStringList *TablaDatos, DatosOracle *DatosOrac);

    void inicio();

    void AsociarClases(TFmeMicroDatos *FmeMicroDatosAsociados);

    void FijarCantidadDatos();

    bool chequearCondicion();

    QString ObtenerValor(int reg);

    //void CheckPoblacion();

   // void CheckCambioDivisas();

   // void CheckCambioDivisasSingular(unsigned IndVarMonOrigen, unsigned IndVarImpOrigen, unsigned IndVarImpEuros, QString TablaCambio);

public slots:

    //void ButChequearClick();
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// PULSAR EL BOTÓN DE GUARDAR INFORME.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void ButGuardarInformeClick();
    void ButChequearClick();
    void ButCancelarClick();
    void ButAyudaClick();
    void ChbActCClick();
};

#endif // CHECKPOBLACION_H
