/*******************************************************************************
** CambiarMicrodato.h: permite modificar el microdato manualmente. Abre una
**                       ventana para realizar la modificación.
**
** author: M-S Hernández-García
*******************************************************************************/

#ifndef CAMBIARMICRODATO_H
#define CAMBIARMICRODATO_H

#include <QtCore/QVariant>
#include <QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QFrame>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

#include "Global.h"


class TFrmCambiarMicrodato : public QWidget
{
    Q_OBJECT

public:

    QLabel *LabTitulo;
    QLabel *LabVariable;
    QFrame *ShpRibete1;
    QLabel *LabRegistro;
    QLabel *LabValorAntiguoMicrodato;
    QFrame *ShpRibete2;
    QLabel *LabValorNuevoMicrodato;
    QFrame *ShpRibete3;
    QLineEdit *EdtVariable;
    QLineEdit *EdtRegistro;
    QLineEdit *EdtValorAntiguoMicrodato;
    QLineEdit *EdtValorNuevoMicrodato;
    QPushButton *ButAceptar;
    QPushButton *ButCancelar;

    TFrmCambiarMicrodato(QWidget* parent);

    void FijarParametros(QString NombreVariable, unsigned IndiceRegistro, double ValorAntiguo);
    
    /*void FijarIdioma()
    {
      LabTitulo->setCaption(STR0161);
      LabVariable->setCaption(STR0162);
      LabRegistro->setCaption(STR0163);
      LabValorAntiguoMicrodato->setCaption(STR0164);
      LabValorNuevoMicrodato->setCaption(STR0165);
      ButAceptar->setCaption(STR0038);
      ButCancelar->setCaption(STR0039);

      setCaption(STR0166);
    }  */

    QPushButton *GetButAceptar();
    QPushButton *GetButCancelar();
    
    double GetValorNuevo();

public slots:

    //void ButAceptarClick();

    //void ButCancelarClick();

private:

    double ValorNuevo;

};

#endif // CAMBIARMICRODATO_H
