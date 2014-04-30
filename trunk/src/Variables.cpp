/*******************************************************************************
** Variables.cpp: contiene todo lo necesario para trabajar con la solapa
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


#include "Variables.h"

 TFmeVariables::TFmeVariables(QWidget* parent, const char* name, Qt::WindowFlags fl, QSqlDatabase *AdcConexionBD, QString NombreTabla, QString NombreTablaMissing, QStringList *ListaVariables, QString NombreConjunto, QTextEdit *MemLogs, bool *correcto, bool Xml, QString NombreBaseDatos, QTabWidget *PctContenedorPrincipal, int Num_valores_missing, QStringList *Cadenas_Missing, bool excel, QAction *Accion)
    {
      setGeometry(0, 0, parent->width()-2, parent->height()-15);

      if (this->objectName().isEmpty())
        this->setObjectName(("TFmeVariables"));
      PanContenedorVar = new QFrame(this);
      PanContenedorVar->setObjectName(("PanContenedorVar"));
      PanContenedorVar->setGeometry(QRect(0, 0, this->width(), this->height()-50));
      PanContenedorVar->setFrameShape(QFrame::Panel);
      PanContenedorVar->setFrameShadow(QFrame::Raised);
      view = new MiTabla(PanContenedorVar);
      VisualizarVar = new QComboBox(PctContenedorPrincipal);
      VisualizarVar->setGeometry(PanContenedorVar->width()-220, 0, 200, 25);
      VisualizarVar->setVisible(false);
      SbrBarraEstado = new QFrame(PanContenedorVar);
      SbrBarraEstado->setObjectName(("SbrBarraEstado"));
      SbrBarraEstado->setGeometry(QRect(1, PanContenedorVar->height()-2-22, PanContenedorVar->width()-1, 22));
      SbrBarraEstado->setFrameShape(QFrame::Panel);
      SbrBarraEstado->setFrameShadow(QFrame::Raised);
      SbrBarraEstado0 = new QFrame(SbrBarraEstado);
      SbrBarraEstado0->setObjectName(("SbrBarraEstado0"));
      SbrBarraEstado0->setGeometry(QRect(0, 0, SbrBarraEstado->width()/3 - 1, 19));
      SbrBarraEstado0->setFrameShape(QFrame::Box);
      SbrBarraEstado0->setFrameShadow(QFrame::Raised);
      LabBarraEstado0 = new QLabel(SbrBarraEstado0);
      LabBarraEstado0->setObjectName(("LabBarraEstado0"));
      LabBarraEstado0->setGeometry(QRect(3, 0, SbrBarraEstado0->width(), 19));
      SbrBarraEstado1 = new QFrame(SbrBarraEstado);
      SbrBarraEstado1->setObjectName(("SbrBarraEstado1"));
      SbrBarraEstado1->setGeometry(QRect(SbrBarraEstado0->width(), 0, SbrBarraEstado->width()/3 - 1, 19));
      SbrBarraEstado1->setFrameShape(QFrame::Box);
      SbrBarraEstado1->setFrameShadow(QFrame::Raised);
      LabBarraEstado1 = new QLabel(SbrBarraEstado1);
      LabBarraEstado1->setObjectName(("LabBarraEstado1"));
      LabBarraEstado1->setGeometry(QRect(3, 0, SbrBarraEstado1->width(), 19));
      SbrBarraEstado2 = new QFrame(SbrBarraEstado);
      SbrBarraEstado2->setObjectName(("SbrBarraEstado2"));
      SbrBarraEstado2->setGeometry(QRect(SbrBarraEstado1->x() + SbrBarraEstado1->width(), 0, SbrBarraEstado->width()/3, 19));
      SbrBarraEstado2->setFrameShape(QFrame::Box);
      SbrBarraEstado2->setFrameShadow(QFrame::Raised);
      LabBarraEstado2 = new QLabel(SbrBarraEstado2);
      LabBarraEstado2->setObjectName(("LabBarraEstado2"));
      LabBarraEstado2->setGeometry(QRect(3, 0, SbrBarraEstado2->width(), 19));

      PanIrA = new QFrame(PanContenedorVar);
      PanIrA->setObjectName(("PanIrA"));
      PanIrA->setGeometry(QRect(1, PanContenedorVar->height()-2-24-30, PanContenedorVar->width()-2, 30));
      view->setGeometry(QRect(1, 0, PanContenedorVar->width()-1, PanIrA->y()-2));
      PanIrA->setFrameShape(QFrame::Box);
      PanIrA->setFrameShadow(QFrame::Raised);
      LabIrAVariablePorNumero = new QLabel(PanIrA);
      LabIrAVariablePorNumero->setObjectName(("LabIrAVariablePorNumero"));
      LabIrAVariablePorNumero->setGeometry(QRect(3, 4, 140, 19));
      EdtIrAVariablePorNumero = new QLineEdit(PanIrA);
      EdtIrAVariablePorNumero->setObjectName(("EdtIrAVariablePorNumero"));
      EdtIrAVariablePorNumero->setGeometry(QRect(104, 4, 43, 21));
      LabIrAVariablePorNombre = new QLabel(PanIrA);
      LabIrAVariablePorNombre->setObjectName(("LabIrAVariablePorNombre"));
      LabIrAVariablePorNombre->setGeometry(QRect(190, 4, 140, 19));
      CbxIrAVariablePorNombre = new QComboBox(PanIrA);
      CbxIrAVariablePorNombre->setObjectName(("CbxIrAVariablePorNombre"));
      CbxIrAVariablePorNombre->setGeometry(QRect(301, 4, 145, 21));
      CbxIrAVariablePorNombre->setEditable(true);
      LabIrAtributo = new QLabel(PanIrA);
      LabIrAtributo->setObjectName(("LabIrAtributo"));
      LabIrAtributo->setGeometry(QRect(469, 4, 95, 19));
      CbxIrAAtributo = new QComboBox(PanIrA);
      CbxIrAAtributo->setObjectName(("CbxIrAAtributo"));
      CbxIrAAtributo->setGeometry(QRect(565, 4, 145, 21));
      menu = new QMenu( this);
      menu->addAction( QObject::tr(""));

      this->setWindowTitle(QApplication::translate("TFmeVariables", "Form"));
      view->setToolTip(QApplication::translate("TFmeVariables", "Rejilla de visualizaci\303\263n de variables.", 0));
      LabIrAVariablePorNombre->setText(QApplication::translate("TFmeVariables", "Ir a var. (nom)", 0));
      LabIrAtributo->setText(QApplication::translate("TFmeVariables", "Ir a atributo", 0));
      LabIrAVariablePorNumero->setText(QApplication::translate("TFmeVariables", "Ir a var. (num)", 0));
      CbxIrAVariablePorNombre->setToolTip(QApplication::translate("TFmeVariables", "Seleccione la variable que desea visualizar.", 0));
      CbxIrAAtributo->setToolTip(QApplication::translate("TFmeVariables", "Seleccione el atributo que desea visualizar.", 0));
      EdtIrAVariablePorNumero->setToolTip(QApplication::translate("TFmeVariables", "Indique un n\303\272mero de variable y pulse ENTER parar ir a ella.", 0));
      VisualizarVar->setToolTip(QApplication::translate("TFmeVariables", "Seleccione el modo de vizualizaci\303\263n de las variables.", 0));
      VisualizarVar->addItem(QApplication::translate("TFmeVariables", "Visualizar todas", 0));
      VisualizarVar->addItem(QApplication::translate("TFmeVariables", "Visualizar variables de trabajo", 0));

      QObject::connect(CbxIrAVariablePorNombre, SIGNAL(activated ( const int & ) ), this, SLOT(CbxIrAVariablePorNombreCloseUp(const int &)));
      QObject::connect(VisualizarVar, SIGNAL(activated ( const int & ) ), this, SLOT(VisualizarVarCloseUp(const int &)));
      QObject::connect(CbxIrAAtributo, SIGNAL(activated ( const int & ) ), this, SLOT(CbxIrAAtributoCloseUp(const int &)));
      QObject::connect(EdtIrAVariablePorNumero, SIGNAL(returnPressed ()), this, SLOT(EdtIrAVariablePorNumeroKeyDown()));
      QObject::connect(view, SIGNAL(doubleClicked(const QModelIndex&)), this, SLOT(SgrRejillaDblClick(const QModelIndex&)));
      QObject::connect(view, SIGNAL(clicked(const QModelIndex&)), this, SLOT(SgrRejillaSelectCell(const QModelIndex&)));
      QObject::connect(view->verticalHeader(), SIGNAL(sectionClicked ( const int & )), this, SLOT(SgrRejillaSelectCellV(const int &)));
      QObject::connect(view->horizontalHeader(), SIGNAL(sectionClicked ( const int & )), this, SLOT(SgrRejillaSelectCellH(const int &)));
      QObject::connect(view, SIGNAL(clicked(const QModelIndex&)), this, SLOT(VisualizarMenu(const QModelIndex&)));

      QMetaObject::connectSlotsByName(this);

      // Asociamos el nombre del conjunto
      this->NombreConjunto = NombreConjunto;
      this->NombreBaseDatos = NombreBaseDatos;
      this->Xml = Xml;
      // Fijamos un nombre
      this->Name = "FmeVariables" + NombreConjunto;
      this->Excel = excel;
      // Asociamos el memo de logs
      this->MemLogs = MemLogs;
      this->accion = Accion;
      // Conexion a la base de MicroDatos
      AdqConsulta = AdcConexionBD;

      // Fijamos el nombre de la tabla
      this->NombreTabla = NombreTabla;

      // Fijamos las variables
      this->ListaVariables = ListaVariables;
      this->Num_valores_missing = Num_valores_missing;
      this->Cadenas_Missing = Cadenas_Missing;

      // Consulta de Variables
      QString Campos = RealizarConsultaVariables();

      if (Campos == "false") *correcto = false;
      else {
        // Inicializar el vector de informacion de variables
        InicializarVectorInfoVariables();
        
        // Inicializar el vector de tipos de variables
        InicializarVectorTiposVariables();

        // Cargar las variables en la rejilla
        CargarVariablesEnRejilla(Campos);

        // Creamos el modelo y lo asignamos a la vista
        view->setModel(model);
        FijarAnchoColumnasRejilla();
        // Cargar las variables en la lista de seleccion
        CargarVariablesEnLista();

        // Cargar los atributos en la lista de seleccion
        CargarAtributosEnLista();

        // Asociar los valores missing
        MemLogs->append(tr("Asociando los valores missing de la tabla") + " \"" + NombreTablaMissing + "\"");
        QApplication::processEvents();
        if (AsociarValoresMissing(NombreTablaMissing)) {

          // Generar las listas de rangos
          MemLogs->append(tr("Generando los rangos de la tabla") + " \"" + NombreTabla + "\"");
          QApplication::processEvents();
          GenerarListasRangos();

          // Generar las Variables de los Edits de filtros
          GenerarVariablesFiltros();

          // Chequear la completitud de los atributos principales
          MemLogs->append(tr("Completitud de atributos de la tabla") + " \"" + NombreTabla + "\"");
          QApplication::processEvents();
          ChequearCompletitudAtributos();

          // Validar los filtros
          MemLogs->append(tr("Validando filtros de la tabla") + " \"" + NombreTabla + "\"");
          QApplication::processEvents();
          *correcto = ValidarFiltros();

          if (*correcto) {
            // Chequear las tablas de mapping
            MemLogs->append(tr("Validando la existencia y estructura de las tablas de mapping"));
            QApplication::processEvents();

            // Cargar la matriz de admision de missing
            CargarMatrizAdmisionMissing();

            // Cargar el vector de pesos de imputacion
            CargarVectorPesosImputacion();

            // Cargar el vector de variable imputable
            CargarVectorVariableImputable();

            // Cargar el vector de tipo de imputacion
            CargarVectorTipoImputacion();

            // Cargar el vector de filtros warning
            CargarVectorFiltrosWarning();

            // Calcular los porcentajes estadisticos
            CalcularEstadisticas();

            // Crear el vector de pertenencia a filtros
            CrearVectorPertenenciaFiltros();

            // Informacion general de las variables cargadas.
            MostrarInfoAsociada(0, 0, NumVariablesT, true);
            EscribirInformacion();
            model->setListaVariables(ListaVariables);
            QColor rojo = view->currentIndex().model()->data(view->currentIndex(), Qt::BackgroundRole).value<QColor>();
            QString color = rojo.name();
            setStyleSheet("selection-background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 " + color + ", stop: 1 gray);");

          }
        }else *correcto = false;
      }      
    }
    void TFmeVariables::ajustarSize ( )
    {
         //parentWidget()->ajustarSize ();
         //parentWidget()->resizeEvent(event);
         this->setGeometry(0, 0, parentWidget()->width()-2, parentWidget()->height()-15);

         PanContenedorVar->setGeometry(QRect(0, 0, this->width(), this->height()-50));
         VisualizarVar->setGeometry(PanContenedorVar->width()-220, 0, 200, 25);
         SbrBarraEstado->setGeometry(QRect(1, PanContenedorVar->height()-2-22, PanContenedorVar->width()-1, 22));

         SbrBarraEstado0->setGeometry(QRect(0, 0, SbrBarraEstado->width()/3 - 1, 19));

         LabBarraEstado0->setGeometry(QRect(3, 0, SbrBarraEstado0->width(), 19));

         LabBarraEstado1->setGeometry(QRect(3, 0, SbrBarraEstado1->width(), 19));

         LabBarraEstado2->setGeometry(QRect(3, 0, SbrBarraEstado2->width(), 19));

         PanIrA->setGeometry(QRect(1, PanContenedorVar->height()-2-24-30, PanContenedorVar->width()-2, 30));
         view->setGeometry(QRect(1, 0, PanContenedorVar->width()-1, PanIrA->y()-2));

    }
    /*void TFmeVariables::updateGeometry ()
    {
         //parentWidget()->ajustarSize ();
         //parentWidget()->resizeEvent(event);
         this->setGeometry(0, 0, parentWidget()->width()-2, parentWidget()->height()-15);

         PanContenedorVar->setGeometry(QRect(0, 0, this->width(), this->height()-50));
         VisualizarVar->setGeometry(PanContenedorVar->width()-220, 0, 200, 25);
         SbrBarraEstado->setGeometry(QRect(1, PanContenedorVar->height()-2-22, PanContenedorVar->width()-1, 22));

         SbrBarraEstado0->setGeometry(QRect(0, 0, SbrBarraEstado->width()/3 - 1, 19));

         LabBarraEstado0->setGeometry(QRect(3, 0, SbrBarraEstado0->width(), 19));

         LabBarraEstado1->setGeometry(QRect(3, 0, SbrBarraEstado1->width(), 19));

         LabBarraEstado2->setGeometry(QRect(3, 0, SbrBarraEstado2->width(), 19));

         PanIrA->setGeometry(QRect(1, PanContenedorVar->height()-2-24-30, PanContenedorVar->width()-2, 30));
         view->setGeometry(QRect(1, 0, PanContenedorVar->width()-1, PanIrA->y()-2));

    }*/
 /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
 // Guarda cuales son los valores missing validos segun lo indica en opciones.
 /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void TFmeVariables::AsociarMissingValidos(TFrmOpciones *FrmOpciones)
    {
      unsigned i;

      for (i = 0; i < Num_valores_missing; i++)
        MissingValidos[i] = FrmOpciones->GetMissingValido(i);
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Guarda los valores missing indicados en la tabla missing.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    bool TFmeVariables::AsociarValoresMissing(QString NombreTablaMissing)
    {
      QString CadenaSQL, Literal;
      int Codigo;
      unsigned i, j=0;

      if (Xml) {
        QDomDocument *doc = new QDomDocument("?xml");
        QDomNode n;
        QDomElement e, e1;
        QDomNode n1;

        QFile file(QDir::toNativeSeparators(NombreBaseDatos + NombreTablaMissing));
        if ((!file .open(QIODevice::ReadOnly)) || (!doc->setContent(&file)))
        {
          MemLogs->append("ERROR: " + tr("No se pudo realizar satisfactoriamente la consulta sobre la base de datos") +  " [\"" + NombreTablaMissing + "\"]");
          QApplication::processEvents();
          file.close();
          delete doc;
          return false;
        }
        //MemLogs->append(tr("Fichero xml cumple con el estandar W3C/XML"));
        QDomElement root = doc->documentElement();
        if (!root.tagName().contains("dataroot"))
         if (root.tagName() != "ROWSET")
         {
           MemLogs->append("ERROR: " + tr("No se pudo realizar satisfactoriamente la consulta sobre la base de datos") +  " [\"" + NombreTablaMissing + "\"]");
           QApplication::processEvents();
           file.close();
           delete doc;
           return false;
         }
        //MemLogs->append(tr("Leyendo fichero xml"));
        QApplication::processEvents();
        CadenaSQL = NombreTablaMissing;
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
                  if (e1.tagName() == "CODIGO") Codigo = e1.text().toInt();
                  if (e1.tagName() == "DESCRIPCION") Literal = e1.text();

                }
                n1 = n1.nextSibling();
              }
              i = Cadenas_Missing->indexOf(Literal);
              if (i != -1) VectorValoresMissing[i] = Codigo;
            }
          }
          n = n.nextSibling();
        }
        file.close();
        delete doc;
      }else {
        CadenaSQL = "SELECT CODIGO, DESCRIPCION FROM " + NombreTablaMissing;
        QSqlQuery query(CadenaSQL, *AdqConsulta);
        if (!query.isActive()) {        
          MemLogs->append("ERROR: " + tr("No se pudo realizar satisfactoriamente la consulta sobre la base de datos"));
          QApplication::processEvents();
          return false;
        }
        QSqlRecord record = query.record();
        QString pro;
        while (query.next()) {
          pro = query.value(record.indexOf("CODIGO")).toString().replace(".0", "");
          Codigo = pro.toInt();          
          Literal = query.value(record.indexOf("DESCRIPCION")).toString();

          i = Cadenas_Missing->indexOf(Literal);
          if (i != -1) VectorValoresMissing[i] = Codigo;
        }
      }
      // Crear los codigos y literales missing
      CrearCodigosLiteralesMissing();
      return true;
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Funciones relacionadas con los missing.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    int TFmeVariables::getVectorValoresMissing(int i) { return VectorValoresMissing[i]; }

    QStringList *TFmeVariables::GetCadenas_Missing() { return Cadenas_Missing; }

    int TFmeVariables::GetNum_valores_missing() { return Num_valores_missing; }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Carga las variables y atributos en los combobox.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void TFmeVariables::CargarVariablesEnLista()
    {
      CbxIrAVariablePorNombre->clear();
      for (int i = 0; i < model->rowCount(view->currentIndex()); i++)
        CbxIrAVariablePorNombre->addItem(model->data(model->index(i, 0, view->currentIndex()), Qt::DisplayRole).toString()); //*ListaVariables);
      CbxIrAVariablePorNombre->setCurrentIndex(0);
      CbxIrAVariablePorNombre->setInsertPolicy(QComboBox::NoInsert);
    }

    void TFmeVariables::CargarAtributosEnLista()
    {
      int i;

      for (i = 0; i < NUM_ATRIBUTOS_VARIABLE; i++) {
        CbxIrAAtributo->addItem(ATRIBUTOS_VARIABLE[i]);
        if (i == 7)
            for (int j = 0; j < Num_valores_missing; j++) CbxIrAAtributo->addItem(Cadenas_Missing->at(j));
      }
      CbxIrAAtributo->setCurrentIndex(0);
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Carga los datos en la rejilla.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void TFmeVariables::CargarVariablesEnRejilla(QString Campos)
    {
      unsigned j, IndiceVariable;
      QString Variable, str;
      QString valor;
      QString mapp;
      bool impar;      
      int i = 0;
      QString Aviso;
      bool filtro_vacio = false; // indica si el filtro es vacio
      int pos = -1; //indica si el filtro es vacio la posición de la columna sentido_filtro

      // Fijar el numero de filas de la rejilla      
      MatrizVariablesS = new QString*[NumVariables];
      MatrizVariablesT = new QString*[NumVariablesT];

      view->verticalHeader()->setDefaultSectionSize(20);

      // Fijamos los titulos de la rejilla
      FijarTitulosColumnasRejilla();      

      if (Xml) {
        QDomDocument *doc = new QDomDocument("?xml");
        QDomNode n;
        QDomElement e, e1;
        QDomNode n1;
        QString infvar, rang, filt, nom, infofilt, sent, id, tipo, imp, nproc, mapping, impnum, peso;
        infvar = rang = filt = nom = infofilt = sent = id = tipo = imp = nproc = mapping = impnum = peso = "";
        QMap<QString, QString> miss;

        QFile file(QDir::toNativeSeparators(NombreBaseDatos + NombreTabla));
        if ((!file .open(QIODevice::ReadOnly)) || (!doc->setContent(&file)))
        {
          MemLogs->append("ERROR: " + tr("No se pudo realizar satisfactoriamente la consulta sobre la base de datos") +  " [\"" + NombreTabla + "\"]");
          QApplication::processEvents();
          file.close();
          delete doc;
          return;
        }
        //MemLogs->append(tr("Fichero xml cumple con el estandar W3C/XML"));
        QDomElement root = doc->documentElement();
        if (!root.tagName().contains("dataroot"))
         if (root.tagName() != "ROWSET")
         {
           MemLogs->append("ERROR: " + tr("No se pudo realizar satisfactoriamente la consulta sobre la base de datos") +  " [\"" + NombreTabla + "\"]");
           QApplication::processEvents();
           file.close();
           delete doc;
           return;
         }
        //MemLogs->append(tr("Leyendo fichero xml"));
        QApplication::processEvents();
        str = NombreTabla;
        str.replace(".xml", "", Qt::CaseInsensitive);
        n = root.firstChild();
        while (!n.isNull())
        {
          sent = "";
          miss.clear();
          e = n.toElement();
          if (!e.isNull()) {
            if ((e.tagName() == str) || (e.tagName() == "ROW")) {
              n1 = n.firstChild();
              while (!n1.isNull())
              {
                e1 = n1.toElement();
                if (!e1.isNull()) {
                  if (e1.tagName() == "NOMBRE"){
                    nom = e1.text();                    
                  }else if (e1.tagName() == "INFO_VARIABLE") infvar = e1.text();
                       else if (e1.tagName() == "RANGO") rang = e1.text();
                            else if (e1.tagName() == "FILTRO") filt = e1.text();
                                 else if (e1.tagName() == "INFO_FILTRO") infofilt = e1.text();
                                      else if (e1.tagName() == "SENTIDO_FILTRO") sent = e1.text();
                                           else if (e1.tagName() == "ID") id = e1.text();
                                                else if (e1.tagName() == "IMPUTABLE") imp = e1.text();
                                                     else if (NOPROCEDE.contains(e1.tagName())) nproc = e1.text();
                                                          else if (Cadenas_Missing->contains(e1.tagName())) miss.insert(e1.tagName(), e1.text());
                                                               else if (e1.tagName() == "MAPPING")  mapping = e1.text();
                                                                              else if (e1.tagName() == "IMP_NUM") impnum = e1.text();
                                                                                   else if (e1.tagName() == "PESO") peso = e1.text();
                                                                                        else if (e1.tagName() == "TIPO") tipo = e1.text();
                }
                n1 = n1.nextSibling();
              }
            }
          }          
          MatrizVariablesT[i] = new QString[NumAtributos];
          if (ListaVariables->contains(nom)) {
            IndiceVariable = GetIndiceVariable(nom);
            MatrizVariablesS[IndiceVariable] = new QString[NumAtributos];
            if (((IndiceVariable) % 2) != 0) impar = true;
            else impar = false;
            VectorInfoVariables[IndiceVariable].Id = id.toInt();
            listaVT.append(id);
            for (j = 0; j < (unsigned)NumAtributos; j++) {
              if (listaH.at(j) == "TIPO") {
                MatrizVariablesS[IndiceVariable][j] = GetCadenaTipoVariable(VectorInfoVariables[IndiceVariable].TipoVariable);
                MatrizVariablesT[i][j] = GetCadenaTipoVariable((TTipoVariable)tipo.toInt());
                tipo = "";
              }else {
                if (listaH.at(j) == "IMPUTABLE") {
                    if (imp == "0") {
                      MatrizVariablesS[IndiceVariable][j] = "False";
                      MatrizVariablesT[i][j] = "False";
                    }else {
                      MatrizVariablesS[IndiceVariable][j] = "True";
                      MatrizVariablesT[i][j] = "True";
                    }
                  imp = "";
                }else
                  if (NOPROCEDE.contains(listaH.at(j)))  {                    
                    if (nproc.contains("0")) {
                        if (!filt.isEmpty()) {
                          MatrizVariablesS[IndiceVariable][j] = "True";
                          MatrizVariablesT[i][j] = "True";
                          Aviso += nom + "  ";
                        }else{
                          MatrizVariablesS[IndiceVariable][j] = "False";
                          MatrizVariablesT[i][j] = "False";
                        }
                    }else {
                      MatrizVariablesS[IndiceVariable][j] = "True";
                      MatrizVariablesT[i][j] = "True";
                    }
                    nproc = "";                    
                  }else
                    if (Cadenas_Missing->contains(listaH.at(j))){
                      if (miss.value(listaH.at(j)) == "0") {
                        MatrizVariablesS[IndiceVariable][j] = "False";
                        MatrizVariablesT[i][j] = "False";
                      }else {
                        MatrizVariablesS[IndiceVariable][j] = "True";
                        MatrizVariablesT[i][j] = "True";
                      }                      
                    }else
                         if (listaH.at(j) == "MAPPING") { // si es mapping
                            if (!mapping.isEmpty()) {
                              QFile filem(QDir::toNativeSeparators(NombreBaseDatos + mapping + ".xml"));
                              if (filem.exists ()) {    // si existe la tabla, en color negro                                
                                m.append(mapping);
                              }
                              MatrizVariablesS[IndiceVariable][j] = mapping;
                              MatrizVariablesT[i][j] = mapping;
                            }
                            mapping = "";
                          }else
                            if (listaH.at(j) == "SENTIDO_FILTRO") { // si es sentido filtro
                              if (!sent.isEmpty()){
                                MatrizVariablesS[IndiceVariable][j] = sent;
                                MatrizVariablesT[i][j] = sent;                                
                              }else {
                                MatrizVariablesS[IndiceVariable][j] = "a";
                                MatrizVariablesT[i][j] = "a";
                              }
                              pos = j;
                              sent = "";
                            }else// si no es TIPO ni SENTIDO_FILTRO ni ninguna de las True False O mapping
                              if (listaH.at(j) == "IMP_NUM") {
                                MatrizVariablesS[IndiceVariable][j] = impnum;
                                MatrizVariablesT[i][j] = impnum;
                                impnum = "";
                              }else
                                if (listaH.at(j) == "INFO_FILTRO"){
                                  MatrizVariablesS[IndiceVariable][j] = infofilt;
                                  MatrizVariablesT[i][j] = infofilt;
                                  infofilt = "";
                                }else
                                  if (listaH.at(j) == "FILTRO") {
                                    MatrizVariablesS[IndiceVariable][j] = filt;
                                    MatrizVariablesT[i][j] = filt;
                                    if (filt.isEmpty()) filtro_vacio = true;
                                    //filt = "";
                                  }else
                                    if (listaH.at(j) == "RANGO") {
                                      MatrizVariablesS[IndiceVariable][j] = rang;
                                      MatrizVariablesT[i][j] = rang;
                                      rang = "";
                                    }else
                                      if (listaH.at(j) == "INFO_VARIABLE") {
                                        MatrizVariablesS[IndiceVariable][j] = infvar;
                                        MatrizVariablesT[i][j] = infvar;
                                        infvar = "";
                                      }else
                                        if (listaH.at(j) == "NOMBRE") {
                                          MatrizVariablesS[IndiceVariable][j] = nom;
                                          MatrizVariablesT[i][j] = nom;
                                          //nom = "";
                                        }else
                                          if (listaH.at(j) == "ID"){
                                            MatrizVariablesS[IndiceVariable][j] = id;
                                            MatrizVariablesT[i][j] = id;
                                            id = "";
                                          }else
                                            if (listaH.at(j) == "PESO"){
                                              peso.replace('.', ',');
                                              MatrizVariablesS[IndiceVariable][j] = peso/*.replace(",0", "")*/;
                                              MatrizVariablesT[i][j] = peso/*.replace(",0", "")*/;
                                              peso = "";
                                            }
              }              
            } // fin for
            filt = "";
            nom = "";            
            if (filtro_vacio && (pos != -1)) {
                MatrizVariablesS[IndiceVariable][pos] = "";
                MatrizVariablesT[i][pos] = "";
                filtro_vacio = false;
                pos = -1;
            }
          }else {
            if (((i) % 2) != 0) impar = true;
            else impar = false;
            listaVT.append(id);
            for (j = 0; j < (unsigned)NumAtributos; j++) {
              if (listaH.at(j) == "TIPO") {
                MatrizVariablesT[i][j] = GetCadenaTipoVariable((TTipoVariable)tipo.toInt());
                tipo = "";
              }else {
                if (listaH.at(j) == "IMPUTABLE") {
                    if (imp == "0") {
                      MatrizVariablesT[i][j] = "False";
                    }else {
                      MatrizVariablesT[i][j] = "True";
                    }
                  imp = "";
                }else
                  if (NOPROCEDE.contains(listaH.at(j)))  {
                    if (nproc == "0") {                       
                      MatrizVariablesT[i][j] = "False";
                    }else {
                      MatrizVariablesT[i][j] = "True";
                    }
                    nproc = "";
                  }else
                    if (Cadenas_Missing->contains(listaH.at(j))){
                      if (miss.value(listaH.at(j)) == "0") {
                        MatrizVariablesT[i][j] = "False";
                      }else {
                        MatrizVariablesT[i][j] = "True";
                      }                      
                    }else
                         if (listaH.at(j) == "MAPPING") { // si es mapping
                            if (!mapping.isEmpty()) {
                              QFile filem(QDir::toNativeSeparators(NombreBaseDatos + mapping + ".xml"));
                              if (filem.exists ()) {    // si existe la tabla, en color negro
                                m.append(mapping);
                              }
                              MatrizVariablesS[IndiceVariable][j] = mapping;
                              MatrizVariablesT[i][j] = mapping;
                            }
                            mapping = "";
                          }else
                            if (listaH.at(j) == "SENTIDO_FILTRO") { // si es sentido filtro
                              if (!sent.isEmpty()){
                                MatrizVariablesT[i][j] = sent;
                              }else {
                                MatrizVariablesT[i][j] = "a";
                              }
                              pos = j;
                              sent = "";
                            }else// si no es TIPO ni SENTIDO_FILTRO ni ninguna de las True False O mapping
                              if (listaH.at(j) == "IMP_NUM") {
                                MatrizVariablesT[i][j] = impnum;
                                impnum = "";
                              }else
                                if (listaH.at(j) == "INFO_FILTRO"){
                                  MatrizVariablesT[i][j] = infofilt;
                                  infofilt = "";
                                }else
                                  if (listaH.at(j) == "FILTRO") {
                                    MatrizVariablesT[i][j] = filt;
                                    if (filt.isEmpty()) filtro_vacio = true;
                                    filt = "";
                                  }else
                                    if (listaH.at(j) == "RANGO") {
                                      MatrizVariablesT[i][j] = rang;
                                      rang = "";
                                    }else
                                      if (listaH.at(j) == "INFO_VARIABLE") {
                                        MatrizVariablesT[i][j] = infvar;
                                        infvar = "";
                                      }else
                                        if (listaH.at(j) == "NOMBRE") {
                                          MatrizVariablesT[i][j] = nom;
                                          nom = "";
                                        }else
                                          if (listaH.at(j) == "ID"){
                                            MatrizVariablesT[i][j] = id;
                                            id = "";
                                          }else
                                            if (listaH.at(j) == "PESO"){
                                              peso.replace('.', ',');
                                              MatrizVariablesT[i][j] = peso/*.replace(",0", "")*/;
                                              peso = "";
                                            }
              }              
            } // fin for
            if (filtro_vacio && (pos != -1)) {
                MatrizVariablesT[i][pos] = "";
                filtro_vacio = false;
                pos = 1;
            }
          }          
          i++;
          n = n.nextSibling();
        }
        file.close();
        delete doc;
      }else {        
        Campos += ", SENTIDO_FILTRO";        
        QSqlQuery query1("SELECT " + Campos + ", ID FROM " + NombreTabla + " ORDER BY ID", *AdqConsulta);
        QSqlRecord record1 = query1.record();
        if (record1.indexOf("SENTIDO_FILTRO") == -1) Campos.remove(", SENTIDO_FILTRO");
        QSqlQuery query("SELECT " + Campos + ", ID FROM " + NombreTabla + " ORDER BY ID", *AdqConsulta);
        QSqlRecord record = query.record();
        while (query.next()) {
          Variable = query.value(record.indexOf("NOMBRE")).toString();
          MatrizVariablesT[i] = new QString[NumAtributos];
          if (ListaVariables->contains(Variable)) {
            IndiceVariable = GetIndiceVariable(Variable);
            MatrizVariablesS[IndiceVariable] = new QString[NumAtributos];            
            if (((IndiceVariable) % 2) != 0) impar = true;
            else impar = false;
            VectorInfoVariables[IndiceVariable].Id = query.value(record.indexOf("ID")).toString().replace(".0", "").toInt();
            listaVT.append(query.value(record.indexOf("ID")).toString().replace(".0", ""));
            for (j = 0; j < (unsigned)NumAtributos; j++) {
                if (listaH.at(j) == "TIPO") {
                  MatrizVariablesS[IndiceVariable][j] = GetCadenaTipoVariable(VectorInfoVariables[IndiceVariable].TipoVariable);
                  MatrizVariablesT[i][j] = GetCadenaTipoVariable((TTipoVariable)query.value(record.indexOf("TIPO")).toInt());
                }else {
                  if ((listaH.at(j) == "IMPUTABLE") || (Cadenas_Missing->contains(listaH.at(j)))) {
                    valor = query.value(record.indexOf(listaH.at(j))).toString().replace(".0", "");
                    if (valor == "0") {
                      if ((NOPROCEDE.contains(listaH.at(j))) && (!query.value(record.indexOf("FILTRO")).toString().isEmpty())) {
                          MatrizVariablesS[IndiceVariable][j] = "True";
                          MatrizVariablesT[i][j] = "True";
                          Aviso += Variable + "  ";
                      }else {
                          MatrizVariablesS[IndiceVariable][j] = "False";
                          MatrizVariablesT[i][j] = "False";
                      }
                    }else{
                      MatrizVariablesS[IndiceVariable][j] = "True";
                      MatrizVariablesT[i][j] = "True";                    
                    }
                  }else {
                    if (listaH.at(j) == "MAPPING") { // si es mapping
                      mapp = query.value(record.indexOf("MAPPING")).toString();
                      if (!mapp.isEmpty()) {
                        if (Excel) str = "SELECT * FROM [" + mapp + "$]";
                        else str = "SELECT * FROM " + mapp;                    
                        QSqlQuery querym(str, *AdqConsulta);
                        if (querym.isActive())   // si existe la tabla, en color negro
                          m.append(mapp);
                        MatrizVariablesS[IndiceVariable][j] = query.value(record.indexOf("MAPPING")).toString();
                        MatrizVariablesT[i][j] = query.value(record.indexOf("MAPPING")).toString();
                      }
                    }else
                      if (listaH.at(j) == "SENTIDO_FILTRO") { // si es sentido filtro
                        if (query.value(record.indexOf("FILTRO")).toString().isEmpty())
                        {
                            MatrizVariablesS[IndiceVariable][j] = "";
                            MatrizVariablesT[i][j] = "";
                        }else{
                          if ((NumAtributos == Campos.count(',')+1) && (!query.value(record.indexOf("SENTIDO_FILTRO")).toString().isEmpty())) {
                            MatrizVariablesS[IndiceVariable][j] = query.value(record.indexOf("SENTIDO_FILTRO")).toString();
                            MatrizVariablesT[i][j] = query.value(record.indexOf("SENTIDO_FILTRO")).toString();
                          }else {
                            MatrizVariablesS[IndiceVariable][j] = "a";
                            MatrizVariablesT[i][j] = "a";
                          }
                        }
                      }else// si no es TIPO ni SENTIDO_FILTRO ni ninguna de las True False O mapping
                        if (listaH.at(j) == "PESO"){
                          MatrizVariablesS[IndiceVariable][j] = query.value(record.indexOf("PESO")).toString().replace('.', ',')/*.replace(",0", "")*/;
                          MatrizVariablesT[i][j] = query.value(record.indexOf("PESO")).toString().replace('.', ',')/*.replace(",0", "")*/;
                        }else
                          if (!query.value(record.indexOf(listaH.at(j))).toString().isEmpty()) {
                            MatrizVariablesS[IndiceVariable][j] = query.value(record.indexOf(listaH.at(j))).toString();
                            MatrizVariablesT[i][j] = query.value(record.indexOf(listaH.at(j))).toString();
                          }                        
                }
              }
            }
          }else
          {
            if (((i) % 2) != 0) impar = true;
            else impar = false;
            listaVT.append(query.value(record.indexOf("ID")).toString().replace(".0", ""));
            for (j = 0; j < (unsigned)NumAtributos; j++) {
              if (listaH.at(j) == "TIPO")
                MatrizVariablesT[i][j] = GetCadenaTipoVariable((TTipoVariable)query.value(record.indexOf("TIPO")).toInt());                
              else {
                if ((listaH.at(j) == "IMPUTABLE") || (Cadenas_Missing->contains(listaH.at(j)))) {
                  valor = query.value(record.indexOf(listaH.at(j))).toString().replace(".0", "");
                  if (valor == "0")                    
                    MatrizVariablesT[i][j] = "False";                    
                  else
                    MatrizVariablesT[i][j] = "True";                    
                }else {
                  if (listaH.at(j) == "MAPPING") { // si es mapping
                    mapp = query.value(record.indexOf("MAPPING")).toString();
                    if (!mapp.isEmpty()) {
                      if (Excel) str = "SELECT * FROM [" + mapp + "$]";
                      else str = "SELECT * FROM " + mapp;
                      QSqlQuery querym(str, *AdqConsulta);
                      if (querym.isActive())   // si existe la tabla, en color negro
                        m.append(mapp);
                      MatrizVariablesT[i][j] = query.value(record.indexOf("MAPPING")).toString();
                    }
                  }else
                    if (listaH.at(j) == "SENTIDO_FILTRO") { // si es sentido filtro
                      if (query.value(record.indexOf("FILTRO")).toString().isEmpty())
                      {
                          MatrizVariablesT[i][j] = "";
                      }else{
                        if ((NumAtributos == Campos.count(',')+1) && (!query.value(record.indexOf("SENTIDO_FILTRO")).toString().isEmpty())) {
                          MatrizVariablesT[i][j] = query.value(record.indexOf("SENTIDO_FILTRO")).toString();
                        }else
                          MatrizVariablesT[i][j] = "a";
                      }
                    }else// si no es TIPO ni SENTIDO_FILTRO ni ninguna de las True False O mapping
                      if (listaH.at(j) == "PESO"){
                        MatrizVariablesT[i][j] = query.value(record.indexOf("PESO")).toString().replace('.', ',')/*.replace(",0", "")*/;
                      }else
                        if (!query.value(record.indexOf(listaH.at(j))).toString().isEmpty())
                          MatrizVariablesT[i][j] = query.value(record.indexOf(listaH.at(j))).toString();                        
                }
              }
            }
          }
          i++;
        }
      }      
      if (!Aviso.isEmpty()) {
        TFrmAvisoFiltro *avisoFiltro = new TFrmAvisoFiltro(0, "AvisoFiltro", Qt::Widget, Aviso, accion);
        avisoFiltro->show();        
      }
      // Fijamos los ids de las filas
      FijarIdsFilasRejilla();      
      model = new TablaModelV(0, MatrizVariablesT, listaH, listaVT);
      model->setVectorMappingExiste(m);      
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Chequea que los datos vacios sean aquellos en lo que se permite un valor vacio.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void TFmeVariables::ChequearCompletitudAtributos()
    {
      unsigned i, j;
      QString Atributo;     
      for (i = 0; i < (unsigned)NumVariables; i++)
      {
        for (j = 0; j < (unsigned)NumAtributos; j++)
        {
          if ((listaH.at(j) == "FILTRO") || (listaH.at(j) == "INFO_FILTRO") || (listaH.at(j) == "SENTIDO_FILTRO") || (listaH.at(j) == "MAPPING") ||(listaH.at(j) == "INFO_VARIABLE") || (listaH.at(j) == "IMP_NUM"))
            continue;
          Atributo = MatrizVariablesS[i][j];          
          if (Atributo.isEmpty())
          {
            MemLogs->append("ERROR: i" + QString::number(i+1) + tr(" Atributo ") + listaH.at(j) + "; " + (QString)STR0049 + " " + GetNombreVariable(i) + " " + QApplication::translate("", "est\303\241 vac\303\255o", 0));
            QApplication::processEvents();
          }
        }
      }      
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Carga los valores missing.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void TFmeVariables::CargarMatrizAdmisionMissing()
    {
      unsigned i, j, h;

      for (i = 0; i < NumVariables; i++)
        for (j = 8, h = 0; h < Num_valores_missing; j++, h++)
          VectorInfoVariables[i].AdmisionMissing[h] = ((GetValorAtributo(i, (TTipoAtributo)j) == "True") ? true : false);
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Calcula las estadisticas.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    void TFmeVariables::CalcularEstadisticas()
    {
      double Aux;
      unsigned i, j, Indice;

      // Inicializacion
      for (j = 0; (int)j < NUM_TIPOS_VARIABLE; j++)
        NumTiposVariable[j] = 0;

      // Tipos de variables
      for (i = 0; i < NumVariables; i++)
        NumTiposVariable[VectorInfoVariables[i].TipoVariable]++;

      for (j = 0; (int)j < NUM_TIPOS_VARIABLE; j++)
        PorcentajesTiposVariable[j] = ((double)NumTiposVariable[j] / (double)NumVariables) * 100;

      // Porcentajes de admision de valores missing
      for (j = 0; j < Num_valores_missing; j++)
      {
        Aux = 0;
        for (i = 0; i < NumVariables; i++)
          Aux += VectorInfoVariables[i].AdmisionMissing[j];
        NumAdmisionMissing[j] = (unsigned)Aux;
        PorcentajesAdmisionMissing[j] = ((double)Aux / (double)NumVariables) * 100;
      }

      // Porcentajes de existencia de filtros
      Indice = GetIndiceAtributo("FILTRO");
      Aux = 0;
      for (i = 0; i < NumVariables; i++)
        if (!MatrizVariablesS[i][Indice].isEmpty())        
          Aux++;
      NumFiltros = (unsigned)Aux;
      PorcentajeFiltros = ((double)Aux / (double)NumVariables) * 100;

      // Porcentajes de variables imputables
      Indice = GetIndiceAtributo("IMPUTABLE");
      Aux = 0;
      for (i = 0; i < NumVariables; i++)
        if (MatrizVariablesS[i][Indice] == "True")        
          Aux++;
      NumVariablesImputables = (unsigned)Aux;
      PorcentajeVariablesImputables = ((double)Aux / (double)NumVariables) * 100;
    }
 /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
 // Carga los valores de los pesos.
 /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    void TFmeVariables::CargarVectorPesosImputacion()
    {
      unsigned i;

      for (i = 0; i < NumVariables; i++)
        VectorInfoVariables[i].Peso = (double)GetValorAtributo(i, ATR_PESO, Num_valores_missing).toDouble() / (double)MAX_PESO_VARIABLE;
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Crea el vector con las variables imputables.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    void TFmeVariables::CargarVectorVariableImputable()
    {
      unsigned i;

      VariablesNoImputables.clear();

      for (i = 0; i < NumVariables; i++)
      {
        VectorInfoVariables[i].Imputable = ((GetValorAtributo(i, ATR_IMPUTABLE) == "True") ? true : false);
        if (!VectorInfoVariables[i].Imputable)
          VariablesNoImputables.insert(i);
      }   
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Obtiene que variables pertencen a los filtros.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void TFmeVariables::CrearVectorPertenenciaFiltros()
    {
      unsigned i, j;

      // Rellenar el vector de pertenencia de filtros
      for (i = 0; i < NumVariables; i++)
      {
        VectorInfoVariables[i].FiltrosEnQueAparece.clear();
        VectorInfoVariables[i].FiltrosEnQueAparece.insert(i);
        for (j = 0; j < NumVariables; j++)
          if (VariableEnFiltro(i, j))
            VectorInfoVariables[i].FiltrosEnQueAparece.insert(j);
      }
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Consulta la tabla mapping de la base de datos
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
   void TFmeVariables::ConsultarTablaMapping(QString NombreTablaMapping)
    {
      QString CadenaSQL;
      QStringList *Codigos;
      QStringList *Literales;

      if (NombreTablaMapping.isEmpty())
        return;
      if (Xml) {
        QDomDocument *doc = new QDomDocument("?xml");
        QDomNode n;
        QDomElement e, e1;
        QDomNode n1;

        QFile file(QDir::toNativeSeparators(NombreBaseDatos + NombreTablaMapping + ".xml"));
        if ((!file .open(QIODevice::ReadOnly)) || (!doc->setContent(&file)))
        {
          file.close();
          return;
        }

        QDomElement root = doc->documentElement();
        if (!root.tagName().contains("dataroot"))
         if (root.tagName() != "ROWSET")
         {
           file.close();
           delete doc;
           return;
         }
        Codigos = new QStringList();
        Literales = new QStringList();
        Codigos->append("CODIGO");
        Literales->append("DESCRIPCION");
        n = root.firstChild();
        while (!n.isNull())
        {
          e = n.toElement();
          if (!e.isNull()) {
            if ((e.tagName() == NombreTablaMapping) || (e.tagName() == "ROW")) {
              n1 = n.firstChild();
              while (!n1.isNull())
              {
                e1 = n1.toElement();
                if (!e1.isNull()) {
                  if (e1.tagName() == "CODIGO") Codigos->append(e1.text().replace('.', ','));
                  if (e1.tagName() == "DESCRIPCION") Literales->append(e1.text());
                }
                n1 = n1.nextSibling();
              }
            }
          }
          n = n.nextSibling();
        }
        file.close();
        FrmMostrarMapping = new TFrmMostrarMapping(this, "mapping", Qt::Widget);
        FrmMostrarMapping->Mostrar(NombreTablaMapping, Codigos, Literales);

        delete Codigos;
        delete Literales;
        delete doc;
      }else {
        if (Excel) CadenaSQL = "SELECT * FROM [" + NombreTablaMapping + "$] ORDER BY CODIGO";
        else CadenaSQL = "SELECT * FROM " + NombreTablaMapping + " ORDER BY CODIGO";
        QSqlQuery query(CadenaSQL, *AdqConsulta);
        if (query.isActive()) {
          QSqlRecord record = query.record();
          Codigos = new QStringList();
          Literales = new QStringList();

          Codigos->append("CODIGO");
          Literales->append("DESCRIPCION");
          while (query.next()) {
            Codigos->append(query.value(record.indexOf("CODIGO")).toString().replace(".0", "").replace('.', ','));
            Literales->append(query.value(record.indexOf("DESCRIPCION")).toString());
          }
          FrmMostrarMapping = new TFrmMostrarMapping(this, "mapping", Qt::Widget);
          FrmMostrarMapping->Mostrar(NombreTablaMapping, Codigos, Literales);

          delete Codigos;
          delete Literales;
        }
      }
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Muestra la tabla missing.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void TFmeVariables::ConsultarTablaMissing()
    {
      FrmMostrarMapping = new TFrmMostrarMapping(this, "missing", Qt::Widget);
      FrmMostrarMapping->Mostrar("MISSING", CodigosMissing, LiteralesMissing);
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Crea vectores con los código y literales de los missing.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void TFmeVariables::CrearCodigosLiteralesMissing()                                       
    {
      unsigned i;
      QString x;

      CodigosMissing = new QStringList();
      LiteralesMissing = new QStringList();

      CodigosMissing->append("CODIGO");
      LiteralesMissing->append("DESCRIPCION");

      for (i = 0; i < Num_valores_missing; i++)
      {
        CodigosMissing->append(QString::number(VectorValoresMissing[i], 10));
        LiteralesMissing->append(Cadenas_Missing->at(i));
      }      
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Chequea si el mapping es valido o no.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void TFmeVariables::ChequearTablasMapping()
    {
      unsigned j;
      QString TablaMapping, CadenaSQL;      

      for (j = 0; j < NumVariables; j++)
      {
        TablaMapping = GetValorAtributo(j, ATR_MAPPING, Num_valores_missing);
        if (TablaMapping != "")
        {
          if (Xml) {
            QFile file(QDir::toNativeSeparators(NombreBaseDatos + TablaMapping));
            if (file.exists()) {
              VectorInfoVariables[j].MappingValido = true;
            }else {
              VectorInfoVariables[j].MappingValido = false;
            }
          }else {
            if (Excel) CadenaSQL = "SELECT CODIGO, DESCRIPCION FROM [" + TablaMapping + "$]";
            else CadenaSQL = "SELECT CODIGO, DESCRIPCION FROM " + TablaMapping;
            QSqlQuery query(CadenaSQL, *AdqConsulta);
            if (query.isActive()) {
              VectorInfoVariables[j].MappingValido = true;
            }else {
              VectorInfoVariables[j].MappingValido = false;
            }
          }
        }
      }
    }    
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Carga el vector con el tipo de imputacion.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void TFmeVariables::CargarVectorTipoImputacion()
    {
      unsigned i;
      QString Imp, Error, Var, Nd;
      bool Resultado;
      QMap<QString,double> mc;
      QMap<QString,double>::iterator Puntero;
      int v, a, b;
      double c;

      for (i = 0; i < NumVariables; i++)
      {
        Imp = GetValorAtributo(i, ATR_IMP_NUM, Num_valores_missing);
	VectorInfoVariables[i].NumDonantes = 0;
	if (Imp == "")
  	  VectorInfoVariables[i].TipoImputacion = T_DONANTE;
	else
	  if (Imp.mid(0, 7) == "MEDIANA")      // retorna un string que contiene 7 caracteres empezando en la posicion 0
	  {
	    VectorInfoVariables[i].TipoImputacion = T_MEDIANA;
	    Nd = Imp.mid(8);    	    
            if (Nd == "")
                  VectorInfoVariables[i].NumDonantes = DONANTES_NUMERICOS;
            else
                  VectorInfoVariables[i].NumDonantes = (unsigned)Nd.toInt();            
    	  }
	  else
	    if (Imp.mid(0, 7) == "MEDIA_R")
	    {
	      VectorInfoVariables[i].TipoImputacion = T_MEDIA_R;
	      Nd = Imp.mid(8);
              a = b = -1;
	      sscanf(QString(Nd).toLatin1(), "%d %d", &a, &b);
	      if ((a == -1) || (b == -1))
	      {
	        a = DONANTES_NUMERICOS;
		b = VALORES_RECORTADOS;
              }              
	      VectorInfoVariables[i].NumDonantes = (unsigned)a;
	      VectorInfoVariables[i].ValRec = (unsigned)b;
            }
	    else
	      if (Imp.mid(0, 5) == "MEDIA")
	      {
	        VectorInfoVariables[i].TipoImputacion = T_MEDIA;
	        Nd = Imp.mid(6);
                if (Nd == "")
                  VectorInfoVariables[i].NumDonantes = DONANTES_NUMERICOS;
                else
                  VectorInfoVariables[i].NumDonantes = (unsigned)Nd.toInt();                
	      }
	      else
	        if (Imp.mid(0, 4) == "MODA")
		{
		  VectorInfoVariables[i].TipoImputacion = T_MODA;
		  Nd = Imp.mid(5);
                  if (Nd == "")
                    VectorInfoVariables[i].NumDonantes = DONANTES_NUMERICOS;
                  else
                    VectorInfoVariables[i].NumDonantes = (unsigned)Nd.toInt();                  
		}
		else
		{
   		  VectorInfoVariables[i].TipoImputacion = T_REGRESION;
		  Resultado = GetValoresDeRegresion((char*)Imp.toLatin1().data(), &mc);
		  if (!Resultado)
		  {
            Error = QApplication::translate("", "Ecuaci\303\263n de regresi\303\263n", 0) + " " + Imp + "; " + (QString)STR0049 + " " + GetNombreVariable(i) + " " + QApplication::translate("", "est\303\241 mal escrita", 0);
                    MemLogs->append("ERROR: " + Error);
                    QApplication::processEvents();
		  }
   		  else
		  {
		    Puntero = mc.begin();
		    while (Puntero != mc.end())
		    {		      
		      Var = Puntero.key();
		      v = GetIndiceVariable(Var);
		      if ((v < 0) && (Var != "B0"))
                      {
                        Error = QApplication::translate("", "Ecuaci\303\263n de regresi\303\263n", 0) + " " + Imp + "; " + (QString)STR0049 + " " + GetNombreVariable(i) + " " + QApplication::translate("", "est\303\241 mal escrita", 0);
                        MemLogs->append("ERROR: " + Error);
                        QApplication::processEvents();
                      }                      
                      c = Puntero.value();                      
                      VectorInfoVariables[i].MapCoef.insert(v, c);
                      ++Puntero;
                    }
                  }
                }
      }
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Indica que variables son warning, es decir estan en filtro y son no imputables.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void TFmeVariables::CargarVectorFiltrosWarning()
    {
      QSet<unsigned>::iterator Puntero;
      QSet<unsigned> VariablesDeFiltro;
      unsigned i, IndiceVariable;
      bool VariableImputableEncontrada;

      for (i = 0; i < NumVariables; i++)
      {
        VariablesDeFiltro = VectorInfoVariables[i].VariablesDeFiltro;
        Puntero = VariablesDeFiltro.begin();
        VariableImputableEncontrada = false;
        while ((Puntero != VariablesDeFiltro.end()) && (!VariableImputableEncontrada))
        {
          IndiceVariable = (*Puntero);
          if (VectorInfoVariables[IndiceVariable].Imputable)
            VariableImputableEncontrada = true;
          ++Puntero;
        }
        VectorInfoVariables[i].FiltroWarning = !VariableImputableEncontrada;
      }
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Escribe la informacion en la parte de abajo de la pantalla.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void TFmeVariables::EscribirInformacion()
    {
      LabBarraEstado0->setText(QString::number(model->rowCount(view->currentIndex()), 10) + " " + (QString)STR0053 + ", " + QString::number(NumAtributos, 10) + " " + tr("Atributos"));
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Algunas funciones utiles.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    bool TFmeVariables::ExisteVariable(QString Variable)
    {
      if (GetIndiceVariable(Variable) == -1)
        return false;
      else
        return true;
    }

    QString TFmeVariables::getlistaH(int indice)
    {
      return listaH.at(indice);
    }

    QString TFmeVariables::getlistaV(int indice)
    {
      return listaV.at(indice);
    }

    QString TFmeVariables::getMatrizVariablesS(int fila, int col)
    {
      return MatrizVariablesS[fila][col];
    }

    bool TFmeVariables::EsValorMissing(double Valor)
    {
      unsigned i;

      for (i = 0; i < Num_valores_missing; i++)
        if (Valor == VectorValoresMissing[i])
          return true;
      return false;
    }

    bool TFmeVariables::EsVariableImputable(unsigned IndiceVariable)
    {
      return VectorInfoVariables[IndiceVariable].Imputable;
    }

    bool TFmeVariables::EsVariableIgnorable(QString Variable)
    {
      return (ListaVariablesIgnorables->indexOf(Variable) != -1);
    }

    bool TFmeVariables::EsFiltroWarning(unsigned IndiceVariable)
    {
      return VectorInfoVariables[IndiceVariable].FiltroWarning;
    }

    bool TFmeVariables::EsValorMissingAdmisible(unsigned IndiceVariable, TTipoMissing TipoMissing)
    {
      return VectorInfoVariables[IndiceVariable].AdmisionMissing[TipoMissing];
    }
    bool TFmeVariables::EsValorMissingAdmisible(unsigned IndiceVariable, QString TipoMissing)
    {
      return VectorInfoVariables[IndiceVariable].AdmisionMissing[Cadenas_Missing->indexOf(TipoMissing)];
    }
    bool TFmeVariables::EsValorMissingAdmisible(unsigned IndiceVariable, QStringList TipoMissing)
    {
      for (int i=0; i < TipoMissing.size(); i++)
        if (Cadenas_Missing->contains(TipoMissing.at(i)))
          return VectorInfoVariables[IndiceVariable].AdmisionMissing[Cadenas_Missing->indexOf(TipoMissing.at(i))];
      return false;
    }
    TTipoImputacionVariable TFmeVariables::GetTipoImputacion(unsigned IndiceVariable)
    {
      return VectorInfoVariables[IndiceVariable].TipoImputacion;
    }


    bool TFmeVariables::FiltrosValidados()
    {
      return (NumFiltrosValidados == NumVariables);
    }

    QString TFmeVariables::GetNombreTabla()
    {
      return NombreTabla;
    }

    QStringList *TFmeVariables::GetListaVariables()
    {
      return ListaVariables;
    }
    QStringList TFmeVariables::GetListaVariablesT()
    {
      QStringList aux;
      for (int i = 0; i < NumVariablesT; i++)
        aux.append(MatrizVariablesT[i][0]);
      return aux;
    }

    QStringList *TFmeVariables::GetListaVariablesIgnorables()
    {
      return ListaVariablesIgnorables;
    }

    int TFmeVariables::GetIndiceVariable(QString Variable)
    {
      return ListaVariables->indexOf(Variable);
    }

    QString TFmeVariables::GetNombreVariable(unsigned IndiceVariable)
    {
      return ListaVariables->at(IndiceVariable);
    }

    unsigned TFmeVariables::GetNumVariables()
    {
      return NumVariables;
    }
    unsigned TFmeVariables::GetNumVariablesT()
    {
      return NumVariablesT;
    }

    unsigned TFmeVariables::GetNumAtributos()
    {
      return NumAtributos;
    }

    TTipoVariable TFmeVariables::GetTipoVariable(QString Variable)
    {
      unsigned IndiceVariable;

      IndiceVariable = GetIndiceVariable(Variable);
      return VectorInfoVariables[IndiceVariable].TipoVariable;
    }

    TTipoVariable TFmeVariables::GetTipoVariable(unsigned IndiceVariable)
    {
      return VectorInfoVariables[IndiceVariable].TipoVariable;
    }

    QString TFmeVariables::GetValorAtributo(unsigned IndiceVariable, TTipoAtributo IndiceAtributo)
    {
      return MatrizVariablesS[IndiceVariable][(int)(IndiceAtributo)];
    }
    
    QString TFmeVariables::GetValorAtributo(unsigned IndiceVariable, TTipoAtributo IndiceAtributo, int mis)
    {
      return MatrizVariablesS[IndiceVariable][(int)(IndiceAtributo)+mis];
    }
    
    QList<double> TFmeVariables::GetValoresRangos(unsigned IndiceVariable)
    {
      return VectorInfoVariables[IndiceVariable].ValoresRango;
    }

    QMap<int,double> TFmeVariables::GetMapCoef(unsigned IndiceVariable)
    {
      return VectorInfoVariables[IndiceVariable].MapCoef;
    }

    int TFmeVariables::GetValorMissing(QString CadenaMissing)
    {
      unsigned i;

      for (i = 0; i < Num_valores_missing; i++)
        if (Cadenas_Missing->at(i) == CadenaMissing)
          return VectorValoresMissing[i];
      return 0;
    }
    int TFmeVariables::GetValorMissing(QStringList CadenaMissing)
    {
      unsigned i;

      for (i = 0; i < Num_valores_missing; i++)
        if (CadenaMissing.contains(Cadenas_Missing->at(i)))
          return VectorValoresMissing[i];
      return 0;
    }
    
    QMap <QString, double> TFmeVariables::GetMapMissing()
    {
      unsigned i;
      QMap <QString, double> mapp;
      for (i = 0; i < Num_valores_missing; i++)
        mapp.insert(Cadenas_Missing->at(i), VectorValoresMissing[i]);
      return mapp;
    }
    
    int TFmeVariables::GetValorMissing(TTipoMissing TipoMissing)
    {
      switch(TipoMissing)
      {
        case T_NO_PROCEDE:
          return VectorValoresMissing[0];
        case T_NO_SABE:
          return VectorValoresMissing[1];
        case T_NO_CONTESTA:
          return VectorValoresMissing[2];
        case T_NS_NC:
          return VectorValoresMissing[3];
        default:
          return 0;
      }
    }

    QString TFmeVariables::GetCadenaMissing(int ValorMissing)
    {
      unsigned i;

      for (i = 0; i < Num_valores_missing; i++)
        if (VectorValoresMissing[i] == ValorMissing)
          return Cadenas_Missing->at(i);
      return "";
    }
    QString TFmeVariables::GetCadenaMissing(double ValorMissing)
    {
      unsigned i;

      for (i = 0; i < Num_valores_missing; i++)
        if (VectorValoresMissing[i] == ValorMissing)
          return Cadenas_Missing->at(i);
      return "";
    }
    int TFmeVariables::GetIndiceAtributo(QString Atributo)
    {
      unsigned j;

      for (j = 0; j < (unsigned)NumAtributos; j++)
        if (listaH.at(j) == Atributo)
          return j;
      return -1;
    }

    double TFmeVariables::GetPorcentajeFiltros()
    {
      return PorcentajeFiltros;
    }

    double TFmeVariables::GetPorcentajeVariablesImputables()
    {
      return PorcentajeVariablesImputables;
    }

    double TFmeVariables::GetPorcentajeTiposVariable(int TipoVariable)
    {
      return PorcentajesTiposVariable[TipoVariable];
    }

    double TFmeVariables::GetPorcentajeAdmisionMissing(int TipoMissing)
    {
      return PorcentajesAdmisionMissing[TipoMissing];
    }

    unsigned TFmeVariables::GetNumFiltros()
    {
      return NumFiltros;
    }

    unsigned TFmeVariables::GetNumVariablesImputables()
    {
      return NumVariablesImputables;
    }

    unsigned TFmeVariables::GetNumTiposVariable(int TipoVariable)
    {
      return NumTiposVariable[TipoVariable];
    }

    unsigned TFmeVariables::GetNumAdmisionMissing(int TipoMissing)
    {
      return NumAdmisionMissing[TipoMissing];
    }

    unsigned TFmeVariables::GetIdVariable(unsigned IndiceVariable)
    {
      return VectorInfoVariables[IndiceVariable].Id;
    }

    QTextEdit *TFmeVariables::GetMemLogs()
    {
      return MemLogs;
    }



    QString TFmeVariables::GetCadenaTipoVariable(TTipoVariable TipoVariable)
    {
      switch(TipoVariable)
      {
        case T_CONTINUO:
          return (tr("CONTINUO"));
        case T_DISCRETO:
          return (tr("DISCRETO EN LISTA"));
        case T_MIXTO:
          return (tr("DISCRETO EN RANGO"));
        case T_IGNORABLE:
          return (tr("IGNORABLE"));
        default:
          break;
      }
      return (tr("DESCONOCIDO"));
    }

    QSet<unsigned> TFmeVariables::GetConjuntoDesdeLista(QStringList *Lista)
    {
      unsigned i, IndiceVariable;
      QSet<unsigned> Conjunto;

      for (i = 0; i < (unsigned)Lista->size(); i++)
      {
        IndiceVariable = GetIndiceVariable(Lista->at(i));
        Conjunto.insert(IndiceVariable);
      }
      return Conjunto;
    }

    QSet<unsigned> TFmeVariables::GetVariablesFiltros(unsigned IndiceFiltro)
    {
      return VectorInfoVariables[IndiceFiltro].VariablesDeFiltro;
    }

    double TFmeVariables::GetPesoImputacion(unsigned IndiceVariable)
    {
      return VectorInfoVariables[IndiceVariable].Peso;
    }

    QString TFmeVariables::GetNombreConjunto()
    {
      return NombreConjunto;
    }

    QSet<unsigned> TFmeVariables::GetVariablesNoImputables()
    {
      return VariablesNoImputables;
    }

    QString TFmeVariables::GetCadenaEditRango(unsigned IndiceVariable)
    {
      TTipoVariable TipoVariable;
      QString Edit = "";
      double ValorMin, ValorMax;
      QString NombreVariable, Aux = "";
      QList<double>::iterator Puntero;

      NombreVariable = GetNombreVariable(IndiceVariable);
      TipoVariable = GetTipoVariable(IndiceVariable);
      switch(TipoVariable)
      {
        case T_CONTINUO:
          ValorMin = VectorInfoVariables[IndiceVariable].ValoresRango.front();
          ValorMax = VectorInfoVariables[IndiceVariable].ValoresRango.back();
          Edit = NombreVariable + " IN [" + QString::number(ValorMin, 'g', 6) + "," + QString::number(ValorMax, 'g', 6) + "] (C)";
          break;
        // discreto en lista
        case T_DISCRETO:
          Edit = NombreVariable + " IN {";
          Puntero = VectorInfoVariables[IndiceVariable].ValoresRango.begin();
          while (Puntero != VectorInfoVariables[IndiceVariable].ValoresRango.end())
          {
            Aux += QString::number(*Puntero, 'g', 6);
            ++Puntero;
            if (Puntero != VectorInfoVariables[IndiceVariable].ValoresRango.end())
              Aux += ",";
          }
          Edit += (Aux + "}");
          break;
        // discreto en rango
        case T_MIXTO:
          ValorMin = VectorInfoVariables[IndiceVariable].ValoresRango.front();
          ValorMax = VectorInfoVariables[IndiceVariable].ValoresRango.back();
          Edit = NombreVariable + " IN [" + QString::number(ValorMin, 'g', 6) + "," + QString::number(ValorMax, 'g', 6) + "] (D)";
          break;
        default:
          Edit = "";
      }
      return Edit;
    }

    QString TFmeVariables::GetCadenaEditFiltro(unsigned IndiceVariable)
    {
      QString Filtro, NombreVariable, Edit, Noprocede;
      unsigned IndiceColumna;

      IndiceColumna = GetIndiceAtributo("SENTIDO_FILTRO");
      Filtro = GetValorAtributo(IndiceVariable, ATR_FILTRO);
      if (Filtro.isEmpty())
        return "";
      NombreVariable = GetNombreVariable(IndiceVariable);
      for (int i = 0; i < NOPROCEDE.size(); i++)
        if (Cadenas_Missing->contains(NOPROCEDE.at(i)))
            Noprocede = NOPROCEDE.at(i);

      if (MatrizVariablesS[IndiceVariable][IndiceColumna] == "a")
            Edit = "IF NOT(" + Filtro + ") THEN (" + NombreVariable + " = " + Noprocede + ")";
      else
        if (MatrizVariablesS[IndiceVariable][IndiceColumna] == "b")
            Edit = "IF (" + Filtro + ") then (" + NombreVariable + " != " + Noprocede + ")";
        else
            if (MatrizVariablesS[IndiceVariable][IndiceColumna] == "c")
                Edit = "(" + Filtro + ") <=> (" + NombreVariable + " != " + Noprocede + ")";
      return Edit;
    }

    unsigned TFmeVariables::GetNumFiltrosVariable(unsigned IndiceVariable)
    {
      return VectorInfoVariables[IndiceVariable].FiltrosEnQueAparece.size();
    }

    QSet<unsigned> TFmeVariables::GetFiltrosConVariable(unsigned IndiceVariable)
    {
      return VectorInfoVariables[IndiceVariable].FiltrosEnQueAparece;
    }

    double TFmeVariables::GetFrontRango(unsigned IndiceVariable)
    {
      return VectorInfoVariables[IndiceVariable].ValoresRango.front();
    }

    double TFmeVariables::GetBackRango(unsigned IndiceVariable)
    {
      return VectorInfoVariables[IndiceVariable].ValoresRango.back();
    }

    double TFmeVariables::GetValorAleatorioRango(unsigned IndiceVariable)
    {
      unsigned i, num_valores, h, dif;
      QList<double> Valores;
      QList<double>::iterator Puntero;
      TTipoVariable TipoVariable;
      double min, max, v;

      Valores = VectorInfoVariables[IndiceVariable].ValoresRango;
      TipoVariable = GetTipoVariable(IndiceVariable);
      switch(TipoVariable)
      {
        case T_CONTINUO:
          min = Valores.front();
          max = Valores.back();
          dif = max - min;
          v = (rand() % dif) + min;
          break;
        /* Tipo Discreto */
        case T_DISCRETO:
          num_valores = Valores.size();
          Puntero = Valores.begin();
          h = rand() % num_valores;
          for (i = 0; i < h; i++)
            ++Puntero;
          v = (*Puntero);
          break;
        /* Tipo Mixto */
        case T_MIXTO:
          min = Valores.front();
          max = Valores.back();
          dif = max - min;
          v = (unsigned)((rand() % dif) + min);
          break;
        default:
          break;
      }
      return v;
    }

    unsigned TFmeVariables::GetNumDonantes(unsigned IndiceVariable)
    {
      return VectorInfoVariables[IndiceVariable].NumDonantes;
    }

    unsigned TFmeVariables::GetValRec(unsigned IndiceVariable)
    {
      return VectorInfoVariables[IndiceVariable].ValRec;
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Inicializa los valores de la rejilla.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void TFmeVariables::FijarAnchoColumnasRejilla()
    {
       int i;
          int j = 0;
          for (i = 0; i < NumAtributos; i++)
                if ((i > 7) && (i < 8 + Num_valores_missing)) view->setColumnWidth(i, 100);
                else {
                  view->setColumnWidth(i, ANCHOS_VARIABLE[j]);
                  j++;
          }
     }
     void TFmeVariables::FijarTitulosColumnasRejilla()
     {
          int j;

          for (j = 0; j < NUM_ATRIBUTOS_VARIABLE; j++) {
                  if (j == 8) {
                      for (int i = 0; i < Num_valores_missing; i++) {
                        listaH.append(Cadenas_Missing->at(i));
                      }
                      listaH.append(ATRIBUTOS_VARIABLE[j]);
                  }else {
                    listaH.append(ATRIBUTOS_VARIABLE[j]);
                  }
          }
      }

      void TFmeVariables::FijarIdsFilasRejilla()
      {
          unsigned i;
          for (i = 0; i < (unsigned)NumVariables; i++) {
             listaV.append(QString::number(VectorInfoVariables[i].Id, 10).replace(".0", ""));
          }
      }

      void TFmeVariables::FijarCantidadDatos()
      {
          QSqlQuery query("SELECT * FROM " + NombreTabla, *AdqConsulta);          
          NumVariables = query.size();          
      }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Comprueba que el tipo de rango concuerda con los valores de rango dados.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
      void TFmeVariables::GenerarListasRangos()
      {
          unsigned i;
          TResultadoRangos Resultado;
          QString Error, Rango;
          TTipoVariable Tipo;

          for (i = 0; i < NumVariables; i++)
          {
            Rango = GetValorAtributo(i, ATR_RANGO);
            Tipo = GetTipoVariable(i);
            Resultado = GetValoresDeRango((char*)Rango.toLatin1().data(), &VectorInfoVariables[i].ValoresRango);            
            Error = tr("Rango") + " " + Rango + "; " + (QString)STR0049 + " " + GetNombreVariable(i);
            if (Resultado == ERROR_RANGO)
            {
              Error += " " + QApplication::translate("", "est\303\241 mal escrita", 0);
              MemLogs->append("ERROR: " + Error);
              QApplication::processEvents();
            }
            if ((Resultado == RANGO_COMAS) && (Tipo != T_DISCRETO))
            {
              Error += " " + tr("es incoherente");
              MemLogs->append("ERROR: " + Error);
              QApplication::processEvents();
            }
            if ((Resultado == RANGO_PUNTOS) && (Tipo == T_DISCRETO))
            {
              Error += " " + tr("es incoherente");
              MemLogs->append("ERROR: " + Error);
              QApplication::processEvents();
            }
          }
      }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Obtiene las variables de los filtros.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
      void TFmeVariables::GenerarVariablesFiltros()
      {
          QStringList *Variables;
          unsigned i;

          for (i = 0; i < NumVariables; i++)
          {
            Variables = GetVariablesDeEdit(GetValorAtributo(i, ATR_FILTRO));
            VectorInfoVariables[i].VariablesDeFiltro = GetConjuntoDesdeLista(Variables);
          }
      }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Obtiene el vector con el nombre de la variable y su tipo.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
      void TFmeVariables::InicializarVectorTiposVariables()
      {
      unsigned IndiceVariable;
      if (Xml) {
        QDomDocument *doc = new QDomDocument("?xml");
        QDomNode n;
        QDomElement e, e1;
        QDomNode n1;

        QFile file(QDir::toNativeSeparators(NombreBaseDatos + NombreTabla));
        if ((file.open(QIODevice::ReadOnly)) && (doc->setContent(&file))) {
          QDomElement root = doc->documentElement();
          n = root.firstChild();
          QString CadenaSQL = NombreTabla;
          CadenaSQL.replace(".xml", "", Qt::CaseInsensitive);
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
                    if (e1.tagName() == "NOMBRE") IndiceVariable = GetIndiceVariable(e1.text());
                    if (e1.tagName() == "TIPO") if (IndiceVariable != -1) VectorInfoVariables[IndiceVariable].TipoVariable = (TTipoVariable)e1.text().toInt();
                  }
                  n1 = n1.nextSibling();
                }
              }
            }
            n = n.nextSibling();
          }
          file.close();
        }
        delete doc;
      }else {
        double entero;        
        QSqlQuery query("SELECT NOMBRE, TIPO FROM " + NombreTabla + " ORDER BY ID", *AdqConsulta);
        QSqlRecord record = query.record();
        while (query.next()) {          
          if (ListaVariables->contains(query.value(record.indexOf("NOMBRE")).toString())) {
            IndiceVariable = GetIndiceVariable(query.value(record.indexOf("NOMBRE")).toString());
            entero = query.value(record.indexOf("TIPO")).toDouble();
            VectorInfoVariables[IndiceVariable].TipoVariable = (TTipoVariable)(int)entero;
          }
        }
      }
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Inicializa el vector global.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void TFmeVariables::InicializarVectorInfoVariables()
    {
      VectorInfoVariables = new InfoVariables[NumVariables];
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Muestra la informacion asociada a una variable.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void TFmeVariables::MostrarInfoAsociada(unsigned Fila, unsigned Columna, unsigned numvar, bool Fijar)
    {
        if (numvar == 0)
          LabBarraEstado2->setText(tr("VARIABLE 0/0"));
        else
        {
          if (Columna < 8) LabBarraEstado1->setText(tr(QString(DESCRIPCION_ATRIBUTOS_VARIABLE[Columna]).toLatin1(), ""));
          else
              if (Columna > 7 + Num_valores_missing) LabBarraEstado1->setText(tr(QString(DESCRIPCION_ATRIBUTOS_VARIABLE[Columna-Num_valores_missing]).toLatin1(), ""));
              else LabBarraEstado1->setText(listaH.at(Columna));
          LabBarraEstado2->setText("VARIABLE " + QString::number(Fila+1, 10) + "/" + QString::number(numvar, 10) + "  (" + listaH.at(Columna) + ")");

          if (Fijar) {
            view->setCurrentIndex(view->indexAt(QPoint(view->columnViewportPosition(Columna), view->rowViewportPosition(Fila))));            
          }
        }
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Consulta de la tabla variables.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    QString TFmeVariables::RealizarConsultaVariables()
    {
      unsigned i;
      QString Campos = "", CadenaSQL, Variable;
      int IndiceVariableEnLista;
      QStringList *ListaCheck;
      int tam;
      NumVariablesT = 0;
      // Creacion de la cadena de atributos para la consulta SQL
      for (i = 0; i < (NUM_ATRIBUTOS_VARIABLE - 1); i++)
          if (ATRIBUTOS_VARIABLE[i] == "TIPO") {
            Campos += (ATRIBUTOS_VARIABLE[i] + ", "); // coloca TIPO
            for (int j = 0; j < Num_valores_missing; j++)
                Campos += Cadenas_Missing->at(j) + ", ";   // despues de tipo van los missing
          }else
             if (ATRIBUTOS_VARIABLE[i] != "SENTIDO_FILTRO")
               Campos += (ATRIBUTOS_VARIABLE[i] + ", ");
      Campos += ATRIBUTOS_VARIABLE[NUM_ATRIBUTOS_VARIABLE - 1];

      // Consulta de Variables
      MemLogs->append(tr("Cargando variables de la tabla") + " \"" + NombreTabla + "\"");
      QApplication::processEvents();
      if (Xml) {
        QDomDocument *doc = new QDomDocument("?xml");
        QDomNode n;
        QDomElement e, e1;
        QDomNode n1;
        QString nom, tipo;
        QFile file(QDir::toNativeSeparators(NombreBaseDatos + NombreTabla));
        if ((!file.open(QIODevice::ReadOnly)) || (!doc->setContent(&file)))
        {
          MemLogs->append("ERROR: " + tr("No se pudo realizar satisfactoriamente la consulta sobre la base de datos") +  " [\"" + NombreTabla + "\"]");
          QApplication::processEvents();
          file.close();
          delete doc;
          return "false";
        }
        //MemLogs->append(tr("Fichero xml cumple con el estandar W3C/XML"));
        QDomElement root = doc->documentElement();
        if (!root.tagName().contains("dataroot"))
         if (root.tagName() != "ROWSET")
         {
           MemLogs->append("ERROR: " + tr("No se pudo realizar satisfactoriamente la consulta sobre la base de datos") +  " [\"" + NombreTabla + "\"]");
           QApplication::processEvents();
           file.close();
           delete doc;
           return "false";
         }
        //MemLogs->append(tr("Leyendo fichero xml"));
        QApplication::processEvents();

        ListaVariablesIgnorables = new QStringList();
        ListaCheck = new QStringList();

        CadenaSQL = NombreTabla;
        CadenaSQL.replace(".xml", "", Qt::CaseInsensitive);
        n = root.firstChild();
        tam = 0;
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
                  if (e1.tagName() == "NOMBRE") nom = e1.text();
                  if (e1.tagName() == "TIPO") tipo = e1.text();
                }
                n1 = n1.nextSibling();
              }
              IndiceVariableEnLista = ListaVariables->indexOf(nom);
              NumVariablesT++;
              if (IndiceVariableEnLista != -1)
              {
                if (tipo.toInt() == T_IGNORABLE)
                {
                  ListaVariables->removeAt(IndiceVariableEnLista);
                  ListaVariablesIgnorables->append(nom);
                }
                else
                {
                  ListaCheck->append(nom);
                }
              }
            }
          }
          n = n.nextSibling();
          tam++;
        }
        file.close();
        delete doc;
      }else {        
        CadenaSQL = "SELECT " + Campos + ", ID FROM " + NombreTabla + " ORDER BY ID";      
        QSqlQuery query(CadenaSQL, *AdqConsulta);
        
        if (!query.isActive ()) {
          MemLogs->append(tr("No se pudo realizar satisfactoriamente la consulta sobre la tabla ") + NombreTabla + tr(". Compruebe que tiene los campos exigidos."));
          QApplication::processEvents();
          return "false";
        }

        ListaVariablesIgnorables = new QStringList();
        ListaCheck = new QStringList();

        QSqlRecord record = query.record();
        tam = 0;
        while (query.next()) {
          Variable = query.value(record.indexOf("NOMBRE")).toString();
          IndiceVariableEnLista = ListaVariables->indexOf(Variable);
          NumVariablesT++;        
          if (IndiceVariableEnLista != -1)
          {
            if (query.value(record.indexOf("TIPO")).toDouble() == T_IGNORABLE)
            {
              ListaVariables->removeAt(IndiceVariableEnLista);              
              ListaVariablesIgnorables->append(Variable);            
            }
            else
            {
              ListaCheck->append(Variable);            
            }
          }
          tam++;
        }
      }

      if (tam != ListaVariables->size())
      {
        for (i = 0; i < (unsigned)ListaVariables->size(); i++)
          if (!ListaCheck->contains(ListaVariables->at(i)))
          {            
            MemLogs->append("ERROR: " + (QString)STR0049 + " " + ListaVariables->at(i) + " " + QApplication::translate("", "se usa en los microdatos pero no est\303\241 definida en las variables. Compruebe que esa variable se llama igual en los microdatos y el campo nombre de variables. Compruebe MAYUSCULAS y minusculas.", 0));
            QApplication::processEvents();  return "false"; break;
          }
      }
      delete ListaCheck;

      NumVariables = ListaVariables->size();
      NumAtributos = NUM_ATRIBUTOS_VARIABLE + Num_valores_missing;      
      return Campos;
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Comprueba que un valor esta dentro de un rango o valor missing.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    bool TFmeVariables::ValorEnRango(double Valor, unsigned IndiceVariable)
    {
      TTipoVariable TipoVariable;
      unsigned j;
      double rangoMin;
      double rangoMax;

      TipoVariable = GetTipoVariable(IndiceVariable);
      try
      {
        // Admision de valores missing
        for (j = 0; j < Num_valores_missing; j++)
        {
          if (Valor == VectorValoresMissing[j])
          {
            if (MissingValidos[j])
              return true;
            else
              if (VectorInfoVariables[IndiceVariable].AdmisionMissing[j])
                return true;
              else
                return false;
          }
        }

        switch(TipoVariable)
        {
          /* Tipo Continuo */
          case T_CONTINUO:
            if ((Valor >= VectorInfoVariables[IndiceVariable].ValoresRango.front()) && (Valor <= VectorInfoVariables[IndiceVariable].ValoresRango.back()))
              return true;
            else
              return false;
          /* Tipo Discreto */
          case T_DISCRETO:
            if (std::find(VectorInfoVariables[IndiceVariable].ValoresRango.begin(), VectorInfoVariables[IndiceVariable].ValoresRango.end(), Valor) != VectorInfoVariables[IndiceVariable].ValoresRango.end())
              return true;
            else
              return false;
          /* Tipo Mixto */
          case T_MIXTO:
            rangoMin = VectorInfoVariables[IndiceVariable].ValoresRango.front();
            rangoMax = VectorInfoVariables[IndiceVariable].ValoresRango.back();
            if ((fabs(Valor - rangoMin) < 0.000001) || (fabs(Valor - rangoMax) < 0.000001) || ((Valor > rangoMin) && (Valor < rangoMax)))
               return true;
            else
              return false;
          default:
            return false;
        }
      }
      catch (...)
      {
        return false;
      }
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Indica si una variable esta en un filtro.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    bool TFmeVariables::VariableEnFiltro(unsigned IndiceVariable, unsigned IndiceFiltro)
    {
      try
      {
        if (VectorInfoVariables[IndiceFiltro].VariablesDeFiltro.contains(IndiceVariable))
          return true;
        else
          return false;
      }
      catch (...)
      {
        return false;
      }
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Evalua el filtro.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    bool TFmeVariables::ValidarFiltros()
    {
      unsigned i;
      QMap<QString,double> MapTest;
      QString Filtro, Variable;
      QMap<QString,double> mappM;

      // Creamos un map de test
      for (i = 0; i < NumVariables; i++)
      {
        Variable = ListaVariables->at(i);        
        MapTest.insert(Variable, 0);
      }
      mappM = GetMapMissing();      
      for (i = 0; i < NumVariables; i++)
      {
        Filtro = GetValorAtributo(i, ATR_FILTRO);        
        if ((!Filtro.isEmpty()) && (EvaluarExpresionFiltros((char*)Filtro.toLatin1().data(), &MapTest, &mappM) > 1))
        {          
          MemLogs->append("ERROR: " + tr("Filtro") + " " + Filtro + "; " + (QString)STR0049 + " " + GetNombreVariable(i) + " " + QApplication::translate("", "est\303\241 mal escrita", 0));
          QApplication::processEvents();
          return false;
        }        
      }
      return true;
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Indica el modo de visualizar las variables.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    QComboBox *TFmeVariables::GetVisualizarVar()
    {        
        return VisualizarVar;
    }
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Visualiza lo significa el sentido sobre el que se ha pulsado.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void TFmeVariables::VisualizarMenu(const QModelIndex& index)
    {
      QString texto3, texto0;
      if (!view->boton()) {
        texto3 = model->data(view->indexAt(QPoint(view->columnViewportPosition(3), view->rowViewportPosition(index.row()))), Qt::DisplayRole).toString();
        texto0 = model->data(view->indexAt(QPoint(view->columnViewportPosition(0), view->rowViewportPosition(index.row()))), Qt::DisplayRole).toString();
        menu->clear();
        if ((listaH.at(index.column()) == "SENTIDO_FILTRO") && (!texto3.isEmpty()))  {
          if (model->data(index, Qt::DisplayRole) == "a")
            menu->addAction("if (!(" + texto3 + ")) then (" + texto0 + " == NP)");
          else
            if (model->data(index, Qt::DisplayRole) == "b")
              menu->addAction("if (" + texto3 + ") then (" + texto0 + " != NP)");
            else
              if (model->data(index, Qt::DisplayRole) == "c")
                menu->addAction("(" + texto3 + ") <=> (" + texto0 + " != NP)");
          menu->popup(QCursor::pos());
        }
      }      
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Carga la tabla segun el modo de visualizacion seleccionado.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void TFmeVariables::VisualizarVarCloseUp(int index)
    {
      if (index == 0) {
           delete model;
           model = new TablaModelV(0, MatrizVariablesT, listaH, listaVT);
           model->setVectorMappingExiste(m);
           view->setModel(model);
           MostrarInfoAsociada(0, 0, NumVariablesT, true);
      }else {
           delete model;
           model = new TablaModelV(0, MatrizVariablesS, listaH, listaV);
           model->setVectorMappingExiste(m);
           view->setModel(model);
           MostrarInfoAsociada(0, 0, NumVariables, true);
      }
      EscribirInformacion();
      CargarVariablesEnLista();
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Combo para ir a una variable por su nombre.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void TFmeVariables::CbxIrAVariablePorNombreCloseUp(int index)
    {
      view->setCurrentIndex(view->indexAt(QPoint(view->columnViewportPosition(view->currentIndex().column()), view->rowViewportPosition(index))));
      SgrRejillaSelectCell(view->currentIndex());
      view->setFocus();
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Muestra la información dependiendo de la seleccion de las diferentes rejillas.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void TFmeVariables::SgrRejillaSelectCell(const QModelIndex& index)
    {      
      MostrarInfoAsociada(index.row(), index.column(), model->rowCount(view->currentIndex()), false);
    }

    void TFmeVariables::SgrRejillaSelectCellV(const int& index)
    {
      int fila = view->currentIndex().row();
      int col = 0;
      MostrarInfoAsociada(fila, col, model->rowCount(view->currentIndex()), false);
    }
    void TFmeVariables::SgrRejillaSelectCellH(const int& index)
    {
      int fila = 0;
      int col = view->currentIndex().column();
      MostrarInfoAsociada(fila, col, model->rowCount(view->currentIndex()), false);
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Combo para ir a una determinada variable segun su atributo.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void TFmeVariables::CbxIrAAtributoCloseUp(int index)
    {      
      view->setCurrentIndex(view->indexAt(QPoint(view->columnViewportPosition(index), view->rowViewportPosition(view->currentIndex().row()))));
      SgrRejillaSelectCell(view->currentIndex());
      view->setFocus();
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Muestra informacion si se hace doble click sobre la rejilla principal en una determinada columna.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void TFmeVariables::SgrRejillaDblClick(const QModelIndex& index)
    {
      unsigned i;
      bool MostrarValoresMissing = false;

      if (listaH.at(index.column()) == "MAPPING"){
        ConsultarTablaMapping(model->data(index, Qt::DisplayRole).toString());
      }else
      {
        for (i = 0; i < Num_valores_missing; i++)
          if (listaH.at(index.column()) == Cadenas_Missing->at(i))
            MostrarValoresMissing = true;
        if (MostrarValoresMissing)
          ConsultarTablaMissing();
      }
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Editor para ir a una determinada variable por su posicion.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void TFmeVariables::EdtIrAVariablePorNumeroKeyDown()
    {
      unsigned IndiceVariable;

      IndiceVariable = EdtIrAVariablePorNumero->text().toInt();

      if ((IndiceVariable >= 1) && (IndiceVariable <= NumVariables))
        view->setCurrentIndex(view->indexAt(QPoint(view->columnViewportPosition(view->currentIndex().column()), view->rowViewportPosition(IndiceVariable-1))));
      EdtIrAVariablePorNumero->setText("");
      SgrRejillaSelectCell(view->currentIndex());
      view->setFocus();
    }
 

