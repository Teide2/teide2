/*******************************************************************************
** Edits.cpp: contiene todo lo necesario para trabajar con la solapa Reglas.
**
** author: M-S Hernández-García
*******************************************************************************/

#include "Edits.h"


TFmeEdits::TFmeEdits(QWidget* parent, const char* name, Qt::WindowFlags fl, QSqlDatabase *AdcConexionBD, QString NombreTabla, TFmeMicroDatos *FmeMicroDatosAsociados, bool Xml, QString NombreBaseDatos, bool *correcto, bool excel, QTabWidget *PctContenedorPrincipal):QWidget(parent, fl)
    {
      unsigned i;

      QString CadenaSQL, s;

      setGeometry(0, 0, parent->width()-2, parent->height()-15);

      if (this->objectName().isEmpty())
        this->setObjectName(("TFmeEdits"));

      QFont font;
      font.setFamily(("Tahoma"));
      this->setFont(font);
      PanContenedor = new QFrame(this);
      PanContenedor->setObjectName(("PanContenedor"));
      PanContenedor->setGeometry(QRect(0, 0, this->width(), this->height()-50));
      PanContenedor->setFrameShape(QFrame::Panel);
      PanContenedor->setFrameShadow(QFrame::Raised);
      VisualizarEd = new QComboBox(PctContenedorPrincipal);
      VisualizarEd->setGeometry(PanContenedor->width()-220, 0, 200, 25);
      SbrBarraEstado = new QFrame(PanContenedor);
      SbrBarraEstado->setObjectName(("SbrBarraEstado"));
      SbrBarraEstado->setGeometry(QRect(1, PanContenedor->height()-2-22, PanContenedor->width()-1, 22));
      SbrBarraEstado->setFrameShape(QFrame::Panel);
      SbrBarraEstado->setFrameShadow(QFrame::Raised);
      SbrBarraEstado1 = new QFrame(SbrBarraEstado);
      SbrBarraEstado1->setObjectName(("SbrBarraEstado1"));
      SbrBarraEstado1->setGeometry(QRect(0, 0, SbrBarraEstado->width()/2, 19));
      SbrBarraEstado1->setFrameShape(QFrame::Box);
      SbrBarraEstado1->setFrameShadow(QFrame::Raised);
      LabBarraEstado1 = new QLabel(SbrBarraEstado1);
      LabBarraEstado1->setObjectName(("LabBarraEstado1"));
      LabBarraEstado1->setGeometry(QRect(3, 0, SbrBarraEstado1->width(), 19));
      SbrBarraEstado2 = new QFrame(SbrBarraEstado);
      SbrBarraEstado2->setObjectName(("SbrBarraEstado2"));
      SbrBarraEstado2->setGeometry(QRect(SbrBarraEstado1->width()+1, 0, SbrBarraEstado1->width()-1, 19));
      SbrBarraEstado2->setFrameShape(QFrame::Box);
      SbrBarraEstado2->setFrameShadow(QFrame::Raised);
      LabBarraEstado2 = new QLabel(SbrBarraEstado2);
      LabBarraEstado2->setObjectName(("LabBarraEstado2"));
      LabBarraEstado2->setGeometry(QRect(3, 0, SbrBarraEstado2->width(), 19));
      PanVariables = new QFrame(PanContenedor);
      PanVariables->setObjectName(("PanVariables"));
      PanVariables->setGeometry(QRect(1, PanContenedor->height()-2-24-30, PanContenedor->width()-1, 30));
      PanVariables->setFrameShape(QFrame::Box);
      PanVariables->setFrameShadow(QFrame::Raised);
      LabVariable = new QLabel(PanVariables);
      LabVariable->setObjectName(("LabVariable"));
      LabVariable->setGeometry(QRect(8, 5, 31, 16));
      LabEdit = new QLabel(PanVariables);
      LabEdit->setObjectName(("LabEdit"));
      LabEdit->setGeometry(QRect(480, 5, 35, 16));
      LabOperadores = new QLabel(PanVariables);
      LabOperadores->setObjectName(("LabOperadores"));
      LabOperadores->setGeometry(QRect(150, 5, 38, 16));
      CbxVariables = new QComboBox(PanVariables);
      CbxVariables->setObjectName(("CbxVariables"));
      CbxVariables->setGeometry(QRect(35, 4, 109, 22));
      CbxVariables->setEditable(true);
      LabMissing = new QLabel(PanVariables);
      LabMissing->setObjectName(("LabMissing"));
      LabMissing->setGeometry(QRect(295, 5, 45, 16));
      CbxMissing = new QComboBox(PanVariables);
      CbxMissing->setObjectName(("CbxMissing"));
      CbxMissing->setGeometry(QRect(340, 4, 129, 22));
      EdtEdit = new QLineEdit(PanVariables);
      EdtEdit->setObjectName(("EdtEdit"));
      EdtEdit->setGeometry(QRect(525, 4, 415, 22));
      CbxOperadores = new QComboBox(PanVariables);
      CbxOperadores->setObjectName(("CbxOperadores"));
      CbxOperadores->setGeometry(QRect(185, 4, 65, 22));
      CbxOperadores->setSizeAdjustPolicy(QComboBox::AdjustToContents);
      ButModificarEdit = new QPushButton(PanVariables);
      ButModificarEdit->setObjectName(("ButModificarEdit"));
      ButModificarEdit->setGeometry(QRect(943, 8, 49, 17));
      ButInsertarEdit = new QPushButton(PanVariables);
      ButInsertarEdit->setObjectName(("ButInsertarEdit"));
      ButInsertarEdit->setGeometry(QRect(994, 8, 49, 17));
      ButBorrarEdit = new QPushButton(PanVariables);
      ButBorrarEdit->setObjectName(("ButBorrarEdit"));
      ButBorrarEdit->setGeometry(QRect(1045, 8, 49, 17));
      PanValidarEdit = new QFrame(PanContenedor);
      PanValidarEdit->setObjectName(("PanValidarEdit"));
      PanValidarEdit->setGeometry(QRect(1, PanContenedor->height()-2-56-30, PanContenedor->width()-1, 30));
      PanValidarEdit->setFrameShape(QFrame::Box);
      PanValidarEdit->setFrameShadow(QFrame::Raised);
      LabValidacionSintactica = new QLabel(PanValidarEdit);
      LabValidacionSintactica->setObjectName(("LabValidacionSintactica"));
      LabValidacionSintactica->setGeometry(QRect(8, 8, 132, 18));
      ImgValidacionSintactica = new QPushButton(PanValidarEdit);
      ImgValidacionSintactica->setObjectName(("ImgValidacionSintactica"));
      ImgValidacionSintactica->setGeometry(QRect(125, 5, 28, 24));
      ImgValidacionSintactica->setIcon(QIcon(("images/right.bmp")));
      LabValidacionLexica = new QLabel(PanValidarEdit);
      LabValidacionLexica->setObjectName(("LabValidacionLexica"));
      LabValidacionLexica->setGeometry(QRect(170, 8, 111, 18));
      ImgValidacionLexica = new QPushButton(PanValidarEdit);
      ImgValidacionLexica->setObjectName(("ImgValidacionLexica"));
      ImgValidacionLexica->setGeometry(QRect(267, 5, 28, 24));
      ImgValidacionLexica->setIcon(QIcon(("images/right.bmp")));
      LabIrA = new QLabel(PanValidarEdit);
      LabIrA->setObjectName(("LabIrA"));
      LabIrA->setGeometry(QRect(750, 9, 43, 16));
      LabFiltro = new QLabel(PanValidarEdit);
      LabFiltro->setObjectName(("LabFiltro"));
      LabFiltro->setGeometry(QRect(300, 9, 101, 16));
      EdtIrA = new QLineEdit(PanValidarEdit);
      EdtIrA->setObjectName(("EdtIrA"));
      EdtIrA->setGeometry(QRect(790, 6, 33, 21));
      ButSigEditMal = new QPushButton(PanValidarEdit);
      ButSigEditMal->setObjectName(("ButSigEditMal"));
      ButSigEditMal->setGeometry(QRect(536, 6, 201, 21));
      EdtFiltro = new QLineEdit(PanValidarEdit);
      EdtFiltro->setObjectName(("EdtFiltro"));
      EdtFiltro->setGeometry(QRect(396, 6, 121, 21));

      view2 = new MiTabla(PanContenedor);
      view2->setGeometry(QRect(1, PanContenedor->height()-2-88-65, PanContenedor->width()-1, 65));
      view = new MiTabla(PanContenedor);
      view->setGeometry(QRect(1, 0, PanContenedor->width()-1, view2->y()-2));

      this->setWindowTitle( "Form");
      LabBarraEstado1->setText("");
      LabBarraEstado2->setText("");
      LabVariable->setText("Var.");
      LabMissing->setText("Missing");
      LabEdit->setText("Regla");
      LabOperadores->setText("Oper.");
      CbxVariables->setToolTip(QApplication::translate("TFmeEdits", "Listado de variables del conjunto de microdatos actual."));
      CbxOperadores->clear();
      CbxOperadores->insertItems(0, QStringList()
       << "<"
       << ">"
       << "<="
       << ">="
       << "!="
       << "<>"
       << "="
       << "Y"
       << "AND"
       << "O"
       << "OR"
       << "XOR"
       << "NO"
       << "NOT"
       << "SI"
       << "IF"
       << "ENTONCES"
       << "THEN"
       << "SI Y SOLO SI"
       << "IFF"
       << "+"
       << "-"
       << "/"
       << "*"
       << "("
       << ")"
       << "|"
       << "&"
       << "!"
       << "%"
      );
      CbxOperadores->setToolTip(QApplication::translate("TFmeEdits", "Listado de posibles operadores y elementos l\303\251xicos", 0, QApplication::UnicodeUTF8));
      CbxMissing->setToolTip(QApplication::translate("TFmeEdits", "Listado de los valores missing"));
      ButModificarEdit->setToolTip(QApplication::translate("TFmeEdits", "Pulse aqu\303\255 para modificar la regla actual", 0, QApplication::UnicodeUTF8));
      ButModificarEdit->setText(QApplication::translate("TFmeEdits", "MOD."));
      ButInsertarEdit->setToolTip(QApplication::translate("TFmeEdits", "Pulse aqu\303\255 para insertar una nueva regla", 0, QApplication::UnicodeUTF8));
      ButInsertarEdit->setText(QApplication::translate("TFmeEdits", "INS."));
      ButBorrarEdit->setToolTip(QApplication::translate("TFmeEdits", "Pulse aqu\303\255 para borrar la regla actual", 0, QApplication::UnicodeUTF8));
      ButBorrarEdit->setText(QApplication::translate("TFmeEdits", "BOR."));
      PanValidarEdit->setToolTip(QApplication::translate("TFmeEdits", "Informaci\303\263n sobre la validaci\303\263n de la regla actual.", 0, QApplication::UnicodeUTF8));
      LabValidacionSintactica->setText(QApplication::translate("TFmeEdits", "Validaci\303\263n sint\303\241ctica", 0, QApplication::UnicodeUTF8));
      ImgValidacionSintactica->setToolTip(QApplication::translate("TFmeEdits", "Validaci\303\263n sint\303\241ctica. En verde es correcta y en rojo hay errores.Pulse para ver el error", 0, QApplication::UnicodeUTF8));
      ImgValidacionSintactica->setText(QString());
      LabValidacionLexica->setText(QApplication::translate("TFmeEdits", "Validaci\303\263n l\303\251xica", 0, QApplication::UnicodeUTF8));
      ImgValidacionLexica->setToolTip(QApplication::translate("TFmeEdits", "Validaci\303\263n l\303\251xica. En verde es correcta y en rojo hay errores.Pulse para ver el error", 0, QApplication::UnicodeUTF8));
      ImgValidacionLexica->setText(QString());
      LabIrA->setText(QApplication::translate("TFmeEdits", "Ir a ..."));
      LabFiltro->setText(QApplication::translate("TFmeEdits", "Filtrar reglas ..."));
      EdtIrA->setToolTip(QApplication::translate("TFmeEdits", "Indique un n\303\272mero de regla y pulse ENTER parar ir a ella.", 0, QApplication::UnicodeUTF8));
      ButSigEditMal->setToolTip(QApplication::translate("TFmeEdits", "Pulse aqu\303\255 para ir a la siguiente regla incorrecta de la lista.", 0, QApplication::UnicodeUTF8));
      ButSigEditMal->setText(QApplication::translate("TFmeEdits", "Ir a la siguiente Regla incorrecta"));
      EdtFiltro->setToolTip(QApplication::translate("TFmeEdits", "Indique la variable y pulse ENTER para filtrar las reglas."));
      view->setToolTip(QApplication::translate("TFmeEdits", "Rejilla de visualizaci\303\263n de reglas.", 0, QApplication::UnicodeUTF8));
      view2->setToolTip(QApplication::translate("TFmeEdits", "Informaci\303\263n de la variable activa.", 0, QApplication::UnicodeUTF8));
      EdtEdit->setToolTip(QApplication::translate("TFmeEdits", "Editor de Reglas"));
      VisualizarEd->setToolTip(QApplication::translate("TFmeEdits", "Seleccione el modo de vizualizaci\303\263n de las reglas.", 0, QApplication::UnicodeUTF8));
      VisualizarEd->addItem(QApplication::translate("TFmeEdits", "Visualizar todas", 0, QApplication::UnicodeUTF8));
      VisualizarEd->addItem(QApplication::translate("TFmeEdits", "Visualizar reglas correctas", 0, QApplication::UnicodeUTF8));
      VisualizarEd->addItem(QApplication::translate("TFmeEdits", "Visualizar reglas incorrectas", 0, QApplication::UnicodeUTF8));

      connect(CbxVariables, SIGNAL(activated ( const QString & )), this, SLOT(CbxVariablesCloseUp(const QString &)));
      connect(EdtEdit, SIGNAL(returnPressed()), this, SLOT(EdtEditEnter()));
      connect(CbxOperadores, SIGNAL(activated ( const QString & )), this, SLOT(CbxOperadoresCloseUp(const QString &)));
      connect(CbxMissing, SIGNAL(activated ( const QString & )), this, SLOT(CbxMissingCloseUp(const QString &)));
      connect(ButModificarEdit, SIGNAL(clicked()), this, SLOT(ButModificarEditClick()));
      connect(ButInsertarEdit, SIGNAL(clicked()), this, SLOT(ButInsertarEditClick()));
      connect(ButBorrarEdit, SIGNAL(clicked()), this, SLOT(ButBorrarEditClick()));
      connect(EdtIrA, SIGNAL(returnPressed()), this, SLOT(EdtIrAKeyDown()));
      connect(ButSigEditMal, SIGNAL(clicked()), this, SLOT(ButSigEditMalClick()));
      connect(EdtFiltro, SIGNAL(returnPressed()), this, SLOT(EdtFiltroKeyDown()));
      connect(view, SIGNAL(clicked(const QModelIndex&)), this, SLOT(SgrRejillaSelectCell(const QModelIndex&)));
      connect(view->verticalHeader(), SIGNAL(sectionClicked ( const int & )), this, SLOT(SgrRejillaSelectCellV(const int &)));
      connect(ImgValidacionSintactica, SIGNAL(clicked()), this, SLOT(ButValidacionSintacticaClick()));
      connect(ImgValidacionLexica, SIGNAL(clicked()), this, SLOT(ButValidacionLexicaClick()));
	  connect(VisualizarEd, SIGNAL(activated ( const int & ) ), this, SLOT(VisualizarEdCloseUp(const int &)));
      // Asociar las clases
      AsociarClases(FmeMicroDatosAsociados);

      // Fijamos un nombre
      this->Name = "FmeEdits" + NombreTabla;

      // Fijamos el nombre de la tabla
      this->NombreTabla = NombreTabla;
      this->NombreBaseDatos = NombreBaseDatos;
      this->Xml = Xml;
      this->Excel = excel;
      // Conexión a la base de MicroDatos
      AdqConsulta = AdcConexionBD;
      query2 = new QSqlQuery(QString::null, *AdcConexionBD);

      // Creación de la cadena de atributos para la consulta SQL
      for (i = 0; i < (NUM_ATRIBUTOS_EDIT - 1); i++)
        VariablesALeer = VariablesALeer + ATRIBUTOS_EDIT[i] + ", ";
      VariablesALeer = VariablesALeer + ATRIBUTOS_EDIT[NUM_ATRIBUTOS_EDIT - 1];

      // Consulta de Edits
      MemLogs->append(tr("Cargando reglas de la tabla") + " \"" + NombreTabla + "\"");
      QApplication::processEvents();
      if (Xml) {
        QDomDocument *doc = new QDomDocument("?xml");
        QDomNode n;
        QDomElement e, e1;
        QDomNode n1;

        QFile file(QDir::convertSeparators(NombreBaseDatos + NombreTabla));

        if ((!file .open(QIODevice::ReadOnly)) || (!doc->setContent(&file)))
        {
            MemLogs->append("ERROR: " + tr("No se pudo realizar satisfactoriamente la consulta sobre la base de datos") +  " [\"" + NombreTabla + "\"]");
            QApplication::processEvents();
            file.close();
            *correcto = false;
            return;
        }
      }else {
        CadenaSQL = "SELECT " + VariablesALeer + ", ID FROM " + NombreTabla + " ORDER BY ID";
        QSqlQuery query(CadenaSQL, *AdqConsulta);
        if (!query.isActive()) {
          MemLogs->append("ERROR: " + tr("No se pudo realizar la consulta ") + CadenaSQL);
          QApplication::processEvents();
          *correcto = false;
          return;
        }
      }
      // Fijar la cantidad de datos
      FijarCantidadDatos();

      // Cargar las variables y missing en la lista de selección
      CargarVariablesEnLista();
      CargarMissingEnLista();

      // Cargar los edits en la rejilla
      CargarEditsEnRejilla();

      model = new TablaModelE(0, MatrizEditsS, listaH, listaV);
      view->setModel(model);
      FijarAnchoColumnasRejilla();

      // Creación del vector de información de edits
      VectorInfoEdits = new TInfoEdits[NumEdits + MAX_EDITS];

      // Iconos de validación
      IconoBien = RUTA_ICONO_BIEN;
      IconoMal = RUTA_ICONO_MAL;

      // Validar los edits
      MemLogs->append(tr("Validando reglas de la tabla") + " \"" + NombreTabla + "\"");
      QApplication::processEvents();
      ValidarEdits();

      // Inicializar la rejilla de Variables
      InicializarRejillaVariable();
      model2 = new TablaModelInfo(0, VectorDatosS, listaH2, listaV2);
      view2->setModel(model2);      
      view2->verticalHeader()->setDefaultSectionSize(20);

      ActualizarInformacionVariable(0);

      // Crear el vector de pertenencia de edits
      CrearVectorPertenenciaEdits();

      // Cargar el vector de edits warning
      CargarVectorEditsWarning();

      MostrarInfoAsociada(0, 0, true);
      EscribirInformacion();
      *correcto = true;
    }
