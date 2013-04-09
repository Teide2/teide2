/*******************************************************************************
** PedirExpresion.h: muestra la ventana donde se introduce la expresion a
**               buscar en la solpapa de microdatos.
**
** author: M-S Hernández-García
*******************************************************************************/

#ifndef PEDIREXPRESION_H
#define PEDIREXPRESION_H

#include <QtCore/QVariant>
#include <QAction>
#include <QtGui/QApplication>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QLabel>
#include <QtGui/QWidget>
#include <QMessageBox>

class TFrmPedirExpresion : public QFrame
{
    Q_OBJECT

public:

    QLabel *Texto;
    QLineEdit *EdtExpresion;
    QPushButton *ButAceptar;
    QPushButton *ButCancelar;    

    TFrmPedirExpresion(QWidget* parent, const char* name, Qt::WindowFlags fl);
    QString getExpresion();

public slots:

private:

};

#endif // PEDIREXPRESION_H
