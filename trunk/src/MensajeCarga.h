/*******************************************************************************
** MensajeCarga.h:
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

#ifndef MENSAJECARGA_H
#define MENSAJECARGA_H

#include <QFile>
#include <QByteArray>
#include <QApplication>
#include <QTextCodec>
#include <QString>
#include <QPushButton>
#include <QTextEdit>
#include <QWidget>
#include <QLabel>
#include <QDesktopWidget>
#include <QCloseEvent>


class TMensajeCarga : public QWidget
{
    Q_OBJECT

private:	// User declarations


public:

    QPushButton *ButOk;
    QPushButton *ButDetalles;
    QLabel *mensaje;
    QTextEdit *MemInfo;    

    TMensajeCarga(QWidget* parent, Qt::WindowFlags fl, QString mensajeI, QString informacion);
    bool load(const QString &f);
    void closeEvent(QCloseEvent *event);
public slots:

    void ButOkClick();    
    void ButDetallesClick();

private:
    QWidget* padre;
    QString information;

};

#endif // MENSAJECARGA_H
