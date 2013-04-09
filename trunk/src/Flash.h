/*******************************************************************************
** Flash: visualiza la pantalla de bienvenida de TEIDE2.
**
** author: M-S Hernández-García
*******************************************************************************/

#ifndef FLASH_H
#define FLASH_H

#include <QtCore/QVariant>
#include <QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QLabel>
#include <QtGui/QWidget>
#include <qpixmap.h>

class TFrmFlash : public QWidget
{
public:
    QLabel *label;

    TFrmFlash(QWidget* parent, const char* name, Qt::WindowFlags fl)
    : QWidget(parent, fl)
    {
      setObjectName(QString::fromUtf8("FrmFlash"));
      label = new QLabel(this);
      label->setObjectName(QString::fromUtf8("label"));
      label->setGeometry(QRect(0, -10, 521, 401));
      QString start = QCoreApplication::applicationDirPath();
      QString meta = QDir::convertSeparators("/images/splash2.png");
      label->setPixmap(QPixmap(start+meta));      

      QSize size(511, 381);
      size = size.expandedTo(minimumSizeHint());
      resize(size);      
    }
    
protected:


};

#endif // FLASH_H
