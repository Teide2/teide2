/*******************************************************************************
** scrollarea.cpp: permite que cuando no este maximizada la ventana se muestre
**                 los scroll para ver completa la informacion de la ventana.
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


#include "scrollarea.h"

Scrollarea::Scrollarea( QWidget* parent, QWidget* hijo):QScrollArea( parent ) {
       setWindowTitle(hijo->windowTitle());
       hij = hijo;       
       WidthMax = this->maximumWidth();
       HeightMax = this->maximumHeight();
       setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
       connect(this, SIGNAL(miSignal()), hij, SLOT(ajustarSize()));       
   }

Scrollarea::~Scrollarea() {    }    

void Scrollarea::resizeEvent ( QResizeEvent * event ) 
    {
       /*QSize areaSize;
       QSize widgetSize;

       if (windowState()!= Qt::WindowMaximized)
       {
           //QMessageBox::warning(this, "Warning",  QApplication::translate("", "Min", 0), "&Ok");
           hij->setGeometry(0, 0, 1276, 746);
           emit miSignal();

           areaSize = viewport()->size();
           widgetSize = hij->size();
           verticalScrollBar()->setPageStep(widgetSize.height());
           horizontalScrollBar()->setPageStep(widgetSize.width());
           verticalScrollBar()->setRange(0, widgetSize.height() - areaSize.height());
           horizontalScrollBar()->setRange(0, widgetSize.width() - areaSize.width());

           if (widgetSize.height() - areaSize.height() <= 0)  this->resize(1293, this->height());
           else this->resize(this->width(), this->height());
           if (widgetSize.width() - areaSize.width() <= 0)  this->resize(this->width(), 763);
           else this->resize(this->width(), this->height());
       }else{
           //QMessageBox::warning(this, "Warning",  "Max"+QString::number(QGuiApplication::primaryScreen()->availableGeometry().width(),10)+" " + QString::number(QGuiApplication::primaryScreen()->availableGeometry().height(),10)+"\n" +QString::number(this->visibleRegion().boundingRect().width(),10)+ " "+ QString::number(this->visibleRegion().boundingRect().height(),10), "&Ok");
           this->resize(QGuiApplication::primaryScreen()->availableGeometry().width(), QGuiApplication::primaryScreen()->availableGeometry().height()-22);
           hij->setGeometry(0,0,QGuiApplication::primaryScreen()->availableGeometry().width()-5,QGuiApplication::primaryScreen()->availableGeometry().height()-30);//hij->resize(hij->maximumSize());//hij->resize(viewport()->size());
           updateGeometry();
           //hij->setGeometry(0,0,this->visibleRegion().boundingRect().width()-5,this->visibleRegion().boundingRect().height()-5);//hij->resize(hij->maximumSize());//hij->resize(viewport()->size());
           emit miSignal();

           areaSize = viewport()->size();
           widgetSize = hij->size();

           verticalScrollBar()->setPageStep(widgetSize.height());
           verticalScrollBar()->setRange(0, widgetSize.height() - areaSize.height());
           horizontalScrollBar()->setPageStep(widgetSize.width());
           horizontalScrollBar()->setRange(0, widgetSize.width() - areaSize.width());           
       }*/
    }

void Scrollarea::actualizartitulo(QString titulo)
    {
      setWindowTitle(titulo);
    }
void Scrollarea::mensaje()
{
    //QMessageBox::warning(0, "WarningMe",  "ancho " + QString::number(hij->width(),10) + " alto " + QString::number(hij->height(),10), "&Ok");

}

