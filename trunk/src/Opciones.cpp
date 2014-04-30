/*******************************************************************************
** Opciones.cpp: muestra la ventana con los diferentes tab para indicar las
**               diferentes opciones.
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

#include "Opciones.h"


TFrmOpciones::TFrmOpciones(QWidget* parent, const char* name, Qt::WindowFlags fl, int num_val_missing, QStringList *cad_missing):QWidget(parent, fl)
    {
      if (this->objectName().isEmpty())
        this->setObjectName(QString::fromUtf8("TFrmOpciones"));

      this->resize(500, 308);

      PgcOpciones = new QTabWidget(this);
      PgcOpciones->setObjectName(QString::fromUtf8("PgcOpciones"));
      PgcOpciones->setGeometry(QRect(0, 0, 500, 311));
      TshMissing = new QWidget();
      TshMissing->setObjectName(QString::fromUtf8("TshMissing"));
      ChbMiss1Valido = new QCheckBox(TshMissing);
      ChbMiss1Valido->setObjectName(QString::fromUtf8("ChbMiss1Valido"));
      ChbMiss1Valido->setGeometry(QRect(8, 30, 420, 17));
      ChbMiss2Valido = new QCheckBox(TshMissing);
      ChbMiss2Valido->setObjectName(QString::fromUtf8("ChbMiss2Valido"));
      ChbMiss2Valido->setGeometry(QRect(8, 80, 420, 17));
      ChbMiss3Valido = new QCheckBox(TshMissing);
      ChbMiss3Valido->setObjectName(QString::fromUtf8("ChbMiss3Valido"));
      ChbMiss3Valido->setGeometry(QRect(8, 130, 420, 17));
      ChbMiss4Valido = new QCheckBox(TshMissing);
      ChbMiss4Valido->setObjectName(QString::fromUtf8("ChbMiss4Valido"));
      ChbMiss4Valido->setGeometry(QRect(8, 180, 420, 17));
      PgcOpciones->addTab(TshMissing, QString());
      TshDistancia = new QWidget();
      TshDistancia->setObjectName(QString::fromUtf8("TshDistancia"));
      LabInfoDistancias = new QLabel(TshDistancia);
      LabInfoDistancias->setObjectName(QString::fromUtf8("LabInfoDistancias"));
      LabInfoDistancias->setGeometry(QRect(8, 5, 352, 18));
      LabPesoAlfa = new QLabel(TshDistancia);
      LabPesoAlfa->setObjectName(QString::fromUtf8("LabPesoAlfa"));
      LabPesoAlfa->setGeometry(QRect(8, 42, 200, 18));
      LabPesoBeta1 = new QLabel(TshDistancia);
      LabPesoBeta1->setObjectName(QString::fromUtf8("LabPesoBeta1"));
      LabPesoBeta1->setGeometry(QRect(8, 72, 200, 18));
      LabMaxDistDonante = new QLabel(TshDistancia);
      LabMaxDistDonante->setObjectName(QString::fromUtf8("LabMaxDistDonante"));
      LabMaxDistDonante->setGeometry(QRect(8, 159, 310, 18));
      LabPesoGamma = new QLabel(TshDistancia);
      LabPesoGamma->setObjectName(QString::fromUtf8("LabPesoGamma"));
      LabPesoGamma->setGeometry(QRect(8, 132, 200, 18));
      LabPesoBeta2 = new QLabel(TshDistancia);
      LabPesoBeta2->setObjectName(QString::fromUtf8("LabPesoBeta2"));
      LabPesoBeta2->setGeometry(QRect(8, 102, 200, 18));
      PanDivision1 = new QLineEdit(TshDistancia);
      PanDivision1->setObjectName(QString::fromUtf8("PanDivision1"));
      PanDivision1->setGeometry(QRect(8, 21, 355, 5));
      QPalette palette( QApplication::palette() );
      palette.setColor( QPalette::Active, QPalette::Base, Qt::black );
      PanDivision1->setPalette(palette);
      EdtPesoAlfa = new QSpinBox(TshDistancia);
      EdtPesoAlfa->setObjectName(QString::fromUtf8("EdtPesoAlfa"));
      EdtPesoAlfa->setGeometry(QRect(215, 35, 46, 23));
      EdtPesoBeta1 = new QSpinBox(TshDistancia);
      EdtPesoBeta1->setObjectName(QString::fromUtf8("EdtPesoBeta1"));
      EdtPesoBeta1->setGeometry(QRect(215, 65, 46, 23));
      EdtPesoBeta2 = new QSpinBox(TshDistancia);
      EdtPesoBeta2->setObjectName(QString::fromUtf8("EdtPesoBeta2"));
      EdtPesoBeta2->setGeometry(QRect(215, 95, 46, 23));
      EdtPesoGamma = new QSpinBox(TshDistancia);
      EdtPesoGamma->setObjectName(QString::fromUtf8("EdtPesoGamma"));
      EdtPesoGamma->setGeometry(QRect(215, 125, 46, 23));
      ButMinAlfa = new QPushButton(TshDistancia);
      ButMinAlfa->setObjectName(QString::fromUtf8("ButMinAlfa"));
      ButMinAlfa->setGeometry(QRect(275, 35, 40, 23));
      ButMaxAlfa = new QPushButton(TshDistancia);
      ButMaxAlfa->setObjectName(QString::fromUtf8("ButMaxAlfa"));
      ButMaxAlfa->setGeometry(QRect(335, 35, 40, 23));
      ButMinBeta1 = new QPushButton(TshDistancia);
      ButMinBeta1->setObjectName(QString::fromUtf8("ButMinBeta1"));
      ButMinBeta1->setGeometry(QRect(275, 65, 40, 23));
      ButMaxBeta1 = new QPushButton(TshDistancia);
      ButMaxBeta1->setObjectName(QString::fromUtf8("ButMaxBeta1"));
      ButMaxBeta1->setGeometry(QRect(335, 65, 40, 23));
      ButMinBeta2 = new QPushButton(TshDistancia);
      ButMinBeta2->setObjectName(QString::fromUtf8("ButMinBeta2"));
      ButMinBeta2->setGeometry(QRect(275, 95, 40, 23));
      ButMinGamma = new QPushButton(TshDistancia);
      ButMinGamma->setObjectName(QString::fromUtf8("ButMinGamma"));
      ButMinGamma->setGeometry(QRect(275, 125, 40, 23));
      ButMaxBeta2 = new QPushButton(TshDistancia);
      ButMaxBeta2->setObjectName(QString::fromUtf8("ButMaxBeta2"));
      ButMaxBeta2->setGeometry(QRect(335, 95, 40, 23));
      ButMaxGamma = new QPushButton(TshDistancia);
      ButMaxGamma->setObjectName(QString::fromUtf8("ButMaxGamma"));
      ButMaxGamma->setGeometry(QRect(335, 125, 40, 23));
      EdtMaxDistDonante = new QLineEdit(TshDistancia);
      EdtMaxDistDonante->setObjectName(QString::fromUtf8("EdtMaxDistDonante"));
      EdtMaxDistDonante->setGeometry(QRect(320, 155, 81, 23));

      LabInfoDistancias2 = new QLabel(TshDistancia);
      LabInfoDistancias2->setObjectName(QString::fromUtf8("LabInfoDistancias2"));
      LabInfoDistancias2->setGeometry(QRect(8, 197, 302, 18));
      PanDivision2 = new QLineEdit(TshDistancia);
      PanDivision2->setObjectName(QString::fromUtf8("PanDivision2"));
      PanDivision2->setGeometry(QRect(8, 215, 311, 5));
      PanDivision2->setPalette(palette);
      RbMetodo1 = new QRadioButton(TshDistancia);
      RbMetodo1->setObjectName(QString::fromUtf8("ChbMetodo1"));
      RbMetodo1->setGeometry(QRect(10, 232, 371, 17));
      RbMetodo2 = new QRadioButton(TshDistancia);
      RbMetodo2->setObjectName(QString::fromUtf8("ChbMetodo2"));
      RbMetodo2->setGeometry(QRect(10, 252, 371, 17));
      PgcOpciones->addTab(TshDistancia, QString());
      TshPesosVariables = new QWidget();
      TshPesosVariables->setObjectName(QString::fromUtf8("TshPesosVariables"));
      GbMetodoPesos = new QGroupBox(TshPesosVariables);
      GbMetodoPesos->setObjectName(QString::fromUtf8("GbMetodoPesos"));
      GbMetodoPesos->setGeometry(QRect(10, 29, 371, 161));
      RbMetodoPesosImpApar = new QRadioButton(GbMetodoPesos);
      RbMetodoPesosImpApar->setObjectName(QString::fromUtf8("RbMetodoPesosImpApar"));
      RbMetodoPesosImpApar->setGeometry(QRect(10, 40, 295, 21));
      RbMetodoPesosAleatorio = new QRadioButton(GbMetodoPesos);
      RbMetodoPesosAleatorio->setObjectName(QString::fromUtf8("RbMetodoPesosAleatorio"));
      RbMetodoPesosAleatorio->setGeometry(QRect(10, 100, 95, 21));
      PgcOpciones->addTab(TshPesosVariables, QString());
      TshVarios = new QWidget();
      TshVarios->setObjectName(QString::fromUtf8("TshVarios"));
      ChbIgnorarEdits = new QCheckBox(TshVarios);
      ChbIgnorarEdits->setObjectName(QString::fromUtf8("ChbIgnorarEdits"));
      ChbIgnorarEdits->setGeometry(QRect(10, 50, 210, 21));
      ChbIgnorarVariablesNoImputables = new QCheckBox(TshVarios);
      ChbIgnorarVariablesNoImputables->setObjectName(QString::fromUtf8("ChbIgnorarVariablesNoImputables"));
      ChbIgnorarVariablesNoImputables->setGeometry(QRect(10, 130, 231, 21));
      PgcOpciones->addTab(TshVarios, QString());
      TshInforme = new QWidget();
      TshInforme->setObjectName(QString::fromUtf8("TshInforme"));
      GbMetodoInforme = new QGroupBox(TshInforme);
      GbMetodoInforme->setObjectName(QString::fromUtf8("GbMetodoInforme"));
      GbMetodoInforme->setGeometry(QRect(10, 29, 371, 161));
      RbMetodoInformeResumido = new QRadioButton(GbMetodoInforme);
      RbMetodoInformeResumido->setObjectName(QString::fromUtf8("RbMetodoInformeResumido"));
      RbMetodoInformeResumido->setGeometry(QRect(10, 40, 271, 21));
      RbMetodoInformeExtenso = new QRadioButton(GbMetodoInforme);
      RbMetodoInformeExtenso->setObjectName(QString::fromUtf8("RbMetodoInformeExtenso"));
      RbMetodoInformeExtenso->setGeometry(QRect(10, 100, 95, 21));
      PgcOpciones->addTab(TshInforme, QString());
      TshImputacion = new QWidget();
      TshImputacion->setObjectName(QString::fromUtf8("TshImputacion"));
      LabNumMaxRegDonantes = new QLabel(TshImputacion);
      LabNumMaxRegDonantes->setObjectName(QString::fromUtf8("NumMaxRegDonantes"));
      LabNumMaxRegDonantes->setGeometry(QRect(20, 45, 292, 41));
      EdtNumMaxRegDonantes = new QLineEdit(TshImputacion);
      EdtNumMaxRegDonantes->setObjectName(("EdtNumMaxRegDonantes"));
      EdtNumMaxRegDonantes->setGeometry(QRect(300, 50, 90, 21));
      LabUmbralEnumVariables = new QLabel(TshImputacion);
      LabUmbralEnumVariables->setObjectName(QString::fromUtf8("LabUmbralEnumVariables"));
      LabUmbralEnumVariables->setGeometry(QRect(20, 110, 292, 61));
      EdtUmbralEnumVariables = new QLineEdit(TshImputacion);
      EdtUmbralEnumVariables->setObjectName(("EdtUmbralEnumVariables"));
      EdtUmbralEnumVariables->setGeometry(QRect(300, 130, 90, 21));
      PgcOpciones->addTab(TshImputacion, QString());

      num_valores_missing = num_val_missing;
      cadenas_missing = cad_missing;

      this->setWindowTitle(QApplication::translate("TFrmOpciones", "Opciones", 0));
      PgcOpciones->setTabText(PgcOpciones->indexOf(TshMissing), QApplication::translate("TFrmOpciones", "&Missing", 0));
      LabInfoDistancias2->setText(QApplication::translate("TFrmOpciones", "Especifique la forma de calcular las distancias", 0));
      LabInfoDistancias->setText(QApplication::translate("TFrmOpciones", "Especifique los valores de los pesos de las distancias", 0));
      LabPesoAlfa->setText(QApplication::translate("TFrmOpciones", "Peso de la distancia alfa ...", 0));
      LabPesoBeta1->setText(QApplication::translate("TFrmOpciones", "Peso de la distancia beta1 ...", 0));
      LabMaxDistDonante->setText(QApplication::translate("TFrmOpciones", "M\303\241xima distancia permitida al registro donante", 0));
      LabPesoGamma->setText(QApplication::translate("TFrmOpciones", "Peso de la distancia gamma ...", 0));
      LabPesoBeta2->setText(QApplication::translate("TFrmOpciones", "Peso de la distancia beta2 ...", 0));
      ButMinAlfa->setText(QApplication::translate("TFrmOpciones", "Min", 0));
      ButMaxAlfa->setText(QApplication::translate("TFrmOpciones", "Max", 0));
      ButMinBeta1->setText(QApplication::translate("TFrmOpciones", "Min", 0));
      ButMaxBeta1->setText(QApplication::translate("TFrmOpciones", "Max", 0));
      ButMinBeta2->setText(QApplication::translate("TFrmOpciones", "Min", 0));
      ButMinGamma->setText(QApplication::translate("TFrmOpciones", "Min", 0));
      ButMaxBeta2->setText(QApplication::translate("TFrmOpciones", "Max", 0));
      ButMaxGamma->setText(QApplication::translate("TFrmOpciones", "Max", 0));
      PgcOpciones->setTabText(PgcOpciones->indexOf(TshDistancia), QApplication::translate("TFrmOpciones", "&Distancias", 0));
      GbMetodoPesos->setTitle(QApplication::translate("TFrmOpciones", "M\303\251todos de asignaci\303\263n de pesos a variables", 0));
      RbMetodoPesosImpApar->setText(QApplication::translate("TFrmOpciones", "Peso de imputaci\303\263n + Aparici\303\263n en reglas", 0));
      RbMetodoPesosAleatorio->setText(QApplication::translate("TFrmOpciones", "Aleatorio", 0));
      PgcOpciones->setTabText(PgcOpciones->indexOf(TshPesosVariables), QApplication::translate("TFrmOpciones", "&Pesos", 0));
      ChbIgnorarEdits->setText(QApplication::translate("TFrmOpciones", "Ignorar las reglas expl\303\255citas", 0));
      ChbIgnorarVariablesNoImputables->setText(QApplication::translate("TFrmOpciones", "Ignorar variables no imputables", 0));
      PgcOpciones->setTabText(PgcOpciones->indexOf(TshVarios), QApplication::translate("TFrmOpciones", "&Varios", 0));
      GbMetodoInforme->setTitle(QApplication::translate("TFrmOpciones", "Informe de estad\303\255stica", 0));
      RbMetodoInformeResumido->setText(QApplication::translate("TFrmOpciones", "Resumido", 0));
      RbMetodoInformeExtenso->setText(QApplication::translate("TFrmOpciones", "Extenso", 0));
      PgcOpciones->setTabText(PgcOpciones->indexOf(TshInforme), QApplication::translate("TFrmOpciones", "&Informe", 0));
      LabNumMaxRegDonantes->setText(QApplication::translate("TFrmOpciones", "N\303\272mero m\303\241ximo de registros donantes \na considerar", 0));
      EdtNumMaxRegDonantes->setText(QApplication::translate("TFrmOpciones", "500", 0));
      LabUmbralEnumVariables->setText(QApplication::translate("TFrmOpciones", "N\303\272mero m\303\241ximo de variables a considerar \npara realizar las combinaciones en la \nimputaci\303\263n de variables de reglas", 0));
      EdtUmbralEnumVariables->setText(QApplication::translate("TFrmOpciones", "10", 0));
      PgcOpciones->setTabText(PgcOpciones->indexOf(TshImputacion), QApplication::translate("TFrmOpciones", "&CtesImputaci\303\263n", 0));
      RbMetodo1->setText(QApplication::translate("TFrmOpciones", "Calcular distancias mediante sumas", 0));
      RbMetodo2->setText(QApplication::translate("TFrmOpciones", "Calcular distancias mediante productos", 0));

      QObject::connect(ChbMiss1Valido, SIGNAL(clicked()), this, SLOT(ChbMiss1ValidoClick()));
      QObject::connect(ChbMiss2Valido, SIGNAL(clicked()), this, SLOT(ChbMiss2ValidoClick()));
      QObject::connect(ChbMiss3Valido, SIGNAL(clicked()), this, SLOT(ChbMiss3ValidoClick()));
      QObject::connect(ChbMiss4Valido, SIGNAL(clicked()), this, SLOT(ChbMiss4ValidoClick()));
      QObject::connect(ButMinAlfa, SIGNAL(clicked()), this, SLOT(ButMinAlfaClick()));
      QObject::connect(ButMaxAlfa, SIGNAL(clicked()), this, SLOT(ButMaxAlfaClick()));
      QObject::connect(ButMinBeta1, SIGNAL(clicked()), this, SLOT(ButMinBeta1Click()));
      QObject::connect(ButMaxBeta1, SIGNAL(clicked()), this, SLOT(ButMaxBeta1Click()));
      QObject::connect(ButMinBeta2, SIGNAL(clicked()), this, SLOT(ButMinBeta2Click()));
      QObject::connect(ButMaxBeta2, SIGNAL(clicked()), this, SLOT(ButMaxBeta2Click()));
      QObject::connect(ButMinGamma, SIGNAL(clicked()), this, SLOT(ButMinGammaClick()));
      QObject::connect(ButMaxGamma, SIGNAL(clicked()), this, SLOT(ButMaxGammaClick()));      

      PgcOpciones->setCurrentIndex(0);

      QMetaObject::connectSlotsByName(this);
      
      EdtPesoAlfa->setMaximum(MAX_PESOS_DISTANCIAS);
      EdtPesoBeta1->setMaximum(MAX_PESOS_DISTANCIAS);
      EdtPesoBeta2->setMaximum(MAX_PESOS_DISTANCIAS);
      EdtPesoGamma->setMaximum(MAX_PESOS_DISTANCIAS);
    }
    
    void TFrmOpciones::InicValores()
    {
      unsigned i;
      QString cadena;
      // Validación de valores missing
      for (i = 0; i < num_valores_missing; i++) {
        MissingValidos[i] = false;
        cadena = tr("Considerar siempre los valores ") + cadenas_missing->at(i) + tr(" como validos");
        if (i == 0)ChbMiss1Valido->setText(tr(cadena.toLatin1().data()));
        else if (i == 1) ChbMiss2Valido->setText(tr(cadena.toLatin1().data()));
             else if (i == 2) ChbMiss3Valido->setText(tr(cadena.toLatin1().data()));
                  else ChbMiss4Valido->setText(tr(cadena.toLatin1().data()));
      }

      ChbMiss1Valido->setChecked(false);
      ChbMiss2Valido->setChecked(false);
      ChbMiss3Valido->setChecked(false);
      ChbMiss4Valido->setChecked(false);

      if (num_valores_missing == 1) {
          ChbMiss2Valido->hide();
          ChbMiss3Valido->hide();
          ChbMiss4Valido->hide();
          disconnect(ChbMiss2Valido, SIGNAL(clicked()));
          disconnect(ChbMiss3Valido, SIGNAL(clicked()));
          disconnect(ChbMiss4Valido, SIGNAL(clicked()));
      }else
          if (num_valores_missing == 2) {
            ChbMiss3Valido->hide();
            ChbMiss4Valido->hide();
            disconnect(ChbMiss3Valido, SIGNAL(clicked()));
            disconnect(ChbMiss4Valido, SIGNAL(clicked()));
          }else
              if (num_valores_missing == 3) {
                ChbMiss4Valido->hide();
                disconnect(ChbMiss4Valido, SIGNAL(clicked()));
              }

      // Distancias      
      EdtPesoAlfa->setValue(PESO_ALFA);
      EdtPesoBeta1->setValue(PESO_BETA1);
      EdtPesoBeta2->setValue(PESO_BETA2);
      EdtPesoGamma->setValue(PESO_GAMMA);
      EdtMaxDistDonante->setText("INF");
      RbMetodo1->setChecked(true);

      // Pesos      
      RbMetodoPesosImpApar->setChecked(true);

      // Varios
      ChbIgnorarEdits->setChecked(false);
      ChbIgnorarVariablesNoImputables->setChecked(false);
      
      // Informe
      RbMetodoInformeResumido->setChecked(true);
    }

    double TFrmOpciones::GetPesoAlfa()
    {
      return ((double)EdtPesoAlfa->value() / (double)EdtPesoAlfa->maximum());
    }

    double TFrmOpciones::GetPesoBeta1()
    {
      return ((double)EdtPesoBeta1->value() / (double)EdtPesoBeta1->maximum());
    }

    double TFrmOpciones::GetPesoBeta2()
    {
      return ((double)EdtPesoBeta2->value() / (double)EdtPesoBeta2->maximum());
    }

    double TFrmOpciones::GetPesoGamma()
    {
      return ((double)EdtPesoGamma->value() / (double)EdtPesoGamma->maximum());
    }

    bool *TFrmOpciones::GetMissingValidos()
    {
      return MissingValidos;
    }

    bool TFrmOpciones::GetMissingValido(unsigned i)
    {
      return MissingValidos[i];
    }

    TTipoMetodoPesosVariables TFrmOpciones::GetMetodoPesosVariables()
    {
      if (RbMetodoPesosImpApar->isChecked())
        return (TTipoMetodoPesosVariables)0;
      else
        return (TTipoMetodoPesosVariables)1;      
    }

    bool TFrmOpciones::GetIgnorarEdits()
    {
      return ChbIgnorarEdits->isChecked();
    }

    bool TFrmOpciones::GetIgnorarVariablesNoImputables()
    {
      return ChbIgnorarVariablesNoImputables->isChecked();
    }

    bool TFrmOpciones::GetMetodoInformeResumido()
    {
      if (RbMetodoInformeResumido->isChecked())
        return true;
      else
        return false;
    }

    
    double TFrmOpciones::GetMaxDistDonante()
    {
        double x;

        if (EdtMaxDistDonante->text() == "INF")
        {
            x =  999.9; //MaxDouble;
        }
        else
            try
        {
            x = EdtMaxDistDonante->text().toDouble();
        }
        catch(...)
        {
            x = 999.9; //MaxDouble;
        }
        return x;
    }
    int TFrmOpciones::GetNumMaxRegDonantes()
    {
      return EdtNumMaxRegDonantes->text().toInt();
    }
    int TFrmOpciones::GetUmbralEnumVariables()
    {
      return EdtUmbralEnumVariables->text().toInt();
    }


    bool TFrmOpciones::GetMetodo1()   //metodo para el calculo de las distancias
    {
      if (RbMetodo1->isChecked())
        return true;
      else
        return false;
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// PULSAR EL BOTÓN DE MIN EN EL PESO ALFA.
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
   void TFrmOpciones::ButMinAlfaClick()
   {
     EdtPesoAlfa->setValue(EdtPesoAlfa->minimum());   // donde le asigno el valor minimo
   }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// PULSAR EL BOTÓN DE MAX EN EL PESO ALFA.
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
   void TFrmOpciones::ButMaxAlfaClick()
   {
     EdtPesoAlfa->setValue(EdtPesoAlfa->maximum());
   }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// PULSAR EL BOTÓN DE MIN EN EL PESO BETA.
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
   void TFrmOpciones::ButMinBeta1Click()
   {
     EdtPesoBeta1->setValue(EdtPesoBeta1->minimum());
   }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// PULSAR EL BOTÓN DE MAX EN EL PESO BETA.
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
   void TFrmOpciones::ButMaxBeta1Click()
   {
     EdtPesoBeta1->setValue(EdtPesoBeta1->maximum());
   }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// PULSAR EL BOTÓN DE MIN EN EL PESO BETA.
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void TFrmOpciones::ButMinBeta2Click()
    {
      EdtPesoBeta2->setValue(EdtPesoBeta2->minimum());
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// PULSAR EL BOTÓN DE MAX EN EL PESO BETA.
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void TFrmOpciones::ButMaxBeta2Click()
    {
      EdtPesoBeta2->setValue(EdtPesoBeta2->maximum());
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// PULSAR EL BOTÓN DE MIN EN EL PESO GAMMA.
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void TFrmOpciones::ButMinGammaClick()
    {
      EdtPesoGamma->setValue(EdtPesoGamma->minimum());
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// PULSAR EL BOTÓN DE MAX EN EL PESO GAMMA.
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void TFrmOpciones::ButMaxGammaClick()
    {
      EdtPesoGamma->setValue(EdtPesoGamma->maximum());
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// PULSAR SOBRE EL CHECKBOX DE VALIDEZ DEL NO_PROCEDE.
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void TFrmOpciones::ChbMiss1ValidoClick()
    {
      if (ChbMiss1Valido->isChecked())
        MissingValidos[0] = true;
      else
        MissingValidos[0] = false;
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// PULSAR SOBRE EL CHECKBOX DE VALIDEZ DEL 2 MISSING.
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void TFrmOpciones::ChbMiss2ValidoClick()
    {
      if (ChbMiss2Valido->isChecked())
        MissingValidos[1] = true;
      else
        MissingValidos[1] = false;
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// PULSAR SOBRE EL CHECKBOX DE VALIDEZ DEL 3 MISSING.
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void TFrmOpciones::ChbMiss3ValidoClick()
    {
      if (ChbMiss3Valido->isChecked())
        MissingValidos[2] = true;
      else
        MissingValidos[2] = false;
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// PULSAR SOBRE EL CHECKBOX DE VALIDEZ DEL 4 MISSING.
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
   void TFrmOpciones::ChbMiss4ValidoClick()
   {
     if (ChbMiss4Valido->isChecked())
       MissingValidos[3] = true;
     else
       MissingValidos[3] = false;
   }
