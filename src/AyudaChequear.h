/*******************************************************************************
** AyudaChequear.h:
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

#ifndef AYUDACHEQUEAR_H
#define AYUDACHEQUEAR_H

#include <QFile>
#include <QByteArray>
#include <QApplication>
#include <QTextCodec>
#include <QString>
#include <QPushButton>
#include <QTextEdit>
#include <QWidget>
#include <QDesktopWidget>
#include <QLabel>
#include <QScrollArea>


class TFrmAyudaChequear : public QWidget
{
    Q_OBJECT

private:	// User declarations


public:

    QPushButton *ButOk;
    //QTextEdit *MemInfo;
    QLabel *Etiq1;
    QLabel *Etiq2;
    QLabel *Etiq3;
    QLabel *Etiq4;
    QLabel *Etiq5;
    QLabel *Etiq6;
    QLabel *Panel1;
    QLabel *Panel2;
    QLabel *Panel3;
    QLabel *Panel4;
    QLabel *Panel5;

    TFrmAyudaChequear(QWidget* parent, const char* name, Qt::WindowFlags fl, QWidget* otro);

    bool load(const QString &f);

public slots:

    void ButOkClick();    

};

#endif // AYUDACHEQUEAR_H
