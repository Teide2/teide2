/*******************************************************************************
** Teide2.h: programa principal.
**
** author: M-S Hernández-García
*******************************************************************************/

#ifndef TEIDE2_H
#define TEIDE2_H
#include <QDesktopWidget>
#include <QVariant>
#include <QAction>
#include <QApplication>
#include <QButtonGroup>
#include <QFrame>
#include <QLabel>
#include <QMainWindow>
#include <QMenu>
#include <QMenuBar>
#include <QStatusBar>
#include <QTabWidget>
#include <QTextEdit>
#include <QWidget>
#include <QMessageBox>
//#include <QMessageBoxDetailsText>
#include <QDesktopServices>
#include <QUrl>
#include <QObject>
#include <qdom.h>
#include "scrollarea.h"
//#include "helpwindow.h"
#include "AbrirMetafile.h"
#include "Edits.h"
#include "IrAVariable.h"
#include "Test.h"
#include "Imputacion.h"
#include "Estadisticas.h"
#include "ficheroXML.h"
#include "DatosOracle.h"
#include "MensajeCarga.h"
//enum DetailButtonLabel { ShowLabel = 0, HideLabel = 1 };
//QString label(DetailButtonLabel2 label) { return label == ShowLabel ? QMessageBox::tr("Mostrar Detalles...") : QMessageBox::tr("Ocultar Detalles..."); }

class TFrmPrincipal : public QMainWindow
{
    Q_OBJECT

public:

    QAction *MitNuevoMetafile;
    QAction *MitAbrirMetafile;
    QAction *MitCerrarMetafile;
    QAction *MitOpciones;
    QAction *MitProcederPasoAPaso;
    QAction *MitProcederCompleto;
    QAction *MitCheckPoblacion;
    QAction *MitSalir;
    QAction *MitAyudaTEIDE2;
    QAction *MitAcercaDe;
    QTabWidget *PctContenedorPrincipal;
    QFrame *PanCargarMetafile;
    QFrame *PanTitulo;
    QLabel *LabTitulo;
    QTextEdit *MemLogs;
    QFrame *ShpRibete1;
    QLineEdit *ShpRibete2;
    QMenuBar *MmnMenuPrincipal;
    QMenu *MitPrincipal;
    QMenu *MitAyuda;
    QStatusBar *statusbar;
    QSqlDatabase AdcConexionBD;

    TFrmPrincipal(QWidget* parent, int argc, char ** argv);

    void PrimeraEjecucion();
    void ContandoEjecucion();

    //void ajustarSize();
    void updateGeometry ();

    void resizeEvent ( QResizeEvent * event );

    void asignar(Scrollarea * scroll);

    void AbrirUnMetafile(QString Metafile);

    void CargarMetafile(QString NombreMetafile);

    void continuarCargaMetafile(QString NombreMetafile, QString NombreBaseDatos);

    QStringList *GetTablasMicroDatos(QString NombreMetafile);

    QString GetValorTag(QString NombreMetafile, QString tag);

    bool CrearConexionBD(QString NombreBaseDatos, QString CadenaConexionBD, QString *mens);

    QWidget *CrearNuevaHoja(QString Nombre, bool Visible);

    bool ChequearMicroDatos(QStringList *TablasMicroDatos, QSqlDatabase *AdcConexionBD, unsigned &NumRegistros,
    QStringList **VariablesTrabajo, QStringList **ListaIds, QTextEdit *MemLogs, QString Key, QString Nor, QString &Cota,
    QString CondicionLectura, QString NombreTablaMissing, int *Num_valores_missing, QStringList **Cadenas_Missing);
    int size_tabla(QSqlQuery query) ;
    
    bool ChequearMicroDatosXML(QStringList *TablasMicroDatos, QString NombreBaseDatos, unsigned &NumRegistros,
    QStringList **VariablesTrabajo, QStringList **ListaIds, QTextEdit *MemLogs, QString Key, QString Nor, QString &Cota,
    QString CondicionLectura, QString NombreTablaMissing, int *Num_valores_missing, QStringList **Cadenas_Missing);
    void LiberarConjuntosDatos();

   
public slots:

    void probando (int ventana);
    void ajustarSize(int entero);
    void ajustarSize();

    void Actualizacion_interfaz_usuario();

    void ButAceptarOracle();

    void ButCancelarOracle();

    void ButAceptarMetafileClick();    

    void MitAbrirMetafileClick();

    void MitSalirClick();

    void MitCerrarMetafileClick();

    void MitNuevoMetafileClick();

    void MitAccesstoXMLClick();
    void MitXMLtoAccessClick();

    void MitProcederPasoAPasoClick();

    void MitAcercaDeClick();
  
    void MitOpcionesClick();

    void MitAyudaTEIDE2Click();

    void MitProcederCompletoClick();

    void MitCheckPoblacionClick();

    void HacerBatchMode();

    void CambiarSolapa ( int index );

private:	// User declarations

  TTipoVentana TipoVentana;
  bool DatosCargados;
  bool conexion;
  bool BatchMode;
  bool Oracle;
  bool Xml;
  bool Excel;
  DatosOracle *datorac;
  QTime InstanteComienzo;
  QTime InstanteFinalizacion;
  TTipoFase Fase;
  
  TFmeMicroDatos *FmeMicroDatos;
  TFmeVariables *FmeVariables;
  TFmeEdits *FmeEdits;
  TFmeRangos *FmeRangos;
  TFmeTest *FmeTest;
  TFmeImputacion *FmeImputacion;
  TFmeEstadisticas *FmeEstadisticas;

  QWidget *VentanaMicroDatos;
  QWidget *VentanaVariables;
  QWidget *VentanaEdits;
  QWidget *VentanaRangos;
  QWidget *VentanaTest;
  QWidget *VentanaImputacion;
  QWidget *VentanaEstadisticas;

  TFrmIrAVariable *FrmIrAVariable;
  TFrmCheckPoblacion *FrmCheckPoblacion;

  TFrmOpciones *FrmOpciones;
  TFrmAbrirMetafile *FrmAbrirMetafile;
  TFrmCambiarMicrodato *FrmCambiarMicrodato;
  QString EXTRATITULO2;
  Scrollarea *scrollarea;
  int numParam;   // número de parametros que se pasa por en modo batch
  QString NomMetafileParam;  // nombre del metafile que se pasa en modo batch
  QString nomMet;  
  bool segundaEjecucion;
  int contEjecucion;

};
#endif // TEIDE2_H
