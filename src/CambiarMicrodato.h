/*******************************************************************************
** CambiarMicrodato.h: permite modificar el microdato manualmente. Abre una
**                       ventana para realizar la modificación.
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

#ifndef CAMBIARMICRODATO_H
#define CAMBIARMICRODATO_H

#include <QtCore/QVariant>
#include <QAction>
#include <QApplication>
#include <QButtonGroup>
#include <QFrame>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QWidget>

#include "Global.h"


class TFrmCambiarMicrodato : public QWidget
{
    Q_OBJECT

public:

    QLabel *LabTitulo;
    QLabel *LabVariable;
    QFrame *ShpRibete1;
    QLabel *LabRegistro;
    QLabel *LabValorAntiguoMicrodato;
    QFrame *ShpRibete2;
    QLabel *LabValorNuevoMicrodato;
    QFrame *ShpRibete3;
    QLineEdit *EdtVariable;
    QLineEdit *EdtRegistro;
    QLineEdit *EdtValorAntiguoMicrodato;
    QLineEdit *EdtValorNuevoMicrodato;
    QPushButton *ButAceptar;
    QPushButton *ButCancelar;

    TFrmCambiarMicrodato(QWidget* parent);

    void FijarParametros(QString NombreVariable, unsigned IndiceRegistro, double ValorAntiguo);
    
    /*void FijarIdioma()
    {
      LabTitulo->setCaption(STR0161);
      LabVariable->setCaption(STR0162);
      LabRegistro->setCaption(STR0163);
      LabValorAntiguoMicrodato->setCaption(STR0164);
      LabValorNuevoMicrodato->setCaption(STR0165);
      ButAceptar->setCaption(STR0038);
      ButCancelar->setCaption(STR0039);

      setCaption(STR0166);
    }  */

    QPushButton *GetButAceptar();
    QPushButton *GetButCancelar();
    
    double GetValorNuevo();

public slots:

    //void ButAceptarClick();

    //void ButCancelarClick();

private:

    double ValorNuevo;

};

#endif // CAMBIARMICRODATO_H
