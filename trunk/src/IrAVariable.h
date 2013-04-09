/*******************************************************************************
** IrAVariable.h: abre la ventana donde permite indicar los datos para acceder
**                  directamente a la variable indicada.
**
** author: M-S Hernández-García
*******************************************************************************/

#ifndef IRAVARIABLE_H
#define IRAVARIABLE_H

#include <QtCore/QVariant>
#include <QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QFrame>
#include <QtGui/QGroupBox>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QWidget>

#include "Global.h"

class TFrmIrAVariable : public QWidget
{
    Q_OBJECT

public:

    QGroupBox *RgpMetodo;
    QRadioButton *Rbnombre;
    QRadioButton *Rbnumero;
    QGroupBox *GbxPorNombre;
    QComboBox *CbxPorNombre;
    QGroupBox *GbxPorNumero;
    QComboBox *CbxPorNumero;
    QFrame *PanResultado;
    QPushButton *ButAplicar;
    QPushButton *ButCancelar;

    TFrmIrAVariable(QWidget* parent, const char* name, Qt::WindowFlags fl, QStringList *ListaVariables);

    unsigned GetVariableSeleccionada();

    QPushButton *GetButAplicar();

    QPushButton *GetButCancelar();

    QRadioButton *GetRbnombre();
    
    QRadioButton *GetRbnumero();

    QComboBox *GetCbxPorNombre();

    QComboBox *GetCbxPorNumero();

    void SetVariableSeleccionada(unsigned vs);

   
public slots:

    void RgpMetodoNombreClick();
    
    void RgpMetodoNumeroClick();

private:

    unsigned VariableSeleccionada;

};

#endif // IRAVARIABLE_H
