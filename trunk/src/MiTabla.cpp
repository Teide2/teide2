/*******************************************************************************
** pintar.h: contiene la clase para crear la tabla.
**
** author: M-S Hernández-García
*******************************************************************************/

#include "MiTabla.h"


     MiTabla::MiTabla(QWidget *parent):QTableView(parent)
     {
         verticalHeader()->setResizeMode ( QHeaderView::Interactive );
         verticalHeader()->setHighlightSections(true);
         horizontalHeader()->setHighlightSections(true);
         connect(verticalHeader(), SIGNAL(sectionClicked(int)), this, SLOT(pruebaV(int)));
         connect(horizontalHeader(), SIGNAL(sectionClicked(int)), this, SLOT(pruebaH(int)));
     }
     void MiTabla::mousePressEvent(QMouseEvent *event)
     {
       QColor rojo;
       if (event->buttons() == Qt::RightButton)
          botonderecho = true;
       else botonderecho = false;
       QTableView::mousePressEvent(event);
       if (verticalHeader()->length ()  > 0)
       {
           rojo = this->currentIndex().model()->data(this->currentIndex(), Qt::BackgroundRole).value<QColor>();
           QString color = rojo.name();
           setStyleSheet("selection-color: black;selection-background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 " + color + ", stop: 1 gray);");
       }
     }

     void MiTabla::emitirSennal()
     {
         //pruebaV(currentIndex().row());
         QColor rojo = this->currentIndex().model()->data(this->currentIndex(), Qt::BackgroundRole).value<QColor>();
         QString color = rojo.name();
         setStyleSheet("selection-color: black;selection-background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 " + color + ", stop: 1 gray);");
     }

     void MiTabla::keyPressEvent(QKeyEvent *event)
     {
       if ((event->key() == Qt::Key_Left) || (event->key() == Qt::Key_Right) || (event->key() == Qt::Key_Down) || (event->key() == Qt::Key_Up)) {
         QTableView::keyPressEvent(event);
         this->clicked(this->currentIndex());
       }
       QColor rojo = this->currentIndex().model()->data(this->currentIndex(), Qt::BackgroundRole).value<QColor>();
       QString color = rojo.name();
       setStyleSheet("selection-color: black;selection-background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 " + color + ", stop: 1 gray);");
     }
     void MiTabla::keyReleaseEvent ( QKeyEvent * event )
     {
         QColor rojo = this->currentIndex().model()->data(this->currentIndex(), Qt::BackgroundRole).value<QColor>();
         QString color = rojo.name();
         setStyleSheet("selection-color: black;selection-background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 " + color + ", stop: 1 gray);");
     }

     bool MiTabla::boton() { return botonderecho; }
     
     void MiTabla::rowResized ( int i, int viejo, int nuevo)
     {
       emit verticalHeader()->resizeSection ( i, nuevo);
     }

     void MiTabla::pruebaV(int logindex)
     {
         setStyleSheet("selection-color: white;selection-background-color: blue;");
     }
     void MiTabla::pruebaH(int logindex)
     {
         if (verticalHeader()->length ()  > 0) setStyleSheet("selection-color: white;selection-background-color: blue;");
     }


