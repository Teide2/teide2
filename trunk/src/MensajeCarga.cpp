/*******************************************************************************
** MensajeCarga.cpp: muestra un mensaje de informaci�n cuando ha terminado la
**                   carga de los datos.
**
** author: M-S Hern�ndez-Garc�a
*******************************************************************************/

#include "MensajeCarga.h"

TMensajeCarga::TMensajeCarga(QWidget* parent, Qt::WindowFlags fl, QString mensajeI, QString informacion):QWidget(parent, fl)
    {
        if (this->objectName().isEmpty())
            this->setObjectName(QString::fromUtf8("TMensajeCarga"));        
        this->setGeometry(parent->width()/2 - 60, parent->height()/2-60, 379, 193);
        //this->setWindowFlags(Qt::WindowMinMaxButtonsHint);
        //setWindowFlags(Qt::FramelessWindowHint);
        //setWindowFlags(Qt::WindowTitleHint);
        padre = parent;
        QFont font;
        font.setFamily(QString::fromUtf8("Tahoma"));
        this->setFont(font);
        mensaje = new QLabel(mensajeI, this, Qt::Widget);
        mensaje->setObjectName(QString::fromUtf8("mensaje"));
        mensaje->setGeometry(30, 30, 600, 81);
        ButOk = new QPushButton(this);
        ButOk->setObjectName(QString::fromUtf8("ButOk"));
        ButOk->setGeometry(30, 150, 93, 28);
        ButDetalles = new QPushButton(this);
        ButDetalles->setObjectName(QString::fromUtf8("ButDetalles"));
        ButDetalles->setGeometry(130, 150, 131, 28);
        ButDetalles->setText(tr("Mostrar Detalles..."));
        MemInfo = new QTextEdit(this);
        MemInfo->setObjectName(QString::fromUtf8("MemInfo"));
        MemInfo->setGeometry(13, 200, 651, 361);
        MemInfo->setText(informacion);
        MemInfo->setReadOnly(true);

        this->setWindowTitle(QApplication::translate("TMensajeCarga", "Informaci\303\263n...", 0, QApplication::UnicodeUTF8));
        ButOk->setText(QApplication::translate("TMensajeCarga", "OK", 0, QApplication::UnicodeUTF8));

        QObject::connect(ButOk, SIGNAL(clicked()), this, SLOT(ButOkClick()));
        QObject::connect(ButOk, SIGNAL(clicked()), parent, SLOT(Actualizacion_interfaz_usuario()));
        QObject::connect(ButDetalles, SIGNAL(clicked()), this, SLOT(ButDetallesClick()));
        QMetaObject::connectSlotsByName(this);        
    }
    void TMensajeCarga::closeEvent(QCloseEvent *event)
    {
        event->ignore();
    }
    void TMensajeCarga::ButOkClick()
    {        
        hide();
    }
    void TMensajeCarga::ButDetallesClick()
    {
        if (ButDetalles->text() == "Mostrar Detalles...")
        {
            ButDetalles->setText(tr("Ocultar Detalles..."));
            this->resize(679, 579);
        }else
        {
            ButDetalles->setText(tr("Mostrar Detalles..."));
            this->resize(679, 193);
        }
    }

    bool TMensajeCarga::load(const QString &f)
    {
        if (!QFile::exists(f))
            return false;
        QFile file(f);
        if (!file.open(QFile::ReadOnly))
            return false;

        QByteArray data = file.readAll();
        QTextCodec *codec = Qt::codecForHtml("UTF-32");
        QString str = codec->toUnicode(data);
        if (Qt::mightBeRichText(str)) {            
            MemInfo->setHtml(str);
        } else {
            str = QString::fromLocal8Bit(data);
            MemInfo->setPlainText(str);
        }
        return true;
    }
