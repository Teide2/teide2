/*******************************************************************************
** Test.h: contiene todo lo necesario para trabajar con la solapa
**           eval. de edits.
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


#ifndef TEST_H
#define TEST_H

#include <QVariant>
#include <QAction>
#include <QApplication>
#include <QButtonGroup>
#include <QFrame>
#include <QGroupBox>
#include <QLabel>
#include <QLineEdit>
#include <QProgressBar>
#include <QPushButton>
#include <QSpinBox>
#include <QWidget>
#include <QTableView>
#include "TablaModelT.h"
#include "Rangos.h"
#include "ExpAna.h"

class TFmeTest : public QWidget
{
    Q_OBJECT

public:

    QFrame *PanContenedor;
    QFrame *SplSeparador;
    QFrame *PanExclusion;
    QLabel *LabExclusionRegistros;
    QLabel *LabExclusionEdits;
    QLineEdit *EdtExclusionRegistros;
    QLineEdit *EdtExclusionEdits;
    QPushButton *ButAplicarExclusion;    
    MiTabla *view;    // vista de la tabla principal
    MiTabla *view2;   // vista de la tabla registro
    QFrame *SbrBarraEstado;
    QFrame *SbrBarraEstado1;
    QLabel *LabBarraEstado1;
    QFrame *SbrBarraEstado2;
    QLabel *LabBarraEstado2;
    QFrame *SbrBarraEditActual;
    QFrame *PanInfo;
    QLabel *LabIrARegistroPorNumero;
    QLabel *LabIrARegistroPorNombre;
    QLabel *LabIrAEdit;
    QLabel *LabEditActual;
    QLineEdit *EdtEdit;
    QLineEdit *EdtIrARegistroPorNumero;
    QComboBox *CbxIrARegistroPorNombre;
    QLineEdit *EdtIrAEdit;    
    MiBox *GbxHistograma;
    QFrame *PanSalvarPorcentajesError;
    QLabel *LabUmbralErrorEdits;
    QLabel *Label1;
    QLabel *LabUmbralErrorRegistros;
    QLabel *Label3;
    QPushButton *ButSalvarErrorEdits;
    QPushButton *ButSalvarErrorRegistros;
    QSpinBox *EdtUmbralErrorEdits;
    QSpinBox *EdtUmbralErrorRegistros;
    QLineEdit *PanProgreso;
    QLabel *LabOperacion;
    QLabel *LabProgreso;
    QLabel *LabPorcentaje;
    QLabel *LabElemento;
    QLineEdit *EdtOperacion;
    QProgressBar *PbrProgreso;
    QLineEdit *EdtPorcentaje;
    QLineEdit *EdtElemento; 
    QComboBox *VisualizarReg;
    QMenu * menu;

    TFmeTest(QWidget* parent, const char* name, Qt::WindowFlags fl, TFmeRangos *FmeRangosAsociados, TFrmIrAVariable *FrmIrAVariable, TFrmCambiarMicrodato *FrmCambiarMicrodato, TFrmOpciones *FrmOpciones, QTabWidget *Frmprincipal, QStringList *ListaIds);
    void ajustarSize();
    bool EvaluacionEditRegistro(unsigned IndiceRegistro, unsigned IndiceEdit);
    bool EstaCargado();
    bool EditCorrecto(unsigned IndiceEdit);
    bool EditExcluido(unsigned IndiceEdit);
    double GetPorcentajeErrorEdit(unsigned IndiceEdit);
    double GetPorcentajeErrorRegistro(unsigned IndiceRegistro);
    unsigned GetNumeroErrorEdit(unsigned IndiceEdit);
    unsigned GetNumeroErrorRegistro(unsigned IndiceRegistro);
    TFmeRangos *GetRangosAsociados();
    bool GetTestEdit(unsigned IndiceRegistro, unsigned IndiceEdit);
    unsigned GetUmbralExclusionRegistros();
    unsigned GetUmbralExclusionEdits();
    double GetTiempoProcesoSegundos();
    double GetTiempoProcesoMilisengudos();
    unsigned GetNumRegistrosCorrectos();
    unsigned GetNumRegistrosIncorrectos();
    unsigned GetNumRegistrosExcluidosAPriori();
    unsigned GetNumRegistrosExcluidos();
    unsigned GetNumEditsCorrectos();
    unsigned GetNumEditsIncorrectos();
    unsigned GetNumEditsExcluidosAPriori();
    unsigned GetNumEditsExcluidos();
    bool RegistroCorrecto(unsigned IndiceRegistro);
    bool RegistroExcluido(unsigned IndiceRegistro);
    bool VarModEdit(QSet<unsigned> VarEdit, QSet<unsigned> VarModificadas);
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Asociar las clases provenientes de etapas anteriores.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void AsociarClases(TFmeRangos *FmeRangosAsociados);
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Actualizar los porcentajes de exclusion.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void ActualizarUmbralExclusion();
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Actualizar la evaluacion y toda la interface despues de haber modificado un microdato concreto.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void ActualizarInterfaceMicrodatoCambiado(unsigned IndiceRegistro, unsigned IndiceVariable, double Valor);
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Aplicar los porcentajes de exclusion y recalcular los resultados.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void AplicarExclusion();
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Actualizar los datos de la evaluacion del registro.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    bool ActualizarEvaluacionRegistro(unsigned IndiceRegistro, bool MicrodatoModificado);
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Buscar la siguiente variable de la rejilla registro del edit seleccionado.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    unsigned BuscarVariableDerecha(unsigned ColumnaOrigen);
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Buscar la anterior variable de la rejilla registro del edit seleccionado.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    unsigned BuscarVariableIzquierda(unsigned ColumnaOrigen);
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Buscar el siguiente edit con error hacia la derecha.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    unsigned BuscarEditErrorDerecha(unsigned FilaOrigen, unsigned ColumnaOrigen);
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Buscar el  con error hacia la izquierda.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    unsigned BuscarEditErrorIzquierda(unsigned FilaOrigen, unsigned ColumnaOrigen);
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Buscar el siguiente microdato erroneo hacia arriba.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    unsigned BuscarMicroDatoErrorArriba(unsigned FilaOrigen, unsigned ColumnaOrigen);
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Buscar el siguiente microdato erroneo hacia abajo.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    unsigned BuscarMicroDatoErrorAbajo(unsigned FilaOrigen, unsigned ColumnaOrigen);
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Cargar el test del registro en la rejilla de visualizacion.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void CargarTestRegistroEnRejilla(unsigned IndiceRegistro);
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void CargarEnLista();
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Cargar el test en la rejilla de visualizacion.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void CargarTestEnRejilla();
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Cargar porcentajes en la rejilla y en las series de datos.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void CargarResultados();
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Cargar porcentajes en la rejilla y en las series de datos para el registro especificado.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void CargarResultadosRegistro(unsigned IndiceRegistro);

    QString SustCaracter(QString Cadena, char CarABuscar, char CarSustitucion);
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Cargar porcentajes en la rejilla y en las series de datos para el edit especificado.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void CargarResultadosEdit(unsigned IndiceEdit);
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Copiar el vector de totales originales en el vector de totales temporal.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void CrearCopiaVectoresTotales();
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Calcular numero de edits correctos.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    unsigned CalcularNumEditsCorrectos();
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Calcular numero de registros correctos.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    unsigned CalcularNumRegistrosCorrectos();
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Calcular numeros de resumen.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void CalcularNumResumen();
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Evaluar el registro que se pasa por parametros.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    bool EvaluarRegistro(unsigned IndiceRegistro, QSet<unsigned> VariablesModificadas, QMap<QString,double> *MapTest);
    bool EvaluarRegistro2(unsigned IndiceRegistro, QSet<unsigned> VariablesModificadas, QMap<QString,double> *MapTest);
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Excluir el registro por parametros.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void ExcluirRegistro(unsigned IndiceRegistro);
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Excluir el edit por parametros.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void ExcluirEdit(unsigned IndiceEdit);
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Excluir los registros que estan por encima del umbral especificado.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void ExcluirRegistros();
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Excluir las variables que estan por encima del umbral especificado.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void ExcluirEdits();
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Excluir los registros a priori.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void ExcluirRegistrosAPriori();
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Excluir los edits a priori.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void ExcluirEditsAPriori();
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Determina si el edit contiene alguna variable excluida.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    bool EditConVariableExcluida(unsigned IndiceEdit);
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Fijar la cantidad de datos que intervienen en el proceso.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void FijarCantidadDatos();
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Fijar el ancho de las columnas de la rejilla registro.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void FijarAnchoColumnasRejillaRegistro(unsigned ancho);
 //////////////////////////////////////////////////////////////7
    TablaModelT *GetTablaModel();
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    QComboBox *GetVisualizarReg();
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Inicializar la rejilla de visualizacion general.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void InicializarRejilla();
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Inicializar la rejilla de visualizacion de registros.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void InicializarRejillaRegistro();
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Inicializar la matriz de test.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void InicializarMatrizTest();
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Inicializar los vectores totales.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void InicializarVectoresTotales();
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Inicializar los vectores de exclusion.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void InicializarVectoresExclusion();
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Inicializar los cuadros de exclusion.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void InicializarCuadrosExclusion();
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Inicializar el sistema de progreso.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void InicSistemaProgreso();
    
    void InicSistemaProgreso2();
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Incrementar el sistema de progreso.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void IncSistemaProgreso();
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Mostrar la informacion asociada a la fila y a la columna.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void MostrarInfoAsociada(unsigned Fila, unsigned Columna, bool Fijar);
    void MostrarInfoAsociada(unsigned Fila, unsigned Columna, unsigned numreg, bool Fijar, QStringList listah, QString **matriz, QStringList listav);
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Resetear los vectores totales.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void ResetearVectoresTotales();
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Resetear los vectores de exclusion.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void InicializarListasExclusionAPriori();
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Resetear los vectores de exclusion.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void ResetearVectoresExclusion();
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Resetear las listas de exclusion.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void ResetearListasExclusion();
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Resetear las listas de exclusion a priori.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void ResetearListasExclusionAPriori();
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Salvar en un fichero los porcentajes de error de los edits.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void SalvarPorcentajesErrorEdits(QString NombreFichero, double PorcentajeUmbral);
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Salvar en un fichero los porcentajes de error de los registros.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void SalvarPorcentajesErrorRegistros(QString NombreFichero, double PorcentajeUmbral);
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Testear los MicroDatos con los Edits.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void TestearMicroDatos();
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Preparar la interface por si han habido cambios en el numero de edits.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void PrepararInterface();
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Pinta la rejilla principal.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void repintar(int i, int j);
    void repintar(int i, int j, QString texto);
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Pinta la rejilla registro.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void repintarRegistro(int col);
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Fijar el ancho de las columnas de la rejilla principal y rejilla registro.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void FijarAnchoColumnasRejilla(unsigned ancho);

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


public slots:

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// PULSAR EL BOTON DE APLICAR LA EXCLUSION.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void ButAplicarExclusionClick();
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// HACER DOBLE CLICK SOBRE EL EDIT DE EDITS.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void EdtEditClick();
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// PULSAR UNA TECLA EN EL EDIT DE IR A REGISTRO.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void EdtIrARegistroPorNumeroKeyDown();
    void CbxIrARegistroPorNombreCloseUp(int index);
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// PULSAR UNA TECLA EN EL EDIT DE IR A EDIT.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void EdtIrAEditKeyDown();
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// SELECCIONAR UNA CELDA DE LA REJILLA.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void SgrRejillaSelectCell(const QModelIndex& index);
    void SgrRejillaSelectCellV(const int& index);
    void SgrRejillaSelectCellH(const int& index);
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// COPIAR EL IDENTIFICADOR DEL REGISTRO ACTUAL.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void MitCopiarIdentificadorRegistroClick();
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// COPIAR EL IDENTIFICADOR DE LA VARIABLE ACTUAL.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void MitCopiarIdentificadorEditClick();
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// PULSAR UNA TECLA SOBRE LA REJILLA REGISTRO.
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void SgrRejillaRegKeyDownCR();
    void SgrRejillaRegKeyDownCL();
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// PULSAR UNA TECLA SOBRE LA REJILLA PRINCIPAL.
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void SgrRejillaKeyDownAR();
    void SgrRejillaKeyDownAL();
    void SgrRejillaKeyDownAU();
    void SgrRejillaKeyDownAD();
    void SgrRejillaKeyDownCZ();
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// HACER DOBLE CLICK SOBRE LA REJILLA DE REGISTRO.
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void SgrRejillaRegistroDblClick(const QModelIndex& index);
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// PULSAR EL BOTON DE SALVAR ERROR EDITS.
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void ButSalvarErrorEditsClick();
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// PULSAR EL BOTON DE SALVAR ERROR REGISTROS.
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void ButSalvarErrorRegistrosClick();
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// DOBLE CLICK SOBRE LA REJILLA DE EVALUACION.
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void SgrRejillaDblClick(const QModelIndex& index);
    void ButAplicarIrAVariableClick();

    void ButCancelarIrAVariableClick();
    void ButAceptarCambiarMicrodatoClick();

    void ButCancelarCambiarMicrodatoClick();

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// PINCHAR LA OPCION DE MENU DE AUMENTAR EL TAMAÑO DE LAS COLUMNAS.
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void MitAumentarColumnasClick();
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// PINCHAR LA OPCION DE MENU DE DISMINUIR EL TAMAÑO DE LAS COLUMNAS.
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void MitDisminuirColumnasClick();

    void VisualizarMenu(const QModelIndex& index);
    
    void ButClick_sig();
    void ButClick_ant();
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// MODO DE VISUALIZAR LA TABLA DE TEST.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void VisualizarRegCloseUp(int index);

private:

  TFmeRangos *FmeRangosAsociados;
  TFmeEdits *FmeEditsAsociados;
  TFmeMicroDatos *FmeMicroDatosAsociados;
  TFmeVariables *FmeVariablesAsociadas;
  TFrmCambiarMicrodato *FrmCambiarMicrodato;
  TFrmIrAVariable *FrmIrAVariable;
  TFrmOpciones *FrmOpciones;

  QString Name;
  unsigned NumRegistros;
  unsigned NumEdits;
  unsigned *VectorTotalesPorFilas;
  unsigned *VectorTotalesPorColumnas;
  unsigned *VectorTotalesPorFilasOriginal;
  unsigned *VectorTotalesPorColumnasOriginal;
  QStringList *ListaVariables;
  QStringList *ListaIds;
  bool **MatrizTest;
  QString **MatrizTestS;
  QStringList listaH;
  QStringList listaV;
  bool Cargado;
  bool *VectorExclusionRegistros;
  bool *VectorExclusionEdits;
  double PorcentajeExclusionRegistros;
  double PorcentajeExclusionEdits;
  QSet<unsigned> RegistrosExcluidos;
  QSet<unsigned> EditsExcluidos;
  QSet<unsigned> RegistrosExcluidosAPriori;
  QSet<unsigned> EditsExcluidosAPriori;
  QTime InstanteComienzo;
  QTime InstanteFinalizacion;
  unsigned NumRegistrosCorrectos;
  unsigned NumRegistrosIncorrectos;
  unsigned NumRegistrosExcluidosAPriori;
  unsigned NumRegistrosExcluidos;
  unsigned NumEditsCorrectos;
  unsigned NumEditsIncorrectos;
  unsigned NumEditsExcluidosAPriori;
  unsigned NumEditsExcluidos;
  unsigned UmbralExclusionRegistros, UmbralExclusionEdits;
  bool ModificacionMicrodato;
  double UltimoMicrodatoModificado;
  double UltimoIndiceRegistroModificado;
  double UltimoIndiceVariableModificado;
  bool rejillaregistro;
  QTextEdit *MemLogs;
  //bool activeSerieEdits;
  //bool activeSerieRegistros;
  TablaModelT *model;
  QString *VectorTestR;
  QStringList listaH2;
  QStringList listaV2;
  TablaModelInfoR *model2;
  QTabWidget *principal;
  QwtPlotHistogram *histogramed;
  QwtPlotHistogram *histogramreg;

};

#endif // TEST_H
