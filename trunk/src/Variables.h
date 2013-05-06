/*******************************************************************************
** Variables.h: contiene todo lo necesario para trabajar con la solapa
**                variables.
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

#ifndef VARIABLES_H
#define VARIABLES_H

#include <QVariant>
#include <QAction>
#include <QApplication>
#include <QButtonGroup>
#include <QComboBox>
#include <QFrame>
#include <QLabel>
#include <QLineEdit>
#include <QWidget>
#include <QtSql>
#include <QTextEdit>  
#include <qdom.h>
#include <QMap>
#include <QMenu>
#include <QPushButton>
#include "TablaModelV.h"
#include "Opciones.h"
#include "ExpAna.h"
#include "RanAna.h"
#include "RegAna.h"
#include "VariablesDeEdits.h" 
#include "AvisoFiltro.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <math.h>

using namespace std;
#include <map>
typedef
  struct
  {
    QList<double> ValoresRango;
    QSet<unsigned> FiltrosEnQueAparece;
    bool AdmisionMissing[4];
    bool Imputable;
    bool MappingValido;
    bool FiltroWarning;
    TTipoVariable TipoVariable;
    double Peso;
    QSet<unsigned> VariablesDeFiltro;
    unsigned Id;
    QMap<int,double> MapCoef;
    TTipoImputacionVariable TipoImputacion;
    unsigned NumDonantes;
    unsigned ValRec;
  } InfoVariables;


class TFmeVariables : public QWidget
{
    Q_OBJECT

public:
QStringList m;
    MiTabla *view;    
    QFrame *SbrBarraEstado;
    QFrame *SbrBarraEstado0;
    QLabel *LabBarraEstado0;
    QFrame *SbrBarraEstado1;
    QLabel *LabBarraEstado1;
    QFrame *SbrBarraEstado2;
    QLabel *LabBarraEstado2;
    QFrame *PanContenedorVar;
    QFrame *PanIrA;
    QLabel *LabIrAVariablePorNombre;
    QLabel *LabIrAtributo;
    QLabel *LabIrAVariablePorNumero;
    QComboBox *CbxIrAVariablePorNombre;
    QComboBox *CbxIrAAtributo;
    QLineEdit *EdtIrAVariablePorNumero;
    QSqlDatabase *AdqConsulta;
    QMenu * menu;
    QComboBox *VisualizarVar;

    TFmeVariables(QWidget* parent, const char* name, Qt::WindowFlags fl, QSqlDatabase *AdcConexionBD, QString NombreTabla, QString NombreTablaMissing, QStringList *ListaVariables, QString NombreConjunto, QTextEdit *MemLogs, bool *correcto, bool Xml, QString NombreBaseDatos, QTabWidget *PctContenedorPrincipal, int Num_valores_missing, QStringList *Cadenas_Missing, bool excel, QAction *Accion);

    void ajustarSize();//void updateGeometry ();

    void AsociarMissingValidos(TFrmOpciones *FrmOpciones);

    bool AsociarValoresMissing(QString NombreTablaMissing);
    
    int getVectorValoresMissing(int i);

    void CargarVariablesEnLista();

    void CargarAtributosEnLista();

    void CargarVariablesEnRejilla(QString Campos);

    void ChequearCompletitudAtributos();

    void CargarMatrizAdmisionMissing();

    void CalcularEstadisticas();

    void CargarVectorPesosImputacion();

    void CargarVectorVariableImputable();

    void CrearVectorPertenenciaFiltros();

    void ConsultarTablaMapping(QString NombreTablaMapping);

    void ConsultarTablaMissing();

    void CrearCodigosLiteralesMissing();

    void ChequearTablasMapping();

    void CargarVectorTipoImputacion();

    void CargarVectorFiltrosWarning();
    void EscribirInformacion();

    bool ExisteVariable(QString Variable);

    QString getlistaH(int indice);
    QString getlistaV(int indice);

    QString getMatrizVariablesS(int fila, int col);

    bool EsValorMissing(double Valor);
    bool EsVariableImputable(unsigned IndiceVariable);

    bool EsVariableIgnorable(QString Variable);

    bool EsFiltroWarning(unsigned IndiceVariable);

    bool EsValorMissingAdmisible(unsigned IndiceVariable, TTipoMissing TipoMissing);
    bool EsValorMissingAdmisible(unsigned IndiceVariable, QString TipoMissing);
    bool EsValorMissingAdmisible(unsigned IndiceVariable, QStringList TipoMissing);

    TTipoImputacionVariable GetTipoImputacion(unsigned IndiceVariable);

    void FijarAnchoColumnasRejilla();

    void FijarTitulosColumnasRejilla();

    void FijarIdsFilasRejilla();

    bool FiltrosValidados();

    void FijarCantidadDatos();

    QString GetNombreTabla();

    QStringList *GetListaVariables();
    QStringList GetListaVariablesT();

    QStringList *GetCadenas_Missing();

    int GetNum_valores_missing();

    QStringList *GetListaVariablesIgnorables();

    int GetIndiceVariable(QString Variable);

    QString GetNombreVariable(unsigned IndiceVariable);

    unsigned GetNumVariables();
    unsigned GetNumVariablesT();

    unsigned GetNumAtributos();

    TTipoVariable GetTipoVariable(QString Variable);

    TTipoVariable GetTipoVariable(unsigned IndiceVariable);

    QString GetValorAtributo(unsigned IndiceVariable, TTipoAtributo IndiceAtributo);
    QString GetValorAtributo(unsigned IndiceVariable, TTipoAtributo IndiceAtributo, int mis);

    QList<double> GetValoresRangos(unsigned IndiceVariable);

    QMap<int,double> GetMapCoef(unsigned IndiceVariable);

    int GetValorMissing(QString CadenaMissing);
    int GetValorMissing(QStringList CadenaMissing);

    QMap <QString, double> GetMapMissing();
    
    int GetValorMissing(TTipoMissing TipoMissing);

    QString GetCadenaMissing(int ValorMissing);
    QString GetCadenaMissing(double ValorMissing);

    int GetIndiceAtributo(QString Atributo);

    double GetPorcentajeFiltros();

    double GetPorcentajeVariablesImputables();

    double GetPorcentajeTiposVariable(int TipoVariable);

    double GetPorcentajeAdmisionMissing(int TipoMissing);

    unsigned GetNumFiltros();

    unsigned GetNumVariablesImputables();

    unsigned GetNumTiposVariable(int TipoVariable);

    unsigned GetNumAdmisionMissing(int TipoMissing);

    unsigned GetIdVariable(unsigned IndiceVariable);

    QTextEdit *GetMemLogs();

    QComboBox *GetVisualizarVar();

    void GenerarListasRangos();

    void GenerarVariablesFiltros();

    QString GetCadenaTipoVariable(TTipoVariable TipoVariable);

    QSet<unsigned> GetConjuntoDesdeLista(QStringList *Lista);

    QSet<unsigned> GetVariablesFiltros(unsigned IndiceFiltro);

    double GetPesoImputacion(unsigned IndiceVariable);

    QString GetNombreConjunto();

    QSet<unsigned> GetVariablesNoImputables();

    QString GetCadenaEditRango(unsigned IndiceVariable);

    QString GetCadenaEditFiltro(unsigned IndiceVariable);

    unsigned GetNumFiltrosVariable(unsigned IndiceVariable);

    QSet<unsigned> GetFiltrosConVariable(unsigned IndiceVariable);

    double GetFrontRango(unsigned IndiceVariable);

    double GetBackRango(unsigned IndiceVariable);

    double GetValorAleatorioRango(unsigned IndiceVariable);

    unsigned GetNumDonantes(unsigned IndiceVariable);

    unsigned GetValRec(unsigned IndiceVariable);

    void InicializarVectorTiposVariables();

    void InicializarVectorInfoVariables();

    void MostrarInfoAsociada(unsigned Fila, unsigned Columna, unsigned numvar, bool Fijar);

    QString RealizarConsultaVariables();

    bool ValorEnRango(double Valor, unsigned IndiceVariable);

    bool VariableEnFiltro(unsigned IndiceVariable, unsigned IndiceFiltro);

    bool ValidarFiltros();    

public slots:

    void VisualizarMenu(const QModelIndex& index);

    void VisualizarVarCloseUp(int index);    

    void CbxIrAVariablePorNombreCloseUp(int index);

    void SgrRejillaSelectCell(const QModelIndex& index); 
    
    void SgrRejillaSelectCellV(const int& index);
    void SgrRejillaSelectCellH(const int& index);

    void CbxIrAAtributoCloseUp(int index);

    void SgrRejillaDblClick(const QModelIndex& index);

    void EdtIrAVariablePorNumeroKeyDown();

 
private:

  QString NombreTabla;
  QString NombreBaseDatos;
  bool Xml;
  QString Name;
  QString NombreConjunto;
  QStringList *ListaVariables;  
  QStringList *ListaVariablesIgnorables;
  unsigned NumFiltrosValidados;
  unsigned NumVariables;
  unsigned NumVariablesT;
  unsigned NumAtributos;
  int VectorValoresMissing[4];

  double PorcentajesAdmisionMissing[4];
  double PorcentajeFiltros;
  double PorcentajeVariablesImputables;
  double PorcentajesTiposVariable[NUM_TIPOS_VARIABLE];

  unsigned NumAdmisionMissing[4];
  unsigned NumFiltros;
  unsigned NumVariablesImputables;
  unsigned NumTiposVariable[NUM_TIPOS_VARIABLE];

  QSet<unsigned> VariablesNoImputables;
  QStringList *CodigosMissing;
  QStringList *LiteralesMissing;
  bool MissingValidos[4];
  QStringList *Cadenas_Missing;
  int Num_valores_missing;
  InfoVariables *VectorInfoVariables;
  QTextEdit *MemLogs;  

  TFrmMostrarMapping * FrmMostrarMapping;
  QStringList listaH;
  QStringList listaV;
  QStringList listaVT;
  QString **MatrizVariablesS;
  TablaModelV *model;
  QString **MatrizVariablesT;
  TablaModelV *modelT;
  bool Excel;
  QAction *accion;
};

#endif // VARIABLES_H
