/*******************************************************************************
** EntradaDatos.h:
**
** author: M-S Hernández-García
*******************************************************************************/

#ifndef ENTRADADATOS_H
#define ENTRADADATOS_H

#include <QtCore/QVariant>
#include <QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

#include "Global.h"

class TFrmEntradaDatos : public QWidget
{   

private:	// User declarations

public:

    QLabel *LabEntradaDatos1;
    QLineEdit *EdtEntradaDatos1;
    QPushButton *ButAceptar;
    QPushButton *ButCancelar;

    TFrmEntradaDatos(QWidget* parent, const char* name, Qt::WindowFlags fl);
    
    void FijarEtiqueta1(QString Texto);
    
    void FijarEntrada1(QString Texto);
    
    QString GetEntrada1();
    
   
public slots:

};

extern TFrmEntradaDatos *FrmEntradaDatos; 

#endif // ENTRADADATOS_H
