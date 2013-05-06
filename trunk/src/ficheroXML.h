/*******************************************************************************
** ficheroXML: pasa una base de datos Access a XML.
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

#include <qdom.h>
#include <QProgressDialog>

class ficheroXML {
  
public:

    int crearXML (QString NombreMetafile, QWidget *padre)
    {
      QString NombreBaseDatos, Key, NombreConjunto, NombreVariables, NombreMissing, NombreEdits;
      QString CadenaConexionBD, Variable, texto;
      QStringList *TablasMicroDatos;
      int NumTablas;
      int i, j;
      int NumVar = 0;

      NombreBaseDatos = QCoreApplication::applicationDirPath() + "/" + GetValorTag(NombreMetafile, "RBD");
      NombreBaseDatos = QDir::convertSeparators(NombreBaseDatos);

      if (!QFile::exists(NombreBaseDatos))
        return false;
      CadenaConexionBD = "DRIVER={Microsoft Access Driver (*.mdb)}; FIL={MS Acess}; DBQ=";
      CadenaConexionBD += NombreBaseDatos;
      QSqlDatabase *AdcConexionBD = &QSqlDatabase::addDatabase("QODBC3");
      AdcConexionBD->setDatabaseName(CadenaConexionBD);      
      if (AdcConexionBD->open()) {

        // Obtener las tablas de microdatos del conjunto
        TablasMicroDatos = GetTablasMicroDatos(NombreMetafile);
        NumTablas = TablasMicroDatos->count();

        // Obtener el nombre de la variable clave
        Key = GetValorTag(NombreMetafile, "KEY");
        NombreConjunto = GetValorTag(NombreMetafile, "NOM");
        NombreVariables = GetValorTag(NombreMetafile, "VAR");
        NombreMissing = GetValorTag(NombreMetafile, "MIS");
        NombreEdits = GetValorTag(NombreMetafile, "EDT");

        //Creacion del fichero Variable
        QSqlQuery query("SELECT * FROM " + NombreVariables + " ORDER BY ID", *AdcConexionBD);
        QProgressDialog progress("Leyendo tabla" + NombreVariables, "Cancelar" , 0, query.size(), padre);
        progress.setWindowModality(Qt::WindowModal);
        int cont = 0;
        QDomDocument doc("");
        QDomElement root = doc.createElement("dataroot");
        doc.appendChild(root);
        QSqlRecord record = query.record();
        while (query.next()) {
          progress.setValue(cont);

          QDomElement tag = doc.createElement("Variable");
          root.appendChild(tag);

          QDomElement t0 = doc.createElement("ID");
          t0.appendChild(doc.createTextNode(query.value(record.indexOf("ID")).toString()));
          tag.appendChild(t0);

          for (i = 0; i < NUM_ATRIBUTOS_VARIABLE; i++) {

            QDomElement t1 = doc.createElement(ATRIBUTOS_VARIABLE[i]);
            if ((ATRIBUTOS_VARIABLE[i] == "TIPO") || (ATRIBUTOS_VARIABLE[i] == "PESO"))
              t1.appendChild(doc.createTextNode(query.value(record.indexOf(ATRIBUTOS_VARIABLE[i])).toString()));
            else
              if ((NOPROCEDE.contains(ATRIBUTOS_VARIABLE[i])) || (ATRIBUTOS_VARIABLE[i] == "NO_SABE") || (ATRIBUTOS_VARIABLE[i] == "NO_CONTESTA") || (ATRIBUTOS_VARIABLE[i] == "NS_NC") || (ATRIBUTOS_VARIABLE[i] == "IMPUTABLE"))
                if (query.value(record.indexOf(ATRIBUTOS_VARIABLE[i])).toString() == "0")
                  t1.appendChild(doc.createTextNode("false"));
                else
                  t1.appendChild(doc.createTextNode("true"));
              else {
                texto = query.value(record.indexOf(ATRIBUTOS_VARIABLE[i])).toString();
                t1.appendChild(doc.createCDATASection(texto));
                if (ATRIBUTOS_VARIABLE[i] == "MAPPING")
                  if (!texto.isEmpty()) {
                    //Creacion del fichero Mapping
                    QSqlQuery query3("SELECT * FROM " + texto + " ORDER BY CODIGO", *AdcConexionBD);
                    if (query3.isActive()) {
                      QDomDocument doc3("");
                      QDomElement root3 = doc3.createElement("dataroot");
                      doc3.appendChild(root3);
                      QSqlRecord record3 = query3.record();
                      while (query3.next()) {
                        QDomElement tag = doc3.createElement("Mapping");
                        root3.appendChild(tag);

                        QDomElement t0 = doc3.createElement("CODIGO");
                        t0.appendChild(doc3.createTextNode(query3.value(record3.indexOf("CODIGO")).toString()));
                        tag.appendChild(t0);

                        QDomElement t1 = doc3.createElement("DESCRIPCION");
                        t1.appendChild(doc3.createCDATASection(query3.value(record3.indexOf("DESCRIPCION")).toString()));
                        tag.appendChild(t1);
                      }
                      QString xml3 = doc3.toString();
                      QFile file3(QDir::convertSeparators(QCoreApplication::applicationDirPath() + "/data/" + texto + ".xml"));
                      if (file3.open(QIODevice::WriteOnly))   {
                        QTextStream stream(&file3);
                        stream << "<?xml version='1.0' encoding='ISO-8859-1'?>\n";
                        stream << xml3;
                      }
                    }
                  }
              }
            tag.appendChild(t1);
          }
          NumVar++;
          cont++;
        }
        QString xml = doc.toString();
        QFile file(QDir::convertSeparators(QCoreApplication::applicationDirPath() + "/data/" + NombreVariables + ".xml"));
        if (file.open(QIODevice::WriteOnly))   {
          QTextStream stream(&file);
          stream << "<?xml version='1.0' encoding='ISO-8859-1'?>\n";
          stream << xml;
        }
        progress.setValue(query.size());
        //Creacion del fichero Microdatos
        for(i = 0; i < NumTablas; i++) {
          QSqlQuery query("SELECT * FROM " + TablasMicroDatos->at(i) + " ORDER BY ID", *AdcConexionBD);
          QDomDocument doc("");
          QDomElement root = doc.createElement("dataroot");
          doc.appendChild(root);
          QSqlRecord record = query.record();

          while (query.next()) {
            QDomElement tag = doc.createElement("Registro");
            root.appendChild(tag);

            QDomElement t0 = doc.createElement("ID");
            t0.appendChild(doc.createTextNode(query.value(record.indexOf("ID")).toString()));
            tag.appendChild(t0);

            QDomElement t1 = doc.createElement(Key);
            t1.appendChild(doc.createCDATASection(query.value(record.indexOf(Key)).toString()));
            tag.appendChild(t1);

            for (j = 0; j < NumVar; j++) {
              Variable = record.fieldName (j);              
              if ((Variable != Key) && (Variable != "ID") && (!Variable.isEmpty()))
              {
                QDomElement t2 = doc.createElement(Variable);
                t2.appendChild(doc.createCDATASection(query.value(record.indexOf(Variable)).toString()));
                tag.appendChild(t2);
              }
            }
          }
          QString xml = doc.toString();
          QFile file(QDir::convertSeparators(QCoreApplication::applicationDirPath() + "/data/" + TablasMicroDatos->at(i) + ".xml"));

          if (file.open(QIODevice::WriteOnly))   {
            QTextStream stream(&file);
            stream << "<?xml version='1.0' encoding='ISO-8859-1'?>\n";
            stream << xml;
          }
        }

        //Creacion del fichero EDIT
        QSqlQuery query2("SELECT * FROM " + NombreEdits + " ORDER BY ID", *AdcConexionBD);
        QDomDocument doc2("");
        QDomElement root2 = doc2.createElement("dataroot");
        doc2.appendChild(root2);
        QSqlRecord record2 = query2.record();
        while (query2.next()) {
          QDomElement tag = doc2.createElement("Edit");
          root2.appendChild(tag);

          QDomElement t0 = doc2.createElement("ID");
          t0.appendChild(doc2.createTextNode(query2.value(record2.indexOf("ID")).toString()));
          tag.appendChild(t0);

          for (i = 0; i < NUM_ATRIBUTOS_EDIT; i++) {
            QDomElement t1 = doc2.createElement(ATRIBUTOS_EDIT[i]);
            t1.appendChild(doc2.createCDATASection(query2.value(record2.indexOf(ATRIBUTOS_EDIT[i])).toString()));
            tag.appendChild(t1);
          }
        }
        QString xml2 = doc2.toString();
        QFile file2(QDir::convertSeparators(QCoreApplication::applicationDirPath() + "/data/" + NombreEdits + ".xml"));
        if (file2.open(QIODevice::WriteOnly))   {
          QTextStream stream(&file2);
          stream << "<?xml version='1.0' encoding='ISO-8859-1'?>\n";
          stream << xml2;
        }

        //Creacion del fichero Missing
        QSqlQuery query3("SELECT * FROM " + NombreMissing + " ORDER BY CODIGO", *AdcConexionBD);
        QDomDocument doc3("");
        QDomElement root3 = doc3.createElement("dataroot");
        doc3.appendChild(root3);
        QSqlRecord record3 = query3.record();
        while (query3.next()) {
          QDomElement tag = doc3.createElement("Missing");
          root3.appendChild(tag);

          QDomElement t0 = doc3.createElement("CODIGO");
          t0.appendChild(doc3.createTextNode(query3.value(record3.indexOf("CODIGO")).toString()));
          tag.appendChild(t0);

          QDomElement t1 = doc3.createElement("DESCRIPCION");
          t1.appendChild(doc3.createCDATASection(query3.value(record3.indexOf("DESCRIPCION")).toString()));
          tag.appendChild(t1);
        }
        QString xml3 = doc3.toString();
        QFile file3(QDir::convertSeparators(QCoreApplication::applicationDirPath() + "/data/" + NombreMissing + ".xml"));
        if (file3.open(QIODevice::WriteOnly))   {
          QTextStream stream(&file3);
          stream << "<?xml version='1.0' encoding='ISO-8859-1'?>\n";
          stream << xml3;
        }
      }
      QMessageBox::information(padre, "Creando ficheros", "Ficheros XML creados", QMessageBox::Ok);
      AdcConexionBD->close();
      return true;
    }

    QStringList *GetTablasMicroDatos(QString NombreMetafile)
    {
      int i = 1;
      QString NombreTabla;
      QStringList *TablasMicroDatos;

      TablasMicroDatos = new QStringList();
      NombreTabla = GetValorTag(NombreMetafile, "MD" + QString::number(i, 10));
      while(NombreTabla != "")
      {
        TablasMicroDatos->append(NombreTabla);
        i++;
        NombreTabla = GetValorTag(NombreMetafile, "MD" + QString::number(i, 10));
      }
      return TablasMicroDatos;
    }

    QString GetValorTag(QString NombreMetafile, QString tag)
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
};
