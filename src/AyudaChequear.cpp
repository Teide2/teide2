/*******************************************************************************
** AyudaChequear.cpp: muestra la ayuda sobre como chequear
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

#include "AyudaChequear.h"

TFrmAyudaChequear::TFrmAyudaChequear(QWidget* parent, const char* name, Qt::WindowFlags fl, QWidget* otro):QWidget(parent, fl)
    {
        if (this->objectName().isEmpty())
            this->setObjectName(QString::fromUtf8("TFrmAyudaChequear"));
        //QRect tam = qApp->desktop ()->availableGeometry(1);
//        this->setGeometry(otro->width()/2 - 5, 35, otro->width()/2, otro->height()-30);
        this->setGeometry(otro->width()/2 - 5, 35, 865, 777);

        QFont font;
        font.setFamily(QString::fromUtf8("Tahoma"));
        this->setFont(font);
        this->setWindowFlags(Qt::WindowMinimizeButtonHint);
        //ButOk = new QPushButton(this);
        //ButOk->setObjectName(QString::fromUtf8("ButOk"));
        //ButOk->setGeometry(QRect(this->width()/2 - 13, this->height()-35, 113, 25));
       /* MemInfo = new QTextEdit(this);
        MemInfo->setObjectName(QString::fromUtf8("MemInfo"));
        MemInfo->setGeometry(QRect(2, 2, this->width()-4, this->height()-40));
        MemInfo->setReadOnly(true);*/
        Etiq1 = new QLabel(this);
        Etiq1->setObjectName(("Etiq1"));
        Etiq1->setGeometry(QRect(5, 5, 857, 98));
        Etiq1->setText(QApplication::translate("TFrmAyudaChequear", "Consiste en comprobar si 2 bases de datos relacionadas son coherentes. Es decir si el valor de unas variables comunes en las 2 bases de datos\n se encuentran en ambas.\nChequear poblaci\303\263n est\303\241 dividido en 5 paneles.\n\n", 0, QApplication::UnicodeUTF8));
        Panel1 = new QLabel(this);
        Panel1->setObjectName(("Panel1"));
        Panel1->setGeometry(QRect(5, 102, 509, 98));
        Panel1->setFrameShape(QFrame::Box);
        Panel1->setPixmap(QPixmap("images/panel1.bmp", 0, Qt::ColorOnly));
        Etiq2 = new QLabel(this);
        Etiq2->setObjectName(("Etiq2"));
        Etiq2->setGeometry(QRect(520, 102, 857, 110));
        Etiq2->setText(QApplication::translate("TFrmAyudaChequear", "Panel 1\n Este panel permite indicar las bases de datos a tratar.\n Se tomar\303\241 por defecto como primera base de datos la que\nse encuentra cargada en TEIDE2.\n La segunda base de datos ser\303\241 la que indique el usuario o\nla misma que la primera.\n\n", 0, QApplication::UnicodeUTF8));
        Panel2 = new QLabel(this);
        Panel2->setObjectName(("Panel2"));
        Panel2->setGeometry(QRect(5, 226, 510, 98));
        Panel2->setFrameShape(QFrame::Box);
        Panel2->setPixmap(QPixmap(("images/panel2.bmp")));
        Etiq3 = new QLabel(this);
        Etiq3->setObjectName(("Etiq3"));
        Etiq3->setGeometry(QRect(520, 226, 870, 98));
        Etiq3->setText(QApplication::translate("TFrmAyudaChequear", "Panel 2\n En este panel se indica las tablas de cada una de las bases\nde datos, por defecto la/s tabla/s primeras ser\303\241n las que\nse encuentran abiertas en TEIDE2.\n Se indicar\303\241n las tablas secundarias.\n\n", 0, QApplication::UnicodeUTF8));
        Panel3 = new QLabel(this);
        Panel3->setObjectName(("Panel3"));
        Panel3->setGeometry(QRect(5, 350, 510, 101));
        Panel3->setFrameShape(QFrame::Box);
        Panel3->setPixmap(QPixmap(("images/panel3.bmp")));
        Etiq4 = new QLabel(this);
        Etiq4->setObjectName(("Etiq4"));
        Etiq4->setGeometry(QRect(520, 350, 857, 68));
        Etiq4->setText(QApplication::translate("TFrmAyudaChequear", "Panel 3\n En este panel se indicar\303\241 que variables se quieren\nchequear, si es m\303\241s de una se separar\303\241n por (, ).\n\n", 0, QApplication::UnicodeUTF8));
        Panel4 = new QLabel(this);
        Panel4->setObjectName(("Panel4"));
        Panel4->setGeometry(QRect(5, 487, 513, 69));
        Panel4->setFrameShape(QFrame::Box);
        Panel4->setPixmap(QPixmap(("images/panel4.bmp")));
        Etiq5 = new QLabel(this);
        Etiq5->setObjectName(("Etiq5"));
        Etiq5->setGeometry(QRect(520, 473, 857, 118));
        Etiq5->setText(QApplication::translate("TFrmAyudaChequear", "Panel 4\n Si tambi\303\251n queremos indicar cu\303\241ntas veces se tienen que\nrepetir las combinaciones indicadas, lo podemos hacer\nindicando cual es la variable de conteo, es decir que\nvariable indica el n\303\272mero de repeticiones.\n Y a su vez se puede indicar si queremos el 100% de ese\nvalor o un porcentaje diferente (entre 1-100).\n\n", 0, QApplication::UnicodeUTF8));
        Panel5 = new QLabel(this);
        Panel5->setObjectName(("Panel5"));
        Panel5->setGeometry(QRect(5, 607, 511, 160));
        Panel5->setFrameShape(QFrame::Box);
        Panel5->setPixmap(QPixmap(("images/panel5.bmp")));
        Etiq6 = new QLabel(this);
        Etiq6->setObjectName(("Etiq6"));
        Etiq6->setGeometry(QRect(520, 607, 857, 118));
        Etiq6->setText(QApplication::translate("TFrmAyudaChequear", "Panel 5\n Este panel es para un tipo de encuesta especial, son\naquellas en las que para calcular el n\303\272mero de repeticiones,\nadem\303\241s de disponer de la variable de conteo y de un\nporcentaje, tambi\303\251n indicaremos una condici\303\263n.\n Poniendo las variables (deben estar en la primera base de\ndatos) y los valores a cumplir.", 0, QApplication::UnicodeUTF8));


        this->setWindowTitle(QApplication::translate("TFrmAyudaChequear", "Informaci\303\263n...", 0, QApplication::UnicodeUTF8));
        //ButOk->setText(QApplication::translate("TFrmAyudaChequear", "OK", 0, QApplication::UnicodeUTF8));

        //QObject::connect(ButOk, SIGNAL(clicked()), this, SLOT(ButOkClick()));
        //QMetaObject::connectSlotsByName(this);
        //load(QApplication::applicationDirPath() + "/doc/help/AyudaChequear.html");
    }

    void TFrmAyudaChequear::ButOkClick()
    {
        hide();
    }


    bool TFrmAyudaChequear::load(const QString &f)
    {

       /* if (!QFile::exists(f))
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
        }*/

        return true;
    }
