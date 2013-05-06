/*******************************************************************************
** Estadisticas.h: contiene todo lo necesario para trabajar con la solapa
**                   Estadisticas.
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

#ifndef ESTADISTICAS_H
#define ESTADISTICAS_H

#include <QVariant>
#include <QAction>
#include <QApplication>
#include <QButtonGroup>
#include <QComboBox>
#include <QFrame>
#include <QGroupBox>
#include <QLabel>
#include <QLineEdit>
#include <QProgressBar>
#include <QPushButton>
#include <QTextEdit>
#include <QWidget>

#include "Imputacion.h"

#include <qpen.h>
#include <qwt_plot.h>
#include <qwt_plot_grid.h>
#include <qwt_plot_marker.h>
//#include <qwt_interval_data.h>
//#include "histogram_item.h"


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
typedef
  struct
  {
    double x;
    double y;
  }
  TTipoResumenVariables;
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class TFmeEstadisticas : public QWidget
{
    Q_OBJECT

public:

    QLineEdit *PanProgreso;
    QLabel *LabOperacion;
    QLabel *LabProgreso;
    QLabel *LabPorcentaje;
    QLabel *LabElemento;
    QLineEdit *EdtOperacion;
    QProgressBar *PbrProgreso;
    QLineEdit *EdtPorcentaje;
    QLineEdit *EdtElemento;
    QFrame *PanContenedor;
    QLabel *SptSeparador;
    QFrame *PanUtilidades;
    QLabel *LabVariable;
    QComboBox *CbxVariables;
    QPushButton *ButGuardarInforme;
    QTextEdit *MemInfo;
    QGroupBox *GbxHistogramaFrecuencias;
    QLineEdit *EdtValoresRango;
    QLineEdit *EdtValoresMissing;
    QwtPlotHistogram *histogrampre;
    QwtPlotHistogram *histogrampos;
    QwtPlotHistogram *histogrampreM;
    QwtPlotHistogram *histogramposM;
    QwtPlot *plot;
    QwtPlotGrid *grid;
    QwtPlot *plotM;
    QwtPlotGrid *gridM;
    QPushButton *ButAnterior;
    QPushButton *ButSiguiente;
    QPushButton *ButAnteriorM;
    QPushButton *ButSiguienteM;

    TFmeEstadisticas(QWidget* parent, const char* name, Qt::WindowFlags fl, QString NombreConjunto, TFmeImputacion *FmeImputacionAsociada, TFrmOpciones *FrmOpciones);
    void ajustarSize();
    void SetTiempoCargaDatos(double t);
    bool EstaCargado() ;

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Asociar las clases provenientes de etapas anteriores.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void AsociarClases(TFmeImputacion *FmeImputacionAsociada);
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Fijar la cantidad de datos que intervienen en el proceso.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void FijarCantidadDatos();
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Generar las estadisticas del proceso.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void GenerarEstadisticas(bool resumen);
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Generar las estadisticas de la seccion de variables.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void GenerarEstadisticasVariables();
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Generar las estadisticas de la seccion de microdatos.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void GenerarEstadisticasMicroDatos();
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Generar las estadisticas de la seccion de edits.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void GenerarEstadisticasEdits();
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Generar las estadisticas de la seccion de rangos.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void GenerarEstadisticasRangos();
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Generar las estadï¿½sticas de la secciï¿½n de test.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void GenerarEstadisticasTest();
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Generar las estadï¿½sticas de la seccion de imputacion.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void GenerarEstadisticasImputacion();
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Generar el listado de edits.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void GenerarListadoEdits();
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Generar el listado del incumplimiento de edits.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void GenerarIncumplimientoEdits();
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Generar el listado de las variables imputadas en cada registro.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void GenerarVariablesImputadas();
    void GenerarInformacionDonantes();
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Generar el listado de pertenencia de variables a edits.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void GenerarPertenenciaVariables();
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Generar el listado de exclusion.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void GenerarExclusion();
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Generar el resumen de las variables.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void GenerarResumenVariables();
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Inicializar el vector de resumen de variables.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void InicializarResumenVariables(TTipoResumenVariables ***RV);
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Inicializar el sistema de progreso.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void InicSistemaProgreso();
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Incrementar el sistema de progreso.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void IncSistemaProgreso();
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Realizar el resumen de variables.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void RealizarResumenVariables(TTipoResumenVariables **RV, double **MicroDatos);
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Generar un listado coyuntural.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void GenerarListadoCoyuntural();
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Generar un listado de porcentajes de error tanto en rangos como en edits.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void GenerarListadoErrores();
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Generar un listado con el porcentaje de imputacion por variables.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void GenerarImputacionVariables();
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Generar un listado con la correspondencia entre numeros de variables y nombres de variables.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void GenerarCorrespondenciaVariables();
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Generar las tablas latex de descripciï¿½n y resumen.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void GenerarTablaLatex();
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Añadir una linea al fichero de ejecuciones.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void AddExecutionLine();
    QString SustCaracter(QString Cadena, char CarABuscar, char CarSustitucion);

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void ant_sig_hist(bool sig);
    void ant_sig_histM(bool sig);

public slots:

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// PULSAR EL BOTON DE GUARDAR INFORME.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void ButGuardarInformeClick();
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// SELECCIONAR UN ELEMENTO DE LA LISTA DE VARIABLES.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void CbxVariablesCloseUp(int index);
    void ButClick_sig();
    void ButClick_ant();
    void ButClick_sigM();
    void ButClick_antM();

private:

  TFmeImputacion *FmeImputacionAsociada;
  TFmeTest *FmeTestAsociado;
  TFmeRangos *FmeRangosAsociados;
  TFmeEdits *FmeEditsAsociados;
  TFmeMicroDatos *FmeMicroDatosAsociados;
  TFmeVariables *FmeVariablesAsociadas;
  TFrmOpciones *FrmOpciones;

  unsigned NumRegistros;
  unsigned NumVariables;
  unsigned NumEdits;
  QString NombreConjunto;
  bool Cargado;
  double TiempoCargaDatos;

  TTipoResumenVariables **ResumenVariablesPreImputacion;
  TTipoResumenVariables **ResumenVariablesPosImputacion;

  QTextEdit *MemLogs;
  double ultimo;
  double ultimoM;
  double resumido;

  QMap <int,int> donantesreg;
  QList <int> donantes;  

};

#endif // ESTADISTICAS_H