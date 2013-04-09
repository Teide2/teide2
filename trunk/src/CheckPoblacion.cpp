/*******************************************************************************
** CheckPoblacion.cpp: permite comparar diferentes bases de datos o tablas de
**                     datos con variables en común y relacionadas.
**
** author: M-S Hernández-García
*******************************************************************************/

#include "CheckPoblacion.h"

TFrmCheckPoblacion::TFrmCheckPoblacion(QWidget* parent, const char* name, Qt::WindowFlags fl, QSqlDatabase *AdcConexionBD, TFmeMicroDatos *FmeMicroDatosAsociados, QString BaseDatos, QStringList *TablaDatos, DatosOracle *DatosOrac):QWidget(parent, fl)
    {
      if (this->objectName().isEmpty())
        this->setObjectName(QString::fromUtf8("TFrmCheckPoblacion"));
      this->resize(403, 384);
      QFont font;
      font.setFamily(QString::fromUtf8("Tahoma"));
      this->setFont(font);

      MemInfo = new QTextEdit(this);
      MemInfo->setObjectName(QString::fromUtf8("MemInfo"));
      MemInfo->setGeometry(QRect(8, 8, 377, 340));
      MemInfo->setReadOnly(true);

      PbrProgreso = new QProgressBar(this);
      PbrProgreso->setObjectName(QString::fromUtf8("PbrProgreso"));
      PbrProgreso->setGeometry(QRect(8, 355, 291, 25));
      PbrProgreso->setValue(0);
      PbrProgreso->setTextVisible(false);
      ButGuardarInforme = new QPushButton(this);
      ButGuardarInforme->setObjectName(QString::fromUtf8("ButGuardarInforme"));
      ButGuardarInforme->setGeometry(QRect(308, 355, 91, 25));

      this->setWindowTitle(QApplication::translate("TFrmCheckPoblacion", "Chequear poblaci\303\263n...", 0, QApplication::UnicodeUTF8));
      ButGuardarInforme->setText(QApplication::translate("TFrmCheckPoblacion", "Guardar", 0, QApplication::UnicodeUTF8));

      QObject::connect(ButGuardarInforme, SIGNAL(clicked()), this, SLOT(ButGuardarInformeClick()));
      QMetaObject::connectSlotsByName(this);

      // Asociar las clases
      AsociarClases(FmeMicroDatosAsociados);

      // Conexión a la base de MicroDatos
      AdqConsulta = AdcConexionBD;

      // Fijar la cantidad de datos
      FijarCantidadDatos();
      padre = parent;
      NombBD1 = BaseDatos;
      TablaDatos1 = TablaDatos;
      QString valor = NombBD1.section(QDir::convertSeparators("/"), -1);

      if ((valor.contains( ".mdb" ) > 0) || (valor.contains( ".xls" ) > 0)) {
        Oracle = false;
        Xml = false;
        if (valor.contains( ".xls" ) > 0) Excel = true;
        else Excel = false;
      }else {
        if ((valor.contains("/") || (valor.contains("\\")))) {
          Xml = true;
          Oracle = false;
          Excel = false;
        }else {
          Oracle = true;
          Xml = false;
          Excel = false;
        }
      }
      datorac = DatosOrac;
    }

    void TFrmCheckPoblacion::inicio()
    {
      QMessageBox msgBox;
      msgBox.setText(tr("¿Son la misma base de datos?\n(si la respuesta es NO, recuerde que deben estar las dos en la carpeta data)."));
      QPushButton *YesButton = msgBox.addButton(tr("SI"), QMessageBox::AcceptRole);
      QPushButton *NotButton = msgBox.addButton(tr("NO"), QMessageBox::NoRole);
      msgBox.setIcon(QMessageBox::Question);
      int ret = msgBox.exec();
      switch (ret) {
        case QMessageBox::AcceptRole: DosBD = false;
                                      break;
        default: DosBD = true;
                 break;
      }
      datocheq = new TFrmDatosChequeo(this, "DatosChequeo", Qt::Widget, DosBD, NombBD1, TablaDatos1);
      datocheq->show();
    }

    void TFrmCheckPoblacion::AsociarClases(TFmeMicroDatos *FmeMicroDatosAsociados)
    {
      this->FmeMicroDatosAsociados = FmeMicroDatosAsociados;
      this->FmeVariablesAsociadas = FmeMicroDatosAsociados->GetVariablesAsociadas();
    }

    void TFrmCheckPoblacion::FijarCantidadDatos()
    {
      NumRegistros = FmeMicroDatosAsociados->GetNumRegistros();
      NumVariables = FmeVariablesAsociadas->GetNumVariables();
    }

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// PULSAR EL BOTÓN DE GUARDAR INFORME.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void TFrmCheckPoblacion::ButGuardarInformeClick()
    {      
      QString start = QCoreApplication::applicationDirPath();
      QString meta = QDir::convertSeparators(start + "/" + DIRECTORIO_STATS);
      QString NombreFichero = QFileDialog::getSaveFileName(this, tr("Guardar fichero informe" ), meta, "TXT (*.txt)");

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

    void TFrmCheckPoblacion::ButChequearClick()
    {
        QStringList nomVar;
        QStringList tablasDatos2;
        QString BD1;
        QString BD2;
        QString valor;
        double valorN;
        int i, j, k;
        QString CadenaSQL;
        QString aux = "";
        QString start;
        QString meta;
        QStringList datos2;
        QString varConteo;
        QString CadenaConexionBD;
        QSqlQuery query;
        QString condicion;
        int porcentaje;
        //comprobaciones, antes de chequear
        BD1 = datocheq->GetEdtBD1();
        BD2 = datocheq->GetEdtBD2();
        tablasDatos2 = datocheq->GetEdtTD2().split(", ");
        if (Xml) {
           /*start = QApplication::applicationDirPath();
           meta = QDir::convertSeparators(start+"/data/"+BD2);
           QDir dir;
           if (!dir.exists(meta)) {
              QMessageBox::warning(datocheq, "Warning", tr( "La base de datos %1 no existe" ).arg( BD2  ), "&Ok");
              return;
           }
           QDomDocument *doc = new QDomDocument("?xml");
           QDomNode n;
           QDomElement e, e1;
           QDomNode n1;
           QDomElement root;
           for (j = 0; j < tablasDatos2.size(); j++)
           {
             QFile file(meta + tablasDatos2.at(j));
             if (!file.exists()) {
                 QMessageBox::warning(datocheq, "Warning", tr( "La tabla %1 no se encuentra" ).arg( tablasDatos2.at(j) ), "&Ok");
                 return;
             }
           }

           // comprobar que las variables existen en todas las tablas
           bool encontrada = false;
           bool encontradaT = false;
           nomVar = datocheq->GetEdtVar().split(", ");
           for (j = 0; j < tablasDatos2.size(); j++)
           {
             QFile file2(meta + tablasDatos2.at(j));
             if ((!file2.open(QIODevice::ReadOnly)) || (!doc->setContent(&file2))) {
                 QMessageBox::warning(datocheq, "Warning", tr( "La tabla %1 no se puede abrir" ).arg( tablasDatos2.at(j) ), "&Ok");
                 return;
             }
             root = doc->documentElement();
             if (!root.tagName().contains("dataroot"))
               if (root.tagName() != "ROWSET")  {
                 QMessageBox::warning(datocheq, "Warning", tr( "Error de lectura " ), "&Ok");
                 return;
               }
             }
             CadenaSQL = tablasDatos2.at(j);
             CadenaSQL.replace(".xml", "", Qt::CaseInsensitive);
             for (k = 0; k < nomVar.size(); k++) {
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
                       if (e1.hasAttribute ( nomVar.at(k) ) ) {
                         n1 = n.lastChild();
                         n = root.lastChild();
                         encontrada = true
                       }
                       n1 = n1.nextSibling();
                     }
                   }
                 }
                 n = n.nextSibling();
               }
               if (!encontrada) encontradaT = false;
             }
               if (!encontrada)
               {
                 QMessageBox::warning(datocheq, "Warning", tr( "La variable %1 no se encuentra en la/s tabla/s secundaria/s" ).arg( nomVar.at(k)  ), "&Ok");
                 //AdqConsulta2->close();
                 return;
               }
           }
           //comprobar variable de conteo
           varConteo = datocheq->GetEdtVarConteo();
           if (!varConteo.isEmpty()) {
             if (!FmeVariablesAsociadas->GetListaVariables()->contains(varConteo))  //comprobar si existen en TD1
             {
                QMessageBox::warning(datocheq, "Warning", tr( "La variable %1 de conteo no se encuentra en la/s tabla/s inicial/es" ).arg( varConteo  ), "&Ok");
                //AdqConsulta2->close();
                return;
             }
           }*/
        }else{
           start = QCoreApplication::applicationDirPath();
           meta = QDir::convertSeparators(start+"/data/"+BD2);
           QFile file(meta);
           if ((file.exists()) || (Oracle)){   //comprobar que la BD2 existe
             if (!DosBD) {
               AdqConsulta2 = *AdqConsulta;
             }else{
               if (!Oracle) {
                 if (Excel) CadenaConexionBD = "DRIVER={Microsoft Excel Driver (*.xls)}; ReadOnly=0; DBQ=";
                 else CadenaConexionBD = "DRIVER={Microsoft Access Driver (*.mdb)}; DBQ=";
               }
               if (Oracle) {
                 AdqConsulta2 = QSqlDatabase::addDatabase("QOCI", "oracle2");
                 AdqConsulta2.setDatabaseName(datorac->getEdtNombre());
                 AdqConsulta2.setUserName(datorac->getEdtUsuario());
                 AdqConsulta2.setPassword(datorac->getEdtPassword());
                 AdqConsulta2.setHostName(datorac->getEdtHost());
                 if (!AdqConsulta2.open()) {
                   QMessageBox::warning(datocheq, "Warning", tr( "La base de datos %1 no se puedo abrir" ).arg( BD2 ), "&Ok");
                   return;
                 }
               }else {
                 CadenaConexionBD += meta;
                 AdqConsulta2 = QSqlDatabase::addDatabase("QODBC3", "office2");
                 AdqConsulta2.setDatabaseName(CadenaConexionBD);
                 if (!AdqConsulta2.open()) {   // comprobar base de datos 2 es adecuada
                   QMessageBox::warning(datocheq, "Warning", tr( "La base de datos %1 no se puedo abrir" ).arg( BD2 ), "&Ok");
                   return;
                 }
               }
             }
             // comprobar que las tablas de dtos 2 existen
             QStringList tablas = AdqConsulta2.tables(QSql::Tables);
             for (k = 0; k < tablasDatos2.size(); k++) {
                if (!tablas.contains(tablasDatos2.at(k)))
                {
                   QMessageBox::warning(datocheq, "Warning", tr( "La tabla %1 no se encuentra" ).arg( tablasDatos2.at(k) ), "&Ok");
                   return;
                }
             }
             query = AdqConsulta2.exec(QString());
             // comprobar que las variables existen en todas las tablas
             bool encontrada = false;
             nomVar = datocheq->GetEdtVar().split(", ");
             for (k = 0; k < nomVar.size(); k++) {
                if (!FmeVariablesAsociadas->GetListaVariables()->contains(nomVar.at(k)))  //comprobar si existen en TD1
                {
                   QMessageBox::warning(datocheq, "Warning", tr( "La variable %1 no se encuentra en la/s tabla/s inicial/es" ).arg( nomVar.at(k)  ), "&Ok");
                   return;
                }
                for (j = 0; j < tablasDatos2.size(); j++) {
                  if (Excel) CadenaSQL = "SELECT " + nomVar.at(k) + " FROM [" + tablasDatos2.at(j) + "$]";
                  else CadenaSQL = "SELECT " + nomVar.at(k) + " FROM " + tablasDatos2.at(j);
                   query.exec(CadenaSQL);
                   query.first();
                   i = 0;
                   if (query.isValid())
                   {
                     encontrada = true;
                     if (k == 0) datos2.insert(i, query.value(0).toString());
                     else {
                         datos2[i] += ", " + query.value(0).toString();
                         i++;
                     }                     
                     while (query.next())
                     {
                        if (k == 0) datos2.insert(i, query.value(0).toString());
                        else {
                          datos2[i] = datos2.at(i) + ", " + query.value(0).toString();
                          i++;
                        }                        
                     }
                     break;
                   }
                }
                if (!encontrada)
                {
                   QMessageBox::warning(datocheq, "Warning", tr( "La variable %1 no se encuentra en la/s tabla/s secundaria/s" ).arg( nomVar.at(k)  ), "&Ok");
                   return;
                }
             }
             //comprobar variable de conteo
             varConteo = datocheq->GetEdtVarConteo();
             if (!varConteo.isEmpty()) {
               if (!FmeVariablesAsociadas->GetListaVariables()->contains(varConteo))  //comprobar si existen en TD1
               {
                  QMessageBox::warning(datocheq, "Warning", tr( "La variable %1 de conteo no se encuentra en la/s tabla/s inicial/es" ).arg( varConteo  ), "&Ok");
                  return;
               }

               porcentaje = datocheq->GetEdtPorcentaje().toInt();
               if (datocheq->GetEdtPorcentaje().isEmpty())
               {
                  QMessageBox::warning(datocheq, "Warning", tr( "Valor del porcentaje vacio" ), "&Ok");
                  return;
               }else {
                   if ((porcentaje <= 0) || (100 < porcentaje))
                   {
                      QMessageBox::warning(datocheq, "Warning", tr( "Valor del porcentaje no admitido (1-100)" ), "&Ok");
                      return;
                   }
               }
               if (!chequearCondicion()) return;
            }            
          }else {
             QMessageBox::warning(datocheq, "Warning", tr( "No existe la base de datos %1" ).arg( BD2 ), "&Ok");
             return;
          }
        }

        datocheq->hide();
        MemInfo->clear();
        this->show();

        nomVar = datocheq->GetEdtVar().split(", ");
        tablasDatos2 = datocheq->GetEdtTD2().split(", ");        
        PbrProgreso->setRange(0, NumRegistros);
        PbrProgreso->setValue(0);
        QString cadena;
        for (i=0; i < NumRegistros; i++) {            
            k = 0; // recorre datos2
            cadena = "";
            aux = "";
            for (j = 0; j < nomVar.size(); j++)
            {                
                valor = FmeMicroDatosAsociados->GetValorS(i, FmeVariablesAsociadas->GetIndiceVariable(nomVar.at(j)));
                cadena += valor + ", ";
                aux += nomVar.at(j) + " = " + valor + ", ";
            }
            cadena.chop(2);
            aux.chop(2);
            if (varConteo.isEmpty()) {
              if (!datos2.contains(cadena))
                MemInfo->append(tr("Registro ") + QString::number(i+1, 10) + tr(": con los valores ") + aux + tr(" no se encuentra en la/s tabla/s ") + datocheq->GetEdtTD2() + tr(" de ") + BD2);
            }else {
              if (!datocheq->GetChbActC()->isChecked())
                valor = FmeMicroDatosAsociados->GetValorS(i, FmeVariablesAsociadas->GetIndiceVariable(varConteo));
              else
                valor = ObtenerValor(i);
              valorN = ceil(valor.toDouble() * porcentaje / 100.0);
              if (valorN != datos2.count(cadena))
                MemInfo->append(tr("Registro ") + QString::number(i+1, 10) + tr(": con los valores ") + aux + tr(" deberia estar, en la/s tabla/s ") + datocheq->GetEdtTD2() + tr(" de ") + BD2 + ", " + QString::number((int)valorN, 10) + tr(" veces y en cambio se encuentra ") + QString::number((int)datos2.count(cadena), 10) + tr(" veces"));
            }
            PbrProgreso->setValue(PbrProgreso->value()+1);
            QApplication::processEvents();
        }
        if (MemInfo->toPlainText () == "")
            MemInfo->append("El chequeo ha sido correcto");        
    }

    bool TFrmCheckPoblacion::chequearCondicion()
    {
        QStringList lisVar;
        QString operador;
        double valor;
        int k;

        if (datocheq->GetChbActC()->isChecked()) {
            lisVar = datocheq->GetEdtVariablesC().split(", ");
            for (k = 0; k < lisVar.size(); k++) {
                if (!FmeVariablesAsociadas->GetListaVariables()->contains(lisVar.at(k)))  //comprobar si existen en TD1
                {
                   QMessageBox::warning(datocheq, "Warning", tr( "La variable %1 de la encuesta especial no se encuentra en la/s tabla/s inicial/es" ).arg( lisVar.at(k)  ), "&Ok");
                   return false;
                }
            }
            if (datocheq->GetEdtValorC().isEmpty())
            {
                QMessageBox::warning(datocheq, "Warning", tr( "No se le ha asignado ningun valor" ), "&Ok");
                return false;
            }
        }else return true;
    }

    void TFrmCheckPoblacion::ButCancelarClick()
    {
        datocheq->hide();
    }

    void TFrmCheckPoblacion::ButAyudaClick()
    {
        TFrmAyudaChequear *ayudaCheq = new TFrmAyudaChequear(0, "AyudaChequear", Qt::Widget, padre);
        nuevo = new QScrollArea(0);
        nuevo->setWindowTitle(QApplication::translate("TFrmCheckPoblacion", "Ayuda", 0, QApplication::UnicodeUTF8));
        nuevo->setWindowFlags(Qt::WindowMinimizeButtonHint);
        nuevo->setMaximumSize(ayudaCheq->width()+5, ayudaCheq->height()+5);
        nuevo->setGeometry(padre->width()/2 - 5, 35, ayudaCheq->width()+5, 800);
        nuevo->setWidget(ayudaCheq);
        nuevo->show();
        //ayudaCheq->show();
    }

    void TFrmCheckPoblacion::ChbActCClick()
    {
        if (datocheq->GetChbActC()->isChecked()) {
          if (datocheq->GetEdtVarConteo().isEmpty()) {             
             datocheq->GbActC->setVisible(false);
             datocheq->GetChbActC()->setChecked(false);
             QMessageBox::warning(datocheq, "Warning", tr( "La variable de conteo esta vacia" ), "&Ok");
          }else datocheq->GbActC->setVisible(true);
        }else
          datocheq->GbActC->setVisible(false);
    }

    QString TFrmCheckPoblacion::ObtenerValor(int reg)
    {
        QStringList lisVar = datocheq->GetEdtVariablesC().split(", ");
        double valor = datocheq->GetEdtValorC().toDouble();
        QString operador = datocheq->GetOperadorC();
        QString varConteo = datocheq->GetEdtVarConteo();
        int porcentaje = datocheq->GetEdtPorcentaje().toInt();
        int k, num;
        int cont = 0;

        if (operador.contains("<"))
        {
            num = FmeMicroDatosAsociados->GetValor(reg, FmeVariablesAsociadas->GetIndiceVariable(varConteo));
            for (k = 0; k < num; k++) {
                if ((FmeMicroDatosAsociados->GetValor(reg, FmeVariablesAsociadas->GetIndiceVariable(lisVar.at(k))) < valor))
                        cont++;
            }
            return QString::number(cont, 10);
        }else {
            if (operador.contains(">"))
            {
                num = FmeMicroDatosAsociados->GetValor(reg, FmeVariablesAsociadas->GetIndiceVariable(varConteo));
                for (k = 0; k < num; k++) {
                    if ((FmeMicroDatosAsociados->GetValor(reg, FmeVariablesAsociadas->GetIndiceVariable(lisVar.at(k))) > valor))
                        cont++;
                }
                return QString::number(cont, 10);
            }else {
                if (operador.contains("<="))
                {
                    num = FmeMicroDatosAsociados->GetValor(reg, FmeVariablesAsociadas->GetIndiceVariable(varConteo));
                    for (k = 0; k < num; k++) {
                        if ((FmeMicroDatosAsociados->GetValor(reg, FmeVariablesAsociadas->GetIndiceVariable(lisVar.at(k))) <= valor))
                          cont++;
                    }
                    return QString::number(cont, 10);
                }else {
                    if (operador.contains(">="))
                    {
                        num = FmeMicroDatosAsociados->GetValor(reg, FmeVariablesAsociadas->GetIndiceVariable(varConteo));
                        for (k = 0; k < num; k++) {
                            if ((FmeMicroDatosAsociados->GetValor(reg, FmeVariablesAsociadas->GetIndiceVariable(lisVar.at(k))) >= valor))
                                cont++;
                        }
                        return QString::number(cont, 10);
                    }else {
                        if (operador.contains("!="))
                        {
                            num = FmeMicroDatosAsociados->GetValor(reg, FmeVariablesAsociadas->GetIndiceVariable(varConteo));
                            for (k = 0; k < num; k++) {
                                if ((FmeMicroDatosAsociados->GetValor(reg, FmeVariablesAsociadas->GetIndiceVariable(lisVar.at(k))) > valor))
                                    cont++;
                            }
                            return QString::number(cont, 10);
                        }else {
                            if (operador.contains("="))
                            {
                                num = FmeMicroDatosAsociados->GetValor(reg, FmeVariablesAsociadas->GetIndiceVariable(varConteo));
                                for (k = 0; k < num; k++) {
                                    if ((FmeMicroDatosAsociados->GetValor(reg, FmeVariablesAsociadas->GetIndiceVariable(lisVar.at(k))) > valor))
                                        cont++;
                                }
                                return QString::number(cont, 10);
                            }
                        }
                    }
                }
            }
        }
    }
