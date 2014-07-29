/*******************************************************************************
** Teide2.cpp: programa principal.
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


#include "Teide2.h"

TFrmPrincipal::TFrmPrincipal(QWidget* parent, int argc, char ** argv):QMainWindow(parent)
    {
      if (this->objectName().isEmpty())
        this->setObjectName(("TFrmPrincipal"));

      //this->setGeometry(qApp->desktop ()->availableGeometry(1));
      connect(qApp->desktop (), SIGNAL(resized(int)), this, SLOT(probando(int)));

      //this->setMaximumSize(scrollarea->viewport());
      if (QGuiApplication::primaryScreen()->availableGeometry().width() < 1100) {
          /*if (windowState() == Qt::WindowMaximized) {
            this->showFullScreen();
          }else*/
            this->setGeometry(0, 0, 1276, 746);
           //scrollarea->setStyle(>setFrameStyle(>blockSignals(true);
      }else {
        #ifdef linux
          this->setGeometry(QRect(QPoint(0, 0), this->maximumSize()));
        #else
          this->setGeometry(0, 0, QGuiApplication::primaryScreen()->availableGeometry().width()-10, QGuiApplication::primaryScreen()->availableGeometry().height()-24);//this->showFullScreen();
        #endif
      }
      
      MitNuevoMetafile = new QAction(this);
      MitNuevoMetafile->setObjectName(("MitNuevoMetafile"));
      MitAbrirMetafile = new QAction(this);
      MitAbrirMetafile->setObjectName(("MitAbrirMetafile"));
      MitCerrarMetafile = new QAction(this);
      MitCerrarMetafile->setObjectName(("MitCerrarMetafile"));
      MitCerrarMetafile->setEnabled(false);
      MitOpciones = new QAction(this);
      MitOpciones->setObjectName(("MitOpciones"));
      MitOpciones->setEnabled(false);
      MitProcederPasoAPaso = new QAction(this);
      MitProcederPasoAPaso->setObjectName(("MitProcederPasoAPaso"));
      MitProcederPasoAPaso->setEnabled(false);
      MitProcederCompleto = new QAction(this);
      MitProcederCompleto->setObjectName(("MitProcederCompleto"));
      MitProcederCompleto->setEnabled(false);
      MitCheckPoblacion = new QAction(this);
      MitCheckPoblacion->setObjectName(("MitCheckPoblacion"));
      MitCheckPoblacion->setEnabled(false);
      MitSalir = new QAction(this);
      MitSalir->setObjectName(("MitSalir"));
      MitAyudaTEIDE2 = new QAction(this);
      MitAyudaTEIDE2->setObjectName(("MitAyudaTEIDE2"));
      MitAcercaDe = new QAction(this);
      MitAcercaDe->setObjectName(("MitAcercaDe"));
      segundaEjecucion = false;
      PctContenedorPrincipal = new QTabWidget(this);
      PctContenedorPrincipal->setObjectName(("PctContenedorPrincipal"));
      PctContenedorPrincipal->setGeometry(QRect(0, 40, this->width(), this->height()-40));
      PctContenedorPrincipal->setVisible(false);
      PanCargarMetafile = new QFrame(this);
      PanCargarMetafile->setObjectName(("PanCargarMetafile"));
      PanCargarMetafile->setGeometry(QRect(1, 40, this->width(), this->height()-200));
      PanCargarMetafile->setVisible(false);
      PanCargarMetafile->setFrameShape(QFrame::Panel);
      PanCargarMetafile->setFrameShadow(QFrame::Raised);
      PanTitulo = new QFrame(PanCargarMetafile);
      PanTitulo->setObjectName(("PanTitulo"));
      PanTitulo->setGeometry(QRect(0, 0, PanCargarMetafile->width(), 31));
      PanTitulo->setFrameShape(QFrame::WinPanel);
      PanTitulo->setFrameShadow(QFrame::Raised);
      LabTitulo = new QLabel(PanTitulo);
      LabTitulo->setObjectName(("LabTitulo"));
      LabTitulo->setGeometry(QRect(8, 8, 251, 18));
      MemLogs = new QTextEdit(PanCargarMetafile);
      MemLogs->setObjectName(("MemLogs"));
      MemLogs->setGeometry(QRect(0, 33, PanCargarMetafile->width()-5, this->height()-233));
      MemLogs->setReadOnly(true);      

      QPalette palette( QApplication::palette() );
      palette.setColor( QPalette::Base, Qt::blue );      
      ShpRibete2 = new QLineEdit(this); //ShpRibete1);
      ShpRibete2->setObjectName(("ShpRibete2"));
      ShpRibete2->setGeometry(QRect(0, 26, this->width()-4, 12));//(0, 0, ShpRibete1->width(), ShpRibete1->height()));
      ShpRibete2->setReadOnly(true);
      ShpRibete2->setPalette(palette);
      ShpRibete2->setAutoFillBackground( true );      
      ShpRibete2->show();

      MmnMenuPrincipal = new QMenuBar(this);
      MmnMenuPrincipal->setObjectName(("MmnMenuPrincipal"));
      MmnMenuPrincipal->setGeometry(QRect(0, 0, 1319, 29));

      MitPrincipal = new QMenu(MmnMenuPrincipal);
      MitPrincipal->setObjectName(("MitPrincipal"));
      MitAyuda = new QMenu(MmnMenuPrincipal);
      MitAyuda->setObjectName(("MitAyuda"));
      this->setMenuBar(MmnMenuPrincipal);
      statusbar = new QStatusBar(this);
      statusbar->setObjectName(("statusbar"));
      this->setStatusBar(statusbar);

      MmnMenuPrincipal->addAction(MitPrincipal->menuAction());
      MmnMenuPrincipal->addAction(MitAyuda->menuAction());
      MitPrincipal->addAction(MitNuevoMetafile);
      MitPrincipal->addAction(MitAbrirMetafile);
      MitPrincipal->addAction(MitCerrarMetafile);
      MitPrincipal->addSeparator();
      MitPrincipal->addAction(MitOpciones);
      MitPrincipal->addAction(MitProcederPasoAPaso);
      MitPrincipal->addAction(MitProcederCompleto);
      MitPrincipal->addSeparator();
      MitPrincipal->addAction(MitCheckPoblacion);
      MitPrincipal->addSeparator();
      MitPrincipal->addAction(MitSalir);
      MitAyuda->addAction(MitAyudaTEIDE2);
      MitAyuda->addSeparator();
      MitAyuda->addAction(MitAcercaDe);

      MitNuevoMetafile->setText(QApplication::translate("TFrmPrincipal", "&Nuevo Metafile", 0));
      MitNuevoMetafile->setShortcut(QApplication::translate("TFrmPrincipal", "Ctrl+N", 0));
      MitAbrirMetafile->setText(QApplication::translate("TFrmPrincipal", "&Abrir Metafile", 0));
      MitAbrirMetafile->setShortcut(QApplication::translate("TFrmPrincipal", "Ctrl+A", 0));
      MitCerrarMetafile->setText(QApplication::translate("TFrmPrincipal", "&Cerrar Metafile", 0));
      MitCerrarMetafile->setShortcut(QApplication::translate("TFrmPrincipal", "Ctrl+K", 0));
      MitOpciones->setText(QApplication::translate("TFrmPrincipal", "&Opciones", 0));
      MitOpciones->setShortcut(QApplication::translate("TFrmPrincipal", "Ctrl+O", 0));
      MitProcederPasoAPaso->setText(QApplication::translate("TFrmPrincipal", "&Proceder paso a paso", 0));
      MitProcederPasoAPaso->setShortcut(QApplication::translate("TFrmPrincipal", "Ctrl+P", 0));
      MitProcederCompleto->setText(QApplication::translate("TFrmPrincipal", "Proceder &completo", 0));
      MitProcederCompleto->setShortcut(QApplication::translate("TFrmPrincipal", "Ctrl+C", 0));
      MitCheckPoblacion->setText(QApplication::translate("TFrmPrincipal", "C&hequear poblaci\303\263n...", 0));
      MitSalir->setText(QApplication::translate("TFrmPrincipal", "&Salir", 0));
      MitSalir->setShortcut(QApplication::translate("TFrmPrincipal", "Ctrl+X", 0));
      MitAyudaTEIDE2->setText(QApplication::translate("TFrmPrincipal", "Ayuda de &TEIDE2", 0));
      MitAcercaDe->setText(QApplication::translate("TFrmPrincipal", "&Acerca de...", 0));
      LabTitulo->setText(QApplication::translate("TFrmPrincipal", "Progreso de la carga del metafile...", 0));
      MitPrincipal->setTitle(QApplication::translate("TFrmPrincipal", "&Principal", 0));
      MitAyuda->setTitle(QApplication::translate("TFrmPrincipal", "&Ayuda", 0));
    
      connect(MitNuevoMetafile, SIGNAL(triggered()), this, SLOT(MitNuevoMetafileClick()));
      connect(MitAbrirMetafile, SIGNAL(triggered()), this, SLOT(MitAbrirMetafileClick()));
      connect(MitCerrarMetafile, SIGNAL(triggered()), this, SLOT(MitCerrarMetafileClick()));
      connect(MitOpciones, SIGNAL(triggered()), this, SLOT(MitOpcionesClick()));
      connect(MitProcederPasoAPaso, SIGNAL(triggered()), this, SLOT(MitProcederPasoAPasoClick()));
      connect(MitProcederCompleto, SIGNAL(triggered()), this, SLOT(MitProcederCompletoClick()));
      connect(MitCheckPoblacion, SIGNAL(triggered()), this, SLOT(MitCheckPoblacionClick()));
      connect(MitSalir, SIGNAL(triggered()), this, SLOT(MitSalirClick()));
      connect(MitAyudaTEIDE2, SIGNAL(triggered()), this, SLOT(MitAyudaTEIDE2Click()));
      connect(MitAcercaDe, SIGNAL(triggered()), this, SLOT(MitAcercaDeClick()));



      QMetaObject::connectSlotsByName(this);
      (void)statusBar();      

      DatosCargados = false;
      conexion = false;

      setWindowTitle(QMainWindow::tr(QString(TITULOAPP + EXTRATITULO).toLatin1(), ""));
      BatchMode = false;
      if (argc > 1) {
        BatchMode = true;
        nomMet = argv[1];
      }      
    }
    void TFrmPrincipal::PrimeraEjecucion()
    {
      segundaEjecucion = false;
    }
    void TFrmPrincipal::ContandoEjecucion()
    {
        contEjecucion=0;
    }

    void TFrmPrincipal::probando (int ventana)
    {
        if (qApp->desktop ()->availableGeometry(-1).width() < 1100) {            
             scrollarea->setWindowFlags(Qt::WindowMinimizeButtonHint);
        }else {
               scrollarea->setWindowFlags(Qt::WindowMinMaxButtonsHint);               
        }
        scrollarea->setWindowState(Qt::WindowNoState);        
        scrollarea->show();
    }
    void TFrmPrincipal::resizeEvent ( QResizeEvent * event )
    {
        QMainWindow::resizeEvent(event);
    }
    void TFrmPrincipal::ajustarSize(int entero)
    {
        if (segundaEjecucion)
        {
             PctContenedorPrincipal->setGeometry(QRect(0, 40, this->width(), this->height()+25));
             PanCargarMetafile->setGeometry(QRect(1, 40, this->width(), this->height()-200));
             PanTitulo->setGeometry(QRect(0, 0, PanCargarMetafile->width(), 31));
             MemLogs->setGeometry(QRect(0, 33, PanCargarMetafile->width()-5, this->height()-233));
             ShpRibete2->setGeometry(QRect(0, 26, this->width()-4, 12));
             if (conexion)
             {
                 FmeVariables->ajustarSize();
                 FmeMicroDatos->ajustarSize();
                 FmeEdits->ajustarSize();
                 FmeRangos->ajustarSize();
                 FmeTest->ajustarSize();
                 FmeImputacion->ajustarSize();
                 FmeEstadisticas->ajustarSize();
             }
        }
    }
    void TFrmPrincipal::ajustarSize()
    {        
       if (segundaEjecucion)
       {
            PctContenedorPrincipal->setGeometry(QRect(0, 40, this->width(), this->height()+25/*-40*/));
            PanCargarMetafile->setGeometry(QRect(1, 40, this->width(), this->height()-200));
            PanTitulo->setGeometry(QRect(0, 0, PanCargarMetafile->width(), 31));
            MemLogs->setGeometry(QRect(0, 33, PanCargarMetafile->width()-5, this->height()-233));
            ShpRibete2->setGeometry(QRect(0, 26, this->width()-4, 12));
            if (conexion)
            {
                FmeVariables->ajustarSize();
                FmeMicroDatos->ajustarSize();
                FmeEdits->ajustarSize();
                FmeRangos->ajustarSize();
                FmeTest->ajustarSize();               
                FmeImputacion->ajustarSize();               
                FmeEstadisticas->ajustarSize();              
            }
       }else {
            if (contEjecucion < 2)
               contEjecucion++;
            else segundaEjecucion=true;
       }
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Asigna el scroll ya creado al scroll principal.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void TFrmPrincipal::asignar(Scrollarea * scroll)
    {
      scrollarea = scroll;
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Abre y carga un metafile.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void TFrmPrincipal::AbrirUnMetafile(QString Metafile)
    {
      InstanteComienzo = QTime::currentTime();
      Fase = FASE_INICIAL;
      MemLogs->clear();
      PanCargarMetafile->show();
      CargarMetafile(Metafile);
    }

    void TFrmPrincipal::CargarMetafile(QString NombreMetafile)
    {
      QString NombreBaseDatos;      

      PctContenedorPrincipal->setVisible(false);

      // Miramos si hay algo ya cargado
      if (PctContenedorPrincipal->count() > 0)
        LiberarConjuntosDatos();

      // Apertura del metafile
      QString valor = NombreMetafile;      
      valor = QDir::toNativeSeparators(valor);

      QFile file(valor);
      if (!file.exists())
      {        
        MemLogs->append("ERROR: " + QMainWindow::tr("Fichero metafile no existe"));
        QApplication::processEvents();
        return;
      }

      MemLogs->append(QMainWindow::tr("Abriendo metafile ") + valor);
      QApplication::processEvents();

      if (GetValorTag(NombreMetafile, "") == ERROR_METAFILE)
      {        
        MemLogs->append("ERROR: " + QMainWindow::tr("La estructura del metafile es incorrecta"));
        QApplication::processEvents();
        return;
      }

      // Lectura del nombre de la base de datos
      valor = GetValorTag(NombreMetafile, "RBD");
      valor.replace("\\", "/");
      Excel = false;
      if ((valor.contains( ".mdb")) || (valor.contains( ".xls" )) || (valor.contains( ".accdb" ))) {
        Oracle = false;
        Xml = false;
        if (valor.contains( ".xls" ) > 0) Excel = true;        
        NombreBaseDatos = QCoreApplication::applicationDirPath() + "/" + valor;
        continuarCargaMetafile(NombreMetafile, NombreBaseDatos);
      }else {
        if ((valor.count("/") > 1 || (valor.count("\\")> 1))) {
          Xml = true;          
          NombreBaseDatos = QCoreApplication::applicationDirPath() + "/" + valor;
          continuarCargaMetafile(NombreMetafile, NombreBaseDatos);
        }else {
          if ((valor.contains("ORACLE")) || (valor.contains("Oracle")) || (valor.contains("oracle"))) {
            Oracle = true;
            Xml = false;
            NombreBaseDatos = valor;            
            datorac = new DatosOracle(this, "datos oracle", Qt::Widget, NombreBaseDatos);
            datorac->show();
          }else {
            MemLogs->append("ERROR: " + QMainWindow::tr("No se acepta el valor RBD (") + valor + QMainWindow::tr(") del metafile"));
            QApplication::processEvents();
            return;
          }
        }
      }      
    }

    void TFrmPrincipal::continuarCargaMetafile(QString NombreMetafile, QString NombreBaseDatos)
    {
      QString Aux, Aux2, NombreConjunto, Key, Nor, Cota, Conjunto, CondicionLectura;
      QStringList *TablasMicroDatos, *VariablesTrabajo, *ListaIds, *Cadenas_Missing;
      unsigned NumRegistros;
      QString CadenaConexionBD;
      bool correcto = true;
      int Num_valores_missing;
      QString mens;

      NombreBaseDatos = QDir::toNativeSeparators(NombreBaseDatos);
      MemLogs->append(QApplication::translate("", "Creando la conexi\303\263n a la base de datos", 0) + " \"" + NombreBaseDatos + "\"");
      QApplication::processEvents();

      if (!Oracle) {
        if (!Xml)
            if (Excel) CadenaConexionBD = "DRIVER={Microsoft Excel Driver (*.xls)}; ReadOnly=0; DBQ=";
            else CadenaConexionBD = "DRIVER={Microsoft Access Driver (*.mdb)}; DBQ=";
      }

      if (!Xml) {
        if (!CrearConexionBD(NombreBaseDatos, CadenaConexionBD, &mens))
        {
          if (!Oracle) {
            if (Excel) CadenaConexionBD = "DRIVER={Microsoft Excel Driver (*.xls, *.xlsx, *.xlsm, *.xlsb)}; ReadOnly=0; DBQ=";
            else CadenaConexionBD = "DRIVER={Microsoft Access Driver (*.mdb, *.accdb)}; DBQ=";
            if (!CrearConexionBD(NombreBaseDatos, CadenaConexionBD, &mens)) {
              if (mens.isEmpty()) MemLogs->append(AdcConexionBD.lastError().text());
              else MemLogs->append(mens);
              MemLogs->append("ERROR: " + QMainWindow::tr("No se pudo realizar satisfactoriamente la consulta sobre la base de datos"));
              QApplication::processEvents();
              return;
            }
          }else {
            MemLogs->append(AdcConexionBD.lastError().text());
            MemLogs->append("ERROR: " + QMainWindow::tr("No se pudo realizar satisfactoriamente la consulta sobre la base de datos"));
            QApplication::processEvents();
            return;
          }
        }
      }else {
        conexion = true;
      }

      // Obtener las tablas de microdatos del conjunto
      TablasMicroDatos = GetTablasMicroDatos(NombreMetafile);

      // Obtener el nombre de la variable clave
      Key = GetValorTag(NombreMetafile, "KEY");

      // Chequear conjuntos de microdatos
      if (!BatchMode) {
        Nor = FrmAbrirMetafile->EdtNumRegistros->text();
        CondicionLectura = FrmAbrirMetafile->EdtCondicionLectura->text();
      }else {
        Nor = NUM_REGISTROS_A_CARGAR;
        CondicionLectura = "";
      }
      if (Excel) Aux2 = "[" + GetValorTag(NombreMetafile, "MIS") + "$]";
      else Aux2 = GetValorTag(NombreMetafile, "MIS");
      if ((!Xml) && (!ChequearMicroDatos(TablasMicroDatos, &AdcConexionBD, NumRegistros, &VariablesTrabajo, &ListaIds, MemLogs, Key, Nor, Cota, CondicionLectura, Aux2, &Num_valores_missing, &Cadenas_Missing)))
        return;
      if ((Xml) && (!ChequearMicroDatosXML(TablasMicroDatos, NombreBaseDatos, NumRegistros, &VariablesTrabajo, &ListaIds, MemLogs, Key, Nor, Cota, CondicionLectura, Aux2, &Num_valores_missing, &Cadenas_Missing)))
        return;
      FrmOpciones = new TFrmOpciones(this, "opciones", Qt::Window, Num_valores_missing, Cadenas_Missing);
      FrmOpciones->InicValores();
      // Obtener el nombre del conjunto de datos
      Conjunto = GetValorTag(NombreMetafile, "NOM");
      NombreConjunto = Conjunto;
      // Creacion de las Variables
      VentanaVariables = CrearNuevaHoja(STR0024, true);
      if (Excel) Aux = "[" + GetValorTag(NombreMetafile, "VAR") + "$]";
      else Aux = GetValorTag(NombreMetafile, "VAR");

      (FmeVariables = new TFmeVariables(this, "variables", Qt::Widget, &AdcConexionBD, Aux, Aux2, VariablesTrabajo, NombreConjunto, MemLogs, &correcto, Xml, NombreBaseDatos, PctContenedorPrincipal, Num_valores_missing, Cadenas_Missing, Excel, MitCerrarMetafile))->setParent(VentanaVariables);

      if (correcto) {
        // Creacion de los MicroDatos
        VentanaMicroDatos = CrearNuevaHoja(QMainWindow::tr("MICRODATOS"), true);
        if (!BatchMode)
          (FmeMicroDatos = new TFmeMicroDatos(this, "microdatos", Qt::Widget, &AdcConexionBD, FmeVariables, TablasMicroDatos, NumRegistros, ListaIds, Key, Cota, FrmAbrirMetafile->ContaminarMicrodatos(), FrmAbrirMetafile->GetPorcentajeContaminacion(), Oracle, Xml, NombreBaseDatos, PctContenedorPrincipal, Excel, Nor))->setParent(VentanaMicroDatos);
        else
          (FmeMicroDatos = new TFmeMicroDatos(this, "microdatos", Qt::Widget, &AdcConexionBD, FmeVariables, TablasMicroDatos, NumRegistros, ListaIds, Key, Cota, false, 0, Oracle, Xml, NombreBaseDatos, PctContenedorPrincipal, Excel, Nor))->setParent(VentanaMicroDatos);

        // Creacion de los Edits
        VentanaEdits = CrearNuevaHoja(tr("REGLAS"), true);
        if (Excel) Aux = "[" +  GetValorTag(NombreMetafile, "EDT") + "$]";
        else Aux = GetValorTag(NombreMetafile, "EDT");
        (FmeEdits = new TFmeEdits(this, "edits", Qt::Widget, &AdcConexionBD, Aux, FmeMicroDatos, Xml, NombreBaseDatos, &correcto, Excel, PctContenedorPrincipal))->setParent(VentanaEdits);
        if (correcto) {
          // Creacion de la ventana de ir a variable
          FrmIrAVariable = new TFrmIrAVariable(this, "iravariable", Qt::Widget, VariablesTrabajo);

          // Creacion de la ventana cambiar microdato
          FrmCambiarMicrodato = new TFrmCambiarMicrodato(this);

          // Creacion del dialogo de chequear poblacion
          FrmCheckPoblacion = new TFrmCheckPoblacion(this, "checkpoblacion", Qt::Window, &AdcConexionBD, FmeMicroDatos, NombreBaseDatos, TablasMicroDatos, datorac);

          // Creacion de la validacion de rangos
          VentanaRangos = CrearNuevaHoja(QMainWindow::tr("EVAL. RANGOS Y FILTROS"), false);
          (FmeRangos = new TFmeRangos(this, "rangos", Qt::Widget, FmeEdits, FrmIrAVariable, FrmCambiarMicrodato, FrmOpciones, PctContenedorPrincipal, ListaIds))->setParent(VentanaRangos);

          // Creacion de los tests
          VentanaTest = CrearNuevaHoja(tr("EVAL. DE OTRAS REGLAS"), false);
          (FmeTest = new TFmeTest(this, "test", Qt::Widget, FmeRangos, FrmIrAVariable, FrmCambiarMicrodato, FrmOpciones, PctContenedorPrincipal, ListaIds))->setParent(VentanaTest);

          // Creacion de las imputaciones
          VentanaImputacion = CrearNuevaHoja(QMainWindow::tr("IMPUTACION"), false);
          (FmeImputacion = new TFmeImputacion(this, "imputacion", Qt::Widget, &AdcConexionBD, FmeTest, FrmIrAVariable, FrmCambiarMicrodato, FrmOpciones, Oracle, Xml, NombreBaseDatos, Excel, PctContenedorPrincipal, ListaIds))->setParent(VentanaImputacion);

          // Creacion de los generadores de estadisticas
          VentanaEstadisticas = CrearNuevaHoja(QMainWindow::tr("ESTADISTICAS"), false);
          (FmeEstadisticas = new TFmeEstadisticas(this, "estadistica", Qt::Widget, NombreConjunto, FmeImputacion, FrmOpciones))->setParent(VentanaEstadisticas);

          MemLogs->append("");
          MemLogs->append(QString::number(FmeMicroDatos->GetNumRegistros(), 10) + " " + QMainWindow::tr("registros") + "; " + QString::number(FmeVariables->GetNumVariablesT(), 10) + " variables " + QMainWindow::tr("totales") + "; " + QString::number(FmeVariables->GetNumVariables(), 10) + " variables " + QMainWindow::tr("de trabajo"));
          // Titulo de la aplicacion
          if ((!BatchMode) && (FrmAbrirMetafile->EdtPorcentajeContaminacion->value() > 0))
            Aux = " [" + (QString)STR0031 + ": " + QString::number(FrmAbrirMetafile->EdtPorcentajeContaminacion->value(), 10) + "%])";
          else
            Aux = ")";

          EXTRATITULO2 = " (" + Conjunto + " [" + QString::number(FmeMicroDatos->GetNumRegistros(), 10) + tr(" regs.") + "," + QString::number(FmeVariables->GetNumVariables(), 10) + tr(" vars.]") + Aux;
          scrollarea->actualizartitulo(QMainWindow::tr(QString(TITULOAPP + EXTRATITULO2).toLatin1(), ""));
          DatosCargados = true;

          InstanteFinalizacion = QTime::currentTime();
          double tiempo = InstanteComienzo.secsTo(InstanteFinalizacion);

          FmeEstadisticas->SetTiempoCargaDatos(tiempo);
          if (!BatchMode) {
              TMensajeCarga *mensajeBox = new TMensajeCarga(this, Qt::Window, QApplication::translate("", "El proceso de carga termin\303\263 de manera satisfactoria\nPulse aqu\303\255 para acceder a las funcionalidades del sistema", 0) + "\n" + QString::number(InstanteComienzo.secsTo(InstanteFinalizacion), 10) + " sec." + "\n\n", MemLogs->toPlainText());
              mensajeBox->show();              
          }else Actualizacion_interfaz_usuario();
        }else {
          delete VentanaVariables;
          delete VentanaEdits;
          delete FmeVariables->GetVisualizarVar();
          delete FmeMicroDatos->GetVisualizarReg();
          delete FmeEdits->GetVisualizarEd();
          MitCerrarMetafileClick();
        }
      }else {
        delete VentanaVariables;
        delete FmeVariables->GetVisualizarVar();
        MitCerrarMetafileClick();
      }
    }
 /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
 // Actualiza la interfaz de usuario.
 /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
     void TFrmPrincipal::Actualizacion_interfaz_usuario()
    {
      MitAbrirMetafile->setEnabled(false);
      MitCerrarMetafile->setEnabled(true);
      MitProcederPasoAPaso->setEnabled(true);
      MitProcederCompleto->setEnabled(true);
      MitOpciones->setEnabled(true);
      if (!Xml) MitCheckPoblacion->setEnabled(true);
      else MitCheckPoblacion->setEnabled(false);

      PanCargarMetafile->hide();
      PctContenedorPrincipal->setVisible(true);
      PctContenedorPrincipal->show();
      connect(PctContenedorPrincipal, SIGNAL(currentChanged ( const int &  ) ), this, SLOT(CambiarSolapa ( const int &  ) ));
      connect(PctContenedorPrincipal, SIGNAL(currentChanged(const int &)), this, SLOT(ajustarSize(const int &)));
      extern bool botonCancelar;
      botonCancelar = false;
      extern QString cadena;
      cadena = "";
      extern bool mens1;
      mens1 = false;
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Obtiene los nombres de las tablas de los microdatos del fichero metafile.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    QStringList *TFrmPrincipal::GetTablasMicroDatos(QString NombreMetafile)
    {
      int i = 1;
      QString NombreTabla;
      QStringList *TablasMicroDatos;

      TablasMicroDatos = new QStringList();

      if (Excel) NombreTabla = "[" + GetValorTag(NombreMetafile, "MD" + QString::number(i, 10)) + "$]";
      else NombreTabla = GetValorTag(NombreMetafile, "MD" + QString::number(i, 10));
      while((NombreTabla != "") && (NombreTabla != "[$]"))
      {
        TablasMicroDatos->append(NombreTabla);
        i++;
        if (Excel) NombreTabla = "[" + GetValorTag(NombreMetafile, "MD" + QString::number(i, 10)) + "$]";
        else NombreTabla = GetValorTag(NombreMetafile, "MD" + QString::number(i, 10));
      }
      return TablasMicroDatos;
    }
   QString TFrmPrincipal::GetValorTag(QString NombreMetafile, QString tag)
    {
      QFile file( NombreMetafile );
      if (file.open( QIODevice::ReadOnly ))
      {
        QTextStream stream( &file );
        QString line;
        while ( !stream.atEnd() ) {
          line = stream.readLine();
          if (line.indexOf ( tag ) != -1)
            return line.section( '"', 1, 1);
        }
      }
      file.close();
      return "";
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Crea la conexion.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    bool TFrmPrincipal::CrearConexionBD(QString NombreBaseDatos, QString CadenaConexionBD, QString *mens)
    {
      if (Oracle) {
        AdcConexionBD = QSqlDatabase::addDatabase("QOCI", "oracle");
        AdcConexionBD.setDatabaseName(datorac->getEdtNombre());
        AdcConexionBD.setUserName(datorac->getEdtUsuario());
        AdcConexionBD.setPassword(datorac->getEdtPassword());
        AdcConexionBD.setHostName(datorac->getEdtHost());
        if (AdcConexionBD.open()) {
          conexion = true;
          return true;
        }
      }else {
        if (!QFile::exists(NombreBaseDatos)) {
          *mens = "La base de datos " + NombreBaseDatos + " no existe";
          return false;
        }
        CadenaConexionBD += NombreBaseDatos;		
        AdcConexionBD = QSqlDatabase::addDatabase("QODBC3", "office");
        AdcConexionBD.setDatabaseName(CadenaConexionBD);
        if (AdcConexionBD.open()) {
          conexion = true;
          *mens = "";
          return true;
        }
      }
      *mens = "";
      conexion = false;
      return false;
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Crea cada una de las solapas.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    QWidget *TFrmPrincipal::CrearNuevaHoja(QString Nombre, bool Visible)
    {
      QWidget *Hoja;

      Hoja = new QWidget(this);
      Hoja->setWindowTitle(Nombre);
      if (Visible) {
        PctContenedorPrincipal->addTab(Hoja, Nombre);
        PctContenedorPrincipal->setCurrentWidget(Hoja);
      }
      return Hoja;
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Chequea si las variables y registros son los adecuado.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    bool TFrmPrincipal::ChequearMicroDatos(QStringList *TablasMicroDatos, QSqlDatabase *AdcConexionBD, unsigned &NumRegistros,
    QStringList **VariablesTrabajo, QStringList **ListaIds, QTextEdit *MemLogs, QString Key, QString Nor, QString &Cota,
    QString CondicionLectura, QString NombreTablaMissing, int *Num_valores_missing, QStringList **Cadenas_Missing)
    {
      unsigned i, j;
      QString CadenaSQL;
      QString Variable;
      QString s;

      MemLogs->append(QMainWindow::tr("Realizando comprobaciones de microdatos"));
      QApplication::processEvents();

      if (Nor == "ALL")
      {
        if (CondicionLectura.isEmpty())
          Cota = "";
        else
          Cota = " WHERE " + CondicionLectura;
        NumRegistros = 0;
      }
      else
      {
        try
        {
          NumRegistros = Nor.toInt();          
        }
        catch(...)
        {
          MemLogs->append("ERROR: " + QApplication::translate("", "El valor especificado para NOR no es un n\303\272mero entero v\303\241lido", 0));
          QApplication::processEvents();
          return false;
        }
        if (CondicionLectura.isEmpty())
          Cota = "";//Cota = " WHERE (ID >= 1) AND (ID <= " + QString::number(NumRegistros, 10) + ")";
        else
          Cota = " WHERE " + CondicionLectura; //Cota = " WHERE (ID >= 1) AND (ID <= " + QString::number(NumRegistros, 10) + ") AND " + CondicionLectura;
      }
      // comprobar que existe la tabla
      CadenaSQL = "SELECT * FROM " + TablasMicroDatos->at(0);
      QSqlQuery query4(CadenaSQL, *AdcConexionBD);
      if (!query4.isActive())
      {
         MemLogs->append("ERROR: " + QMainWindow::tr("No se pudo realizar la consulta. Puede que no exista la tabla ") +  TablasMicroDatos->at(0));
         QApplication::processEvents();
         return false;
      }
      query4.finish();
      //comprobar que tiene la key
      CadenaSQL = "SELECT * FROM " + TablasMicroDatos->at(0);
      QSqlQuery query5(CadenaSQL, *AdcConexionBD);
      QSqlRecord record5 = query5.record();
      int l=0;
      while (l < record5.count()) {
          if (record5.fieldName(l) == Key) break;
          l++;
      }
      if (l == record5.count())
      {
          MemLogs->append("ERROR: " + QMainWindow::tr("No se encuentra la key ") + Key + QMainWindow::tr(" en ") + TablasMicroDatos->at(0) + QMainWindow::tr(". Compruebe MAYUSCULAS y minusculas."));
          QApplication::processEvents();
         return false;
      }
      query5.finish();

      CadenaSQL = "SELECT * FROM " + TablasMicroDatos->at(0) + Cota + " ORDER BY \"" + Key + "\"";
      QSqlQuery query(CadenaSQL, *AdcConexionBD);

      QSqlRecord record = query.record();

      if (!query.isActive())
      {
        MemLogs->append("ERROR: " + QMainWindow::tr("No se pudo realizar la consulta"));
        QApplication::processEvents();
        return false;
      }
      *VariablesTrabajo = new QStringList();

      *ListaIds = new QStringList();

      i = 0;
      while (query.next())
      {
        (*ListaIds)->append(query.value(record.indexOf(Key)).toString());
        i++;      
      }

      if ((NumRegistros == 0) || (NumRegistros > i)) NumRegistros = i;

      for (j = 0; j < (unsigned)record.count(); j++)
      {
        Variable = record.fieldName(j);
        if ((Variable != Key) && (Variable != "ID"))
        {
          if ((*VariablesTrabajo)->indexOf(Variable) == -1)
            (*VariablesTrabajo)->append(Variable);
          else
          {
            MemLogs->append("ERROR: " + QMainWindow::tr("Variable") + " " + Variable + " " + QMainWindow::tr("de la tabla") + " \"" + TablasMicroDatos->at(0) + "\" " + QApplication::translate("", "est\303\241 duplicada. No puede estar en m\303\241s de una tabla.", 0));
            QApplication::processEvents();
            return false;
          }
        }
      }
      for (i = 1; i < (unsigned)TablasMicroDatos->count(); i++)
      {
        // comprobar que existe la tabla
        CadenaSQL = "SELECT * FROM " + TablasMicroDatos->at(i);
        QSqlQuery query4(CadenaSQL, *AdcConexionBD);
        if (!query4.isActive())
        {
           MemLogs->append("ERROR: " + QMainWindow::tr("No se pudo realizar la consulta. Puede que no exista la tabla ") +  TablasMicroDatos->at(i));
           QApplication::processEvents();
           return false;
        }
        query4.finish();
        //comprobar que tiene la key
        CadenaSQL = "SELECT * FROM " + TablasMicroDatos->at(i);
        QSqlQuery query5(CadenaSQL, *AdcConexionBD);        
        QSqlRecord record5 = query5.record();
        int l=0;
        while (l < record5.count()) {
            if (record5.fieldName(l) == Key) break;
            l++;
        }
        if (l == record5.count())
        {
           MemLogs->append("ERROR: " + QMainWindow::tr("No se encuentra la key ") + Key + QMainWindow::tr(" en ") + TablasMicroDatos->at(i) + QMainWindow::tr(". Compruebe MAYUSCULAS y minusculas."));
           QApplication::processEvents();
           return false;
        }

        CadenaSQL = "SELECT * FROM " + TablasMicroDatos->at(i)+ Cota + " ORDER BY \"" + Key + "\"";
        QSqlQuery query2(CadenaSQL, *AdcConexionBD);
        QSqlRecord record2 = query2.record();
        if (!query2.isActive())
        {
          MemLogs->append("ERROR: " + QMainWindow::tr("No se pudo realizar la consulta"));
          QApplication::processEvents();
          return false;
        }

        if (size_tabla(query2) != (*ListaIds)->size())
        {
          MemLogs->append("ERROR: " + QApplication::translate("", "El tama\303\261o de la tabla", 0) + " \"" + TablasMicroDatos->at(i) + "\" " + QMainWindow::tr("es incorrecto"));
          QApplication::processEvents();
          return false;
        }

        j = 0;
        query2.first();
        if (query2.value(record2.indexOf(Key)).toString() != (*ListaIds)->at(j))
        {
          MemLogs->append("ERROR: " + QMainWindow::tr("Los identificadores de la tabla") + " \"" + TablasMicroDatos->at(i) + "\" " + QMainWindow::tr("son incoherentes"));
          QApplication::processEvents();
          return false;
        }
        j++;

        while (query2.next())
        {
          if (query2.value(record2.indexOf(Key)).toString() != (*ListaIds)->at(j))
          {
            MemLogs->append("ERROR: " + QMainWindow::tr("Los identificadores de la tabla") + " \"" + TablasMicroDatos->at(i) + "\" " + QMainWindow::tr("son incoherentes"));
            QApplication::processEvents();
            return false;
          }
          j++;
        }
        for (j = 0; j < (unsigned)record2.count(); j++)
        {
          Variable = record2.fieldName(j);
          if ((Variable != Key) && (Variable != "ID"))
          {
            if ((*VariablesTrabajo)->indexOf(Variable) == -1)
              (*VariablesTrabajo)->append(Variable);
            else
            {
              MemLogs->append("ERROR: " + QMainWindow::tr("Variable") + " " + Variable + " " + QMainWindow::tr("de la tabla") + " \"" + TablasMicroDatos->at(i) + "\" " + QApplication::translate("", "est\303\241 duplicada. No puede estar en m\303\241s de una tabla.", 0));
              QApplication::processEvents();
              return false;
            }
          }
        }
      }
      (*ListaIds)->replaceInStrings(".0", "");

      //Tomar los valores missing
      CadenaSQL = "SELECT CODIGO, DESCRIPCION FROM " + NombreTablaMissing;
      QSqlQuery query3(CadenaSQL, *AdcConexionBD);
      if (!query3.isActive()) {
          MemLogs->append("ERROR: " + tr("No se pudo realizar satisfactoriamente la consulta sobre la tabla ") + NombreTablaMissing);
          QApplication::processEvents();
          return false;
      }
      QSqlRecord record3 = query3.record();
      int num = 0;
      QString Literal;
      bool ok = false;
      *Cadenas_Missing = new QStringList();
      while (query3.next()) {
        Literal = query3.value(record3.indexOf("DESCRIPCION")).toString();
        (*Cadenas_Missing)->append(Literal);
        num++;
        if (num > 4) {
          if (NOPROCEDE.contains((*Cadenas_Missing)->at(4), Qt::CaseSensitive)){
              (*Cadenas_Missing)->removeAt(3);
              ok = true;
          }else
              (*Cadenas_Missing)->removeLast();
          num--;
          MemLogs->append("ERROR: " + tr("La tabla missing tiene más de 4 valores missing, se han tomado 4"));
          QApplication::processEvents();
          break;
        }
        if (NOPROCEDE.contains(Literal, Qt::CaseSensitive)) ok = true;
      }      
      if (!ok) {
          MemLogs->append("ERROR: " + tr("La tabla missing no tiene al menos el valor NO_PROCEDE ó No_Procede ó NoProcede (obligatorio)"));
          QApplication::processEvents();
          return false;
      }

      *Num_valores_missing = num;

      return true;
    }
    int TFrmPrincipal::size_tabla(QSqlQuery query) {
      int tot = 0;
      while (query.next()) {
        tot++;
      }
      return tot;
    }
    
    bool TFrmPrincipal::ChequearMicroDatosXML(QStringList *TablasMicroDatos, QString NombreBaseDatos, unsigned &NumRegistros,
    QStringList **VariablesTrabajo, QStringList **ListaIds, QTextEdit *MemLogs, QString Key, QString Nor, QString &Cota,
    QString CondicionLectura, QString NombreTablaMissing, int *Num_valores_missing, QStringList **Cadenas_Missing)
    {
      unsigned i;
      QString CadenaSQL;
      unsigned NumRegistros2;

      MemLogs->append(QMainWindow::tr("Realizando comprobaciones de microdatos"));
      QApplication::processEvents();

      NumRegistros = 0;
      QDomDocument *doc = new QDomDocument("?xml");
      QDomNode n;
      QDomElement e, e1;
      QDomNode n1;

      for (i = 0; i < (unsigned)TablasMicroDatos->count(); i++)
      {
        QFile file(NombreBaseDatos + TablasMicroDatos->at(i));

        if ((!file .open(QIODevice::ReadOnly)) || (!doc->setContent(&file)))
        {
          MemLogs->append("ERROR: " + QMainWindow::tr("No se pudo realizar satisfactoriamente la consulta sobre la base de datos") +  " [\"" + TablasMicroDatos->at(i) + "\"]");
          QApplication::processEvents();
          file.close();
          return false;
        }
        //MemLogs->append(QMainWindow::tr("Fichero xml cumple con el estandar W3C/XML"));

        QDomElement root = doc->documentElement();
        if (!root.tagName().contains("dataroot"))
         if (root.tagName() != "ROWSET")
         {
           MemLogs->append("ERROR: " + QMainWindow::tr("No se pudo realizar satisfactoriamente la consulta sobre la base de datos") +  " [\"" + TablasMicroDatos->at(i) + "\"]");
           QApplication::processEvents();
           file.close();
           return false;
         }
        //MemLogs->append(QMainWindow::tr("Leyendo fichero xml"));
        QApplication::processEvents();
        if (i == 0) {
          *VariablesTrabajo = new QStringList();

          *ListaIds = new QStringList();
        }

        n = root.firstChild();

        CadenaSQL = TablasMicroDatos->at(i);
        CadenaSQL.replace(".xml", "", Qt::CaseInsensitive);
        NumRegistros2 = 0;
        while (!n.isNull())
        {
          e = n.toElement();
          if (!e.isNull()) {
            if ((e.tagName() == CadenaSQL) || (e.tagName() == "ROW")) {
              if (i == 0) NumRegistros++;
              else NumRegistros2++;
              n1 = n.firstChild();
              while (!n1.isNull())
              {
                e1 = n1.toElement();
                if (!e1.isNull()) {
                  if ((NumRegistros == 1) || (NumRegistros2 == 1)) {
                    if ((e1.tagName() != Key) && (e1.tagName() != "ID")) {
                      if (!(*VariablesTrabajo)->contains(e1.tagName()))
                        (*VariablesTrabajo)->append(e1.tagName());
                      else
                      {
                        MemLogs->append("ERROR: " + QMainWindow::tr("Variable") + " " + e1.tagName() + " " + QMainWindow::tr("de la tabla") + " \"" + TablasMicroDatos->at(i) + "\" " + QApplication::translate("", "est\303\241 duplicada en algunos conjuntos de microdatos", 0));
                        QApplication::processEvents();
                        return false;
                      }
                    }
                  }
                  if (e1.tagName() == Key) {
                    if (i == 0)(*ListaIds)->append(e1.text());
                    else {
                      if (!(*ListaIds)->contains(e1.text()))
                      {
                        MemLogs->append("ERROR: " + QMainWindow::tr("Los identificadores de la tabla") + " \"" + TablasMicroDatos->at(i) + "\" " + QMainWindow::tr("son incoherentes"));
                        QApplication::processEvents();
                        return false;
                      }
                    }
                  }
                }
                n1 = n1.nextSibling();
              }
            }
          }
          n = n.nextSibling();
        }
        if ((i != 0) && (NumRegistros2 != NumRegistros))
        {          
          MemLogs->append("ERROR: " + QApplication::translate("", "El tama\303\261o de la tabla", 0) + " \"" + TablasMicroDatos->at(i) + "\" " + QMainWindow::tr("es incorrecto: ") + QString::number(NumRegistros2));
          QApplication::processEvents();
          return false;
        }
      }

      //Tomar los valores missing
      QFile file(NombreBaseDatos + NombreTablaMissing);

      if ((!file .open(QIODevice::ReadOnly)) || (!doc->setContent(&file)))
      {
          MemLogs->append("ERROR: " + QMainWindow::tr("No se pudo realizar satisfactoriamente la consulta sobre ") +  " [\"" + NombreTablaMissing + "\"]");
          QApplication::processEvents();
          file.close();
          return false;
      }
      QDomElement root = doc->documentElement();
      if (!root.tagName().contains("dataroot"))
      if (root.tagName() != "ROWSET")
      {
           MemLogs->append("ERROR: " + QMainWindow::tr("No se pudo realizar satisfactoriamente la consulta sobre") +  " [\"" + NombreTablaMissing + "\"]");
           QApplication::processEvents();
           file.close();
           return false;
      }
      int num = 0;
      QString Literal;
      bool ok = false;
      *Cadenas_Missing = new QStringList();
      n = root.firstChild();

      CadenaSQL = NombreTablaMissing;
      CadenaSQL.replace(".xml", "", Qt::CaseInsensitive);
      while ((!n.isNull()) && (num <= 4))
      {
         e = n.toElement();
         if (!e.isNull()) {
           if ((e.tagName() == CadenaSQL) || (e.tagName() == "ROW")) {
             n1 = n.firstChild();
             while (!n1.isNull())
             {
               e1 = n1.toElement();
               if (!e1.isNull()) {
                 if (e1.tagName() == "DESCRIPCION") {
                   Literal = e1.text();
                   (*Cadenas_Missing)->append(Literal);
                   num++;
                   if (num > 4) {
                     if (NOPROCEDE.contains((*Cadenas_Missing)->at(4), Qt::CaseSensitive)){
                         (*Cadenas_Missing)->removeAt(3);
                         ok = true;
                     }else
                         (*Cadenas_Missing)->removeLast();
                     num--;
                     MemLogs->append("ERROR: " + tr("La tabla missing tiene más de 4 valores missing, se han tomado los 4 primeros"));
                     QApplication::processEvents();
                     break;
                   }
                   if (NOPROCEDE.contains(Literal)) ok = true;
                 }
               }
               n1 = n1.nextSibling();
             }
           }
        }
        n = n.nextSibling();
      }
      delete doc;
      if (!ok) {
          MemLogs->append("ERROR: " + tr("La tabla missing no tiene al menos el valor NO_PROCEDE ó No_Procede ó NoProcede (obligatorio)", 0));
          QApplication::processEvents();
          return false;
      }

      *Num_valores_missing = num;

      return true;
    }
 /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
 // Libera conjunto de datos.
 /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void TFrmPrincipal::LiberarConjuntosDatos()
    {
      if (DatosCargados) {        
        if (!FmeVariables->isHidden()) FmeVariables->hide();
        delete FmeVariables;        
        if (!FmeMicroDatos->isHidden()) FmeMicroDatos->hide();
        delete FmeMicroDatos;        
        if (!FmeEdits->isHidden()) FmeEdits->hide();
        delete FmeEdits;       
        if (!FrmIrAVariable->isHidden()) FrmIrAVariable->hide();
        delete FrmIrAVariable;       
        if (!FrmCheckPoblacion->isHidden()) FrmCheckPoblacion->hide();
        delete FrmCheckPoblacion;       
        if (!FrmCambiarMicrodato->isHidden()) FrmCambiarMicrodato->hide();
        delete FrmCambiarMicrodato;
        if (!FrmOpciones->isHidden()) FrmOpciones->hide();
        delete FrmOpciones;        
      }
   }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Acciones a realizar segun lo que pulsemos en el menu principal.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

   void TFrmPrincipal::ButAceptarOracle()
   {
      datorac->hide();
      continuarCargaMetafile(FrmAbrirMetafile->GetNombreMetafile(), datorac->getNomBaseDatos());
   }

   void TFrmPrincipal::ButCancelarOracle()
   {
      datorac->hide();
   }

   void TFrmPrincipal::ButAceptarMetafileClick()
   {
      if (FrmAbrirMetafile->GetNombreMetafile() == "")
        QMessageBox::warning(FrmAbrirMetafile, "Warning",  QApplication::translate("", "No ha introducido ning\303\272n fichero", 0), "&Ok");
      else {
        if (FrmAbrirMetafile->MetafileCorrrecto())
        {
          Oracle = false;
          FrmAbrirMetafile->hide();
          AbrirUnMetafile(FrmAbrirMetafile->GetNombreMetafile());
        }
      }
   }

   void TFrmPrincipal::MitAbrirMetafileClick()
   {
     FrmAbrirMetafile = new TFrmAbrirMetafile(this, "abrirmetafile", Qt::Window);
     FrmAbrirMetafile->show();
   }

   void TFrmPrincipal::MitSalirClick()
   {
    //cerrar base de datos
    if (conexion) AdcConexionBD.close();    
    LiberarConjuntosDatos();
    disconnect(PctContenedorPrincipal, SIGNAL(currentChanged ( int ) ), 0, 0);
    PctContenedorPrincipal->clear();
    if (!PctContenedorPrincipal->isHidden()) PctContenedorPrincipal->hide();
    QApplication::exit();
   }

   void TFrmPrincipal::MitCerrarMetafileClick()
   {
    extern bool botonCancelar;
    botonCancelar = false;
    extern QString cadena;
    cadena = "";
    extern bool mens1;
    mens1 = true;
    if (conexion) AdcConexionBD.close();  //cerrar base de datos o conexion

    MitCerrarMetafile->setEnabled(false);
    MitAbrirMetafile->setEnabled(true);
    MitProcederPasoAPaso->setEnabled(false);
    MitProcederCompleto->setEnabled(false);
    MitOpciones->setEnabled(false);
    MitCheckPoblacion->setEnabled(false);

    switch (Fase)
    {
      case FASE_INICIAL: break;
      case FASE_RANGOS:  delete FmeVariables->GetVisualizarVar();
                         delete FmeMicroDatos->GetVisualizarReg();
                         delete FmeEdits->GetVisualizarEd();
                         delete FmeRangos->GetVisualizarReg();
                         break;
      case FASE_TEST: delete FmeVariables->GetVisualizarVar();
                      delete FmeMicroDatos->GetVisualizarReg();
                      delete FmeEdits->GetVisualizarEd();
                      delete FmeRangos->GetVisualizarReg();
                      delete FmeTest->GetVisualizarReg();
                      break;
      case FASE_IMPUTACION: delete FmeVariables->GetVisualizarVar();
                            delete FmeMicroDatos->GetVisualizarReg();
                            delete FmeEdits->GetVisualizarEd();
                            delete FmeRangos->GetVisualizarReg();
                            delete FmeTest->GetVisualizarReg();
                            delete FmeImputacion->GetVisualizarReg();
                            break;
      case FASE_ESTADISTICAS: delete FmeVariables->GetVisualizarVar();
                              delete FmeMicroDatos->GetVisualizarReg();
                              delete FmeEdits->GetVisualizarEd();
                              delete FmeRangos->GetVisualizarReg();
                              delete FmeTest->GetVisualizarReg();
                              delete FmeImputacion->GetVisualizarReg();
                              break;
      default : break;
    }    
    LiberarConjuntosDatos();
    disconnect(PctContenedorPrincipal, SIGNAL(currentChanged ( int ) ), 0, 0);
    PctContenedorPrincipal->clear();
    if (!PctContenedorPrincipal->isHidden()) PctContenedorPrincipal->hide();
    DatosCargados = false;
    scrollarea->actualizartitulo(QMainWindow::tr(QString(TITULOAPP + EXTRATITULO).toLatin1(), ""));    
   }

   void TFrmPrincipal::MitNuevoMetafileClick()
   {
     TFrmNuevoMetafile *FrmNuevoMetafile = new TFrmNuevoMetafile(this, "nuevometafile", Qt::Window);
     FrmNuevoMetafile->show();
   }

   void TFrmPrincipal::MitAccesstoXMLClick()
   {
    QString start = QCoreApplication::applicationDirPath();
    QString meta = QDir::toNativeSeparators("/metafiles");

    QString NombreMetafile = QFileDialog::getOpenFileName(this, QMainWindow::tr("Abrir fichero metafile"), start+meta, "VME (*.vme)");
    ficheroXML fx;
    if (!NombreMetafile.isEmpty()) {
      fx.crearXML (NombreMetafile, this);
    }
   }
   void TFrmPrincipal::MitXMLtoAccessClick()
   {  }

   void TFrmPrincipal::MitProcederPasoAPasoClick()
   {
    switch (Fase)
    {
      case FASE_INICIAL:        
        FmeRangos->PanContenedor->hide();
        PctContenedorPrincipal->addTab(VentanaRangos, QMainWindow::tr("EVAL. RANGOS Y FILTROS"));
        PctContenedorPrincipal->setCurrentWidget(VentanaRangos);        
	    FmeRangos->ValidarRangos();        
        Fase = TTipoFase(Fase + 1);
	    break;
      case FASE_RANGOS:
	if (FmeEdits->EditsValidados())
	{
 	  FmeTest->PrepararInterface();	// problema de los edits nuevos
	  FmeTest->PanContenedor->hide();
          PctContenedorPrincipal->addTab(VentanaTest, tr("EVAL. DE OTRAS REGLAS"));
          PctContenedorPrincipal->setCurrentWidget(VentanaTest);
          FmeTest->TestearMicroDatos();          
	  Fase = TTipoFase(Fase + 1);
	}
	else
          QMessageBox::information(this, QApplication::translate("", "Informaci\303\263n", 0),  QMainWindow::tr("Existen reglas no validadas\nCorrija las reglas e intentelo de nuevo"), "&Ok");
        break;
      case FASE_TEST:
        FmeImputacion->SetPermImputacManual(true);
	FmeImputacion->FijarCantidadDatos();	// problema de los edits nuevos
	FmeImputacion->PanContenedor->hide();
	PctContenedorPrincipal->addTab(VentanaImputacion, QMainWindow::tr("IMPUTACION"));
        PctContenedorPrincipal->setCurrentWidget(VentanaImputacion);	
	FmeImputacion->ImputarMicroDatosRegistroDonante();
	Fase = TTipoFase(Fase + 1);
	break;
      case FASE_IMPUTACION:
	FmeEstadisticas->FijarCantidadDatos();	// problema de los edits nuevos
	FmeEstadisticas->PanContenedor->hide();
        PctContenedorPrincipal->addTab(VentanaEstadisticas, QMainWindow::tr("ESTADISTICAS"));
        PctContenedorPrincipal->setCurrentWidget(VentanaEstadisticas);
	
        FmeEstadisticas->GenerarEstadisticas(FrmOpciones->GetMetodoInformeResumido());
        Fase = TTipoFase(Fase + 1);
	MitProcederPasoAPaso->setEnabled(false);
	MitProcederCompleto->setEnabled(false);
	FmeImputacion->GetButCambiarRegistroDonante()->hide();
        FmeImputacion->SetPermImputacManual(false);
        break;
      case FASE_ESTADISTICAS:
        QMessageBox::information(this, QApplication::translate("", "Informaci\303\263n", 0),  QApplication::translate("", "Se ha llegado al final del proceso de edici\303\263n e imputaci\303\263n\nGuarde los datos en la ventana de imputaci\303\263n\nGuarde el informe en la ventana de estad\303\255sticas\n\nTambi\303\251n puede cerrar este metafile para cargar uno nuevo y trabajar sobre \303\251l", 0), "&Ok");
        break;
      default:
	break;
    }
   }

   void TFrmPrincipal::MitAcercaDeClick()
   {
    QMessageBox::about(this, QMainWindow::tr( "Acerca de Teide2" ),
                       QApplication::translate("",  "<center><p><h1>Programa para depurar encuestas.</h1></p><p>M Salom\303\251 Hern\303\241ndez Garc\303\255a y Juan Jos\303\251 Salazar Gonz\303\241lez.</p><p>Versi\303\263n 2.0. / " , 0) + QString::number(DAY, 10) + " " + mes.at(MONTH) + " " + QString::number(YEAR, 10) + QApplication::translate("", ".</p><p>Universidad de La Laguna.</p><p>Uso de las herramientas:</p><p>  Qt  http://www.qtsoftware.com/</p><p>  Qwt  http://qwt.sourceforge.net/</p></center>" , 0) );
   }
  
   void TFrmPrincipal::MitOpcionesClick()
   {
     FrmOpciones->show();
   }

   void TFrmPrincipal::MitAyudaTEIDE2Click()
   {
     QString start = QCoreApplication::applicationDirPath() + "/doc/help/Ayuda.html";
     QDesktopServices::openUrl(QUrl::fromLocalFile(start));
   }

   void TFrmPrincipal::MitProcederCompletoClick()
   {
    TTipoFase i;
    if (!BatchMode)
    {
      if (QMessageBox::information(this, QApplication::translate("", "Informaci\303\263n", 0),  QApplication::translate("", "Va a proceder a realizar el proceso completo de edici\303\263n e imputaci\303\263n\n\302\277Est\303\241 seguro que desea continuar?", 0), QMessageBox::Ok | QMessageBox::Cancel, QMessageBox::Ok) == QMessageBox::Ok) {
        for (i = Fase; i < FASE_ESTADISTICAS; i = (TTipoFase)(i+1))
          MitProcederPasoAPasoClick();
      }
    }else {
      for (i = Fase; i < FASE_ESTADISTICAS; i = (TTipoFase)(i+1))
        MitProcederPasoAPasoClick();
    }
   }

   void TFrmPrincipal::MitCheckPoblacionClick()
   {     
     FrmCheckPoblacion->inicio();
   }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Hace un batch.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
   void TFrmPrincipal::HacerBatchMode()
   {
      AbrirUnMetafile(QDir::toNativeSeparators(QCoreApplication::applicationDirPath()+"/metafiles/"+nomMet));
      if (DatosCargados) MitProcederCompletoClick();
   }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Controla lo de visualizar cada vez se cambia de solapa.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
   void TFrmPrincipal::CambiarSolapa ( int index )
   {
      FmeVariables->GetVisualizarVar()->show();

      if (index == 0)
      {
        FmeVariables->GetVisualizarVar()->show();
		FmeMicroDatos->GetVisualizarReg()->hide();
		FmeEdits->GetVisualizarEd()->hide();
        FmeRangos->GetVisualizarReg()->hide();
        FmeTest->GetVisualizarReg()->hide();
        FmeImputacion->GetVisualizarReg()->hide();
      }else
          if (index == 1)
          {
             FmeMicroDatos->GetVisualizarReg()->show();
             FmeVariables->GetVisualizarVar()->hide();			 
			 FmeEdits->GetVisualizarEd()->hide();
             FmeRangos->GetVisualizarReg()->hide();
             FmeTest->GetVisualizarReg()->hide();
             FmeImputacion->GetVisualizarReg()->hide();
          }else
            if (index == 2)
            {                
                FmeVariables->GetVisualizarVar()->hide();
				FmeMicroDatos->GetVisualizarReg()->hide();                
                FmeEdits->GetVisualizarEd()->show();
				FmeRangos->GetVisualizarReg()->hide();
				FmeTest->GetVisualizarReg()->hide();
				FmeImputacion->GetVisualizarReg()->hide();
            }else
                if (index == 3)
                {
                    FmeRangos->GetVisualizarReg()->show();
                    FmeVariables->GetVisualizarVar()->hide();
					FmeMicroDatos->GetVisualizarReg()->hide();
					FmeEdits->GetVisualizarEd()->hide();					
					FmeTest->GetVisualizarReg()->hide();
					FmeImputacion->GetVisualizarReg()->hide();
                }else
                    if (index == 4)
                    {
                        FmeTest->GetVisualizarReg()->show();
						FmeVariables->GetVisualizarVar()->hide();
						FmeMicroDatos->GetVisualizarReg()->hide();
						FmeEdits->GetVisualizarEd()->hide();
						FmeRangos->GetVisualizarReg()->hide();						
						FmeImputacion->GetVisualizarReg()->hide();
                    }else
                        if (index == 5)
                        {
                            FmeImputacion->GetVisualizarReg()->show();
                            FmeVariables->GetVisualizarVar()->hide();
							FmeMicroDatos->GetVisualizarReg()->hide();
							FmeEdits->GetVisualizarEd()->hide();
							FmeRangos->GetVisualizarReg()->hide();
							FmeTest->GetVisualizarReg()->hide();							
                        }else
                        {
                            FmeVariables->GetVisualizarVar()->hide();
							FmeMicroDatos->GetVisualizarReg()->hide();
							FmeEdits->GetVisualizarEd()->hide();
							FmeRangos->GetVisualizarReg()->hide();
							FmeTest->GetVisualizarReg()->hide();
							FmeImputacion->GetVisualizarReg()->hide();
                        }
   }
