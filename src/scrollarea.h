/*******************************************************************************
** scrollarea.h: permite que cuando no este
**               maximizada la ventana se muestre los scroll para ver complata
**               la informacion de la ventana.
**
** author: M-S Hernández-García
*******************************************************************************/

#ifndef SCROLLAREA_H
#define SCROLLAREA_H

#include <QScrollArea>
#include <QScrollBar>
#include <QApplication>
#include <QDesktopWidget>
#include <QMessageBox>

class Scrollarea : public QScrollArea
{
    Q_OBJECT
private:
   QWidget* hij;
   int WidthMax;
   int HeightMax;

public:

    Scrollarea( QWidget* parent, QWidget* hijo);

    ~Scrollarea() ;  

    void resizeEvent ( QResizeEvent * event );
    void actualizartitulo(QString titulo);

public slots:
    void mensaje();

signals:
    void miSignal();
   // void porl();
    /*void Scrollarea::miSignal()
    {
        QMessageBox::warning(0, "Warning",  "ancho " + QString::number(hij->width(),10) + " alto " + QString::number(hij->height(),10), "&Ok");
    };*/
   
};
#endif


