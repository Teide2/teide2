/*******************************************************************************
** MicroDatos.cpp: contiene todo lo necesario para trabajar con la solapa
**                   Microdatos.
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

#ifndef MICRODATOS_H
#define MICRODATOS_H

#include <QVariant>
#include <QAction>
#include <QApplication>
#include <QButtonGroup>
#include <QComboBox>
#include <QFrame>
#include <QLabel>
#include <QLineEdit>
#include <QProgressBar>
#include <QWidget>
#include <QMenu>
#include <QTableView>
#include <QFileDialog>
#include <QMessageBox>
#include <QProgressDialog>
#include <QPainter>
#include <QMenuBar>
#include <QSortFilterProxyModel>
#include "Variables.h"
#include "TablaModelInfo.h"
#include "PedirExpresion.h"
#include <QVector>

#include <set>
 

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// STL - Standard C++ Template Library
#include <list>
using namespace std;
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class TipoMicroDato {
public:
  unsigned fila;
  unsigned columna;
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
struct LT_TipoMicroDato
{
  bool operator()(TipoMicroDato s1, TipoMicroDato s2) const
  {
     if ((s1.fila < s2.fila) || (s1.columna < s2.columna))
      return true;
     else
      return false;
  }
};

class TFmeMicroDatos : public QWidget
{
    Q_OBJECT

public:

    QSqlDatabase *AdqConsulta;    
    QFrame *PanContenedorM;    
    QFrame *PanIrA;
    QLabel *LabIrARegistro;
    QLabel *LabIrAVariablePorNombre;
    QLabel *LabMapping;
    QLabel *LabIrAVariablePorNumero;
    QLabel *LabBuscarID;
    QLineEdit *EdtIrARegistro;
    QComboBox *CbxIrAVariable;
    QLineEdit *EdtMapping;
    QLineEdit *EdtIrAVariablePorNumero;
    QComboBox *CbxBuscarID;    
    MiTabla *view;    
    MiTabla *view2;    
    QFrame *SbrBarraEstado;
    QFrame *SbrBarraEstado0;
    QLabel *LabBarraEstado0;
    QFrame *SbrBarraEstado1;
    QLabel *LabBarraEstado1;
    QMenuBar *PumUtilidades;
    QMenu * menu;
    QComboBox *VisualizarReg;

    TFmeMicroDatos(QWidget* parent, const char* name, Qt::WindowFlags fl, QSqlDatabase *AdcConexionBD, TFmeVariables *FmeVariablesAsociadas, QStringList *NombresTablas, unsigned NumRegistros, QStringList *ListaIds, QString Key, QString Cota, bool Contaminar, unsigned PorcentajeContaminacion, bool oracle, bool Xml, QString NombreBaseDatos, QTabWidget *PctContenedorPrincipal, bool excel, QString Nrac);
    
    void ajustarSize();//void updateGeometry ();

    void AsociarClases(TFmeVariables *FmeVariablesAsociadas);
    void CrearMatrizMicroDatos();

    void ChequearCompletitudRegistros();

    void CalcularEstadisticas();
    void ReestructurarTablaM();
    void CargarMicroDatos();
    int buscar_pos(QString var);

    void CrearMapRegistros();

    void ContaminarMicrodatos(double PorcentajeContaminacion);

    void EscribirInformacion();

    void FijarFormatoRejilla();

    int GetposID(QString id);

    QString GetlistaH2(int indice);

    QString GetlistaV2(int indice);

    QString GetVectorDatosS(int col);

    unsigned GetNumRegistros();

    unsigned GetNumVariables();

    unsigned GetNumMicrodatos();

    double **GetMatrizMicroDatos();

    QString **GetMatrizMicroDatosS();

    double *GetRegistro(unsigned IndiceRegistro);

    TFmeVariables *GetVariablesAsociadas();

    double GetValor(unsigned IndiceRegistro, unsigned IndiceVariable);

    TablaModel *GetTablaModel();

    QString GetValorS(unsigned IndiceRegistro, unsigned IndiceVariable);

    int numColumnMicroS();

    unsigned GetNumMissing(int TipoMissing);

    double GetPorcentajeMissing(int TipoMissing);

    QString GetNombreConjunto();

    QString GetNombreTabla();

    QStringList *GetNombresTablas();

    QString GetIdRegistro(unsigned IndiceRegistro);

    QStringList *GetListaRegistros();

    unsigned GetNumVariablesTabla(unsigned IndiceTabla);

    double GetValoresContaminados();

    QMap<QString,double> *GetMapRegistro(unsigned IndiceRegistro);

    QString GetKey();

    void InicializarRejillaVariable();

    void MostrarInfoAsociada(unsigned Fila, unsigned Columna, unsigned numreg, bool Fijar);

    void repintarVariable(bool filtro, bool falso);

    void ModificarMicrodato(unsigned IndiceRegistro, unsigned IndiceVariable, double Valor);

    void SalvarMicrodatosEnFichero(QString NombreFichero);

    QString GetCota();

    void SalvarMicrodatosEnBBDD(QString NombreTablaBaseSalida);
    bool encontrar(TipoMicroDato d);

    void FijarAnchoColumnasRejilla(unsigned ancho);

    QComboBox *GetVisualizarReg();

    void cargarmodelo2(QString exp);
    
public slots:

    void EdtIrARegistroKeyDown();

    void CbxIrAVariableCloseUp(int index);

    void SgrRejillaSelectCell(const QModelIndex& index);

    void SgrRejillaSelectCellV(const int& index);
    void SgrRejillaSelectCellH(const int& index);

    void EdtIrAVariablePorNumeroKeyDown();

    void CbxBuscarIDCloseUp(int index);

    void VisualizarMenu(const QModelIndex& index);

    void MitSalvarMicrodatosFicheroClick();

    void MitSalvarMicrodatosBBDDClick();
    void ButAceptarEntradaDatosClick();

    void ButCancelarEntradaDatosClick();

    void ButAceptarPedirExpresionClick();
    void ButCancelarPedirExpresionClick();

    void MitAumentarColumnasClick();

    void MitDisminuirColumnasClick();

    void VisualizarRegCloseUp(int index);

private:

    TFmeVariables *FmeVariablesAsociadas;
    QSqlQuery *query5;
    bool Oracle;
    bool Xml;
    QStringList *NombresTablas;
    QString NombreBaseDatos;
    QString Name;
    unsigned NumTablas;
    unsigned NumRegistros;
    unsigned NumRegistrosSelec;
    unsigned NumVariables;
    unsigned NumMicrodatos;
    double **MatrizMicroDatos;
    double PorcentajesMissing[4];
    unsigned NumMissing[4];
    QStringList *ListaIds;
    QStringList listaH;
    QStringList listaV;
    QStringList listaVSelec;
    QString NombreConjunto;
    vector<unsigned> NumVariablesTablas;
    QMap<QString,double> **MapRegistros;
    QString Key;
    QString Cota;
    unsigned ValoresContaminados;
    set<TipoMicroDato,LT_TipoMicroDato> MicroDatosModificados;    
    QTextEdit *MemLogs;
    QString **MatrizMicroDatosS;
    QString **MatrizMicroDatosSelec;
    TFrmEntradaDatos *FrmEntradaDatos;
    TFrmPedirExpresion *wpedexp;
    TablaModel *model;
    TablaModelInfo *model2;
    QStringList listaH2;
    QStringList listaV2;
    QString *VectorDatosS;
    bool Excel;
    QString Nrac;   //numero de registros a cargar
};


#endif // MICRODATOS_H
