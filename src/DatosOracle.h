/*******************************************************************************
** DatosOracle.h: abre la ventana que pide los datos necesarios para abrir una
**                  base de datos Oracle.
**
** author: M-S Hernández-García
*******************************************************************************/

#ifndef DATOSORACLE_H
#define DATOSORACLE_H

#include <QtCore/QVariant>
#include <QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

#include "AyudaOrigenDatos.h"



class DatosOracle : public QWidget
{
    Q_OBJECT

public:

    QLineEdit *EdtNombre;
    QLineEdit *EdtUsuario;
    QLineEdit *EdtPassword;
    QLineEdit *EdtHost;
    QLabel *LbNombre;    
    QLabel *LbUsuario;
    QLabel *LbPassword;
    QLabel *LbHost;
    QPushButton *ButAceptar;
    QPushButton *ButCancelar;

    DatosOracle(QWidget* parent, const char* name, Qt::WindowFlags fl, QString NombreBaseDatos);
    
    QString getEdtNombre();
    QString getEdtUsuario();
    QString getEdtPassword();
    QString getEdtHost();
    QString getNomBaseDatos();

public slots:

private:
    QString NomBaseDatos;

};

#endif // DATOSORACLE_H
