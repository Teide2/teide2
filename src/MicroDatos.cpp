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


#include "MicroDatos.h"

    TFmeMicroDatos::TFmeMicroDatos(QWidget* parent, const char* name, Qt::WindowFlags fl, QSqlDatabase *AdcConexionBD, TFmeVariables *FmeVariablesAsociadas, QStringList *NombresTablas, unsigned NumRegistros, QStringList *ListaIds, QString Key, QString Cota, bool Contaminar, unsigned PorcentajeContaminacion, bool oracle, bool Xml, QString NombreBaseDatos, QTabWidget *PctContenedorPrincipal, bool excel, QString Nrac)
    {
      QString s;

      setGeometry(0, 0, parent->width()-2, parent->height()-15);
      if (this->objectName().isEmpty())
        this->setObjectName(("TFmeMicroDatos"));

      PanContenedorM = new QFrame(this);
      PanContenedorM->setGeometry(QRect(0, 0, this->width(), this->height()-50));
      PanContenedorM->setFrameShape(QFrame::Panel);
      PanContenedorM->setFrameShadow(QFrame::Raised);
      VisualizarReg = new QComboBox(PctContenedorPrincipal);
      VisualizarReg->setGeometry(PanContenedorM->width()-220, 0, 200, 25);
      VisualizarReg->setVisible(false);

      view = new MiTabla(PanContenedorM);
      view2 = new MiTabla(PanContenedorM);      
      view2->setGeometry(QRect(1, PanContenedorM->height()-2-56-65, PanContenedorM->width()-1, 65));

      view->setGeometry(QRect(2, 1, PanContenedorM->width()-2, view2->y()-2));

      PanIrA = new QFrame(PanContenedorM);
      PanIrA->setGeometry(QRect(1, PanContenedorM->height()-2-24-30, PanContenedorM->width()-2, 30));
      PanIrA->setFrameShape(QFrame::Box);
      PanIrA->setFrameShadow(QFrame::Raised);
      LabIrARegistro = new QLabel(PanIrA);
      LabIrARegistro->setGeometry(QRect(3, 5, 95, 18));
      EdtIrARegistro = new QLineEdit(PanIrA);
      EdtIrARegistro->setGeometry(QRect(105, 5, 33, 21));

      LabBuscarID = new QLabel(PanIrA);
      LabBuscarID->setGeometry(QRect(150, 5, 95, 18));
      CbxBuscarID = new QComboBox(PanIrA);
      CbxBuscarID->setGeometry(QRect(248, 5, 130, 21));
      CbxBuscarID->setEditable(true);

      LabIrAVariablePorNumero = new QLabel(PanIrA);
      LabIrAVariablePorNumero->setGeometry(QRect(385, 5, 140, 18));
      EdtIrAVariablePorNumero = new QLineEdit(PanIrA);
      EdtIrAVariablePorNumero->setGeometry(QRect(485, 5, 33, 21));

      LabIrAVariablePorNombre = new QLabel(PanIrA);
      LabIrAVariablePorNombre->setObjectName(("LabIrAVariablePorNombre"));
      LabIrAVariablePorNombre->setGeometry(QRect(531, 5, 140, 18));
      CbxIrAVariable = new QComboBox(PanIrA);
      CbxIrAVariable->setGeometry(QRect(630, 5, 130, 21));
      CbxIrAVariable->setEditable(true);

      LabMapping = new QLabel(PanIrA);
      LabMapping->setGeometry(QRect(775, 5, 55, 18));
      EdtMapping = new QLineEdit(PanIrA);
      EdtMapping->setGeometry(QRect(835, 5, 313, 21));
      EdtMapping->setReadOnly(true);

      SbrBarraEstado = new QFrame(PanContenedorM);

      SbrBarraEstado->setGeometry(QRect(1, PanContenedorM->height()-2-22, PanContenedorM->width()-1, 22));
      SbrBarraEstado->setFrameShape(QFrame::Panel);
      SbrBarraEstado->setFrameShadow(QFrame::Raised);
      SbrBarraEstado0 = new QFrame(SbrBarraEstado);

      SbrBarraEstado0->setGeometry(QRect(0, 0, SbrBarraEstado->width()/2, 19));
      SbrBarraEstado0->setFrameShape(QFrame::Box);
      SbrBarraEstado0->setFrameShadow(QFrame::Raised);
      LabBarraEstado0 = new QLabel(SbrBarraEstado0);

      LabBarraEstado0->setGeometry(QRect(3, 0, SbrBarraEstado->width()/2, 19));
      SbrBarraEstado1 = new QFrame(SbrBarraEstado);

      SbrBarraEstado1->setGeometry(QRect(SbrBarraEstado0->width() + 1, 0, SbrBarraEstado0->width() - 1, 19));
      SbrBarraEstado1->setFrameShape(QFrame::Box);
      SbrBarraEstado1->setFrameShadow(QFrame::Raised);
      LabBarraEstado1 = new QLabel(SbrBarraEstado1);

      LabBarraEstado1->setGeometry(QRect(4, 0, SbrBarraEstado->width()/2 - 1, 19));

      menu = new QMenu( this);
      menu->addAction( QObject::tr("Salvar microdatos a fichero..."), this, SLOT(MitSalvarMicrodatosFicheroClick()));
      menu->addAction( QObject::tr("Salvar microdatos a BBDD..."), this, SLOT(MitSalvarMicrodatosBBDDClick()));
      menu->addSeparator();
      menu->addAction( QObject::tr("Aumentar el ancho de las columnas..."), this, SLOT(MitAumentarColumnasClick()));
      menu->addAction( QObject::tr("Disminuir el ancho de las columnas..."), this, SLOT(MitDisminuirColumnasClick()));
    
      this->setWindowTitle(QApplication::translate("TFmeMicroDatos", "Form", 0));
      LabBuscarID->setText(QApplication::translate("TFmeMicroDatos", "Ir a reg. (nom)", 0));
      CbxBuscarID->setToolTip(QApplication::translate("TFmeMicroDatos", "Indique el nombre de registro para acceder a \303\251l.", 0));
      LabIrARegistro->setText(QApplication::translate("TFmeMicroDatos", "Ir a reg. (num)", 0));
      LabIrAVariablePorNombre->setText(QApplication::translate("TFmeMicroDatos", "Ir a var. (nom) ", 0));
      LabMapping->setText(QApplication::translate("TFmeMicroDatos", "Mapping ", 0));
      LabIrAVariablePorNumero->setText(QApplication::translate("TFmeMicroDatos", "Ir a var. (num) ", 0));
      EdtIrARegistro->setToolTip(QApplication::translate("TFmeMicroDatos", "Indique un n\303\272mero de registro y pulse ENTER parar ir a \303\251l.", 0));
      EdtMapping->setToolTip(QApplication::translate("TFmeMicroDatos", "Mapping del valor de la variable a su c\303\263digo literal correspondiente.", 0));
      EdtIrAVariablePorNumero->setToolTip(QApplication::translate("TFmeMicroDatos", "Indique un n\303\272mero de variable y pulse ENTER parar ir a ella.", 0));
      view->setToolTip(QApplication::translate("TFmeMicroDatos", "Rejilla de visualizaci\303\263n de microdatos con variables num\303\251ricas.", 0));
      view2->setToolTip(QApplication::translate("TFmeMicroDatos", "Informaci\303\263n de la variable activa.", 0));
      VisualizarReg->setToolTip(QApplication::translate("TFmeMicroDatos", "Seleccione el modo de vizualizaci\303\263n de los registros.", 0));
      VisualizarReg->addItem(QApplication::translate("TFmeMicroDatos", "Visualizar todos", 0));
      VisualizarReg->addItem(QApplication::translate("TFmeMicroDatos", "Visualizar reg. seg\303\272n expresi\303\263n", 0));

      QObject::connect(view, SIGNAL(clicked(const QModelIndex&)), this, SLOT(SgrRejillaSelectCell(const QModelIndex&)));
      QObject::connect(view, SIGNAL(pressed ( const QModelIndex& )), this, SLOT(VisualizarMenu(const QModelIndex&)));
      QObject::connect(view->verticalHeader(), SIGNAL(sectionClicked ( const int & )), this, SLOT(SgrRejillaSelectCellV(const int &)));
      QObject::connect(view->horizontalHeader(), SIGNAL(sectionClicked ( const int & )), this, SLOT(SgrRejillaSelectCellH(const int &)));
      QObject::connect(VisualizarReg, SIGNAL(activated ( const int & ) ), this, SLOT(VisualizarRegCloseUp(const int &)));
      QObject::connect(EdtIrAVariablePorNumero, SIGNAL(returnPressed ()), this, SLOT(EdtIrAVariablePorNumeroKeyDown()));
      QObject::connect(CbxIrAVariable, SIGNAL(activated ( const int & )), this, SLOT(CbxIrAVariableCloseUp(const int &)));
      QObject::connect(EdtIrARegistro, SIGNAL(returnPressed ()), this, SLOT(EdtIrARegistroKeyDown()));
      QObject::connect(CbxBuscarID, SIGNAL(activated ( const int & )), this, SLOT(CbxBuscarIDCloseUp(const int &)));

      QMetaObject::connectSlotsByName(this);

      // Asociar las clases
      AsociarClases(FmeVariablesAsociadas);

      // Asociamos el nombre del conjunto
      this->NombreConjunto = FmeVariablesAsociadas->GetNombreConjunto();

      // Fijamos un nombre
      this->Name = "FmeMicroDatos" + NombreConjunto;

      // Fijamos el nombre de la tabla
      this->NombresTablas = NombresTablas;
      NumTablas = NombresTablas->size();
      this->Excel = excel;
      // Fijamos el nombre de la variable clave
      this->Key = Key;

      // Fijamos la cota de lectura de registros
      this->Cota = Cota;

      // Fijar la cantidad de datos
      this->NumRegistros = NumRegistros;
      this->NumVariables = FmeVariablesAsociadas->GetNumVariables();
      this->NumMicrodatos = NumRegistros * NumVariables;

      // Asociamos la lista de identificadores
      this->ListaIds = ListaIds;
      this->Nrac = Nrac;

      // Conexion a la base de MicroDatos
      AdqConsulta = AdcConexionBD;
      query5 = new QSqlQuery(QString::null, *AdcConexionBD);
      Oracle = oracle;

      this->NombreBaseDatos = NombreBaseDatos;
      this->Xml = Xml;
      // Cargar MicroDatos
      MemLogs->append(tr("Cargando microdatos"));
      QApplication::processEvents();
      CargarMicroDatos();

      // Creamos el modelo y lo asignamos a la vista          
      model = new TablaModel(0, MatrizMicroDatosS, listaH, listaV);
      view->setModel(model);
      //qDebug() << MatrizMicroDatosS[0][46];
      QApplication::processEvents();
      // Chequear la completitud de los registros y crear la matriz de datos asociada
      MemLogs->append(QApplication::translate("", "Completitud y validaci\303\263n de los registros del conjunto", 0) + " \"" + NombreConjunto + "\"");
      QApplication::processEvents();
      ChequearCompletitudRegistros();

      // Contaminar microdatos si es necesario
      ValoresContaminados = 0;
      if (Contaminar)
      {
        MemLogs->append(tr("Contaminando") + " " + s.setNum(PorcentajeContaminacion, 10) + "% " + tr("de las variables en el conjunto") + " \"" + NombreConjunto + "\"");
        ContaminarMicrodatos(PorcentajeContaminacion);
      }

      // Inicializar la rejilla de Variables
      MemLogs->append(tr("Inicializando la rejilla de variables"));
      QApplication::processEvents();
      InicializarRejillaVariable();
      model2 = new TablaModelInfo(0, VectorDatosS, listaH2, listaV2);
      view2->setModel(model2);

      // Creando el map de registros
      MemLogs->append(tr("Inicializando el map de registros"));
      QApplication::processEvents();
      CrearMapRegistros();

      // Rellenar el combo de ir a
      CbxIrAVariable->addItems (* FmeVariablesAsociadas->GetListaVariables());
      CbxIrAVariable->setCurrentIndex (0);
      CbxIrAVariable->setInsertPolicy(QComboBox::NoInsert);      
      CbxBuscarID->addItems (* ListaIds);
      CbxBuscarID->setCurrentIndex (0);
      CbxBuscarID->setInsertPolicy(QComboBox::NoInsert);

      // Calcular los porcentajes estadisticos
      CalcularEstadisticas();      
      // Inicializacion de los microdatos modificados posteriormente
      MicroDatosModificados.clear();      

      MostrarInfoAsociada(0, 0, NumRegistros, true);

      EscribirInformacion();      
    }
    /*void TFmeMicroDatos::updateGeometry ()
    {
            //parentWidget()->resizeEvent(event);
            this->setGeometry(0, 0, parentWidget()->width()-2, parentWidget()->height()-15);

            PanContenedorM->setGeometry(QRect(0, 0, this->width(), this->height()-50));

            VisualizarReg->setGeometry(PanContenedorM->width()-220, 0, 200, 25);

            view2->setGeometry(QRect(1, PanContenedorM->height()-2-56-65, PanContenedorM->width()-1, 65));

            view->setGeometry(QRect(2, 1, PanContenedorM->width()-2, view2->y()-2));

            PanIrA->setGeometry(QRect(1, PanContenedorM->height()-2-24-30, PanContenedorM->width()-2, 30));

            SbrBarraEstado->setGeometry(QRect(1, PanContenedorM->height()-2-22, PanContenedorM->width()-1, 22));

            SbrBarraEstado0->setGeometry(QRect(0, 0, SbrBarraEstado->width()/2, 19));

            LabBarraEstado0->setGeometry(QRect(3, 0, SbrBarraEstado->width()/2, 19));

            SbrBarraEstado1->setGeometry(QRect(SbrBarraEstado0->width() + 1, 0, SbrBarraEstado0->width() - 1, 19));

            LabBarraEstado1->setGeometry(QRect(4, 0, SbrBarraEstado->width()/2 - 1, 19));
     }*/
    void TFmeMicroDatos::ajustarSize ( )
    {            
            this->setGeometry(0, 0, parentWidget()->width()-2, parentWidget()->height()-15);

            PanContenedorM->setGeometry(QRect(0, 0, this->width(), this->height()-50));

            VisualizarReg->setGeometry(PanContenedorM->width()-220, 0, 200, 25);

            view2->setGeometry(QRect(1, PanContenedorM->height()-2-56-65, PanContenedorM->width()-1, 65));

            view->setGeometry(QRect(2, 1, PanContenedorM->width()-2, view2->y()-2));

            PanIrA->setGeometry(QRect(1, PanContenedorM->height()-2-24-30, PanContenedorM->width()-2, 30));

            SbrBarraEstado->setGeometry(QRect(1, PanContenedorM->height()-2-22, PanContenedorM->width()-1, 22));

            SbrBarraEstado0->setGeometry(QRect(0, 0, SbrBarraEstado->width()/2, 19));

            LabBarraEstado0->setGeometry(QRect(3, 0, SbrBarraEstado->width()/2, 19));

            SbrBarraEstado1->setGeometry(QRect(SbrBarraEstado0->width() + 1, 0, SbrBarraEstado0->width() - 1, 19));

            LabBarraEstado1->setGeometry(QRect(4, 0, SbrBarraEstado->width()/2 - 1, 19));
     }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Asociar las clases provenientes de etapas anteriores.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void TFmeMicroDatos::AsociarClases(TFmeVariables *FmeVariablesAsociadas)
    {
      this->FmeVariablesAsociadas = FmeVariablesAsociadas;
      this->MemLogs = FmeVariablesAsociadas->GetMemLogs();
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Se crea la matriz de Microdatos.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void TFmeMicroDatos::CrearMatrizMicroDatos()
    {
      unsigned i, j;
      bool error = false;
      QString s, valor;

      MatrizMicroDatos = new double*[NumRegistros];
      for (i = 0; i < NumRegistros; i++)
      {
        MatrizMicroDatos[i] = new double[NumVariables];
        for (j = 0; j < NumVariables; j++)
        {
	// partimos de la premisa que el sistema windows tiene la coma como separador por defecto de decimales
          try
          {
            valor = MatrizMicroDatosS[i][j];
            MatrizMicroDatos[i][j] = valor.replace(',', '.').toDouble();            
          }
          catch (...)
          {
            error = true;
          }
          // si hay un error podemos pensar que se debe a que el separador ha cambiado a un punto
          if (error)
          {
            try
            {
              MatrizMicroDatosS[i][j].replace(',', '.');
              MatrizMicroDatos[i][j] = MatrizMicroDatosS[i][j].toDouble();
            }
            catch (...)
            {              
              MemLogs->append("ERROR: " + QApplication::translate("", "Conversi\303\263n en la variable", 0) + " " + FmeVariablesAsociadas->GetNombreVariable(j) + " " + QApplication::translate("", "Conversi\303\263n en el registro", 0) + " " + s.setNum(i + 1, 10) + ".");
              QApplication::processEvents();
            }
          }
        }
      }
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Se chequea que el dato no este vacío.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void TFmeMicroDatos::ChequearCompletitudRegistros()
    {
      unsigned i, j;
      QString Valor, s;
      bool error = false;      
      
      MatrizMicroDatos = new double*[NumRegistros];
      for (i = 0; i < NumRegistros; i++)
      {
        MatrizMicroDatos[i] = new double[NumVariables];
        for (j = 0; j < NumVariables; j++)
        {
          Valor = MatrizMicroDatosS[i][j];
          if (Valor.isEmpty())
          {            
            MemLogs->append("ERROR: " + (QString)STR0049 + " " + FmeVariablesAsociadas->GetNombreVariable(j) + " " + QApplication::translate("", "Conversi\303\263n en el registro", 0) + " " + QString::number(i+1, 10) + " " + QApplication::translate("", "est\303\241 vac\303\255o", 0));
            QApplication::processEvents();
          }else {
            // partimos de la premisa que el sistema windows tiene la coma como separador por defecto de decimales
            try
            {
              MatrizMicroDatos[i][j] = Valor.replace(',', '.').toDouble();              
            }
            catch (...)
            {
              error = true;
            }
            // si hay un error podemos pensar que se debe a que el separador ha cambiado a un punto
            if (error)
            {
              try
              {
                MatrizMicroDatosS[i][j] = Valor.replace(',', '.');
                MatrizMicroDatos[i][j] = Valor.toDouble();                
              }
              catch (...)
              {                
                MemLogs->append("ERROR: " + QApplication::translate("", "Conversi\303\263n en la variable", 0) + " " + FmeVariablesAsociadas->GetNombreVariable(j) + " " + QApplication::translate("", "Conversi\303\263n en el registro", 0) + " " + s.setNum((i + 1), 10) + ".");
                QApplication::processEvents();
              }
            }
          }
        }
      }
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Se cálcula las estadísticas.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void TFmeMicroDatos::CalcularEstadisticas()
    {
      unsigned i, j, k;
      QString mis;
      int index;
      for (i = 0; i < FmeVariablesAsociadas->GetNum_valores_missing(); i++)
        NumMissing[i] = 0;

      for (i = 0; i < NumRegistros; i++)
        for (j = 0; j < NumVariables; j++)
        {          
          for (k = 0; k < FmeVariablesAsociadas->GetNum_valores_missing(); k++) {
             mis = FmeVariablesAsociadas->GetCadenas_Missing()->at(k);             
             if (MatrizMicroDatos[i][j] == (double)FmeVariablesAsociadas->GetValorMissing(mis)) {
               NumMissing[k]++;               
               break;
             }
           }
        }

      for (i = 0; i < FmeVariablesAsociadas->GetNum_valores_missing(); i++) {
        PorcentajesMissing[i] = ((double)NumMissing[i] / (double)(NumRegistros*NumVariables)) * 100;
      }
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Se cargan los datos de la base de datos.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void TFmeMicroDatos::ReestructurarTablaM()
    {
        int num_reg_a_cargar = Nrac.toInt();
        if ((!Nrac.contains("ALL", Qt::CaseSensitive)) && (num_reg_a_cargar < NumRegistros)) {
          for (int i=(NumRegistros-1); i > (num_reg_a_cargar-1);i--)
          {
            listaV.removeLast();            
            for (int j=(NumVariables-1); j >= 0; j-- )
              MatrizMicroDatosS[i]->remove(j);            
          }
          NumRegistros = num_reg_a_cargar;
        }
    }

    void TFmeMicroDatos::CargarMicroDatos()
    {
      unsigned i, IndiceVariableTabla, IndiceVariable, IndiceRegistro, NumVariablesTabla, ultimoIndiceVariable;
      QString CadenaSQL, Variable;
      QString s;
      double aux;
      int aux2;

      FijarFormatoRejilla();

      IndiceVariable = 0;  // indice de la variable en la tabla
      ultimoIndiceVariable = 0;   // indice en que se quedo al añadir en la anterior tabla

      if (Xml) {
        QDomDocument *doc = new QDomDocument("?xml");
        QDomNode n;
        QDomElement e, e1;
        QDomNode n1;
        for (i = 0; i < NumTablas; i++)
        {
          MemLogs->append(tr("Realizando la consulta sobre la tabla") + " " + NombresTablas->at(i) + " ...");
          QApplication::processEvents();
          
          QFile file(QDir::toNativeSeparators(NombreBaseDatos + NombresTablas->at(i)));

          if ((!file .open(QIODevice::ReadOnly)) || (!doc->setContent(&file)))
          {
            MemLogs->append("ERROR: " + tr("No se pudo realizar satisfactoriamente la consulta sobre la base de datos") +  " [\"" + NombresTablas->at(i) + "\"]");
            QApplication::processEvents();
            file.close();
            delete doc;
            return;
          }          
          
          QDomElement root = doc->documentElement();
          if (!root.tagName().contains("dataroot"))
          if (root.tagName() != "ROWSET")
          {
            MemLogs->append("ERROR: " + tr("No se pudo realizar satisfactoriamente la consulta sobre la base de datos") +  " [\"" + NombresTablas->at(i) + "\"]");
            QApplication::processEvents();
            file.close();
            delete doc;
            return;
          }          
          QApplication::processEvents();

          NumVariablesTablas.push_back(0);

          n = root.firstChild();
          CadenaSQL = NombresTablas->at(i);
          CadenaSQL.replace(".xml", "", Qt::CaseInsensitive);
          while (!n.isNull())
          {
            e = n.toElement();
            if (!e.isNull()) {
              if ((e.tagName() == CadenaSQL) || (e.tagName() == "ROW")) {
                n1 = n.firstChild();
                while (!n1.isNull())  // buscamos primero el identificador de cada registro
                {
                  e1 = n1.toElement();
                  if (!e1.isNull()) {
                    if (e1.tagName() == Key)
                    {
                        IndiceRegistro = listaV.indexOf(e1.text());                        
                    }
                  }
                  n1 = n1.nextSibling();
                }
                n1 = n.firstChild();
                while (!n1.isNull())    // buscamos el resto de atributos
                {
                  e1 = n1.toElement();                  
                  if (!e1.isNull()) {                    
                    if ((e1.tagName() != Key) && (e1.tagName() != "ID"))// && (IndiceVariable != -1))
                    {
                      if (!FmeVariablesAsociadas->EsVariableIgnorable(e1.tagName()))
                      {
                          IndiceVariable = listaH.indexOf(e1.tagName());
                          if (IndiceVariable != -1) {
                            MatrizMicroDatosS[IndiceRegistro][IndiceVariable] = e1.text().replace('.', ',');
                            if (IndiceRegistro == 0) NumVariablesTablas[i]++;
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
        }
        ReestructurarTablaM();
        delete doc;
      }else {
        for (i = 0; i < NumTablas; i++)
        {
          MemLogs->append(tr("Realizando la consulta sobre la tabla") + " " + NombresTablas->at(i) + " ...");
          QApplication::processEvents();

          CadenaSQL = "SELECT * FROM " + NombresTablas->at(i) + Cota + " ORDER BY \"" + Key + "\"";
          QSqlQuery query(CadenaSQL, *AdqConsulta);

          QSqlRecord record = query.record();
          if (!query.isActive())          {

            MemLogs->append("ERROR: " + tr("No se pudo realizar satisfactoriamente la consulta sobre la base de datos"));
            QApplication::processEvents();
            return;
          }

          NumVariablesTabla = record.count();
          NumVariablesTablas.push_back(0);

          IndiceRegistro = 0;
          while ((query.next()) && (IndiceRegistro != NumRegistros)) {
            IndiceVariable = ultimoIndiceVariable;
            for (IndiceVariableTabla = 0; IndiceVariableTabla < NumVariablesTabla; IndiceVariableTabla++)
            {
              QApplication::processEvents();
              Variable = record.fieldName (IndiceVariableTabla);
              if ((Variable != Key) && (Variable != "ID"))// && (IndiceVariable != -1))
              {
                if (!FmeVariablesAsociadas->EsVariableIgnorable(Variable))
                {
                  if (!query.value(IndiceVariableTabla).isNull()) {
                      s = query.value(IndiceVariableTabla).toString();
                      aux = s.toDouble();
                      if (FmeVariablesAsociadas->EsValorMissing(aux)) {
                          aux2 = (int)aux;
                          MatrizMicroDatosS[IndiceRegistro][IndiceVariable] = QString::number(aux2, 10);
                      }else {
                          s = query.value(IndiceVariableTabla).toString();                          
                          MatrizMicroDatosS[IndiceRegistro][IndiceVariable] = s.replace('.', ',');                          
                      }
                  }
                  if (IndiceRegistro == 0) NumVariablesTablas[i]++;
                  IndiceVariable++;
                }
              }
            }
            IndiceRegistro++;
          }
          ultimoIndiceVariable += NumVariablesTablas[i];
        }
      }      
    }
    int TFmeMicroDatos::buscar_pos(QString var)
    {
      for (int i = 0; i < NumVariables; i++)
        if (model->headerData(i, Qt::Horizontal , Qt::DisplayRole) == var) return i;
      return -1;
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Se crea un map con el nombre de la variable y su valor.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void TFmeMicroDatos::CrearMapRegistros()
    {
      QString Variable;
      QStringList *ListaVariables;
      unsigned i, j;
      double Valor;

      ListaVariables = FmeVariablesAsociadas->GetListaVariables();
      MapRegistros = new QMap<QString,double>*[NumRegistros];
      for (i = 0; i < NumRegistros; i++)
      {
        MapRegistros[i] = new QMap<QString,double>;
        for (j = 0; j < NumVariables; j++)
        {
          Variable = ListaVariables->at(j);
          Valor = MatrizMicroDatos[i][j];
          MapRegistros[i]->insert(Variable, Valor);
        }
      }      
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Se contaminan los datos.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void TFmeMicroDatos::ContaminarMicrodatos(double PorcentajeContaminacion)
    {
      double NoProcede, NuevoValor;
      unsigned i, c, h, num_contaminaciones;
      QSet<unsigned> IndicesSeleccionados;

      c = ROUND((double)(PorcentajeContaminacion * (double)NumVariables) / double(100));
      NoProcede = FmeVariablesAsociadas->GetValorMissing(NOPROCEDE);
      for (i = 0; i < NumRegistros; i+=2)
      {
        num_contaminaciones = 0;
        IndicesSeleccionados.clear();
        while (num_contaminaciones < c)
        {
          h = rand() % NumVariables;
          if ((FmeVariablesAsociadas->EsVariableImputable(h)) && (!IndicesSeleccionados.contains(h)))
          {
            IndicesSeleccionados.insert(h);
            // Si es un NO_PROCEDE le asignamos un valor real del rango
            if (GetValor(i, h) == NoProcede)
            {
              NuevoValor = FmeVariablesAsociadas->GetValorAleatorioRango(h);
            }
            // Si es un valor normal le asignamos NO_PROCEDE
            else
            {
              NuevoValor = NoProcede;
            }
            MatrizMicroDatos[i][h] = NuevoValor;
            MatrizMicroDatosS[i][h] = QString::number(MatrizMicroDatos[i][h], 'f', 1);
            num_contaminaciones++;
          }
        }
      }
      ValoresContaminados = ceil((double)NumRegistros / (double)2) * c;
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Muestra la infomación en la parte de abajo de la pantalla.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void TFmeMicroDatos::EscribirInformacion()
    {
      LabBarraEstado0->setText(QString::number(model->rowCount(view->currentIndex()), 10) + " " + tr("registros") + ", " + QString::number(NumVariables, 10) + " " + (QString)STR0053);
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Crea el tamaño de la rejilla principal, junto con las cabeceras.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void TFmeMicroDatos::FijarFormatoRejilla()
    {
      unsigned i, j;

      MatrizMicroDatosS = new QString*[NumRegistros];

      view->verticalHeader()->setDefaultSectionSize(20);

      // Fijar ids de las filas
      for (i = 0; i < (unsigned)NumRegistros; i++) {        
        listaV.append(ListaIds->at(i));
        MatrizMicroDatosS[i] = new QString[NumVariables];
      }

      for (j = 0; j < (unsigned)NumVariables; j++) {
        listaH.append(FmeVariablesAsociadas->getMatrizVariablesS(j, 0));
        view->setColumnWidth(j, ANCHO_VARIABLES_CORTAS);
      }
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Funciones para obtener determinados valores.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    int TFmeMicroDatos::GetposID(QString id)
    {
      return listaV.indexOf(id);
    }

    QString TFmeMicroDatos::GetlistaH2(int indice)
    {
      return listaH2.at(indice);
    }

    QString TFmeMicroDatos::GetlistaV2(int indice)
    {
      return listaV2.at(indice);
    }

    QString TFmeMicroDatos::GetVectorDatosS(int col)
    {
      return VectorDatosS[col];
    }

    unsigned TFmeMicroDatos::GetNumRegistros()
    {
      return NumRegistros;
    }

    unsigned TFmeMicroDatos::GetNumVariables()
    {
      return NumVariables;
    }

    unsigned TFmeMicroDatos::GetNumMicrodatos()
    {
      return NumMicrodatos;
    }

    double **TFmeMicroDatos::GetMatrizMicroDatos()
    {
      return MatrizMicroDatos;
    }

    QString **TFmeMicroDatos::GetMatrizMicroDatosS()
    {
      return MatrizMicroDatosS;
    }

    double *TFmeMicroDatos::GetRegistro(unsigned IndiceRegistro)
    {
      return MatrizMicroDatos[IndiceRegistro];
    }

    TFmeVariables *TFmeMicroDatos::GetVariablesAsociadas()
    {
      return FmeVariablesAsociadas;
    }

    double TFmeMicroDatos::GetValor(unsigned IndiceRegistro, unsigned IndiceVariable)
    {
      return MatrizMicroDatos[IndiceRegistro][IndiceVariable];
    }

    TablaModel *TFmeMicroDatos::GetTablaModel()
    {
      return model;
    }

    QString TFmeMicroDatos::GetValorS(unsigned IndiceRegistro, unsigned IndiceVariable)
    {
      return MatrizMicroDatosS[IndiceRegistro][IndiceVariable];
    }

    int TFmeMicroDatos::numColumnMicroS()
    {
      return NumVariables;
    }

    unsigned TFmeMicroDatos::GetNumMissing(int TipoMissing)
    {
      return NumMissing[TipoMissing];
    }

    double TFmeMicroDatos::GetPorcentajeMissing(int TipoMissing)
    {
      return PorcentajesMissing[TipoMissing];
    }

    QString TFmeMicroDatos::GetNombreConjunto()
    {
      return NombreConjunto;
    }

    QString TFmeMicroDatos::GetNombreTabla()
    {
      return NombreConjunto;
    }

    QStringList *TFmeMicroDatos::GetNombresTablas()
    {
      return NombresTablas;
    }

    QString TFmeMicroDatos::GetIdRegistro(unsigned IndiceRegistro)
    {
      return ListaIds->at(IndiceRegistro);
    }

    QStringList *TFmeMicroDatos::GetListaRegistros()
    {
      return ListaIds;
    }

    unsigned TFmeMicroDatos::GetNumVariablesTabla(unsigned IndiceTabla)
    {
      return NumVariablesTablas[IndiceTabla];
    }

    double TFmeMicroDatos::GetValoresContaminados()
    {
      return ValoresContaminados;
    }

    QMap<QString,double> *TFmeMicroDatos::GetMapRegistro(unsigned IndiceRegistro)
    {
      return MapRegistros[IndiceRegistro];
    }

    QString TFmeMicroDatos::GetKey()
    {
      return Key;
    }

    QString TFmeMicroDatos::GetCota()
    {
      return Cota;
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Se inicializa la rejilla de variables.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void TFmeMicroDatos::InicializarRejillaVariable()
    {
      unsigned j;

      VectorDatosS = new QString[FmeVariablesAsociadas->GetNumAtributos()];

      // Establecemos los titulos en la primera fila
      for (j = 0; j < (unsigned)FmeVariablesAsociadas->GetNumAtributos(); j++)
      {        
        listaH2.append(FmeVariablesAsociadas->getlistaH(j));        
      }      
      listaV2.append("");      
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Muestra la información en la tabla varaibles, en el mapping y en la parte de abajo de la pantalla.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void TFmeMicroDatos::MostrarInfoAsociada(unsigned Fila, unsigned Columna, unsigned numreg, bool Fijar)
    {
        static unsigned UltimaColumna = 0, UltimaFila = 0;
        QString CadenaSQL, Mapping, Valor, TablaMapping, Codigo;

        listaV2[0] = FmeVariablesAsociadas->getlistaV(Columna);
        model2->setCabeceraV(listaV2);
        model2->setHeaderData(0, Qt::Vertical, QVariant(), Qt::DisplayRole);
        for (int i = 0; i < FmeVariablesAsociadas->GetNumAtributos(); i++)   {
            VectorDatosS[i] = FmeVariablesAsociadas->getMatrizVariablesS(Columna, i);
            if (i < 8) view2->setColumnWidth ( i, ANCHOS_VARIABLE[i]);
            else
                if (i < 8 + FmeVariablesAsociadas->GetNum_valores_missing()) view2->setColumnWidth ( i, 100);
                else view2->setColumnWidth ( i, ANCHOS_VARIABLE[i - FmeVariablesAsociadas->GetNum_valores_missing()]);
        }

        repintarVariable((!VectorDatosS[listaH2.indexOf("FILTRO")].isEmpty()), (MatrizMicroDatosS[Fila][Columna] == "False"));
        UltimaColumna = Columna;
        UltimaFila = Fila;

        // Consulta de MicroDatos
        Valor = model->data(view->indexAt(QPoint(view->columnViewportPosition(Columna), view->rowViewportPosition(Fila))), Qt::DisplayRole).toString();
        Mapping = FmeVariablesAsociadas->GetCadenaMissing(Valor.replace(',', '.').toDouble());
        //Valor.replace(',', '.');

        bool salirX = false;
        if (Mapping.isEmpty())
        {
            TablaMapping = FmeVariablesAsociadas->GetValorAtributo(Columna, ATR_MAPPING, FmeVariablesAsociadas->GetNum_valores_missing());
            if (!TablaMapping.isEmpty())
            {
                if (Xml) {
                    QDomDocument *doc = new QDomDocument("?xml");
                    QDomNode n;
                    QDomElement e, e1;
                    QDomNode n1;

                    QFile file(QDir::toNativeSeparators(NombreBaseDatos + TablaMapping + ".xml"));
                    if ((!file .open(QIODevice::ReadOnly)) || (!doc->setContent(&file)))
                    {
                        file.close();
                        Mapping = tr("NO HAY MAPPING DISPONIBLE");
                        salirX=true;
                    }
                    if (!salirX) {
                        QDomElement root = doc->documentElement();
                        if (!root.tagName().contains("dataroot"))
                            if (root.tagName() != "ROWSET")
                            {
                                file.close();
                                Mapping = tr("NO HAY MAPPING DISPONIBLE");
                                salirX = true;
                            }
                        if (!salirX) {
                            n = root.firstChild();
                            while (!n.isNull())
                            {
                                e = n.toElement();
                                if (!e.isNull()) {
                                    if ((e.tagName() == TablaMapping) || (e.tagName() == "ROW")) {
                                        n1 = n.firstChild();
                                        while (!n1.isNull())
                                        {
                                            e1 = n1.toElement();
                                            if (!e1.isNull()) {
                                                if (e1.tagName() == "CODIGO") Codigo = e1.text();
                                                if (e1.tagName() == "DESCRIPCION") Mapping = e1.text();
                                            }
                                            n1 = n1.nextSibling();
                                        }
                                    }
                                }
                                if (Codigo != Valor) Mapping = tr("NO HAY MAPPING DISPONIBLE");
                                else break;
                                n = n.nextSibling();
                            }
                        }
                    }
                    file.close();
                    delete doc;
                }else {
                    if (Excel) CadenaSQL = "SELECT * FROM [" + TablaMapping + "$] WHERE CODIGO = " + Valor;
                    else CadenaSQL = "SELECT * FROM " + TablaMapping + " WHERE CODIGO = " + Valor;
                    query5->exec(CadenaSQL);
                    if (query5->isActive()){
                        QSqlRecord record2 = query5->record();
                        query5->first();
                        Mapping = query5->value(record2.indexOf("DESCRIPCION")).toString();
                    }else
                        Mapping = tr("NO HAY MAPPING DISPONIBLE");
                }
            }
        }
        EdtMapping->setText(Mapping);
        LabBarraEstado1->setText(tr("Registro") + " " + QString::number(Fila+1, 10) + "/" + QString::number(model->rowCount(view->currentIndex()), 10) + " [ " + (QString)STR0049 + " = " + QString::number(Columna+1, 10) + "]");
        if (Fijar) {
            view->setCurrentIndex(view->indexAt(QPoint(view->columnViewportPosition(Columna), view->rowViewportPosition(Fila))));
            QColor rojo = view->currentIndex().model()->data(view->currentIndex(), Qt::BackgroundRole).value<QColor>();
            QString color = rojo.name();
            setStyleSheet("selection-color: black;selection-background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 " + color + ", stop: 1 gray);");
        }
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Pinta la rejilla variable.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void TFmeMicroDatos::repintarVariable(bool filtro, bool falso)
    {
      int col = FmeVariablesAsociadas->GetIndiceAtributo("FILTRO");
      QString *v = new QString[FmeVariablesAsociadas->GetNumAtributos()];
      for (int i = 1; i < FmeVariablesAsociadas->GetNumAtributos(); i++) {
        if (VectorDatosS[i] == "False") {
          v[i] = "Red";          
        }
      }
      if (filtro) {
        if (falso) {          
          v[col] = "Red";
        } else {          
          v[col] = "Blue";
        }
      }else {        
        v[col] = "Blue";
      }
      model2->setVectorPintar(v);
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Se modifica el dato con el valor dado.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void TFmeMicroDatos::ModificarMicrodato(unsigned IndiceRegistro, unsigned IndiceVariable, double Valor)
    {
      TipoMicroDato d;

      d.fila = IndiceRegistro;
      d.columna = IndiceVariable;
      MicroDatosModificados.insert(d);

      MatrizMicroDatos[IndiceRegistro][IndiceVariable] = Valor;
      MatrizMicroDatosS[IndiceRegistro][IndiceVariable] = QString::number(Valor, 'f', 1).replace(".", ",");
      // Tambien es necesario modificar el map previamente creado
      (*MapRegistros[IndiceRegistro])[model->headerData(IndiceVariable, Qt::Horizontal, Qt::DisplayRole).toString()] = Valor;
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Salvar datos en un fichero.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void TFmeMicroDatos::SalvarMicrodatosEnFichero(QString NombreFichero)
    {
      QStringList *Datos;
      unsigned i, j;
      QString Linea;

      LabBarraEstado0->setText(tr("Introduzca el nombre base de la tabla"));
      QApplication::processEvents();

      Datos =  new QStringList();
      // Escribir los nombres de las variables
      Linea = "";
      for (j = 0; j < NumVariables; j++)
        Linea += (model->headerData(j, Qt::Horizontal, Qt::DisplayRole).toString() + " ");
      Datos->append(Linea);
      // Escribir todos los registros
      for (i = 0; i < NumRegistros; i++)
      {
	Linea = "";
        for (j = 0; j < NumVariables; j++)
          Linea += (MatrizMicroDatosS[i][j] + " ");
        Datos->append(Linea);
      }
      // escribir en disco
      QFile file( NombreFichero );
      if ( file.open( QIODevice::WriteOnly ) ) {
        QTextStream stream( &file );
        for ( QStringList::Iterator it = Datos->begin(); it != Datos->end(); ++it )
            stream << *it << "\n";
        file.close();
      }
      delete Datos;

      EscribirInformacion();
      QApplication::processEvents();
      QMessageBox::information(this, QApplication::translate("", "Informaci\303\263n", 0), tr("MicroDatos salvados correctamente"), QMessageBox::Ok, QMessageBox::NoButton);
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Salvar datos en la base de datos.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void TFmeMicroDatos::SalvarMicrodatosEnBBDD(QString NombreTablaBaseSalida)
    {
      unsigned i, j, k, NumVariablesTabla, UltimaVariableEscrita = 0;
      QString TablaEntrada, TablaSalida, CadenaSQL, CadenaSQL2, ValoresActualizacion, IdRegistro, ComillasKey;
      QString Mensaje = tr("Error en el proceso de escritura en base de datos"), Valor;
      bool actualizar;
      TipoMicroDato d;
      int cont = 0;
      int r = 0;

      QProgressDialog progress(tr("Salvando microdatos..."), tr("Cancelar"), 0, NumRegistros*NumTablas, this);
      progress.setWindowModality(Qt::WindowModal);
      progress.show();
      if (Xml) {
        QDomDocument *docE = new QDomDocument("?xml");
        QDomNode n;
        QDomElement e, e1;
        QDomNode n1;

        for (i = 0; i < NumTablas; i++)
        {
          if (progress.wasCanceled())
             break;

          QDomDocument docS("");
          QDomElement rootS = docS.createElement("dataroot");
          docS.appendChild(rootS);

          TablaEntrada = NombresTablas->at(i);
          if (NumTablas == 1)
            TablaSalida = NombreTablaBaseSalida + "_" + SUFIJOENTRADA + ".xml";
          else
            TablaSalida = NombreTablaBaseSalida + "_T" + QString::number(i+1, 10) + "_" + SUFIJOENTRADA + ".xml";

          QFile file(QDir::toNativeSeparators(NombreBaseDatos + TablaEntrada));
          if ((!file.open(QIODevice::ReadOnly)) || (!docE->setContent(&file)))
          {
            QMessageBox::critical(this, tr("Error"), tr("No se pudo realizar satisfactoriamente la consulta sobre la base de datos") +  " [\"" + TablaSalida + "\"]", QMessageBox::Ok, QMessageBox::NoButton);
            QApplication::processEvents();
            file.close();
            delete docE;
            return;
          }

          QDomElement root = docE->documentElement();
          if (!root.tagName().contains("dataroot"))
            if (root.tagName() != "ROWSET")
            {
              QMessageBox::critical(this, tr("Error"), tr("No se pudo realizar satisfactoriamente la consulta sobre la base de datos") +  " [\"" + TablaSalida + "\"]", QMessageBox::Ok, QMessageBox::NoButton);
              QApplication::processEvents();
              file.close();
              delete docE;
              return;
            }

          CadenaSQL2 = TablaSalida;
          CadenaSQL2.replace(".xml", "", Qt::CaseInsensitive);
          CadenaSQL = TablaEntrada;
          CadenaSQL.replace(".xml", "", Qt::CaseInsensitive);
          k=0;
          NumVariablesTabla = GetNumVariablesTabla(i);
          n = root.firstChild();

          while (!n.isNull())
          {
            progress.setValue(r);
            if (progress.wasCanceled())
              break;
            e = n.toElement();
            if (!e.isNull()) {
              if ((e.tagName() == CadenaSQL) || (e.tagName() == "ROW")) {
                QDomElement tag = docS.createElement(CadenaSQL2);
                rootS.appendChild(tag);
                n1 = n.firstChild();
                while (!n1.isNull())
                {
                  e1 = n1.toElement();
                  if (!e1.isNull())
                  {
                    d.fila = k;
                    j = listaH.indexOf(e1.tagName());
                    d.columna = j;
                    if (encontrar(d))
                    {
                      Valor = MatrizMicroDatosS[k][j];
                      //Valor = Valor.replace(',', '.');
                      QDomElement t = docS.createElement(e1.tagName());
                      t.appendChild(docS.createTextNode(Valor));
                      tag.appendChild(t);
                      cont++;
                    }else {
                      QDomElement t = docS.createElement(e1.tagName());
                      t.appendChild(docS.createTextNode(e1.text()));
                      tag.appendChild(t);
                    }
                  }
                  n1 = n1.nextSibling();
                }
              }
            }
            k++;
            r++;
            n = n.nextSibling();
          }
          file.close();
          QString xml = docS.toString();
          QFile file2(QDir::toNativeSeparators(NombreBaseDatos + TablaSalida));
          if (file2.open(QIODevice::WriteOnly))   {
            QTextStream stream(&file2);
            stream << xml;
          }
        }
      }else {
         // si los campos son de tipo string en la bbdd, esta variable debe estar inicializada a "'". En otro caso
         // esta variable debe estar inicializada a ""
         QString ComillasCampos = "";
        // Si la clave es ID presuponemos que es autonumerica
        if (Key == "ID")
          ComillasKey = "";
        else
          ComillasKey = "'";
        for (i = 0; i < NumTablas; i++)
        {
          if (progress.wasCanceled())
            break;

          TablaEntrada = NombresTablas->at(i);
          if (NumTablas == 1)
            TablaSalida = NombreTablaBaseSalida + "_" + SUFIJOENTRADA;
          else
            TablaSalida = NombreTablaBaseSalida + "_T" + QString::number(i+1, 10) + "_" + SUFIJOENTRADA;
          query5->exec("DROP TABLE " + TablaSalida);

          if (!Oracle) {
            if (Excel) {
                query5->exec("SELECT * FROM " + TablaEntrada + Cota + " ORDER BY \"" + Key + "\"");
                QSqlRecord record6 = query5->record();
                int l = 0;
                QStringList lista;
                while (l < record6.count()) {
                    lista.append(record6.fieldName(l));
                    l++;
                }
                query5->exec("CREATE TABLE " + TablaSalida + "(" + lista.join(" char(250), ") + " char(250))");
                query5->exec("INSERT INTO " + TablaSalida + " SELECT * FROM " + TablaEntrada + Cota + " ORDER BY \"" + Key + "\"");
            }else query5->exec("SELECT * INTO " + TablaSalida + " FROM " + TablaEntrada + Cota + " ORDER BY \"" + Key + "\"");
          }else
            query5->exec("CREATE TABLE " + TablaSalida + " AS SELECT * FROM " + TablaEntrada + Cota + " ORDER BY \"" + Key + "\"");

          if (!query5->isActive())
          {
            QMessageBox::critical(this, "Error", Mensaje + "\nError: " + query5->lastError().text(), QMessageBox::Ok, QMessageBox::NoButton);
            return;
          }

          NumVariablesTabla = GetNumVariablesTabla(i);
          for (k = 0; k < NumRegistros; k++)
          {
            progress.setValue(r);
            if (progress.wasCanceled())
              break;

            actualizar = false;
            ValoresActualizacion = "";
            for (j = UltimaVariableEscrita; j < (UltimaVariableEscrita + NumVariablesTabla); j++)
            {
              d.fila = k;
              d.columna = j;
              if (encontrar(d))
              {
                Valor = MatrizMicroDatosS[k][j];
                //Valor = Valor.replace(',', '.');
	        ValoresActualizacion += ("`" + model->headerData(j, Qt::Horizontal, Qt::DisplayRole).toString() + "` = " + ComillasCampos + Valor + ComillasCampos + ",");
                actualizar = true;
                cont++;
              }
            }
            if (actualizar)
            {
              ValoresActualizacion[ValoresActualizacion.size()-1] = ' ';
              IdRegistro = GetIdRegistro(k);
              query5->exec("UPDATE " + TablaSalida + " SET " + ValoresActualizacion + "WHERE " + Key + " = " + ComillasKey + IdRegistro + ComillasKey);
              if (!query5->isActive())
              {
                 QMessageBox::critical(this, tr("Error"), Mensaje, QMessageBox::Ok, QMessageBox::NoButton);
                return;
              }
            }
            r++;
          }
          UltimaVariableEscrita += NumVariablesTabla;
        }
      }
      progress.setValue(NumTablas*NumRegistros);      
      if (cont == MicroDatosModificados.size()) {
        QMessageBox::information(this, QApplication::translate("", "Informaci\303\263n", 0), tr("MicroDatos salvados correctamente"), QMessageBox::Ok, QMessageBox::NoButton);
      }else {
        QString cadena = tr(QString("Se ha actualizado " + QString::number(cont) + " datos de " + QString::number(MicroDatosModificados.size()) + " microdatos modificados.").toLatin1(), "");
        QMessageBox::critical(this, tr("Error"), cadena, QMessageBox::Ok, QMessageBox::NoButton);
      }
    }
    bool TFmeMicroDatos::encontrar(TipoMicroDato d)
    {
      set<TipoMicroDato,LT_TipoMicroDato>::iterator it = MicroDatosModificados.begin();
      while (it != MicroDatosModificados.end()) {
	 if ((d.fila == it->fila) && (d.columna == it->columna)) return true;
	 it++;
      }
      return false;
    }  
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Fija el ancho de la columnas de la rejilla principal.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void TFmeMicroDatos::FijarAnchoColumnasRejilla(unsigned ancho)
    {
      unsigned j;

      for (j = 0; j < (unsigned)NumVariables; j++)
        view->setColumnWidth(j, ancho);
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Retorna el como queremos visualizar los registros.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    QComboBox *TFmeMicroDatos::GetVisualizarReg()
    {        
        return VisualizarReg;
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Editor que indica al registro donde queremos ir por posicion.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void TFmeMicroDatos::EdtIrARegistroKeyDown()
    {
      unsigned IndiceRegistro;

      try
      {
        IndiceRegistro = EdtIrARegistro->text().toInt();
      }
      catch (...)
      {
        EdtIrARegistro->setText("");
	    return;
      }
      if ((IndiceRegistro >= 1) && (IndiceRegistro <= model->rowCount(view->currentIndex()))) {//NumRegistros))  {
        view->setCurrentIndex(view->indexAt(QPoint(view->columnViewportPosition(view->currentIndex().column()), view->rowViewportPosition(IndiceRegistro-1))));
      }
      EdtIrARegistro->setText("");      
      SgrRejillaSelectCell(view->currentIndex());
      view->setFocus();
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Combo para ir a una variable por nombre.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void TFmeMicroDatos::CbxIrAVariableCloseUp(int index)
    {      
      view->setCurrentIndex(view->indexAt(QPoint(view->columnViewportPosition(index), view->rowViewportPosition(view->currentIndex().row()))));
      SgrRejillaSelectCell(view->currentIndex());
      view->setFocus();
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Selecciones en las rejillas.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void TFmeMicroDatos::SgrRejillaSelectCell(const QModelIndex& index)
    {
        MostrarInfoAsociada(index.row(), index.column(), model->rowCount(view->currentIndex()), true);
    }
    void TFmeMicroDatos::SgrRejillaSelectCellV(const int& index)
    {
      int fila = view->currentIndex().row();
      int col = 0;
      MostrarInfoAsociada(fila, col, model->rowCount(view->currentIndex()), false);
    }
    void TFmeMicroDatos::SgrRejillaSelectCellH(const int& index)
    {
      int fila = 0;
      int col = view->currentIndex().column();
      MostrarInfoAsociada(fila, col, model->rowCount(view->currentIndex()), false);
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Editor para ir a una variable segun la posicion indicada.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void TFmeMicroDatos::EdtIrAVariablePorNumeroKeyDown()
    {
      unsigned IndiceVariable;

      try
      {
        IndiceVariable = EdtIrAVariablePorNumero->text().toInt();
      }
      catch (...)
      {
        EdtIrAVariablePorNumero->setText("");
        return;
      }
      if ((IndiceVariable >= 1) && (IndiceVariable <= NumVariables))        
        view->setCurrentIndex(view->indexAt(QPoint(view->columnViewportPosition(IndiceVariable-1), view->rowViewportPosition(view->currentIndex().row()))));
      EdtIrAVariablePorNumero->setText("");
      SgrRejillaSelectCell(view->currentIndex());
      view->setFocus();
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Combo para ir a un registro seleccionado.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void TFmeMicroDatos::CbxBuscarIDCloseUp(int index)
    {
      view->setCurrentIndex(view->indexAt(QPoint(view->columnViewportPosition(view->currentIndex().column()), view->rowViewportPosition(index))));

      SgrRejillaSelectCell(view->currentIndex());
      view->setFocus();
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Visualiza el menu en la rejilla principal cuando se pulsa el boton derecho del raton.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void TFmeMicroDatos::VisualizarMenu(const QModelIndex& index)
    {
      if (view->boton())
        menu->popup(QCursor::pos());      
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Indica que quiere salvar los datos en un fichero.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void TFmeMicroDatos::MitSalvarMicrodatosFicheroClick()
    {      
      QString start = QCoreApplication::applicationDirPath();
      QString meta = QDir::toNativeSeparators(start+"/" + DIRECTORIO_DATA + "/DATA_" + NombreConjunto + "_IN");
      QString NombreFichero = QFileDialog::getSaveFileName(this, tr("Guardar fichero"), meta, "TXT (*.txt)");
      if (NombreFichero == "")
        QMessageBox::warning(this, "Warning",  tr("No ha introducido ningun fichero"), "&Ok");
      else  {        
        SalvarMicrodatosEnFichero(NombreFichero);
      }
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Indica que quiere salvar los datos en la base de datos.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void TFmeMicroDatos::MitSalvarMicrodatosBBDDClick()
    {
      FrmEntradaDatos = new TFrmEntradaDatos(this, "entradadatos", Qt::Widget);
      FrmEntradaDatos->FijarEtiqueta1(tr("Introduzca el nombre base de la tabla"));
      FrmEntradaDatos->FijarEntrada1(NombreConjunto);
      QObject::connect(FrmEntradaDatos->ButAceptar, SIGNAL(clicked()), this, SLOT(ButAceptarEntradaDatosClick()));
      QObject::connect(FrmEntradaDatos->ButCancelar, SIGNAL(clicked()), this, SLOT(ButCancelarEntradaDatosClick()));

      FrmEntradaDatos->show();      
    }
    void TFmeMicroDatos::ButAceptarEntradaDatosClick()
    {
      FrmEntradaDatos->hide();
      SalvarMicrodatosEnBBDD(FrmEntradaDatos->GetEntrada1());      
    }
    void TFmeMicroDatos::ButCancelarEntradaDatosClick()
    {
      FrmEntradaDatos->hide();
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Acciones para cambiar el ancho de las columnas.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void TFmeMicroDatos::MitAumentarColumnasClick()
    {
      FijarAnchoColumnasRejilla(view->columnWidth (1) + 50);
    }
    void TFmeMicroDatos::MitDisminuirColumnasClick()
    {
      FijarAnchoColumnasRejilla(view->columnWidth (1) - 50);
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Trata la visualización de los registros en la tabla principal.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void TFmeMicroDatos::VisualizarRegCloseUp(int index)
    {
      if (index == 0) {
           delete model;
           model = new TablaModel(0, MatrizMicroDatosS, listaH, listaV);
           view->setModel(model);
           CbxBuscarID->clear();
           CbxBuscarID->addItems(listaV);
           MostrarInfoAsociada(0, 0, NumRegistros, true);
           EscribirInformacion();           
      }else {           
           NumRegistrosSelec = 0;
           wpedexp = new TFrmPedirExpresion(0, "pedirexp", Qt::Widget);
           QObject::connect(wpedexp->ButAceptar, SIGNAL(clicked()), this, SLOT(ButAceptarPedirExpresionClick()));
           QObject::connect(wpedexp->ButCancelar, SIGNAL(clicked()), this, SLOT(ButCancelarPedirExpresionClick()));
           wpedexp->show();           
      }
    }
    void TFmeMicroDatos::cargarmodelo2(QString exp)
    {
      QMap <QString, double> * mapp;
      QMap<QString,double> mappM;
      MatrizMicroDatosSelec = new QString*[NumRegistros];
      listaVSelec.clear();
      int k = 0;
      for (int i = 0; i < NumRegistros; i++) {
           mapp = GetMapRegistro(i);
           mappM = FmeVariablesAsociadas->GetMapMissing();
           switch (EvaluarExpresion((char*)exp.toLatin1().data(), mapp, &mappM))
           {
                case ERROR_SINTACTICO: i = NumRegistros;
                                       break;
                case ERROR_LEXICO: i = NumRegistros;
                                   break;
                case ERROR_SINTACTICO_Y_LEXICO: i = NumRegistros;
                                                break;
                case VERDADERO: MatrizMicroDatosSelec[k] = new QString[NumVariables];
                                for (int j = 0; j < NumVariables; j++)  MatrizMicroDatosSelec[k][j] = MatrizMicroDatosS[i][j];
                                listaVSelec.append(ListaIds->at(i));
                                NumRegistrosSelec++;
                                k++;
                                break;
                default: break;
           }        
      }
      //poner una condicion para q solo entre cuando no hay error
      if (NumRegistrosSelec == 0) {
          QMessageBox::information(0, QApplication::translate("", "Informaci\303\263n", 0), QApplication::translate("", "No se han encontrado registros", 0), QMessageBox::Ok, QMessageBox::NoButton);
          VisualizarReg->setCurrentIndex(0);
      }else {
        delete model;
        model = new TablaModel(0, MatrizMicroDatosSelec, listaH, listaVSelec);
        view->setModel(model);
        CbxBuscarID->clear();
        CbxBuscarID->addItems(listaVSelec);
        MostrarInfoAsociada(0, 0, NumRegistrosSelec, true);
        EscribirInformacion();
      }
    }
    void TFmeMicroDatos::ButAceptarPedirExpresionClick()
    {
      if (wpedexp->getExpresion() == "")
        QMessageBox::warning(this, "Warning",  QApplication::translate("", "No ha introducido ninguna expresi\303\263n", 0), "&Ok");
      else {
        wpedexp->hide();
        cargarmodelo2(wpedexp->getExpresion());
      }      
    }
    void TFmeMicroDatos::ButCancelarPedirExpresionClick()
    {
      wpedexp->hide();
    }
