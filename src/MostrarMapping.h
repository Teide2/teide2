/*******************************************************************************
** MostrarMapping.h: muestra la ventana con la tabla del mapping seleccionado.
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

#ifndef MOSTRARMAPPING_H
#define MOSTRARMAPPING_H

#include <QtCore/QVariant>
#include <QAction>
#include <QApplication>
#include <QButtonGroup>
#include <QWidget>
#include "TablaModel.h"

#include "EntradaDatos.h"

class Ui_TFrmMostrarMapping
{
public:    
    MiTabla *view;

    void setupUi(QFrame *TFrmMostrarMapping)
    {
      if (TFrmMostrarMapping->objectName().isEmpty())
        TFrmMostrarMapping->setObjectName(QString::fromUtf8("TFrmMostrarMapping"));
      TFrmMostrarMapping->resize(606, 165);

      view = new MiTabla(TFrmMostrarMapping);
      view->setGeometry(QRect(0, 0, 605, 165));

      retranslateUi(TFrmMostrarMapping);

      QMetaObject::connectSlotsByName(TFrmMostrarMapping);
    } // setupUi

    void retranslateUi(QFrame *TFrmMostrarMapping)
    {
      TFrmMostrarMapping->setWindowTitle(QApplication::translate("TFrmMostrarMapping", "Form", 0));
      view->setToolTip(QApplication::translate("TFrmMostrarMapping", "Rejilla de visualizaci\303\263n del mapping entre c\303\263digos y literales de variables.", 0));
    } // retranslateUi

};

namespace Ui {
    class TFrmMostrarMapping: public Ui_TFrmMostrarMapping {};
} // namespace Ui

class TFrmMostrarMapping : public QFrame, public Ui::TFrmMostrarMapping
{

public:

    TFrmMostrarMapping(QWidget* parent, const char* name, Qt::WindowFlags fl)
    {
      setupUi(this);      
    }
    
    void Mostrar(QString Titulo, QStringList *Codigos, QStringList *Literales)
    {
      QString **VectorDatosS = new QString*[Codigos->size()-1];
      QStringList listaH, listaV;      
      setWindowTitle(Titulo);      
      listaH.append(Literales->at(0));
      QString aux;      
      for (int i = 0; i < Codigos->size()-1; i++) {        
        VectorDatosS[i] = new QString[1]; 
        listaV.append(Codigos->at(i+1));
        VectorDatosS[i][0] = Literales->at(i+1);
      }
      TablaModel *model = new TablaModel(0, VectorDatosS, listaH, listaV);
      view->setModel(model);
      show();
    }

public slots:


private:

};

extern TFrmMostrarMapping * FrmMostrarMapping;

#endif // MOSTRARMAPPING_H
