/*******************************************************************************
** MiBox.h: lugar donde van las gráficas.
**
** author: M-S Hernández-García
*******************************************************************************/

#include <qpen.h>
#include <qwt_plot.h>
#include <qwt_plot_grid.h>
#include <qwt_plot_marker.h>
//#include <qwt_interval_data.h>
#include <QPushButton>
#include <QGroupBox>
#include <qwt_plot_histogram.h>  //#include "histogram_item.h"

class MiBox: public QGroupBox
{   
public:
     QwtPlot *plotr;
     QwtPlotGrid *gridr;
     QwtPlot *plotc;
     QwtPlotGrid *gridc;
     unsigned NumRegistros;
     unsigned NumColumnas;
     unsigned *VectorTotalesPorFilas;
     unsigned *VectorTotalesPorColumnas;
     QwtPlotHistogram *histogramcol;
     QwtPlotHistogram *histogramreg;
     bool activeSerieColumnas;
     bool activeSerieRegistros;
     int ultimo;
     bool variables;
     QPushButton *ButAnterior;
     QPushButton *ButSiguiente;

     MiBox(QWidget *parent, int ancho, QWidget *otro):QGroupBox(parent)
     {
       setTitle(QApplication::translate("", "N\303\232MERO DE ERRORES [ejeX: Ordinal de registros, ejeY: N\303\272mero de errores]", 0, QApplication::UnicodeUTF8));
       this->setToolTip(QApplication::translate("", "Histograma de porcentajes de error.", 0, QApplication::UnicodeUTF8));

       plotr = new QwtPlot((QWidget*)this);
       plotr->setGeometry(QRect(2, 18, ancho-2, 145));
       plotr->setCanvasBackground(QColor(Qt::white));
       gridr = new QwtPlotGrid;
       gridr->enableXMin(true);
       gridr->enableYMin(true);
       gridr->setMajPen(QPen(Qt::black, 0, Qt::DotLine));
       gridr->setMinPen(QPen(Qt::gray, 0 , Qt::DotLine));
       gridr->attach(plotr);
       plotc = new QwtPlot((QWidget*)this);
       plotc->setGeometry(QRect(2, 18, ancho-2, 145));
       plotc->setCanvasBackground(QColor(Qt::white));
       gridc = new QwtPlotGrid;
       gridc->enableXMin(true);
       gridc->enableYMin(true);
       gridc->setMajPen(QPen(Qt::black, 0, Qt::DotLine));
       gridc->setMinPen(QPen(Qt::gray, 0 , Qt::DotLine));
       gridc->attach(plotc);
       ultimo = 0;

       ButAnterior = new QPushButton(this);
       ButAnterior->setObjectName(("ButAnterior"));
       ButAnterior->setGeometry(QRect(((ancho-2)/2)-25, 0, 20, 20));
       ButAnterior->setToolTip(QApplication::translate("", "Pulse aqu\303\255 para visualizar los anteriores", 0, QApplication::UnicodeUTF8));
       ButSiguiente = new QPushButton(this);
       ButSiguiente->setObjectName(("ButSiguiente"));
       ButSiguiente->setGeometry(QRect((ancho-2)/2, 0, 20, 20));
       ButSiguiente->setText(">");
       ButSiguiente->setToolTip(QApplication::translate("", "Pulse aqu\303\255 para visualizar los siguientes", 0, QApplication::UnicodeUTF8));
       ButAnterior->setText("<");
       QObject::connect(ButSiguiente, SIGNAL(clicked()), otro, SLOT(ButClick_sig()));
       QObject::connect(ButAnterior, SIGNAL(clicked()), otro, SLOT(ButClick_ant()));       
     }
     void inicializar()
     {
        histogramcol = new QwtPlotHistogram();
        histogramcol->setBrush(Qt::blue);
        //histogramcol->setColor(Qt::blue);
        histogramreg = new QwtPlotHistogram();
        histogramreg->setBrush(Qt::blue);
        //histogramreg->setColor(Qt::blue);


        /*QVector<QwtIntervalSample> samples(25);
        for ( uint i = 0; i < 25; i++ )
        {
           QwtInterval interval(double(i), i + 1.0);

           interval.setBorderFlags(QwtInterval::ExcludeMaximum);*/

           //samples[i] = QwtIntervalSample(i*2/*int*values values[i]*/, interval);
        /*}
        curve1->setData(new QwtIntervalSeriesData(samples));*/
        /*QwtArray<QwtDoubleInterval> intervalscol(100);
        QwtArray<double> valuescol(100);
        QwtArray<QwtDoubleInterval> intervalsreg(100);
        QwtArray<double> valuesreg(100);*/
        //QwtSeriesData<QwtIntervalSample> intervalscol(100);
        QVector<QwtIntervalSample> samplescol(100);
        //QVector<double> valuescol(100);
        //QwtSeriesData<QwtIntervalSample> intervalsreg;
        QVector<QwtIntervalSample> samplesreg(100);
        //QVector<double> valuesreg(100);
        double posX, width, value;
        double posY_maxR = 0.0;
        double posX_maxR = 0.0;
        double posY_maxV = 0.0;
        double posX_maxV = 0.0;
        //histogramreg->setSamples();
        int col;
        int reg;
        if (NumRegistros < 100) reg = NumRegistros;
        else reg = 100;
        for (int i = 0; i < reg; i++) {
         posX = (double)(i+1);
         width = 0.2;
         value = (double)VectorTotalesPorFilas[i];

         //intervalsreg[i] = QwtIntervalSample(posX, posX + double(width));
         QwtInterval interval(posX, posX + double(width));

         interval.setBorderFlags(QwtInterval::ExcludeMaximum);
         samplesreg[i] = QwtIntervalSample(value, interval);
         //valuesreg[i] = value;

         if (posX_maxR < posX) posX_maxR = posX;
         if (posY_maxR < value) posY_maxR = value;
        }
        if (NumColumnas < 100) col = NumColumnas;
        else col = 100;
        for (int j = 0; j < col; j++) {
         posX = (double)(j+1);
         width = 0.2;
         value = (double)VectorTotalesPorColumnas[j];

         //intervalscol[j] = QwtIntervalSample(posX, posX + double(width));
         QwtInterval interval(posX, posX + double(width));

         interval.setBorderFlags(QwtInterval::ExcludeMaximum);
         samplescol[j] = QwtIntervalSample(value, interval);
         //valuescol[j] = value;

         if (posX_maxV < posX) posX_maxV = posX;
         if (posY_maxV < value) posY_maxV = value;
        }
        histogramreg->setData(new QwtIntervalSeriesData(samplesreg));//QwtIntervalData(intervalsreg, valuesreg));
        histogramreg->attach(plotr);
        plotr->setAxisScale(QwtPlot::yLeft, 0.0, posY_maxR);
        plotr->setAxisScale(QwtPlot::xBottom, 0.0, posX_maxR);
        plotr->replot();
        plotr->show();
        histogramcol->setData(new QwtIntervalSeriesData(samplescol));//QwtIntervalData(intervalscol, valuescol));
        histogramcol->attach(plotc);
        plotc->setAxisScale(QwtPlot::yLeft, 0.0, posY_maxV);
        plotc->setAxisScale(QwtPlot::xBottom, 0.0, posX_maxV);
        plotc->replot();
        plotc->hide();
        ultimo = 100;
     }

