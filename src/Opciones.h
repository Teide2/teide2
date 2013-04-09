/*******************************************************************************
** Opciones.h: muestra la ventana con los diferentes tab para indicar las
**               diferentes opciones.
**
** author: M-S Hern�ndez-Garc�a
*******************************************************************************/

#ifndef OPCIONES_H
#define OPCIONES_H

#include <QtCore/QVariant>
#include <QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QFrame>
#include <QtGui/QGroupBox>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QSpinBox>
#include <QtGui/QTabWidget>
#include <QtGui/QWidget>
#include "MostrarMapping.h"


class TFrmOpciones : public QWidget
{
    Q_OBJECT

private:	// User declarations
    bool MissingValidos[4];
    int num_valores_missing;
    QStringList *cadenas_missing;    

public:

    QTabWidget *PgcOpciones;
    QWidget *TshMissing;
    QCheckBox *ChbMiss1Valido;
    QCheckBox *ChbMiss2Valido;
    QCheckBox *ChbMiss3Valido;
    QCheckBox *ChbMiss4Valido;
    QWidget *TshDistancia;
    QLabel *LabInfoDistancias;
    QLabel *LabPesoAlfa;
    QLabel *LabPesoBeta1;
    QLabel *LabMaxDistDonante;
    QLabel *LabPesoGamma;
    QLabel *LabPesoBeta2;
    QLineEdit *PanDivision1;
    QLabel *LabInfoDistancias2;
    QRadioButton *RbMetodo1;
    QRadioButton *RbMetodo2;
    QLineEdit *PanDivision2;
    QSpinBox *EdtPesoAlfa;
    QSpinBox *EdtPesoBeta1;
    QSpinBox *EdtPesoBeta2;
    QSpinBox *EdtPesoGamma;
    QPushButton *ButMinAlfa;
    QPushButton *ButMaxAlfa;
    QPushButton *ButMinBeta1;
    QPushButton *ButMaxBeta1;
    QPushButton *ButMinBeta2;
    QPushButton *ButMinGamma;
    QPushButton *ButMaxBeta2;
    QPushButton *ButMaxGamma;
    QLineEdit *EdtMaxDistDonante;
    QWidget *TshPesosVariables;
    QGroupBox *GbMetodoPesos;
    QRadioButton *RbMetodoPesosImpApar;
    QRadioButton *RbMetodoPesosAleatorio;
    QWidget *TshVarios;
    QCheckBox *ChbIgnorarEdits;
    QCheckBox *ChbIgnorarVariablesNoImputables;
    QWidget *TshInforme;
    QGroupBox *GbMetodoInforme;
    QRadioButton *RbMetodoInformeResumido;
    QRadioButton *RbMetodoInformeExtenso;
    QWidget *TshImputacion;
    QLabel *LabNumMaxRegDonantes;
    QLineEdit *EdtNumMaxRegDonantes;
    QLabel *LabUmbralEnumVariables;
    QLineEdit *EdtUmbralEnumVariables;
    //QWidget *TshCalculoDistancia;


    TFrmOpciones(QWidget* parent, const char* name, Qt::WindowFlags fl, int num_val_missing, QStringList *cad_missing);
    
    void InicValores();

    double GetPesoAlfa();

    double GetPesoBeta1();

    double GetPesoBeta2();

    double GetPesoGamma();

    bool *GetMissingValidos();

    bool GetMissingValido(unsigned i);

    TTipoMetodoPesosVariables GetMetodoPesosVariables();

    bool GetIgnorarEdits();

    bool GetIgnorarVariablesNoImputables();

    bool GetMetodoInformeResumido();

    double GetMaxDistDonante();

    int GetNumMaxRegDonantes();
    
    int GetUmbralEnumVariables();

    bool GetMetodo1();   // metodo sobre el calculo de las distancias
    
public slots:

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// PULSAR EL BOT�N DE MIN EN EL PESO ALFA.
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
   void ButMinAlfaClick();
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// PULSAR EL BOT�N DE MAX EN EL PESO ALFA.
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
   void ButMaxAlfaClick();
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// PULSAR EL BOT�N DE MIN EN EL PESO BETA.
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
   void ButMinBeta1Click();
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// PULSAR EL BOT�N DE MAX EN EL PESO BETA.
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
   void ButMaxBeta1Click();
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// PULSAR EL BOT�N DE MIN EN EL PESO BETA.
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void ButMinBeta2Click();
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// PULSAR EL BOT�N DE MAX EN EL PESO BETA.
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void ButMaxBeta2Click();
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// PULSAR EL BOT�N DE MIN EN EL PESO GAMMA.
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void ButMinGammaClick();
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// PULSAR EL BOT�N DE MAX EN EL PESO GAMMA.
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void ButMaxGammaClick();
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// PULSAR SOBRE EL CHECKBOX DE VALIDEZ DEL NO_PROCEDE.
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void ChbMiss1ValidoClick();
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// PULSAR SOBRE EL CHECKBOX DE VALIDEZ DEL NO_SABE.
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void ChbMiss2ValidoClick();
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// PULSAR SOBRE EL CHECKBOX DE VALIDEZ DEL NO_CONTESTA.
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void ChbMiss3ValidoClick();
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// PULSAR SOBRE EL CHECKBOX DE VALIDEZ DEL NS_NC.
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
   void ChbMiss4ValidoClick();
};

extern TFrmOpciones *FrmOpciones;

#endif // OPCIONES_H       
