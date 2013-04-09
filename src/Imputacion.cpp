/*******************************************************************************
** Imputacion.cpp: contiene todo lo necesario para trabajar con la solapa
**                   Imputacion.
**
** author: M-S Hernández-García
*******************************************************************************/

#include "Imputacion.h"

    TFmeImputacion::TFmeImputacion(QWidget* parent, const char* name, Qt::WindowFlags fl, QSqlDatabase *AdcConexionBD, TFmeTest *FmeTestAsociado, TFrmIrAVariable *FrmIrAVariable, TFrmCambiarMicrodato *FrmCambiarMicrodato, TFrmOpciones *FrmOpciones, bool oracle, bool Xml, QString NombreBaseDatos, bool excel, QTabWidget *PctContenedorPrincipal, QStringList *ListaIds)
    {
      setGeometry(0, 0, parent->width()-2, parent->height()-15);

      if (this->objectName().isEmpty())
        this->setObjectName(("TFmeImputacion"));
      QFont font;
      font.setFamily(("Tahoma"));
      this->setFont(font);

      PanProgreso = new QLineEdit(this);
      PanProgreso->setObjectName(("PanProgreso"));
      PanProgreso->setGeometry(QRect(0, 0, this->width(), 90));
      QColor color = Qt::green;
       color.setRgb(0, 218, 160);
      color.setHsv (164, 255, 218);
      QPalette palette( QApplication::palette() );
      palette.setColor( QPalette::Active, QPalette::Base, color );
      PanProgreso->setPalette(palette);
      LabOperacion = new QLabel(PanProgreso);
      LabOperacion->setObjectName(("LabOperacion"));
      LabOperacion->setGeometry(QRect(8, 8, 141, 18));
      LabProgreso = new QLabel(PanProgreso);
      LabProgreso->setObjectName(("LabProgreso"));
      LabProgreso->setGeometry(QRect(8, 52, 163, 18));
      LabPorcentaje = new QLabel(PanProgreso);
      LabPorcentaje->setObjectName(("LabPorcentaje"));
      LabPorcentaje->setGeometry(QRect(368, 8, 92, 18));
      LabElemento = new QLabel(PanProgreso);
      LabElemento->setObjectName(("LabElemento"));
      LabElemento->setGeometry(QRect(483, 8, 91, 18));
      EdtOperacion = new QLineEdit(PanProgreso);
      EdtOperacion->setObjectName(("EdtOperacion"));
      EdtOperacion->setGeometry(QRect(8, 24, 345, 23));
      EdtOperacion->setReadOnly(true);
      palette.setColor( QPalette::Active, QPalette::Base, Qt::white );
      EdtOperacion->setPalette(palette);
      PbrProgreso = new QProgressBar(PanProgreso);
      PbrProgreso->setObjectName(("PbrProgreso"));
      PbrProgreso->setGeometry(QRect(2, 73, PanProgreso->width()-2, 15));
      PbrProgreso->setValue(0);
      PbrProgreso->setTextVisible(false);
      EdtPorcentaje = new QLineEdit(PanProgreso);
      EdtPorcentaje->setObjectName(("EdtPorcentaje"));
      EdtPorcentaje->setGeometry(QRect(368, 24, 73, 23));
      EdtPorcentaje->setReadOnly(true);
      EdtPorcentaje->setPalette(palette);
      EdtElemento = new QLineEdit(PanProgreso);
      EdtElemento->setObjectName(("EdtElemento"));
      EdtElemento->setGeometry(QRect(483, 24, 113, 23));
      EdtElemento->setReadOnly(true);
      EdtElemento->setPalette(palette);
      PanContenedor = new QFrame(this);
      PanContenedor->setObjectName(("PanContenedor"));
      PanContenedor->setGeometry(QRect(0, 0, this->width(), this->height()-50));
      PanContenedor->setFrameShape(QFrame::Panel);
      PanContenedor->setFrameShadow(QFrame::Raised);
      VisualizarReg = new QComboBox(PctContenedorPrincipal);
      VisualizarReg->setGeometry(PanContenedor->width()-220, 0, 200, 25);
      VisualizarReg->setVisible(false);
      SbrBarraEstado = new QFrame(PanContenedor);
      SbrBarraEstado->setObjectName(("SbrBarraEstado"));
      SbrBarraEstado->setGeometry(QRect(1, PanContenedor->height()-2-22, PanContenedor->width()-1, 22));
      SbrBarraEstado->setFrameShape(QFrame::StyledPanel);
      SbrBarraEstado->setFrameShadow(QFrame::Raised);
      SbrBarraEstado1 = new QFrame(SbrBarraEstado);
      SbrBarraEstado1->setObjectName(("SbrBarraEstado1"));
      SbrBarraEstado1->setGeometry(QRect(0, 0, SbrBarraEstado->width()/2, 19));
      SbrBarraEstado1->setFrameShape(QFrame::Box);
      SbrBarraEstado1->setFrameShadow(QFrame::Raised);
      LabBarraEstado1 = new QLabel(SbrBarraEstado1);
      LabBarraEstado1->setObjectName(("LabBarraEstado1"));
      LabBarraEstado1->setGeometry(QRect(0, 0, SbrBarraEstado1->width(), 19));
      SbrBarraEstado2 = new QFrame(SbrBarraEstado);
      SbrBarraEstado2->setObjectName(("SbrBarraEstado2"));
      SbrBarraEstado2->setGeometry(QRect(SbrBarraEstado1->width()+1, 0, SbrBarraEstado1->width()-1, 19));
      SbrBarraEstado2->setFrameShape(QFrame::Box);
      SbrBarraEstado2->setFrameShadow(QFrame::Raised);
      LabBarraEstado2 = new QLabel(SbrBarraEstado2);
      LabBarraEstado2->setObjectName(("LabBarraEstado2"));
      LabBarraEstado2->setGeometry(QRect(3, 0, SbrBarraEstado2->width(), 19));
      PanIrA = new QFrame(PanContenedor);
      PanIrA->setObjectName(("PanIrA"));
      PanIrA->setGeometry(QRect(1, SbrBarraEstado->y()-2-43, PanContenedor->width()-1, 43));
      PanIrA->setFrameShape(QFrame::Box);
      PanIrA->setFrameShadow(QFrame::Raised);
      PanIrA2 = new QFrame(PanIrA);
      PanIrA2->setObjectName(("PanIrA"));
      PanIrA2->setGeometry(QRect(750, 0, PanIrA->width()-748, 43));
      PanIrA2->setFrameShape(QFrame::Box);
      PanIrA2->setFrameShadow(QFrame::Raised);

      LabIrARegistroPorNumero = new QLabel(PanIrA);
      LabIrARegistroPorNumero->setObjectName(("LabIrARegistroPorNumero"));
      LabIrARegistroPorNumero->setGeometry(QRect(7, 12, 90, 18));
      EdtIrARegistroPorNumero = new QLineEdit(PanIrA);
      EdtIrARegistroPorNumero->setObjectName(("EdtIrARegistroPorNumero"));
      EdtIrARegistroPorNumero->setGeometry(QRect(98, 8, 33, 23));

      LabIrARegistroPorNombre = new QLabel(PanIrA);
      LabIrARegistroPorNombre->setObjectName(("LabIrARegistroPorNombre"));
      LabIrARegistroPorNombre->setGeometry(QRect(135, 12, 90, 18));
      CbxIrARegistroPorNombre = new QComboBox(PanIrA);
      CbxIrARegistroPorNombre->setObjectName(("CbxIrARegistroPorNombre"));
      CbxIrARegistroPorNombre->setGeometry(QRect(230, 8, 135, 23));
      CbxIrARegistroPorNombre->setEditable(true);

      LabIrAVariablePorNumero = new QLabel(PanIrA);
      LabIrAVariablePorNumero->setObjectName(("LabIrAVariablePorNumero"));
      LabIrAVariablePorNumero->setGeometry(QRect(380, 12, 111, 18));
      EdtIrAVariablePorNumero = new QLineEdit(PanIrA);
      EdtIrAVariablePorNumero->setObjectName(("EdtIrAVariablePorNumero"));
      EdtIrAVariablePorNumero->setGeometry(QRect(480, 8, 33, 23));

      LabIrAVariablePorNombre = new QLabel(PanIrA);
      LabIrAVariablePorNombre->setObjectName(("LabIrAVariablePorNombre"));
      LabIrAVariablePorNombre->setGeometry(QRect(525, 12, 111, 18));
      CbxIrAVariablePorNombre = new QComboBox(PanIrA);
      CbxIrAVariablePorNombre->setObjectName(("CbxIrAVariablePorNombre"));
      CbxIrAVariablePorNombre->setGeometry(QRect(620, 8, 125, 23));
      CbxIrAVariablePorNombre->setEditable(true);

      LabNumVariablesAImputarBasico = new QLabel(PanIrA2);
      LabNumVariablesAImputarBasico->setObjectName(("LabNumVariablesAImputarBasico"));
      LabNumVariablesAImputarBasico->setGeometry(QRect(5, 12, 60, 18));
      EdtNumVariablesAImputarBasico = new QLineEdit(PanIrA2);
      EdtNumVariablesAImputarBasico->setObjectName(("EdtNumVariablesAImputarBasico"));
      EdtNumVariablesAImputarBasico->setGeometry(QRect(65, 8, 33, 23));
      EdtNumVariablesAImputarBasico->setReadOnly(true);
      palette.setColor( QPalette::Active, QPalette::Base, Qt::gray );
      EdtNumVariablesAImputarBasico->setPalette(palette);

      LabNumVariablesAImputar = new QLabel(PanIrA2);
      LabNumVariablesAImputar->setObjectName(("LabNumVariablesAImputar"));
      LabNumVariablesAImputar->setGeometry(QRect(108, 12, 57, 18));
      EdtNumVariablesAImputar = new QLineEdit(PanIrA2);
      EdtNumVariablesAImputar->setObjectName(("EdtNumVariablesAImputar"));
      EdtNumVariablesAImputar->setGeometry(QRect(170, 8, 33, 23));
      EdtNumVariablesAImputar->setReadOnly(true);
      EdtNumVariablesAImputar->setPalette(palette);

      LabNumVariablesImputadas = new QLabel(PanIrA2);
      LabNumVariablesImputadas->setObjectName(("LabNumVariablesImputadas"));
      LabNumVariablesImputadas->setGeometry(QRect(213, 12, 62, 18));
      EdtNumVariablesImputadas = new QLineEdit(PanIrA2);
      EdtNumVariablesImputadas->setObjectName(("EdtNumVariablesImputadas"));
      EdtNumVariablesImputadas->setGeometry(QRect(280, 8, 33, 23));
      EdtNumVariablesImputadas->setReadOnly(true);
      EdtNumVariablesImputadas->setPalette(palette);

      LabMicroDatoOriginal = new QLabel(PanIrA2);
      LabMicroDatoOriginal->setObjectName(("LabMicroDatoOriginal"));
      LabMicroDatoOriginal->setGeometry(QRect(343, 12, 129, 20));
      EdtMicroDatoOriginal = new QLineEdit(PanIrA2);
      EdtMicroDatoOriginal->setObjectName(("EdtMicroDatoOriginal"));
      EdtMicroDatoOriginal->setGeometry(QRect(420, 8, 50, 23));
      EdtMicroDatoOriginal->setReadOnly(true);
      EdtMicroDatoOriginal->setPalette(palette);
    
      menu = new QMenu( this);
      menu->addAction( QObject::tr("Salvar microdatos a fichero..."), this, SLOT(MitSalvarMicrodatosFicheroClick()));
      menu->addAction( QObject::tr("Salvar microdatos a BBDD..."), this, SLOT(MitSalvarMicrodatosBBDDClick()));
      menu->addSeparator();
      menu->addAction( QObject::tr("Aumentar el ancho de las columnas..."), this, SLOT(MitAumentarColumnasClick()));
      menu->addAction( QObject::tr("Disminuir el ancho de las columnas..."), this, SLOT(MitDisminuirColumnasClick()));

      menu2 = new QMenu( this);
      menu2->addAction( QObject::tr(""));

      scrollArea1 = new QScrollArea(0);   // se utiliza para visualizar la inform sobre reg. incorrectos

      view2 = new MiTabla(PanContenedor);
      view2->setGeometry(QRect(1, PanIrA->y()-2-65, PanContenedor->width()-1, 65));

      PanRegistroDonante = new QFrame(PanContenedor);
      PanRegistroDonante->setObjectName(("PanRegistroDonante"));
      PanRegistroDonante->setGeometry(QRect(1, view2->y()-2-32, PanContenedor->width()-1, 32));
      PanRegistroDonante->setFrameShape(QFrame::Box);
      PanRegistroDonante->setFrameShadow(QFrame::Raised);
      LabNumRegistrosDonantes = new QLabel(PanRegistroDonante);
      LabNumRegistrosDonantes->setObjectName(("LabNumRegistrosDonantes"));
      LabNumRegistrosDonantes->setGeometry(QRect(745, 8, 107, 19));
      LabNavRegDonantes = new QLabel(PanRegistroDonante);
      LabNavRegDonantes->setObjectName(("LabNavRegDonantes"));
      LabNavRegDonantes->setGeometry(QRect(8, 8, 146, 19));
      LabDistanciaAlfa = new QLabel(PanRegistroDonante);
      LabDistanciaAlfa->setObjectName(("LabDistanciaAlfa"));
      LabDistanciaAlfa->setGeometry(QRect(289, 10, 156, 19));
      UpdRegistroDonante_sig = new QPushButton(PanRegistroDonante);
      UpdRegistroDonante_sig->setObjectName(("UpdRegistroDonante_sig"));
      UpdRegistroDonante_sig->setGeometry(QRect(185, 6, 25, 25));
      UpdRegistroDonante_ant = new QPushButton(PanRegistroDonante);
      UpdRegistroDonante_ant->setObjectName(("UpdRegistroDonante_ant"));
      UpdRegistroDonante_ant->setGeometry(QRect(160, 6, 25, 25));
      EdtDistancia = new QLineEdit(PanRegistroDonante);
      EdtDistancia->setObjectName(("EdtDistancia"));
      EdtDistancia->setGeometry(QRect(459, 6, 81, 21));
      EdtDistancia->setReadOnly(true);
      EdtDistancia->setPalette(palette);
      ButCambiarRegistroDonante = new QPushButton(PanRegistroDonante);
      ButCambiarRegistroDonante->setObjectName(("ButCambiarRegistroDonante"));
      ButCambiarRegistroDonante->setGeometry(QRect(550, 6, 185, 23));
      EdtMensajeRegistroDonante = new QLineEdit(PanRegistroDonante);
      EdtMensajeRegistroDonante->setObjectName(("EdtMensajeRegistroDonante"));
      EdtMensajeRegistroDonante->setGeometry(QRect(905, 5, 140, 21));
      palette.setColor( QPalette::Active, QPalette::Base, Qt::darkGreen );
      EdtMensajeRegistroDonante->setPalette(palette);
      EdtMensajeRegistroDonante->setReadOnly(true);
      EdtIndiceRegistroDonante = new QLineEdit(PanRegistroDonante);
      EdtIndiceRegistroDonante->setObjectName(("EdtIndiceRegistroDonante"));
      EdtIndiceRegistroDonante->setGeometry(QRect(841, 5, 57, 21));
      EdtIndiceRegistroDonante->setReadOnly(true);
      palette.setColor( QPalette::Active, QPalette::Base, Qt::gray );
      EdtIndiceRegistroDonante->setPalette(palette);
      view3 = new MiTabla(PanContenedor);
      view3->setGeometry(QRect(1, PanRegistroDonante->y()-2-65, PanContenedor->width()-1, 65));
      PanLeyenda = new QFrame(PanContenedor);
      PanLeyenda->setObjectName(("PanLeyenda"));
      PanLeyenda->setGeometry(QRect(1, view3->y()-2-24, PanContenedor->width()-1, 24));
      PanLeyenda->setFrameShape(QFrame::Box);
      PanLeyenda->setFrameShadow(QFrame::Raised);
      ShpMicroDatoSimImputar = new QLabel(PanLeyenda);
      ShpMicroDatoSimImputar->setObjectName(("ShpMicroDatoSimImputar"));
      ShpMicroDatoSimImputar->setGeometry(QRect(8, 5, 15, 15));
      ShpMicroDatoSimImputar->setFrameShape(QFrame::Box);
      ShpMicroDatoSimImputar->setPixmap(QPixmap("images/blanco.bmp"));
      LabMicroDatoSinImputar = new QLabel(PanLeyenda);
      LabMicroDatoSinImputar->setObjectName(("LabMicroDatoSinImputar"));
      LabMicroDatoSinImputar->setGeometry(QRect(32, 5, 114, 19));
      ShpMicroDatoImputado = new QLabel(PanLeyenda);
      ShpMicroDatoImputado->setObjectName(("ShpMicroDatoImputado"));
      ShpMicroDatoImputado->setGeometry(QRect(152, 5, 15, 15));
      ShpMicroDatoImputado->setFrameShape(QFrame::Box);
      ShpMicroDatoImputado->setPixmap(QPixmap(("images/amarillo.bmp")));
      LabMicroDatoImputado = new QLabel(PanLeyenda);
      LabMicroDatoImputado->setObjectName(("LabMicroDatoImputado"));
      LabMicroDatoImputado->setGeometry(QRect(176, 5, 118, 19));
      ShpRegistroDonante = new QLabel(PanLeyenda);
      ShpRegistroDonante->setObjectName(("ShpRegistroDonante"));
      ShpRegistroDonante->setGeometry(QRect(292, 5, 15, 15));
      ShpRegistroDonante->setFrameShape(QFrame::Box);
      ShpRegistroDonante->setPixmap(QPixmap(("images/azul.bmp")));
      LabRegistroDonante = new QLabel(PanLeyenda);
      LabRegistroDonante->setObjectName(("LabRegistroDonante"));
      LabRegistroDonante->setGeometry(QRect(313, 5, 85, 19));
      ShpRegistroExcluido = new QLabel(PanLeyenda);
      ShpRegistroExcluido->setObjectName(("ShpRegistroExcluido"));
      ShpRegistroExcluido->setGeometry(QRect(408, 5, 15, 15));
      ShpRegistroExcluido->setFrameShape(QFrame::Box);
      ShpRegistroExcluido->setPixmap(QPixmap(("images/carne.bmp")));
      LabRegistroExcluido = new QLabel(PanLeyenda);
      LabRegistroExcluido->setObjectName(("LabRegistroExcluido"));
      LabRegistroExcluido->setGeometry(QRect(432, 5, 77, 19));
      ShpRegistroIncorrecto = new QLabel(PanLeyenda);
      ShpRegistroIncorrecto->setObjectName(("ShpRegistroIncorrecto"));
      ShpRegistroIncorrecto->setGeometry(QRect(520, 5, 15, 15));
      ShpRegistroIncorrecto->setFrameShape(QFrame::Box);
      ShpRegistroIncorrecto->setPixmap(QPixmap(("images/rojo.bmp")));
      LabRegistroIncorrecto = new QLabel(PanLeyenda);
      LabRegistroIncorrecto->setObjectName(("LabRegistroIncorrecto"));
      LabRegistroIncorrecto->setGeometry(QRect(544, 5, 94, 19));
      ShpMicroDatoSimImputarIncorrecto = new QLabel(PanLeyenda);
      ShpMicroDatoSimImputarIncorrecto->setObjectName(("ShpMicroDatoSimImputarIncorrecto"));
      ShpMicroDatoSimImputarIncorrecto->setGeometry(QRect(644, 5, 15, 15));
      ShpMicroDatoSimImputarIncorrecto->setFrameShape(QFrame::Box);
      ShpMicroDatoSimImputarIncorrecto->setPixmap(QPixmap("images/magenta.bmp"));
      LabMicroDatoSinImputarIncorrecto = new QLabel(PanLeyenda);
      LabMicroDatoSinImputarIncorrecto->setObjectName(("LabMicroDatoSinImputarIncorrecto"));
      LabMicroDatoSinImputarIncorrecto->setGeometry(QRect(665, 5, 170, 19));

      view = new MiTabla(PanContenedor);
      view->setGeometry(QRect(1, 0, PanContenedor->width()-1, PanLeyenda->y()-2));
      view->verticalHeader()->setDefaultSectionSize(20);

      this->setWindowTitle(QApplication::translate("TFmeImputacion", "Form", 0, QApplication::UnicodeUTF8));
      LabOperacion->setText(QApplication::translate("TFmeImputacion", "Operaci\303\263n en curso", 0, QApplication::UnicodeUTF8));
      LabProgreso->setText(QApplication::translate("TFmeImputacion", "Progreso de la operaci\303\263n", 0, QApplication::UnicodeUTF8));
      LabPorcentaje->setText(QApplication::translate("TFmeImputacion", "% completado", 0, QApplication::UnicodeUTF8));
      LabElemento->setText(QApplication::translate("TFmeImputacion", "# completado", 0, QApplication::UnicodeUTF8));
      EdtOperacion->setToolTip(QApplication::translate("TFmeImputacion", "Nombre de la operaci\303\263n que esta siendo ejecutada actualmente.", 0, QApplication::UnicodeUTF8));
      EdtOperacion->setText(QApplication::translate("TFmeImputacion", "Imputaci\303\263n de los microdatos.", 0, QApplication::UnicodeUTF8));
      PbrProgreso->setToolTip(QApplication::translate("TFmeImputacion", "Muestra del progreso de la operaci\303\263n.", 0, QApplication::UnicodeUTF8));
      EdtPorcentaje->setToolTip(QApplication::translate("TFmeImputacion", "Porcentaje completado de la operaci\303\263n.", 0, QApplication::UnicodeUTF8));
      EdtElemento->setToolTip(QApplication::translate("TFmeImputacion", "Elemento actual en proceso / N\303\272mero total de elementos a procesar", 0, QApplication::UnicodeUTF8));
      LabIrARegistroPorNumero->setText(QApplication::translate("TFmeImputacion", "Ir a reg. (num.)", 0, QApplication::UnicodeUTF8));
      LabIrARegistroPorNombre->setText(QApplication::translate("TFmeImputacion", "Ir a reg. (nom.)", 0, QApplication::UnicodeUTF8));
      LabIrAVariablePorNombre->setText(QApplication::translate("TFmeImputacion", "Ir a var. (nom.)", 0, QApplication::UnicodeUTF8));
      LabMicroDatoOriginal->setText(QApplication::translate("TFmeImputacion", "Dato original", 0, QApplication::UnicodeUTF8));
      LabNumVariablesAImputarBasico->setText(QApplication::translate("TFmeImputacion", "#Var. Bas.", 0, QApplication::UnicodeUTF8));
      LabNumVariablesAImputar->setText(QApplication::translate("TFmeImputacion", "#Var. Ext.", 0, QApplication::UnicodeUTF8));
      LabNumVariablesImputadas->setText(QApplication::translate("TFmeImputacion", "#Var. Imp.", 0, QApplication::UnicodeUTF8));
      LabIrAVariablePorNumero->setText(QApplication::translate("TFmeImputacion", "Ir a var. (num.)", 0, QApplication::UnicodeUTF8));
      CbxIrAVariablePorNombre->setToolTip(QApplication::translate("TFmeImputacion", "Seleccione la variable que desea visualizar.", 0, QApplication::UnicodeUTF8));
      CbxIrARegistroPorNombre->setToolTip(QApplication::translate("TFmeImputacion", "Seleccione el registro que desea visualizar.", 0, QApplication::UnicodeUTF8));
      EdtMicroDatoOriginal->setToolTip(QApplication::translate("TFmeImputacion", "Dato original sin imputaci\303\263n", 0, QApplication::UnicodeUTF8));
      EdtNumVariablesAImputarBasico->setToolTip(QApplication::translate("TFmeImputacion", "N\303\272mero de variables b\303\241sicas a imputar.", 0, QApplication::UnicodeUTF8));
      EdtNumVariablesAImputar->setToolTip(QApplication::translate("TFmeImputacion", "N\303\272mero de variables extendidas a imputar (componentes conexas)", 0, QApplication::UnicodeUTF8));
      EdtNumVariablesImputadas->setToolTip(QApplication::translate("TFmeImputacion", "N\303\272mero total de variables imputadas en este registro.", 0, QApplication::UnicodeUTF8));
      EdtIrAVariablePorNumero->setToolTip(QApplication::translate("TFmeImputacion", "Indique un n\303\272mero de variable y pulse ENTER parar ir a ella.", 0, QApplication::UnicodeUTF8));
      EdtIrARegistroPorNumero->setToolTip(QApplication::translate("TFmeImputacion", "Indique el n\303\272mero de registro y pulse enter para ir a \303\251l.", 0, QApplication::UnicodeUTF8));
      PanRegistroDonante->setToolTip(QApplication::translate("TFmeImputacion", "Panel de registros donantes", 0, QApplication::UnicodeUTF8));
      UpdRegistroDonante_sig->setText(QApplication::translate("TFmeImputacion", ">", 0, QApplication::UnicodeUTF8));
      UpdRegistroDonante_ant->setText(QApplication::translate("TFmeImputacion", "<", 0, QApplication::UnicodeUTF8));
      LabNumRegistrosDonantes->setText(QApplication::translate("TFmeImputacion", "# Reg. donante", 0, QApplication::UnicodeUTF8));
      LabNavRegDonantes->setText(QApplication::translate("TFmeImputacion", "Navegador reg. donantes", 0, QApplication::UnicodeUTF8));
      LabDistanciaAlfa->setText(QApplication::translate("TFmeImputacion", "Distancia al registro actual", 0, QApplication::UnicodeUTF8));
      EdtDistancia->setToolTip(QApplication::translate("TFmeImputacion", "Distancia del registro actual al donante actual sobre las variables b\303\241sicas a imputar.", 0, QApplication::UnicodeUTF8));
      ButCambiarRegistroDonante->setToolTip(QApplication::translate("TFmeImputacion", "Pulse aqu\303\255 para cambiar el registro donante al registro actual.", 0, QApplication::UnicodeUTF8));
      ButCambiarRegistroDonante->setText(QApplication::translate("TFmeImputacion", "CAMBIAR REGISTRO DONANTE", 0, QApplication::UnicodeUTF8));
      EdtMensajeRegistroDonante->setToolTip(QApplication::translate("TFmeImputacion", "El registro actual mostrado en esta rejilla es el donante.", 0, QApplication::UnicodeUTF8));
      EdtMensajeRegistroDonante->setText(QApplication::translate("TFmeImputacion", "REGISTRO DONANTE !!", 0, QApplication::UnicodeUTF8));
      EdtIndiceRegistroDonante->setToolTip(QApplication::translate("TFmeImputacion", "Registro donante actual / N\303\272mero total de registros donantes", 0, QApplication::UnicodeUTF8));
      view2->setToolTip(QApplication::translate("TFmeImputacion", "Informaci\303\263n de la variable", 0, QApplication::UnicodeUTF8));
      view->setToolTip(QApplication::translate("TFmeImputacion", "Rejilla de visualizaci\303\263n de microdatos imputados.(ALT  Ir a dato imputado) (SHIFT  Ir a posible dato incorrecto)", 0, QApplication::UnicodeUTF8));
      view->verticalHeader()->setToolTip(QApplication::translate("TFmeImputacion", "ID registro", 0, QApplication::UnicodeUTF8));
      view->horizontalHeader()->setToolTip(QApplication::translate("TFmeImputacion", "Variables", 0, QApplication::UnicodeUTF8));
      view3->setToolTip(QApplication::translate("TFmeImputacion", "Informaci\303\263n del registro donante actual.", 0, QApplication::UnicodeUTF8));
      LabBarraEstado1->setText("");
      LabBarraEstado2->setText("");
      PanLeyenda->setToolTip(QApplication::translate("TFmeImputacion", "Leyenda de imputaci\303\263n", 0, QApplication::UnicodeUTF8));
      ShpMicroDatoSimImputar->setText("");
      LabMicroDatoSinImputar->setText(QApplication::translate("TFmeImputacion", "Dato original", 0, QApplication::UnicodeUTF8));
      ShpMicroDatoImputado->setText("");
      LabMicroDatoImputado->setText(QApplication::translate("TFmeImputacion", "Dato imputado", 0, QApplication::UnicodeUTF8));
      ShpRegistroDonante->setText("");
      LabRegistroDonante->setText(QApplication::translate("TFmeImputacion", "Reg. correcto", 0, QApplication::UnicodeUTF8));
      ShpRegistroExcluido->setText("");
      LabRegistroExcluido->setText(QApplication::translate("TFmeImputacion", "Reg. excluido", 0, QApplication::UnicodeUTF8));
      ShpRegistroIncorrecto->setText("");
      LabRegistroIncorrecto->setText(QApplication::translate("TFmeImputacion", "Reg. incorrecto", 0, QApplication::UnicodeUTF8));
      ShpMicroDatoSimImputarIncorrecto->setText("");
      LabMicroDatoSinImputarIncorrecto->setText(QApplication::translate("TFmeImputacion", "Posible dato incorrecto", 0, QApplication::UnicodeUTF8));
      VisualizarReg->setToolTip(QApplication::translate("TFmeImputacion", "Seleccione el modo de vizualizaci\303\263n de los registros.", 0, QApplication::UnicodeUTF8));
      VisualizarReg->addItem(QApplication::translate("TFmeImputacion", "Visualizar todos", 0, QApplication::UnicodeUTF8));
      VisualizarReg->addItem(QApplication::translate("TFmeImputacion", "Visualizar correctos", 0, QApplication::UnicodeUTF8));
      VisualizarReg->addItem(QApplication::translate("TFmeImputacion", "Visualizar incorrectos", 0, QApplication::UnicodeUTF8));
      VisualizarReg->addItem(QApplication::translate("TFmeImputacion", "Visualizar warnig", 0, QApplication::UnicodeUTF8));
      VisualizarReg->addItem(QApplication::translate("TFmeImputacion", "Visualizar reg. seg\303\272n expresi\303\263n", 0, QApplication::UnicodeUTF8));

      QObject::connect(EdtIrARegistroPorNumero, SIGNAL(returnPressed()), this, SLOT(EdtIrARegistroPorNumeroKeyDown()));
      QObject::connect(CbxIrAVariablePorNombre, SIGNAL(activated ( const int & )), this, SLOT(CbxIrAVariablePorNombreCloseUp(const int &)));
      QObject::connect(CbxIrARegistroPorNombre, SIGNAL(activated ( const int & )), this, SLOT(CbxIrARegistroPorNombreCloseUp(const int &)));
      QObject::connect(EdtIrAVariablePorNumero, SIGNAL(returnPressed()), this, SLOT(EdtIrAVariablePorNumeroKeyDown()));
      QObject::connect(ButCambiarRegistroDonante, SIGNAL(clicked()), this, SLOT(ButCambiarRegistroDonanteClick()));
      QObject::connect(UpdRegistroDonante_sig, SIGNAL(clicked()), this, SLOT(UpdRegistroDonanteClick_sig()));
      QObject::connect(UpdRegistroDonante_ant, SIGNAL(clicked()), this, SLOT(UpdRegistroDonanteClick_ant()));
      QObject::connect(view2, SIGNAL(doubleClicked(const QModelIndex&)), this, SLOT(SgrRejillaVariableDblClick(const QModelIndex&)));
      QObject::connect(view, SIGNAL(clicked(const QModelIndex&)), this, SLOT(SgrRejillaSelectCell(const QModelIndex&)));
      QObject::connect(view->horizontalHeader(), SIGNAL(sectionClicked ( const int & )), this, SLOT(SgrRejillaSelectCellH(const int &)));
      QObject::connect(view->verticalHeader(), SIGNAL(sectionClicked ( const int & )), this, SLOT(SgrRejillaSelectCellV(const int &)));
      QObject::connect(view->verticalHeader(), SIGNAL(sectionClicked ( const int & )), this, SLOT(VisualizarInforRegIncorrecto(const int &)));
      QObject::connect(view, SIGNAL(pressed ( const QModelIndex& )), this, SLOT(VisualizarMenu(const QModelIndex& )));
      QObject::connect(view, SIGNAL(doubleClicked(const QModelIndex&)), this, SLOT(SgrRejillaDblClick(const QModelIndex&)));
      QObject::connect(view3, SIGNAL(doubleClicked(const QModelIndex&)), this, SLOT(SgrRejillaRegistroDonanteDblClick(const QModelIndex&)));
      QObject::connect(VisualizarReg, SIGNAL(activated ( const int & ) ), this, SLOT(VisualizarRegCloseUp(const int &)));

      QAction *RejAR = new QAction(view);
      RejAR->setShortcut(Qt::ALT + Qt::Key_Right);
      QObject::connect(RejAR, SIGNAL(triggered()), this, SLOT(SgrRejillaKeyDownAR()));
      view->addAction(RejAR);
      QAction *RejAL = new QAction(view);
      RejAL->setShortcut(Qt::ALT + Qt::Key_Left);
      QObject::connect(RejAL, SIGNAL(triggered()), this, SLOT(SgrRejillaKeyDownAL()));
      view->addAction(RejAL);
      QAction *RejAU = new QAction(view);
      RejAU->setShortcut(Qt::ALT + Qt::Key_Up);
      QObject::connect(RejAU, SIGNAL(triggered()), this, SLOT(SgrRejillaKeyDownAU()));
      view->addAction(RejAU);
      QAction *RejAD = new QAction(view);
      RejAD->setShortcut(Qt::ALT + Qt::Key_Down);
      QObject::connect(RejAD, SIGNAL(triggered()), this, SLOT(SgrRejillaKeyDownAD()));
      view->addAction(RejAD);
      QAction *RejSR = new QAction(view);
      RejSR->setShortcut(Qt::SHIFT + Qt::Key_Right);
      QObject::connect(RejSR, SIGNAL(triggered()), this, SLOT(SgrRejillaKeyDownSR()));
      view->addAction(RejSR);
      QAction *RejSL = new QAction(view);
      RejSL->setShortcut(Qt::SHIFT + Qt::Key_Left);
      QObject::connect(RejSL, SIGNAL(triggered()), this, SLOT(SgrRejillaKeyDownSL()));
      view->addAction(RejSL);
      QAction *RejSU = new QAction(view);
      RejSU->setShortcut(Qt::SHIFT + Qt::Key_Up);
      QObject::connect(RejSU, SIGNAL(triggered()), this, SLOT(SgrRejillaKeyDownSU()));
      view->addAction(RejSU);
      QAction *RejSD = new QAction(view);
      RejSD->setShortcut(Qt::SHIFT + Qt::Key_Down);
      QObject::connect(RejSD, SIGNAL(triggered()), this, SLOT(SgrRejillaKeyDownSD()));
      view->addAction(RejSD);

      QMetaObject::connectSlotsByName(this);

      Cargado = false;

      // Asociar las clases
      AsociarClases(FmeTestAsociado);
      this->FrmIrAVariable = FrmIrAVariable;
      this->FrmCambiarMicrodato = FrmCambiarMicrodato;
      this->FrmOpciones = FrmOpciones;

      MemLogs->append(QApplication::translate("", "Creando la clase de imputaci\303\263n de microdatos", 0, QApplication::UnicodeUTF8));
      QApplication::processEvents();

      // Fijamos un nombre
      this->Name = "FmeImputacion" + FmeMicroDatosAsociados->GetNombreTabla();
      this->ListaIds = ListaIds;
      // Conexion a la base de MicroDatos
      AdqConsulta = AdcConexionBD;
      query5 = new QSqlQuery(QString::null, *AdcConexionBD);
      Oracle = oracle;
      this->NombreBaseDatos = NombreBaseDatos;
      this->Xml = Xml;
      this->Excel = excel;

      // Fijar la cantidad de datos
      FijarCantidadDatos();
      CargarEnLista();

      // Copiar la rejilla desde los microdatos originales
      CopiarRejillaMicroDatos();
      model = new TablaModelI(0, MatrizMicroDatosS, listaH, listaV, FmeMicroDatosAsociados);
      view->setModel(model);

      // Copiar la rejilla de variable desde los microdatos originales
      CopiarRejillaVariable();
      model2 = new TablaModelInfoR(0, VectorDatosV, listaH2, listaV2);
      model2->setVectorPintar(VectorDatosV);
      view2->setModel(model2);            

      // Copiar la rejilla de registro desde los microdatos originales
      CopiarRejillaRegistroDonante();
      model3 = new TablaModelInfoR(0, VectorDatosR, listaH3, listaV3);
      view3->setModel(model3);      

      // Crear la matriz de microdatos  y la matriz de imputacion
      CrearMatrizMicroDatos();

      // Rellenar el combo de ir a
      CbxIrAVariablePorNombre->addItems(*FmeVariablesAsociadas->GetListaVariables());
      CbxIrAVariablePorNombre->setCurrentIndex(0);
      CbxIrAVariablePorNombre->setInsertPolicy(QComboBox::NoInsert);
      
      // Crear el grafo de variables
      CrearGrafoVariables();
      
      // Crear las componentes conexas
      CrearComponentesConexas();      

      MatrizRegistrosDonantes = NULL;

      MostrarInfoAsociada(0, 1, false);
      EscribirInformacion();
      repintar();
    }
    void TFmeImputacion::ajustarSize()
    {
        setGeometry(0, 0, parentWidget()->width()-2, parentWidget()->height()-15);

        PanContenedor->setGeometry(QRect(0, 0, this->width(), this->height()-50));

        VisualizarReg->setGeometry(PanContenedor->width()-220, 0, 200, 25);

        SbrBarraEstado->setGeometry(QRect(1, PanContenedor->height()-2-22, PanContenedor->width()-1, 22));

        SbrBarraEstado1->setGeometry(QRect(0, 0, SbrBarraEstado->width()/2, 19));

        LabBarraEstado1->setGeometry(QRect(0, 0, SbrBarraEstado1->width(), 19));

        SbrBarraEstado2->setGeometry(QRect(SbrBarraEstado1->width()+1, 0, SbrBarraEstado1->width()-1, 19));

        LabBarraEstado2->setGeometry(QRect(3, 0, SbrBarraEstado2->width(), 19));

        PanIrA->setGeometry(QRect(1, SbrBarraEstado->y()-2-43, PanContenedor->width()-1, 43));

        PanIrA2->setGeometry(QRect(750, 0, PanIrA->width()-748, 43));

        view2->setGeometry(QRect(1, PanIrA->y()-2-65, PanContenedor->width()-1, 65));

        PanRegistroDonante->setGeometry(QRect(1, view2->y()-2-32, PanContenedor->width()-1, 32));

        view3->setGeometry(QRect(1, PanRegistroDonante->y()-2-65, PanContenedor->width()-1, 65));

        PanLeyenda->setGeometry(QRect(1, view3->y()-2-24, PanContenedor->width()-1, 24));

        view->setGeometry(QRect(1, 0, PanContenedor->width()-1, PanLeyenda->y()-2));
    }

    QPushButton *TFmeImputacion::GetButCambiarRegistroDonante() { return ButCambiarRegistroDonante;}
    TFmeTest *TFmeImputacion::GetTestAsociado() { return FmeTestAsociado; }
    unsigned TFmeImputacion::GetRegistroDonante(unsigned IndiceRegistro) { return MatrizRegistrosDonantes[IndiceRegistro][MatrizRegistrosDonantes[IndiceRegistro][NRD].IndiceRegistro].IndiceRegistro; }
    double *TFmeImputacion::GetRegistro(unsigned IndiceRegistro) { return MatrizMicroDatos[IndiceRegistro]; }
    double TFmeImputacion::GetValor(unsigned IndiceRegistro, unsigned IndiceVariable) { return MatrizMicroDatos[IndiceRegistro][IndiceVariable]; }
    unsigned TFmeImputacion::GetNumRegistrosDonantes() { return NumRegistrosDonantes; }
    unsigned TFmeImputacion::GetNumRegistrosExcluidos() { return NumRegistrosExcluidos; }
    unsigned TFmeImputacion::GetNumRegistrosCorrectos() { return NumRegistrosCorrectos; }
    unsigned TFmeImputacion::GetNumRegistrosIncorrectos() { return NumRegistrosIncorrectos; }
    unsigned TFmeImputacion::GetNumRegistrosWarning() { return NumRegistrosWarning; }
    unsigned TFmeImputacion::GetNumRegistrosACorregir() { return NumRegistrosACorregir; }
    double TFmeImputacion::GetPorcentajeRegistrosDonantes() { return PorcentajeRegistrosDonantes; }
    double TFmeImputacion::GetPorcentajeRegistrosExcluidos() { return PorcentajeRegistrosExcluidos; }
    double TFmeImputacion::GetPorcentajeRegistrosCorrectos() { return PorcentajeRegistrosCorrectos; }
    double TFmeImputacion::GetPorcentajeRegistrosIncorrectos() { return PorcentajeRegistrosIncorrectos; }
    double TFmeImputacion::GetPorcentajeRegistrosWarning() { return PorcentajeRegistrosWarning; }
    double TFmeImputacion::GetPorcentajeRegistrosACorregir() { return PorcentajeRegistrosACorregir; }
    double TFmeImputacion::GetTiempoProcesoSegundos() { return (double)InstanteComienzo.secsTo(InstanteFinalizacion); }
    double TFmeImputacion::GetTiempoProcesoMilisegundos() { return (double)InstanteComienzo.msecsTo(InstanteFinalizacion); }
    unsigned TFmeImputacion::GetNumVariablesRangoAImputar(unsigned IndiceRegistro) { return VectorVariablesAImputarRangoAux[VectorMapeadoImputacionRegistros[IndiceRegistro]].size(); }
    unsigned TFmeImputacion::GetNumVariablesEditsAImputar(unsigned IndiceRegistro) { return VectorVariablesAImputarEditsAux[VectorMapeadoImputacionRegistros[IndiceRegistro]].size(); }
    unsigned TFmeImputacion::GetNumVariablesRangoAImputarImputables(unsigned IndiceRegistro) { return VectorVariablesAImputarRango[VectorMapeadoImputacionRegistros[IndiceRegistro]].size(); }
    unsigned TFmeImputacion::GetNumVariablesEditsAImputarImputables(unsigned IndiceRegistro) { return VectorVariablesAImputarEdits[VectorMapeadoImputacionRegistros[IndiceRegistro]].size(); }
    unsigned TFmeImputacion::GetNumVariablesExtendidasAImputar(unsigned IndiceRegistro) { return VectorVariablesAImputarExtendidoAux[VectorMapeadoImputacionRegistros[IndiceRegistro]].size(); }
    unsigned TFmeImputacion::GetNumVariablesExtendidasAImputarLargo(unsigned IndiceRegistro) { return VectorVariablesAImputarExtendidoLargoAux[VectorMapeadoImputacionRegistros[IndiceRegistro]].size(); }
    unsigned TFmeImputacion::GetNumVariablesImputadas(unsigned IndiceRegistro) { return NumVariablesImputadas[VectorMapeadoImputacionRegistros[IndiceRegistro]]; }
    unsigned TFmeImputacion::GetNumRegistrosImputados(unsigned IndiceVariable) { return NumRegistrosImputados[IndiceVariable]; }
    double TFmeImputacion::GetPorcentajeRegistrosImputados(unsigned IndiceVariable) { return ((double)NumRegistrosImputados[IndiceVariable] / (double)NumRegistros) * 100; }
    double **TFmeImputacion::GetMatrizMicroDatos() { return MatrizMicroDatos; }
    double TFmeImputacion::GetPromedioVariablesImputadasTotal() { return PromedioVariablesImputadasTotal; }
    double TFmeImputacion::GetPromedioVariablesImputadasSinWarning() { return PromedioVariablesImputadasSinWarning; }
    unsigned TFmeImputacion::GetIndiceVariableEnPosicion(unsigned Posicion) { return VectorPesosVariables[Posicion].IndiceVariable; }
    double TFmeImputacion::GetPesoVariableEnPosicion(unsigned Posicion) { return VectorPesosVariables[Posicion].Peso; }
    double TFmeImputacion::GetPromedioErroresRango() { return PromedioErroresRango; }
    double TFmeImputacion::GetPromedioErroresEdits() { return PromedioErroresEdits; }
    double TFmeImputacion::GetPromedioErroresTotal() { return PromedioErroresTotal; }
    double TFmeImputacion::GetPromedioSizeCompConexas() { return PromedioSizeCompConexas; }
    double TFmeImputacion::GetPromedioDistancias() { return PromedioDistancias; }
    bool TFmeImputacion::MicrodatoImputado(unsigned IndiceRegistro, unsigned IndiceVariable) { return MatrizImputacion[IndiceRegistro][IndiceVariable]; }
    bool TFmeImputacion::RegistroExcluido(unsigned IndiceRegistro) { return (ConjuntoRegistrosExcluidos.contains(IndiceRegistro)); }
    bool TFmeImputacion::RegistroIncorrecto(unsigned IndiceRegistro) { return (ConjuntoRegistrosIncorrectos.contains(IndiceRegistro)); }
    bool TFmeImputacion::RegistroWarning(unsigned IndiceRegistro) { return (ConjuntoRegistrosWarning.contains(IndiceRegistro)); }
    bool TFmeImputacion::RegistroDonante(unsigned IndiceRegistro) { return (ConjuntoRegistrosDonantes.contains(IndiceRegistro)); }
    QComboBox *TFmeImputacion::GetVisualizarReg() { return VisualizarReg;   }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Salvar los microdatos en un fichero.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void TFmeImputacion::SalvarMicrodatosEnFichero(QString NombreFichero)
    {
      QStringList *Datos;
      unsigned i, j;
      QString Linea;

      LabBarraEstado1->setText(tr("Guardando microdatos en fichero de texto... (ESPERE UN MOMENTO, POR FAVOR)"));
      QApplication::processEvents();

      Datos =  new QStringList();
      // Escribir los nombres de las variables
      Linea = "";
      for (j = 0; j < NumVariables; j++)
        Linea += (listaH.at(j+1) + " ");
      Datos->append(Linea);
      // Escribir todos los registros
      for (i = 0; i < NumRegistros; i++)
      {
        Linea = "";
        for (j = 0; j < NumVariables; j++)          
          Linea += (MatrizMicroDatosS[i][j+1] + " ");
        Datos->append(Linea);
      }
      // escribir en disco      
      QFile file( NombreFichero );
      if ( file.open( QIODevice::WriteOnly ) ) {
        QTextStream stream( &file );
        for ( QStringList::Iterator it = Datos->begin(); it != Datos->end(); ++it )
            stream << *it << "\n";
        file.close();
      }

      delete Datos;

      EscribirInformacion();
      QApplication::processEvents();
      QMessageBox::information(this, QApplication::translate("", "Informaci\303\263n", 0, QApplication::UnicodeUTF8), tr("MicroDatos salvados correctamente"), QMessageBox::Ok, QMessageBox::NoButton);
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Asociar las clases provenientes de etapas anteriores.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void TFmeImputacion::AsociarClases(TFmeTest *FmeTestAsociado)
    {
      this->FmeTestAsociado = FmeTestAsociado;
      this->FmeRangosAsociados = FmeTestAsociado->GetRangosAsociados();
      this->FmeEditsAsociados = FmeRangosAsociados->GetEditsAsociados();
      this->FmeMicroDatosAsociados = FmeEditsAsociados->GetMicroDatosAsociados();
      this->FmeVariablesAsociadas = FmeMicroDatosAsociados->GetVariablesAsociadas();
      this->MemLogs = FmeVariablesAsociadas->GetMemLogs();
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Actualizar la informacion del registro donante.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void TFmeImputacion::ActualizarInformacionRegistroDonante(unsigned IndiceRegistro, unsigned PosicionRegistroDonante)
    {
      unsigned IndiceRegistroDonante, IndiceMapeado;      

      if (MatrizRegistrosDonantes[IndiceRegistro][NRD].IndiceRegistro == (int)PosicionRegistroDonante)
      {
        ButCambiarRegistroDonante->setEnabled(false);
        EdtMensajeRegistroDonante->setVisible(true);
      }
      else
      {        
        if (RegistroIncorrecto(IndiceRegistro)) ButCambiarRegistroDonante->setEnabled(false);
        else  ButCambiarRegistroDonante->setEnabled(true);
        EdtMensajeRegistroDonante->setVisible(false);
      }
      EdtDistancia->setText(QString::number(MatrizRegistrosDonantes[IndiceRegistro][PosicionRegistroDonante].Distancia, 'f', 2).replace('.', ','));
      IndiceMapeado = VectorMapeadoImputacionRegistros[IndiceRegistro];
      EdtNumVariablesAImputar->setText(QString::number(VectorVariablesAImputarExtendidoAux[IndiceMapeado].size(), 10));
      EdtNumVariablesAImputarBasico->setText(QString::number(VectorVariablesAImputarRangoAux[IndiceMapeado].size() + VectorVariablesAImputarEditsAux[IndiceMapeado].size(), 10));
      EdtNumVariablesImputadas->setText(QString::number(NumVariablesImputadas[IndiceMapeado], 10));
      IndiceRegistroDonante = MatrizRegistrosDonantes[IndiceRegistro][PosicionRegistroDonante].IndiceRegistro;
      for (int i = 0; i < NumVariables; i++)
        VectorDatosR[i] = FmeMicroDatosAsociados->GetValorS(IndiceRegistroDonante, i);
      listaV3[0] = FmeMicroDatosAsociados->GetTablaModel()->headerData(IndiceRegistroDonante, Qt::Vertical, Qt::DisplayRole).toString();
      model3->setCabeceraV(listaV3);
      model3->setHeaderData(0, Qt::Vertical, QVariant(), Qt::DisplayRole);
      EdtIndiceRegistroDonante->setText(QString::number(PosicionRegistroDonante+1, 10) + "/" + QString::number(NRD, 10));
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Buscar la siguiente variable con error hacia la derecha en registro incorrecto.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    unsigned TFmeImputacion::BuscarVariableErrorDerechaRI(unsigned FilaOrigen, unsigned ColumnaOrigen)
    {
      unsigned j;
      unsigned IndiceMapeado = VectorMapeadoImputacionRegistros[FilaOrigen];
      if ((ColumnaOrigen == (unsigned)(NumVariables - 1)) || (!RegistroIncorrecto(FilaOrigen)))
        return ColumnaOrigen;
      for (j = ColumnaOrigen + 1; j < (unsigned)NumVariables; j++)
      {
        if (!FmeVariablesAsociadas->EsVariableImputable(j-1))
          if (VectorVariablesAImputarRangoAux[IndiceMapeado].contains(j-1) || VectorVariablesAImputarEditsAux[IndiceMapeado].contains(j-1) || VectorVariablesAImputarExtendidoAux[IndiceMapeado].contains(j-1) || VectorVariablesAImputarExtendidoLargoAux[IndiceMapeado].contains(j-1)) //MatrizImputacion[FilaOrigen][j-1])
            return (j);
      }      
      return ColumnaOrigen;      
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Buscar la siguiente variable con error hacia la izquierda en registro incorrecto.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    unsigned TFmeImputacion::BuscarVariableErrorIzquierdaRI(unsigned FilaOrigen, unsigned ColumnaOrigen)
    {
      int j;
      unsigned IndiceMapeado = VectorMapeadoImputacionRegistros[FilaOrigen];
      if ((ColumnaOrigen == 0) || (!RegistroIncorrecto(FilaOrigen)))
        return ColumnaOrigen;
      for (j = ColumnaOrigen - 1; j > 0; j--) {
        if (!FmeVariablesAsociadas->EsVariableImputable(j-1))
          if (VectorVariablesAImputarRangoAux[IndiceMapeado].contains(j-1) || VectorVariablesAImputarEditsAux[IndiceMapeado].contains(j-1) || VectorVariablesAImputarExtendidoAux[IndiceMapeado].contains(j-1) || VectorVariablesAImputarExtendidoLargoAux[IndiceMapeado].contains(j-1))
            return (j);
      }      
      return ColumnaOrigen;      
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Buscar el siguiente microdato erroneo hacia arriba en registro incorrecto.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    unsigned TFmeImputacion::BuscarMicroDatoErrorArribaRI(unsigned FilaOrigen, unsigned ColumnaOrigen)
    {
      int i;
      unsigned IndiceMapeado;
      if ((FilaOrigen == 0) || (FmeVariablesAsociadas->EsVariableImputable(ColumnaOrigen-1)))
        return FilaOrigen;
      for (i = FilaOrigen - 1; i >= 0; i--) {
        IndiceMapeado = VectorMapeadoImputacionRegistros[i];
        if ((RegistroIncorrecto(i)) && (VectorVariablesAImputarRangoAux[IndiceMapeado].contains(ColumnaOrigen-1) || VectorVariablesAImputarEditsAux[IndiceMapeado].contains(ColumnaOrigen-1) || VectorVariablesAImputarExtendidoAux[IndiceMapeado].contains(ColumnaOrigen-1) || VectorVariablesAImputarExtendidoLargoAux[IndiceMapeado].contains(ColumnaOrigen-1))) //MatrizImputacion[i][ColumnaOrigen-1])
          return i;
      }      
      return FilaOrigen;       
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Buscar el siguiente microdato erroneo hacia abajo en registro incorrecto.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    unsigned TFmeImputacion::BuscarMicroDatoErrorAbajoRI(unsigned FilaOrigen, unsigned ColumnaOrigen)
    {
      unsigned i;
      unsigned IndiceMapeado;
      if ((FilaOrigen == unsigned(NumRegistros - 1)) || (FmeVariablesAsociadas->EsVariableImputable(ColumnaOrigen-1)))
        return FilaOrigen;
      for (i = FilaOrigen + 1; i < (unsigned)NumRegistros; i++) {
        IndiceMapeado = VectorMapeadoImputacionRegistros[i];
        if ((RegistroIncorrecto(i)) && (VectorVariablesAImputarRangoAux[IndiceMapeado].contains(ColumnaOrigen-1) || VectorVariablesAImputarEditsAux[IndiceMapeado].contains(ColumnaOrigen-1) || VectorVariablesAImputarExtendidoAux[IndiceMapeado].contains(ColumnaOrigen-1) || VectorVariablesAImputarExtendidoLargoAux[IndiceMapeado].contains(ColumnaOrigen-1)))
          return i;
      }      
      return FilaOrigen;      
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Buscar la siguiente variable con error hacia la derecha.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    unsigned TFmeImputacion::BuscarVariableErrorDerecha(unsigned FilaOrigen, unsigned ColumnaOrigen)
    {
      unsigned j;

      if (ColumnaOrigen == (unsigned)(NumVariables - 1))
        return ColumnaOrigen;
      for (j = ColumnaOrigen + 1; j < (unsigned)NumVariables+1; j++)
        if (MatrizImputacion[FilaOrigen][j-1])
          return (j);      
      return ColumnaOrigen;
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Buscar la siguiente variable con error hacia la izquierda.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    unsigned TFmeImputacion::BuscarVariableErrorIzquierda(unsigned FilaOrigen, unsigned ColumnaOrigen)
    {
      int j;

      if (ColumnaOrigen == 0)
        return ColumnaOrigen;
      for (j = ColumnaOrigen - 1; j > 0; j--)
        if (MatrizImputacion[FilaOrigen][j-1])
          return (j);
      return ColumnaOrigen;
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Buscar el siguiente microdato erroneo hacia arriba.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    unsigned TFmeImputacion::BuscarMicroDatoErrorArriba(unsigned FilaOrigen, unsigned ColumnaOrigen)
    {
      int i;

      if (FilaOrigen == 0)
        return FilaOrigen;
       for (i = FilaOrigen - 1; i >= 0; i--)
         if (MatrizImputacion[i][ColumnaOrigen-1])
           return i;       
       return FilaOrigen;
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Buscar el siguiente microdato erroneo hacia abajo.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    unsigned TFmeImputacion::BuscarMicroDatoErrorAbajo(unsigned FilaOrigen, unsigned ColumnaOrigen)
    {
      unsigned i;

      if (FilaOrigen == unsigned(NumRegistros - 1))
        return FilaOrigen;
      for (i = FilaOrigen + 1; i < (unsigned)NumRegistros; i++)
        if (MatrizImputacion[i][ColumnaOrigen-1])
          return i;      
      return FilaOrigen;
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Buscar la componente conexa a partir de una variable por una busqueda en profundidad.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void TFmeImputacion::BuscarComponenteConexaDFS(unsigned IndiceVariable, bool *VariablesVisitadas, QList<TipoNodoCC> &ComponenteConexa)
    {
      QSet<unsigned>::iterator Puntero;
      TipoNodoCC temp;
      QStack<TipoNodoCC> VariablesPorVisitar;
      unsigned ProfundidadPadre;

      temp.nodo = IndiceVariable;
      temp.distancia = 0;
      VariablesPorVisitar.push(temp);
      VariablesVisitadas[IndiceVariable] = true;
      while (!VariablesPorVisitar.empty())
      {
        temp = VariablesPorVisitar.top();
        VariablesPorVisitar.pop();

        ComponenteConexa.push_back(temp);

        IndiceVariable = temp.nodo;
        ProfundidadPadre = temp.distancia;

        Puntero = GrafoVariables[IndiceVariable].begin();
        while (Puntero != GrafoVariables[IndiceVariable].end())
        {
          if (!VariablesVisitadas[(*Puntero)])
          {
            VariablesVisitadas[(*Puntero)] = true;
            temp.nodo = (*Puntero);
            temp.distancia = ProfundidadPadre + 1;
            VariablesPorVisitar.push(temp);
          }
          ++Puntero;
        }
      }
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Buscar la componente conexa a partir de una variable por una busqueda en anchura.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void TFmeImputacion::BuscarComponenteConexaBFS(unsigned IndiceVariable, bool *VariablesVisitadas, list<TipoNodoCC> &ComponenteConexa)
    {
      QSet<unsigned>::iterator Puntero;
      TipoNodoCC temp;
      QQueue<TipoNodoCC> VariablesPorVisitar;
      unsigned ProfundidadPadre;

      temp.nodo = IndiceVariable;
      temp.distancia = 0;      
      VariablesPorVisitar.enqueue(temp);
      VariablesVisitadas[IndiceVariable] = true;
      while (!VariablesPorVisitar.empty())
      {
        temp = VariablesPorVisitar.front();        
        VariablesPorVisitar.dequeue();

        ComponenteConexa.push_back(temp);

        IndiceVariable = temp.nodo;
        ProfundidadPadre = temp.distancia;

        Puntero = GrafoVariables[IndiceVariable].begin();
        while (Puntero != GrafoVariables[IndiceVariable].end())
        {
          if (!VariablesVisitadas[(*Puntero)])
          {
            VariablesVisitadas[(*Puntero)] = true;
            temp.nodo = (*Puntero);
            temp.distancia = ProfundidadPadre + 1;            
            VariablesPorVisitar.enqueue(temp);
          }
          ++Puntero;
        }
      }
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Buscar una donacion correcta.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    TTipoImputacionRegistro TFmeImputacion::BuscarDonacionCorrecta(unsigned IndiceRegistroAImputar, unsigned IndiceRegistroDonante, QSet<unsigned> VariablesRangoAImputar, QSet<unsigned> VariablesEditsAImputar, QSet<unsigned> VariablesExtendidasAImputar, QSet<unsigned> VariablesExtendidasLargasAImputar, double *RegistroTest, unsigned *NumVariablesImputadas)
    {
      QSet<unsigned>::iterator Puntero;
      double *RegistroDonante, *RegistroBackup;
      unsigned j, NumVariablesRango, NumVariablesEdits, NumVariablesBasicasAImputar, NumVariablesExtendidas, NumVariablesExtendidasLargas, NumVariablesDonadas, Frontera, IndiceVariable;
      bool RegistroCorrecto;
      QSet<unsigned> VariablesModificadas;

      NumVariablesRango = VariablesRangoAImputar.size();
      NumVariablesEdits = VariablesEditsAImputar.size();
      NumVariablesExtendidas = VariablesExtendidasAImputar.size();
      NumVariablesExtendidasLargas = VariablesExtendidasLargasAImputar.size();
      NumVariablesBasicasAImputar = NumVariablesRango + NumVariablesEdits;
      VariablesModificadas.clear();

       // Inicializar el registro test y crear el registro backup
      RegistroBackup = new double[NumVariables];
      for (j = 0; j < NumVariables; j++)  {
        RegistroTest[j] = GetValor(IndiceRegistroAImputar, j);
        RegistroBackup[j] = RegistroTest[j];        
      }

      // Obtener el registro donante
      RegistroDonante = GetRegistro(IndiceRegistroDonante);

      // Imputar las variables de rango
      ImputarVariablesTest(VariablesRangoAImputar, RegistroTest, RegistroBackup, RegistroDonante, &VariablesModificadas);
      
      // Evaluar el registro
      if (CheckRegistro(IndiceRegistroAImputar, RegistroTest, VariablesModificadas))
      {
        delete RegistroBackup;
        *NumVariablesImputadas = GetNumVariablesDistintas(IndiceRegistroAImputar, RegistroTest);
        if (*NumVariablesImputadas <= NumVariablesBasicasAImputar)
          return T_CORREGIDO_NO_WARNING;
        else
          return T_CORREGIDO_WARNING;
      }

      // Realizar una enumeracion sobre las variables de edits
      if (NumVariablesEdits > 0)
      {
        if (NumVariablesEdits <= UMBRAL_ENUM_VARIABLES)
          if (CheckEnumeracion(VariablesEditsAImputar, NumVariablesEdits, VectorPesosVariables, IndiceRegistroAImputar, RegistroTest, RegistroBackup, RegistroDonante, VariablesModificadas))
          {
            delete RegistroBackup;
            *NumVariablesImputadas = GetNumVariablesDistintas(IndiceRegistroAImputar, RegistroTest);
            if (*NumVariablesImputadas <= NumVariablesBasicasAImputar)
              return T_CORREGIDO_NO_WARNING;
            else
              return T_CORREGIDO_WARNING;
          }

        // Imputar las variables de edits

        ImputarVariablesTest(VariablesEditsAImputar, RegistroTest, RegistroBackup, RegistroDonante, &VariablesModificadas);

        // Evaluar el registro
        if (CheckRegistro(IndiceRegistroAImputar, RegistroTest, VariablesModificadas))
        {
          delete RegistroBackup;
          *NumVariablesImputadas = GetNumVariablesDistintas(IndiceRegistroAImputar, RegistroTest);
          if (*NumVariablesImputadas <= NumVariablesBasicasAImputar)
            return T_CORREGIDO_NO_WARNING;
          else
            return T_CORREGIDO_WARNING;
        }
      }

      delete RegistroBackup;

      // Donar las variables extendidas
      Frontera = 0;
      NumVariablesDonadas = 0;
      RegistroCorrecto = false;
      while ((NumVariablesDonadas < NumVariablesExtendidas) && (!RegistroCorrecto))
      {
        IndiceVariable = VectorPesosVariables[Frontera].IndiceVariable;
        if (VariablesExtendidasAImputar.contains(IndiceVariable))
        {
          if (RegistroTest[IndiceVariable] != RegistroDonante[IndiceVariable])
          {
            VariablesModificadas.insert(IndiceVariable);
            RegistroTest[IndiceVariable] = RegistroDonante[IndiceVariable];

            RegistroCorrecto = CheckRegistro(IndiceRegistroAImputar, RegistroTest, VariablesModificadas);
          }
          NumVariablesDonadas++;
        }
        Frontera++;
      }

      if (!RegistroCorrecto)
      {
        // Donar las variables extendidas largas
        Frontera = 0;
        NumVariablesDonadas = 0;
        RegistroCorrecto = false;
        while ((NumVariablesDonadas < NumVariablesExtendidasLargas) && (!RegistroCorrecto))
        {
          IndiceVariable = VectorPesosVariables[Frontera].IndiceVariable;
          if (VariablesExtendidasLargasAImputar.contains(IndiceVariable))
          {
            if (RegistroTest[IndiceVariable] != RegistroDonante[IndiceVariable])
            {
              VariablesModificadas.insert(IndiceVariable);
              RegistroTest[IndiceVariable] = RegistroDonante[IndiceVariable];

              RegistroCorrecto = CheckRegistro(IndiceRegistroAImputar, RegistroTest, VariablesModificadas);
            }
            NumVariablesDonadas++;
          }
          Frontera++;
        }
      }

      *NumVariablesImputadas = GetNumVariablesDistintas(IndiceRegistroAImputar, RegistroTest);

      if (RegistroCorrecto)
      {
        if (*NumVariablesImputadas <= NumVariablesBasicasAImputar)
          return T_CORREGIDO_NO_WARNING;
        else
          return T_CORREGIDO_WARNING;
      }
      else
        return T_NO_CORREGIDO;
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Carga el id de los registros en el combobox.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void TFmeImputacion::CargarEnLista()
    {
      CbxIrARegistroPorNombre->addItems(*ListaIds);
      CbxIrARegistroPorNombre->setCurrentIndex(0);
      CbxIrARegistroPorNombre->setInsertPolicy(QComboBox::NoInsert);
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Realizar un chequeo de los filtros y los edits explicitos sobre un determinado registro objetivo.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    bool TFmeImputacion::CheckRegistro(unsigned IndiceRegistroAImputar, double *RegistroTest, QSet<unsigned> VariablesModificadas)
    {
      QMap<QString,double> *MapTest;
      bool ResultadoRangos, ResultadoTest;

      MapTest = GetMapDesdeVector(RegistroTest);
      ResultadoRangos = FmeRangosAsociados->EvaluarFiltros(IndiceRegistroAImputar, VariablesModificadas, MapTest);
      ResultadoTest = ResultadoRangos && FmeTestAsociado->EvaluarRegistro(IndiceRegistroAImputar, VariablesModificadas, MapTest);

      delete MapTest;

      return ResultadoTest;
    }
    bool TFmeImputacion::CheckRegistro2(unsigned IndiceRegistroAImputar, double *RegistroTest, QSet<unsigned> VariablesModificadas)
    {
      QMap<QString,double> *MapTest;
      bool ResultadoRangos, ResultadoTest;

      MapTest = GetMapDesdeVector(RegistroTest);
      ResultadoRangos = FmeRangosAsociados->EvaluarFiltros(IndiceRegistroAImputar, VariablesModificadas, MapTest);
      ResultadoTest = ResultadoRangos && FmeTestAsociado->EvaluarRegistro2(IndiceRegistroAImputar, VariablesModificadas, MapTest);

      delete MapTest;

      return ResultadoTest;
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Realizar una enumeracion sobre el numero de variables del conjunto que se pase para probar si el registro se puede arreglar.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    bool TFmeImputacion::CheckEnumeracion(QSet<unsigned> VariablesEnumeracion, unsigned NumVariablesEnumeracion, TipoPesoVariable *VectorPesosVariables, unsigned IndiceRegistroAImputar, double *RegistroTest, double *RegistroBackup, double *RegistroDonante, QSet<unsigned> VariablesModificadas)
    {
      unsigned j, k, Frontera, IndiceVariable;
      bool *PatronEvaluacion;
      unsigned *VectorIndicesVariables;

      // Crear el patron de evaluacion
      PatronEvaluacion = new bool[NumVariablesEnumeracion];
      for (j = 0; j < NumVariablesEnumeracion; j++)
        PatronEvaluacion[j] = false;

      // Crear el vector de indices de variables
      VectorIndicesVariables = new unsigned[NumVariablesEnumeracion];
      for (j = 0, Frontera = 0; Frontera < NumVariablesEnumeracion; j++)
      {
        IndiceVariable = VectorPesosVariables[j].IndiceVariable;
        if (VariablesEnumeracion.contains(IndiceVariable))
        {
          VectorIndicesVariables[Frontera] = IndiceVariable;
          Frontera++;
        }
      }

      // Realizar la enumeracion
      for (j = 1; j <= NumVariablesEnumeracion; j++)
        if (GeneraNSobreM(PatronEvaluacion, VectorIndicesVariables, RegistroTest, RegistroDonante, RegistroBackup, IndiceRegistroAImputar, NumVariablesEnumeracion, j, 0, 0, VariablesModificadas))
        {
          delete VectorIndicesVariables;
          delete PatronEvaluacion;
          return true;
        }
        else
        {
          for (k = 0; k < NumVariablesEnumeracion; k++)
            PatronEvaluacion[k] = false;
        }

      delete VectorIndicesVariables;
      delete PatronEvaluacion;
      return false;
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Calcular las estadisticas de los procesos llevados a cabo.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void TFmeImputacion::CalcularEstadisticas()
    {
      PorcentajeRegistrosDonantes = ((double)NumRegistrosDonantes / (double)NumRegistros) * 100;
      PorcentajeRegistrosExcluidos = ((double)NumRegistrosExcluidos / (double)NumRegistros) * 100;
      PorcentajeRegistrosCorrectos = ((double)NumRegistrosCorrectos / (double)NumRegistros) * 100;
      PorcentajeRegistrosIncorrectos = ((double)NumRegistrosIncorrectos / (double)NumRegistros) * 100;
      PorcentajeRegistrosWarning = ((double)NumRegistrosWarning / (double)NumRegistros) * 100;
      PorcentajeRegistrosACorregir = ((double)NumRegistrosACorregir / (double)NumRegistros) * 100;

      if (NumRegistrosCorrectos == 0) {
        PromedioErroresRango = (double)0;
        PromedioErroresEdits = (double)0;
        PromedioErroresTotal = (double)0;
        PromedioSizeCompConexas = (double)0;
        PromedioDistancias = (double)0;
        PromedioVariablesImputadasTotal = (double)0;
        PromedioVariablesImputadasSinWarning = (double)0;

      }else {
        PromedioErroresRango = (double)NumErroresRango / (double)NumRegistrosCorrectos;
        PromedioErroresEdits = (double)NumErroresEdits / (double)NumRegistrosCorrectos;
        PromedioErroresTotal = (double)NumErroresTotal / (double)NumRegistrosCorrectos;
        PromedioSizeCompConexas = (double)SizeCompConexas / (double)NumRegistrosCorrectos;
        PromedioDistancias = (double)SumDistancias / (double)NumRegistrosCorrectos;
        PromedioVariablesImputadasTotal = (double)NumVariablesImputadasTotal / (double)NumRegistrosCorrectos;
        PromedioVariablesImputadasSinWarning = (double)(NumVariablesImputadasTotal - NumVariablesImputadasWarning) / (double)(NumRegistrosCorrectos - NumRegistrosWarning);
      }
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Copiar la rejilla desde los microdatos originales.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void TFmeImputacion::CopiarRejillaMicroDatos()
    {
      unsigned i, j;

      MatrizMicroDatosS = new QString*[FmeMicroDatosAsociados->GetNumRegistros()];

      listaH.append("Var. a imputar");
      // Fijas los anchos de columna
      for (j = 0; j < (unsigned)NumVariables; j++)  {
        view->setColumnWidth(j, ANCHO_VARIABLES_CORTAS);
        listaH.append(FmeMicroDatosAsociados->GetTablaModel()->headerData(j, Qt::Horizontal, Qt::DisplayRole).toString());
      }
      view->resizeColumnToContents (0);
      for (i = 0; i < (unsigned)NumRegistros; i++) {
        listaV.append(FmeMicroDatosAsociados->GetTablaModel()->headerData(i, Qt::Vertical, Qt::DisplayRole).toString());
        MatrizMicroDatosS[i] = new QString[FmeMicroDatosAsociados->GetNumVariables()+1];
        view->setRowHeight(i, 5);
        for (j = 0; j < (unsigned)NumVariables; j++) {          
          MatrizMicroDatosS[i][j+1] = FmeMicroDatosAsociados->GetValorS(i, j);
        }
      }
    }
    void TFmeImputacion::CopiarRejillaMicroDatos2()
    {
      unsigned i, j;

      for (i = 0; i < (unsigned)NumRegistros; i++)
        for (j = 0; j < (unsigned)NumVariables; j++)
          MatrizMicroDatosS[i][j+1] = FmeMicroDatosAsociados->GetValorS(i, j);          
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Copiar la rejilla de variable desde la rejilla de variable de microdatos originales.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void TFmeImputacion::CopiarRejillaVariable()
    {
      unsigned j;

      VectorDatosV = new QString[FmeVariablesAsociadas->GetNumAtributos()];

      // Copiar los valores
      for (j = 0; j < (unsigned)FmeVariablesAsociadas->GetNumAtributos(); j++) {        
        listaH2.append(FmeVariablesAsociadas->getlistaH(j));
      }
      listaV2.append(FmeVariablesAsociadas->getlistaV(0));      
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Copiar la rejilla de registro desde la rejilla de variable de microdatos originales.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void TFmeImputacion::CopiarRejillaRegistroDonante()
    {
      unsigned j;      

      VectorDatosR = new QString[NumVariables];

      // Copiar los titulos
      for (j = 0; j < (unsigned)NumVariables; j++) {
        listaH3.append(FmeMicroDatosAsociados->GetTablaModel()->headerData(j, Qt::Horizontal, Qt::DisplayRole).toString());        
      }
      listaV3.append("");      
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Crear la matriz de microdatos.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void TFmeImputacion::CrearMatrizMicroDatos()
    {
      unsigned i;

      MatrizMicroDatos = new double*[NumRegistros];
      MatrizImputacion = new bool*[NumRegistros];
      for (i = 0; i < NumRegistros; i++)  {
        MatrizMicroDatos[i] = new double[NumVariables];
        MatrizImputacion[i] = new bool[NumVariables];
      }
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Copiar la matriz de microdatos desde los originales.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void TFmeImputacion::CopiarMatrizMicroDatos()
    {
      unsigned i, j;

      for (i = 0; i < NumRegistros; i++)
        for (j = 0; j < NumVariables; j++)
          MatrizMicroDatos[i][j] = FmeMicroDatosAsociados->GetValor(i, j);
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Crear el conjunto de registros donantes.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void TFmeImputacion::CrearRegistrosDonantes()
    {
      unsigned i, j;
      bool Salir;

      ConjuntoRegistrosDonantes.clear();

      for (i = 0; i < NumRegistros; i++)
        if (!RegistroExcluido(i))
        {
          Salir = false;

          // Recorrido de las variables (edits de rango)
          for (j = 0; ((j < NumVariables) && (!Salir)); j++)
            if (!FmeRangosAsociados->VariableExcluida(j))
            {
              if (!FmeRangosAsociados->GetTest(i, j))
              {
                if (!FmeRangosAsociados->GetTestFiltro(i, j))
                  Salir = true;
                if (!FmeRangosAsociados->GetTestRango(i, j)) //if ((FmeVariablesAsociadas->EsVariableImputable(j)) && (!FmeRangosAsociados->GetTestRango(i, j)))
                  Salir = true;
              }
            }
          // Recorrido de los edits (edits explicitos)
          for (j = 0; ((j < NumEdits) && (!Salir)); j++)
          if (!FmeTestAsociado->EditExcluido(j))
          {
            if (!FmeTestAsociado->GetTestEdit(i, j))
              Salir = true;
          }

          if (!Salir)
            ConjuntoRegistrosDonantes.insert(i);
        }

      NumRegistrosDonantes = ConjuntoRegistrosDonantes.size();
      NRD = MIN(FrmOpciones->GetNumMaxRegDonantes(), NumRegistrosDonantes);      
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Crear la matriz de tipo de imputacion.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void TFmeImputacion::CrearMatrizImputacion()
    {
      unsigned i;

      MatrizImputacion = new bool*[NumRegistros];
      for (i = 0; i < NumRegistros; i++)
        MatrizImputacion[i] = new bool[NumVariables];
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Crear el conjunto de registros incorrectos.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void TFmeImputacion::InicializarConjuntoRegistrosIncorrectos()
    {
      ConjuntoRegistrosIncorrectos.clear();
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Inicializar el conjunto de registros warning.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void TFmeImputacion::InicializarConjuntoRegistrosWarning()
    {
      ConjuntoRegistrosWarning.clear();
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Asigna o devuelve del valor de PermImputacManual, el cual indica si se puede modificar manualmente.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void TFmeImputacion::SetPermImputacManual(bool valor)
    {
        PermImputacManual=valor;
    }
    bool TFmeImputacion::GetPermImputacManual()
    {
        return PermImputacManual;
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Crear el conjunto de variables a imputar.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void TFmeImputacion::CrearVariablesAImputar()
    {
      unsigned i, j, IndiceMapeado;
      QSet<unsigned> ConjuntoUnion, ConjuntoAux, ConjuntoFiltro, ConjuntoCC, ConjuntoRango, ConjuntoCCL;
      insert_iterator<QSet<unsigned> > Puntero(ConjuntoUnion, ConjuntoUnion.begin());
      insert_iterator<QSet<unsigned> > Puntero1(ConjuntoCC, ConjuntoCC.begin());
      QSet<unsigned>::iterator Puntero2;
      QList<TipoNodoCC>::iterator PunteroCC;

      // Recorrido de cada registro
      model->inicVariablesAImputar(NumRegistros);
      model->getVariablesAsociadas(FmeVariablesAsociadas);
      for (i = 0; i < NumRegistros; i++)
      {
        ConjuntoUnion.clear();
        ConjuntoRango.clear();
        if ((!RegistroDonante(i)) && (!RegistroExcluido(i)))
        {
          // Recorrido de las variables (edits de rango)
          for (j = 0; j < NumVariables; j++)
            if (!FmeRangosAsociados->VariableExcluida(j))
            {
              if (!FmeRangosAsociados->GetTest(i, j))   // tiene un error de rango y/o filtro
              {
                ConjuntoAux.clear();
                // CONTROL DE LAS VARIABLES DEL FILTRO
                if (!FmeRangosAsociados->GetTestFiltro(i, j))
                {
                  ConjuntoAux = FmeVariablesAsociadas->GetVariablesFiltros(j);
                  ConjuntoAux.insert(j);
                }
                // Insertamos la variable
                if (!FmeRangosAsociados->GetTestRango(i, j))
                  ConjuntoRango.insert(j);

                ConjuntoUnion.unite(ConjuntoAux);
              }
            }
          // Recorrido de los edits (edits explicitos)
          for (j = 0; j < NumEdits; j++)
            if (!FmeTestAsociado->EditExcluido(j))
            {
              if (!FmeTestAsociado->GetTestEdit(i, j))
              {
                ConjuntoAux = FmeEditsAsociados->GetVariablesEdits(j);	        
	        ConjuntoUnion.unite(ConjuntoAux);
              }
            }

          IndiceMapeado = VectorMapeadoImputacionRegistros[i];

          VectorVariablesAImputarEdits[IndiceMapeado] = ConjuntoUnion;
          VectorVariablesAImputarRango[IndiceMapeado] = ConjuntoRango;
          //EliminarVariablesBasicasNoImputables();
          VectorVariablesAImputarEditsAux[IndiceMapeado] = ConjuntoUnion;
          VectorVariablesAImputarRangoAux[IndiceMapeado] = ConjuntoRango;          
          model->setVariablesAImputar(VectorVariablesAImputarRangoAux[IndiceMapeado], i);
          model->setVariablesAImputar(VectorVariablesAImputarEditsAux[IndiceMapeado], i);          
          ConjuntoUnion.unite(ConjuntoRango);

          // Aumentar el conjunto con las componentes conexas
          Puntero2 = ConjuntoUnion.begin();
          ConjuntoCC.clear();
          ConjuntoCCL.clear();
          while (Puntero2 != ConjuntoUnion.end())
          {
            PunteroCC = ComponentesConexas[(*Puntero2)].begin();
            while (PunteroCC != ComponentesConexas[(*Puntero2)].end())
            {
              if ((*PunteroCC).distancia <= (unsigned)UMBRAL_CC)
                ConjuntoCC.insert((*PunteroCC).nodo);
              else
                ConjuntoCCL.insert((*PunteroCC).nodo);
              ++PunteroCC;
            }
            ++Puntero2;
          }

          VectorVariablesAImputarExtendido[IndiceMapeado] = ConjuntoCC;
          VectorVariablesAImputarExtendidoLargo[IndiceMapeado] = ConjuntoCCL;
          VectorVariablesAImputarExtendidoAux[IndiceMapeado] = ConjuntoCC;
          VectorVariablesAImputarExtendidoLargoAux[IndiceMapeado] = ConjuntoCCL;
          model->setVariablesAImputar(VectorVariablesAImputarExtendido[IndiceMapeado], i);
          model->setVariablesAImputar(VectorVariablesAImputarExtendidoLargo[IndiceMapeado], i);
        }
      }
    }
    void TFmeImputacion::EliminarVariablesBasicasNoImputables()
    {
      unsigned i, IndiceMapeado;
      QSet<unsigned> VariablesAEliminar, VariablesAEliminarAumentado, VariablesBasicasError, VariablesNoImputables, VariablesExcluidasRangos, ConjuntoResta, temp;

      VariablesNoImputables = FmeVariablesAsociadas->GetVariablesNoImputables();
      VariablesExcluidasRangos = FmeRangosAsociados->GetVariablesExcluidas();

      VariablesAEliminar =  VariablesNoImputables;

      VariablesAEliminar.unite(VariablesExcluidasRangos);
      for (i = 0; i < NumRegistros; i++)
        if (!(RegistroDonante(i)) && !(RegistroExcluido(i)))
        {
          IndiceMapeado = VectorMapeadoImputacionRegistros[i];

          // BASICAS
          temp = VectorVariablesAImputarEdits[IndiceMapeado];          
          ConjuntoResta = temp;
          ConjuntoResta.subtract(VariablesAEliminar);
          VectorVariablesAImputarEdits[IndiceMapeado] = ConjuntoResta;
          
          temp = VectorVariablesAImputarRango[IndiceMapeado];          
          ConjuntoResta = temp;
          ConjuntoResta.subtract(VariablesAEliminar);
          VectorVariablesAImputarRango[IndiceMapeado] = ConjuntoResta;
        }
    }
    void TFmeImputacion::ObtenerInforRegIncorrecto(int registro)
    {      
      QString imp;
      QSet<unsigned> variablesEdits;
      QSet<unsigned>::const_iterator p;
      int IndiceMapeado = VectorMapeadoImputacionRegistros[registro];
      int numVariablesRI = VectorVariablesAImputarRango[IndiceMapeado].size();  //vbles de rango a imputar imputables
      int numVariablesEI = VectorVariablesAImputarEdits[IndiceMapeado].size();   //vbles de edits a imputar imputables
      int numVariablesRT = VectorVariablesAImputarRangoAux[IndiceMapeado].size(); //todas vbles de rango a imputar
      int numVariablesET = VectorVariablesAImputarEditsAux[IndiceMapeado].size();  //todas vbles de edits a imputar

      menu2->addAction(" * Rangos y/o filtros incorrectos");
      menu2->addSeparator();
      for (int i = 0; i < NumVariables; i++) {
        if (!FmeRangosAsociados->GetTest(registro, i)) {
          if (FmeVariablesAsociadas->EsVariableImputable(i)) imp = "True";
          else imp = "False";
          menu2->addAction(" Variable: " + FmeVariablesAsociadas->GetNombreVariable(i) + " = " + MatrizMicroDatosS[registro][i+1] + " imputable " + imp);
          if (!FmeRangosAsociados->GetTestRango(registro, i))
            menu2->addAction("   Rango " + FmeVariablesAsociadas->GetCadenaEditRango(i));
          if (!FmeRangosAsociados->GetTestFiltro(registro, i))
            menu2->addAction("   Filtro " + FmeVariablesAsociadas->GetCadenaEditFiltro(i));
        }
      }
      menu2->addSeparator();      
      menu2->addAction(" * Reglas incorrectas");
      menu2->addSeparator();      
      bool imputable = false;  // indica si un edit tiene todas sus variables no imputables
      bool imputable2 = true;
      int cont=0;
      for (int i = 0; i < NumEdits; i++) {
        if (!FmeTestAsociado->GetTestEdit(registro, i)) {
          menu2->addAction(" Regla ID" + QString::number(FmeEditsAsociados->GetIdEdit(i), 10) + " " + FmeEditsAsociados->GetEdit(i));
          variablesEdits = FmeEditsAsociados->GetVariablesEdits(i);
          if (imputable) imputable = false;
          p = variablesEdits.constBegin();
          while (p != variablesEdits.constEnd()) {
            if (FmeVariablesAsociadas->EsVariableImputable(*p)) {
              imp = "True";
              imputable = true;
            }
            else {
              imp = "False";
            }
            menu2->addAction("   " + FmeVariablesAsociadas->GetNombreVariable(*p) + " = " + MatrizMicroDatosS[registro][*p+1] + " imputable " + imp);
            ++p;
          }
          if ((!imputable) && (imputable2)) imputable2 = false;
          cont++;
        }
      }
      if (cont == 0) imputable2 = false;  // si no tiene ningun edit, que dependa solo de los rangos
      menu2->addSeparator();      
      if (ImpManualCorrecto[registro]) menu2->addAction(" ** Imputación manual errónea");
      else {
        if ((!ConjuntoRegistrosDonantes.empty()) && (ImputacionVar[registro])) {
          menu2->addAction(" ** Imputación errónea de variables numéricas");
          if (ImpManualIncorrecto[registro]) menu2->addAction(" ** Imputación manual errónea");
        }else if ((numVariablesRT != numVariablesRI) || ((numVariablesET != 0) && (!imputable2))) {
                menu2->addAction(" ** No tiene variables básicas a imputar imputables");
                if (ImpManualIncorrecto[registro]) menu2->addAction(" ** Imputación manual errónea");
              }else {
                 menu2->addAction(" ** No tiene un registro donante adecuado");
                 if (ImpManualIncorrecto[registro]) menu2->addAction(" ** Imputación manual errónea");
              }
     }
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Calcular la distancia de dos valores en dos registros distintos sobre una misma variable.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    double TFmeImputacion::CalcularDistanciaEnVariable(unsigned IndiceVariable, double x1, double x2)
    {
      double min, max, temp;

      if ((FmeVariablesAsociadas->GetTipoVariable(IndiceVariable) == T_CONTINUO) && (x1 >= 0) && (x2 >= 0))
      {
        min = FmeVariablesAsociadas->GetFrontRango(IndiceVariable);
        max = FmeVariablesAsociadas->GetBackRango(IndiceVariable);
        temp = (x1 - x2) / (max - min);
        temp = ((temp >= 0) ? temp : -temp);
      }
      else
      {
        if (x1 == x2)
          temp = 0;
        else
          temp = 1;
      }
      return temp;
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Crear la matriz de registros donantes.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void TFmeImputacion::CrearMatrizRegistrosDonantes()
    {
      QSet<unsigned>::iterator Puntero;
      unsigned i, j, k, RegistroEstudio;
      double PesoAlfa, PesoBeta1, PesoBeta2, PesoGamma, PesoVariable, inc, da, db1, db2, dg;
      TipoRegistroDonante *VectorRegistrosDonantesAux;

      InicSistemaProgreso(QApplication::translate("", "Creaci\303\263n de la matriz de registros donantes", 0, QApplication::UnicodeUTF8), NumRegistros - NumRegistrosExcluidos - NumRegistrosDonantes);

      // Inicializamos la nueva
      InicializarMatrizRegistrosDonantes();

      // Obtener los pesos para las distancias
      PesoAlfa = FrmOpciones->GetPesoAlfa();
      PesoBeta1 = FrmOpciones->GetPesoBeta1();
      PesoBeta2 = FrmOpciones->GetPesoBeta2();
      PesoGamma = FrmOpciones->GetPesoGamma();

      VectorRegistrosDonantesAux = new TipoRegistroDonante[NumRegistrosDonantes];

      // Obtener los registros donantes y sus distancias
      for (i = 0; i < NumRegistros; i++)
        if ((!RegistroDonante(i)) && (!RegistroExcluido(i)))
        {
          // Obtenemos las distancias de los registros donantes al registro a imputar
          k = 0;
          Puntero = ConjuntoRegistrosDonantes.begin();
          while (Puntero != ConjuntoRegistrosDonantes.end())
          {
            RegistroEstudio = (*Puntero);
            da = 0;
            db1 = 0;
            db2 = 0;
            dg = 0;
            for (j = 0; j < NumVariables; j++)
            {
              PesoVariable = FmeVariablesAsociadas->GetPesoImputacion(j);
              inc = PesoVariable * CalcularDistanciaEnVariable(j, MatrizMicroDatos[i][j], MatrizMicroDatos[RegistroEstudio][j]);
              switch(MatrizTiposVariablesAImputar[i][j])
              {
              case T_BASICA:
                da += inc;
		break;
              case T_EXTENDIDA:
                db1 += inc;
                break;
              case T_EXTENDIDA_LARGA:
                db2 += inc;
                break;
              case T_CORRECTA:
                dg += inc;
                break;
              default:
                break;
              }
            }

            VectorRegistrosDonantesAux[k].IndiceRegistro = RegistroEstudio;
            VectorRegistrosDonantesAux[k].DistanciaAlfa = da;
            VectorRegistrosDonantesAux[k].DistanciaBeta1 = db1;
            VectorRegistrosDonantesAux[k].DistanciaBeta2 = db2;
            VectorRegistrosDonantesAux[k].DistanciaGamma = dg;
            if (FrmOpciones->GetMetodo1())
                VectorRegistrosDonantesAux[k].Distancia = (PesoAlfa * da) + (PesoBeta1 * db1) + (PesoBeta2 * db2) + (PesoGamma * dg);
            else
                VectorRegistrosDonantesAux[k].Distancia = (PesoAlfa * da) * (PesoBeta1 * db1) * (PesoBeta2 * db2) * (PesoGamma * dg);
            ++k;
            ++Puntero;
          }
          qsort((void*)VectorRegistrosDonantesAux, NumRegistrosDonantes, sizeof(TipoRegistroDonante), OrdenacionMatrizRegistrosDonantes);

          for (j = 0; j < NRD; j++)
            MatrizRegistrosDonantes[i][j] = VectorRegistrosDonantesAux[j];

          IncSistemaProgreso();
        }

      delete VectorRegistrosDonantesAux;
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Crear el conjunto de registros excluidos.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void TFmeImputacion::CrearConjuntoRegistrosExcluidos()
    {
      unsigned i;

      NumRegistrosExcluidos = 0;
      ConjuntoRegistrosExcluidos.clear();
      for (i = 0; i < NumRegistros; i++)
      {
        if (FmeRangosAsociados->RegistroExcluido(i) || FmeTestAsociado->RegistroExcluido(i))
        {
          ConjuntoRegistrosExcluidos.insert(i);
          NumRegistrosExcluidos++;
        }
      }
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Crear el grafo de dependencias de variables.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void TFmeImputacion::CrearGrafoVariables()
    {
      unsigned i, j;
      QSet<unsigned> ConjuntoUnion, ConjuntoAux;
      insert_iterator<QSet<unsigned> > Puntero(ConjuntoUnion, ConjuntoUnion.begin());

      GrafoVariables = new QSet<unsigned>[NumVariables];
      for (i = 0; i < NumVariables; i++)
      {
        ConjuntoUnion.clear();
        ConjuntoAux = FmeVariablesAsociadas->GetVariablesFiltros(i);        
        ConjuntoUnion.unite(ConjuntoAux);
        // Filtros
        for (j = 0; j < NumVariables; j++)
        {
          ConjuntoAux = FmeVariablesAsociadas->GetVariablesFiltros(j);
          if (ConjuntoAux.contains(i))
          {            
            ConjuntoAux.remove(i);
            ConjuntoAux.insert(j);            
            ConjuntoUnion.unite(ConjuntoAux);
          }
        }

        // Edits
        for (j = 0; j < NumEdits; j++)
        {
          ConjuntoAux = FmeEditsAsociados->GetVariablesEdits(j);
          if (ConjuntoAux.contains(i))
          {            
            ConjuntoAux.remove(i);            
            ConjuntoUnion.unite(ConjuntoAux);
          }
        }
        GrafoVariables[i] = ConjuntoUnion;
      }
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Crear las componentes conexas del grafo de variables.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void TFmeImputacion::CrearComponentesConexas()
    {
      unsigned i, j;
      bool *VariablesVisitadas;

      VariablesVisitadas = new bool[NumVariables];
      ComponentesConexas = new QList<TipoNodoCC>[NumVariables];
      for (i = 0; i < NumVariables; i++)
      {
        for (j = 0; j < NumVariables; j++)
          VariablesVisitadas[j] = false;
        ComponentesConexas[i].clear();
        BuscarComponenteConexaDFS(i, VariablesVisitadas, ComponentesConexas[i]);
      }
      delete VariablesVisitadas;
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Crear el vector de pesos de variables.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void TFmeImputacion::CrearVectorPesosVariables()
    {
      unsigned j, MaxEditsVariable;

      VectorPesosVariables = new TipoPesoVariable[NumVariables];

      // Buscar el maximo numero de edits a los que pertenecen las variables
      MaxEditsVariable = 0;
      for (j = 0; j < NumVariables; j++)
        if ((FmeVariablesAsociadas->GetNumFiltrosVariable(j) + FmeEditsAsociados->GetNumEditsVariable(j)) > MaxEditsVariable)
          MaxEditsVariable = FmeVariablesAsociadas->GetNumFiltrosVariable(j) + FmeEditsAsociados->GetNumEditsVariable(j);

      if (FrmOpciones->GetMetodoPesosVariables() == MPV_ALEATORIO)
      {        
        srand ( time(NULL) );
        for (j = 0; j < NumVariables; j++)
        {
          VectorPesosVariables[j].IndiceVariable = j;
          VectorPesosVariables[j].Peso = ((double)rand() / (double)RAND_MAX);
        }
      }
      else
        for (j = 0; j < NumVariables; j++)
        {
          VectorPesosVariables[j].IndiceVariable = j;
          VectorPesosVariables[j].Peso = (0.5 * ((double)(FmeVariablesAsociadas->GetNumFiltrosVariable(j) + FmeEditsAsociados->GetNumEditsVariable(j)) / (double)MaxEditsVariable))
                                     + (0.5 * ((double)FmeVariablesAsociadas->GetPesoImputacion(j)));
        }

      // Ordenar el vector de pesos variables
      //qsort((void *)VectorPesosVariables, NumVariables, sizeof(TipoPesoVariable), OrdenacionPesosVariablesDescendente);

      //sort ((void *)VectorPesosVariables, NumVariables, sizeof(TipoPesoVariable), &OrdenacionPesosVariablesDescendente);
      ordenar();
    }
    void TFmeImputacion::ordenar()
    {
      unsigned iv, i, j;
      double p;

      /*for (i=0; i < NumVariables; i++)
        for (j=0; j < NumVariables; j++)
          if (VectorPesosVariables[j].Peso < VectorPesosVariables[j+1].Peso) {
            iv = VectorPesosVariables[j+1].IndiceVariable;
            p = VectorPesosVariables[j+1].Peso;
            VectorPesosVariables[j+1].IndiceVariable = VectorPesosVariables[j].IndiceVariable;
            VectorPesosVariables[j+1].Peso = VectorPesosVariables[j].Peso;
            VectorPesosVariables[j].IndiceVariable = iv;
            VectorPesosVariables[j].Peso = p;
          }*/
      int pasada=0;
      int necesario;
      do {
          necesario=0;
          for (j=0; (j<(NumVariables)); j++) {
              if (VectorPesosVariables[j].Peso < VectorPesosVariables[j+1].Peso) {
                iv = VectorPesosVariables[j+1].IndiceVariable;
                p = VectorPesosVariables[j+1].Peso;
                VectorPesosVariables[j+1].IndiceVariable = VectorPesosVariables[j].IndiceVariable;
                VectorPesosVariables[j+1].Peso = VectorPesosVariables[j].Peso;
                VectorPesosVariables[j].IndiceVariable = iv;
                VectorPesosVariables[j].Peso = p;
                necesario = 1;
              }
          }
          //pasada++;
      } while (necesario);
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Crear la matriz de tipos de variables a imputar.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void TFmeImputacion::CrearMatrizTiposVariablesAImputar()
    {
      unsigned i, j, IndiceMapeado;

      MatrizTiposVariablesAImputar = new TTipoVariableAImputar*[NumRegistros];
      for (i = 0; i < NumRegistros; i++)
        if ((!RegistroDonante(i)) && (!RegistroExcluido(i)))
        {
          IndiceMapeado = VectorMapeadoImputacionRegistros[i];
          MatrizTiposVariablesAImputar[i] = new TTipoVariableAImputar[NumVariables];
          for (j = 0; j < NumVariables; j++)
          {
            if ((VectorVariablesAImputarRango[IndiceMapeado].contains(j)) || (VectorVariablesAImputarEdits[IndiceMapeado].contains(j)))
              MatrizTiposVariablesAImputar[i][j] = T_BASICA;
            else
              if (VectorVariablesAImputarExtendido[IndiceMapeado].contains(j))
                MatrizTiposVariablesAImputar[i][j] = T_EXTENDIDA;
              else
                if (VectorVariablesAImputarExtendidoLargo[IndiceMapeado].contains(j))
                  MatrizTiposVariablesAImputar[i][j] = T_EXTENDIDA_LARGA;
                else
                  MatrizTiposVariablesAImputar[i][j] = T_CORRECTA;
          }
        }
        else
          MatrizTiposVariablesAImputar[i] = NULL;
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Actualizar el registro.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void TFmeImputacion::CommitRegistro(unsigned IndiceRegistro, double *Registro)
    {
      unsigned j;      

      for (j = 0; j < NumVariables; j++)
      {
        if (MatrizMicroDatos[IndiceRegistro][j] != Registro[j])
        {
          NumRegistrosImputados[j]++;
          MatrizMicroDatos[IndiceRegistro][j] = Registro[j];          
          MatrizMicroDatosS[IndiceRegistro][j+1] = QString::number(Registro[j], 'f', 1).replace('.', ',');          
          MatrizImputacion[IndiceRegistro][j] = true;
        }
      }
      model->setMatrizImputacion(MatrizImputacion);
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Copiar dos registros.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void TFmeImputacion::CopiarRegistros(double *RegistroOrigen, double *RegistroDestino)
    {
      unsigned j;

      for (j = 0; j < NumVariables; j++)
        RegistroDestino[j] = RegistroOrigen[j];
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Eliminar de los conjuntos a imputar las variables no imputables y las variables excluidas.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void TFmeImputacion::EliminarVariablesNoImputables()
    {
      unsigned i, IndiceMapeado;
      QSet<unsigned> VariablesAEliminar, VariablesAEliminarAumentado, VariablesBasicasError, VariablesNoImputables, VariablesExcluidasRangos, ConjuntoResta, temp;

      VariablesNoImputables = FmeVariablesAsociadas->GetVariablesNoImputables();
      VariablesExcluidasRangos = FmeRangosAsociados->GetVariablesExcluidas();

      VariablesAEliminar =  VariablesNoImputables;

      VariablesAEliminar.unite(VariablesExcluidasRangos);
      for (i = 0; i < NumRegistros; i++)
        if (!(RegistroDonante(i)) && !(RegistroExcluido(i)))
        {
          IndiceMapeado = VectorMapeadoImputacionRegistros[i];

          // BASICAS
          temp = VectorVariablesAImputarEdits[IndiceMapeado];          
          ConjuntoResta = temp;
          ConjuntoResta.subtract(VariablesAEliminar);
          VectorVariablesAImputarEdits[IndiceMapeado] = ConjuntoResta;
          
          temp = VectorVariablesAImputarRango[IndiceMapeado];          
          ConjuntoResta = temp;
          ConjuntoResta.subtract(VariablesAEliminar);
          VectorVariablesAImputarRango[IndiceMapeado] = ConjuntoResta;
          
          VariablesBasicasError = VectorVariablesAImputarEdits[IndiceMapeado];
          VariablesBasicasError.unite(VectorVariablesAImputarRango[IndiceMapeado]);

          VariablesAEliminarAumentado = VariablesAEliminar;
          VariablesAEliminarAumentado.unite(VariablesBasicasError);

          // EXTENDIDAS
          temp = VectorVariablesAImputarExtendido[IndiceMapeado];
          ConjuntoResta = temp;
          ConjuntoResta.subtract(VariablesAEliminarAumentado);
          VectorVariablesAImputarExtendido[IndiceMapeado] = ConjuntoResta;

          temp = VectorVariablesAImputarExtendidoLargo[IndiceMapeado];
          ConjuntoResta = temp;
          ConjuntoResta.subtract(VariablesAEliminarAumentado);
          VectorVariablesAImputarExtendidoLargo[IndiceMapeado] = ConjuntoResta;
        }
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Obtener el numero de variables en las que se diferencia el registro test de los valores originales.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    unsigned TFmeImputacion::GetNumVariablesDistintas(unsigned IndiceRegistro, double *Registro)
    {
      unsigned j, NumVariablesDistintas;

      NumVariablesDistintas = 0;
      for (j = 0; j < NumVariables; j++)
      {
        if (MatrizMicroDatos[IndiceRegistro][j] != Registro[j])
          NumVariablesDistintas++;
      }
      return NumVariablesDistintas;
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Deshabilitar la informacion que describe al registro donante.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void TFmeImputacion::DeshabilitarInformacionRegistroDonante()
    {
      unsigned j;

      UpdRegistroDonante_sig->setEnabled(false);
      UpdRegistroDonante_ant->setEnabled(false);
      ButCambiarRegistroDonante->setEnabled(false);
      EdtMensajeRegistroDonante->setVisible(false);
      EdtDistancia->setText(0);
      EdtNumVariablesAImputar->setText(0);
      EdtNumVariablesAImputarBasico->setText(0);
      EdtNumVariablesImputadas->setText(0);
      for (j = 0; j < (unsigned)NumVariables; j++)
        VectorDatosR[j] = "---";        
      listaV3[0] = "";
      model3->setCabeceraV(listaV3);
      model3->setHeaderData(0, Qt::Vertical, QVariant(), Qt::DisplayRole);
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Escribir mensaje de informacion en la barra de estado.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void TFmeImputacion::EscribirInformacion()
    {
      LabBarraEstado1->setText(QString::number(model->rowCount(view->currentIndex()), 10) + " " + tr("Registros") + ", " + QString::number(NumVariables, 10) + " " + (QString)STR0053);
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Indica si un registro es donante o no.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    bool TFmeImputacion::EvaluarRegistroConPatron(bool *Patron, unsigned *VectorIndices, double *RegistroTest, double *RegistroDonante, unsigned NumVariablesEnImputacion, unsigned IndiceRegistro, QSet<unsigned> VariablesModificadas)
    {
      unsigned j, IndiceVariable;
      bool ResultadoRangos, ResultadoTest, RegistroCorrecto;
      QMap<QString,double> *MapTest;

      for (j = 0; j < NumVariablesEnImputacion; j++)
        if (Patron[j])
        {
          IndiceVariable = VectorIndices[j];
          if (RegistroTest[IndiceVariable] != RegistroDonante[IndiceVariable])
          {
            VariablesModificadas.insert(IndiceVariable);
            RegistroTest[IndiceVariable] = RegistroDonante[IndiceVariable];
          }
        }
      MapTest = GetMapDesdeVector(RegistroTest);
      ResultadoRangos = FmeRangosAsociados->EvaluarFiltros(IndiceRegistro, VariablesModificadas, MapTest);
      ResultadoTest = ResultadoRangos && FmeTestAsociado->EvaluarRegistro(IndiceRegistro, VariablesModificadas, MapTest);
      RegistroCorrecto = ResultadoTest;
      delete MapTest;
      return RegistroCorrecto;
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Evaluar el registro despues de haber hecho una modificacion manual.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void TFmeImputacion::EvaluarRegistroModificado(unsigned IndiceRegistro, unsigned IndiceVariable, double ValorNuevo)
    {
      bool ResultadoRango, ResultadoFiltros, ResultadoTest;
      QSet<unsigned> VariablesModificadas;
      double *RegistroTest;
      unsigned j;
      QMap<QString,double> *MapTest;

      // Crear el conjunto de variables modificadas
      VariablesModificadas.clear();
      VariablesModificadas.insert(IndiceVariable);

      // Crear el registro test
      RegistroTest = new double[NumVariables];
      for (j = 0; j < NumVariables; j++)
        RegistroTest[j] = GetValor(IndiceRegistro, j);

      // Incorporamos el valor
      RegistroTest[IndiceVariable] = ValorNuevo;

      // Evaluamos el registro
      MapTest = GetMapDesdeVector(RegistroTest);
      ResultadoRango = FmeVariablesAsociadas->ValorEnRango(ValorNuevo, IndiceVariable);
      ResultadoFiltros = ResultadoRango && FmeRangosAsociados->EvaluarFiltros(IndiceRegistro, VariablesModificadas, MapTest);
      ResultadoTest = ResultadoFiltros && FmeTestAsociado->EvaluarRegistro(IndiceRegistro, VariablesModificadas, MapTest);
      if (ResultadoTest){        
        ConjuntoRegistrosIncorrectos.remove(IndiceRegistro);
      }else {        
        if ((ConjuntoRegistrosIncorrectos.contains(IndiceRegistro)) && (!ImpManualCorrecto[IndiceRegistro]))
          ImpManualIncorrecto[IndiceRegistro] = true;
        else {
          ConjuntoRegistrosIncorrectos.insert(IndiceRegistro);
          ImpManualCorrecto[IndiceRegistro] = true;
        }
      }
      delete MapTest;

      CommitRegistro(IndiceRegistro, RegistroTest);      
      repintar();
      delete RegistroTest;
      NumRegistrosIncorrectos = ConjuntoRegistrosIncorrectos.size();
      NumRegistrosCorrectos = NumRegistros - NumRegistrosIncorrectos - NumRegistrosDonantes - NumRegistrosExcluidos;
      NumRegistrosWarning = ConjuntoRegistrosWarning.size();
      NumRegistrosACorregir = NumRegistros - NumRegistrosDonantes - NumRegistrosExcluidos;

      // Calcular Estadisticas
      CalcularEstadisticas();
      MostrarInfoAsociada(view->currentIndex().row(), view->currentIndex().column(), true);      
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Fijar la cantidad de datos que intervienen en el proceso.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void TFmeImputacion::FijarCantidadDatos()
    {
      NumEdits = FmeEditsAsociados->GetNumEdits();
      NumRegistros = FmeMicroDatosAsociados->GetNumRegistros();
      NumVariables = FmeVariablesAsociadas->GetNumVariables();
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Genera las combinaciones de n sobre m.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /*bool TFmeImputacion::GeneraNSobreM(bool *Patron, unsigned *VectorIndices, double *RegistroTest, double *RegistroDonante, double *RegistroBackup, unsigned IndiceRegistro, unsigned n, unsigned m, unsigned k, unsigned t, QSet<unsigned> VariablesModificadas)
    {
        numletras = n;
        combina = m;
        serie = 1;
        for(i=0; i<combina; i++)
            serie *= numLetras;
        for(i=0;i<serie;i++)
            Patron[i]=false;
        subSerie = serie/numLetras;
        for(i=0;i<combina;i++) {
            per=1 ; let=0;
            for(j=0;j<serie;j++) {
                permuta[j]+=letras[let];
                per+=1;
                if(per>subSerie) {
                    per=1; let+=1;
                    if(let>numLetras-1) let=0;
                }
            }
            subSerie /= numLetras;
        }
    }*/

    bool TFmeImputacion::GeneraNSobreM(bool *Patron, unsigned *VectorIndices, double *RegistroTest, double *RegistroDonante, double *RegistroBackup, unsigned IndiceRegistro, unsigned n, unsigned m, unsigned k, unsigned t, QSet<unsigned> VariablesModificadas)
    {
          bool salir = false;
          while ((k < n) && (!salir))
          {
              salir = prueba(Patron, VectorIndices, RegistroTest, RegistroDonante, RegistroBackup, IndiceRegistro, n, m, k, t, VariablesModificadas);
              inic_Patron(Patron, n);
              if ((m == 1) || (k+m >= n)) // si solo tenemos q modificar una variable lo hacemos una sola vez O si no podemos modificar m vbles a partir del indice k
                  k = n;
              else
                  k++;
          }
          return salir;
    }
    void TFmeImputacion::inic_Patron(bool *Patron, unsigned n)
    {
        for (int i = 0; i < n ; i++)
            Patron[i] = false;
    }
    void TFmeImputacion::inic_Patron(bool *Patron, unsigned n, unsigned inic)
    {
        for (int i = 0; i < n ; i++)
        {
            if (i == inic) Patron[i] = true;
            else Patron[i] = false;
        }
    }
    bool TFmeImputacion::prueba(bool *Patron, unsigned *VectorIndices, double *RegistroTest, double *RegistroDonante, double *RegistroBackup, unsigned IndiceRegistro, unsigned n, unsigned m, unsigned k, unsigned t, QSet<unsigned> VariablesModificadas)
    {
        int inic, cont;
        if ((m == 1) || (m == 2))
        {
            while (k < n)
            {
                Patron[k] = true;
                t++;
                if (t == m)
                {
                  if (EvaluarRegistroConPatron(Patron, VectorIndices, RegistroTest, RegistroDonante, n, IndiceRegistro, VariablesModificadas))
                  {
                      return true;
                  }else
                  {
                     RestaurarRegistro(RegistroTest, RegistroBackup);
                     Patron[k] = false;
                     t--;
                  }
                }
                k++;
            }            
            return false;
        }
        else
        {
            inic = k;
            cont = 1;
            inic_Patron(Patron, n, inic);            
            t=1;
            k++;
            while (k < n)
            {
                Patron[k] = true;
                t++;
                if (t == m)
                {
                  if (EvaluarRegistroConPatron(Patron, VectorIndices, RegistroTest, RegistroDonante, n, IndiceRegistro, VariablesModificadas))
                  {
                      return true;
                  }else
                  {
                     RestaurarRegistro(RegistroTest, RegistroBackup);
                     if (k + 1 == n)
                     {
                         inic_Patron(Patron, n, inic);
                         t=1;
                         k = inic+cont;
                         cont++;
                     }
                     else
                     {
                         Patron[k] = false;
                         t--;
                     }
                  }
                }
                k++;
            }
            return false;
        }
    }
   /* bool TFmeImputacion::GeneraNSobreM(bool *Patron, unsigned *VectorIndices, double *RegistroTest, double *RegistroDonante, double *RegistroBackup, unsigned IndiceRegistro, unsigned n, unsigned m, unsigned k, unsigned t, QSet<unsigned> VariablesModificadas)
    {
      if (t == m)
      {
        if (EvaluarRegistroConPatron(Patron, VectorIndices, RegistroTest, RegistroDonante, n, IndiceRegistro, VariablesModificadas))
          return true;
        else
        {
          RestaurarRegistro(RegistroTest, RegistroBackup);
          return false;
        }
      }
      else
        if (k < n)
        {
          Patron[k] = true;
          if (!GeneraNSobreM(Patron, VectorIndices, RegistroTest, RegistroDonante, RegistroBackup, IndiceRegistro, n, m, k+1, t+1, VariablesModificadas))
          {
            Patron[k] = false;
            return GeneraNSobreM(Patron, VectorIndices, RegistroTest, RegistroDonante, RegistroBackup, IndiceRegistro, n, m, k+1, t, VariablesModificadas);
          }
          else
            return true;
        }
        else
          return false;
    }*/
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Devolver la posicion que tiene una variable dentro del vector de aparicion en edit.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    unsigned TFmeImputacion::GetPosicionPorIndiceVariable(unsigned IndiceVariable)
    {
      unsigned j;

      for (j = 0; j < NumVariables; j++)
        if (VectorPesosVariables[j].IndiceVariable == IndiceVariable)
          return j;
      return 0;
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Devolver el map desde un vector.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    QMap<QString,double> *TFmeImputacion::GetMapDesdeVector(double *Valores)
    {
      unsigned i;
      QMap<QString,double> *MapResultado;
      QString Variable;
      double Valor;

      MapResultado = new QMap<QString,double>;
      for (i = 0; i < NumVariables; i++)
      {
        Variable = FmeVariablesAsociadas->GetNombreVariable(i);
        Valor = Valores[i];        
        MapResultado->insert(Variable, Valor);
      }
      return MapResultado;
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Habilitar la informacion que describe al registro donante.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void TFmeImputacion::HabilitarInformacionRegistroDonante()
    {
      UpdRegistroDonante_sig->setEnabled(true);
      UpdRegistroDonante_ant->setEnabled(true);
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Fijar el ancho de las columnas de la rejilla principal.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void TFmeImputacion::FijarAnchoColumnasRejilla(unsigned ancho)
    {
      unsigned j;

      for (j = 0; j < (unsigned)NumVariables; j++)
        view->setColumnWidth(j, ancho);
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Inicializar estructuras de imputacion.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void TFmeImputacion::InicializarEstructurasImputacion()
    {
      InicSistemaProgreso(QApplication::translate("", "Inicializaci\303\263n de estructuras de imputaci\303\263n (I) [espere por favor...]", 0, QApplication::UnicodeUTF8), 10);

      // Crear el vector de pesos de variables
      CrearVectorPesosVariables();
      IncSistemaProgreso(); 
      // Crear el conjunto de registros excluidos
      CrearConjuntoRegistrosExcluidos();
      IncSistemaProgreso();
      // Copiar la rejilla desde los microdatos originales
      CopiarRejillaMicroDatos2();
      IncSistemaProgreso();
      // Copiar la matriz de microdatos desde los originales
      CopiarMatrizMicroDatos();
      IncSistemaProgreso();
      // Inicializar la matriz de tipo de imputacion
      InicializarMatrizImputacion();
      IncSistemaProgreso();
      // Crear el conjunto de registros donantes
      CrearRegistrosDonantes();
      IncSistemaProgreso();
      // Inicializar las variables a imputar
      InicializarVariablesAImputar();
      IncSistemaProgreso();
      // Crear las variables a imputar
      CrearVariablesAImputar();
      IncSistemaProgreso();
      // Crear la matriz de tipos de variables a imputar
      CrearMatrizTiposVariablesAImputar();
      IncSistemaProgreso();
      // Crear la matriz de registros donantes
      CrearMatrizRegistrosDonantes();

      IncSistemaProgreso();
      InicSistemaProgreso(QApplication::translate("", "Inicializaci\303\263n de estructuras de imputaci\303\263n (II) [espere por favor...]", 0, QApplication::UnicodeUTF8), 5);

      // Eliminar las variables no imputables
      EliminarVariablesNoImputables();
      IncSistemaProgreso();
      // Inicializar el vector de numero de variables imputadas
      InicializarNumVariablesImputadas();
      IncSistemaProgreso();
      // Inicializar el vector de numero de registros imputados
      InicializarNumRegistrosImputados();
      IncSistemaProgreso();
      // Crear el conjunto de registros correctos y registros warning
      InicializarConjuntoRegistrosIncorrectos();
      IncSistemaProgreso();
      InicializarConjuntoRegistrosWarning();
      IncSistemaProgreso();

      posicion = 0;

      NumRegistrosCorrectos = 0;
      NumRegistrosWarning = 0;
      NumVariablesImputadasTotal = 0;
      NumVariablesImputadasWarning = 0;
      SumDistancias = 0;
      NumErroresRango = 0;
      NumErroresEdits = 0;
      NumErroresTotal = 0;
      SizeCompConexas = 0;

    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Imputar los microdatos asociados mediante la tecnica de registro donante.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void TFmeImputacion::ImputarMicroDatosRegistroDonante()
    {
      unsigned i, j, IndiceMapeado, NumVariablesImputadasActual, MinNumVariablesImputadas, IndiceRegistroDonanteMin;
      int IndiceRegistroDonante;
      double *RegistroTest;
      double *RegistroTestMin;
      TTipoImputacionRegistro TipoImputacionRegistro, TipoImputacionRegistroMin;
      QSet<unsigned> ConjuntoUnion;
      insert_iterator<QSet<unsigned> > Puntero(ConjuntoUnion, ConjuntoUnion.begin());

      double MaximaDistancia = FrmOpciones->GetMaxDistDonante();

      InstanteComienzo = QTime::currentTime();

      InicializarEstructurasImputacion();

      InicSistemaProgreso(QApplication::translate("", "Imputaci\303\263n de microdatos", 0, QApplication::UnicodeUTF8), NumRegistros - NumRegistrosExcluidos - NumRegistrosDonantes);

      RegistroTest = new double[NumVariables];
      RegistroTestMin = new double[NumVariables];

      if (ConjuntoRegistrosDonantes.empty()) {
        DeshabilitarInformacionRegistroDonante();
        for (i = 0; i < NumRegistros; i++)
        {
          MatrizRegistrosDonantes[i][NRD].IndiceRegistro = -1;
          ConjuntoRegistrosIncorrectos.insert(i);
            IncSistemaProgreso();
        }

      }else
      {
        // Recorremos cada registro
        ImputacionVar = new bool[NumRegistros];
        for (i = 0; i < NumRegistros; i++)
        {
          ImputacionVar[i] = false;
          //if (i == 1905) {
          if ((!RegistroDonante(i)) && (!RegistroExcluido(i)))
          {
            if (MatrizRegistrosDonantes[i][0].Distancia > MaximaDistancia)
              TipoImputacionRegistroMin = T_NO_CORREGIDO;
            else
            {
              IndiceMapeado = VectorMapeadoImputacionRegistros[i];

              MinNumVariablesImputadas = NumVariables;
              TipoImputacionRegistro = T_NO_CORREGIDO;
              TipoImputacionRegistroMin = T_NO_CORREGIDO;

              for (j = 0; ((j < NRD) && (TipoImputacionRegistro != T_CORREGIDO_NO_WARNING)); j++)
              {
                IndiceRegistroDonante = MatrizRegistrosDonantes[i][j].IndiceRegistro;

                TipoImputacionRegistro = BuscarDonacionCorrecta(i, IndiceRegistroDonante, VectorVariablesAImputarRango[IndiceMapeado], VectorVariablesAImputarEdits[IndiceMapeado], VectorVariablesAImputarExtendido[IndiceMapeado], VectorVariablesAImputarExtendidoLargo[IndiceMapeado], RegistroTest, &NumVariablesImputadasActual);

                switch(TipoImputacionRegistro)
                {
                case T_NO_CORREGIDO:
                  break;
                case T_CORREGIDO_NO_WARNING:
                  TipoImputacionRegistroMin = T_CORREGIDO_NO_WARNING;
                  MinNumVariablesImputadas = NumVariablesImputadasActual;
                  IndiceRegistroDonanteMin = j;
                  CopiarRegistros(RegistroTest, RegistroTestMin);
                  break;
                case T_CORREGIDO_WARNING:
                  TipoImputacionRegistroMin = T_CORREGIDO_WARNING;
                  if (NumVariablesImputadasActual < MinNumVariablesImputadas)
                  {
                    MinNumVariablesImputadas = NumVariablesImputadasActual;
                    IndiceRegistroDonanteMin = j;
                    CopiarRegistros(RegistroTest, RegistroTestMin);
                  }
                  break;
                default:
                  break;
                }
              }
            }

            if (TipoImputacionRegistroMin != T_NO_CORREGIDO)
            {              
              MatrizRegistrosDonantes[i][NRD].IndiceRegistro = IndiceRegistroDonanteMin;
              NumVariablesImputadas[IndiceMapeado] = MinNumVariablesImputadas;
              CommitRegistro(i, RegistroTestMin);

              if (TipoImputacionRegistroMin == T_CORREGIDO_WARNING)
              {
                NumVariablesImputadasWarning += MinNumVariablesImputadas;
                ConjuntoRegistrosWarning.insert(i);                
              }

              // Calculo de estadisticas
              NumVariablesImputadasTotal += MinNumVariablesImputadas;
              SumDistancias += MatrizRegistrosDonantes[i][IndiceRegistroDonanteMin].Distancia;
              NumErroresRango += VectorVariablesAImputarRango[IndiceMapeado].size();
              NumErroresEdits += VectorVariablesAImputarEdits[IndiceMapeado].size();
              ConjuntoUnion = VectorVariablesAImputarRango[IndiceMapeado];
              ConjuntoUnion.unite(VectorVariablesAImputarEdits[IndiceMapeado]);
              NumErroresTotal += ConjuntoUnion.size();
              ConjuntoUnion = VectorVariablesAImputarExtendido[IndiceMapeado];
              ConjuntoUnion.unite(VectorVariablesAImputarExtendidoLargo[IndiceMapeado]);
              SizeCompConexas += ConjuntoUnion.size();
            }
            else
            {
              MatrizRegistrosDonantes[i][NRD].IndiceRegistro = -1;
              ConjuntoRegistrosIncorrectos.insert(i);
            }

            IncSistemaProgreso();
          }
          //}
        }
      }      
      view->hideColumn(0);

      SustituirImputacionVariablesNumericas();

      delete RegistroTest;
      delete RegistroTestMin;

      NumRegistrosIncorrectos = ConjuntoRegistrosIncorrectos.size();
      NumRegistrosCorrectos = NumRegistros - NumRegistrosIncorrectos - NumRegistrosDonantes - NumRegistrosExcluidos;
      NumRegistrosWarning = ConjuntoRegistrosWarning.size();
      NumRegistrosACorregir = NumRegistros - NumRegistrosDonantes - NumRegistrosExcluidos;

      // Calcular Estadisticas
      CalcularEstadisticas();

      MostrarInfoAsociada(0, 1, true);

      Cargado = true;

      PanProgreso->hide();
      repintar();
      PanContenedor->show();

      InstanteFinalizacion = QTime::currentTime();
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Imputar los microdatos asociados mediante la tecnica de ecuacion de regresion lineal multiple (ERLM).
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void TFmeImputacion::ImputarMicroDatosERLM()
    {
    InstanteComienzo = QTime::currentTime();
    InstanteFinalizacion = QTime::currentTime();
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Imputar el conjunto de variables sobre el registro test.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void TFmeImputacion::ImputarVariablesTest(QSet<unsigned> VariablesAImputar, double *RegistroTest, double *RegistroBackup, double *RegistroDonante, QSet<unsigned> *VariablesModificadas)
    {
      QSet<unsigned>::iterator Puntero;
      unsigned IndiceVariable;

      Puntero = VariablesAImputar.begin();
      while (Puntero != VariablesAImputar.end())
      {
        IndiceVariable = (*Puntero);
        if (RegistroTest[IndiceVariable] != RegistroDonante[IndiceVariable])
        {
          VariablesModificadas->insert(IndiceVariable);
          RegistroTest[IndiceVariable] = RegistroDonante[IndiceVariable];
          RegistroBackup[IndiceVariable] = RegistroDonante[IndiceVariable];
        }
        ++Puntero;
      }
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Inicializar la matriz de tipo de imputacion.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void TFmeImputacion::InicializarMatrizImputacion()
    {
      unsigned i, j;

      ImpManualIncorrecto = new bool[NumRegistros];
      ImpManualCorrecto = new bool[NumRegistros];
      for (i = 0; i < NumRegistros; i++){
        ImpManualIncorrecto[i] = false;  // ninguna imputacion manual por ahora
        ImpManualCorrecto[i] = false;  // ninguna imputacion manual por ahora
        for (j = 0; j < NumVariables; j++)
          MatrizImputacion[i][j] = false;
      }
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Inicializar los vectores de las variables a imputar.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void TFmeImputacion::InicializarVariablesAImputar()
    {
      unsigned i, j;

      NumRegistrosAImputar = NumRegistros - NumRegistrosDonantes - NumRegistrosExcluidos;

      VectorVariablesAImputarExtendidoLargo = new QSet<unsigned>[NumRegistrosAImputar];
      VectorVariablesAImputarExtendido = new QSet<unsigned>[NumRegistrosAImputar];
      VectorVariablesAImputarEdits = new QSet<unsigned>[NumRegistrosAImputar];
      VectorVariablesAImputarRango = new QSet<unsigned>[NumRegistrosAImputar];
      VectorVariablesAImputarExtendidoLargoAux = new QSet<unsigned>[NumRegistrosAImputar];
      VectorVariablesAImputarExtendidoAux = new QSet<unsigned>[NumRegistrosAImputar];
      VectorVariablesAImputarEditsAux = new QSet<unsigned>[NumRegistrosAImputar];
      VectorVariablesAImputarRangoAux = new QSet<unsigned>[NumRegistrosAImputar];

      VectorMapeadoImputacionRegistros = new unsigned[NumRegistros];

      for (i = 0, j = 0; i < NumRegistros; i++)
      {
        if ((RegistroDonante(i)) || (RegistroExcluido(i)))
          VectorMapeadoImputacionRegistros[i] = 0;
        else
        {
          VectorMapeadoImputacionRegistros[i] = j;

          VectorVariablesAImputarExtendidoLargo[j].clear();
          VectorVariablesAImputarExtendido[j].clear();
          VectorVariablesAImputarEdits[j].clear();
          VectorVariablesAImputarRango[j].clear();
          VectorVariablesAImputarExtendidoLargoAux[j].clear();
          VectorVariablesAImputarExtendidoAux[j].clear();
          VectorVariablesAImputarEditsAux[j].clear();
          VectorVariablesAImputarRangoAux[j].clear();

          j++;
        }
      }
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Inicializar el vector de numero de variables imputadas.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void TFmeImputacion::InicializarNumVariablesImputadas()
    {
      unsigned i;

      NumVariablesImputadas = new unsigned[NumRegistrosAImputar];

      for (i = 0; i < NumRegistrosAImputar; i++)
        NumVariablesImputadas[i] = 0;
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Inicializar el vector de numero de registros imputados.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void TFmeImputacion::InicializarNumRegistrosImputados()
    {
      unsigned j;

      NumRegistrosImputados = new unsigned[NumVariables];

      for (j = 0; j < NumVariables; j++)
        NumRegistrosImputados[j] = 0;
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Inicializar la matriz de registros donantes.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void TFmeImputacion::InicializarMatrizRegistrosDonantes()
    {
      unsigned i;

      MatrizRegistrosDonantes = new TipoRegistroDonante*[NumRegistros];
      for (i = 0; i < NumRegistros; i++)
        if ((RegistroDonante(i)) || (RegistroExcluido(i)))
          MatrizRegistrosDonantes[i] = NULL;
        else
          MatrizRegistrosDonantes[i] = new TipoRegistroDonante[NRD + 1];
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Inicializar el sistema de progreso.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void TFmeImputacion::InicSistemaProgreso(QString Operacion, unsigned NumElementos)
    {

      EdtOperacion->setText(Operacion);
      PbrProgreso->setRange(0, NumElementos);
      PbrProgreso->setValue(0);
      EdtPorcentaje->setText("0%");
      EdtElemento->setText("(" + QString::number(PbrProgreso->value(), 10) + "/" + QString::number(PbrProgreso->maximum(), 10) + ")");
      QApplication::processEvents();
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Incrementar el sistema de progreso.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void TFmeImputacion::IncSistemaProgreso()
    {

      PbrProgreso->setValue(PbrProgreso->value()+1);
      EdtElemento->setText("(" + QString::number(PbrProgreso->value(), 10) + "/" + QString::number(PbrProgreso->maximum(), 10) + ")");
      EdtPorcentaje->setText(QString::number(((double)PbrProgreso->value() / (double)PbrProgreso->maximum()) * 100, 'f', 2).replace('.', ',') + "%");
      QApplication::processEvents();
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Mostrar la informacion asociada a la fila y a la columna.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void TFmeImputacion::MostrarInfoAsociada(unsigned Fila, unsigned Columna, bool Fijar)
    {
      if (model->rowCount(view->currentIndex()) > 0) {
        unsigned Fila2 = Fila;
        Fila = listaV.indexOf(model->headerData(Fila, Qt::Vertical, Qt::DisplayRole).toString());
        QPalette palette2( QApplication::palette() );
        if (Columna == 0) {
          palette2.setColor(QPalette::Base, Qt::gray );
          EdtMicroDatoOriginal->setPalette(palette2);
          view3->setCurrentIndex(view3->indexAt(QPoint(view3->columnViewportPosition(Columna), view3->rowViewportPosition(0))));
          for (int j = 0; j < FmeVariablesAsociadas->GetNumAtributos(); j++)  {
            VectorDatosV[j] = "---";
            if (j < 8) view2->setColumnWidth ( j, ANCHOS_VARIABLE[j]);
            else
               if (j < 8 + FmeVariablesAsociadas->GetNum_valores_missing()) view2->setColumnWidth ( j, 100);
               else view2->setColumnWidth ( j, ANCHOS_VARIABLE[j - FmeVariablesAsociadas->GetNum_valores_missing()]);
          }
          listaV2[0] = "";
          model2->setCabeceraV(listaV2);
          model2->setHeaderData(0, Qt::Vertical, QVariant(), Qt::DisplayRole);
          DeshabilitarInformacionRegistroDonante();
          EdtMicroDatoOriginal->setText("-");
          LabBarraEstado2->setText(tr("Registro") + " 0/" + QString::number(model->rowCount(view->currentIndex()), 10) + "   [" + (QString)STR0049 + " = 0]");
        }else {
          view3->setCurrentIndex(view3->indexAt(QPoint(view3->columnViewportPosition(Columna-1), view3->rowViewportPosition(0))));
          for (int j = 0; j < FmeVariablesAsociadas->GetNumAtributos(); j++)  {
            VectorDatosV[j] = FmeVariablesAsociadas->getMatrizVariablesS(Columna-1, j);
            if (j < 8) view2->setColumnWidth ( j, ANCHOS_VARIABLE[j]);
            else
               if (j < 8 + FmeVariablesAsociadas->GetNum_valores_missing()) view2->setColumnWidth ( j, 100);
               else view2->setColumnWidth ( j, ANCHOS_VARIABLE[j - FmeVariablesAsociadas->GetNum_valores_missing()]);
          }
          listaV2[0] = FmeVariablesAsociadas->getlistaV(Columna-1);
          model2->setCabeceraV(listaV2);
          model2->setHeaderData(0, Qt::Vertical, QVariant(), Qt::DisplayRole);
          if (!ConjuntoRegistrosDonantes.empty())
          {
            if (RegistroDonante(Fila) || RegistroExcluido(Fila))
              DeshabilitarInformacionRegistroDonante();
            else
            {
              HabilitarInformacionRegistroDonante();
              posicion = MatrizRegistrosDonantes[Fila][NRD].IndiceRegistro;
              if (posicion == -1) posicion = 0;
              ActualizarInformacionRegistroDonante(Fila, posicion);
            }
          }
          EdtMicroDatoOriginal->setText(FmeMicroDatosAsociados->GetValorS(Fila, Columna-1));
          LabBarraEstado2->setText(tr("Registro") + " " + QString::number(Fila2+1, 10) + "/" + QString::number(model->rowCount(view->currentIndex()), 10) + "   [" + (QString)STR0049 + " = " + QString::number(Columna, 10) + "]");

          if (Fijar) {
            view->setCurrentIndex(view->indexAt(QPoint(view->columnViewportPosition(Columna), view->rowViewportPosition(Fila2))));
            //QColor rojo = model->data(view->currentIndex(), Qt::BackgroundRole).value<QColor>(); //view->currentIndex().model()->data(view->currentIndex(), Qt::BackgroundRole).value<QColor>();
            //QString color = rojo.name();
            //setStyleSheet("selection-background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 " + color + ", stop: 1 gray);");
            view->focusPolicy();
          }
          if (MatrizImputacion[Fila][Columna-1]) {
            palette2.setColor(QPalette::Base, CL_IMPUTACION );
            EdtMicroDatoOriginal->setPalette(palette2);
          }else {
            palette2.setColor(QPalette::Base, Qt::gray );
            EdtMicroDatoOriginal->setPalette(palette2);
          }
        }

        view3->clearSelection();
        // Forzamos a repintar las rejillas de registro y Variable
        repintarRegistroDonante(Columna-1);        
        view3->clearSelection();

      }
    }
    void TFmeImputacion::MostrarInfoAsociada(unsigned Fila, unsigned Columna, unsigned numreg, bool Fijar)
    {
      if (numreg > 0) {
        unsigned Fila2 = Fila;
        Fila = listaV.indexOf(model->headerData(Fila, Qt::Vertical, Qt::DisplayRole).toString());
        QPalette palette2( QApplication::palette() );
        if (Columna == 0) {
          palette2.setColor( QPalette::Active, QPalette::Base, Qt::gray );
          EdtMicroDatoOriginal->setPalette(palette2);
          view3->setCurrentIndex(view3->indexAt(QPoint(view3->columnViewportPosition(Columna), view3->rowViewportPosition(0))));
          for (int j = 0; j < FmeVariablesAsociadas->GetNumAtributos(); j++)  {
            VectorDatosV[j] = "---";
            if (j < 8) view2->setColumnWidth ( j, ANCHOS_VARIABLE[j]);
            else
               if (j < 8 + FmeVariablesAsociadas->GetNum_valores_missing()) view2->setColumnWidth ( j, 100);
               else view2->setColumnWidth ( j, ANCHOS_VARIABLE[j - FmeVariablesAsociadas->GetNum_valores_missing()]);
          }
          listaV2[0] = "";
          model2->setCabeceraV(listaV2);
          model2->setHeaderData(0, Qt::Vertical, QVariant(), Qt::DisplayRole);
          DeshabilitarInformacionRegistroDonante();
          EdtMicroDatoOriginal->setText("-");
          LabBarraEstado2->setText(tr("Registro") + " 0/" + QString::number(numreg, 10) + "   [" + (QString)STR0049 + " = 0]");
        }else {
          if (MatrizImputacion[Fila][Columna-1]) {
            palette2.setColor( QPalette::Active, QPalette::Base, CL_IMPUTACION );
            EdtMicroDatoOriginal->setPalette(palette2);
          }else {
            palette2.setColor( QPalette::Active, QPalette::Base, Qt::gray );
            EdtMicroDatoOriginal->setPalette(palette2);
          }

          view3->setCurrentIndex(view3->indexAt(QPoint(view3->columnViewportPosition(Columna-1), view3->rowViewportPosition(0))));
          for (int j = 0; j < FmeVariablesAsociadas->GetNumAtributos(); j++)  {
            VectorDatosV[j] = FmeVariablesAsociadas->getMatrizVariablesS(Columna-1, j);
            if (j < 8) view2->setColumnWidth ( j, ANCHOS_VARIABLE[j]);
            else
               if (j < 8 + FmeVariablesAsociadas->GetNum_valores_missing()) view2->setColumnWidth ( j, 100);
               else view2->setColumnWidth ( j, ANCHOS_VARIABLE[j - FmeVariablesAsociadas->GetNum_valores_missing()]);
          }
          listaV2[0] = FmeVariablesAsociadas->getlistaV(Columna-1);
          model2->setCabeceraV(listaV2);
          model2->setHeaderData(0, Qt::Vertical, QVariant(), Qt::DisplayRole);
          if (!ConjuntoRegistrosDonantes.empty())
          {
            if (RegistroDonante(Fila) || RegistroExcluido(Fila))
              DeshabilitarInformacionRegistroDonante();
            else
            {
              HabilitarInformacionRegistroDonante();
              posicion = MatrizRegistrosDonantes[Fila][NRD].IndiceRegistro;
              if (posicion == -1) posicion = 0;
              ActualizarInformacionRegistroDonante(Fila, posicion);
            }
          }
          EdtMicroDatoOriginal->setText(FmeMicroDatosAsociados->GetValorS(Fila, Columna-1));
          LabBarraEstado2->setText(tr("Registro") + " " + QString::number(Fila2+1, 10) + "/" + QString::number(numreg, 10) + "   [" + (QString)STR0049 + " = " + QString::number(Columna, 10) + "]");
        }
        if (Fijar) {
          view->setCurrentIndex(view->indexAt(QPoint(view->columnViewportPosition(Columna), view->rowViewportPosition(Fila2))));
          QColor rojo = view->currentIndex().model()->data(view->currentIndex(), Qt::BackgroundRole).value<QColor>();
          QString color = rojo.name();
          setStyleSheet("selection-color: black;selection-background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 " + color + ", stop: 1 gray);");
        }
        view3->clearSelection();
        // Forzamos a repintar las rejillas de registro y Variable
        repintarRegistroDonante(Columna-1);
        view3->clearSelection();
      }else
        LabBarraEstado2->setText(tr("Registro") + " 0/0[" + (QString)STR0049 + " = 0]");
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Pinta la rejilla registro.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void TFmeImputacion::repintarRegistroDonante(int col)
    {
      QString *v = new QString[NumVariables];

      for (int i = 0; i < NumVariables; i++) {
        if (i == col) {
          v[i] = "Blue";          
        }else {          
          v[i] = "Otro";
        }
      }      
      model3->setVectorPintar(v);
      model3->setHeaderData(0, Qt::Vertical, QVariant(), Qt::DisplayRole);
      view3->setCurrentIndex(view3->indexAt(QPoint(view3->columnViewportPosition(col), view3->rowViewportPosition(0))));
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Funcion de ordenacion de las variables a traves de su peso.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    int TFmeImputacion::OrdenacionPesosVariablesAscendente(const void *A, const void *B)
    {
      TipoPesoVariable *VarA, *VarB;

      VarA = (TipoPesoVariable *)A;
      VarB = (TipoPesoVariable *)B;
      if ((*VarA).Peso < (*VarB).Peso)
        return -1;
      if ((*VarA).Peso == (*VarB).Peso)
        return 0;
      if ((*VarA).Peso > (*VarB).Peso)
        return 1;
      return 0;
    }
    /*int OrdenacionPesosVariablesDescendente(const void *A, const void *B)
    {
          TipoPesoVariable *VarA, *VarB;

          VarA = (TipoPesoVariable *)A;
          VarB = (TipoPesoVariable *)B;
          if ((*VarA).Peso > (*VarB).Peso)
            return -1;
          if ((*VarA).Peso == (*VarB).Peso)
            return 0;
          if ((*VarA).Peso < (*VarB).Peso)
            return 1;
          return 0;
     }*/
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//  Calcular la media del vector de entrada.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    double TFmeImputacion::CalcularMedia(double *v, unsigned n)
    {
      unsigned i;
      double r = 0;

      for (i = 0; i < n; i++)
        r += v[i];
      r /= (double)n;
      return r;
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Calcular la mediana del vector de entrada.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    double TFmeImputacion::CalcularMediana(double *v, unsigned n)
    {
      double r;

      // primero hay que ordenar el vector de entrada
      qsort((void*)v, n, sizeof(double), ordfun);
      // mediana si n es par
      if ((n % 2) == 0)
      {
	r = (double)(v[n/2] + v[(n/2)+1]) / (double)2;
      }
      // mediana si n es impar
      else
      {
	r = v[(n+1)/2];
      }
      return r;
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Calcular la media recortada del vector de entrada.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    double TFmeImputacion::CalcularMediaR(double *v, unsigned n, unsigned rec)
    {
      unsigned i, lb, ub;
      double r = 0;

      // primero hay que ordenar el vector de entrada
      qsort((void *)v, n, sizeof(double), ordfun);
      // eliminamos los extremos en el calculo
      if (n > (2 * rec))
      {
	lb = rec;
	ub = n - rec;
	n -= (2 * rec);
      }
      else
      {
      	lb = 0;
	ub = n;
      }
      for (i = lb; i < ub; i++)
	r += v[i];
      r /= (double)n;
      return r;
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Calcular la moda del vector de entrada.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    double TFmeImputacion::CalcularModa(double *v, unsigned n)
    {
      unsigned i, frec;
      int max_frec;
      double valor;

      // primero hay que ordenar el vector de entrada
      qsort((void *)v, n, sizeof(double), ordfun);

      i = 0;
      max_frec = -1;
      valor = 0;
      while (i < n)
      {
	frec = 1;
	while ((i < (n - 1)) && (v[i] == v[i + 1]))
	{
 	  frec++;
	  i++;
	}
	if ((int)frec > max_frec)
	{
	  valor = v[i];
	  max_frec = frec;
	}
	i++;
      }
      return valor;
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Restaurar el registro actual con la copia.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void TFmeImputacion::RestaurarRegistro(double *RegistroOrigen, double *RegistroBackup)
    {
      unsigned j;

      for (j = 0; j < NumVariables; j++)
        RegistroOrigen[j] = RegistroBackup[j];
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Restaurar el registro actual con la copia.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void TFmeImputacion::RestaurarRegistro(unsigned IndiceRegistro)
    {
      unsigned j;
      QString s;

      for (j = 0; j < NumVariables; j++)
      {
        MatrizMicroDatos[IndiceRegistro][j] = FmeMicroDatosAsociados->GetValor(IndiceRegistro, j);        
        MatrizMicroDatosS[IndiceRegistro][j+1] = QString::number(MatrizMicroDatos[IndiceRegistro][j], 'f', 1).replace('.', ',');
        MatrizImputacion[IndiceRegistro][j] = false;
      }
      model->setMatrizImputacion(MatrizImputacion);
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Sustituir los valores imputados en las variables numericas por otros valores temporales.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void TFmeImputacion::RestaurarEstadisticas(int registro, bool warning)
    {
      QSet<unsigned> ConjuntoUnion;
      int IndiceMapeado = VectorMapeadoImputacionRegistros[registro];      

      if (warning)
      {
        NumVariablesImputadasWarning -= NumVariablesImputadas[IndiceMapeado];
      }

      // Calculo de estadisticas
      NumVariablesImputadasTotal -= NumVariablesImputadas[IndiceMapeado];
      NumVariablesImputadas[IndiceMapeado] = 0;
      SumDistancias -= MatrizRegistrosDonantes[registro][MatrizRegistrosDonantes[registro][NRD].IndiceRegistro].Distancia;
      NumErroresRango -= VectorVariablesAImputarRango[IndiceMapeado].size();
      NumErroresEdits -= VectorVariablesAImputarEdits[IndiceMapeado].size();
      
      ConjuntoUnion = VectorVariablesAImputarRango[IndiceMapeado];
      ConjuntoUnion.unite(VectorVariablesAImputarEdits[IndiceMapeado]);
      NumErroresTotal -= ConjuntoUnion.size();
      
      ConjuntoUnion = VectorVariablesAImputarExtendido[IndiceMapeado];
      ConjuntoUnion.unite(VectorVariablesAImputarExtendidoLargo[IndiceMapeado]);
      SizeCompConexas -= ConjuntoUnion.size();
    }
    
    void TFmeImputacion::SustituirImputacionVariablesNumericas()
    {
      unsigned i, j, k, rd, nd;
      QMap<int,double> mc;
      QMap<int,double>::iterator Puntero;
      double Resultado, c, md;
      int v;
      TTipoImputacionVariable TipoImputacionVariable;
      double *tempdata;
      int NumVarImputadas, NumVarBasicasAImputar;
      double *RegTest = new double[NumVariables];
      QSet<unsigned> VarModificadas;
      bool warning;

      for (i = 0; i < NumRegistros; i++)
      {
        VarModificadas.clear();
        for (j = 0; j < NumVariables; j++)
        {
	  TipoImputacionVariable = FmeVariablesAsociadas->GetTipoImputacion(j);
	  if (TipoImputacionVariable == T_REGRESION)
	  {	  
	    if ((MicrodatoImputado(i, j)) && (GetValor(i, j) >= 0))
	    {
	      mc = FmeVariablesAsociadas->GetMapCoef(j);
	      Puntero = mc.begin();
	      Resultado = 0;
	      while (Puntero != mc.end())
	      {	        
                v = Puntero.key();
		c = Puntero.value();
                // tener en cuenta el termino independiente
		if (v < 0)
		  Resultado += c;
		else
		{
		  md = GetValor(i, v);
		  if (md > 0)
		    Resultado += (md * c);
		}

		++Puntero;
              }
              MatrizMicroDatos[i][j] = Resultado;	      
              MatrizMicroDatosS[i][j+1] = QString::number(Resultado, 'f', 1).replace('.', ',');
	      VarModificadas.insert(j);	      
            }          
          }
          else
	  if (TipoImputacionVariable != T_DONANTE)
	  {
	    // obtener el numero de donantes para la variable que estamos tratando
	    nd = MIN(FmeVariablesAsociadas->GetNumDonantes(j), NumRegistrosDonantes);
	    
            // creamos el vector temporal de datos
	    tempdata = new double[nd];	    	    
	      // tratar aquellos valores ya imputados y mayores que cero
	      if ((MicrodatoImputado(i, j)) && (GetValor(i, j) >= 0))
	      {
	        c = 0;
	        for (k = 0; k < nd; k++)
	        {
	          rd = MatrizRegistrosDonantes[i][k].IndiceRegistro;
		  md = GetValor(rd, j);
                  // OJO! no todos los valores son cogidos
		  if ((!(MicrodatoImputado(rd, j))) && (md >= 0))
		  {
		    tempdata[k] = md;
		    c++;
		  }
	        }
		if (c != 0)
		{
		  switch(TipoImputacionVariable)
		  {
		  case T_MEDIA:
		    Resultado = CalcularMedia(tempdata, (unsigned)c);
		    break;
		  case T_MEDIANA:
		    Resultado = CalcularMediana(tempdata, (unsigned)c);
		    break;
		  case T_MEDIA_R:
                    Resultado = CalcularMediaR(tempdata, (unsigned)c, FmeVariablesAsociadas->GetValRec(j));
		    break;
		  case T_MODA:
		    Resultado = CalcularModa(tempdata, (unsigned)c);
		    break;
		  default:
                    break;
		  }
		  // asignar el valor
		  MatrizMicroDatos[i][j] = Resultado;		  
		  MatrizMicroDatosS[i][j+1] = QString::number(Resultado, 'f', 1).replace('.', ',');		  
		  VarModificadas.insert(j);

                }else {
                  MatrizMicroDatos[i][j] = FmeMicroDatosAsociados->GetValor(i, j);                  
                  MatrizMicroDatosS[i][j+1] = QString::number(MatrizMicroDatos[i][j], 'f', 1).replace('.', ',');                  
                  QMessageBox::critical(this, "Error", tr("No hay donantes para la variable ") + QString::number(j+1, 10) + tr(" registro ") + QString::number(i+1, 10), QMessageBox::Ok, QMessageBox::NoButton);
                }
              }            
            delete tempdata;
          }
          RegTest[j] = GetValor(i, j);
        }
        if ((!VarModificadas.empty()) && (!CheckRegistro2(i, RegTest, VarModificadas)))
        {
          warning = false;
          RestaurarRegistro(i);
          MatrizRegistrosDonantes[i][NRD].IndiceRegistro = -1;
          ConjuntoRegistrosIncorrectos.insert(i);
          if (ConjuntoRegistrosWarning.contains(i)){
            ConjuntoRegistrosWarning.remove(i);
            warning = true;
          }
          RestaurarEstadisticas(i, warning);
          ImputacionVar[i] = true;
        }
      }
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Salvar los microdatos en la base de datos.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void TFmeImputacion::SalvarMicrodatosEnBBDD(QString NombreBaseTablaSalida)
    {
      unsigned i, j, k, NumVariablesTabla, UltimaVariableEscrita = 0, NumTablas;
      QString TablaEntrada, TablaSalida, CadenaSQL, CadenaSQL2, ValoresActualizacion, IdRegistro, Key, ComillasKey, Valor;
      QString Mensaje = tr("Error en el proceso de escritura en base de datos");
      QStringList *NombresTablas;
      bool actualizar;
      int valor = 0;
      int valor2 = 0;
      int r = 0;
      // si los campos son de tipo string en la bbdd, esta variable debe estar inicializada a "'". En otro caso
      // esta variable debe estar inicializada a ""
      QString ComillasCampos = "";

      NombresTablas = FmeMicroDatosAsociados->GetNombresTablas();
      NumTablas = NombresTablas->count();
      Key = FmeMicroDatosAsociados->GetKey();
      
      QProgressDialog progress(tr("Salvando microdatos..."), tr("Cancelar"), 0, NumRegistros*NumTablas, this);
      progress.setWindowModality(Qt::WindowModal);
      progress.show();
      if (Xml) {
        QDomDocument *docE = new QDomDocument("?xml");
        QDomNode n;
        QDomElement e, e1;
        QDomNode n1;

        for (i = 0; i < NumTablas; i++)
        {
          if (progress.wasCanceled())
             break;

          QDomDocument docS("");
          QDomElement rootS = docS.createElement("dataroot");
          docS.appendChild(rootS);
          
          TablaEntrada = NombresTablas->at(i);
	  if (NumTablas == 1)
	    TablaSalida = NombreBaseTablaSalida + "_" + SUFIJOSALIDA + ".xml";
	  else
	    TablaSalida = NombreBaseTablaSalida + "_T" + QString::number(i+1) + "_" + SUFIJOSALIDA + ".xml";

          QFile file(QDir::convertSeparators(NombreBaseDatos + TablaEntrada));
          if ((!file.open(QIODevice::ReadOnly)) || (!docE->setContent(&file)))
          {
            QMessageBox::critical(this, tr("Error"), tr("No se pudo realizar satisfactoriamente la consulta sobre la base de datos") +  " [\"" + TablaSalida + "\"]", QMessageBox::Ok, QMessageBox::NoButton);
            QApplication::processEvents();
            file.close();
            return;
          }

          QDomElement root = docE->documentElement();
          if (!root.tagName().contains("dataroot"))
            if (root.tagName() != "ROWSET")
            {
              QMessageBox::critical(this, tr("Error"), tr("No se pudo realizar satisfactoriamente la consulta sobre la base de datos") +  " [\"" + TablaSalida + "\"]", QMessageBox::Ok, QMessageBox::NoButton);
              QApplication::processEvents();
              file.close();
              return;
            }

          CadenaSQL2 = TablaSalida;
          CadenaSQL2.replace(".xml", "", Qt::CaseInsensitive);
          CadenaSQL = TablaEntrada;
          CadenaSQL.replace(".xml", "", Qt::CaseInsensitive);
          k=0;

          n = root.firstChild();

          while (!n.isNull())
          {
            progress.setValue(r);
            if (progress.wasCanceled())
              break;
            e = n.toElement();
            if (!e.isNull()) {
              if ((e.tagName() == CadenaSQL) || (e.tagName() == "ROW")) {
                QDomElement tag = docS.createElement(CadenaSQL2);
                rootS.appendChild(tag);
                n1 = n.firstChild();
                while (!n1.isNull())
                {
                  e1 = n1.toElement();
                  if (!e1.isNull())
                  {
                    if ((e1.tagName() == Key) || (e1.tagName() == "ID")) {
                      QDomElement t = docS.createElement(e1.tagName());
                      t.appendChild(docS.createTextNode(e1.text()));
                      tag.appendChild(t);
                    }else {
                      j = listaH.indexOf(e1.tagName());
                      if (MatrizImputacion[k][j-1])
                      {
	                Valor = MatrizMicroDatosS[k][j].replace(',', '.');
                        QDomElement t = docS.createElement(e1.tagName());
                        t.appendChild(docS.createTextNode(Valor));
                        tag.appendChild(t);
                      }else {
                        QDomElement t = docS.createElement(e1.tagName());
                        t.appendChild(docS.createTextNode(e1.text()));
                        tag.appendChild(t);
                      }
                    }
                  }
                  n1 = n1.nextSibling();
                }
              }
            }
            k++;
            r++;
            n = n.nextSibling();
          }          
          file.close();
          QString xml = docS.toString();
          QFile file2(QDir::convertSeparators(NombreBaseDatos + TablaSalida));
          if (file2.open(QIODevice::WriteOnly))   {
            QTextStream stream(&file2);
            stream << xml;
          }
        }
      }else {
        // Si la clave es ID presuponemos que es autonumerica
        if (Key == "ID")
	  ComillasKey = "";
        else
	  ComillasKey = "'";

        QProgressDialog progress(tr("Volcado de los microdatos"), tr("Cancelar"), 0, NumTablas * NumRegistros, this);
        progress.show();
        for (i = 0; i < NumTablas; i++)
        {
          TablaEntrada = NombresTablas->at(i);
	  if (NumTablas == 1)
	    TablaSalida = NombreBaseTablaSalida + "_" + SUFIJOSALIDA;
	  else
	    TablaSalida = NombreBaseTablaSalida + "_T" + QString::number(i+1) + "_" + SUFIJOSALIDA;

	  CadenaSQL = "DROP TABLE " + TablaSalida;	
	  query5->exec(CadenaSQL);	
          if (!Oracle) {
            if (Excel) {
                query5->exec("SELECT * FROM " + TablaEntrada + FmeMicroDatosAsociados->GetCota() + " ORDER BY \"" + Key + "\"");
                QSqlRecord record6 = query5->record();
                int l = 0;
                QStringList lista;
                while (l < record6.count()) {
                    lista.append(record6.fieldName(l));
                    l++;
                }
                query5->exec("CREATE TABLE " + TablaSalida + "(" + lista.join(" char(250), ") + " char(250))");
                query5->exec("INSERT INTO " + TablaSalida + " SELECT * FROM " + TablaEntrada + FmeMicroDatosAsociados->GetCota() + " ORDER BY \"" + Key + "\"");
            }else query5->exec("SELECT * INTO " + TablaSalida + " FROM " + TablaEntrada + FmeMicroDatosAsociados->GetCota() + " ORDER BY \"" + Key + "\"");
          }else
            query5->exec("CREATE TABLE " + TablaSalida + " AS SELECT * FROM " + TablaEntrada + FmeMicroDatosAsociados->GetCota() + " ORDER BY \"" + Key + "\"");

          if (!query5->isActive())
          {
            QMessageBox::critical(this, "Error", Mensaje, QMessageBox::Ok, QMessageBox::NoButton);	  
	    progress.hide();
	    return;
	  }
	  NumVariablesTabla = FmeMicroDatosAsociados->GetNumVariablesTabla(i);
	  for (k = 0; k < NumRegistros; k++)
	  {
	    actualizar = false;
	    ValoresActualizacion = "";
	    for (j = UltimaVariableEscrita; j < (UltimaVariableEscrita + NumVariablesTabla); j++)
	    {
	      if (MatrizImputacion[k][j])
	      {	      
                Valor = MatrizMicroDatosS[k][j+1].replace(',', '.').replace(".0", "");
                if (!Oracle) {
                  if (Excel)
                    ValoresActualizacion += " " + (listaH.at(j+1) + " = '" + Valor + "',");
                  else
                    ValoresActualizacion += ("`" + listaH.at(j+1) + "` = " + ComillasCampos + Valor + ComillasCampos + ",");
                }else
                    ValoresActualizacion += "\"" + (listaH.at(j+1) + "\" = " + ComillasCampos + Valor + ComillasCampos + ",");                
	        actualizar = true;
	      }
            }
            if (actualizar)
	    {
              ValoresActualizacion[ValoresActualizacion.size()-1] = ' ';
              IdRegistro = ListaIds->at(k);
	      if (!Oracle)
                if (Excel)
                    CadenaSQL = "UPDATE [" + TablaSalida + "$] SET " + ValoresActualizacion + "WHERE " + Key + " = '"  + IdRegistro + "'";//query2->exec("UPDATE " + NombreTabla + " SET CONDICION = '" + EdtEdit->text() + "' WHERE ID = " + id);
                else
                    CadenaSQL = "UPDATE " + TablaSalida + " SET " + ValoresActualizacion + "WHERE `" + Key + "` = " + ComillasKey + IdRegistro + ComillasKey;
              else
                CadenaSQL = "UPDATE " + TablaSalida + " SET " + ValoresActualizacion + "WHERE \"" + Key + "\" = " + ComillasKey + IdRegistro + ComillasKey;
              query5->exec(CadenaSQL);
              if (!query5->isActive())
              {
                QMessageBox::critical(this, "Error", "Cadena: " + CadenaSQL + " " + Mensaje + "\nError: " + query5->lastError().text(), QMessageBox::Ok, QMessageBox::NoButton);
                progress.hide();
                return;
              }
            }
            valor2 = valor + k;
            progress.setValue(valor2);
            QApplication::processEvents();
          }
          UltimaVariableEscrita += NumVariablesTabla;
          valor = NumRegistros * i+1;
        }
        progress.setValue(NumTablas * NumRegistros);
        progress.hide();
        QApplication::processEvents();
      }
      QMessageBox::information(this, QApplication::translate("", "Informaci\303\263n", 0, QApplication::UnicodeUTF8), tr("MicroDatos salvados correctamente"), QMessageBox::Ok, QMessageBox::NoButton);
    }
    QString TFmeImputacion::SustCaracter(QString Cadena, char CarABuscar, char CarSustitucion)
    {
      QString Aux;
      int Pos;

      Aux = Cadena;
      Pos = Aux.indexOf(CarABuscar);
      if (Pos != -1)
        Aux[Pos] = CarSustitucion;
      return Aux;
    }

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Repintar la Rejilla principal.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void TFmeImputacion::repintar()
    {
      model->setMatrizImputacion(MatrizImputacion);
      model->setConjuntoRegistrosDonantes(ConjuntoRegistrosDonantes);
      model->setVectorExclusionVariables(FmeRangosAsociados->GetVectorExclusionVariables());
      model->setConjuntoRegistrosExcluidos(ConjuntoRegistrosExcluidos);
      model->setConjuntoRegistrosIncorrectos(ConjuntoRegistrosIncorrectos);
      view->repaint();
    }

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// IMPUTAR DATO POR REGISTRO DONANTE.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void TFmeImputacion::ImputarMicroDatoRegistroDonante(int registro, int IndiceRegistroDonante)     //ver posicion registro empiez en 0?
    {
      unsigned IndiceMapeado, NumVariablesImputadasActual, MinNumVariablesImputadas, IndiceRegistroDonanteMin;
      double *RegistroTest;
      double *RegistroTestMin;
      TTipoImputacionRegistro TipoImputacionRegistro, TipoImputacionRegistroMin;
      QSet<unsigned> ConjuntoUnion;
      insert_iterator<QSet<unsigned> > Puntero(ConjuntoUnion, ConjuntoUnion.begin());

      RegistroTest = new double[NumVariables];
      RegistroTestMin = new double[NumVariables];

      IndiceMapeado = VectorMapeadoImputacionRegistros[registro];

      MinNumVariablesImputadas = NumVariables;
      TipoImputacionRegistro = T_NO_CORREGIDO;
      TipoImputacionRegistroMin = T_NO_CORREGIDO;

      TipoImputacionRegistro = BuscarDonacionCorrecta2(registro, IndiceRegistroDonante, VectorVariablesAImputarRangoAux[IndiceMapeado], VectorVariablesAImputarEditsAux[IndiceMapeado], VectorVariablesAImputarExtendidoAux[IndiceMapeado], VectorVariablesAImputarExtendidoLargoAux[IndiceMapeado], RegistroTest, &NumVariablesImputadasActual);

      switch(TipoImputacionRegistro)
      {
        case T_NO_CORREGIDO:
          break;
        case T_CORREGIDO_NO_WARNING:
          TipoImputacionRegistroMin = T_CORREGIDO_NO_WARNING;
          MinNumVariablesImputadas = NumVariablesImputadasActual;
          IndiceRegistroDonanteMin = posicion;
          CopiarRegistros(RegistroTest, RegistroTestMin);
          break;
        case T_CORREGIDO_WARNING:
          TipoImputacionRegistroMin = T_CORREGIDO_WARNING;
          if (NumVariablesImputadasActual < MinNumVariablesImputadas)
          {
            MinNumVariablesImputadas = NumVariablesImputadasActual;
            IndiceRegistroDonanteMin = posicion;
            CopiarRegistros(RegistroTest, RegistroTestMin);
          }
          break;
        default:
          break;
      }

      if (TipoImputacionRegistroMin != T_NO_CORREGIDO)
      {
         MatrizRegistrosDonantes[registro][NRD].IndiceRegistro = IndiceRegistroDonanteMin;
         NumVariablesImputadas[IndiceMapeado] = MinNumVariablesImputadas;
         CommitRegistro(registro, RegistroTestMin);
      
         if (TipoImputacionRegistroMin == T_CORREGIDO_WARNING)
         {
           NumVariablesImputadasWarning += MinNumVariablesImputadas;
           ConjuntoRegistrosWarning.insert(registro);
         }

         // Calculo de estadisticas
         NumVariablesImputadasTotal += MinNumVariablesImputadas;
         SumDistancias += MatrizRegistrosDonantes[registro][IndiceRegistroDonanteMin].Distancia;
         NumErroresRango += VectorVariablesAImputarRango[IndiceMapeado].size();
         NumErroresEdits += VectorVariablesAImputarEdits[IndiceMapeado].size();
         ConjuntoUnion = VectorVariablesAImputarRango[IndiceMapeado];
         ConjuntoUnion.unite(VectorVariablesAImputarEdits[IndiceMapeado]);
         NumErroresTotal += ConjuntoUnion.size();
         ConjuntoUnion = VectorVariablesAImputarExtendido[IndiceMapeado];
         ConjuntoUnion.unite(VectorVariablesAImputarExtendidoLargo[IndiceMapeado]);
         SizeCompConexas += ConjuntoUnion.size();
      }
      else
      {
         MatrizRegistrosDonantes[registro][NRD].IndiceRegistro = -1;
         ConjuntoRegistrosIncorrectos.insert(registro);
      }

      SustituirImputacionVariablesNumericas();

      delete RegistroTest;
      delete RegistroTestMin;

      NumRegistrosIncorrectos = ConjuntoRegistrosIncorrectos.size();
      NumRegistrosCorrectos = NumRegistros - NumRegistrosIncorrectos - NumRegistrosDonantes - NumRegistrosExcluidos;
      NumRegistrosWarning = ConjuntoRegistrosWarning.size();
      NumRegistrosACorregir = NumRegistros - NumRegistrosDonantes - NumRegistrosExcluidos;

      // Calcular Estadisticas
      CalcularEstadisticas();

      MostrarInfoAsociada(0, 1, true);
      //QColor rojo = model->data(view->indexAt(QPoint(view->columnViewportPosition(5), view->rowViewportPosition(5))), Qt::BackgroundRole).value<QColor>(); //view->currentIndex().model()->data(view->currentIndex(), Qt::BackgroundRole).value<QColor>();
      //QString color = rojo.name();
      //view->setStyleSheet("selection-color: black;selection-background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 " + color + ", stop: 1 gray);");
      //SgrRejillaSelectCell(view->currentIndex());

      repintar();

    }

    TTipoImputacionRegistro TFmeImputacion::BuscarDonacionCorrecta2(unsigned IndiceRegistroAImputar, unsigned IndiceRegistroDonante, QSet<unsigned> VariablesRangoAImputar, QSet<unsigned> VariablesEditsAImputar, QSet<unsigned> VariablesExtendidasAImputar, QSet<unsigned> VariablesExtendidasLargasAImputar, double *RegistroTest, unsigned *NumVariablesImputadas)
    {
      QSet<unsigned>::iterator Puntero;
      double *RegistroDonante, *RegistroBackup;
      unsigned j, NumVariablesRango, NumVariablesEdits, NumVariablesBasicasAImputar, NumVariablesExtendidas, NumVariablesExtendidasLargas, NumVariablesDonadas, Frontera, IndiceVariable;
      bool RegistroCorrecto;
      QSet<unsigned> VariablesModificadas;

      NumVariablesRango = VariablesRangoAImputar.size();
      NumVariablesEdits = VariablesEditsAImputar.size();
      NumVariablesExtendidas = VariablesExtendidasAImputar.size();
      NumVariablesExtendidasLargas = VariablesExtendidasLargasAImputar.size();
      NumVariablesBasicasAImputar = NumVariablesRango + NumVariablesEdits;
      VariablesModificadas.clear();
      
       // Inicializar el registro test y crear el registro backup
      RegistroBackup = new double[NumVariables];
      for (j = 0; j < NumVariables; j++)  {
        RegistroTest[j] = GetValor(IndiceRegistroAImputar, j);
        RegistroBackup[j] = RegistroTest[j];
      }

      // Obtener el registro donante
      RegistroDonante = GetRegistro(IndiceRegistroDonante);

      // Imputar las variables de rango
      ImputarVariablesTest(VariablesRangoAImputar, RegistroTest, RegistroBackup, RegistroDonante, &VariablesModificadas);
      // Evaluar el registro
      if (CheckRegistro(IndiceRegistroAImputar, RegistroTest, VariablesModificadas))
      {
        delete RegistroBackup;
        *NumVariablesImputadas = GetNumVariablesDistintas(IndiceRegistroAImputar, RegistroTest);
        if (*NumVariablesImputadas <= NumVariablesBasicasAImputar)
          return T_CORREGIDO_NO_WARNING;
        else
          return T_CORREGIDO_WARNING;
      }

      // Realizar una enumeracion sobre las variables de edits
      if (NumVariablesEdits > 0)
      {
        if (NumVariablesEdits <= FrmOpciones->GetUmbralEnumVariables())
          if (CheckEnumeracion(VariablesEditsAImputar, NumVariablesEdits, VectorPesosVariables, IndiceRegistroAImputar, RegistroTest, RegistroBackup, RegistroDonante, VariablesModificadas))
          {
            delete RegistroBackup;
            *NumVariablesImputadas = GetNumVariablesDistintas(IndiceRegistroAImputar, RegistroTest);
            if (*NumVariablesImputadas <= NumVariablesBasicasAImputar)
              return T_CORREGIDO_NO_WARNING;
            else
              return T_CORREGIDO_WARNING;
          }

        // Imputar las variables de edits

        ImputarVariablesTest(VariablesEditsAImputar, RegistroTest, RegistroBackup, RegistroDonante, &VariablesModificadas);
         // Evaluar el registro
        if (CheckRegistro(IndiceRegistroAImputar, RegistroTest, VariablesModificadas))
        {
          delete RegistroBackup;
          *NumVariablesImputadas = GetNumVariablesDistintas(IndiceRegistroAImputar, RegistroTest);
          if (*NumVariablesImputadas <= NumVariablesBasicasAImputar)
            return T_CORREGIDO_NO_WARNING;
          else
            return T_CORREGIDO_WARNING;
        }
      }

      delete RegistroBackup;

      // Donar las variables extendidas
      Frontera = 0;
      NumVariablesDonadas = 0;
      RegistroCorrecto = false;
      while ((NumVariablesDonadas < NumVariablesExtendidas) && (!RegistroCorrecto))
      {
        IndiceVariable = VectorPesosVariables[Frontera].IndiceVariable;
        if (VariablesExtendidasAImputar.contains(IndiceVariable))
        {
          if (RegistroTest[IndiceVariable] != RegistroDonante[IndiceVariable])
          {
            VariablesModificadas.insert(IndiceVariable);
            RegistroTest[IndiceVariable] = RegistroDonante[IndiceVariable];

            RegistroCorrecto = CheckRegistro(IndiceRegistroAImputar, RegistroTest, VariablesModificadas);
          }
          NumVariablesDonadas++;
        }
        Frontera++;
      }

      if (!RegistroCorrecto)
      {
        // Donar las variables extendidas largas
        Frontera = 0;
        NumVariablesDonadas = 0;
        RegistroCorrecto = false;
        while ((NumVariablesDonadas < NumVariablesExtendidasLargas) && (!RegistroCorrecto))
        {
          IndiceVariable = VectorPesosVariables[Frontera].IndiceVariable;
          if (VariablesExtendidasLargasAImputar.contains(IndiceVariable))
          {
            if (RegistroTest[IndiceVariable] != RegistroDonante[IndiceVariable])
            {
              VariablesModificadas.insert(IndiceVariable);
              RegistroTest[IndiceVariable] = RegistroDonante[IndiceVariable];

              RegistroCorrecto = CheckRegistro(IndiceRegistroAImputar, RegistroTest, VariablesModificadas);
            }
            NumVariablesDonadas++;
          }
          Frontera++;
        }
      }

      *NumVariablesImputadas = GetNumVariablesDistintas(IndiceRegistroAImputar, RegistroTest);

      if (RegistroCorrecto)
      {
        if (*NumVariablesImputadas <= NumVariablesBasicasAImputar)
          return T_CORREGIDO_NO_WARNING;
        else
          return T_CORREGIDO_WARNING;
      }
      else
        return T_NO_CORREGIDO;
    }

    void TFmeImputacion::DesImputarMicroDatoRegistroDonante(int registro)     //ver posicion registro empiez en 0?
    {
      unsigned IndiceMapeado, MinNumVariablesImputadas, IndiceRegistroDonanteMin;
      QSet<unsigned> ConjuntoUnion;


      IndiceMapeado = VectorMapeadoImputacionRegistros[registro];

      IndiceRegistroDonanteMin = MatrizRegistrosDonantes[registro][NRD].IndiceRegistro;
      MinNumVariablesImputadas = NumVariablesImputadas[IndiceMapeado];

      if (ConjuntoRegistrosWarning.contains(registro))
      {
        NumVariablesImputadasWarning -= MinNumVariablesImputadas;
        ConjuntoRegistrosWarning.remove(registro);
      }

      // Calculo de estadisticas
      NumVariablesImputadasTotal -= MinNumVariablesImputadas;
      SumDistancias -= MatrizRegistrosDonantes[registro][IndiceRegistroDonanteMin].Distancia;
      NumErroresRango -= VectorVariablesAImputarRango[IndiceMapeado].size();
      NumErroresEdits -= VectorVariablesAImputarEdits[IndiceMapeado].size();

      ConjuntoUnion = VectorVariablesAImputarRango[IndiceMapeado];
      ConjuntoUnion.unite(VectorVariablesAImputarEdits[IndiceMapeado]);
      NumErroresTotal -= ConjuntoUnion.size();

      ConjuntoUnion = VectorVariablesAImputarExtendido[IndiceMapeado];
      ConjuntoUnion.unite(VectorVariablesAImputarExtendidoLargo[IndiceMapeado]);
      SizeCompConexas -= ConjuntoUnion.size();

      NumRegistrosWarning = ConjuntoRegistrosWarning.size();

      // Calcular Estadisticas
      CalcularEstadisticas();

      RestaurarRegistro(registro);
      repintar();
    }
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// PULSAR EL BOTON DE IMPUTAR.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void TFmeImputacion::ButCambiarRegistroDonanteClick()
    {
      unsigned IndiceRegistroAImputar, IndiceRegistroDonante;
      int actual = view->currentIndex().column();
      IndiceRegistroAImputar = view->currentIndex().row();
      IndiceRegistroDonante = MatrizRegistrosDonantes[IndiceRegistroAImputar][posicion].IndiceRegistro;      
      DesImputarMicroDatoRegistroDonante(IndiceRegistroAImputar);
      ImputarMicroDatoRegistroDonante(IndiceRegistroAImputar, IndiceRegistroDonante);
      MostrarInfoAsociada(IndiceRegistroAImputar, actual, true);
      view->setFocus();
      //MostrarInfoAsociada(IndiceRegistroAImputar, view->currentIndex().column(), true);
    }

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// SELECCIONAR UNA VARIABLE DE LA LISTA DE IR A VARIABLES.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void TFmeImputacion::CbxIrAVariablePorNombreCloseUp(int index)
    {      
      view->setCurrentIndex(view->indexAt(QPoint(view->columnViewportPosition(index+1), view->rowViewportPosition(view->currentIndex().row()))));
      SgrRejillaSelectCell(view->currentIndex());      
      view->setFocus();
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// PULSAR UNA TECLA EN EL EDIT DE IR A REGISTRO.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void TFmeImputacion::EdtIrARegistroPorNumeroKeyDown()
    {
      unsigned IndiceRegistro;

      //try
      //{
        IndiceRegistro = EdtIrARegistroPorNumero->text().toInt();
      /*}
      catch (...)
      {
        EdtIrARegistroPorNumero->setText("");
        return;
      }*/
      if ((IndiceRegistro >= 1) && (IndiceRegistro <= NumRegistros))
        view->setCurrentIndex(view->indexAt(QPoint(view->columnViewportPosition(view->currentIndex().column()), view->rowViewportPosition(IndiceRegistro-1))));
      EdtIrARegistroPorNumero->setText("");

      SgrRejillaSelectCell(view->currentIndex());
      view->setFocus();
    }
    
    void TFmeImputacion::CbxIrARegistroPorNombreCloseUp(int index)
    {      
      view->setCurrentIndex(view->indexAt(QPoint(view->columnViewportPosition(view->currentIndex().column()), view->rowViewportPosition(index))));
      SgrRejillaSelectCell(view->currentIndex());
      view->setFocus();
    }
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// PULSAR UNA TECLA EN EL EDIT DE IR A VARIABLE.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void TFmeImputacion::EdtIrAVariablePorNumeroKeyDown()
    {
      unsigned IndiceVariable;

      //try
      //{
      IndiceVariable = EdtIrAVariablePorNumero->text().toInt();
      /*}
      catch (...)
      {
      EdtIrAVariablePorNumero->setText("");
      return;
      }*/
      if ((IndiceVariable >= 1) && (IndiceVariable <= NumVariables))
        view->setCurrentIndex(view->indexAt(QPoint(view->columnViewportPosition(IndiceVariable), view->rowViewportPosition(view->currentIndex().row()))));
      EdtIrAVariablePorNumero->setText("");
      SgrRejillaSelectCell(view->currentIndex());      
      view->setFocus();
    }
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// SELECCIONAR UNA CELDA EN LA REJILLA.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void TFmeImputacion::SgrRejillaSelectCell(const QModelIndex& index)
    {
      int fila = index.row();
      int col = index.column();
      if ((fila >= 0) && (col >=0))
        MostrarInfoAsociada(fila, col, true);
      else
        LabBarraEstado2->setText(tr("Registro") + " 0/" + QString::number(model->rowCount(view->currentIndex()), 10) + "   [" + (QString)STR0049 + " = 0]");
    }

    void TFmeImputacion::SgrRejillaSelectCellV(const int& index)
    {
      int fila = view->currentIndex().row();
      int col = 1;
      MostrarInfoAsociada(fila, col, false);
    }
    void TFmeImputacion::SgrRejillaSelectCellH(const int& index)
    {
      int fila = 1;
      int col = view->currentIndex().column();
      MostrarInfoAsociada(fila, col, false);
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// PULSAR ALT + UNA TECLA SOBRE LA REJILLA PRINCIPAL.
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void TFmeImputacion::SgrRejillaKeyDownAR()
    {
      unsigned Fila, Columna;

      Fila = view->currentIndex().row();
      Fila = listaV.indexOf(model->headerData(Fila, Qt::Vertical, Qt::DisplayRole).toString());
      Columna = BuscarVariableErrorDerecha(Fila, view->currentIndex().column());
      QModelIndex index = view->indexAt(QPoint(view->columnViewportPosition(Columna), view->rowViewportPosition(view->currentIndex().row())));
      view->setCurrentIndex(index);
      SgrRejillaSelectCell(view->currentIndex());
      view->setFocus();      
    }
    void TFmeImputacion::SgrRejillaKeyDownAL()
    {
      unsigned Fila, Columna;

      Fila = view->currentIndex().row();
      Fila = listaV.indexOf(model->headerData(Fila, Qt::Vertical, Qt::DisplayRole).toString());
      Columna = BuscarVariableErrorIzquierda(Fila, view->currentIndex().column());
      QModelIndex index = view->indexAt(QPoint(view->columnViewportPosition(Columna), view->rowViewportPosition(view->currentIndex().row())));
      view->setCurrentIndex(index);
      SgrRejillaSelectCell(view->currentIndex());
      view->setFocus();      
    }
    void TFmeImputacion::SgrRejillaKeyDownAU()
    {
      unsigned Fila, Columna;

      Columna = view->currentIndex().column();
      Fila = BuscarMicroDatoErrorArriba(listaV.indexOf(model->headerData(view->currentIndex().row(), Qt::Vertical, Qt::DisplayRole).toString()), Columna);
      Fila = model->GetcabeceraV().indexOf(ListaIds->at(Fila));
      QModelIndex index = view->indexAt(QPoint(view->columnViewportPosition(Columna), view->rowViewportPosition(Fila)));
      view->setCurrentIndex(index);
      SgrRejillaSelectCell(view->currentIndex());
      view->setFocus();     
    }
    void TFmeImputacion::SgrRejillaKeyDownAD()
    {
      unsigned Fila, Columna;

      Columna = view->currentIndex().column();
      Fila = BuscarMicroDatoErrorAbajo(listaV.indexOf(model->headerData(view->currentIndex().row(), Qt::Vertical, Qt::DisplayRole).toString()), Columna);
      Fila = model->GetcabeceraV().indexOf(ListaIds->at(Fila));
      QModelIndex index = view->indexAt(QPoint(view->columnViewportPosition(Columna), view->rowViewportPosition(Fila)));
      view->setCurrentIndex(index);
      SgrRejillaSelectCell(view->currentIndex());
      view->setFocus();      
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// PULSAR SHIFT + UNA TECLA SOBRE LA REJILLA PRINCIPAL.
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void TFmeImputacion::SgrRejillaKeyDownSR()
    {
      unsigned Fila, Columna;

      Fila = view->currentIndex().row();
      Fila = listaV.indexOf(model->headerData(Fila, Qt::Vertical, Qt::DisplayRole).toString());
      Columna = BuscarVariableErrorDerechaRI(Fila, view->currentIndex().column());
      QModelIndex index = view->indexAt(QPoint(view->columnViewportPosition(Columna), view->rowViewportPosition(view->currentIndex().row())));
      view->setCurrentIndex(index);
      SgrRejillaSelectCell(view->currentIndex());
      view->setFocus();      
    }
    void TFmeImputacion::SgrRejillaKeyDownSL()
    {
      unsigned Fila, Columna;

      Fila = view->currentIndex().row();
      Fila = listaV.indexOf(model->headerData(Fila, Qt::Vertical, Qt::DisplayRole).toString());
      Columna = BuscarVariableErrorIzquierdaRI(Fila, view->currentIndex().column());
      QModelIndex index = view->indexAt(QPoint(view->columnViewportPosition(Columna), view->rowViewportPosition(view->currentIndex().row())));
      view->setCurrentIndex(index);
      SgrRejillaSelectCell(view->currentIndex());
      view->setFocus();      
    }
    void TFmeImputacion::SgrRejillaKeyDownSU()
    {
      unsigned Fila, Columna;

      Columna = view->currentIndex().column();
      Fila = BuscarMicroDatoErrorArribaRI(listaV.indexOf(model->headerData(view->currentIndex().row(), Qt::Vertical, Qt::DisplayRole).toString()), Columna);
      Fila = model->GetcabeceraV().indexOf(ListaIds->at(Fila));
      QModelIndex index = view->indexAt(QPoint(view->columnViewportPosition(Columna), view->rowViewportPosition(Fila)));
      view->setCurrentIndex(index);
      SgrRejillaSelectCell(view->currentIndex());
      view->setFocus();      
    }
    void TFmeImputacion::SgrRejillaKeyDownSD()
    {
      unsigned Fila, Columna;

      Columna = view->currentIndex().column();
      Fila = BuscarMicroDatoErrorAbajoRI(listaV.indexOf(model->headerData(view->currentIndex().row(), Qt::Vertical, Qt::DisplayRole).toString()), Columna);
      Fila = model->GetcabeceraV().indexOf(ListaIds->at(Fila));
      QModelIndex index = view->indexAt(QPoint(view->columnViewportPosition(Columna), view->rowViewportPosition(Fila)));
      view->setCurrentIndex(index);
      SgrRejillaSelectCell(view->currentIndex());
      view->setFocus();      
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// HACER DOBLE CLICK SOBRE LA REJILLA DE VARIABLE.
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void TFmeImputacion::SgrRejillaVariableDblClick(const QModelIndex& index)
    {      
      unsigned ColumnaActiva;

      ColumnaActiva = index.column();

      if (listaH2[ColumnaActiva] == "MAPPING")
        FmeVariablesAsociadas->ConsultarTablaMapping(VectorDatosV[ColumnaActiva]);

      if (listaH2[ColumnaActiva] == "FILTRO")
        if (!VectorDatosV[ColumnaActiva].isEmpty())
          QMessageBox::information(this, QApplication::translate("", "Informaci\303\263n", 0, QApplication::UnicodeUTF8), VectorDatosV[ColumnaActiva]);

      if (FmeVariablesAsociadas->GetCadenas_Missing()->contains(listaH2[ColumnaActiva]))
        FmeVariablesAsociadas->ConsultarTablaMissing();
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// DOBLE CLICK SOBRE LA REJILLA PRINCIPAL.
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void TFmeImputacion::SgrRejillaDblClick(const QModelIndex& index)
    {
      if (GetPermImputacManual()) {
        unsigned IndiceRegistro, IndiceVariable;

        IndiceRegistro = index.row();
        IndiceVariable = index.column();
        if (RegistroDonante(IndiceRegistro) || RegistroExcluido(IndiceRegistro) || FmeRangosAsociados->VariableExcluida(IndiceVariable) || !FmeVariablesAsociadas->EsVariableImputable(IndiceVariable))
          return;
        FrmCambiarMicrodato = new TFrmCambiarMicrodato(this);
        connect(FrmCambiarMicrodato->GetButAceptar(), SIGNAL(clicked()), this, SLOT(ButAceptarCambiarMicrodatoClick()));
        connect(FrmCambiarMicrodato->GetButCancelar(), SIGNAL(clicked()), this, SLOT(ButCancelarCambiarMicrodatoClick()));
        FrmCambiarMicrodato->FijarParametros(listaH.at(IndiceVariable), IndiceRegistro+1, MatrizMicroDatos[IndiceRegistro][IndiceVariable-1]);
        FrmCambiarMicrodato->show();
      }      
    }

    void TFmeImputacion::ButAceptarCambiarMicrodatoClick()
    {
      unsigned IndiceRegistro, IndiceVariable, IndiceMapeado;

      IndiceRegistro = view->currentIndex().row();
      IndiceVariable = view->currentIndex().column();
      if (!MicrodatoImputado(IndiceRegistro, IndiceVariable-1)){
          IndiceMapeado = VectorMapeadoImputacionRegistros[IndiceRegistro];
          NumVariablesImputadas[IndiceMapeado]++;
          EdtNumVariablesImputadas->setText(QString::number(NumVariablesImputadas[IndiceMapeado], 10));
      }
      EvaluarRegistroModificado(IndiceRegistro, IndiceVariable-1, FrmCambiarMicrodato->GetValorNuevo());
      FrmCambiarMicrodato->hide();      
    }

    void TFmeImputacion::ButCancelarCambiarMicrodatoClick()
    {
       FrmCambiarMicrodato->hide();
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// HACER DOBLE CLICK SOBRE LA REJILLA DE REGISTRO.
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void TFmeImputacion::SgrRejillaRegistroDonanteDblClick(const QModelIndex& index)
    {      
      connect(FrmIrAVariable->GetButAplicar(), SIGNAL(clicked()), this, SLOT(ButAplicarIrAVariableClick()));
      connect(FrmIrAVariable->GetButCancelar(), SIGNAL(clicked()), this, SLOT(ButCancelarIrAVariableClick()));
      FrmIrAVariable->show();
    }
    void TFmeImputacion::ButAplicarIrAVariableClick()
    {
      unsigned IndiceVariable;

      if (FrmIrAVariable->GetRbnombre()->isChecked())
        IndiceVariable = FrmIrAVariable->GetCbxPorNombre()->currentIndex();
      else
        IndiceVariable = FrmIrAVariable->GetCbxPorNumero()->currentIndex();

      FrmIrAVariable->hide();

      view3->setCurrentIndex(view3->indexAt(QPoint(view3->columnViewportPosition(IndiceVariable), view3->rowViewportPosition(0))));
      view3->selectColumn(IndiceVariable);//view3->clearSelection();
      view3->setFocus();      
    }
    void TFmeImputacion::ButCancelarIrAVariableClick()
    {
      FrmIrAVariable->hide();
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// CAMBIAR EL DESPLAZADOR DE REGISTROS DONANTES.
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void TFmeImputacion::UpdRegistroDonanteClick_sig()
    {
      if (posicion != NRD -1) posicion++;
      ActualizarInformacionRegistroDonante(view->currentIndex().row(), posicion);
    }
    void TFmeImputacion::UpdRegistroDonanteClick_ant()
    {
      if (posicion != 0) posicion--;
      ActualizarInformacionRegistroDonante(view->currentIndex().row(), posicion);
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// PINCHAR LA OPCION DE MENU DE SALVAR MICRODATOS A FICHERO.
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void TFmeImputacion::MitSalvarMicrodatosFicheroClick()
    {
      QString start = QCoreApplication::applicationDirPath();
      QString meta = QDir::convertSeparators(start + "/" + DIRECTORIO_STATS + "/" + FICHERO_SALIDA_MICRODATOS + "_" + FmeVariablesAsociadas->GetNombreConjunto() + "_OUT");
      QString NombreFichero = QFileDialog::getSaveFileName(this, tr("Guardar fichero"), meta, "TXT (*.txt)");
      if (NombreFichero == "")
        QMessageBox::warning(this, "Warning",  tr("No ha introducido ningun fichero"), "&Ok");
      else  {
        SalvarMicrodatosEnFichero(NombreFichero);
      }
    }
    void TFmeImputacion::VisualizarMenu(const QModelIndex& )
    {
      if (view->boton())
        menu->popup(QCursor::pos());
    }
    void TFmeImputacion::VisualizarInforRegIncorrecto(const int& )
    {
      int Fila = listaV.indexOf(model->headerData(view->currentIndex().row(), Qt::Vertical, Qt::DisplayRole).toString());
      if (!view->boton()) {
        if (RegistroIncorrecto(Fila)) {
          QScrollArea *scrollArea2 = scrollArea1;
          scrollArea1 = new QScrollArea(0);
          scrollArea1->setWindowTitle("Reg. " + QString::number(Fila+1, 10));
          scrollArea1->setBackgroundRole(QPalette::Light);
          scrollArea1->setWidget(menu2);
          menu2->clear();
          ObtenerInforRegIncorrecto(Fila);
          menu2->popup(QCursor::pos());
          scrollArea1->show();
          menu2->setDisabled(true);
          delete scrollArea2;
        }
      }
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// PINCHAR LA OPCION DE MENU DE SALVAR MICRODATOS A BBDD.
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void TFmeImputacion::MitSalvarMicrodatosBBDDClick()
    {
	FrmEntradaDatos = new TFrmEntradaDatos(this, "entradadatos", Qt::Widget);
        FrmEntradaDatos->FijarEtiqueta1(tr("Introduzca el nombre base de la tabla"));
        FrmEntradaDatos->FijarEntrada1(FmeMicroDatosAsociados->GetNombreConjunto());
        QObject::connect(FrmEntradaDatos->ButAceptar, SIGNAL(clicked()), this, SLOT(ButAceptarEntradaDatosClick()));
        QObject::connect(FrmEntradaDatos->ButCancelar, SIGNAL(clicked()), this, SLOT(ButCancelarEntradaDatosClick()));

        FrmEntradaDatos->show();	
    }
    void TFmeImputacion::ButAceptarEntradaDatosClick()
    {
      FrmEntradaDatos->hide();
      SalvarMicrodatosEnBBDD(FrmEntradaDatos->GetEntrada1());      
    }

    void TFmeImputacion::ButCancelarEntradaDatosClick()
    {
      FrmEntradaDatos->hide();
    }

    void TFmeImputacion::MitAumentarColumnasClick()
    {
	FijarAnchoColumnasRejilla(view->columnWidth (1) + 50);
    }

    void TFmeImputacion::MitDisminuirColumnasClick()
    {
	FijarAnchoColumnasRejilla(view->columnWidth (1) - 50);
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// PINCHAR SOBRE EL MODO DE VISUALIZAR REGISTROS.
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void TFmeImputacion::VisualizarRegCloseUp(int index)
    {
      if (index == 0) {
           delete model;
           model = new TablaModelI(0, MatrizMicroDatosS, listaH, listaV, FmeMicroDatosAsociados);
           view->setModel(model);
           CbxIrARegistroPorNombre->clear();
           CbxIrARegistroPorNombre->addItems(listaV);
           PanRegistroDonante->setEnabled(true);
           MostrarInfoAsociada(0, 1, NumRegistros, true);
           EscribirInformacion();
      }else
          if (index == 1) {            
            cargarmodelo1(NumRegistrosCorrectos+NumRegistrosDonantes, ConjuntoRegistrosIncorrectos);
            model->setCurrencyMap(MatrizMicroDatosSelec);   // cuando modifiquemos la matriz
            model->setCurrencyCabec(listaVSelec);   // cuando modifiquemos la cabecera vertical
            CbxIrARegistroPorNombre->clear();
            CbxIrARegistroPorNombre->addItems(listaVSelec);
            PanRegistroDonante->setEnabled(false);
            MostrarInfoAsociada(0, 1, NumRegistrosCorrectos+NumRegistrosDonantes, true);
            EscribirInformacion();
          }else
            if (index == 2) {                
                cargarmodelo23(NumRegistrosIncorrectos, ConjuntoRegistrosIncorrectos);                
                model->setCurrencyMap(MatrizMicroDatosSelec);   // cuando modifiquemos la matriz
                model->setCurrencyCabec(listaVSelec);   // cuando modifiquemos la cabecera vertical
                CbxIrARegistroPorNombre->clear();
                CbxIrARegistroPorNombre->addItems(listaVSelec);
                PanRegistroDonante->setEnabled(false);
                MostrarInfoAsociada(0, 1, NumRegistrosIncorrectos, true);
                EscribirInformacion();
            }else
                if (index == 3) {                  
                  cargarmodelo23(NumRegistrosWarning, ConjuntoRegistrosWarning);                  
                  model->setCurrencyMap(MatrizMicroDatosSelec);   // cuando modifiquemos la matriz
                  model->setCurrencyCabec(listaVSelec);   // cuando modifiquemos la cabecera vertical
                  CbxIrARegistroPorNombre->clear();
                  CbxIrARegistroPorNombre->addItems(listaVSelec);
                  MostrarInfoAsociada(0, 1, NumRegistrosWarning, true);
                  EscribirInformacion();
                }else
                  if (index == 4) {
                    NumRegistrosSelec = 0;
                    wpedexp = new TFrmPedirExpresion(0, "pedirexp", Qt::Widget);
                    QObject::connect(wpedexp->ButAceptar, SIGNAL(clicked()), this, SLOT(ButAceptarPedirExpresionClick()));
                    QObject::connect(wpedexp->ButCancelar, SIGNAL(clicked()), this, SLOT(ButCancelarPedirExpresionClick()));
                    wpedexp->show();
                  }
       repintar();
    }
    void TFmeImputacion::cargarmodelo1(unsigned numreg, QSet<unsigned> ConjuntoRegistros)
    {

      MatrizMicroDatosSelec = new QString*[numreg];
      listaVSelec.clear();
      int i, j;
      int k = 0;
      for (i = 0; i < NumRegistros; i++) {
          if (!ConjuntoRegistros.contains(i)) {
            MatrizMicroDatosSelec[k] = new QString[NumVariables];
            for (j = 0; j < NumVariables; j++)  MatrizMicroDatosSelec[k][j] = MatrizMicroDatosS[i][j];
            listaVSelec.append(ListaIds->at(i));
            k++;
          }
      }
    }
    void TFmeImputacion::cargarmodelo23(unsigned numreg, QSet<unsigned> ConjuntoRegistros)
    {      
      MatrizMicroDatosSelec = new QString*[numreg];
      listaVSelec.clear();
      int i, j;
      int k = 0;
      for (i = 0; i < NumRegistros; i++) {
          if (ConjuntoRegistros.contains(i)) {
            MatrizMicroDatosSelec[k] = new QString[NumVariables];
            for (j = 0; j < NumVariables; j++)  MatrizMicroDatosSelec[k][j] = MatrizMicroDatosS[i][j];
            listaVSelec.append(ListaIds->at(i));
            k++;
          }
      }
    }
    void TFmeImputacion::cargarmodelo4(QString exp)
    {
      QMap <QString, double> * mapp;
      QMap<QString,double> mappM;
      MatrizMicroDatosSelec = new QString*[NumRegistros];
      listaVSelec.clear();
      int k = 0;
      for (int i = 0; i < NumRegistros; i++) {
           mapp = FmeMicroDatosAsociados->GetMapRegistro(i);
           mappM = FmeVariablesAsociadas->GetMapMissing();
           switch (EvaluarExpresion((char*)exp.toLatin1().data(), mapp, &mappM))
           {
                case ERROR_SINTACTICO: QMessageBox::information(0, QApplication::translate("", "Informaci\303\263n", 0, QApplication::UnicodeUTF8), QApplication::translate("", "Error Sint\303\241ctico", 0, QApplication::UnicodeUTF8), QMessageBox::Ok, QMessageBox::NoButton);
                                       i = NumRegistros;
                                       break;
                case ERROR_LEXICO: QMessageBox::information(0, QApplication::translate("", "Informaci\303\263n", 0, QApplication::UnicodeUTF8), QApplication::translate("", "Error L\303\251xico", 0, QApplication::UnicodeUTF8), QMessageBox::Ok, QMessageBox::NoButton);
                                   i = NumRegistros;
                                   break;
                case ERROR_SINTACTICO_Y_LEXICO: QMessageBox::information(0, QApplication::translate("", "Informaci\303\263n", 0, QApplication::UnicodeUTF8), QApplication::translate("", "Error Sint\303\241ctico y L\303\251xico", 0, QApplication::UnicodeUTF8), QMessageBox::Ok, QMessageBox::NoButton);
                                                i = NumRegistros;
                                                break;
                case VERDADERO: MatrizMicroDatosSelec[k] = new QString[NumVariables];
                                for (int j = 0; j < NumVariables; j++)  MatrizMicroDatosSelec[k][j] = MatrizMicroDatosS[i][j];
                                listaVSelec.append(ListaIds->at(i));
                                NumRegistrosSelec++;
                                k++;
                                break;
                default: break;
           }
      }
      //poner una condicion para q solo entre cuando no hay error
      if (NumRegistrosSelec == 0) {
          QMessageBox::information(0, QApplication::translate("", "Informaci\303\263n", 0, QApplication::UnicodeUTF8), QApplication::translate("", "No se han encontrado registros", 0, QApplication::UnicodeUTF8), QMessageBox::Ok, QMessageBox::NoButton);
          VisualizarReg->setCurrentIndex(0);
      }else {
        delete model;
        model = new TablaModelI(0, MatrizMicroDatosSelec, listaH, listaVSelec, FmeMicroDatosAsociados);
        view->setModel(model);
        CbxIrARegistroPorNombre->clear();
        CbxIrARegistroPorNombre->addItems(listaVSelec);
        PanRegistroDonante->setEnabled(false);
        MostrarInfoAsociada(0, 1, NumRegistrosSelec, true);
        EscribirInformacion();
        repintar();
      }
    }
    void TFmeImputacion::ButAceptarPedirExpresionClick()
    {
      if (wpedexp->getExpresion() == "")
        QMessageBox::warning(this, "Warning",  QApplication::translate("", "No ha introducido ninguna expresi\303\263n", 0, QApplication::UnicodeUTF8), "&Ok");
      else {
        wpedexp->hide();
        cargarmodelo4(wpedexp->getExpresion());
      }
    }

    void TFmeImputacion::ButCancelarPedirExpresionClick()
    {
      wpedexp->hide();
    }
