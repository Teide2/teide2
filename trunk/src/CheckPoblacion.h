/*******************************************************************************
** CheckPoblacion.h:
**
** author: M-S Hernández-García
*******************************************************************************/

#ifndef CHECKPOBLACION_H
#define CHECKPOBLACION_H

#include <QtCore/QVariant>
#include <QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QProgressBar>
#include <QtGui/QPushButton>
#include <QtGui/QTextEdit>
#include <QtGui/QWidget>

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
