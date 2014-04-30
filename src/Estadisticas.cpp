/*******************************************************************************
** Estadisticas.cpp: contiene todo lo necesario para trabajar con la solapa
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

#include "Estadisticas.h"


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    TFmeEstadisticas::TFmeEstadisticas(QWidget* parent, const char* name, Qt::WindowFlags fl, QString NombreConjunto, TFmeImputacion *FmeImputacionAsociada, TFrmOpciones *FrmOpciones)
    {
      setGeometry(0, 0, parent->width()-2, parent->height()-15);

      if (this->objectName().isEmpty())
        this->setObjectName(QString::fromUtf8("TFmeEstadisticas"));

      PanProgreso = new QLineEdit(this);
      PanProgreso->setObjectName(QString::fromUtf8("PanProgreso"));
      PanProgreso->setGeometry(QRect(0, 0, this->width(), 90));
      QColor color = Qt::green;
      color.setRgb(0, 218, 160);
      color.setHsv (164, 255, 218);
      QPalette palette( QApplication::palette() );
      palette.setColor( QPalette::Active, QPalette::Base, color );
      PanProgreso->setPalette(palette);
      LabOperacion = new QLabel(PanProgreso);
      LabOperacion->setObjectName(QString::fromUtf8("LabOperacion"));
      LabOperacion->setGeometry(QRect(8, 8, 111, 18));
      LabProgreso = new QLabel(PanProgreso);
      LabProgreso->setObjectName(QString::fromUtf8("LabProgreso"));
      LabProgreso->setGeometry(QRect(8, 52, 143, 18));
      LabPorcentaje = new QLabel(PanProgreso);
      LabPorcentaje->setObjectName(QString::fromUtf8("LabPorcentaje"));
      LabPorcentaje->setGeometry(QRect(400, 8, 82, 18));
      LabElemento = new QLabel(PanProgreso);
      LabElemento->setObjectName(QString::fromUtf8("LabElemento"));
      LabElemento->setGeometry(QRect(490, 8, 81, 18));
      EdtOperacion = new QLineEdit(PanProgreso);
      EdtOperacion->setObjectName(QString::fromUtf8("EdtOperacion"));
      EdtOperacion->setGeometry(QRect(8, 24, 381, 23));
      EdtOperacion->setReadOnly(true);
      palette.setColor( QPalette::Active, QPalette::Base, Qt::white );
      EdtOperacion->setPalette(palette);
      PbrProgreso = new QProgressBar(PanProgreso);
      PbrProgreso->setObjectName(QString::fromUtf8("PbrProgreso"));
      PbrProgreso->setGeometry(QRect(2, 73, PanProgreso->width()-2, 15));
      PbrProgreso->setValue(0);
      PbrProgreso->setTextVisible(false);
      palette.setColor( QPalette::Active, QPalette::Base, color );
      PbrProgreso->setPalette(palette);
      EdtPorcentaje = new QLineEdit(PanProgreso);
      EdtPorcentaje->setObjectName(QString::fromUtf8("EdtPorcentaje"));
      EdtPorcentaje->setGeometry(QRect(400, 24, 73, 23));
      EdtPorcentaje->setReadOnly(true);
      palette.setColor( QPalette::Active, QPalette::Base, Qt::white );
      EdtPorcentaje->setPalette(palette);
      EdtElemento = new QLineEdit(PanProgreso);
      EdtElemento->setObjectName(QString::fromUtf8("EdtElemento"));
      EdtElemento->setGeometry(QRect(490, 24, 113, 23));
      EdtElemento->setReadOnly(true);
      EdtElemento->setPalette(palette);
      PanContenedor = new QFrame(this);
      PanContenedor->setObjectName(QString::fromUtf8("PanContenedor"));
      PanContenedor->setGeometry(QRect(0, 0, this->width(), this->height()-50));
      PanContenedor->setFrameShape(QFrame::NoFrame);
      PanContenedor->setFrameShadow(QFrame::Raised);
      SptSeparador = new QLabel(PanContenedor);
      SptSeparador->setObjectName(QString::fromUtf8("SptSeparador"));
      SptSeparador->setGeometry(QRect(0, 90, 601, 3));
      SptSeparador->setFrameShape(QFrame::HLine);
      SptSeparador->setFrameShadow(QFrame::Sunken);
      SptSeparador->setLineWidth(3);
      QString start = QCoreApplication::applicationDirPath();
      QString meta = QDir::toNativeSeparators("/images/linea.bmp");
      SptSeparador->setPixmap(QPixmap(start+meta));
      PanUtilidades = new QFrame(PanContenedor);
      PanUtilidades->setObjectName(QString::fromUtf8("PanUtilidades"));
      PanUtilidades->setGeometry(QRect(1, PanContenedor->height()-2-42, PanContenedor->width(), 42));
      PanUtilidades->setFrameShape(QFrame::Box);
      PanUtilidades->setFrameShadow(QFrame::Raised);
      LabVariable = new QLabel(PanUtilidades);
      LabVariable->setObjectName(QString::fromUtf8("LabVariable"));
      LabVariable->setGeometry(QRect(8, 10, 134, 18));
      CbxVariables = new QComboBox(PanUtilidades);
      CbxVariables->setObjectName(QString::fromUtf8("CbxVariables"));
      CbxVariables->setGeometry(QRect(158, 8, 185, 23));
      CbxVariables->setEditable(true);
      ButGuardarInforme = new QPushButton(PanUtilidades);
      ButGuardarInforme->setObjectName(QString::fromUtf8("ButGuardarInforme"));
      ButGuardarInforme->setGeometry(QRect(888, 8, 121, 27));
      MemInfo = new QTextEdit(PanContenedor);
      MemInfo->setObjectName(QString::fromUtf8("MenInfo"));
      MemInfo->setGeometry(QRect(1, 1, PanContenedor->width(), PanContenedor->height()/2));
      MemInfo->setReadOnly(true);
      GbxHistogramaFrecuencias = new QGroupBox(PanContenedor);
      GbxHistogramaFrecuencias->setObjectName(QString::fromUtf8("GbxHistogramaFrecuencias"));
      GbxHistogramaFrecuencias->setGeometry(QRect(1, PanContenedor->height()/2 + 3, PanContenedor->width(), PanContenedor->height()/2-3-44));

      plot = new QwtPlot((QWidget*)PanContenedor);
      plot->setGeometry(QRect(2, PanContenedor->height()/2 + 35, PanContenedor->width()/2 + PanContenedor->width()/4 - 25, PanContenedor->height()/2-87));
      plot->setCanvasBackground(QColor(Qt::white));

      grid = new QwtPlotGrid;
      grid->enableXMin(true);
      grid->enableYMin(true);
      grid->setMajorPen(QPen(Qt::black, 0, Qt::DotLine));
      grid->setMinorPen(QPen(Qt::gray, 0 , Qt::DotLine));
      grid->attach(plot);


      plotM = new QwtPlot((QWidget*)PanContenedor);
      plotM->setGeometry(QRect(PanContenedor->width()/2 + PanContenedor->width()/4 - 15, PanContenedor->height()/2 + 35, PanContenedor->width()/4 - 15, PanContenedor->height()/2-87));
      plotM->setCanvasBackground(QColor(Qt::white));

      gridM = new QwtPlotGrid;
      gridM->enableXMin(true);
      gridM->enableYMin(true);
      gridM->setMajorPen(QPen(Qt::black, 0, Qt::DotLine));
      gridM->setMinorPen(QPen(Qt::gray, 0 , Qt::DotLine));
      gridM->attach(plotM);

      histogrampre = new QwtPlotHistogram();
      histogrampre->setBrush(Qt::blue);

      histogrampos = new QwtPlotHistogram();
      histogrampos->setBrush(Qt::green);

      histogrampreM = new QwtPlotHistogram();

      histogrampreM->setBrush(Qt::blue);
      histogramposM = new QwtPlotHistogram();

      histogramposM->setBrush(Qt::green);

      ButAnterior = new QPushButton(PanUtilidades);
      ButAnterior->setObjectName(("ButAnterior"));
      ButAnterior->setGeometry(QRect(350, 8, 23, 23));

      ButSiguiente = new QPushButton(PanUtilidades);
      ButSiguiente->setObjectName(("ButSiguiente"));
      ButSiguiente->setGeometry(QRect(373, 8, 23, 23));

      ButAnteriorM = new QPushButton(PanUtilidades);
      ButAnteriorM->setObjectName(("ButAnteriorM"));
      ButAnteriorM->setGeometry(QRect(PanContenedor->width()/2 + PanContenedor->width()/4 + 65, 8, 23, 23));

      ButSiguienteM = new QPushButton(PanUtilidades);
      ButSiguienteM->setObjectName(("ButSiguienteM"));
      ButSiguienteM->setGeometry(QRect(PanContenedor->width()/2 + PanContenedor->width()/4 + 88, 8, 23, 23));

      EdtValoresRango = new QLineEdit(GbxHistogramaFrecuencias);
      EdtValoresRango->setObjectName(QString::fromUtf8("EdtValoresRango"));
      EdtValoresRango->setGeometry(QRect(plot->width()/2, 8, 133, 23));
      EdtValoresRango->setReadOnly(true);
      palette.setColor( QPalette::Active, QPalette::Base, Qt::gray );
      EdtValoresRango->setPalette(palette);
      EdtValoresMissing = new QLineEdit(GbxHistogramaFrecuencias);
      EdtValoresMissing->setObjectName(QString::fromUtf8("EdtValoresMissing"));
      EdtValoresMissing->setGeometry(QRect(plotM->x() + plotM->width()/2, 8, 143, 23));
      EdtValoresMissing->setReadOnly(true);
      EdtValoresMissing->setPalette(palette);

      this->setWindowTitle(QApplication::translate("TFmeEstadisticas", "Form", 0));
      LabOperacion->setText(QApplication::translate("TFmeEstadisticas", "Operaci\303\263n en curso", 0));
      LabProgreso->setText(QApplication::translate("TFmeEstadisticas", "Progreso de la operaci\303\263n", 0));
      LabPorcentaje->setText(QApplication::translate("TFmeEstadisticas", "% completado", 0));
      LabElemento->setText(QApplication::translate("TFmeEstadisticas", "# completado", 0));
      EdtOperacion->setToolTip(QApplication::translate("TFmeEstadisticas", "Nombre de la operaci\303\263n que esta siendo ejecutada actualmente.", 0));
      EdtOperacion->setText(QApplication::translate("TFmeEstadisticas", "Generaci\303\263n del informe resumen de las operaciones realizadas.", 0));
      PbrProgreso->setToolTip(QApplication::translate("TFmeEstadisticas", "Muestra del progreso de la operaci\303\263n.", 0));
      EdtPorcentaje->setToolTip(QApplication::translate("TFmeEstadisticas", "Porcentaje completado de la operaci\303\263n.", 0));
      EdtElemento->setToolTip(QApplication::translate("TFmeEstadisticas", "Elemento actual en proceso / N\303\272mero total de elementos a procesar", 0));
      SptSeparador->setText(QString());
      LabVariable->setText(QApplication::translate("TFmeEstadisticas", "Variable a visualizar", 0));
      ButGuardarInforme->setText(QApplication::translate("TFmeEstadisticas", "Guardar informe", 0));
      GbxHistogramaFrecuencias->setToolTip(QApplication::translate("TFmeEstadisticas", "Histograma de porcentajes de error.", 0));
      GbxHistogramaFrecuencias->setTitle(QApplication::translate("TFmeEstadisticas", "Histogramas de frecuencias", 0));
      MemInfo->setToolTip(QApplication::translate("TFmeEstadisticas", "Resumen de operaciones", 0));
      CbxVariables->setToolTip(QApplication::translate("TFmeEstadisticas", "Seleccione la variable a mostrar", 0));
      ButGuardarInforme->setToolTip(QApplication::translate("TFmeEstadisticas", "Guarda informe de las operaciones en un fichero de texto", 0));
      ButSiguiente->setText(">");
      ButAnterior->setText("<");
      ButAnterior->setToolTip(QApplication::translate("", "Pulse aqu\303\255 para visualizar los anteriores valores", 0));
      ButSiguiente->setToolTip(QApplication::translate("", "Pulse aqu\303\255 para visualizar los siguientes valores", 0));
      ButSiguienteM->setText(">");
      ButAnteriorM->setText("<");
      ButAnteriorM->setToolTip(QApplication::translate("", "Pulse aqu\303\255 para visualizar los anteriores missings", 0));
      ButSiguienteM->setToolTip(QApplication::translate("", "Pulse aqu\303\255 para visualizar los siguientes missings", 0));
      EdtValoresRango->setText(QApplication::translate("TFmeEstadisticas", "VALORES RANGO", 0));
      EdtValoresMissing->setText(QApplication::translate("TFmeEstadisticas", "VALORES MISSING", 0));

      connect(CbxVariables, SIGNAL(activated ( const int & )), this, SLOT(CbxVariablesCloseUp(const int &)));
      connect(ButGuardarInforme, SIGNAL(clicked()), this, SLOT(ButGuardarInformeClick()));
      connect(ButSiguiente, SIGNAL(clicked()), this, SLOT(ButClick_sig()));
      connect(ButAnterior, SIGNAL(clicked()), this, SLOT(ButClick_ant()));
      connect(ButSiguienteM, SIGNAL(clicked()), this, SLOT(ButClick_sigM()));
      connect(ButAnteriorM, SIGNAL(clicked()), this, SLOT(ButClick_antM()));

      QMetaObject::connectSlotsByName(this);

       Cargado = false;

      // Asociar las clases
      AsociarClases(FmeImputacionAsociada);
      this->FrmOpciones = FrmOpciones;
      MemLogs->append(QApplication::translate("", "Creando la clase de estad\303\255sticas", 0));
      QApplication::processEvents();

      // Fijar la cantidad de datos
      FijarCantidadDatos();

      // Inicializar la estructura del resumen de variables
      InicializarResumenVariables(&ResumenVariablesPreImputacion);
      QApplication::processEvents();
      InicializarResumenVariables(&ResumenVariablesPosImputacion);
      QApplication::processEvents();

      // Realizar el resumen para los datos a priori
      RealizarResumenVariables(ResumenVariablesPreImputacion, FmeMicroDatosAsociados->GetMatrizMicroDatos());
      QApplication::processEvents();

      this->NombreConjunto = NombreConjunto;

      CbxVariables->addItems(*FmeVariablesAsociadas->GetListaVariables());
      CbxVariables->setInsertPolicy(QComboBox::NoInsert);
      QApplication::processEvents();
    }
    void TFmeEstadisticas::ajustarSize()
    {
        setGeometry(0, 0, parentWidget()->width()-2, parentWidget()->height()-15);

        PanProgreso->setGeometry(QRect(0, 0, this->width(), 90));

        PbrProgreso->setGeometry(QRect(2, 73, PanProgreso->width()-2, 15));

        PanContenedor->setGeometry(QRect(0, 0, this->width(), this->height()-50));

        PanUtilidades->setGeometry(QRect(1, PanContenedor->height()-2-42, PanContenedor->width(), 42));

        MemInfo->setGeometry(QRect(1, 1, PanContenedor->width(), PanContenedor->height()/2));

        GbxHistogramaFrecuencias->setGeometry(QRect(1, PanContenedor->height()/2 + 3, PanContenedor->width(), PanContenedor->height()/2-3-44));

        plot->setGeometry(QRect(2, PanContenedor->height()/2 + 35, PanContenedor->width()/2 + PanContenedor->width()/4 - 25, PanContenedor->height()/2-87));

        plotM->setGeometry(QRect(PanContenedor->width()/2 + PanContenedor->width()/4 - 15, PanContenedor->height()/2 + 35, PanContenedor->width()/4 - 15, PanContenedor->height()/2-87));

        ButAnteriorM->setGeometry(QRect(PanContenedor->width()/2 + PanContenedor->width()/4 + 65, 8, 23, 23));

        ButSiguienteM->setGeometry(QRect(PanContenedor->width()/2 + PanContenedor->width()/4 + 88, 8, 23, 23));

        EdtValoresRango->setGeometry(QRect(plot->width()/2, 8, 133, 23));

        EdtValoresMissing->setGeometry(QRect(plotM->x() + plotM->width()/2, 8, 143, 23));

    }

    void TFmeEstadisticas::SetTiempoCargaDatos(double t) { TiempoCargaDatos = t; }
    bool TFmeEstadisticas::EstaCargado() { return Cargado; }

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Asociar las clases provenientes de etapas anteriores.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void TFmeEstadisticas::AsociarClases(TFmeImputacion *FmeImputacionAsociada)
    {
      this->FmeImputacionAsociada = FmeImputacionAsociada;
      this->FmeTestAsociado = FmeImputacionAsociada->GetTestAsociado();
      this->FmeRangosAsociados = FmeTestAsociado->GetRangosAsociados();
      this->FmeEditsAsociados = FmeRangosAsociados->GetEditsAsociados();
      this->FmeMicroDatosAsociados = FmeEditsAsociados->GetMicroDatosAsociados();
      this->FmeVariablesAsociadas = FmeMicroDatosAsociados->GetVariablesAsociadas();
      this->MemLogs = FmeVariablesAsociadas->GetMemLogs();
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Fijar la cantidad de datos que intervienen en el proceso.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void TFmeEstadisticas::FijarCantidadDatos()
    {
      NumRegistros = FmeMicroDatosAsociados->GetNumRegistros();
      NumVariables = FmeVariablesAsociadas->GetNumVariables();
      NumEdits = FmeEditsAsociados->GetNumEdits();
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Generar las estadisticas del proceso.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void TFmeEstadisticas::GenerarEstadisticas(bool resumen)
    {
      resumido = resumen;
      InicSistemaProgreso();

      // Seccion 1.
      GenerarEstadisticasVariables();
      IncSistemaProgreso();
    
      // Seccion 2.
      GenerarEstadisticasMicroDatos();
      IncSistemaProgreso();
    
      // Seccion 3.
      GenerarEstadisticasEdits();
      IncSistemaProgreso();
    
      // Seccion 4.
      GenerarEstadisticasRangos();
      IncSistemaProgreso();
    
      // Seccion 5.
      GenerarEstadisticasTest();
      IncSistemaProgreso();

      // Seccion 6.
      GenerarEstadisticasImputacion();
      IncSistemaProgreso();
    
      // Seccion 7.
      GenerarListadoEdits();
      IncSistemaProgreso();
    
      // Seccion 10.
      GenerarIncumplimientoEdits();
      IncSistemaProgreso();
    
      // Seccion 11.1
      GenerarVariablesImputadas();
      IncSistemaProgreso();

      // Seccion 11.2
      GenerarInformacionDonantes();
      IncSistemaProgreso();

      // Seccion 12.
      GenerarPertenenciaVariables();
      IncSistemaProgreso();
    
      // Seccion 13.
      GenerarExclusion();
      IncSistemaProgreso();
    
      // Seccion 14.
      GenerarResumenVariables();
      IncSistemaProgreso();
    
      // Seccion 15.
      GenerarListadoCoyuntural();
      IncSistemaProgreso();
    
      // Seccion 16.
      GenerarListadoErrores();
      IncSistemaProgreso();
    
      // Seccion 17.
      GenerarImputacionVariables();
      IncSistemaProgreso();
    
      // Seccion 18.
      GenerarCorrespondenciaVariables();
      IncSistemaProgreso();
    
      Cargado = true;
    
      PanProgreso->hide();

      MemInfo->moveCursor ( QTextCursor::Start, QTextCursor::MoveAnchor);
      PanContenedor->show();
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Generar las estadisticas de la seccion de variables.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void TFmeEstadisticas::GenerarEstadisticasVariables()
    {


      MemInfo->append("1. " + QApplication::translate("", "Secci\303\263n de variables", 0));
      MemInfo->append("---------------------------------------------------------------------------------------------------------------");
      MemInfo->append("1.1. " + QApplication::translate("", "N\303\272mero de variables num\303\251ricas", 0) + ": " + QString::number(FmeVariablesAsociadas->GetNumVariables(), 10));
      MemInfo->append("1.2. " + QApplication::translate("", "N\303\272mero de atributos", 0) + ": " + QString::number(FmeVariablesAsociadas->GetNumAtributos(), 10));
      MemInfo->append("1.3. " + tr("Tipos de variables") + ": ");
      MemInfo->append("  1.3.1. " + tr("Continuas") + ": " + QString::number(FmeVariablesAsociadas->GetNumTiposVariable(T_CONTINUO), 10) + " [" + QString::number(FmeVariablesAsociadas->GetPorcentajeTiposVariable(T_CONTINUO), 'f', 2) + "%]");
      MemInfo->append("  1.3.2. " + tr("Discretas en rango") + ": " + QString::number(FmeVariablesAsociadas->GetNumTiposVariable(T_DISCRETO), 10) + " [" + QString::number(FmeVariablesAsociadas->GetPorcentajeTiposVariable(T_DISCRETO), 'f', 2) + "%]");
      MemInfo->append("  1.3.3. " + tr("Discretas en lista") + ": " + QString::number(FmeVariablesAsociadas->GetNumTiposVariable(T_MIXTO), 10) + " [" + QString::number(FmeVariablesAsociadas->GetPorcentajeTiposVariable(T_MIXTO), 'f', 2) + "%]");
      MemInfo->append("  1.3.4. " + tr("Ignorables") + ": " + QString::number(FmeVariablesAsociadas->GetNumTiposVariable(T_IGNORABLE), 10) + " [" + QString::number(FmeVariablesAsociadas->GetPorcentajeTiposVariable(T_IGNORABLE), 'f', 2) + "%]");
      MemInfo->append("1.4. " + QApplication::translate("", "Admisi\303\263n de valores missing", 0) + ": ");
      for (int i=0; i < FmeVariablesAsociadas->GetNum_valores_missing(); i++)
        MemInfo->append("  1.4." + QString::number(i+1, 10) + " " + FmeVariablesAsociadas->GetCadenas_Missing()->at(i) + ": " + QString::number(FmeVariablesAsociadas->GetNumAdmisionMissing(i), 10) + " [" + QString::number(FmeVariablesAsociadas->GetPorcentajeAdmisionMissing(i), 'f', 2) + "%]");
      MemInfo->append("1.5. " + tr("Existencia de filtros") + ": " + QString::number(FmeVariablesAsociadas->GetNumFiltros(), 10) + " [" + QString::number(FmeVariablesAsociadas->GetPorcentajeFiltros(), 'f', 2) + "%]");
      MemInfo->append("1.6. " + tr("Variables imputables") + ": " + QString::number(FmeVariablesAsociadas->GetNumVariablesImputables(), 10) + " [" + QString::number(FmeVariablesAsociadas->GetPorcentajeVariablesImputables(), 'f', 2) + "%]");
      MemInfo->append("");
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Generar las estadisticas de la seccion de microdatos.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void TFmeEstadisticas::GenerarEstadisticasMicroDatos()
    {
      MemInfo->append("2. " + QApplication::translate("", "Secci\303\263n de microdatos", 0));
      MemInfo->append("---------------------------------------------------------------------------------------------------------------");
      MemInfo->append("2.1. " + QApplication::translate("", "N\303\272mero de registros", 0) + ": " + QString::number(FmeMicroDatosAsociados->GetNumRegistros(), 10));
      MemInfo->append("2.2. " + QApplication::translate("", "N\303\272mero de registros x N\303\272mero de variables", 0) + ": " + QString::number(FmeMicroDatosAsociados->GetNumMicrodatos(), 10));
      MemInfo->append("2.3. " + tr("Existencia de valores missing: "));
      for (int i=0; i < FmeVariablesAsociadas->GetNum_valores_missing(); i++)
          MemInfo->append("  2.3." + QString::number(i+1, 10) + " " + FmeVariablesAsociadas->GetCadenas_Missing()->at(i) + ": " + QString::number(FmeMicroDatosAsociados->GetNumMissing(i), 10) + " [" + QString::number(FmeMicroDatosAsociados->GetPorcentajeMissing(i), 'f', 2) + "%]");
      MemInfo->append("2.4. " + tr("Tiempo de carga de datos") + ": " + QString::number(TiempoCargaDatos, 'f', 2) + " " + tr("segundos"));
      MemInfo->append("");
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Generar las estadisticas de la seccion de edits.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void TFmeEstadisticas::GenerarEstadisticasEdits()
    {
      MemInfo->append("3. " + QApplication::translate("", "Secci\303\263n de reglas", 0));
      MemInfo->append("---------------------------------------------------------------------------------------------------------------");
      MemInfo->append("3.1. " + QApplication::translate("", "N\303\272mero de reglas", 0) + ": " + QString::number(FmeEditsAsociados->GetNumEdits(), 10));
      MemInfo->append("");
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Generar las estadisticas de la secciï¿½n de rangos.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void TFmeEstadisticas::GenerarEstadisticasRangos()
    {
      MemInfo->append("4. " + QApplication::translate("", "Secci\303\263n de rangos y filtros", 0));
      MemInfo->append("---------------------------------------------------------------------------------------------------------------");
      MemInfo->append("4.1. " + tr("Tiempo de proceso") + ": " + QString::number(FmeRangosAsociados->GetTiempoProcesoSegundos(), 'f', 2) + " " + tr("segundos"));
      MemInfo->append("4.2. " + QApplication::translate("", "Umbral de errores de exclusi\303\263n de variables", 0) + ": " + QString::number(FmeRangosAsociados->GetUmbralExclusionVariables(), 10));
      MemInfo->append("4.3. " + QApplication::translate("", "Umbral de errores de exclusi\303\263n de registros", 0) + ": " + QString::number(FmeRangosAsociados->GetUmbralExclusionRegistros(), 10));
      MemInfo->append("4.4. " + tr("Registros") + ":");
      MemInfo->append("  4.4.1. " + tr("Registros excluidos a priori") + ": " + QString::number(FmeRangosAsociados->GetNumRegistrosExcluidosAPriori(), 10));
      MemInfo->append("  4.4.2. " + tr("Registros excluidos a posteriori") + ": " + QString::number(FmeRangosAsociados->GetNumRegistrosExcluidos(), 10));
      MemInfo->append("  4.4.3. " + tr("Registros correctos") + ": " + QString::number(FmeRangosAsociados->GetNumRegistrosCorrectos(), 10));
      MemInfo->append("  4.4.4. " + tr("Registros incorrectos") + ": " + QString::number(FmeRangosAsociados->GetNumRegistrosIncorrectos(), 10));
      MemInfo->append("4.5. Variables:");
      MemInfo->append("  4.5.1. " + tr("Variables excluidas a priori") + ": " + QString::number(FmeRangosAsociados->GetNumVariablesExcluidasAPriori(), 10));
      MemInfo->append("  4.5.2. " + tr("Variables excluidas a posteriori") + ": " + QString::number(FmeRangosAsociados->GetNumVariablesExcluidas(), 10));
      MemInfo->append("  4.5.3. " + tr("Variables correctas") + ": " + QString::number(FmeRangosAsociados->GetNumVariablesCorrectas(), 10));
      MemInfo->append("  4.5.4. " + tr("Variables incorrectas") + ": " + QString::number(FmeRangosAsociados->GetNumVariablesIncorrectas(), 10));
      MemInfo->append("");
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Generar las estadisticas de la seccion de test.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void TFmeEstadisticas::GenerarEstadisticasTest()
    {
      MemInfo->append("5. " + QApplication::translate("", "Secci\303\263n de test", 0));
      MemInfo->append("---------------------------------------------------------------------------------------------------------------");
      MemInfo->append("5.1. " + tr("Tiempo de proceso") + ": " + QString::number(FmeTestAsociado->GetTiempoProcesoSegundos(), 'f', 2) + " " + tr("segundos"));
      MemInfo->append("5.2. " + QApplication::translate("", "Umbral de errores de exclusi\303\263n de reglas", 0) + ": " + QString::number(FmeTestAsociado->GetUmbralExclusionEdits(), 10));
      MemInfo->append("5.3. " + QApplication::translate("", "Umbral de errores de exclusi\303\263n de registros", 0) + ": " + QString::number(FmeTestAsociado->GetUmbralExclusionRegistros(), 10));
      MemInfo->append("5.4. " + tr("Registros") + ":");
      MemInfo->append("  5.4.1. " + tr("Registros excluidos a priori") + ": " + QString::number(FmeTestAsociado->GetNumRegistrosExcluidosAPriori(), 10));
      MemInfo->append("  5.4.2. " + tr("Registros excluidos a posteriori") + ": " + QString::number(FmeTestAsociado->GetNumRegistrosExcluidos(), 10));
      MemInfo->append("  5.4.3. " + tr("Registros correctos") + ": " + QString::number(FmeTestAsociado->GetNumRegistrosCorrectos(), 10));
      MemInfo->append("  5.4.4. " + tr("Registros incorrectos") + ": " + QString::number(FmeTestAsociado->GetNumRegistrosIncorrectos(), 10));
      MemInfo->append("5.5. Reglas:");
      MemInfo->append("  5.5.1. " + tr("Reglas excluidas a priori") + ": " + QString::number(FmeTestAsociado->GetNumEditsExcluidosAPriori(), 10));
      MemInfo->append("  5.5.2. " + tr("Reglas excluidas a posteriori") + ": " + QString::number(FmeTestAsociado->GetNumEditsExcluidos(), 10));
      MemInfo->append("  5.5.3. " + tr("Reglas correctas") + ": " + QString::number(FmeTestAsociado->GetNumEditsCorrectos(), 10));
      MemInfo->append("  5.5.4. " + tr("Reglas incorrectas") + ": " + QString::number(FmeTestAsociado->GetNumEditsIncorrectos(), 10));
      MemInfo->append("");
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Generar las estadisticas de la seccion de imputacion.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void TFmeEstadisticas::GenerarEstadisticasImputacion()
    {
      MemInfo->append("6. " + QApplication::translate("", "Secci\303\263n de imputaci\303\263n", 0));
      MemInfo->append("---------------------------------------------------------------------------------------------------------------");
      MemInfo->append("6.1. " + tr("Tiempo de proceso") + ": " + QString::number(FmeImputacionAsociada->GetTiempoProcesoSegundos(), 'f', 2) + " " + tr(" segundos"));
      MemInfo->append("6.2. " + tr("Registros donantes") + ": " + QString::number(FmeImputacionAsociada->GetNumRegistrosDonantes(), 10) + " [" + QString::number(FmeImputacionAsociada->GetPorcentajeRegistrosDonantes(), 'f', 2) + "%]");
      MemInfo->append("6.3. " + tr("Registros a corregir") + ": " + QString::number(FmeImputacionAsociada->GetNumRegistrosACorregir(), 10) + " [" + QString::number(FmeImputacionAsociada->GetPorcentajeRegistrosACorregir(), 'f', 2) + "%]");
      MemInfo->append("6.4. " + tr("Registros excluidos") + ": " + QString::number(FmeImputacionAsociada->GetNumRegistrosExcluidos(), 10) + " [" + QString::number(FmeImputacionAsociada->GetPorcentajeRegistrosExcluidos(), 'f', 2) + "%]");
      MemInfo->append("6.5. " + tr("Registros correctos") + ": " + QString::number(FmeImputacionAsociada->GetNumRegistrosCorrectos(), 10) + " [" + QString::number(FmeImputacionAsociada->GetPorcentajeRegistrosCorrectos(), 'f', 2) + "%]");
      MemInfo->append("6.6. " + tr("Registros incorrectos") + ": " + QString::number(FmeImputacionAsociada->GetNumRegistrosIncorrectos(), 10) + " [" + QString::number(FmeImputacionAsociada->GetPorcentajeRegistrosIncorrectos(), 'f', 2) + "%]");
      MemInfo->append("6.7. " + tr("Registros warning") + ": " + QString::number(FmeImputacionAsociada->GetNumRegistrosWarning(), 10) + " [" + QString::number(FmeImputacionAsociada->GetPorcentajeRegistrosWarning(), 'f', 2) + "%]");
      MemInfo->append("6.8. " + tr("Promedio de variables imputadas por registro (total)") + ": " + QString::number(FmeImputacionAsociada->GetPromedioVariablesImputadasTotal(), 'f', 2));
      MemInfo->append("6.9. " + tr("Promedio de variables imputadas por registro (sin reg. warning)") + ": " + QString::number(FmeImputacionAsociada->GetPromedioVariablesImputadasSinWarning(), 'f', 2));
      MemInfo->append("6.10. " + tr("Promedio de errores en rango por registro") + ": " + QString::number(FmeImputacionAsociada->GetPromedioErroresRango(), 'f', 2));
      MemInfo->append("6.11. " + tr("Promedio de variables involucradas en reglas incorrectas por registro") + ": " + QString::number(FmeImputacionAsociada->GetPromedioErroresEdits(), 'f', 2));
      MemInfo->append("6.12. " + tr("Promedio de variables involucradas en errores totales por registro") + ": " + QString::number(FmeImputacionAsociada->GetPromedioErroresTotal(), 'f', 2));
      MemInfo->append("6.13. " + tr("Promedio de variables involucradas en comp. conexas con error por registro") + ": " + QString::number(FmeImputacionAsociada->GetPromedioSizeCompConexas(), 'f', 2));
      MemInfo->append("6.15. " + tr("Peso Alfa1") + ": " + QString::number(FrmOpciones->GetPesoAlfa(), 'f', 2));
      MemInfo->append("6.16. " + tr("Peso Alfa2") + ": " + QString::number(FrmOpciones->GetPesoBeta1(), 'f', 2));
      MemInfo->append("6.17. " + tr("Peso Alfa3") + ": " + QString::number(FrmOpciones->GetPesoBeta2(), 'f', 2));
      MemInfo->append("6.18. " + tr("Peso Alfa4") + ": " + QString::number(FrmOpciones->GetPesoGamma(), 'f', 2));
      MemInfo->append("6.19. " + tr("Promedio de distancias a registros donantes") + ": " + QString::number(FmeImputacionAsociada->GetPromedioDistancias(), 'f', 2));
      MemInfo->append("6.20. " + tr("Total de valores contaminados") + ": " + QString::number(FmeMicroDatosAsociados->GetValoresContaminados(), 'f', 2));
      MemInfo->append("");
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Generar el listado de edits.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void TFmeEstadisticas::GenerarListadoEdits()
    {
      QString Edit;
      unsigned j;

      MemInfo->append("7. " + tr("Listado de reglas de rango"));
      MemInfo->append("---------------------------------------------------------------------------------------------------------------");
      for (j = 0; j < NumVariables; j++)
      {
        Edit = FmeVariablesAsociadas->GetCadenaEditRango(j);
        MemInfo->append("V" + QString::number(j + 1, 10) + ": " + Edit);
      }
      MemInfo->append("");
      MemInfo->append("8. " + tr("Listado de reglas de filtro"));
      MemInfo->append("---------------------------------------------------------------------------------------------------------------");
      for (j = 0; j < NumVariables; j++)
      {
        Edit = FmeVariablesAsociadas->GetCadenaEditFiltro(j);
        if (!Edit.isEmpty())
          MemInfo->append("F" + QString::number(j + 1, 10) + ": " + Edit);
      }
      MemInfo->append("");
      MemInfo->append("9. " + tr("Listado de reglas generales"));
      MemInfo->append("---------------------------------------------------------------------------------------------------------------");
      for (j = 0; j < NumEdits; j++)
      {
        Edit = FmeEditsAsociados->GetEdit(j);
        if (!Edit.isEmpty())
          MemInfo->append("E" + QString::number(j + 1, 10) + ": " + Edit);
      }
      MemInfo->append("");
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Generar el listado del incumplimiento de edits.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void TFmeEstadisticas::GenerarIncumplimientoEdits()
    {
      unsigned i, j;
      QString EditsViolados, Cadena, VariablesImputacion, InfoAux;
      unsigned VariablesBasicasAImputar, VariablesExtendidasAImputar, VariablesExtendidasAImputarLargo, VariablesImputadas;

      MemInfo->append("10. " + tr("Incumplimiento de reglas"));
      MemInfo->append("---------------------------------------------------------------------------------------------------------------");
      for (i = 0; i < NumRegistros; i++)
      {
        if (!FmeImputacionAsociada->RegistroExcluido(i) && !FmeImputacionAsociada->RegistroDonante(i))
        {
          EditsViolados = "";
          // Edits de Rango
          for (j = 0; j < NumVariables; j++)            
            if (!FmeRangosAsociados->VariableExcluida(j))
              if ((!FmeRangosAsociados->GetTest(i, j)) && (!FmeRangosAsociados->GetTestRango(i, j)))
                EditsViolados += ("V" + QString::number(j + 1, 10) + " ");
          // Edits de Filtro
          for (j = 0; j < NumVariables; j++)
            if (!FmeRangosAsociados->VariableExcluida(j))
              if ((!FmeRangosAsociados->GetTest(i, j)) && (!FmeRangosAsociados->GetTestFiltro(i, j)))
                EditsViolados += ("F" + QString::number(j + 1, 10) + " ");
          // Edits de Explicitos
          for (j = 0; j < NumEdits; j++)
            if (!FmeTestAsociado->EditExcluido(j))
              if (!FmeTestAsociado->GetTestEdit(i, j))
                EditsViolados += ("E" + QString::number(j + 1, 10) + " ");
          // Variables de imputacion
          VariablesBasicasAImputar = FmeImputacionAsociada->GetNumVariablesRangoAImputar(i) + FmeImputacionAsociada->GetNumVariablesEditsAImputar(i);
          VariablesExtendidasAImputar = FmeImputacionAsociada->GetNumVariablesExtendidasAImputar(i);
          VariablesExtendidasAImputarLargo = FmeImputacionAsociada->GetNumVariablesExtendidasAImputarLargo(i);
          VariablesImputadas = FmeImputacionAsociada->GetNumVariablesImputadas(i);
          VariablesImputacion = "[VBI = " + QString::number(VariablesBasicasAImputar, 10) + ", ";
          VariablesImputacion += "vbi = " + QString::number(FmeImputacionAsociada->GetNumVariablesRangoAImputarImputables(i) + FmeImputacionAsociada->GetNumVariablesEditsAImputarImputables(i), 10) + ", ";
          VariablesImputacion += "VEI(C) = " + QString::number(VariablesExtendidasAImputar, 10) + ", ";
          VariablesImputacion += "VEI(L) = " + QString::number(VariablesExtendidasAImputarLargo, 10) + ", ";
          VariablesImputacion += "VI = " + QString::number(VariablesImputadas, 10) + "]";
          // Registro correcto
          if (FmeImputacionAsociada->RegistroIncorrecto(i))
            InfoAux = "   " + tr("No corregido");
          else
            if (FmeImputacionAsociada->RegistroWarning(i))
              InfoAux = "   Warning";
            else
              InfoAux = "";

          if (!EditsViolados.isEmpty())
          {
            Cadena = "R" + QString::number(i + 1, 10) + ": { " + EditsViolados + "}  " + VariablesImputacion + InfoAux;
            MemInfo->append(Cadena);
          }
        }
      }

      MemInfo->append("");
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Generar el listado de las variables imputadas en cada registro.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void TFmeEstadisticas::GenerarVariablesImputadas()
    {
      unsigned i, j;
      QString VariablesImputadas, Cadena;

      MemInfo->append("11.1 " + tr("Variables imputadas"));
      MemInfo->append("---------------------------------------------------------------------------------------------------------------");
      for (i = 0; i < NumRegistros; i++)
      {
        if (!FmeImputacionAsociada->RegistroExcluido(i) && !FmeImputacionAsociada->RegistroDonante(i) && !FmeImputacionAsociada->RegistroIncorrecto(i))
        {
          VariablesImputadas = "";
          for (j = 0; j < NumVariables; j++)
            if (FmeImputacionAsociada->MicrodatoImputado(i, j))
              VariablesImputadas += ("V" + QString::number(j + 1, 10) + "(" + QString::number(FmeMicroDatosAsociados->GetValor(i, j), 'f', 2) + ", " + QString::number(FmeImputacionAsociada->GetValor(i, j), 'f', 2) + ") ");

          if (!VariablesImputadas.isEmpty())
          {
            Cadena = "R" + QString::number(i + 1, 10) + ": { " + VariablesImputadas + "}  [" + tr("REG.") + " DON. = R" + QString::number(FmeImputacionAsociada->GetRegistroDonante(i) + 1, 10) + "]";
            MemInfo->append(Cadena);
            if (!donantes.contains(FmeImputacionAsociada->GetRegistroDonante(i))) donantes.append(FmeImputacionAsociada->GetRegistroDonante(i));
            donantesreg.insertMulti(FmeImputacionAsociada->GetRegistroDonante(i), i);
          }
        }
      }
      MemInfo->append("");
    }
    void TFmeEstadisticas::GenerarInformacionDonantes()
    {
      unsigned i, j;
      QString Cadena, antes;
      QMap<int, int>::const_iterator it;
      MemInfo->append("11.2 " + tr("Registros Donantes"));
      MemInfo->append("---------------------------------------------------------------------------------------------------------------");
      for (i = 0; i < donantes.size(); i++)
      {
        it = donantesreg.find(donantes.at(i));
        antes = "R" + QString::number(donantes.at(i) + 1, 10) + " " + QString::number(donantesreg.count(donantes.at(i)), 10) + tr(" donaciones: ");
        Cadena = "";
        while (it != donantesreg.end() && it.key() == donantes.at(i)) {
            Cadena += "R" + QString::number(it.value()+1, 10) + " ";            
            it++;            
        }
        MemInfo->append(antes + Cadena);
      }
      MemInfo->append("");
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Generar el listado de pertenencia de variables a edits.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void TFmeEstadisticas::GenerarPertenenciaVariables()
    {
      unsigned j, aux;
      QSet<unsigned> ConjuntoEdits;
      QSet<unsigned>::iterator Puntero;
      QString Edits, Cadena, Orden;
    
      MemInfo->append("12. " + tr("Pertenencia de variables a reglas"));
      MemInfo->append("---------------------------------------------------------------------------------------------------------------");
      for (j = 0; j < NumVariables; j++)
      {
        Edits = "V" + QString::number((j + 1), 10);
        ConjuntoEdits = FmeVariablesAsociadas->GetFiltrosConVariable(j);
        Puntero = ConjuntoEdits.begin();
        while (Puntero != ConjuntoEdits.end())
        {
          Edits += (" F" + QString::number(((*Puntero) + 1), 10));
          ++Puntero;
        }
        ConjuntoEdits = FmeEditsAsociados->GetEditsConVariable(j);
        Puntero = ConjuntoEdits.begin();
        while (Puntero != ConjuntoEdits.end())
        {
          Edits += " E" + QString::number(((*Puntero) + 1), 10);
          ++Puntero;
        }
        aux = FmeImputacionAsociada->GetPosicionPorIndiceVariable(j);
        Orden = "[ORD = " + QString::number((aux + 1), 10) + ", " + tr("PESO") + " = " + QString::number(FmeImputacionAsociada->GetPesoVariableEnPosicion(aux), 'f', 2) + "]";
        Cadena = FmeVariablesAsociadas->GetNombreVariable(j) + ": { " + Edits + "}  " + Orden;
        MemInfo->append(Cadena);
      }
      MemInfo->append("");
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Generar el listado de exclusion.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void TFmeEstadisticas::GenerarExclusion()
    {
      unsigned i, j;
      QString Aux;

      MemInfo->append("13. " + QApplication::translate("", "Exclusi\303\263n", 0));
      MemInfo->append("---------------------------------------------------------------------------------------------------------------");
      MemInfo->append("13.1. " + QApplication::translate("", "Exclusi\303\263n en rangos", 0));
      MemInfo->append("  13.1.1. Variables");
      Aux = "";
      for (j = 0; j < NumVariables; j++)
        if (FmeRangosAsociados->VariableExcluida(j))
          Aux += (FmeVariablesAsociadas->GetNombreVariable(j) + " ");
      MemInfo->append("    " + Aux);
      MemInfo->append("  13.1.2. " + tr("Registros"));
      Aux = "";
      for (i = 0; i < NumRegistros; i++)
        if (FmeRangosAsociados->RegistroExcluido(i))
          Aux += ("R" + QString::number(i + 1, 10) + " ");
      MemInfo->append("    " + Aux);
      MemInfo->append("13.2. " + QApplication::translate("", "Exclusi\303\263n en test", 0));
      MemInfo->append("  13.2.1. " + tr("Reglas"));
      Aux = "";
      for (j = 0; j < NumEdits; j++)
        if (FmeTestAsociado->EditExcluido(j))
          Aux += ("E" + QString::number(j + 1, 10) + " ");
      MemInfo->append("    " + Aux);
      MemInfo->append("  13.2.2. " + tr("Registros"));
      Aux = "";
      for (i = 0; i < NumRegistros; i++)
        if (FmeTestAsociado->RegistroExcluido(i))
          Aux += ("R" + QString::number(i + 1, 10) + " ");
      MemInfo->append("    " + Aux);
      MemInfo->append("");
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Generar el resumen de las variables.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void TFmeEstadisticas::GenerarResumenVariables()
    {
      unsigned j, k;
      TTipoVariable TipoVariable;
      QString NombreVariable;
      unsigned NumValoresRango;

      // Realizar el resumen para los datos a posteriori
      RealizarResumenVariables(ResumenVariablesPosImputacion, FmeImputacionAsociada->GetMatrizMicroDatos());

      // Volcado de datos
      MemInfo->append("14. " + QApplication::translate("", "Comparativa en resumen estad\303\255stico de variables", 0));
      MemInfo->append("---------------------------------------------------------------------------------------------------------------");
      for (j = 0; j < NumVariables; j++)
      {
        if (FmeVariablesAsociadas->EsVariableImputable(j))
        {
          TipoVariable = (TTipoVariable)(int)ResumenVariablesPreImputacion[j][0].x;
          NombreVariable = FmeVariablesAsociadas->GetNombreVariable(j);
          switch (TipoVariable)
          {
            case T_CONTINUO:
              NumValoresRango = ResumenVariablesPreImputacion[j][0].y;
              MemInfo->append("  " + NombreVariable + " (" + tr("Variable continua") + ")");
              MemInfo->append("    " + tr("Media") + " = " + QString::number(ResumenVariablesPreImputacion[j][1].x, 'f', 2) + ", " + QString::number(ResumenVariablesPosImputacion[j][1].x, 'f', 2));
              MemInfo->append("    " + tr("D.tip") + " = " + QString::number(ResumenVariablesPreImputacion[j][2].x, 'f', 2) + ", " + QString::number(ResumenVariablesPosImputacion[j][2].x, 'f', 2));
              for (k = 3; k < NumValoresRango + 1; k++)
                MemInfo->append("    " + QString::number(ResumenVariablesPreImputacion[j][k].x, 'g', 6) + " = " + QString::number(ResumenVariablesPreImputacion[j][k].y, 'f', 2) + ", " + QString::number(ResumenVariablesPosImputacion[j][k].y, 'f', 2));
              break;
            case T_DISCRETO:
            case T_MIXTO:
              NumValoresRango = ResumenVariablesPreImputacion[j][0].y;
              MemInfo->append("  " + NombreVariable + " (" + tr("Variable discreta") + ") [" + QString::number(NumValoresRango, 10) + " " + tr("posibles valores]"));
              for (k = 1; k < NumValoresRango + 1; k++)
                MemInfo->append("    " + QString::number(ResumenVariablesPreImputacion[j][k].x, 'f', 2) + " = " + QString::number(ResumenVariablesPreImputacion[j][k].y, 'f', 2) + ", " + QString::number(ResumenVariablesPosImputacion[j][k].y, 'f', 2));
              break;
            default:
              break;
          }
        }
      }
      MemInfo->append("");
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Inicializar el vector de resumen de variables.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void TFmeEstadisticas::InicializarResumenVariables(TTipoResumenVariables ***RV)
    {
      unsigned j, k, h;
      TTipoVariable TipoVariable;
      QList<double> ValoresRangos;
      QList<double>::iterator Puntero;
      unsigned NumValoresRango, NumValoresTotal;
      double Aux;
    
      (*RV) = new TTipoResumenVariables*[NumVariables];
      for (j = 0; j < NumVariables; j++)
      {
        TipoVariable = FmeVariablesAsociadas->GetTipoVariable(j);
    
        switch (TipoVariable)
        {
          case T_CONTINUO:
            NumValoresRango = 2;
            NumValoresTotal = NumValoresRango + FmeVariablesAsociadas->GetNum_valores_missing();
            (*RV)[j] = new TTipoResumenVariables[1 + NumValoresTotal];
            (*RV)[j][0].x = T_CONTINUO;
            (*RV)[j][0].y = NumValoresTotal;
            (*RV)[j][1].x = 0;
            (*RV)[j][1].y = 0;
            (*RV)[j][2].x = 0;
            (*RV)[j][2].y = 0;
            break;
          case T_DISCRETO:
            ValoresRangos = FmeVariablesAsociadas->GetValoresRangos(j);
            NumValoresRango = ValoresRangos.size();
            NumValoresRango = MIN(NumValoresRango, MAX_VALORES_ESTADISTICAS);
            NumValoresTotal = NumValoresRango + FmeVariablesAsociadas->GetNum_valores_missing();
            (*RV)[j] = new TTipoResumenVariables[1 + NumValoresTotal];
            (*RV)[j][0].x = T_DISCRETO;
            (*RV)[j][0].y = NumValoresTotal;
    
            Puntero = ValoresRangos.begin();
            k = 1;
            while (Puntero != ValoresRangos.end())
            {
              (*RV)[j][k].x = (*Puntero);
              (*RV)[j][k].y = 0;
              ++Puntero;
              k++;
            }
            break;
          case T_MIXTO:
            ValoresRangos = FmeVariablesAsociadas->GetValoresRangos(j);
            NumValoresRango = ValoresRangos.back() - ValoresRangos.front() + 1;
            NumValoresRango = MIN(NumValoresRango, MAX_VALORES_ESTADISTICAS);
            NumValoresTotal = NumValoresRango + FmeVariablesAsociadas->GetNum_valores_missing();
            (*RV)[j] = new TTipoResumenVariables[1 + NumValoresTotal];
            (*RV)[j][0].x = T_MIXTO;
            (*RV)[j][0].y = NumValoresTotal;

            Aux = ValoresRangos.front();
            for (k = 1; k < NumValoresRango + 1; k++)
            {
              (*RV)[j][k].x = Aux;
              (*RV)[j][k].y = 0;
              Aux++;
            }
            break;
          default:
            break;
        }
        // Colocar los valores missing
        for (k = NumValoresRango + 1, h = 0; k < 1 + NumValoresTotal; k++, h++)
        {
          (*RV)[j][k].x = FmeVariablesAsociadas->GetValorMissing((TTipoMissing)(T_NO_PROCEDE + h));
          (*RV)[j][k].y = 0;
        }
      }
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Inicializar el sistema de progreso.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void TFmeEstadisticas::InicSistemaProgreso()
    {
      PbrProgreso->setRange (0, NUM_SECCIONES_INFORME);
      PbrProgreso->setValue(0);      
      EdtPorcentaje->setText("0%");
      EdtElemento->setText("(" + QString::number(PbrProgreso->value(), 10) + "/" + QString::number(PbrProgreso->maximum(), 10) + ")");
      QApplication::processEvents();
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Incrementar el sistema de progreso.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void TFmeEstadisticas::IncSistemaProgreso()
    {
      PbrProgreso->setValue(PbrProgreso->value()+1);
      EdtElemento->setText("(" + QString::number(PbrProgreso->value(), 10) + "/" + QString::number(PbrProgreso->maximum(), 10) + ")");
      EdtPorcentaje->setText(SustCaracter(QString::number(((double)PbrProgreso->value() / (double)PbrProgreso->maximum()) * 100, 'f', 2), '.', ',') + "%");
      QApplication::processEvents();
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Realizar el resumen de variables.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void TFmeEstadisticas::RealizarResumenVariables(TTipoResumenVariables **RV, double **MicroDatos)
    {
      unsigned i, j, k, NumValoresRango;
      TTipoVariable TipoVariable;
      double Valor;

      for (i = 0; i < NumRegistros; i++)
        for (j = 0; j < NumVariables; j++)
        {
          TipoVariable = (TTipoVariable)(int)RV[j][0].x;
          Valor = MicroDatos[i][j];
          switch (TipoVariable)
          {
            case T_CONTINUO:
              if (!FmeVariablesAsociadas->EsValorMissing(Valor))
              {
                // para la media
                RV[j][1].x += Valor;
                RV[j][1].y++;

                // para la desviacion tipica
                RV[j][2].x += pow(Valor, 2);
                RV[j][2].y++;
                break;
              }
            case T_DISCRETO:
            case T_MIXTO:
              NumValoresRango = RV[j][0].y;
              for (k = 1; k < NumValoresRango + 1; k++)
                if (RV[j][k].x == Valor)
                {
                  RV[j][k].y++;
                  break;
                }
              break;
            default:
              break;
          }
        }
      // Calcular la media y la desviacion tipica de las variables continuas
      for (j = 0; j < NumVariables; j++)
      {
        TipoVariable = (TTipoVariable)(int)RV[j][0].x;
        switch (TipoVariable)
        {
          case T_CONTINUO:
            Valor = RV[j][1].y;
            if (Valor == 0)
            {
              RV[j][1].x = 0;
              RV[j][2].x = 0;
            }
            else
            {
              RV[j][1].x /= Valor;
              RV[j][2].x = (((double)1 / (double)Valor) * RV[j][2].x) - pow(RV[j][1].x, 2);
              if (RV[j][2].x < 0)
              {
                RV[j][1].x = 0;
                RV[j][2].x = 0;
              }
              else
                RV[j][2].x = sqrt(RV[j][2].x);
            }
            break;
          case T_DISCRETO:
            break;
          case T_MIXTO:
            break;
          default:
            break;
        }
      }
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Generar un listado coyuntural.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void TFmeEstadisticas::GenerarListadoCoyuntural()
    {
      unsigned i;      

      MemInfo->append("15. " + tr("Listado sobre registros"));
      MemInfo->append("---------------------------------------------------------------------------------------------------------------");
      MemInfo->append("15.1. " + tr("Registros excluidos"));
      MemInfo->append("");
      for (i = 0; i < NumRegistros; i++)
        if (FmeImputacionAsociada->RegistroExcluido(i))
          MemInfo->append("- " + FmeMicroDatosAsociados->GetIdRegistro(i) + " [R" + QString::number(i + 1, 10) + "]");

      MemInfo->append("");
      MemInfo->append("15.2. " + tr("Registros incorrectos"));
      MemInfo->append("");

      for (i = 0; i < NumRegistros; i++)
        if (FmeImputacionAsociada->RegistroIncorrecto(i))
          MemInfo->append("- " + FmeMicroDatosAsociados->GetIdRegistro(i) + " [R" + QString::number(i + 1, 10) + "]");

      MemInfo->append("");
      MemInfo->append("15.3. " + tr("Registros warning"));
      MemInfo->append("");
      for (i = 0; i < NumRegistros; i++)
        if (FmeImputacionAsociada->RegistroWarning(i))
          MemInfo->append("- " + FmeMicroDatosAsociados->GetIdRegistro(i) + " [R" + QString::number(i + 1, 10) + "]");

      MemInfo->append("");
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Generar un listado de porcentajes de error tanto en rangos como en edits.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void TFmeEstadisticas::GenerarListadoErrores()
    {
      unsigned j;

      MemInfo->append("16. " + tr("Listado sobre variables/reglas"));
      MemInfo->append("---------------------------------------------------------------------------------------------------------------");
      MemInfo->append("16.1. " + tr("Rangos y filtros"));
      MemInfo->append("");
      for (j = 0; j < NumVariables; j++)
        if ((resumido) && (FmeRangosAsociados->GetNumeroErrorVariable(j) == 0)) ;
        else
          MemInfo->append("- V" + QString::number(j + 1, 10) + " [" + FmeVariablesAsociadas->GetNombreVariable(j) + "] : " + QString::number(FmeRangosAsociados->GetPorcentajeErrorVariable(j), 'f', 2) + "% [" + QString::number(FmeRangosAsociados->GetNumeroErrorVariable(j), 10) + "]");

      MemInfo->append("");
      MemInfo->append("16.2. " + tr("Test"));
      MemInfo->append("");
      for (j = 0; j < NumEdits; j++)
        if ((resumido) && (FmeTestAsociado->GetNumeroErrorEdit(j) == 0)) ;
        else
          MemInfo->append("- E" + QString::number(j + 1, 10) + ": " + QString::number(FmeTestAsociado->GetPorcentajeErrorEdit(j), 'f', 2) + "% [" +
        QString::number(FmeTestAsociado->GetNumeroErrorEdit(j), 10) + "]");

      MemInfo->append("");
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Generar un listado con el porcentaje de imputacion por variables.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void TFmeEstadisticas::GenerarImputacionVariables()
    {
      unsigned j;
      MemInfo->append("17. " + QApplication::translate("", "Imputaci\303\263n sobre variables", 0));
      MemInfo->append("---------------------------------------------------------------------------------------------------------------");
      MemInfo->append("");
      for (j = 0; j < NumVariables; j++) {
        if ((resumido) && (FmeImputacionAsociada->GetNumRegistrosImputados(j) == 0)) ;
        else {
          MemInfo->append("- V" + QString::number(j + 1, 10) + " [" + FmeVariablesAsociadas->GetNombreVariable(j) + "] : " + QString::number(FmeImputacionAsociada->GetPorcentajeRegistrosImputados(j), 'f', 2) + "% [" +
          QString::number(FmeImputacionAsociada->GetNumRegistrosImputados(j), 10) + "]");
        }
      }
      MemInfo->append("");
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Generar un listado con la correspondencia entre numeros de variables y nombres de variables.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void TFmeEstadisticas::GenerarCorrespondenciaVariables()
    {
      unsigned j;
      if (!resumido) {
        MemInfo->append("18. " + QApplication::translate("", "Correspondencia entre nombres e \303\255ndices de variables", 0));
        MemInfo->append("---------------------------------------------------------------------------------------------------------------");
        MemInfo->append("");
        for (j = 0; j < NumVariables; j++)
          MemInfo->append("- V" + QString::number(j + 1, 10) + ": " + FmeVariablesAsociadas->GetNombreVariable(j));

        MemInfo->append("");
      }
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Generar las tablas latex de descripcion y resumen.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void TFmeEstadisticas::GenerarTablaLatex()
    {
      QString FicheroSalida, Conjunto;
      QStringList *f;
      int p;

      //FicheroSalida = ExtractFilePath(Application->ExeName) + DIRECTORIO_STATS + "\\" + FICHERO_SALIDA_TABLAS + "_" + NombreConjunto + ".txt";
      Conjunto = NombreConjunto;
      p = Conjunto.indexOf("_");
      if (p > 0)
      {
        Conjunto[p] = '-';
      }

      f = new QStringList();

      f->append("\\begin{table}[h!]");
      f->append("\\begin{center}");
      f->append("\\begin{scriptsize}");
      f->append("\\begin{tabular}{|l|l||l|l||l|l||l|l|}");
      f->append("\\hline");
     /* f->append("\\multicolumn{2}{|c||}{Description}\&\\multicolumn{2}{c||}{Ranges and Filters}\&\\multicolumn{2}{c||}{Explicit Edits}\&\\multicolumn{2}{c|}{Imputation}\\\\");
      f->append("\\hline");
      f->append("\\hline");
      f->append("\\#variables\&" + QString::number(FmeVariablesAsociadas->GetNumVariables(), 10) + "\&" +
             "time\&" + QString::number(FmeRangosAsociados->GetTiempoProcesoSegundos(), 'g', 6) + "s\&" +
             "time\&" + QString::number(FmeTestAsociado->GetTiempoProcesoSegundos(), 'g', 6) + "s\&" +
             "time\&" + QString::number(FmeImputacionAsociada->GetTiempoProcesoSegundos(), 'g', 6) + "s" +
             "\\\\");
      f->append("\\hline");

      f->append("\\#records\&" + QString::number(FmeMicroDatosAsociados->GetNumRegistros(), 10) + "\&" +
             "var. exc. threshold\&" + QString::number(FmeRangosAsociados->GetUmbralExclusionVariables(), 10) + "\&" +
             "edit exc. threshold\&" + QString::number(FmeTestAsociado->GetUmbralExclusionEdits(), 10) + "\&" +
             "\\#donor records\&" + QString::number(FmeImputacionAsociada->GetNumRegistrosDonantes(), 10) +
             "\\\\");

      f->append("\\hline");

      f->append("\\#microdata\&" + QString::number(FmeMicroDatosAsociados->GetNumMicrodatos(), 10) + "\&" +
             "rec. exc. threshold\&" + QString::number(FmeRangosAsociados->GetUmbralExclusionRegistros(), 10) + "\&" +
             "rec. exc. threshold\&" + QString::number(FmeTestAsociado->GetUmbralExclusionRegistros(), 10) + "\&" +
             "\\#records to correct\&" + QString::number(FmeImputacionAsociada->GetNumRegistrosACorregir(), 10) +
             "\\\\");

      f->append("\\hline");

      f->append("\\#continuous variables\&" + QString::number(FmeVariablesAsociadas->GetNumTiposVariable(T_CONTINUO), 10) + "\&" +
             "\\#excluded records\&" + QString::number(FmeRangosAsociados->GetNumRegistrosExcluidos(), 10) + "\&" +
             "\\#excluded records\&" + QString::number(FmeTestAsociado->GetNumRegistrosExcluidos(), 10) + "\&" +
             "\\#excluded records\&" + QString::number(FmeImputacionAsociada->GetNumRegistrosExcluidos(), 10) +
             "\\\\");

      f->append("\\hline");

      f->append("\\#discrete variables\&" + QString::number((FmeVariablesAsociadas->GetNumTiposVariable(T_DISCRETO), 10) + FmeVariablesAsociadas->GetNumTiposVariable(T_MIXTO)) + "\&" +
             "\\#correct records\&" + QString::number(FmeRangosAsociados->GetNumRegistrosCorrectos(), 10) + "\&" +
             "\\#correct records\&" + QString::number(FmeTestAsociado->GetNumRegistrosCorrectos(), 10) + "\&" +
             "\\#corrected records\&" + QString::number(FmeImputacionAsociada->GetNumRegistrosCorrectos(), 10) +
             "\\\\");

      f->append("\\hline");
      f->append("\\#imputable variables\&" + QString::number(FmeVariablesAsociadas->GetNumVariablesImputables(), 10) + "\&" +
             "\\#incorrect records\&" + QString::number(FmeRangosAsociados->GetNumRegistrosIncorrectos(), 10) + "\&" +
             "\\#incorrect records\&" + QString::number(FmeTestAsociado->GetNumRegistrosIncorrectos(), 10) + "\&" +
             "\\#uncorrected records\&" + QString::number(FmeImputacionAsociada->GetNumRegistrosIncorrectos(), 10) +
             "\\\\");

      f->append("\\hline");

      f->append("\\#filters\&" + QString::number(FmeVariablesAsociadas->GetNumFiltros(), 10) + "\&" +
             "\\#excluded variables\&" + QString::number(FmeRangosAsociados->GetNumVariablesExcluidas(), 10) + "\&" +
             "\\#excluded edits\&" + QString::number(FmeTestAsociado->GetNumEditsExcluidos(), 10) + "\&" +
             "\\#warning records\&" + QString::number(FmeImputacionAsociada->GetNumRegistrosWarning(), 10) +
             "\\\\");

      f->append("\\hline");

      f->append("\\#explicit edits\&" + QString::number(FmeEditsAsociados->GetNumEdits(), 10) + "\&" +
             "\\#variables with error\&" + QString::number(FmeRangosAsociados->GetNumVariablesIncorrectas(), 10) + "\&" +
             "\\#edits with error\&" + QString::number(FmeTestAsociado->GetNumEditsIncorrectos(), 10) + "\&" +
             "\\#imputation average\&" + QString::number(FmeImputacionAsociada->GetPromedioVariablesImputadasTotal(), 'g', 6) +
             "\\\\");    */

      f->append("\\hline");
      f->append("\\end{tabular}");
      f->append("\\end{scriptsize}");
      f->append("\\end{center}");
      f->append("\\caption{Summary of editing and imputation over " + Conjunto + " survey}");
      f->append("\\end{table}");

      //f->SaveToFile(FicheroSalida);
      QString start = QCoreApplication::applicationDirPath();
      QString meta = QDir::toNativeSeparators(start + "/" + DIRECTORIO_STATS);
      FicheroSalida = QFileDialog::getSaveFileName(this, tr("Guardar fichero stats" ), meta, "TXT (*.txt)");
      if (!FicheroSalida.isEmpty()) {
        QFile file(FicheroSalida);
        if ( !file.open( QIODevice::WriteOnly ) )
          QMessageBox::warning(this, "Warning", tr( "No se puede escribir en el fichero %1" ).arg( FicheroSalida ), "&Ok");
        else {
          QTextStream s( &file );
          for ( QStringList::Iterator it = f->begin(); it != f->end(); ++it )
            s << *it << "\n";
          //s << f;
          file.close();
        }
      }

    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Añadir una linea al fichero de ejecuciones.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void TFmeEstadisticas::AddExecutionLine()
    {
      QString FicheroSalida, LineaEjecucion;
      QStringList *f;

      QString start = QCoreApplication::applicationDirPath();
      QString meta = QDir::toNativeSeparators(start + "/" + DIRECTORIO_STATS);
      FicheroSalida = QFileDialog::getSaveFileName(this, tr("Guardar fichero stats"), meta, "TXT (*.txt)");
      f = new QStringList();
      QFile file(FicheroSalida);
      if (file.exists()) {
        QString line;
        if ( file.open( QIODevice::ReadOnly ) ) {
          QTextStream in( &file );
          while (!in.atEnd()) {
             line = in.readLine();
             QString string(line);
             f->append(string);
          }
          file.close();
        }
      }

      LineaEjecucion = "";
      // nombre del conjunto
      LineaEjecucion += (FmeMicroDatosAsociados->GetNombreConjunto() + QString::number(f->count() + 1, 10) + " ");
      // descripcion
      LineaEjecucion += (QString::number(FmeVariablesAsociadas->GetNumVariables(), 10) + " ");
      LineaEjecucion += (QString::number(FmeMicroDatosAsociados->GetNumRegistros(), 10) + " ");
      LineaEjecucion += (QString::number(FmeMicroDatosAsociados->GetNumMicrodatos(), 10) + " ");
      LineaEjecucion += (QString::number(FmeMicroDatosAsociados->GetNumMicrodatos() - FmeMicroDatosAsociados->GetNumMissing(T_NO_PROCEDE), 10) + " ");
      LineaEjecucion += (QString::number(FmeVariablesAsociadas->GetNumTiposVariable(T_CONTINUO), 10) + " ");
      LineaEjecucion += (QString::number(FmeVariablesAsociadas->GetNumTiposVariable(T_DISCRETO) + FmeVariablesAsociadas->GetNumTiposVariable(T_MIXTO), 10) + " ");
      LineaEjecucion += (QString::number(FmeVariablesAsociadas->GetNumVariablesImputables(), 10) + " ");
      LineaEjecucion += (QString::number(FmeVariablesAsociadas->GetNumFiltros(), 10) + " ");
      LineaEjecucion += (QString::number(FmeEditsAsociados->GetNumEdits(), 10) + " ");
      // evaluacion de rangos y filtros
      LineaEjecucion += (QString::number(FmeRangosAsociados->GetTiempoProcesoSegundos(), 'f', 2) + " ");    
      LineaEjecucion += (QString::number(FmeRangosAsociados->GetNumRegistrosCorrectos(), 10) + " ");
      LineaEjecucion += (QString::number(FmeRangosAsociados->GetNumRegistrosIncorrectos(), 10) + " ");    
      LineaEjecucion += (QString::number(FmeRangosAsociados->GetNumVariablesCorrectas(), 10) + " ");
      LineaEjecucion += (QString::number(FmeRangosAsociados->GetNumVariablesIncorrectas(), 10) + " ");
      // evaluacion de edits explicitos
      LineaEjecucion += (QString::number(FmeTestAsociado->GetTiempoProcesoSegundos(), 'f', 2) + " ");    
      LineaEjecucion += (QString::number(FmeTestAsociado->GetNumRegistrosCorrectos(), 10) + " ");
      LineaEjecucion += (QString::number(FmeTestAsociado->GetNumRegistrosIncorrectos(), 10) + " ");    
      LineaEjecucion += (QString::number(FmeTestAsociado->GetNumEditsCorrectos(), 10) + " ");
      LineaEjecucion += (QString::number(FmeTestAsociado->GetNumEditsIncorrectos(), 10) + " ");
      // imputacion
      LineaEjecucion += (QString::number(FmeImputacionAsociada->GetTiempoProcesoSegundos(), 'f', 2) + " ");
      LineaEjecucion += (QString::number(FmeImputacionAsociada->GetNumRegistrosDonantes(), 10) + " ");
      LineaEjecucion += (QString::number(FmeImputacionAsociada->GetNumRegistrosACorregir(), 10) + " ");
      LineaEjecucion += (QString::number(FmeImputacionAsociada->GetNumRegistrosExcluidos(), 10) + " ");
      LineaEjecucion += (QString::number(FmeImputacionAsociada->GetNumRegistrosCorrectos(), 10) + " ");
      LineaEjecucion += (QString::number(FmeImputacionAsociada->GetNumRegistrosIncorrectos(), 10) + " ");
      LineaEjecucion += (QString::number(FmeImputacionAsociada->GetNumRegistrosWarning(), 10) + " ");
      LineaEjecucion += (QString::number(FmeImputacionAsociada->GetPromedioErroresRango(), 'f', 2) + " ");
      LineaEjecucion += (QString::number(FmeImputacionAsociada->GetPromedioErroresEdits(), 'f', 2) + " ");
      LineaEjecucion += (QString::number(FmeImputacionAsociada->GetPromedioErroresTotal(), 'f', 2) + " ");
      LineaEjecucion += (QString::number(FmeImputacionAsociada->GetPromedioVariablesImputadasTotal(), 'f', 2));
      LineaEjecucion += (QString::number(FmeImputacionAsociada->GetPromedioSizeCompConexas(), 'f', 2));

      f->append(LineaEjecucion);

      if ( file.open( QIODevice::WriteOnly ) )
      {
        QTextStream s( &file );
        for ( QStringList::Iterator it = f->begin(); it != f->end(); ++it )
            s << *it << "\n";
        file.close();
      }      
    }
    QString TFmeEstadisticas::SustCaracter(QString Cadena, char CarABuscar, char CarSustitucion)
    {
      QString Aux;
      int Pos;

      Aux = Cadena;
      Pos = Aux.indexOf(CarABuscar);
      if (Pos != -1)
        Aux[Pos] = CarSustitucion;
      return Aux;
    }

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void TFmeEstadisticas::ant_sig_hist(bool sig)
    {
      unsigned NumValoresRango;
      unsigned NumValoresMissing;
      unsigned IndiceVariable;
      int j;
      TTipoVariable TipoVariable;

      IndiceVariable = CbxVariables->currentIndex();
      TipoVariable = (TTipoVariable)(int)ResumenVariablesPreImputacion[IndiceVariable][0].x;      

      if (TipoVariable == T_CONTINUO)
      {
        j = 3;
        return;
      }else j = 1;

      NumValoresMissing = FmeVariablesAsociadas->GetNum_valores_missing();
      NumValoresRango = (double)ResumenVariablesPreImputacion[IndiceVariable][0].y - NumValoresMissing;

      QVector<QwtIntervalSample> samplespre(NumValoresRango);

      QVector<QwtIntervalSample> samplespos(NumValoresRango);

      double posX = 0.0;
      double posX_max = 0.0;
      double posX_min = 100.0;
      double posY_max = 0.0;
      int width = 0.5;
      double value;
      double max;
      for ( int i = 0; i < NumValoresRango; i++ )
      {
        posX = (double)ResumenVariablesPreImputacion[IndiceVariable][j].x;        
        value = (double)ResumenVariablesPreImputacion[IndiceVariable][j].y;

        QwtInterval interval(posX, posX + 0.05);

        interval.setBorderFlags(QwtInterval::ExcludeMaximum);
        samplespre[i] = QwtIntervalSample(value, interval);

        if (posX > posX_max) posX_max = posX + 2*0.05;
        if (value > posY_max) posY_max = value;
        if (posX < posX_min) posX_min = posX;

        posX = (double)ResumenVariablesPosImputacion[IndiceVariable][j].x + 0.05/*double(width) + 0.3*/;
        value = (double)ResumenVariablesPosImputacion[IndiceVariable][j].y;
        QwtInterval interval2(posX, posX + 0.05);

        interval2.setBorderFlags(QwtInterval::ExcludeMaximum);
        samplespos[i] = QwtIntervalSample(value, interval2);

        if (posX > posX_max) posX_max = posX + (double)width;
        if (value > posY_max) posY_max = value;
        if (posX < posX_min) posX_min = posX;
        j++;
      }
      if ( ( (!sig) && ((ultimo-100 > posX_min) || (ultimo != posX_min)) ) || ( (sig) && ((ultimo+100 < posX_max) || (ultimo != posX_max)) ) ) {  // pulsar dos veces cada boton para que funcione

        histogrampre->setData(new QwtIntervalSeriesData(samplespre));
        histogrampre->attach(plot);
        histogrampos->setData(new QwtIntervalSeriesData(samplespos));

        histogrampos->attach(plot);
        plot->setAxisScale(QwtPlot::yLeft, 0.0, posY_max);
        if (sig) {
          max = ultimo;
          if (ultimo + 100 < posX_max) ultimo = ultimo + 100;
          else ultimo = posX_max;
          plot->setAxisScale(QwtPlot::xBottom, max, ultimo);
        } else {
          max = posX_min;
          if (ultimo - 100 > posX_min) {
            ultimo = ultimo - 100;
            max = ultimo - 100;
          }
          plot->setAxisScale(QwtPlot::xBottom, max, ultimo);
        }
        plot->replot();        
      }      
      samplespre.clear();      
      samplespos.clear();      
    }
    void TFmeEstadisticas::ant_sig_histM(bool sig)
    {
      unsigned NumValoresMissing, NumValoresRango;
      unsigned IndiceVariable;
      int j;
      TTipoVariable TipoVariable;

      IndiceVariable = CbxVariables->currentIndex();
      TipoVariable = (TTipoVariable)(int)ResumenVariablesPreImputacion[IndiceVariable][0].x;

      NumValoresMissing = FmeVariablesAsociadas->GetNum_valores_missing();
      NumValoresRango = (double)ResumenVariablesPreImputacion[IndiceVariable][0].y - NumValoresMissing;

      if (TipoVariable == T_CONTINUO){
        j = 3 + NumValoresRango; return;
      }else j = 1 + NumValoresRango;

      QVector<QwtIntervalSample> samplespreM(NumValoresMissing);
      QVector<QwtIntervalSample> samplesposM(NumValoresMissing);

      double posX = 0.0;
      double posX_max = 0.0;
      double posX_min = 100.0;
      double posY_max = 0.0;
      int width = 0.5;
      double value;
      double max;
      for ( int i = 0; i < NumValoresMissing; i++ )
      {
        posX = (double)ResumenVariablesPreImputacion[IndiceVariable][j].x;
        value = (double)ResumenVariablesPreImputacion[IndiceVariable][j].y;

        QwtInterval interval(posX, posX + 0.15);

        interval.setBorderFlags(QwtInterval::ExcludeMaximum);
        samplespreM[i] = QwtIntervalSample(value, interval);

        if (posX > posX_max) posX_max = posX + 2*0.15;
        if (value > posY_max) posY_max = value;
        if (posX < posX_min) posX_min = posX;

        posX = (double)ResumenVariablesPosImputacion[IndiceVariable][j].x + 0.15;
        value = (double)ResumenVariablesPosImputacion[IndiceVariable][j].y;
        QwtInterval interval2(posX, posX + 0.15);

        interval2.setBorderFlags(QwtInterval::ExcludeMaximum);
        samplesposM[i] = QwtIntervalSample(value, interval2);

        if (posX > posX_max) posX_max = posX + (double)width;
        if (value > posY_max) posY_max = value;
        if (posX < posX_min) posX_min = posX;
        j++;
      }
      if ( ( (!sig) && ((ultimoM-100 > posX_min) || (ultimoM != posX_min)) ) || ( (sig) && ((ultimoM+100 < posX_max) || (ultimoM != posX_max)) ) ) {  // pulsar dos veces cada boton para que funcione
        histogrampreM->setData(new QwtIntervalSeriesData(samplespreM));
        histogrampreM->attach(plotM);
        histogramposM->setData(new QwtIntervalSeriesData(samplesposM));

        histogramposM->attach(plotM);
        plotM->setAxisScale(QwtPlot::yLeft, 0.0, posY_max);
        if (sig) {
          max = ultimoM;
          if (ultimoM + 100 < posX_max) ultimoM = ultimoM + 100;
          else ultimoM = posX_max;
          plotM->setAxisScale(QwtPlot::xBottom, max, ultimoM);
        } else {
          max = posX_min;
          if (ultimoM - 100 > posX_min) {
            ultimoM = ultimoM - 100;
            max = ultimoM - 100;
          }
          plotM->setAxisScale(QwtPlot::xBottom, max, ultimoM);
        }
        plotM->replot();
      }      
      samplespreM.clear();
      samplesposM.clear();
    }

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// PULSAR EL BOTON DE GUARDAR INFORME.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void TFmeEstadisticas::ButGuardarInformeClick()
    {      
      QString start = QCoreApplication::applicationDirPath();
      QString meta = QDir::toNativeSeparators(start + "/" + DIRECTORIO_STATS);
      QString NombreFichero = QFileDialog::getSaveFileName(this, tr("Guardar fichero stats" ), meta, "TXT (*.txt)");

      if (!NombreFichero.isEmpty()) {
        QString texto = MemInfo->toPlainText();
        QFile file(NombreFichero);
        if ( !file.open( QIODevice::WriteOnly ) )
          QMessageBox::warning(this, "Warning", tr( "No se puede escribir en el fichero %1" ).arg( NombreFichero ), "&Ok");
        else {
          QTextStream s( &file );
          s << texto;
          file.close();
        }
      }
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// SELECCIONAR UN ELEMENTO DE LA LISTA DE VARIABLES.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void TFmeEstadisticas::CbxVariablesCloseUp(int index)
    {
      int NumValoresRango;
      int NumValoresTotales;
      int NumValoresMissing;
      int IndiceVariable;
      int j;
      TTipoVariable TipoVariable;

      IndiceVariable = index;
      TipoVariable = (TTipoVariable)(int)ResumenVariablesPreImputacion[IndiceVariable][0].x;      

      if (TipoVariable == T_CONTINUO)
      {
        j = 3;
        histogrampre->detach();
        histogrampos->detach();
        histogrampreM->detach();
        histogramposM->detach();
        plot->replot();
        plotM->replot();
        return;
      }else j = 1;

      NumValoresMissing = FmeVariablesAsociadas->GetNum_valores_missing();
      NumValoresTotales = (double)ResumenVariablesPreImputacion[IndiceVariable][0].y;
      NumValoresRango = (double)ResumenVariablesPreImputacion[IndiceVariable][0].y - NumValoresMissing;

      QVector<QwtIntervalSample> samplespre(NumValoresRango);      
      QVector<QwtIntervalSample> samplespos(NumValoresRango);

      QVector<QwtIntervalSample> samplespreM(NumValoresMissing);
      QVector<QwtIntervalSample> samplesposM(NumValoresMissing);

      double posX = 0.0;
      double posX_max = 0.0;
      double posX_min = 100.0;
      double posY_max = 0.0;
      int width = 0.5;
      double value;
      for ( int i = 0; i < NumValoresRango; i++ )
      {
        posX = (double)ResumenVariablesPreImputacion[IndiceVariable][j].x;        
        value = (double)ResumenVariablesPreImputacion[IndiceVariable][j].y;

        QwtInterval interval(posX, posX + 0.05);

        interval.setBorderFlags(QwtInterval::ExcludeMaximum);
        samplespre[i] = QwtIntervalSample(value, interval);        

        if (posX > posX_max) posX_max = posX + 2*0.05;
        if (value > posY_max) posY_max = value;
        if (posX < posX_min) posX_min = posX;

        posX = (double)ResumenVariablesPosImputacion[IndiceVariable][j].x + 0.05;
        value = (double)ResumenVariablesPosImputacion[IndiceVariable][j].y;
        QwtInterval interval2(posX, posX + 0.05);

        interval2.setBorderFlags(QwtInterval::ExcludeMaximum);
        samplespos[i] = QwtIntervalSample(value, interval2);

        if (posX > posX_max) posX_max = posX + (double)width;
        if (value > posY_max) posY_max = value;
        if (posX < posX_min) posX_min = posX;
        j++;
      }
      if (posX_min+100 < posX_max) ultimo = posX_min+100;
      else ultimo = posX_max;

      histogrampre->setData(new QwtIntervalSeriesData(samplespre));

      histogrampos->setData(new QwtIntervalSeriesData(samplespos));

      plot->setAxisScale(QwtPlot::yLeft, 0.0, posY_max);
      plot->setAxisScale(QwtPlot::xBottom, posX_min, ultimo);

      histogrampre->attach(plot);
      histogrampos->attach(plot);
      plot->replot();
      plot->show();

      samplespre.clear();      
      samplespos.clear();


      posX = 0.0;
      posX_max = 0.0;
      posX_min = 100.0;
      posY_max = 0.0;
      width = 0.5;
      for ( int i = 0; i < NumValoresMissing; i++ )
      {
        posX = (double)ResumenVariablesPreImputacion[IndiceVariable][j].x;
        value = (double)ResumenVariablesPreImputacion[IndiceVariable][j].y;

        QwtInterval interval(posX, posX + 0.15);

        interval.setBorderFlags(QwtInterval::ExcludeMaximum);
        samplespreM[i] = QwtIntervalSample(value, interval);

        if (posX > posX_max) posX_max = posX + 2*0.15;
        if (value > posY_max) posY_max = value;
        if (posX < posX_min) posX_min = posX;

        posX = (double)ResumenVariablesPosImputacion[IndiceVariable][j].x + 0.15;
        value = (double)ResumenVariablesPosImputacion[IndiceVariable][j].y;
        QwtInterval interval2(posX, posX + 0.15);

        interval2.setBorderFlags(QwtInterval::ExcludeMaximum);
        samplesposM[i] = QwtIntervalSample(value, interval2);

        if (posX > posX_max) posX_max = posX + (double)width;
        if (value > posY_max) posY_max = value;
        if (posX < posX_min) posX_min = posX;
        j++;
      }
      if (posX_min+100 < posX_max) ultimoM = posX_min+100;
      else ultimoM = posX_max;

      histogrampreM->setData(new QwtIntervalSeriesData(samplespreM));
      histogrampreM->attach(plotM);
      histogramposM->setData(new QwtIntervalSeriesData(samplesposM));
      histogramposM->attach(plotM);
      plotM->setAxisScale(QwtPlot::yLeft, 0.0, posY_max);
      plotM->setAxisScale(QwtPlot::xBottom, posX_min, ultimoM);
      plotM->replot();

      plotM->show();

      samplespreM.clear();     
      samplesposM.clear();

    }
    void TFmeEstadisticas::ButClick_sig()
    {
      ant_sig_hist(true);
    }

    void TFmeEstadisticas::ButClick_ant()
    {
      ant_sig_hist(false);
    }
    void TFmeEstadisticas::ButClick_sigM()
    {
       ant_sig_histM(true);
    }
    void TFmeEstadisticas::ButClick_antM()
    {
       ant_sig_histM(false);
    }

