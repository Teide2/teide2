/*******************************************************************************
** DatosOracle.h: abre la ventana que pide los datos necesarios para abrir una
**                  base de datos Oracle.
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

#ifndef DATOSORACLE_H
#define DATOSORACLE_H

#include <QtCore/QVariant>
#include <QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

#include "AyudaOrigenDatos.h"



class DatosOracle : public QWidget
{
    Q_OBJECT

public:

    QLineEdit *EdtNombre;
    QLineEdit *EdtUsuario;
    QLineEdit *EdtPassword;
    QLineEdit *EdtHost;
    QLabel *LbNombre;    
    QLabel *LbUsuario;
    QLabel *LbPassword;
    QLabel *LbHost;
    QPushButton *ButAceptar;
    QPushButton *ButCancelar;

    DatosOracle(QWidget* parent, const char* name, Qt::WindowFlags fl, QString NombreBaseDatos);
    
    QString getEdtNombre();
    QString getEdtUsuario();
    QString getEdtPassword();
    QString getEdtHost();
    QString getNomBaseDatos();

public slots:

private:
    QString NomBaseDatos;

};

#endif // DATOSORACLE_H
