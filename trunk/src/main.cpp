/*******************************************************************************
** main.cpp: programa principal.
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

#include <QtGui>
#include <QtSql>
#include <QDebug>
#include <QtPlugin>
#include <QTextEdit>
#include <QTranslator>
#include <qcoreapplication.h>
#include <qapplication.h>
#include <qdir.h>
#include <qpixmap.h>
#include <qtimer.h>
#include <QObject>  
#include "Teide2.h"
#include <qwt_plot.h>
#include <qwt_plot_histogram.h>

#include "Flash.h"

int main( int argc, char ** argv )
{
    //QTranslator translator;
    //QString locale = QLocale::system().name();
    //translator.load(QString("teide2_") + locale); // para qe detecte cual es el idioma del sistema
    //translator.load("teide2tr_ing2");

    QApplication::setColorSpec( QApplication::ManyColor );
    QApplication a( argc, argv );
    a.setStyle(new QCleanlooksStyle);
    //a.installTranslator(&translator);
    QStringList l_libPaths;

    // Build plugins path
    QDir l_pluginsPath(qApp->applicationDirPath());
    l_pluginsPath.mkdir("plugins");
    l_pluginsPath.cd("plugins");

    // Set library paths
    l_libPaths << l_pluginsPath.path() << qApp->applicationDirPath() << qApp->libraryPaths();// << qApp->applicationDirPath()+"/lib/";
    qApp->setLibraryPaths(l_libPaths);

    TFrmPrincipal *w2 = new TFrmPrincipal(0, argc, argv);
    if (qApp->desktop()->numScreens() > 1) w2->setGeometry(qApp->desktop ()->availableGeometry (1));

    Scrollarea *scrollarea = new Scrollarea(0, w2);
    scrollarea->setWidget(w2);
    if (qApp->desktop ()->availableGeometry(-1).width() < 1100) {
         w2->setGeometry(0, 0, 1276, 714);
         scrollarea->setWindowFlags(Qt::WindowMinimizeButtonHint);         
    }
    
    w2->asignar(scrollarea);
    w2->PrimeraEjecucion();
    w2->ContandoEjecucion();
    a.setActiveWindow( w2 );
    QString start = QCoreApplication::applicationDirPath();
    QString meta = QDir::convertSeparators("/images/teide.png");
    scrollarea->setWindowIcon(QPixmap((start+meta)));

    TFrmFlash *FrmFlash = new TFrmFlash(0, "entrada", Qt::SplashScreen);
    FrmFlash->setGeometry(w2->width()/2 - FrmFlash->width()/2, w2->height()/2 - FrmFlash->height()/2, FrmFlash->width(), FrmFlash->height());
    FrmFlash->show();
    QTimer * counter = new QTimer( FrmFlash );
    QObject::connect( counter, SIGNAL(timeout()), FrmFlash, SLOT(hide()) );
    if (qApp->desktop ()->availableGeometry(1).width() < 1100) {
        scrollarea->setGeometry(20, 20, 800, 600);
        QObject::connect( counter, SIGNAL(timeout()), scrollarea, SLOT( show()));
    }else
        QObject::connect( counter, SIGNAL(timeout()), scrollarea, SLOT( showMaximized()));
    counter->start( 2000 );
    QObject::connect( counter, SIGNAL(timeout()), counter, SLOT( stop()) );
    if (argc > 1) {        
        QObject::connect( counter, SIGNAL(timeout()), w2, SLOT( HacerBatchMode()) );
    }

    return a.exec();    
}
