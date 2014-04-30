/*******************************************************************************
** AvisoFiltro.h: abre la ventana que indica si hay algún filtro que no permite
**                  el NO_PROCEDE.
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

#ifndef AVISOFILTRO_H
#define AVISOFILTRO_H

#include <QtCore/QVariant>
#include <QAction>
#include <QApplication>
#include <QButtonGroup>
#include <QCheckBox>
#include <QLabel>
#include <QLineEdit>
#include <QProgressBar>
#include <QPushButton>
#include <QTextEdit>
#include <QWidget>


class TFrmAvisoFiltro : public QWidget
{
    Q_OBJECT

private:	// User declarations


public:

    QPushButton *ButOk;
    QTextEdit *MemInfo;    
    QPushButton *ButMasDetalle;


    TFrmAvisoFiltro(QWidget* parent, const char* name, Qt::WindowFlags fl, QString Aviso, QAction *padre);

public slots:

    void ButOkClick();
    void CerrarMetafileClick();
    void ButMasDetalleClick();

};

#endif // AVISOFILTRO_H