     void operar(int i_ini, int j_ini)
     {
        double posX, width, value;
        
        if (activeSerieRegistros)
        {
          QVector<QwtIntervalSample> samplesreg(100);//QwtArray<QwtDoubleInterval> intervalsreg(100);
          //QVector<double> valuesreg(100);

          double posY_maxR = 0.0;
          double posX_maxR = 0.0;

          ultimo = i_ini+100;
          int reg;
          if (NumRegistros < i_ini + 100) reg = NumRegistros;
          else reg = i_ini + 100;
          for (int i = i_ini; i < reg; i++) {
            posX = (double)(i+1);
            width = 0.2;
            value = (double)VectorTotalesPorFilas[i];

            //intervalsreg[i-i_ini] = QwtDoubleInterval(posX, posX + double(width));
            QwtInterval interval(posX, posX + double(width));

            interval.setBorderFlags(QwtInterval::ExcludeMaximum);
            samplesreg[i-i_ini] = QwtIntervalSample(value, interval);
            //valuesreg[i-i_ini] = value;

            if (posX_maxR < posX) posX_maxR = posX;
            if (posY_maxR < value) posY_maxR = value;
          }
          histogramreg->setData(new QwtIntervalSeriesData(samplesreg));////histogramreg->setData(QwtIntervalData(intervalsreg, valuesreg));
          histogramreg->attach(plotr);
          plotr->setAxisScale(QwtPlot::yLeft, 0.0, posY_maxR);
          plotr->setAxisScale(QwtPlot::xBottom, (double)i_ini, posX_maxR);          
          plotc->hide();
          plotr->replot();
          plotr->show();
        }
        if (activeSerieColumnas)
        {
          QVector<QwtIntervalSample> samplescol(100);//QwtArray<QwtDoubleInterval> intervalscol(100);
          //QVector<double> valuescol(100);
          double posY_maxV = 0.0;
          double posX_maxV = 0.0;
          int col;

          ultimo = j_ini+100;
          if (NumColumnas < j_ini+100) col = NumColumnas;
          else col = j_ini+100;
          for (int j = j_ini; j < col; j++) {
            posX = (double)(j+1);
            width = 0.2;
            value = (double)VectorTotalesPorColumnas[j];

            //intervalscol[j-j_ini] = QwtDoubleInterval(posX, posX + double(width));
            QwtInterval interval(posX, posX + double(width));

            interval.setBorderFlags(QwtInterval::ExcludeMaximum);
            samplescol[j-j_ini] = QwtIntervalSample(value, interval);
            //valuescol[j-j_ini] = value;

            if (posX_maxV < posX) posX_maxV = posX;
            if (posY_maxV < value) posY_maxV = value;
          }
          histogramcol->setData(new QwtIntervalSeriesData(samplescol));////histogramcol->setData(QwtIntervalData(intervalscol, valuescol));
          histogramcol->attach(plotc);
          plotc->setAxisScale(QwtPlot::yLeft, 0.0, posY_maxV);
          plotc->setAxisScale(QwtPlot::xBottom, (double)j_ini, posX_maxV);          
          plotr->hide();
          plotc->replot();
          plotc->show();
       }
     }
     void mouseDoubleClickEvent ( QMouseEvent * event )
     {

       if (activeSerieColumnas)
          {
            activeSerieColumnas = false;
            activeSerieRegistros = true;
            this->setTitle(QApplication::translate("", "N\303\232MERO DE ERRORES [ejeX: Ordinal de registros, ejeY: N\303\272mero de errores]", 0, QApplication::UnicodeUTF8));
            operar(0, 0);            
          }
          else
          {
            activeSerieRegistros = false;
            activeSerieColumnas = true;
            if (variables) this->setTitle(QApplication::translate("", "N\303\232MERO DE ERRORES [ejeX: Ordinal de variables, ejeY: N\303\272mero de errores]", 0, QApplication::UnicodeUTF8));
            else this->setTitle(QApplication::translate("", "N\303\232MERO DE ERRORES [ejeX: Ordinal de reglas, ejeY: N\303\272mero de errores]", 0, QApplication::UnicodeUTF8));
            operar(0, 0);            
          }
       QGroupBox::mouseDoubleClickEvent ( event );
     }

     void ButClick_sig()
     {
      if (activeSerieColumnas) {
        if (ultimo < NumColumnas) operar(ultimo, ultimo);
      }
      if (activeSerieRegistros) {
        if (ultimo < NumRegistros) operar(ultimo, ultimo);
      }
     }
     void ButClick_ant()
     {
      if (ultimo - 200 < 0) ultimo = 0;
      else  ultimo -= 200;
      if (activeSerieColumnas) {
        if (ultimo < NumColumnas) operar(ultimo, ultimo);
      }
      if (activeSerieRegistros) {
        if (ultimo < NumRegistros) operar(ultimo, ultimo);
      }
     }
     void setNumColumnas(unsigned c) { NumColumnas = c; }
     void setNumRegistros(unsigned reg) { NumRegistros = reg; }
     void setVectorTotalesPorFilas(unsigned *f) { VectorTotalesPorFilas = f; }
     void setVectorTotalesPorColumnas(unsigned *c) { VectorTotalesPorColumnas = c; }
     void setActiveSerieColumnas(bool c) { activeSerieColumnas = c; }
     void setActiveSerieRegistros(bool r) { activeSerieRegistros = r; }
     void setVariables(bool v) { variables = v; }

public slots:    

protected:

protected slots:    

};