/*void TFmeEdits::updateGeometry ()
{
    this->setGeometry(0, 0, parentWidget()->width()-2, parentWidget()->height()-15);

    PanContenedor->setGeometry(QRect(0, 0, this->width(), this->height()-50));

    VisualizarEd->setGeometry(PanContenedor->width()-220, 0, 200, 25);

    view2->setGeometry(QRect(1, PanContenedor->height()-2-88-65, PanContenedor->width()-1, 65));

    view->setGeometry(QRect(1, 0, PanContenedor->width()-1, view2->y()-2));

    SbrBarraEstado->setGeometry(QRect(1, PanContenedor->height()-2-22, PanContenedor->width()-1, 22));

    SbrBarraEstado1->setGeometry(QRect(0, 0, SbrBarraEstado->width()/2, 19));

    LabBarraEstado1->setGeometry(QRect(3, 0, SbrBarraEstado1->width(), 19));

    SbrBarraEstado2->setGeometry(QRect(SbrBarraEstado1->width()+1, 0, SbrBarraEstado1->width()-1, 19));

    LabBarraEstado2->setGeometry(QRect(3, 0, SbrBarraEstado2->width(), 19));

    PanVariables->setGeometry(QRect(1, PanContenedor->height()-2-24-30, PanContenedor->width()-1, 30));

    PanValidarEdit->setGeometry(QRect(1, PanContenedor->height()-2-56-30, PanContenedor->width()-1, 30));

}*/
void TFmeEdits::ajustarSize ()
{
    this->setGeometry(0, 0, parentWidget()->width()-2, parentWidget()->height()-15);

    PanContenedor->setGeometry(QRect(0, 0, this->width(), this->height()-50));

    VisualizarEd->setGeometry(PanContenedor->width()-220, 0, 200, 25);

    view2->setGeometry(QRect(1, PanContenedor->height()-2-88-65, PanContenedor->width()-1, 65));

    view->setGeometry(QRect(1, 0, PanContenedor->width()-1, view2->y()-2));

    SbrBarraEstado->setGeometry(QRect(1, PanContenedor->height()-2-22, PanContenedor->width()-1, 22));

    SbrBarraEstado1->setGeometry(QRect(0, 0, SbrBarraEstado->width()/2, 19));

    LabBarraEstado1->setGeometry(QRect(3, 0, SbrBarraEstado1->width(), 19));

    SbrBarraEstado2->setGeometry(QRect(SbrBarraEstado1->width()+1, 0, SbrBarraEstado1->width()-1, 19));

    LabBarraEstado2->setGeometry(QRect(3, 0, SbrBarraEstado2->width(), 19));

    PanVariables->setGeometry(QRect(1, PanContenedor->height()-2-24-30, PanContenedor->width()-1, 30));

    /*LabVariable->setGeometry(QRect(8, 5, 31, 16));

    LabEdit->setGeometry(QRect(480, 5, 35, 16));

    LabOperadores->setGeometry(QRect(150, 5, 38, 16));

    CbxVariables->setGeometry(QRect(35, 4, 109, 22));

    LabMissing->setGeometry(QRect(295, 5, 45, 16));

    CbxMissing->setGeometry(QRect(340, 4, 129, 22));

    EdtEdit->setGeometry(QRect(525, 4, 415, 22));

    CbxOperadores->setGeometry(QRect(185, 4, 65, 22));

    ButModificarEdit->setGeometry(QRect(943, 8, 49, 17));

    ButInsertarEdit->setGeometry(QRect(994, 8, 49, 17));

    ButBorrarEdit->setGeometry(QRect(1045, 8, 49, 17));*/

    PanValidarEdit->setGeometry(QRect(1, PanContenedor->height()-2-56-30, PanContenedor->width()-1, 30));

    /*LabValidacionSintactica->setGeometry(QRect(8, 8, 132, 18));

    ImgValidacionSintactica->setGeometry(QRect(125, 5, 28, 24));

    LabValidacionLexica->setGeometry(QRect(170, 8, 111, 18));

    ImgValidacionLexica->setGeometry(QRect(267, 5, 28, 24));

    LabIrA->setGeometry(QRect(750, 9, 43, 16));

    LabFiltro->setGeometry(QRect(300, 9, 101, 16));

    EdtIrA->setGeometry(QRect(790, 6, 33, 21));

    ButSigEditMal->setGeometry(QRect(536, 6, 201, 21));

    EdtFiltro->setGeometry(QRect(396, 6, 121, 21));*/

}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Asociar las clases provenientes de etapas anteriores.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void TFmeEdits::AsociarClases(TFmeMicroDatos *FmeMicroDatosAsociados)
    {
      this->FmeMicroDatosAsociados = FmeMicroDatosAsociados;
      this->FmeVariablesAsociadas = FmeMicroDatosAsociados->GetVariablesAsociadas();
      this->MemLogs = FmeVariablesAsociadas->GetMemLogs();
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Actualizar la información de la Variable actual.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void TFmeEdits::ActualizarInformacionVariable(unsigned IndiceVariable)
    {
      unsigned j;

      for (j = 0; j < (unsigned)FmeVariablesAsociadas->GetNumAtributos(); j++) {       
        VectorDatosS[j] = FmeVariablesAsociadas->getMatrizVariablesS(IndiceVariable, j);
        if (j < 8) view2->setColumnWidth ( j, ANCHOS_VARIABLE[j]);
        else
             if (j < 8 + FmeVariablesAsociadas->GetNum_valores_missing()) view2->setColumnWidth ( j, 100);
             else view2->setColumnWidth ( j, ANCHOS_VARIABLE[j - FmeVariablesAsociadas->GetNum_valores_missing()]);
      }
      listaV2[0] = FmeVariablesAsociadas->getlistaV(IndiceVariable);
      model2->setCabeceraV(listaV2);
      repintarVariable(true, false);
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Actualizar la validacion del edit cuando existe un error.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void TFmeEdits::ActualizarValidacionEditConError(bool Sintactico, bool Lexico)
    {
      if (EditActualCorrecto())
        NumEditsValidados--;

      VectorInfoEdits[view->currentIndex().row()].Sintactico = Sintactico;
      VectorInfoEdits[view->currentIndex().row()].Lexico = Lexico;
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Actualizar la validacion del edit cuando no existe ningún error.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void TFmeEdits::ActualizarValidacionEditSinError()
    {
      if (!EditActualCorrecto())
        NumEditsValidados++;

      VectorInfoEdits[view->currentIndex().row()].Sintactico = true;
      VectorInfoEdits[view->currentIndex().row()].Lexico = true;
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//  Actualizar la información de validación del edit.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void TFmeEdits::ActualizarValidacionEdit(unsigned IndiceEdit)
    {
      // Validación sintáctica
      if (VectorInfoEdits[IndiceEdit].Sintactico)
        ImgValidacionSintactica->setIcon(QIcon(IconoBien));
      else
        ImgValidacionSintactica->setIcon(QIcon(IconoMal));
      // Validación léxica
      if (VectorInfoEdits[IndiceEdit].Lexico)
        ImgValidacionLexica->setIcon(QIcon(IconoBien));
      else
        ImgValidacionLexica->setIcon(QIcon(IconoMal));
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Actualizar el mensaje de pantalla sobre inserción de edit.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void TFmeEdits::ActualizarMensajeEditActual()
    {
      QString Edit;
      QColor Color;

      Edit = EdtEdit->text();
      QPalette palette( QApplication::palette() );
      QPalette palette2( QApplication::palette() );      
      palette2 = EdtEdit->palette();
      if (!EditActualCorrecto())
      {
        EdtEdit->setText(QApplication::translate("", "Regla insertada en la base de datos. Revise la regla porque tiene errores sint\303\241cticos y/o l\303\251xicos", 0, QApplication::UnicodeUTF8));
        palette.setColor( QPalette::Active, QPalette::Base, CL_FALSE );
        EdtEdit->setPalette(palette);
      }
      else
      {
        EdtEdit->setText(QApplication::translate("", "Regla insertada en la base de datos. La regla es sint\303\241cticamente y l\303\251xicamente correcta", 0, QApplication::UnicodeUTF8));
        palette.setColor( QPalette::Active, QPalette::Base, CL_TRUE );
        EdtEdit->setPalette(palette);
      }

      QApplication::processEvents();      

      EdtEdit->setText(Edit);
      EdtEdit->setPalette(palette2);
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Borrar el edit actual.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void TFmeEdits::BorrarEdit()
    {
      unsigned EditAnterior;      

      EditAnterior = (view->currentIndex().row() == 0) ? view->currentIndex().row() : view->currentIndex().row() - 1;      
      view->setFocus();

      if (EditActualCorrecto())
        NumEditsValidados--;

      QString id = listaV.at(view->currentIndex().row());
      CompactarVectorInfoEdits();
      CompactarRejilla();
      NumEdits--;      

      if (Xml) {
        QDomDocument doc("?xml");
        QDomNode n;
        QDomElement e, e1;
        QDomNode n1;

        QFile file(QDir::convertSeparators(NombreBaseDatos + NombreTabla));

        if ((!file.open(QIODevice::ReadWrite)) || (!doc.setContent(&file)))
        {
          QMessageBox::critical(this, tr("Error"), QApplication::translate("", QString("No se pudo realizar satisfactoriamente la consulta sobre la base de datos [\"" + NombreTabla + "\"]").toLatin1(), "", QApplication::UnicodeUTF8), QMessageBox::Ok, QMessageBox::Ok);
          QApplication::processEvents();
          file.close();
          return;
        }

        QDomElement root = doc.documentElement();

        n = root.firstChild();
        QString CadenaSQL = NombreTabla;
        CadenaSQL.replace(".xml", "", Qt::CaseInsensitive);
        bool salir = false;
        while ((!n.isNull()) && (!salir))
        {          
          e = n.toElement();
          if (!e.isNull()) {
            if ((e.tagName() == CadenaSQL) || (e.tagName() == "ROW")) {
              n1 = n.firstChild();
              while ((!n1.isNull()) && (!salir))  // buscamos primero el identificador de cada registro
              {
                e1 = n1.toElement();
                if ((e1.tagName() == "ID") && (e1.text() == id))  salir = true;
                else  n1 = n1.nextSibling();
              }
            }
          }
          if (!salir) n = n.nextSibling();
        }

        root.removeChild(n);
        file.close();

        QFile file2(QDir::convertSeparators(NombreBaseDatos + NombreTabla));
        if (!file2.open(QIODevice::WriteOnly)) {
          QMessageBox::critical(this, tr("Error"), QApplication::translate("", QString("No se pudo realizar satisfactoriamente la consulta sobre la base de datos [\"" + NombreTabla + "\"]").toLatin1(), "", QApplication::UnicodeUTF8), QMessageBox::Ok, QMessageBox::Ok);
          QApplication::processEvents();
          file2.close();
          return;
        }
        QTextStream ts(&file2);
        ts.setCodec(QTextCodec::codecForName("UTF-8"));
        doc.save(ts, 4, QDomNode::EncodingFromTextStream);

        file2.close();
      }else {
        if (Excel) {
          QMessageBox::warning(this, QApplication::translate("", "Informaci\303\263n", "", QApplication::UnicodeUTF8), QApplication::translate("", QString("TEIDE2 no puede borrar una fila en una tabla Excel, se proceder\303\241 a poner el valor vac\303\255o.\nNo olvide borrar manualmente, en el fichero Excel, estos valores vac\303\255os una vez ha terminado de trabajar con TEIDE2").toLatin1(), "", QApplication::UnicodeUTF8), QMessageBox::Ok, QMessageBox::Ok);
          query2->exec("UPDATE " + NombreTabla + " SET [CONDICION] = '' WHERE [ID] = " + id);
          query2->exec("UPDATE " + NombreTabla + " SET [DESCRIPCION] = '' WHERE [ID] = " + id);
          query2->exec("UPDATE " + NombreTabla + " SET [ID] = '' WHERE [CONDICION] = 'NULL' AND [DESCRIPCION] = ''");
        }else
          query2->exec("DELETE FROM " + NombreTabla + " WHERE [ID] = " + id);        
      }      

      if (NumEdits > 0) {        
        model->removeListaV ( view->currentIndex().row() );        
        view->setCurrentIndex(view->indexAt(QPoint(view->columnViewportPosition(0), view->rowViewportPosition(EditAnterior))));        
      }
      if (NumEdits == 0)
      {
        ButBorrarEdit->setEnabled(false);
        ButModificarEdit->setEnabled(false);        
        model->setData(QModelIndex(), QVariant(""), Qt::EditRole);
        model->setHeaderData(view->currentIndex().row(), Qt::Vertical, QVariant(""), Qt::EditRole);        
      }

      EdtEdit->setText(MatrizEditsS[view->currentIndex().row()][0]);      

      repintar();
      EscribirInformacion();
      view->selectRow(view->currentIndex().row());
      MostrarInfoAsociada(view->currentIndex().row(), 0, true);
      view->emitirSennal();
      //view->update(view->currentIndex());

    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//  Cargar las Variables posibles en la lista desplegable.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void TFmeEdits::CargarVariablesEnLista()
    {
      CbxVariables->addItems(*FmeVariablesAsociadas->GetListaVariables());
      CbxVariables->setCurrentIndex(0);
      CbxVariables->setInsertPolicy(QComboBox::NoInsert);
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//  Cargar los valores missing posibles en la lista desplegable.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void TFmeEdits::CargarMissingEnLista()
    {
      for (int i = 0; i < FmeVariablesAsociadas->GetNum_valores_missing(); i++)
      {        
        CbxMissing->addItem(QString::number(FmeVariablesAsociadas->getVectorValoresMissing(i), 10) + " " + FmeVariablesAsociadas->GetCadenas_Missing()->at(i));
      }
      CbxMissing->setCurrentIndex(0);
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Cargar los edits en la rejilla de visualización.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void TFmeEdits::CargarEditsEnRejilla()
    {
      unsigned i, j;      

      // Fijar el número de filas de la rejilla
      MatrizEditsS = new QString*[(NumEdits == 0) ? 1 + MAX_EDITS : NumEdits + MAX_EDITS];

      view->verticalHeader()->setDefaultSectionSize(20);
      FijarTitulosColumnasRejilla();

      ListaIds = new unsigned[NumEdits + MAX_EDITS];
      if (Xml) {
        QDomDocument *doc = new QDomDocument("?xml");
        QDomNode n;
        QDomElement e, e1;
        QDomNode n1;

        QFile file(QDir::convertSeparators(NombreBaseDatos + NombreTabla));

        if ((!file .open(QIODevice::ReadOnly)) || (!doc->setContent(&file)))
        {
          MemLogs->append("ERROR: " + tr("No se pudo realizar satisfactoriamente la consulta sobre la base de datos") +  " [\"" + NombreTabla + "\"]");
          QApplication::processEvents();
          file.close();
          return;
        }
        MemLogs->append(tr("Fichero xml cumple con el estandar W3C/XML"));
        QDomElement root = doc->documentElement();
        if (!root.tagName().contains("dataroot"))
         if (root.tagName() != "ROWSET")
         {
           MemLogs->append("ERROR: " + tr("No se pudo realizar satisfactoriamente la consulta sobre la base de datos") +  " [\"" + NombreTabla + "\"]");
           QApplication::processEvents();
           file.close();
           return;
         }
        MemLogs->append(tr("Leyendo fichero xml"));
        QApplication::processEvents();
        QString CadenaSQL = NombreTabla;
        CadenaSQL.replace(".xml", "", Qt::CaseInsensitive);
        i = 0;
        n = root.firstChild();
        while (!n.isNull())
        {
          MatrizEditsS[i] = new QString[NUM_ATRIBUTOS_EDIT];
          e = n.toElement();
          if (!e.isNull()) {
            if ((e.tagName() == CadenaSQL) || (e.tagName() == "ROW")) {
              n1 = n.firstChild();
              while (!n1.isNull())
              {
                e1 = n1.toElement();
                if (!e1.isNull()) {  
                  if (e1.tagName() == "ID") {
                    ListaIds[i] = e1.text().toInt();                    
                  }else
                    if (e1.tagName() == "CONDICION") MatrizEditsS[i][0] = e1.text();
                    else
                      if (e1.tagName() == "DESCRIPCION") MatrizEditsS[i][1] = e1.text();
                }
                n1 = n1.nextSibling();
              }
            }
          }
          i++;
          n = n.nextSibling();
        }
      }else {      
        QString CadenaSQL = "SELECT " + VariablesALeer + ", ID FROM " + NombreTabla + " ORDER BY ID";
        QSqlQuery query(CadenaSQL, *AdqConsulta);
        QSqlRecord record = query.record();

        i = 0;
        while (query.next())
        {
          if (!query.value(record.indexOf("CONDICION")).toString().isEmpty()) {
            MatrizEditsS[i] = new QString[NUM_ATRIBUTOS_EDIT];
            ListaIds[i] = query.value(record.indexOf("ID")).toString().replace(".0", "").toInt();
            for (j = 0; j < (unsigned)NUM_ATRIBUTOS_EDIT; j++) {
              MatrizEditsS[i][j] = query.value(j).toString();
            }
            i++;
          }          
        }      
      }
      // Fijar ids de las filas
      FijarIdsFilasRejilla();      
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Compactar el vector de información de edit.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void TFmeEdits::CompactarVectorInfoEdits()
    {
      unsigned i;

      for (i = view->currentIndex().row(); i < (NumEdits - 1); i++)
        VectorInfoEdits[i] = VectorInfoEdits[i+1];
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Compactar la rejilla de edits.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void TFmeEdits::CompactarRejilla()
    {
      unsigned i, j;

      for (i = view->currentIndex().row(); i < (unsigned)(NumEdits - 1); i++)
      {        
        listaV.replace(i, listaV.at(i+1));
        for (j = 0; j < (unsigned)NUM_ATRIBUTOS_EDIT; j++)
          MatrizEditsS[i][j] = MatrizEditsS[i+1][j];          
      }
      listaV.removeLast();
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Crear vectores de pertenencia de variables.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void TFmeEdits::CrearVectorPertenenciaEdits()
    {
      unsigned i, j;
      unsigned NumVariables;

      NumVariables = FmeVariablesAsociadas->GetNumVariables();
      VectorPertenenciaEdits = new QSet<unsigned>[NumVariables];

      // Rellenar el vector de pertenencia de edits explícitos
      for (j = 0; j < NumVariables; j++)
      {
        VectorPertenenciaEdits[j].clear();
        for (i = 0; i < NumEdits; i++)
          if (VariableEnEdit(j, i))
            VectorPertenenciaEdits[j].insert(i);
      }
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Cargar el vector de edits warning.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void TFmeEdits::CargarVectorEditsWarning()
    {
      QSet<unsigned>::iterator Puntero;
      QSet<unsigned> VariablesDeEdit;
      unsigned i, IndiceVariable;
      bool VariableImputableEncontrada;

      for (i = 0; i < NumEdits; i++)
      {
        VariablesDeEdit = VectorInfoEdits[i].Variables;
	Puntero = VariablesDeEdit.begin();
        VariableImputableEncontrada = false;
        while ((Puntero != VariablesDeEdit.end()) && (!VariableImputableEncontrada))
        {
          IndiceVariable = (*Puntero);
          if (FmeVariablesAsociadas->EsVariableImputable(IndiceVariable))
            VariableImputableEncontrada = true;
          ++Puntero;
        }
        VectorInfoEdits[i].EditWarning = !VariableImputableEncontrada;
      }
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Deshabilitar los controles para la gestión de edits.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void TFmeEdits::DeshabilitarControlesEdit()
    {
      CbxVariables->setEnabled(false);
      CbxOperadores->setEnabled(false);
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Escribir mensaje de información en la barra de estado.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void TFmeEdits::EscribirInformacion()
    {
      if (NumEdits == 0)
        LabBarraEstado1->setText(tr("Ninguna regla"));
      else
      {
        LabBarraEstado1->setText(QString::number(NumEdits, 10) + tr(" REGLAS: ") + QString::number(NumEditsValidados, 10) + " " + tr("Reglas validadas") + "[" +
                                  QString::number((((double)NumEditsValidados / (double)NumEdits)*100), 'g', 6) + "%], " +
                                  QString::number(NumEdits - NumEditsValidados, 10)+ " " + tr("Reglas no validadas") + "[" +
                                   QString::number(((double(NumEdits - NumEditsValidados) / (double)NumEdits)*100), 'g', 6) + "%]");
      }
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Devuelve TRUE si el Edit actual es sintáctica y léxicamente correcto.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    bool TFmeEdits::EditActualCorrecto()
    {
      return ((VectorInfoEdits[view->currentIndex().row()].Sintactico) && (VectorInfoEdits[view->currentIndex().row()].Lexico));
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Devuelve TRUE si el Edit por parámetros es sintáctica y léxicamente correcto.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    bool TFmeEdits::EditCorrecto(unsigned IndiceEdit)
    {
      return ((VectorInfoEdits[IndiceEdit].Sintactico) && (VectorInfoEdits[IndiceEdit].Lexico));
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Otras funciones
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    bool TFmeEdits::EditWarning(unsigned IndiceEdit) { return VectorInfoEdits[IndiceEdit].EditWarning; }
    bool TFmeEdits::EditsValidados() { return (NumEdits == NumEditsValidados); }
    bool TFmeEdits::ExistenEdits() { return (NumEdits > 0); }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Fijar el ancho de las columnas de la rejilla.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void TFmeEdits::FijarAnchoColumnasRejilla()
    {
      unsigned i;

      for (i = 0; i < NUM_ATRIBUTOS_EDIT; i++)
        view->setColumnWidth(i, ANCHOS_EDIT[i]);
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Fijar los títulos de las columnas de la rejilla.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void TFmeEdits::FijarTitulosColumnasRejilla()
    {
      unsigned j;

      for (j = 0; j < NUM_ATRIBUTOS_EDIT; j++) {        
        listaH.append(ATRIBUTOS_EDIT[j]);
      }
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Fijar la cantidad de datos que intervienen en el proceso.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void TFmeEdits::FijarCantidadDatos()
    {
      if (Xml) {
        QDomDocument *doc = new QDomDocument("?xml");
        QDomNode n;
        QDomElement e, e1;
        QDomNode n1;

        QFile file(QDir::convertSeparators(NombreBaseDatos + NombreTabla));
        
        if ((!file .open(QIODevice::ReadOnly)) || (!doc->setContent(&file)))
        {
          MemLogs->append("ERROR: " + tr("No se pudo realizar satisfactoriamente la consulta sobre la base de datos") +  " [\"" + NombreTabla + "\"]");
          QApplication::processEvents();
          file.close();
          return;
        }
        MemLogs->append(tr("Fichero xml cumple con el estandar W3C/XML"));
        QDomElement root = doc->documentElement();
        if (!root.tagName().contains("dataroot"))
         if (root.tagName() != "ROWSET")
         {
           MemLogs->append("ERROR: " + tr("No se pudo realizar satisfactoriamente la consulta sobre la base de datos") +  " [\"" + NombreTabla + "\"]");
           QApplication::processEvents();
           file.close();
           return;
         }
        MemLogs->append(tr("Leyendo fichero xml"));
        QApplication::processEvents();
        NumEdits = 0;
        NumEditsTotales = 0;
        QString CadenaSQL = NombreTabla;
        CadenaSQL.replace(".xml", "", Qt::CaseInsensitive);
        n = root.firstChild();
        while (!n.isNull())
        {
          e = n.toElement();
          if (!e.isNull()) {
            if ((e.tagName() == CadenaSQL) || (e.tagName() == "ROW")) {
              n1 = n.firstChild();
              while (!n1.isNull())
              {
                e1 = n1.toElement();
                if (!e1.isNull()) {
                  if (e1.tagName() == "ID") {
                    if (NumEditsTotales < e1.text().toInt()) NumEditsTotales = e1.text().toInt();
                  }
                }
                n1 = n1.nextSibling();
              }
            }
          }
          NumEdits++;
          n = n.nextSibling();
        }
      }else {
        QString CadenaSQL = "SELECT ID, CONDICION FROM " + NombreTabla + " ORDER BY ID ASC";
        query2->exec(CadenaSQL);
        NumEdits = 0;
        NumEditsTotales = 0;
        while (query2->next()) {
          if (!query2->value(1).toString().isEmpty()) NumEdits++;
          if (NumEditsTotales < query2->value(0).toString().replace(".0", "").toInt()) NumEditsTotales = query2->value(0).toString().replace(".0", "").toInt();
        }
      }
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Fijar los identificadores de cada fila.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void TFmeEdits::FijarIdsFilasRejilla()
    {
      unsigned i;     

      for (i = 0; i < (unsigned)NumEdits; i++)  {        
        listaV.append(QString::number(GetIdEdit(i), 10).replace(".0", ""));        
      }
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Obtener el conjunto correspondiente a la lista de variables.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    QSet<unsigned> TFmeEdits::GetConjuntoDesdeLista(QStringList *Lista)
    {
      unsigned i, IndiceVariable;
      QSet<unsigned> Conjunto;

      for (i = 0; i < (unsigned)Lista->count(); i++)
      {
        IndiceVariable = FmeVariablesAsociadas->GetIndiceVariable(Lista->at(i));
        Conjunto.insert(IndiceVariable);
      }
      return Conjunto;
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Varios.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    QString TFmeEdits::GetNombreTabla() { return NombreTabla; }
    QSet<unsigned> TFmeEdits::GetVariablesEdits(unsigned IndiceEdit) { return VectorInfoEdits[IndiceEdit].Variables; }
    unsigned TFmeEdits::GetNumEdits() { return NumEdits; }
    TFmeMicroDatos *TFmeEdits::GetMicroDatosAsociados() { return FmeMicroDatosAsociados; }
    double TFmeEdits::GetPorcentajeEditsValidados() { return ((double)NumEditsValidados / (double)NumEdits) * 100; }
    QString TFmeEdits::GetEdit(unsigned IndiceEdit) { return MatrizEditsS[IndiceEdit][0]; }// SgrRejilla->text(IndiceEdit, 0); }
    unsigned TFmeEdits::GetIdEdit(unsigned IndiceEdit) { return ListaIds[IndiceEdit]; }
    unsigned TFmeEdits::GetNumEditsVariable(unsigned IndiceVariable) { return VectorPertenenciaEdits[IndiceVariable].size(); }
    QSet<unsigned> TFmeEdits::GetEditsConVariable(unsigned IndiceVariable) { return VectorPertenenciaEdits[IndiceVariable]; }
    QComboBox *TFmeEdits::GetVisualizarEd() { return VisualizarEd;  }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Obtener la lista correspondiente al conjunto de variables.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    QStringList *TFmeEdits::GetListaDesdeConjunto(QSet<unsigned> Conjunto)
    {
      QSet<unsigned>::iterator Puntero;
      QStringList *Lista;
      QString NombreVariable;

      Lista = new QStringList();
      Lista->clear();
      Puntero = Conjunto.begin();
      while (Puntero != Conjunto.end())
      {
        NombreVariable = FmeVariablesAsociadas->GetNombreVariable(*Puntero);
        Lista->append(NombreVariable);
        Puntero++;
      }
      return Lista;
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Habilitar los controles para la gestión de edits.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void TFmeEdits::HabilitarControlesEdit()
    {
      CbxVariables->setEnabled(true);
      CbxOperadores->setEnabled(true);
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Inicializar la rejilla de visualización de Variables.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void TFmeEdits::InicializarRejillaVariable()
    {
      unsigned j;
      QString s;      

      // Establecemos el número de filas y columnas
      VectorDatosS = new QString[FmeVariablesAsociadas->GetNumAtributos()];      
      // Establecemos los títulos en la primera fila
      for (j = 0; j < (unsigned)FmeVariablesAsociadas->GetNumAtributos(); j++)
      {
        listaH2.append(FmeVariablesAsociadas->getlistaH(j));        
      }
      listaV2.append("");
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Insertar un nuevo edit.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void TFmeEdits::InsertarEdit()
    {
      // OJO! Hay que chequear un posible desborde del vector de edits
      QString CadenaSQL;

      NumEdits++;
      NumEditsTotales++;
      NumEditsValidados++;      
      EdtEdit->setFocus();
      MatrizEditsS[NumEdits-1] = new QString[NUM_ATRIBUTOS_EDIT];      

      if (Xml) {        
        QDomNode n;        
        QDomNode n1;

        QDomDocument doc("?xml");
        QFile file(QDir::convertSeparators(NombreBaseDatos + NombreTabla));
        if (!file.open(QIODevice::ReadOnly)) {
          QMessageBox::critical(this, tr("Error"), QApplication::translate("", QString("No se pudo realizar satisfactoriamente la consulta sobre la base de datos [\"" + NombreTabla + "\"]").toLatin1(), "", QApplication::UnicodeUTF8), QMessageBox::Ok, QMessageBox::Ok);
          QApplication::processEvents();
          file.close();
          return;
        }
        if (!doc.setContent(&file)) {
          QMessageBox::critical(this, tr("Error"), QApplication::translate("", QString("No se pudo realizar satisfactoriamente la consulta sobre la base de datos [\"" + NombreTabla + "\"]").toLatin1(), "", QApplication::UnicodeUTF8), QMessageBox::Ok, QMessageBox::Ok);
          QApplication::processEvents();
          file.close();
          return;
        }
        file.close();
        QDomElement docElem = doc.documentElement();        
        CadenaSQL = NombreTabla;
        CadenaSQL.replace(".xml", "", Qt::CaseInsensitive);

        QDomElement tag = doc.createElement(CadenaSQL);
        docElem.appendChild(tag);

        QDomElement t0 = doc.createElement("ID");
        t0.appendChild(doc.createTextNode(QString::number(NumEditsTotales, 10)));
        tag.appendChild(t0);

        QDomElement t1 = doc.createElement("DESCRIPCION");
        t1.appendChild(doc.createTextNode("a"));
        tag.appendChild(t1);

        QDomElement t2 = doc.createElement("CONDICION");
        t2.appendChild(doc.createTextNode("a"));
        tag.appendChild(t2);

        QFile file2(QDir::convertSeparators(NombreBaseDatos + NombreTabla));
        if (!file2.open(QIODevice::WriteOnly)) {
          QMessageBox::critical(this, tr("Error"), QApplication::translate("", QString("No se pudo realizar satisfactoriamente la consulta sobre la base de datos [\"" + NombreTabla + "\"]").toLatin1(), "", QApplication::UnicodeUTF8), QMessageBox::Ok, QMessageBox::Ok);
          QApplication::processEvents();
          file2.close();
          return;
        }
        QTextStream ts(&file2);
        ts.setCodec(QTextCodec::codecForName("UTF-8"));
        doc.save(ts, 4, QDomNode::EncodingFromTextStream);

        file2.close();
      }else
        query2->exec("INSERT INTO " + NombreTabla + "(ID) VALUES ('" + QString::number(NumEditsTotales, 10) + "')");

      model->addListaV(QString::number(NumEditsTotales, 10));
      listaV.append(QString::number(NumEditsTotales, 10));

      EdtEdit->setText("");
      view->setCurrentIndex(view->indexAt(QPoint(view->columnViewportPosition(0), view->rowViewportPosition(NumEdits-1))));
      SgrRejillaSelectCell(view->currentIndex());
      view->setFocus();

      VectorInfoEdits[view->currentIndex().row()].Sintactico = true;
      VectorInfoEdits[view->currentIndex().row()].Lexico = true;

      ButInsertarEdit->setEnabled(false);
      ButModificarEdit->setEnabled(true);
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Modificar el edit actual.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void TFmeEdits::ModificarEdit()
    {      
      view->setFocus();

      if (listaH.at(view->currentIndex().column()) == "CONDICION")
      {
	// Insertar el texto del edit en la condición        
        QString id = model->headerData(view->currentIndex().row(), Qt::Vertical, Qt::DisplayRole).toString();

	if (Xml) {
          QDomDocument doc("?xml");
          QDomNode n;
          QDomElement e, e1;
          QDomNode n1;

          QFile file(QDir::convertSeparators(NombreBaseDatos + NombreTabla));

          if ((!file.open(QIODevice::ReadWrite)) || (!doc.setContent(&file)))
          {
            QMessageBox::critical(this, tr("Error"), QApplication::translate("", QString("No se pudo realizar satisfactoriamente la consulta sobre la base de datos [\"" + NombreTabla + "\"]").toLatin1(), "", QApplication::UnicodeUTF8), QMessageBox::Ok, QMessageBox::Ok);
            QApplication::processEvents();
            file.close();
            return;
          }

          QDomElement root = doc.documentElement();

          n = root.firstChild();
          QString CadenaSQL = NombreTabla;
          CadenaSQL.replace(".xml", "", Qt::CaseInsensitive);
          bool salir = false;
          while ((!n.isNull()) && (!salir))
          {            
            e = n.toElement();
            if (!e.isNull()) {
              if ((e.tagName() == CadenaSQL) || (e.tagName() == "ROW")) {
                n1 = n.firstChild();
                while ((!n1.isNull()) && (!salir))  // buscamos primero el identificador de cada registro
                {
                  e1 = n1.toElement();

                  if ((e1.tagName() == "ID") && (e1.text() == id))  salir = true;
                  else  n1 = n1.nextSibling();
                }
              }
            }
            if (!salir) n = n.nextSibling();
          }

          n1 = n.firstChild();
          while (!n1.isNull())
          {
            e1 = n1.toElement();
            if (e1.tagName() == "CONDICION") {
              QDomElement t2 = doc.createElement("CONDICION");
              t2.appendChild(doc.createTextNode(EdtEdit->text()));
              n.replaceChild(t2, e1);
            }
            n1 = n1.nextSibling();
          }
          file.close();
          QFile file2(QDir::convertSeparators(NombreBaseDatos + NombreTabla));
          if (!file2.open(QIODevice::WriteOnly)) {
            QMessageBox::critical(this, tr("Error"), QApplication::translate("", QString("No se pudo realizar satisfactoriamente la consulta sobre la base de datos [\"" + NombreTabla + "\"]").toLatin1(), "", QApplication::UnicodeUTF8), QMessageBox::Ok, QMessageBox::Ok);
            QApplication::processEvents();
            file2.close();
            return;
          }
          QTextStream ts(&file2);
          ts.setCodec(QTextCodec::codecForName("UTF-8"));
          doc.save(ts, 4, QDomNode::EncodingFromTextStream);

          file2.close();
        }else
          query2->exec("UPDATE " + NombreTabla + " SET CONDICION = '" + EdtEdit->text() + "' WHERE ID = " + id);

        ListaIds[view->currentIndex().row()] = id.toInt();
	MatrizEditsS[view->currentIndex().row()][0] = EdtEdit->text();

	// Validación sintáctica y léxico
	ValidarEditActual();
	// Actualizar la validación del edit
	ActualizarValidacionEdit(view->currentIndex().row());
	// Actualizar la información
        EscribirInformacion();
        // Mostrar la información asociada al edit
        MostrarInfoAsociada(view->currentIndex().row(), 0, true);
        // Mensaje informativo
        ActualizarMensajeEditActual();        
      }
      else
      {        
        QString id = model->headerData(view->currentIndex().row(), Qt::Vertical, Qt::DisplayRole).toString();
        if (Xml) {
          QDomDocument doc("?xml");
          QDomNode n;
          QDomElement e, e1;
          QDomNode n1;
          
          QFile file(QDir::convertSeparators(NombreBaseDatos + NombreTabla));

          if ((!file.open(QIODevice::ReadWrite)) || (!doc.setContent(&file)))
          {
            QMessageBox::critical(this, tr("Error"), QApplication::translate("", QString("No se pudo realizar satisfactoriamente la consulta sobre la base de datos [\"" + NombreTabla + "\"]").toLatin1(), "", QApplication::UnicodeUTF8), QMessageBox::Ok, QMessageBox::Ok);
            QApplication::processEvents();
            file.close();
            return;
          }

          QDomElement root = doc.documentElement();

          n = root.firstChild();
          QString CadenaSQL = NombreTabla;
          CadenaSQL.replace(".xml", "", Qt::CaseInsensitive);
          bool salir = false;
          while ((!n.isNull()) && (!salir))
          {            
            e = n.toElement();
            if (!e.isNull()) {
              if ((e.tagName() == CadenaSQL) || (e.tagName() == "ROW")) {
                n1 = n.firstChild();
                while ((!n1.isNull()) && (!salir))  // buscamos primero el identificador de cada registro
                {
                  e1 = n1.toElement();

                  if ((e1.tagName() == "ID") && (e1.text() == id))  salir = true;
                  else  n1 = n1.nextSibling();
                }
              }
            }
            if (!salir) n = n.nextSibling();
          }

          n1 = n.firstChild();
          while (!n1.isNull())
          {
            e1 = n1.toElement();
            if (e1.tagName() == "DESCRIPCION") {
              QDomElement t2 = doc.createElement("DESCRIPCION");
              t2.appendChild(doc.createTextNode(EdtEdit->text()));
              n.replaceChild(t2, e1);
            }
            n1 = n1.nextSibling();
          }
          file.close();
          QFile file2(QDir::convertSeparators(NombreBaseDatos + NombreTabla));
          if (!file2.open(QIODevice::WriteOnly)) {
            QMessageBox::critical(this, tr("Error"), QApplication::translate("", QString("No se pudo realizar satisfactoriamente la consulta sobre la base de datos [\"" + NombreTabla + "\"]").toLatin1(), "", QApplication::UnicodeUTF8), QMessageBox::Ok, QMessageBox::Ok);
            QApplication::processEvents();
            file2.close();
            return;
          }
          QTextStream ts(&file2);
          ts.setCodec(QTextCodec::codecForName("UTF-8"));
          doc.save(ts, 4, QDomNode::EncodingFromTextStream);

          file2.close();
        }else
          query2->exec("UPDATE " + NombreTabla + " SET DESCRIPCION = '" + EdtEdit->text() + "' WHERE ID = " + id);
        MatrizEditsS[view->currentIndex().row()][1] = EdtEdit->text();
      }

      model->setCurrencyMap(MatrizEditsS);      
      ButBorrarEdit->setEnabled(true);
      ButInsertarEdit->setEnabled(true); 
      MostrarInfoAsociada(0, 0, true);
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Mostrar la información asociada a la fila y a la columna.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void TFmeEdits::MostrarInfoAsociada(unsigned Fila, unsigned Columna, bool Fijar)
    {
      unsigned FilaS = listaV.indexOf(model->headerData(Fila, Qt::Vertical, Qt::DisplayRole).toString());
      if (NumEdits == 0)
        LabBarraEstado2->setText(tr("REGLA 0/0"));
      else
         LabBarraEstado2->setText(tr("REGLA ") + QString::number(Fila+1, 10) + "/" + QString::number(model->rowCount(view->currentIndex()), 10));
      EdtEdit->setText(model->data(view->indexAt(QPoint(view->columnViewportPosition(Columna), view->rowViewportPosition(Fila))), Qt::DisplayRole).toString()); //MatrizEditsS[Fila][Columna]);
      ActualizarValidacionEdit(FilaS);

      if (listaH.at(Columna) == "CONDICION")
          HabilitarControlesEdit();
      else
          DeshabilitarControlesEdit();

      if (Fijar) {
        view->setCurrentIndex(view->indexAt(QPoint(view->columnViewportPosition(Columna), view->rowViewportPosition(Fila))));
        view->setFocus();
        QColor rojo = view->currentIndex().model()->data(view->currentIndex(), Qt::BackgroundRole).value<QColor>();
        QString color = rojo.name();
        setStyleSheet("selection-color: black;selection-background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 " + color + ", stop: 1 gray);");
      }

      repintarVariable((!VectorDatosS[listaH2.indexOf("FILTRO")].isEmpty()), false);

    }
    void TFmeEdits::MostrarInfoAsociada(unsigned Fila, unsigned Columna, unsigned numedits, bool Fijar, QStringList listaHA, QString **MatrizEditsA, QStringList listaVA)
    {

        if (numedits == 0)
          LabBarraEstado2->setText(tr("REGLA 0/0"));
        else {
           unsigned FilaS = listaV.indexOf(listaVA.at(Fila));
           LabBarraEstado2->setText(tr("REGLA ") + QString::number(Fila+1, 10) + "/" + QString::number(numedits, 10));
           EdtEdit->setText(model->data(view->indexAt(QPoint(view->columnViewportPosition(Columna), view->rowViewportPosition(Fila))), Qt::DisplayRole).toString());//MatrizEditsA[Fila][Columna]);
           ActualizarValidacionEdit(FilaS);

           if (listaHA.at(Columna) == "CONDICION")
             HabilitarControlesEdit();
           else
             DeshabilitarControlesEdit();

           if (Fijar) {
            view->setCurrentIndex(view->indexAt(QPoint(view->columnViewportPosition(Columna), view->rowViewportPosition(Fila))));
            view->setFocus();
            QColor rojo = view->currentIndex().model()->data(view->currentIndex(), Qt::BackgroundRole).value<QColor>();
            QString color = rojo.name();
            setStyleSheet("selection-color: black;selection-background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 " + color + ", stop: 1 gray);");
           }

           repintarVariable((!VectorDatosS[listaH2.indexOf("FILTRO")].isEmpty()), false); //(MatrizEditsS[FilaS][Columna] == "False"));
        }
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Pinta la rejilla variable.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void TFmeEdits::repintarVariable(bool filtro, bool falso)
    {
      int col = FmeVariablesAsociadas->GetIndiceAtributo("FILTRO");
      QString *v = new QString[FmeVariablesAsociadas->GetNumAtributos()];
      for (int i = 1; i < FmeVariablesAsociadas->GetNumAtributos(); i++) {
        if (VectorDatosS[i] == "False") {
          v[i] = "Red";
        }else
          v[i] = "otro";
      }
      v[col] = "Blue";

      model2->setVectorPintar(v);
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Validar los edits cargados.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void TFmeEdits::ValidarEdits()
    {
      unsigned i;
      unsigned Aux = 0;

      // Se supone que los edits son correctos
      for (i = 0; i < NumEdits + MAX_EDITS; i++)
      {
        VectorInfoEdits[i].Sintactico = true;
        VectorInfoEdits[i].Lexico = true;
      }

      for (i = 0; i < NumEdits; i++)
      {        
        view->setCurrentIndex(view->indexAt(QPoint(view->columnViewportPosition(0), view->rowViewportPosition(i))));
	ValidarEditActual();
	if (EditActualCorrecto())
          Aux++;
      }

      NumEditsValidados = Aux;

      if (NumEdits == 0)
      {
        ButModificarEdit->setEnabled(false);
        ButBorrarEdit->setEnabled(false);
      }
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Validar la sintaxis y el léxico de la Edit actual.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void TFmeEdits::ValidarEditActual()
    {
      QStringList *Variables;
      QString Edit;
      QMap<QString,double> mappM;


      Edit = MatrizEditsS[view->currentIndex().row()][0];

      mappM = FmeVariablesAsociadas->GetMapMissing();
      switch (EvaluarExpresion((char*)Edit.toLatin1().data(), FmeMicroDatosAsociados->GetMapRegistro(0), &mappM, &mensajeE)) //EvaluarExpresion((char*)Edit.toLatin1().data(), FmeMicroDatosAsociados->GetMapRegistro(0), &mappM))
      {
	case ERROR_SINTACTICO:
	  ActualizarValidacionEditConError(false, true);
	  repintar();	  
      	  break;
        case ERROR_LEXICO:
          ActualizarValidacionEditConError(true, false);
          repintar();	  
          break;
        case ERROR_SINTACTICO_Y_LEXICO:
          ActualizarValidacionEditConError(false, false);
          repintar();	  
          break;
	default:
          ActualizarValidacionEditSinError();
          repintar();
          // Obtener las variables asociadas a este edit
          Variables = GetVariablesDeEdit(Edit);
          for (int i = 0; i < FmeVariablesAsociadas->GetNum_valores_missing(); i++)
           Variables->removeOne(FmeVariablesAsociadas->GetCadenas_Missing()->at(i));
          VectorInfoEdits[view->currentIndex().row()].Variables = GetConjuntoDesdeLista(Variables);
          break;
      }
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Comprueba que una variable se encuentra en un edit determinado
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    bool TFmeEdits::VariableEnEdit(unsigned IndiceVariable, unsigned IndiceEdit)
    {
      return VectorInfoEdits[IndiceEdit].Variables.contains(IndiceVariable);
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Vuelve a pintar las celda de la rejilla principal
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void TFmeEdits::repintar()
    {      
      unsigned i;

      bool *v = new bool[NumEdits];

      for (i = 0; i < (unsigned)NumEdits; i++) {
          if (!EditCorrecto(i)) v[i] = false;
          else v[i] = true;
      }
      model->setVectorEditCorrecto(v);
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// PULSAR EL BOTÓN DE MODIFICAR EDIT.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void TFmeEdits::ButModificarEditClick()
    {
      ButInsertarEdit->setEnabled(true);
      ModificarEdit();
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// PULSAR EL BOTÓN DE INSERTAR EDIT.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void TFmeEdits::ButInsertarEditClick()
    {
      ButInsertarEdit->setEnabled(false);
      InsertarEdit();
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// PULSAR EL BOTÓN DE BORRAR EDIT.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void TFmeEdits::ButBorrarEditClick()
    {
      ButInsertarEdit->setEnabled(true);
      BorrarEdit();
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// PULSAR EL BOTÓN DE INFORMACION DE ERROR.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void TFmeEdits::ButValidacionSintacticaClick()
    {
      if (model->rowCount(view->currentIndex()) > 0) {
        if (!VectorInfoEdits[listaV.indexOf(model->headerData(view->currentIndex().row(), Qt::Vertical, Qt::DisplayRole).toString())].Sintactico)
            QMessageBox::information(0, QApplication::translate("", "Informaci\303\263n", 0, QApplication::UnicodeUTF8), QApplication::translate("", "Error Sint\303\241ctico\nRevise los operadores:\n", 0, QApplication::UnicodeUTF8), QMessageBox::Ok, QMessageBox::NoButton);
      }
    }
    void TFmeEdits::ButValidacionLexicaClick()
    {
      if (model->rowCount(view->currentIndex()) > 0) {
        QMap<QString,double> mappM;
        QString Edit;
        if (!VectorInfoEdits[listaV.indexOf(model->headerData(view->currentIndex().row(), Qt::Vertical, Qt::DisplayRole).toString())].Lexico)
        {
            Edit = model->data(view->indexAt(QPoint(view->columnViewportPosition(0), view->rowViewportPosition(view->currentIndex().row()))), Qt::DisplayRole).toString();
            mappM = FmeVariablesAsociadas->GetMapMissing();
            EvaluarExpresion((char*)Edit.toLatin1().data(), FmeMicroDatosAsociados->GetMapRegistro(0), &mappM, &mensajeE);
            QMessageBox::information(0, QApplication::translate("", "Informaci\303\263n", 0, QApplication::UnicodeUTF8), QApplication::translate("", "Error L\303\251xico\n\"", 0, QApplication::UnicodeUTF8) + mensajeE + "\"", QMessageBox::Ok, QMessageBox::NoButton);
        }
      }
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// PULSAR EL BOTÓN DE IR AL SIGUIENTE EDIT INCORRECTO.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void TFmeEdits::ButSigEditMalClick()
    {
      if (model->rowCount(view->currentIndex()) > 0) {
       if (VisualizarEd->currentIndex() == 2)
       {
         UltimoEditVisitadoPorEdit = (UltimoEditVisitadoPorEdit + 1) % model->rowCount(view->currentIndex());
         view->setCurrentIndex(view->indexAt(QPoint(view->columnViewportPosition(0), view->rowViewportPosition(UltimoEditVisitadoPorEdit))));
         SgrRejillaSelectCell(view->currentIndex());
         view->setFocus();
       }else {
          if (NumEditsValidados < model->rowCount(view->currentIndex()))
          {
              UltimoEditVisitadoPorEdit = (UltimoEditVisitadoPorEdit + 1) % model->rowCount(view->currentIndex());
              while (EditCorrecto(UltimoEditVisitadoPorEdit))
                  UltimoEditVisitadoPorEdit = (UltimoEditVisitadoPorEdit + 1) % model->rowCount(view->currentIndex());
              view->setCurrentIndex(view->indexAt(QPoint(view->columnViewportPosition(0), view->rowViewportPosition(UltimoEditVisitadoPorEdit))));
              SgrRejillaSelectCell(view->currentIndex());
              view->setFocus();
          }
       }
      }
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// SELECCIONAR UNA VARIABLE DEL COMBOBOX DE VARIABLES.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void TFmeEdits::CbxVariablesCloseUp(QString var)
    {
      EdtEdit->setText(EdtEdit->text() + CbxVariables->currentText()  + " ");      
      ActualizarInformacionVariable(CbxVariables->currentIndex());
      EdtEdit->setFocus();
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// SELECCIONAR UN OPERADOR DEL COMBOBOX DE OPERADORES.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void TFmeEdits::CbxOperadoresCloseUp(QString op)
    {
      EdtEdit->setText(EdtEdit->text() + op + " ");
      EdtEdit->setFocus();
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// SELECCIONAR UN MISSING DEL COMBOBOX DE MISSING.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void TFmeEdits::CbxMissingCloseUp(QString mis)
    {
      EdtEdit->setText(EdtEdit->text() + mis.section(" ", -1) + " ");
      EdtEdit->setFocus();
    }
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// PRESIONAR UNA TECLA EN EL EDIT DE EDICIÓN DE EDITS.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void TFmeEdits::EdtEditKeyDown()
    {
      ModificarEdit();
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// PRESIONAR UNA TECLA EN EL EDIT DE IR A EDIT.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void TFmeEdits::EdtIrAKeyDown()
    {
      int IndiceEdit;

      //try
      //{
        IndiceEdit = EdtIrA->text().toInt();
      /*}
      catch (...)
      {
        EdtIrA->setText("");
        return;
      }*/
      if ((IndiceEdit >= 1) && (IndiceEdit <= (int)model->rowCount(view->currentIndex()))) {//NumEdits)) {
        view->setCurrentIndex(view->indexAt(QPoint(view->columnViewportPosition(0), view->rowViewportPosition(IndiceEdit-1))));
        SgrRejillaSelectCell(view->currentIndex());        
        view->setFocus();
      }
      EdtIrA->setText("");
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// TOMAR POSESIÓN DEL CONTROL EL EDIT DE EDICION DE EDITS.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void TFmeEdits::EdtEditEnter()
    {
      if (NumEdits == 0)
        InsertarEdit();
      else
        ModificarEdit();
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// PULSAR UNA TECLA EN EL EDIT DE FILTRO DE EDITS.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void TFmeEdits::EdtFiltroKeyDown()
    {
      unsigned PosicionArranque;
      QColor ColorEdit;
      bool Salir = false;
      QString TextoEdit;

      UltimoEditVisitadoPorFiltro = (UltimoEditVisitadoPorFiltro + 1) % NumEdits;
      PosicionArranque = UltimoEditVisitadoPorFiltro;
      while ((!VectorInfoEdits[UltimoEditVisitadoPorFiltro].Variables.contains(FmeVariablesAsociadas->GetIndiceVariable(EdtFiltro->text()))) &&(!Salir))
      {
        UltimoEditVisitadoPorFiltro = (UltimoEditVisitadoPorFiltro + 1) % NumEdits;
        if (UltimoEditVisitadoPorFiltro == PosicionArranque)
        {
          TextoEdit = EdtFiltro->text();
          EdtFiltro->setText(tr("NO ENCONTRADO!"));
          QPalette palette( QApplication::palette() );
          palette = EdtFiltro->palette();          
          QPalette palette2( QApplication::palette() );
          palette2.setColor( QPalette::Active, QPalette::Base, CL_FALSE );
          EdtFiltro->setPalette(palette2);
          QApplication::processEvents();          
          EdtFiltro->setText(TextoEdit);          
          EdtFiltro->setPalette(palette);
          UltimoEditVisitadoPorFiltro = 0;
          Salir = true;
        }
      }      
      view->setCurrentIndex(view->indexAt(QPoint(view->columnViewportPosition(view->currentIndex().column()), view->rowViewportPosition(UltimoEditVisitadoPorFiltro))));
      SgrRejillaSelectCell(view->currentIndex());      
      view->setFocus();      
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// SELECCIONAR UNA CELDA EN LA REJILLA.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void TFmeEdits::SgrRejillaSelectCell(const QModelIndex& index)
    {
      int fila = index.row();
      int col = index.column();
      UltimoEditVisitadoPorFiltro = fila;
      UltimoEditVisitadoPorEdit = fila;
      MostrarInfoAsociada(fila, col, true);
    }

    void TFmeEdits::SgrRejillaSelectCellV(const int& index)
    {
      int fila = view->currentIndex().row();
      int col = 0;
      UltimoEditVisitadoPorFiltro = fila;
      UltimoEditVisitadoPorEdit = fila;
      MostrarInfoAsociada(fila, col, false);
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// MODO DE VISUALIZAR LA TABLA DE EDITS.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void TFmeEdits::VisualizarEdCloseUp(int index2)
    {      
      QString **MatrizEditsA;
      //QStringList listaHA;
      QStringList listaVA;
      bool *editcor;
      int i, j, k;      
      if (index2 == 0) {
          delete model;
          model = new TablaModelE(0, MatrizEditsS, listaH, listaV);
          repintar();
          view->setModel(model);
          MostrarInfoAsociada(0, 0, NumEdits, true, listaH, MatrizEditsS, listaV);
          ButSigEditMal->setEnabled(true);
          ButModificarEdit->setEnabled(true);
          ButInsertarEdit->setEnabled(true);
          ButBorrarEdit->setEnabled(true);
      }else {
          if (index2 == 1) {
              listaVA.clear();
              MatrizEditsA = new QString*[NumEditsValidados];
              editcor = new bool[NumEditsValidados];
              j = 0;
              for (i = 0; i < NumEdits; i++)
              {
                  if (EditCorrecto(i))
                  {
                      MatrizEditsA[j] = new QString[NUM_ATRIBUTOS_EDIT];
                      for (k = 0; k < NUM_ATRIBUTOS_EDIT; k++)
                      {
                          MatrizEditsA[j][k] = MatrizEditsS[i][k];

                      }
                      listaVA.append(listaV.at(i));
                      editcor[j] = true;
                      j++;
                  }
              }
              model->setVectorEditCorrecto(editcor);              
              model->setCurrencyMap(MatrizEditsA);   // cuando modifiquemos la matriz
              model->setCabeceraV(listaVA);   // cuando modifiquemos la cabeceraV
              MostrarInfoAsociada(0, 0, NumEditsValidados, true, listaH, MatrizEditsA, listaVA);
              ButSigEditMal->setEnabled(false);
              ButModificarEdit->setEnabled(false);
              ButInsertarEdit->setEnabled(false);
              ButBorrarEdit->setEnabled(false);              
          }else {              
              listaVA.clear();
              MatrizEditsA = new QString*[NumEdits-NumEditsValidados];
              editcor = new bool[NumEdits-NumEditsValidados];
              j = 0;
              for (i = 0; i < NumEdits; i++)
              {
                  if (!EditCorrecto(i))
                  {
                      MatrizEditsA[j] = new QString[NUM_ATRIBUTOS_EDIT];
                      for (k = 0; k < NUM_ATRIBUTOS_EDIT; k++)
                      {
                          MatrizEditsA[j][k] = MatrizEditsS[i][k];

                      }
                      listaVA.append(listaV.at(i));
                      editcor[j] = false;
                      j++;
                  }
              }
              model->setVectorEditCorrecto(editcor);              
              model->setCurrencyMap(MatrizEditsA);   // cuando modifiquemos la matriz
              model->setCabeceraV(listaVA);   // cuando modifiquemos la cabeceraV
              MostrarInfoAsociada(0, 0, NumEdits-NumEditsValidados, true, listaH, MatrizEditsA, listaVA);
              ButSigEditMal->setEnabled(true);
              ButModificarEdit->setEnabled(false);
              ButInsertarEdit->setEnabled(false);
              ButBorrarEdit->setEnabled(false);
          }
      }      
    }
