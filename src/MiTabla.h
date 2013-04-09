/*******************************************************************************
** pintar.h: contiene la clase para crear la tabla.
**
** author: M-S Hernández-García
*******************************************************************************/

#ifndef MITABLA_H
#define MITABLA_H


#include <QPainter>
#include <QRect>
#include <QMessageBox>
#include <QSet>
#include <QTableView>
#include <QMouseEvent>
#include <QHeaderView>

class MiTabla: public QTableView
{
    Q_OBJECT

public:
     bool botonderecho;

     MiTabla(QWidget *parent);

     void mousePressEvent(QMouseEvent *event);

     void keyPressEvent(QKeyEvent *event);

     void keyReleaseEvent ( QKeyEvent * event );

     void emitirSennal();

     bool boton();
     
     void rowResized ( int i, int viejo, int nuevo);

public slots:

     void pruebaV(int logindex);

     void pruebaH(int logindex);


protected:

protected slots:

};


#endif // MITABLA_H
