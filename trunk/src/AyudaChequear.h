/*******************************************************************************
** AyudaChequear.h:
**
** author: M-S Hernández-García
*******************************************************************************/

#ifndef AYUDACHEQUEAR_H
#define AYUDACHEQUEAR_H

#include <QFile>
#include <QByteArray>
#include <QApplication>
#include <QTextCodec>
#include <QString>
#include <QPushButton>
#include <QTextEdit>
#include <QWidget>
#include <QDesktopWidget>
#include <QLabel>
#include <QScrollArea>


class TFrmAyudaChequear : public QWidget
{
    Q_OBJECT

private:	// User declarations


public:

    QPushButton *ButOk;
    //QTextEdit *MemInfo;
    QLabel *Etiq1;
    QLabel *Etiq2;
    QLabel *Etiq3;
    QLabel *Etiq4;
    QLabel *Etiq5;
    QLabel *Etiq6;
    QLabel *Panel1;
    QLabel *Panel2;
    QLabel *Panel3;
    QLabel *Panel4;
    QLabel *Panel5;

    TFrmAyudaChequear(QWidget* parent, const char* name, Qt::WindowFlags fl, QWidget* otro);

    bool load(const QString &f);

public slots:

    void ButOkClick();    

};

#endif // AYUDACHEQUEAR_H
