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
       //connect(this, SIGNAL(miSignal()), this, SLOT(mensaje()));
       WidthMax = this->maximumWidth();
       HeightMax = this->maximumHeight();
       connect(this, SIGNAL(miSignal()), hij, SLOT(ajustarSize()));       
   }

Scrollarea::~Scrollarea() {    }    

void Scrollarea::resizeEvent ( QResizeEvent * event ) 
    {
       //if (qApp->desktop()->screenGeometry(-1).width() > 1100)
      // {
        // if (windowState() == Qt::WindowMaximized)
         //hij->resize(this->visibleRegion().boundingRect().width()-5,this->visibleRegion().boundingRect().height()-5);//hij->resize(hij->maximumSize());//hij->resize(viewport()->size());
        // else
        //     hij->resize(1276,746);
      // }
       //QMessageBox::warning(0, "Warning",  "ancho " + QString::number(hij->width(),10) + " alto " + QString::number(hij->height(),10), "&Ok");

       QSize areaSize;
       QSize widgetSize;

       if (windowState()!= Qt::WindowMaximized)
       {
           //this->resize(800, 600);
           //this->setMaximumWidth(1293);
           //this->setMaximumHeight(763);

           hij->setGeometry(0, 0, 1276, 746);
           //hij->resize(this->visibleRegion().boundingRect().width()-5,this->visibleRegion().boundingRect().height()-5);//hij->resize(hij->maximumSize());//hij->resize(viewport()->size());

           emit miSignal();
           //hij->ajustarSize();
           areaSize = viewport()->size();
           widgetSize = hij->size();//qApp->desktop()->screenGeometry(-1).size();//QSize(this->visibleRegion().boundingRect().width(),this->visibleRegion().boundingRect().height());
           verticalScrollBar()->setPageStep(widgetSize.height());
           horizontalScrollBar()->setPageStep(widgetSize.width());
           verticalScrollBar()->setRange(0, widgetSize.height() - areaSize.height());
           horizontalScrollBar()->setRange(0, widgetSize.width() - areaSize.width());
           /*if (qApp->desktop()->screenGeometry(-1).width() > 1100) {
             if (verticalScrollBar()->maximum() - verticalScrollBar()->minimum() + verticalScrollBar()->pageStep() >= 746)  this->setFixedWidth(1295);
             if (horizontalScrollBar()->maximum() - horizontalScrollBar()->minimum() + horizontalScrollBar()->pageStep() >= 1276)  this->setFixedHeight(764);
           }*/
           //if (qApp->desktop()->screenGeometry(-1).width() > 1100) {

             if (widgetSize.height() - areaSize.height() <= 0)  this->resize(1293, this->height());
             else this->resize(this->width(), this->height());
             if (widgetSize.width() - areaSize.width() <= 0)  this->resize(this->width(), 763);
             else this->resize(this->width(), this->height());

           //}
           //}
       }else{
           //this->setMaximumWidth(WidthMax);
           //this->setMaximumHeight(HeightMax);
           this->resize(this->visibleRegion().boundingRect().width(), this->visibleRegion().boundingRect().height());
           hij->setGeometry(0,0,this->visibleRegion().boundingRect().width()-5,this->visibleRegion().boundingRect().height()-5);//hij->resize(hij->maximumSize());//hij->resize(viewport()->size());
           emit miSignal();
           //hij->ajustarSize();
           areaSize = viewport()->size();
           widgetSize = hij->size();
           //widgetSize = qApp->desktop()->screenGeometry(-1).size();//QSize(this->visibleRegion().boundingRect().width(),this->visibleRegion().boundingRect().height());
           verticalScrollBar()->setPageStep(widgetSize.height());
           verticalScrollBar()->setRange(0, widgetSize.height() - areaSize.height());
           horizontalScrollBar()->setPageStep(widgetSize.width());
           horizontalScrollBar()->setRange(0, widgetSize.width() - areaSize.width());

           //if (verticalScrollBar()->maximum() - verticalScrollBar()->minimum() + verticalScrollBar()->pageStep() == 1276)  this->setFixedWidth(1276);
           //if (horizontalScrollBar()->maximum() - horizontalScrollBar()->minimum() + horizontalScrollBar()->pageStep() == 746)  this->setFixedHeight(746);

       }
    }

void Scrollarea::actualizartitulo(QString titulo)
    {
      setWindowTitle(titulo);
    }
void Scrollarea::mensaje()
{
    //QMessageBox::warning(0, "WarningMe",  "ancho " + QString::number(hij->width(),10) + " alto " + QString::number(hij->height(),10), "&Ok");

}
/*void Scrollarea::miSignal()
{
    QMessageBox::warning(0, "WarningSig",  "ancho " + QString::number(hij->width(),10) + " alto " + QString::number(hij->height(),10), "&Ok");

}*/
