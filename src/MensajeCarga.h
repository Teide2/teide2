/*******************************************************************************
** MensajeCarga.h:
**
** author: M-S Hernández-García
*******************************************************************************/

#ifndef MENSAJECARGA_H
#define MENSAJECARGA_H

#include <QFile>
#include <QByteArray>
#include <QApplication>
#include <QTextCodec>
#include <QString>
#include <QPushButton>
#include <QTextEdit>
#include <QWidget>
#include <QLabel>
#include <QDesktopWidget>
#include <QCloseEvent>


class TMensajeCarga : public QWidget
{
    Q_OBJECT

private:	// User declarations


public:

    QPushButton *ButOk;
    QPushButton *ButDetalles;
    QLabel *mensaje;
    QTextEdit *MemInfo;    

    TMensajeCarga(QWidget* parent, Qt::WindowFlags fl, QString mensajeI, QString informacion);
    bool load(const QString &f);
    void closeEvent(QCloseEvent *event);
public slots:

    void ButOkClick();    
    void ButDetallesClick();

private:
    QWidget* padre;

};

#endif // MENSAJECARGA_H
