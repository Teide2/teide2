/*******************************************************************************
** AyudaOrigenDatos.h: esta ventana muestra la ayuda del origen de datos de una
**                     base de datos Oracle.
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

#ifndef AYUDAORIGENDATOS_H
#define AYUDAORIGENDATOS_H

#include <QMainWindow>
#include <QTextBrowser>
#include <qstringlist.h>
#include <qmap.h>
#include <qdir.h>

class AyudaOrigenDatos : public QMainWindow
{

public:

    AyudaOrigenDatos( const QString& home_,  const QString& path, QWidget* parent = 0, const char *name=0 ): QMainWindow( parent )
{

    browser = new QTextBrowser( this );
    QStringList str(path);    
    QString meta = QDir::toNativeSeparators("dibujos/");
    str.append(path + meta);
    browser->setSearchPaths(str);    
    browser->setFrameStyle( QFrame::Panel | QFrame::Sunken );

    setCentralWidget( browser );

    if ( !home_.isEmpty() )
        browser->setSource( home_ );

    resize( 645,700 );

    browser->setFocus();

}

private:

    QTextBrowser* browser;

};

#endif
