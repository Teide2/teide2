/*******************************************************************************
** AvisoFiltro.h: abre la ventana que indica si hay algún filtro que no permite
**                  el NO_PROCEDE.
**
** author: M-S Hernández-García
*******************************************************************************/

#ifndef AVISOFILTRO_H
#define AVISOFILTRO_H

#include <QtCore/QVariant>
#include <QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QProgressBar>
#include <QtGui/QPushButton>
#include <QtGui/QTextEdit>
#include <QtGui/QWidget>


class TFrmAvisoFiltro : public QWidget
{
    Q_OBJECT

private:	// User declarations


public:

    QPushButton *ButOk;
    QTextEdit *MemInfo;    
    QPushButton *ButMasDetalle;


    TFrmAvisoFiltro(QWidget* parent, const char* name, Qt::WindowFlags fl, QString Aviso, QAction *padre);

public slots:

    void ButOkClick();
    void CerrarMetafileClick();
    void ButMasDetalleClick();

};

#endif // AVISOFILTRO_H
