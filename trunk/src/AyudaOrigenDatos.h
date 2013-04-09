/*******************************************************************************
** AyudaOrigenDatos.h: esta ventana muestra la ayuda del origen de datos de una
**                     base de datos Oracle.
**
** author: M-S Hernández-García
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
    QString meta = QDir::convertSeparators("dibujos/");
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
