/*******************************************************************************
** Flash: visualiza la pantalla de bienvenida de TEIDE2.
**
** author: M-S Hernández-García
**
**  This file is part of TEIDE2.
**
**  TEIDE2 is free software: you can redistribute it and/or modify
**  it under the terms of the GNU General Public License as published by
**  the Free Software Foundation, either version 3 of the License, or
**  (at your option) any later version.
**
**  Foobar is distributed in the hope that it will be useful,
**  but WITHOUT ANY WARRANTY; without even the implied warranty of
**  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
**  GNU General Public License for more details.
**
**  You should have received a copy of the GNU General Public License
**  along with Foobar.  If not, see <http://www.gnu.org/licenses/>.
**
*******************************************************************************/

#ifndef FLASH_H
#define FLASH_H

#include <QtCore/QVariant>
#include <QAction>
#include <QApplication>
#include <QButtonGroup>
#include <QLabel>
#include <QWidget>
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
      QString meta = QDir::toNativeSeparators("/images/splash2.png");
      label->setPixmap(QPixmap(start+meta));      

      QSize size(511, 381);
      size = size.expandedTo(minimumSizeHint());
      resize(size);      
    }
    
protected:


};

#endif // FLASH_H
