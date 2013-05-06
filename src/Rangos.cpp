/*******************************************************************************
** Rangos.cpp: contiene todo lo necesario para trabajar con la solapa
**             Eval. rangos y filtros.
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

#include "Rangos.h"


TFmeRangos::TFmeRangos(QWidget* parent, const char* name, Qt::WindowFlags fl, TFmeEdits *FmeEditsAsociados, TFrmIrAVariable *FrmIrAVariable, TFrmCambiarMicrodato *FrmCambiarMicrodato, TFrmOpciones *FrmOpciones, QTabWidget *Frmprincipal, QStringList *ListaIds)
    {
      QString s, s1;

      setGeometry(0, 0, parent->width()-2, parent->height()-15);

      if (this->objectName().isEmpty())
        this->setObjectName(("TFmeRangos"));
      QFont font;
      font.setFamily(("Tahoma"));
      this->setFont(font);
      PanContenedor = new QFrame(this);
      PanContenedor->setObjectName(("PanContenedor"));
      PanContenedor->setGeometry(QRect(0, 0, this->width(), this->height()-50));
      PanContenedor->setFrameShape(QFrame::Panel);
      PanContenedor->setFrameShadow(QFrame::Raised);
      VisualizarReg = new QComboBox(Frmprincipal);
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
      LabSbrBarraEstado1 = new QLabel(SbrBarraEstado1);
      LabSbrBarraEstado1->setObjectName(("LabSbrBarraEstado1"));
      LabSbrBarraEstado1->setGeometry(QRect(0, 0, SbrBarraEstado1->width(), 19));
      SbrBarraEstado2 = new QFrame(SbrBarraEstado);
      SbrBarraEstado2->setObjectName(("SbrBarraEstado2"));
      SbrBarraEstado2->setGeometry(QRect(SbrBarraEstado1->width()+1, 0, SbrBarraEstado1->width()-1, 19));
      SbrBarraEstado2->setFrameShape(QFrame::Box);
      SbrBarraEstado2->setFrameShadow(QFrame::Raised);
      LabSbrBarraEstado2 = new QLabel(SbrBarraEstado2);
      LabSbrBarraEstado2->setObjectName(("LabSbrBarraEstado2"));
      LabSbrBarraEstado2->setGeometry(QRect(3, 0, SbrBarraEstado2->width(), 19));
      PanSalvarPorcentajesError = new QFrame(PanContenedor);
      PanSalvarPorcentajesError->setObjectName(("PanSalvarPorcentajesError"));
      PanSalvarPorcentajesError->setGeometry(QRect(1, 0, PanContenedor->width()-1, 41));
      PanSalvarPorcentajesError->setFrameShape(QFrame::Box);
      PanSalvarPorcentajesError->setFrameShadow(QFrame::Raised);
      LabUmbralErrorVariables = new QLabel(PanSalvarPorcentajesError);
      LabUmbralErrorVariables->setObjectName(("LabUmbralErrorVariables"));
      LabUmbralErrorVariables->setGeometry(QRect(310, 13, 161, 18));
      Label1 = new QLabel(PanSalvarPorcentajesError);
      Label1->setObjectName(("Label1"));
      Label1->setGeometry(QRect(520, 13, 15, 18));
      LabUmbralErrorRegistros = new QLabel(PanSalvarPorcentajesError);
      LabUmbralErrorRegistros->setObjectName(("LabUmbralErrorRegistros"));
      LabUmbralErrorRegistros->setGeometry(QRect(580, 13, 156, 18));
      Label3 = new QLabel(PanSalvarPorcentajesError);
      Label3->setObjectName(("Label3"));
      Label3->setGeometry(QRect(790, 13, 15, 18));
      ButSalvarErrorVariables = new QPushButton(PanSalvarPorcentajesError);
      ButSalvarErrorVariables->setObjectName(("ButSalvarErrorVariables"));
      ButSalvarErrorVariables->setGeometry(QRect(8, 8, 261, 25));
      ButSalvarErrorRegistros = new QPushButton(PanSalvarPorcentajesError);
      ButSalvarErrorRegistros->setObjectName(("ButSalvarErrorRegistros"));
      ButSalvarErrorRegistros->setGeometry(QRect(821, 8, 238, 25));
      EdtUmbralErrorVariables = new QSpinBox(PanSalvarPorcentajesError);
      EdtUmbralErrorVariables->setObjectName(("EdtUmbralErrorVariables"));
      EdtUmbralErrorVariables->setGeometry(QRect(470, 10, 43, 23));
      EdtUmbralErrorVariables->setSingleStep(5);
      EdtUmbralErrorRegistros = new QSpinBox(PanSalvarPorcentajesError);
      EdtUmbralErrorRegistros->setObjectName(("EdtUmbralErrorRegistros"));
      EdtUmbralErrorRegistros->setGeometry(QRect(740, 10, 43, 23));
      EdtUmbralErrorRegistros->setSingleStep(5);
      PanInfo = new QFrame(PanContenedor);
      PanInfo->setObjectName(("PanInfo"));
      PanInfo->setGeometry(QRect(1, SbrBarraEstado->y()-2-43, PanContenedor->width()-1, 43));
      PanInfo->setFrameShape(QFrame::Box);
      PanInfo->setFrameShadow(QFrame::Raised);

      SbrBarraNum = new QFrame(PanInfo);
      SbrBarraNum->setObjectName(("SbrBarraNum"));
      SbrBarraNum->setGeometry(QRect(825, 0, PanContenedor->width()-400, 43));
      SbrBarraNum->setFrameShape(QFrame::Box);
      SbrBarraNum->setFrameShadow(QFrame::Raised);
      LabNumFiltrosVariable = new QLabel(SbrBarraNum);
      LabNumFiltrosVariable->setObjectName(("LabNumFiltrosVariable"));
      LabNumFiltrosVariable->setGeometry(QRect(8, 12, 141, 18));
      EdtNumFiltrosVariable = new QLineEdit(SbrBarraNum);
      EdtNumFiltrosVariable->setObjectName(("EdtNumFiltrosVariable"));
      EdtNumFiltrosVariable->setGeometry(QRect(150, 9, 41, 23));
      EdtNumFiltrosVariable->setReadOnly(true);
      QPalette palette( QApplication::palette() );
      palette.setColor( QPalette::Active, QPalette::Base, Qt::gray );
      EdtNumFiltrosVariable->setPalette(palette);
      LabNumEditsVariable = new QLabel(SbrBarraNum);
      LabNumEditsVariable->setObjectName(("LabNumEditsVariable"));
      LabNumEditsVariable->setGeometry(QRect(205, 12, 154, 18));
      EdtNumEditsVariable = new QLineEdit(SbrBarraNum);
      EdtNumEditsVariable->setObjectName(("EdtNumEditsVariable"));
      EdtNumEditsVariable->setGeometry(QRect(360, 9, 41, 23));
      EdtNumEditsVariable->setReadOnly(true);
      EdtNumEditsVariable->setPalette(palette);

      LabIrARegistroPorNumero = new QLabel(PanInfo);
      LabIrARegistroPorNumero->setObjectName(("LabIrARegistroPorNumero"));
      LabIrARegistroPorNumero->setGeometry(QRect(1, 12, 90, 18));
      EdtIrARegistroPorNumero = new QLineEdit(PanInfo);
      EdtIrARegistroPorNumero->setObjectName(("EdtIrARegistroPorNumero"));
      EdtIrARegistroPorNumero->setGeometry(QRect(92, 9, 33, 23));

      LabIrARegistroPorNombre = new QLabel(PanInfo);
      LabIrARegistroPorNombre->setObjectName(("LabIrARegistroPorNumero"));
      LabIrARegistroPorNombre->setGeometry(QRect(143, 12, 90, 18));
      CbxIrARegistroPorNombre = new QComboBox(PanInfo);
      CbxIrARegistroPorNombre->setObjectName(("CbxIrARegistroPorNombre"));
      CbxIrARegistroPorNombre->setGeometry(QRect(238, 9, 145, 23));
      CbxIrARegistroPorNombre->setEditable(true);

      LabIrAVariablePorNombre = new QLabel(PanInfo);
      LabIrAVariablePorNombre->setObjectName(("LabIrAVariablePorNombre"));
      LabIrAVariablePorNombre->setGeometry(QRect(570, 12, 115, 18));
      CbxIrAVariablePorNombre = new QComboBox(PanInfo);
      CbxIrAVariablePorNombre->setObjectName(("CbxIrAVariablePorNombre"));
      CbxIrAVariablePorNombre->setGeometry(QRect(670, 9, 145, 23));
      CbxIrAVariablePorNombre->setEditable(true);

      LabIrAVariablePorNumero = new QLabel(PanInfo);
      LabIrAVariablePorNumero->setObjectName(("LabIrAVariablePorNumero"));
      LabIrAVariablePorNumero->setGeometry(QRect(410, 12, 115, 18));
      EdtIrAVariablePorNumero = new QLineEdit(PanInfo);
      EdtIrAVariablePorNumero->setObjectName(("EdtIrAVariablePorNumero"));
      EdtIrAVariablePorNumero->setGeometry(QRect(510, 10, 33, 23));

      view3 = new MiTabla(PanContenedor);
      view3->setGeometry(QRect(1, PanInfo->y()-2-65, PanContenedor->width()-1, 65));
      view2 = new MiTabla(PanContenedor);
      view2->setGeometry(QRect(1, view3->y()-2-65, PanContenedor->width()-1, 65));
      GbxHistograma = new MiBox(PanContenedor, PanContenedor->width()-1, this);
      GbxHistograma->setObjectName(("GbxHistograma"));
      GbxHistograma->setGeometry(QRect(1, view2->y()-2-171, PanContenedor->width()-1, 171));

      SplSeparador = new QFrame(PanContenedor);
      SplSeparador->setObjectName(("SplSeparador"));
      SplSeparador->setGeometry(QRect(1, GbxHistograma->y()-1-5, PanContenedor->width()-1, 5));
      SplSeparador->setFrameShape(QFrame::HLine);
      SplSeparador->setFrameShadow(QFrame::Raised);
      SplSeparador->setLineWidth(5);
      QPalette *pal = new QPalette();
      pal->setColor(QPalette::Base, Qt::blue);
      SplSeparador->setPalette(*pal);
      PanExclusion = new QFrame(PanContenedor);
      PanExclusion->setObjectName(("PanExclusion"));
      PanExclusion->setGeometry(QRect(1, SplSeparador->y()-1-30, PanContenedor->width()-1, 30));
      PanExclusion->setFrameShape(QFrame::Box);
      PanExclusion->setFrameShadow(QFrame::Raised);
      LabExclusionRegistros = new QLabel(PanExclusion);
      LabExclusionRegistros->setObjectName(("LabExclusionRegistros"));
      LabExclusionRegistros->setGeometry(QRect(8, 8, 319, 18));
      EdtExclusionRegistros = new QLineEdit(PanExclusion);
      EdtExclusionRegistros->setObjectName(("EdtExclusionRegistros"));
      EdtExclusionRegistros->setGeometry(QRect(335, 4, 41, 23));
      LabExclusionVariables = new QLabel(PanExclusion);
      LabExclusionVariables->setObjectName(("LabExclusionVariables"));
      LabExclusionVariables->setGeometry(QRect(400, 8, 315, 18));
      EdtExclusionVariables = new QLineEdit(PanExclusion);
      EdtExclusionVariables->setObjectName(("EdtExclusionVariables"));
      EdtExclusionVariables->setGeometry(QRect(720, 4, 41, 23));
      ButAplicarExclusion = new QPushButton(PanExclusion);
      ButAplicarExclusion->setObjectName(("ButAplicarExclusion"));
      ButAplicarExclusion->setGeometry(QRect(800, 5, 240, 21));

      view = new MiTabla(PanContenedor);
      view->setGeometry(QRect(1, 42, PanContenedor->width()-1, PanExclusion->y()-2-42));
      view->verticalHeader()->setDefaultSectionSize(21);

      PanProgreso = new QLineEdit(this);
      PanProgreso->setObjectName(("PanProgreso"));
      PanProgreso->setGeometry(QRect(0, 0, this->width(), 90));

      QColor color2 = Qt::green;
      color2.setRgb(0, 218, 160);
      color2.setHsv (164, 255, 218);
      palette.setColor( QPalette::Active, QPalette::Base, color2 );
      PanProgreso->setPalette(palette);
      LabProgreso = new QLabel(PanProgreso);
      LabProgreso->setObjectName(("LabProgreso"));
      LabProgreso->setGeometry(QRect(8, 52, 163, 18));
      LabOperacion = new QLabel(PanProgreso);
      LabOperacion->setObjectName(("LabOperacion"));
      LabOperacion->setGeometry(QRect(8, 8, 141, 18));
      LabPorcentaje = new QLabel(PanProgreso);
      LabPorcentaje->setObjectName(("LabPorcentaje"));
      LabPorcentaje->setGeometry(QRect(368, 8, 92, 18));
      LabElemento = new QLabel(PanProgreso);
      LabElemento->setObjectName(("LabElemento"));
      LabElemento->setGeometry(QRect(483, 8, 91, 18));
      palette.setColor( QPalette::Active, QPalette::Base, Qt::white );
      LabElemento->setPalette(palette);
      EdtOperacion = new QLineEdit(PanProgreso);
      EdtOperacion->setObjectName(("EdtOperacion"));
      EdtOperacion->setGeometry(QRect(8, 24, 345, 23));
      EdtOperacion->setReadOnly(true);
      EdtOperacion->setPalette(palette);
      PbrProgreso = new QProgressBar(PanProgreso);
      PbrProgreso->setObjectName(("PbrProgreso"));
      PbrProgreso->setGeometry(QRect(2, 73, PanProgreso->width()-2, 15));
      PbrProgreso->setValue(0);
      PbrProgreso->setTextVisible(false);
      EdtPorcentaje = new QLineEdit(PanProgreso);
      EdtPorcentaje->setObjectName(("EdtPorcentaje"));
      EdtPorcentaje->setGeometry(QRect(368, 24, 81, 23));
      EdtPorcentaje->setReadOnly(true);
      EdtPorcentaje->setPalette(palette);
      EdtElemento = new QLineEdit(PanProgreso);
      EdtElemento->setObjectName(("EdtElemento"));
      EdtElemento->setGeometry(QRect(478, 24, 91, 23));
      EdtElemento->setReadOnly(true);
      EdtElemento->setPalette(palette);

      menu = new QMenu( this);
      menu->addAction( QObject::tr("Copiar identificador de registro..."), this, SLOT(MitCopiarIdentificadorRegistroClick()));
      menu->addAction( QObject::tr("Copiar identificador de variable..."), this, SLOT(MitCopiarIdentificadorVariableClick()));
      menu->addSeparator();
      menu->addAction( QObject::tr("Aumentar el ancho de las columnas..."), this, SLOT(MitAumentarColumnasClick()));
      menu->addAction( QObject::tr("Disminuir el ancho de las columnas..."), this, SLOT(MitDisminuirColumnasClick()));

      this->setWindowTitle(QApplication::translate("TFmeRangos", "Form", 0, QApplication::UnicodeUTF8));
      view->setToolTip(QApplication::translate("TFmeRangos", "Rejilla de visualizaci\303\263n de los resultados de la evaluaci\303\263n.(ALT)", 0, QApplication::UnicodeUTF8));
      view->verticalHeader()->setToolTip(QApplication::translate("TFmeRangos", "ID registro || Total errores", 0, QApplication::UnicodeUTF8));
      view->horizontalHeader()->setToolTip(QApplication::translate("TFmeRangos", "Variables\nTotal errores", 0, QApplication::UnicodeUTF8));
      PanExclusion->setToolTip(QApplication::translate("TFmeRangos", "Panel de exclusi\303\263n.", 0, QApplication::UnicodeUTF8));
      LabExclusionRegistros->setText(QApplication::translate("TFmeRangos", "Excluir REGISTROS con n\303\272mero de errores mayor de ...", 0, QApplication::UnicodeUTF8));
      EdtExclusionRegistros->setToolTip(QApplication::translate("TFmeRangos", "Porcentaje de exclusi\303\263n por encima del cual se excluir\303\241n los registros que superen esta cifra.", 0, QApplication::UnicodeUTF8));
      EdtExclusionRegistros->setText(QApplication::translate("TFmeRangos", "0", 0, QApplication::UnicodeUTF8));
      LabExclusionVariables->setText(QApplication::translate("TFmeRangos", "Excluir VARIABLES con n\303\272mero de errores mayor de ...", 0, QApplication::UnicodeUTF8));
      EdtExclusionVariables->setToolTip(QApplication::translate("TFmeRangos", "Porcentaje de exclusion por encima del cual se excluir\303\241n las variables que superen esta cifra.", 0, QApplication::UnicodeUTF8));
      EdtExclusionVariables->setText(QApplication::translate("TFmeRangos", "0", 0, QApplication::UnicodeUTF8));
      ButAplicarExclusion->setToolTip(QApplication::translate("TFmeRangos", "Pulse aqu\303\255 para aplicar la exclusi\303\263n.", 0, QApplication::UnicodeUTF8));
      ButAplicarExclusion->setText(QApplication::translate("TFmeRangos", "Aplicar Exclusi\303\263n", 0, QApplication::UnicodeUTF8));
      view2->setToolTip(QApplication::translate("TFmeRangos", "Informaci\303\263n del registro activo.(CTRL)", 0, QApplication::UnicodeUTF8));
      view3->setToolTip(QApplication::translate("TFmeRangos", "Informaci\303\263n de la variable activa.", 0, QApplication::UnicodeUTF8));
      LabIrAVariablePorNombre->setText(QApplication::translate("TFmeRangos", "Ir a var. (nom)", 0, QApplication::UnicodeUTF8));
      LabIrARegistroPorNombre->setText(QApplication::translate("TFmeRangos", "Ir a reg. (nom)", 0, QApplication::UnicodeUTF8));
      LabIrAVariablePorNumero->setText(QApplication::translate("TFmeRangos", "Ir a var. (num)", 0, QApplication::UnicodeUTF8));
      LabIrARegistroPorNumero->setText(QApplication::translate("TFmeRangos", "Ir a reg. (num)", 0, QApplication::UnicodeUTF8));
      LabNumFiltrosVariable->setText(QApplication::translate("TFmeRangos", "Num. filtros con variable", 0, QApplication::UnicodeUTF8));
      LabNumEditsVariable->setText(QApplication::translate("TFmeRangos", "Num. reglas con variable", 0, QApplication::UnicodeUTF8));
      EdtIrARegistroPorNumero->setToolTip(QApplication::translate("TFmeRangos", "Indique un n\303\272mero de registro y pulse ENTER parar ir a \303\251l.", 0, QApplication::UnicodeUTF8));
      CbxIrAVariablePorNombre->setToolTip(QApplication::translate("TFmeRangos", "Seleccione la variable que desea visualizar.", 0, QApplication::UnicodeUTF8));
      CbxIrARegistroPorNombre->setToolTip(QApplication::translate("TFmeRangos", "Seleccione el registro que desea visualizar.", 0, QApplication::UnicodeUTF8));
      EdtIrAVariablePorNumero->setToolTip(QApplication::translate("TFmeRangos", "Indique un n\303\272mero de variable y pulse ENTER parar ir a ella.", 0, QApplication::UnicodeUTF8));
      EdtNumFiltrosVariable->setToolTip(QApplication::translate("TFmeRangos", "Numero de filtros en los que aparece esta variable.", 0, QApplication::UnicodeUTF8));
      EdtNumEditsVariable->setToolTip(QApplication::translate("TFmeRangos", "Numero de reglas en los que aparece esta variable.", 0, QApplication::UnicodeUTF8));
      LabSbrBarraEstado1->setText("");
      LabSbrBarraEstado2->setText("");
      LabUmbralErrorVariables->setText(QApplication::translate("TFmeRangos", "Porcentaje umbral de error", 0, QApplication::UnicodeUTF8));
      Label1->setText(QApplication::translate("TFmeRangos", "%", 0, QApplication::UnicodeUTF8));
      LabUmbralErrorRegistros->setText(QApplication::translate("TFmeRangos", "Porcentaje umbral de error", 0, QApplication::UnicodeUTF8));
      Label3->setText(QApplication::translate("TFmeRangos", "%", 0, QApplication::UnicodeUTF8));
      ButSalvarErrorVariables->setText(QApplication::translate("TFmeRangos", "Salvar porcentajes de error de variables", 0, QApplication::UnicodeUTF8));
      ButSalvarErrorVariables->setToolTip(QApplication::translate("TFmeRangos", "Salvar porcentajes de error de variables en fichero", 0, QApplication::UnicodeUTF8));
      ButSalvarErrorRegistros->setText(QApplication::translate("TFmeRangos", "Salvar porcentajes de error de registros", 0, QApplication::UnicodeUTF8));
      ButSalvarErrorRegistros->setToolTip(QApplication::translate("TFmeRangos", "Salvar porcentajes de error de registros en fichero", 0, QApplication::UnicodeUTF8));
      EdtUmbralErrorVariables->setToolTip(QApplication::translate("TFmeRangos", "Umbral para salvar variables con un porcentaje de error", 0, QApplication::UnicodeUTF8));
      EdtUmbralErrorRegistros->setToolTip(QApplication::translate("TFmeRangos", "Umbral para salvar registros con un porcentaje de error", 0, QApplication::UnicodeUTF8));
      LabProgreso->setText(QApplication::translate("TFmeRangos", "Progreso de la operaci\303\263n", 0, QApplication::UnicodeUTF8));
      LabOperacion->setText(QApplication::translate("TFmeRangos", "Operaci\303\263n en curso", 0, QApplication::UnicodeUTF8));
      LabPorcentaje->setText(QApplication::translate("TFmeRangos", "% completado", 0, QApplication::UnicodeUTF8));
      LabElemento->setText(QApplication::translate("TFmeRangos", "# completado", 0, QApplication::UnicodeUTF8));
      EdtOperacion->setToolTip(QApplication::translate("TFmeRangos", "Nombre de la operaci\303\263n que esta siendo ejecutada actualmente.", 0, QApplication::UnicodeUTF8));
      EdtOperacion->setText(QApplication::translate("TFmeRangos", "Evaluaci\303\263n de las reglas de rangos sobre los microdatos.", 0, QApplication::UnicodeUTF8));
      PbrProgreso->setToolTip(QApplication::translate("TFmeRangos", "Muestra del progreso de la operaci\303\263n.", 0, QApplication::UnicodeUTF8));
      EdtPorcentaje->setToolTip(QApplication::translate("TFmeRangos", "Porcentaje completado de la operaci\303\263n.", 0, QApplication::UnicodeUTF8));
      EdtElemento->setToolTip(QApplication::translate("TFmeRangos", "Elemento actual en proceso / N\303\272mero total de elementos a procesar", 0, QApplication::UnicodeUTF8));
      VisualizarReg->setToolTip(QApplication::translate("TFmeRangos", "Seleccione el modo de vizualizaci\303\263n de los registros.", 0, QApplication::UnicodeUTF8));
      VisualizarReg->addItem(QApplication::translate("TFmeRangos", "Visualizar todos", 0, QApplication::UnicodeUTF8));
      VisualizarReg->addItem(QApplication::translate("TFmeRangos", "Visualizar registros correctos", 0, QApplication::UnicodeUTF8));
      VisualizarReg->addItem(QApplication::translate("TFmeRangos", "Visualizar registros incorrectos", 0, QApplication::UnicodeUTF8));

      QObject::connect(view, SIGNAL(doubleClicked(const QModelIndex&)), this, SLOT(SgrRejillaDblClick(const QModelIndex&)));
      QObject::connect(view, SIGNAL(clicked(const QModelIndex&)), this, SLOT(SgrRejillaSelectCell(const QModelIndex&)));
      QObject::connect(view, SIGNAL(pressed ( const QModelIndex& )), this, SLOT(VisualizarMenu(const QModelIndex&)));
      QObject::connect(view->verticalHeader(), SIGNAL(sectionClicked ( const int & )), this, SLOT(SgrRejillaSelectCellV(const int &)));
      QObject::connect(view->horizontalHeader(), SIGNAL(sectionClicked ( const int & )), this, SLOT(SgrRejillaSelectCellH(const int &)));

      QObject::connect(view2, SIGNAL(doubleClicked(const QModelIndex&)), this, SLOT(SgrRejillaRegistroDblClick(const QModelIndex&)));
      QObject::connect(view3, SIGNAL(doubleClicked(const QModelIndex&)), this, SLOT(SgrRejillaVariableDblClick(const QModelIndex&)));
      QObject::connect(EdtIrARegistroPorNumero, SIGNAL(returnPressed()), this, SLOT(EdtIrARegistroPorNumeroKeyDown()));
      QObject::connect(CbxIrAVariablePorNombre, SIGNAL(activated ( const int & )), this, SLOT(CbxIrAVariablePorNombreCloseUp(const int &)));
      QObject::connect(CbxIrARegistroPorNombre, SIGNAL(activated ( const int & )), this, SLOT(CbxIrARegistroPorNombreCloseUp(const int &)));
      QObject::connect(EdtIrAVariablePorNumero, SIGNAL(returnPressed()), this, SLOT(EdtIrAVariablePorNumeroKeyDown()));
      QObject::connect(ButSalvarErrorVariables, SIGNAL(clicked()), this, SLOT(ButSalvarErrorVariablesClick()));
      QObject::connect(ButSalvarErrorRegistros, SIGNAL(clicked()), this, SLOT(ButSalvarErrorRegistrosClick()));
      QObject::connect(ButAplicarExclusion, SIGNAL(clicked()), this, SLOT(ButAplicarExclusionClick()));
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
      QAction *RejCZ = new QAction(view);
      RejCZ->setShortcut(Qt::CTRL + Qt::Key_Z);
      QObject::connect(RejCZ, SIGNAL(triggered()), this, SLOT(SgrRejillaKeyDownCZ()));
      view->addAction(RejCZ);

      QAction *RegCR = new QAction(view2);
      RegCR->setShortcut(Qt::CTRL + Qt::Key_Right);
      QObject::connect(RegCR, SIGNAL(triggered()), this, SLOT(SgrRejillaRegKeyDownCR()));
      view2->addAction(RegCR);
      QAction *RegCL = new QAction(view2);
      RegCL->setShortcut(Qt::CTRL + Qt::Key_Left);
      QObject::connect(RegCL, SIGNAL(triggered()), this, SLOT(SgrRejillaRegKeyDownCL()));
      view2->addAction(RegCL);

      QMetaObject::connectSlotsByName(this);

      Cargado = false;
      rejillaregistro = false;
      // Asociar las clases
      AsociarClases(FmeEditsAsociados);
      this->FrmIrAVariable = FrmIrAVariable;
      this->FrmCambiarMicrodato = FrmCambiarMicrodato;      
      this->FrmOpciones = FrmOpciones;
      this->principal = Frmprincipal;
      MemLogs->append(QApplication::translate("", "Creando la clase de evaluaci\303\263n de reglas de rango", 0, QApplication::UnicodeUTF8));
      QApplication::processEvents();

      //MemLogs->append("num " + QString::number(ListaIds->size(), 10));


      //QApplication::processEvents();

      // Fijamos un nombre
      this->Name = "FmeRangos" + FmeMicroDatosAsociados->GetNombreTabla();

      // Fijar la cantidad de datos
      FijarCantidadDatos();

      // Fijar la lista de variables
      this->ListaIds = ListaIds;
      ListaVariables = FmeVariablesAsociadas->GetListaVariables();


      // Inicializar la matriz de test  y la matriz de test de filtros
      InicializarMatrizTest();      
      //MemLogs->append("q pasa2");QApplication::processEvents();
      //MemLogs->append("numR reg "+QString::number(NumRegistros,10));
      QApplication::processEvents();
      // Inicializar los vectores totales
      InicializarVectoresTotales();

      // Inicializar los vectores de exclusion
      InicializarVectoresExclusion();
//MemLogs->append("q pasa3");QApplication::processEvents();
      // Cargar las variables y los registro en la lista de seleccion
      CargarEnLista();
 //MemLogs->append("q pasa4");QApplication::processEvents();
      // Inicializar las rejillas      
      InicializarRejilla();
//MemLogs->append("q pasa5");QApplication::processEvents();
      InicializarRejillaRegistro();
      model2 = new TablaModelInfoR(0, VectorDatosR, listaH2, listaV2);
      view2->setModel(model2);

      InicializarRejillaVariable();
      model3 = new TablaModelInfoR(0, VectorDatosV, listaH3, listaV3);
      view3->setModel(model3);      

      // Creamos el modelo y lo asignamos a la vista
      model = new TablaModelR(0, MatrizTestS, listaH, listaV);
      view->setModel(model);     
      
      ModificacionMicrodato = false;

      // Inicializar los cuadros de exlusion colocando en ellos el numero de errores por defecto
      InicializarCuadrosExclusion();

      FrmIrAVariable = new TFrmIrAVariable(this, "iravariable", Qt::Widget, ListaVariables);
    } 
    void TFmeRangos::ajustarSize()
    {
        setGeometry(0, 0, parentWidget()->width()-2, parentWidget()->height()-15);

        PanContenedor->setGeometry(QRect(0, 0, this->width(), this->height()-50));

        VisualizarReg->setGeometry(PanContenedor->width()-220, 0, 200, 25);

        SbrBarraEstado->setGeometry(QRect(1, PanContenedor->height()-2-22, PanContenedor->width()-1, 22));

        SbrBarraEstado1->setGeometry(QRect(0, 0, SbrBarraEstado->width()/2, 19));

        LabSbrBarraEstado1->setGeometry(QRect(0, 0, SbrBarraEstado1->width(), 19));

        SbrBarraEstado2->setGeometry(QRect(SbrBarraEstado1->width()+1, 0, SbrBarraEstado1->width()-1, 19));

        LabSbrBarraEstado2->setGeometry(QRect(3, 0, SbrBarraEstado2->width(), 19));

        PanSalvarPorcentajesError->setGeometry(QRect(1, 0, PanContenedor->width()-1, 41));

        PanInfo->setGeometry(QRect(1, SbrBarraEstado->y()-2-43, PanContenedor->width()-1, 43));

        SbrBarraNum->setGeometry(QRect(825, 0, PanContenedor->width()-400, 43));

        view3->setGeometry(QRect(1, PanInfo->y()-2-65, PanContenedor->width()-1, 65));

        view2->setGeometry(QRect(1, view3->y()-2-65, PanContenedor->width()-1, 65));

        GbxHistograma->setGeometry(QRect(1, view2->y()-2-171, PanContenedor->width()-1, 171));

        SplSeparador->setGeometry(QRect(1, GbxHistograma->y()-1-5, PanContenedor->width()-1, 5));

        PanExclusion->setGeometry(QRect(1, SplSeparador->y()-1-30, PanContenedor->width()-1, 30));

        view->setGeometry(QRect(1, 42, PanContenedor->width()-1, PanExclusion->y()-2-42));
    }

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Asociar las clases provenientes de etapas anteriores.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void TFmeRangos::AsociarClases(TFmeEdits *FmeEditsAsociados)
    {
      this->FmeEditsAsociados = FmeEditsAsociados;
      this->FmeMicroDatosAsociados = FmeEditsAsociados->GetMicroDatosAsociados();
      this->FmeVariablesAsociadas = FmeMicroDatosAsociados->GetVariablesAsociadas();
      this->MemLogs = FmeVariablesAsociadas->GetMemLogs();
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Actualizar los umbrales de errores de exclusion.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void TFmeRangos::ActualizarUmbralExclusion()
    {
      //try
      //{
        UmbralExclusionRegistros = (unsigned)EdtExclusionRegistros->text().toInt();
      /*}
      catch(...)
      {
        UmbralExclusionRegistros = (unsigned)(PORCENTAJE_INICIAL_EXCLUSION_REG_RANGOS * NumVariables);
      }*/

      //try
      //{
        UmbralExclusionVariables = (unsigned)EdtExclusionVariables->text().toInt();
      /*}
      catch(...)
      {
        UmbralExclusionVariables = (unsigned)(PORCENTAJE_INICIAL_EXCLUSION_VARIABLES * NumRegistros);
      }*/

      if (UmbralExclusionRegistros > NumVariables)
        UmbralExclusionRegistros = (unsigned)(PORCENTAJE_INICIAL_EXCLUSION_REG_RANGOS * NumVariables);

      if (UmbralExclusionVariables > NumRegistros)
        UmbralExclusionVariables = (unsigned)(PORCENTAJE_INICIAL_EXCLUSION_VARIABLES * NumRegistros);

      EdtExclusionRegistros->setText(QString::number(UmbralExclusionRegistros, 10));
      EdtExclusionVariables->setText(QString::number(UmbralExclusionVariables, 10));
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Aplicar los porcentajes de exclusion y recalcular los resultados.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void TFmeRangos::AplicarExclusion()
    {
      CrearCopiaVectoresTotales();
      ResetearVectoresExclusion();
      ResetearListasExclusion();

      ExcluirRegistrosAPriori();
      ExcluirVariablesAPriori();
      ExcluirRegistros();
      ExcluirVariables();

      CalcularNumRegistrosCorrectos();
      CalcularNumVariablesCorrectas();
      CalcularNumResumen();
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Actualizar la evaluacion y toda la interface despues de haber modificado un microdato concreto.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void TFmeRangos::ActualizarInterfaceMicrodatoCambiado(unsigned IndiceRegistro, unsigned IndiceVariable, double Valor)
    {
      unsigned j;
      //bool ExReg = false;
      bool RegOK_0, RegOK_1;

      RegOK_0 = RegistroCorrecto(IndiceRegistro);

      FmeMicroDatosAsociados->ModificarMicrodato(IndiceRegistro, IndiceVariable, Valor);

      for (j = 0; j < (unsigned)NumVariables; j++)
        VectorDatosR[j] = FmeMicroDatosAsociados->GetValorS(IndiceRegistro, j);        
      model2->setCurrencyMap(VectorDatosR);

      if (ActualizarEvaluacionRegistro(IndiceRegistro, true))        
        ;

      // Copia de los vectores originales
	  for (j = 0; j < NumVariables; j++){
        VectorTotalesPorColumnas[j] = VectorTotalesPorColumnasOriginal[j];
	  }
      VectorTotalesPorFilas[IndiceRegistro] = VectorTotalesPorFilasOriginal[IndiceRegistro];
      model->setVectorTotalesPorFilas(VectorTotalesPorFilas);   // repinta el color azul claro

      // actualizar las interfaces de usuario
      CargarTestRegistroEnRejilla(IndiceRegistro);

      CargarResultadosRegistro(IndiceRegistro);

      for (j = 0; j < NumVariables; j++)
      {        
        CargarResultadosVariable(j);
      }
      model->setCurrencyCabec(listaH, listaV);
      RegOK_1 = RegistroCorrecto(IndiceRegistro);

      // calcular numeros de resumen
      if (RegOK_0 && !RegOK_1)
        NumRegistrosCorrectos--;
      else
        if (!RegOK_0 && RegOK_1)
          NumRegistrosCorrectos++;

      CalcularNumVariablesCorrectas();

      CalcularNumResumen();      
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Actualizar los datos de la evaluacion del registro.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    bool TFmeRangos::EvaluacionEditRegistro(unsigned IndiceRegistro, unsigned IndiceEdit) { return MatrizTest[IndiceRegistro][IndiceEdit]; }
    bool TFmeRangos::EvaluacionFiltroRegistro(unsigned IndiceRegistro, unsigned IndiceEdit) { return MatrizTestFiltro[IndiceRegistro][IndiceEdit]; }
    bool TFmeRangos::EstaCargado() { return Cargado; }
    bool TFmeRangos::FiltroExcluido(unsigned IndiceVariable) { return VectorExclusionFiltros[IndiceVariable]; }
    double TFmeRangos::GetPorcentajeErrorVariable(unsigned IndiceVariable) { return ((double)VectorTotalesPorColumnas[IndiceVariable] / (double)NumRegistros) * 100; }
    double TFmeRangos::GetPorcentajeErrorRegistro(unsigned IndiceRegistro) { return ((double)VectorTotalesPorFilas[IndiceRegistro] / (double)NumVariables) * 100; }
    unsigned TFmeRangos::GetNumeroErrorVariable(unsigned IndiceVariable) { return VectorTotalesPorColumnas[IndiceVariable]; }
    unsigned TFmeRangos::GetNumeroErrorRegistro(unsigned IndiceRegistro) { return VectorTotalesPorFilas[IndiceRegistro]; }
    TFmeEdits *TFmeRangos::GetEditsAsociados() { return FmeEditsAsociados; }
    bool TFmeRangos::GetTest(unsigned IndiceRegistro, unsigned IndiceVariable) { return MatrizTest[IndiceRegistro][IndiceVariable]; }
    bool TFmeRangos::GetTestCondicionFiltro(unsigned IndiceRegistro, unsigned IndiceVariable)  { return MatrizTestFiltro[IndiceRegistro][IndiceVariable]; }
    unsigned TFmeRangos::GetUmbralExclusionRegistros() { return UmbralExclusionRegistros; }
    unsigned TFmeRangos::GetUmbralExclusionVariables() { return UmbralExclusionVariables; }
    QSet<unsigned> TFmeRangos::GetVariablesExcluidas() { return VariablesExcluidas; }
    QSet<unsigned> TFmeRangos::GetRegistrosExcluidos() { return RegistrosExcluidos; }
    double TFmeRangos::GetTiempoProcesoSegundos() { return (double)InstanteComienzo.secsTo(InstanteFinalizacion); }
    double TFmeRangos::GetTiempoProcesoMilisegundos() { return (double)InstanteComienzo.msecsTo(InstanteFinalizacion); }
    unsigned TFmeRangos::GetNumRegistrosCorrectos() { return NumRegistrosCorrectos; }
    unsigned TFmeRangos::GetNumRegistrosIncorrectos() { return NumRegistrosIncorrectos; }
    unsigned TFmeRangos::GetNumRegistrosExcluidosAPriori() { return NumRegistrosExcluidosAPriori; }
    unsigned TFmeRangos::GetNumRegistrosExcluidos() { return NumRegistrosExcluidos; }
    unsigned TFmeRangos::GetNumVariablesCorrectas() { return NumVariablesCorrectas; }
    unsigned TFmeRangos::GetNumVariablesIncorrectas() { return NumVariablesIncorrectas; }
    unsigned TFmeRangos::GetNumVariablesExcluidasAPriori() { return NumVariablesExcluidasAPriori; }
    unsigned TFmeRangos::GetNumVariablesExcluidas() { return NumVariablesExcluidas; }
    bool TFmeRangos::RegistroCorrecto(unsigned IndiceRegistro) { return ((VectorTotalesPorFilas[IndiceRegistro] == 0) && (!RegistroExcluido(IndiceRegistro))); }
    bool TFmeRangos::RegistroExcluido(unsigned IndiceRegistro) { return VectorExclusionRegistros[IndiceRegistro]; }
    bool TFmeRangos::VariableCorrecta(unsigned IndiceVariable) { return ((VectorTotalesPorColumnas[IndiceVariable] == 0) && !(VariableExcluida(IndiceVariable))); }
    bool TFmeRangos::VariableExcluida(unsigned IndiceVariable) { return VectorExclusionVariables[IndiceVariable]; }
    bool *TFmeRangos::GetVectorExclusionVariables() { return VectorExclusionVariables; }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Actualizar los datos de la evaluacion del registro.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    bool TFmeRangos::ActualizarEvaluacionRegistro(unsigned IndiceRegistro, bool MicrodatoModificado)
    {
      unsigned j;
      QString Filtro;
      double Valor;
      int NoProcede, h;
      bool ResultadoFiltro, ResultadoRango, ResultadoTest;
      bool ExcluirRegistro = false;
      QString s, s1, s2, s3, suma = "";      
      QMap <QString, double> * mapp2;      

      NoProcede = FmeVariablesAsociadas->GetValorMissing(NOPROCEDE);      
      for (j = 0; j < NumVariables; j++)
      {
        if ((!FmeVariablesAsociadas->EsVariableImputable(j)) && (FrmOpciones->GetIgnorarVariablesNoImputables()))
        {
          ResultadoFiltro = true;
          ResultadoRango = true;
          ResultadoTest = true;
        }
        else
        {
          // Calculo del filtro
          if (FiltroExcluido(j))
            ResultadoFiltro = true;
          else
          {
            Filtro = FmeVariablesAsociadas->GetValorAtributo(j, ATR_FILTRO);
            if (!Filtro.isEmpty()) {
              mapp2 = FmeMicroDatosAsociados->GetMapRegistro(IndiceRegistro);
              ResultadoFiltro = EvaluarExpresion(Filtro.toLatin1().data(), mapp2);
            }else
              ResultadoFiltro =  true;
          }
          // Miramos si el valor esta en los rangos
          Valor = FmeMicroDatosAsociados->GetValor(IndiceRegistro, j);
          if (!FmeVariablesAsociadas->ValorEnRango(Valor, j))
            ResultadoRango = false;
          else
            ResultadoRango = true;
          if (!Filtro.isEmpty())
            ResultadoTest = ResultadoTestear(ResultadoFiltro, Valor, NoProcede, FmeVariablesAsociadas->GetValorAtributo(j, ATR_SENTIDO_FILTRO), j) && ResultadoRango;
          else {
              if ((Valor == (double)NoProcede) && (!FmeVariablesAsociadas->EsValorMissingAdmisible(j, NOPROCEDE)))
                ResultadoTest = false;
              else
                ResultadoTest = ResultadoFiltro && ResultadoRango;
          }
        }

        h = 0;
        if (!MicrodatoModificado) {
          if (!ResultadoTest)
            h = 1;
        }else {
          if (!(MatrizTest[IndiceRegistro][j]) && (ResultadoTest))
            h = -1;
          else
            if ((MatrizTest[IndiceRegistro][j]) && !(ResultadoTest))
              h = 1;
        }

        VectorTotalesPorFilasOriginal[IndiceRegistro] += h;
        VectorTotalesPorColumnasOriginal[j] += h;

        MatrizTestFiltro[IndiceRegistro][j] = ResultadoFiltro;
        MatrizTest[IndiceRegistro][j] = ResultadoTest;


        if (!ResultadoTest)
        {
          if ((!ResultadoRango) && (!FmeVariablesAsociadas->EsVariableImputable(j)))
            ExcluirRegistro = true;
          else
            if ((!ResultadoFiltro) && (FmeVariablesAsociadas->EsFiltroWarning(j)) && (!FmeVariablesAsociadas->EsVariableImputable(j)))
              ExcluirRegistro = true;
        }        
      }

      return ExcluirRegistro;
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Buscar la siguiente variable de la rejilla registro del filtro.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    unsigned TFmeRangos::BuscarVariableDerecha(unsigned ColumnaOrigen)
    {
      unsigned j;

      QModelIndex index = view->currentIndex();
      if (ColumnaOrigen == (unsigned)(NumVariables))
        return ColumnaOrigen;
      for (j = ColumnaOrigen + 1; j < (unsigned)NumVariables; j++)
        if (FmeVariablesAsociadas->VariableEnFiltro(j, index.column()-1))
          return (j);
      if (ColumnaOrigen == 0)
        return ColumnaOrigen;
      else
        return (ColumnaOrigen);
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Buscar la anterior variable de la rejilla registro del filtro.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    unsigned TFmeRangos::BuscarVariableIzquierda(unsigned ColumnaOrigen)
    {
      int j;
      QModelIndex index = view->currentIndex();
      if (ColumnaOrigen == 0)
        return ColumnaOrigen;
      for (j = ColumnaOrigen - 1; j >= 0; j--)
        if (FmeVariablesAsociadas->VariableEnFiltro(j, index.column()-1))
          return (j);
      if (ColumnaOrigen == (unsigned)NumVariables)
        return ColumnaOrigen;
      else
        return (ColumnaOrigen);
    }

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Buscar la siguiente variable con error hacia la derecha.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    unsigned TFmeRangos::BuscarVariableErrorDerecha(unsigned FilaOrigen, unsigned ColumnaOrigen)
    {
      unsigned j;

      if (ColumnaOrigen == (unsigned)(NumVariables))
        return ColumnaOrigen;
      for (j = ColumnaOrigen + 1; j < (unsigned)NumVariables + 1; j++)
        if (!MatrizTest[FilaOrigen - 1][j - 1])
          return (j);
      if (ColumnaOrigen == 1)
        return ColumnaOrigen;
      else
        return (ColumnaOrigen);
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Buscar la siguiente variable con error hacia la izquierda.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    unsigned TFmeRangos::BuscarVariableErrorIzquierda(unsigned FilaOrigen, unsigned ColumnaOrigen)
    {
      int j;

     if (ColumnaOrigen == 0)
        return ColumnaOrigen;
     for (j = ColumnaOrigen - 1; j > 0; j--)
        if (!MatrizTest[FilaOrigen - 1][j - 1])
          return (j);
      if (ColumnaOrigen == (unsigned)NumVariables)
        return ColumnaOrigen;
      else
        return (ColumnaOrigen);
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Buscar el siguiente microdato erroneo hacia arriba.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    unsigned TFmeRangos::BuscarMicroDatoErrorArriba(unsigned FilaOrigen, unsigned ColumnaOrigen)
    {
      int i;

      if (FilaOrigen == 0)
        return FilaOrigen;
      for (i = FilaOrigen - 1; i > 0; i--)
        if (!MatrizTest[i - 1][ColumnaOrigen - 1])
      return (i);
      if (FilaOrigen == (unsigned)NumRegistros)
        return FilaOrigen;
      else
        return (FilaOrigen);
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Buscar el siguiente microdato erroneo hacia abajo.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    unsigned TFmeRangos::BuscarMicroDatoErrorAbajo(unsigned FilaOrigen, unsigned ColumnaOrigen)
    {
      unsigned i;

      if (FilaOrigen == unsigned(NumRegistros))
        return FilaOrigen;
      for (i = FilaOrigen + 1; i < (unsigned)NumRegistros + 1; i++)
        if (!MatrizTest[i - 1][ColumnaOrigen - 1])
          return (i);
      if (FilaOrigen == 1)
        return FilaOrigen;
      else
        return (FilaOrigen);
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Cargar las Variables y los Registros posibles en la lista desplegable.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void TFmeRangos::CargarEnLista()
    {
      CbxIrAVariablePorNombre->addItems(*ListaVariables);
      //MemLogs->append("q pasa31");QApplication::processEvents();
      CbxIrAVariablePorNombre->setCurrentIndex(0);
      CbxIrAVariablePorNombre->setInsertPolicy(QComboBox::NoInsert);
      //QStringList *ListaIds = ListaIds;
      //MemLogs->append("q pasa32 ");QApplication::processEvents();
      //MemLogs->append("q pasa32 " + QString::number(ListaIds->size(),10));QApplication::processEvents();
      CbxIrARegistroPorNombre->setDuplicatesEnabled (true);
      CbxIrARegistroPorNombre->insertItems(0,*ListaIds);
      //MemLogs->append("q pasa33");QApplication::processEvents();
      CbxIrARegistroPorNombre->setCurrentIndex(0);
      CbxIrARegistroPorNombre->setInsertPolicy(QComboBox::NoInsert);
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Cargar el test en la rejilla de visualizacion.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void TFmeRangos::CargarTestEnRejilla()
    {
      unsigned i;

      // Cargamos los resultados
      for (i = 0; i < NumRegistros; i++)   {
        CargarTestRegistroEnRejilla(i);
      }
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Cargar el test del registro en la rejilla de visualizacion.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void TFmeRangos::CargarTestRegistroEnRejilla(unsigned IndiceRegistro)
    {
      unsigned i, j;
      QString s;
      i = IndiceRegistro + 1;
      for (j = 1; j < NumVariables + 1; j++) {
        if (MatrizTest[i - 1][j - 1]) {
          MatrizTestS[i][j] = "True";
        } else {
          MatrizTestS[i][j] = "False";
        }
        QApplication::processEvents();
      }
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Cargar porcentajes en la rejilla y en las series de datos.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void TFmeRangos::CargarResultados()
    {
      unsigned i, j;
      double Porcentaje;

      // Cargamos los totales por filas
      GbxHistograma->setNumColumnas(NumVariables);
      GbxHistograma->setNumRegistros(NumRegistros);
      GbxHistograma->setVectorTotalesPorFilas(VectorTotalesPorFilas);
      GbxHistograma->setVectorTotalesPorColumnas(VectorTotalesPorColumnas);
      GbxHistograma->setVariables(true);
      GbxHistograma->inicializar();
      model->setVectorExclusionRegistros(VectorExclusionRegistros);
      model->setVectorExclusionVariables(VectorExclusionVariables);

      for (i = 0; i < NumRegistros; i++) {
        Porcentaje = (VectorTotalesPorFilas[i] / (double)NumVariables) * 100;
        MatrizTestS[i+1][0] = QString::number(VectorTotalesPorFilas[i], 10) + " (" + QString::number(Porcentaje, 'f', 2).replace('.', ',') + "%)";
        listaV[i+1] = ListaIds->at(i) + " || " + QString::number(VectorTotalesPorFilas[i], 10) + " (" + QString::number(Porcentaje, 'f', 2).replace('.', ',') + "%)";
      }
      // Cargamos los totales por columnas
      for (j = 0; j < NumVariables; j++) {
        Porcentaje = (VectorTotalesPorColumnas[j] / (double)NumRegistros) * 100;
        MatrizTestS[0][j+1] = QString::number(VectorTotalesPorColumnas[j], 10) + " (" + QString::number(Porcentaje, 'f', 2).replace('.', ',') + "%)";
        listaH[j+1] = CbxIrAVariablePorNombre->itemText(j) + "\n" + QString::number(VectorTotalesPorColumnas[j], 10) + " (" + QString::number(Porcentaje, 'f', 2).replace('.', ',') + "%)";
        QApplication::processEvents();
      }
      model->setCurrencyCabec(listaH, listaV);
      view->hideColumn(0);
      view->hideRow(0);      
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Cargar porcentajes en la rejilla y en las series de datos para el registro especificado.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void TFmeRangos::CargarResultadosRegistro(unsigned IndiceRegistro)
    {
      unsigned i;
      double Porcentaje;

      i = IndiceRegistro;
      Porcentaje = (VectorTotalesPorFilas[i] / (double)NumVariables) * 100;
      MatrizTestS[i+1][0] = QString::number(VectorTotalesPorFilas[i], 10) + " (" + QString::number(Porcentaje, 'f', 2).replace('.', ',') + "%)";
      listaV[i+1] = ListaIds->at(i) + " || " + QString::number(VectorTotalesPorFilas[i], 10) + " (" + QString::number(Porcentaje, 'f', 2).replace('.', ',') + "%)";
      QApplication::processEvents();      
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Cargar porcentajes en la rejilla y en las series de datos para la variable especificada.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void TFmeRangos::CargarResultadosVariable(unsigned IndiceVariable)
    {
      unsigned i, j;
      double Porcentaje;

      QString s;
      j = IndiceVariable;
      Porcentaje = (VectorTotalesPorColumnas[j] / (double)NumRegistros) * 100;
      MatrizTestS[0][j+1] = QString::number(VectorTotalesPorColumnas[j], 10) + " (" + QString::number(Porcentaje, 'f', 2).replace('.', ',') + "%)";
      listaH[j+1] = CbxIrAVariablePorNombre->itemText(j) + "\n" + QString::number(VectorTotalesPorColumnas[j], 10) + " (" + QString::number(Porcentaje, 'f', 2).replace('.', ',') + "%)";
      QApplication::processEvents();
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Copiar el vector de totales originales en el vector de totales temporal.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void TFmeRangos::CrearCopiaVectoresTotales()
    {
      unsigned i, j;

      for (i = 0; i < NumRegistros; i++)
        VectorTotalesPorFilas[i] = VectorTotalesPorFilasOriginal[i];
      model->setVectorTotalesPorFilas(VectorTotalesPorFilas);
      for (j = 0; j < NumVariables; j++)
        VectorTotalesPorColumnas[j] = VectorTotalesPorColumnasOriginal[j];
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Calcular numero de registros correctos.
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    unsigned TFmeRangos::CalcularNumRegistrosCorrectos()
    {
      unsigned i;
      NumRegistrosCorrectos = 0;

      for (i = 0; i < NumRegistros; i++)
      if (RegistroCorrecto(i))
        NumRegistrosCorrectos++;

      return NumRegistrosCorrectos;
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Calcular numero de variables correctas.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    unsigned TFmeRangos::CalcularNumVariablesCorrectas()
    {
      unsigned j;
      NumVariablesCorrectas = 0;

      for (j = 0; j < NumVariables; j++)
        if (VariableCorrecta(j))
          NumVariablesCorrectas++;

      return NumVariablesCorrectas;
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Calcular numeros de resumen.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void TFmeRangos::CalcularNumResumen()
    {
      NumRegistrosExcluidosAPriori = RegistrosExcluidosAPriori.size();
      NumRegistrosExcluidos = RegistrosExcluidos.size();
      NumVariablesExcluidasAPriori = VariablesExcluidasAPriori.size();
      NumVariablesExcluidas = VariablesExcluidas.size();

      NumRegistrosIncorrectos = NumRegistros - NumRegistrosCorrectos - NumRegistrosExcluidos;
      NumVariablesIncorrectas = NumVariables - NumVariablesCorrectas - NumVariablesExcluidas;
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Evaluar el registro que se pasa por parametros sobre los filtros.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    bool TFmeRangos::ResultadoTestear(bool ResultadoFiltro, double Valor, int NP, QString opcion, int var)
    {
      if ((Valor == (double)NP) && (!FmeVariablesAsociadas->EsValorMissingAdmisible(var, NOPROCEDE)))
        return false;
      if (opcion == "a")
        return ((Valor == (double)NP) || (ResultadoFiltro));
      else
        if (opcion == "b")
          return ((Valor != (double)NP) || (!ResultadoFiltro));
        else
          return !((Valor == (double)NP) ^ (!ResultadoFiltro));
    }
    bool TFmeRangos::VarModFiltro(QSet<unsigned> VarFiltro, QSet<unsigned> VarModificadas)
    {
        QSet<unsigned>::const_iterator i = VarFiltro.constBegin();
        while (i != VarFiltro.constEnd()) {          
          if (VarModificadas.contains(*i)) return true;
          ++i;
        }
        return false;
    }
    bool TFmeRangos::EvaluarFiltros(unsigned IndiceRegistro, QSet<unsigned> VariablesModificadas, QMap<QString,double> *MapTest)
    {
      unsigned j;
      QString Filtro;
      double ValorN, Valor;
      bool RegistroCorrecto = true;
      bool ResultadoFiltro, ResultadoTest, ResultadoRango;
      int NoProcede;
      QSet<unsigned> VariablesFiltro;      

      NoProcede = FmeVariablesAsociadas->GetValorMissing(NOPROCEDE);
      for (j = 0; j < NumVariables; j++)
      {
        if ((!VariableExcluida(j)))// && (FmeVariablesAsociadas->EsVariableImputable(j)))
        {
          VariablesFiltro = FmeVariablesAsociadas->GetVariablesFiltros(j);
          VariablesFiltro.insert(j);
          ValorN = (*MapTest)[FmeVariablesAsociadas->GetNombreVariable(j)];
          Valor = FmeMicroDatosAsociados->GetValor(IndiceRegistro, j);
          if ((VarModFiltro(VariablesFiltro, VariablesModificadas)) || (ValorN != Valor))//(!ConjuntoInterseccion.empty())
          {
            // Calculo del filtro
            if (FiltroExcluido(j))
              ResultadoFiltro = true;
            else
            {
              Filtro = FmeVariablesAsociadas->GetValorAtributo(j, ATR_FILTRO);
              if (!Filtro.isEmpty()){
                ResultadoFiltro = EvaluarExpresion(Filtro.toLatin1().data(), MapTest);
              }else
                ResultadoFiltro =  true;
            }
            // Miramos si el valor esta en los rangos
            if (!FmeVariablesAsociadas->ValorEnRango(ValorN, j))
              ResultadoRango = false;
            else
              ResultadoRango = true;
            ResultadoTest = ResultadoTestear(ResultadoFiltro, ValorN, NoProcede, FmeVariablesAsociadas->GetValorAtributo(j, ATR_SENTIDO_FILTRO), j);
          }
          else {            
            if (!FmeVariablesAsociadas->ValorEnRango(Valor, j))
              ResultadoRango = false;
            else
              ResultadoRango = true;
            Filtro = FmeVariablesAsociadas->GetValorAtributo(j, ATR_FILTRO);
            if (!Filtro.isEmpty())
              ResultadoTest = GetTestFiltro(IndiceRegistro, j);
            else
              ResultadoTest = true;
          }

          RegistroCorrecto = (RegistroCorrecto && ResultadoTest && ResultadoRango);

          if (!RegistroCorrecto)
            return false;
        }
      }      
      return (RegistroCorrecto);
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Excluir el registro por parametros.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void TFmeRangos::ExcluirRegistro(unsigned IndiceRegistro)
    {
      VectorExclusionRegistros[IndiceRegistro] = true;
      RegistrosExcluidos.insert(IndiceRegistro);
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Excluir la variable por parametros.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void TFmeRangos::ExcluirVariable(unsigned IndiceVariable)
    {
      VectorExclusionVariables[IndiceVariable] = true;
      VariablesExcluidas.insert(IndiceVariable);
      ExcluirFiltros(IndiceVariable);
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Excluir los filtros afectados por la variable.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void TFmeRangos::ExcluirFiltros(unsigned IndiceVariable)
    {
      unsigned j;

      VectorExclusionFiltros[IndiceVariable] = true;

      for (j = 0; j < NumVariables; j++)
        if ((FmeVariablesAsociadas->VariableEnFiltro(IndiceVariable, j)) && (!FiltroExcluido(j)))
          VectorExclusionFiltros[j] = true;
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Excluir los registros que estïan por encima del umbral especificado.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void TFmeRangos::ExcluirRegistros()
    {
      unsigned i;

      for (i = 0; i < NumRegistros; i++)
        if ((VectorTotalesPorFilas[i] > UmbralExclusionRegistros) && (!RegistroExcluido(i)))
          ExcluirRegistro(i);
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Excluir las variables que estan por encima del umbral especificado.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void TFmeRangos::ExcluirVariables()
    {
      unsigned j;

      for (j = 0; j < NumVariables; j++)
        if (((unsigned)VectorTotalesPorColumnas[j] > UmbralExclusionVariables) && (!VariableExcluida(j)))
          ExcluirVariable(j);
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Excluir los registros a priori.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void TFmeRangos::ExcluirRegistrosAPriori()
    {
      QSet<unsigned>::iterator Puntero;

      Puntero = RegistrosExcluidosAPriori.begin();
      while (Puntero != RegistrosExcluidosAPriori.end())
      {
        ExcluirRegistro((*Puntero));
        ++Puntero;
      }
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Excluir los variables a priori.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void TFmeRangos::ExcluirVariablesAPriori()
    {
      QSet<unsigned>::iterator Puntero;

      Puntero = VariablesExcluidasAPriori.begin();
      while (Puntero != VariablesExcluidasAPriori.end())
      {
        ExcluirVariable((*Puntero));
        ++Puntero;
      }
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Fijar la cantidad de datos que intervienen en el proceso.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void TFmeRangos::FijarCantidadDatos()
    {
      NumRegistros = FmeMicroDatosAsociados->GetNumRegistros();
      NumVariables = FmeVariablesAsociadas->GetNumVariables();
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Dice si el filtro se cumple o no.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    bool TFmeRangos::GetTestFiltro(unsigned IndiceRegistro, unsigned IndiceVariable)
    {
      double Valor;
      double NoProcede;
      bool ResultadoFiltro;
      QString Filtro;

      Filtro = FmeVariablesAsociadas->GetValorAtributo(IndiceVariable, ATR_FILTRO);

      if (FiltroExcluido(IndiceVariable))
        ResultadoFiltro = true;
      else
        ResultadoFiltro = MatrizTestFiltro[IndiceRegistro][IndiceVariable];
      Valor = FmeMicroDatosAsociados->GetValor(IndiceRegistro, IndiceVariable);
      NoProcede = FmeVariablesAsociadas->GetValorMissing(NOPROCEDE);      
      return ResultadoTestear(ResultadoFiltro, Valor, NoProcede, FmeVariablesAsociadas->GetValorAtributo(IndiceVariable, ATR_SENTIDO_FILTRO), IndiceVariable);
    }
 /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
 // Retorna el modo que queremos visualizar los registros.
 /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    QComboBox *TFmeRangos::GetVisualizarReg()
    {
        return VisualizarReg;
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Dice si el rango se cumple o no.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    bool TFmeRangos::GetTestRango(unsigned IndiceRegistro, unsigned IndiceVariable)
    {
      double Valor;
      bool ResultadoRango;

      Valor = FmeMicroDatosAsociados->GetValor(IndiceRegistro, IndiceVariable);
      ResultadoRango = FmeVariablesAsociadas->ValorEnRango(Valor, IndiceVariable);
      return ResultadoRango;
    }
//////////////////////////////////////////////////////////////////////////////
// Retorna el modelo.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    TablaModelR *TFmeRangos::GetTablaModel()
    {
      return model;
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Incluir el registro por parametros.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void TFmeRangos::IncluirRegistro(unsigned IndiceRegistro)
    {
      VectorExclusionRegistros[IndiceRegistro] = false;    
      RegistrosExcluidos.remove(IndiceRegistro);
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Incluir la variable por parametros.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void TFmeRangos::IncluirVariable(unsigned IndiceVariable)
    {
      VectorExclusionVariables[IndiceVariable] = false;      
      VariablesExcluidas.remove(IndiceVariable);
      IncluirFiltros(IndiceVariable);
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Incluir los filtros afectados por la variable.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void TFmeRangos::IncluirFiltros(unsigned IndiceVariable)
    {
      unsigned j;

      VectorExclusionFiltros[IndiceVariable] = false;

      for (j = 0; j < NumVariables; j++)
        if ((FmeVariablesAsociadas->VariableEnFiltro(IndiceVariable, j)) && (FiltroExcluido(j)))
          VectorExclusionFiltros[j] = false;
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Inicializar la rejilla de visualizacion general.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void TFmeRangos::InicializarRejilla()
    {
      unsigned i, j;      

      // Establecemos el numero de filas y columnas      
      MatrizTestS = new QString*[NumRegistros + 1];      
      listaH.append("TOT");
      listaV.append("TOT");
      // Cargamos los titulos
      MatrizTestS[0] = new QString[NumVariables+1];
      for (i = 1; i < (unsigned)NumRegistros + 1; i++) {        
        listaV.append(ListaIds->at(i-1));
        //MemLogs->append("q pasa41");QApplication::processEvents();
        MatrizTestS[i] = new QString[NumVariables+1];
        view->setRowHeight(i, 5);
      }
      //MemLogs->append("q pasa42");QApplication::processEvents();
      view->setColumnWidth(0, ANCHO_COLUMNA_ESTANDAR);
      for (j = 1; j < (unsigned)NumVariables+1; j++) {        
        listaH.append("hola");
        view->setColumnWidth(j, ANCHO_COLUMNA_ESTANDAR);
      }
      MatrizTestS[0][0] = "----";      
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Inicializar la rejilla de visualizacion de registros.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void TFmeRangos::InicializarRejillaRegistro()
    {
      unsigned j;

      VectorDatosR = new QString[FmeMicroDatosAsociados->numColumnMicroS()];

      for (j = 0; j < (unsigned)NumVariables; j++)
      {
        listaH2.append(FmeMicroDatosAsociados->GetTablaModel()->headerData(j, Qt::Horizontal, Qt::DisplayRole).toString());
        view2->setColumnWidth(j, FmeMicroDatosAsociados->view->columnWidth(j+1));        
      }
      listaV2.append("");      
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Inicializar la rejilla de visualizacion de Variables.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void TFmeRangos::InicializarRejillaVariable()
    {
      unsigned j;

      VectorDatosV = new QString[FmeVariablesAsociadas->GetNumAtributos()];
      // Establecemos los titulos en la primera fila
      for (j = 0; j < (unsigned)FmeVariablesAsociadas->GetNumAtributos(); j++)
      {
        listaH3.append(FmeVariablesAsociadas->getlistaH(j));        
      }      
      listaV3.append("");
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Fijar el ancho de las columnas de la rejilla principal y rejilla registro.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void TFmeRangos::FijarAnchoColumnasRejilla(unsigned ancho)
    {
      unsigned j;

      for (j = 0; j < NumVariables + 1; j++)
      {
	view->setColumnWidth(j, ancho);
	view2->setColumnWidth(j, ancho);
      }
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Inicializar la matriz de test y la matriz de test de filtros
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void TFmeRangos::InicializarMatrizTest()
    {
      unsigned i, j;

      MatrizTest = new bool*[NumRegistros];
      MatrizTestFiltro = new bool*[NumRegistros];
      for (i = 0; i < NumRegistros; i++)
      {
        MatrizTest[i] = new bool[NumVariables];
        MatrizTestFiltro[i] = new bool[NumVariables];
        for (j = 0; j < NumVariables; j++) {
          MatrizTest[i][j] = false;
          MatrizTestFiltro[i][j] = false;
        }
      }
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Inicializar la matriz de test de filtros.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void TFmeRangos::InicializarMatrizTestFiltro()
    {
      unsigned i, j;

      MatrizTestFiltro = new bool*[NumRegistros];
      for (i = 0; i < NumRegistros; i++)
      {
        MatrizTestFiltro[i] = new bool[NumVariables];
        for (j = 0; j < NumVariables; j++)
          MatrizTestFiltro[i][j] = false;
      }
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Inicializar los vectores de totales.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void TFmeRangos::InicializarVectoresTotales()
    {
      VectorTotalesPorFilas = new unsigned[NumRegistros];
      VectorTotalesPorColumnas = new unsigned[NumVariables];
      VectorTotalesPorFilasOriginal = new unsigned[NumRegistros];
      VectorTotalesPorColumnasOriginal = new unsigned[NumVariables];
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Inicializar los vectores de exclusion.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void TFmeRangos::InicializarVectoresExclusion()
    {
      unsigned j;

      VectorExclusionRegistros = new bool[NumRegistros];
      VectorExclusionVariables = new bool[NumVariables];
      VectorExclusionFiltros = new bool[NumVariables];
      ResetearVectoresExclusion();
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Inicializar los cuadros de exclusion.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void TFmeRangos::InicializarCuadrosExclusion()
    {
      EdtExclusionRegistros->setText(QString::number(PORCENTAJE_INICIAL_EXCLUSION_REG_RANGOS * NumVariables, 'g', 6));
      EdtExclusionVariables->setText(QString::number(PORCENTAJE_INICIAL_EXCLUSION_VARIABLES * NumRegistros, 'g', 6));
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Inicializar el sistema de progreso.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void TFmeRangos::InicSistemaProgreso()
    {
      PbrProgreso->setRange (0, NumRegistros);
      PbrProgreso->setValue(0);
      EdtPorcentaje->setText("0%");
      EdtElemento->setText("(" + QString::number(PbrProgreso->value(), 10) + "/" + QString::number(PbrProgreso->maximum(), 10) + ")");
      QApplication::processEvents();
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Incrementar el sistema de progreso.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void TFmeRangos::IncSistemaProgreso()
    {
      PbrProgreso->setValue(PbrProgreso->value()+1);
      EdtElemento->setText("(" + QString::number(PbrProgreso->value(), 10) + "/" + QString::number(PbrProgreso->maximum(), 10) + ")");
      EdtPorcentaje->setText(QString::number(((double)PbrProgreso->value() / (double)PbrProgreso->maximum()) * 100, 'f', 2).replace('.', ',') + "%");
      QApplication::processEvents();
    }
    QString TFmeRangos::SustCaracter(QString Cadena, char CarABuscar, char CarSustitucion)
    {
      QString Aux;
      int Pos;

      Aux = Cadena;
      Pos = Aux.indexOf(CarABuscar);
      if (Pos != -1)
        Aux[Pos] = CarSustitucion;
      return Aux;
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Mostrar la informacion asociada a la fila y a la columna.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void TFmeRangos::MostrarInfoAsociada(unsigned Fila, unsigned Columna, bool Fijar)
    {
      static unsigned UltimaFila = 0, UltimaColumna = 0;
      unsigned FilaS = listaV.indexOf(model->headerData(Fila, Qt::Vertical, Qt::DisplayRole).toString());
      LabSbrBarraEstado2->setText(tr("Registro") + " " + QString::number(Fila, 10) + "/" + QString::number(model->rowCount(view->currentIndex())-1, 10) + "   [" + (QString)STR0049 + " " + QString::number(Columna, 10) + "/" + QString::number(NumVariables, 10) + "]");
      if (!MatrizTest[FilaS - 1][Columna - 1])
        LabSbrBarraEstado1->setText(tr("Existe un error para el microdato actual"));
      else
        LabSbrBarraEstado1->setText("");

      if ((Columna != UltimaColumna) || Fijar)
      {
        view2->clearSelection();

        for (int j = 0; j < FmeVariablesAsociadas->GetNumAtributos(); j++)  {
          VectorDatosV[j] = FmeVariablesAsociadas->getMatrizVariablesS(Columna-1, j);
          if (j < 8) view3->setColumnWidth ( j, ANCHOS_VARIABLE[j]);
          else
             if (j < 8 + FmeVariablesAsociadas->GetNum_valores_missing()) view3->setColumnWidth ( j, 100);
             else view3->setColumnWidth ( j, ANCHOS_VARIABLE[j - FmeVariablesAsociadas->GetNum_valores_missing()]);
        }
        EdtNumFiltrosVariable->setText(QString::number(FmeVariablesAsociadas->GetNumFiltrosVariable(Columna - 1), 10));
        EdtNumEditsVariable->setText(QString::number(FmeEditsAsociados->GetNumEditsVariable(Columna - 1), 10));
        listaV3[0] = FmeVariablesAsociadas->getlistaV(Columna - 1);
        model3->setCabeceraV(listaV3);
        model3->setHeaderData(0, Qt::Vertical, QVariant(), Qt::DisplayRole);
      }
      if ((FilaS != UltimaFila) || Fijar) {
        for (int j = 0; j < NumVariables; j++)
          VectorDatosR[j] = FmeMicroDatosAsociados->GetValorS(FilaS - 1, j);
        listaV2[0] = FmeMicroDatosAsociados->GetTablaModel()->headerData(FilaS - 1, Qt::Vertical, Qt::DisplayRole).toString();
        model2->setCabeceraV(listaV2);
        model2->setHeaderData(0, Qt::Vertical, QVariant(), Qt::DisplayRole);
      }
      if (Fijar) {
        view->setCurrentIndex(view->indexAt(QPoint(view->columnViewportPosition(Columna), view->rowViewportPosition(Fila))));
        QColor rojo = view->currentIndex().model()->data(view->currentIndex(), Qt::BackgroundRole).value<QColor>();
        QString color = rojo.name();
        setStyleSheet("selection-background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 " + color + ", stop: 1 gray);");
      }

      repintarVariable((!VectorDatosV[listaH3.indexOf("FILTRO")].isEmpty()), (MatrizTestS[FilaS][Columna] == "False"));
      repintarRegistro(Columna, (MatrizTestS[FilaS][Columna] == "False"));


      view2->clearSelection();
      UltimaFila = FilaS;
      UltimaColumna = Columna;
    }
    void TFmeRangos::MostrarInfoAsociada(unsigned Fila, unsigned Columna, unsigned numreg, bool Fijar, QStringList listah, QString **matriz, QStringList listav)
    {
      if (numreg == 0)
          LabSbrBarraEstado2->setText(tr("Registro 0/0   [") + (QString)STR0049 + " 0/" + QString::number(NumVariables, 10) + "]");
      else {
      static unsigned UltimaFila = 0, UltimaColumna = 0;
      unsigned FilaS = listaV.indexOf(listav.at(Fila));

      LabSbrBarraEstado2->setText(tr("Registro") + " " + QString::number(Fila, 10) + "/" + QString::number(numreg, 10) + "   [" + (QString)STR0049 + " " + QString::number(Columna, 10) + "/" + QString::number(NumVariables, 10) + "]");
      if (!MatrizTest[FilaS - 1][Columna - 1])
        LabSbrBarraEstado1->setText(tr("Existe un error para el microdato actual"));
      else
        LabSbrBarraEstado1->setText("");

      if ((Columna != UltimaColumna) || Fijar)
      {
        view2->clearSelection();

        for (int j = 0; j < FmeVariablesAsociadas->GetNumAtributos(); j++)  {
          VectorDatosV[j] = FmeVariablesAsociadas->getMatrizVariablesS(Columna-1, j);
          if (j < 8) view3->setColumnWidth ( j, ANCHOS_VARIABLE[j]);
          else
             if (j < 8 + FmeVariablesAsociadas->GetNum_valores_missing()) view3->setColumnWidth ( j, 100);
             else view3->setColumnWidth ( j, ANCHOS_VARIABLE[j - FmeVariablesAsociadas->GetNum_valores_missing()]);
        }
        EdtNumFiltrosVariable->setText(QString::number(FmeVariablesAsociadas->GetNumFiltrosVariable(Columna - 1), 10));
        EdtNumEditsVariable->setText(QString::number(FmeEditsAsociados->GetNumEditsVariable(Columna - 1), 10));
        listaV3[0] = FmeVariablesAsociadas->getlistaV(Columna - 1);
        model3->setCabeceraV(listaV3);
        model3->setHeaderData(0, Qt::Vertical, QVariant(), Qt::DisplayRole);
      }
      if ((FilaS != UltimaFila) || Fijar) {
        for (int j = 0; j < NumVariables; j++)
          VectorDatosR[j] = FmeMicroDatosAsociados->GetValorS(FilaS - 1, j);
        listaV2[0] = FmeMicroDatosAsociados->GetTablaModel()->headerData(FilaS - 1, Qt::Vertical, Qt::DisplayRole).toString();
        model2->setCabeceraV(listaV2);
        model2->setHeaderData(0, Qt::Vertical, QVariant(), Qt::DisplayRole);
      }

      repintarVariable((!VectorDatosV[listaH3.indexOf("FILTRO")].isEmpty()), (MatrizTestS[FilaS][Columna] == "False"));
      repintarRegistro(Columna, (MatrizTestS[FilaS][Columna] == "False"));

      if (Fijar) {
        view->setCurrentIndex(view->indexAt(QPoint(view->columnViewportPosition(Columna), view->rowViewportPosition(Fila))));
        QColor rojo = view->currentIndex().model()->data(view->currentIndex(), Qt::BackgroundRole).value<QColor>();
        QString color = rojo.name();
        setStyleSheet("selection-background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 " + color + ", stop: 1 gray);");
      }
      view2->clearSelection();
      UltimaFila = FilaS;
      UltimaColumna = Columna;
      }
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Resetear los vectores de totales y los vectores de exclusion
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void TFmeRangos::ResetearVectoresTotales()
    {
      unsigned i, j;

      for (i = 0; i < NumRegistros; i++)  {
        VectorTotalesPorFilasOriginal[i] = 0;
        VectorExclusionRegistros[i] = false;
      }
      for (j = 0; j < NumVariables; j++) {
        VectorTotalesPorColumnasOriginal[j] = 0;
        VectorExclusionVariables[j] = false;
        VectorExclusionFiltros[j] = false;
      }
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Resetear los vectores de exclusion.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void TFmeRangos::ResetearVectoresExclusion()
    {
      unsigned i, j;

      for (i = 0; i < NumRegistros; i++)
        VectorExclusionRegistros[i] = false;

      for (j = 0; j < NumVariables; j++)
      {
        VectorExclusionVariables[j] = false;
        VectorExclusionFiltros[j] = false;
      }
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Resetear las listas de exclusion.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void TFmeRangos::ResetearListasExclusion()
    {
      VariablesExcluidas.clear();
      RegistrosExcluidos.clear();
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Resetear las listas de exclusion a priori.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void TFmeRangos::ResetearListasExclusionAPriori()
    {
      VariablesExcluidasAPriori.clear();
      RegistrosExcluidosAPriori.clear();
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Salvar en un fichero los porcentajes de error de las variables.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void TFmeRangos::SalvarPorcentajesErrorVariables(QString NombreFichero, double PorcentajeUmbral)
    {
      QStringList *t = new QStringList();
      double percentage;
      unsigned i, j, n = 0;
      QString Linea; //, s, s1, s2, s3, s4, s5, s6, s7, s8, s9;

      t->append(tr("Porcentajes de error de variables"));
      if (PorcentajeUmbral > 0)
      {
	t->append("======================================================");
	t->append(tr("Mostrando aquellas variables con un porcentaje de error mayor o igual que el") + " " + QString::number(PorcentajeUmbral, 'f', 2) + "%");
      }
      t->append("=================================");
      t->append("");

      for (j = 0; j < NumVariables; j++)
      {
	percentage = ((double)VectorTotalesPorColumnas[j] / (double)NumRegistros) * 100;
	if (percentage >= PorcentajeUmbral)
	{
	  Linea = "[" + QString::number(j+1, 10) + "] " + FmeVariablesAsociadas->GetNombreVariable(j) + ": " + QString::number(percentage, 'f', 2) + "% [" + QString::number(VectorTotalesPorColumnas[j], 10) + "] {";
	  for (i = 0; i < NumRegistros; i++)
	    if (!(GetTest(i, j)))
	      Linea += " R" + QString::number(i+1, 10);
	  Linea += "}";
	  t->append(Linea);
	  n++;
	}
      }
      t->append("");
      t->append(tr("Variables listadas") + ": " + QString::number(n, 10));

      t->append("");
      t->append("======================================================");
      t->append(QApplication::translate("", "Variables que est\303\241n excluidas", 0, QApplication::UnicodeUTF8));
      t->append("======================================================");
      t->append("");

      n = 0;
      for (j = 0; j < NumVariables; j++)
      {
	if (VariableExcluida(j))
        {
	  percentage = ((double)VectorTotalesPorColumnas[j] / (double)NumRegistros) * 100;
	  t->append("[" + QString::number(j+1, 10) + "] " + FmeVariablesAsociadas->GetNombreVariable(j) + ": " + QString::number(percentage, 'f', 2) + "% [" + QString::number(VectorTotalesPorColumnas[j], 10) + "]");
	  n++;
	}
      }
      t->append("");
      t->append(tr("Variables listadas") + ": " + QString::number(n, 10));

      QString texto = t->join(QString('\n'));
      QFile f( NombreFichero );
      if ( !f.open( QIODevice::WriteOnly ) )
          QMessageBox::warning(this, "Warning", tr( "No se puede escribir en el fichero %1" ).arg( NombreFichero ), "&Ok");
      else {
        QTextStream s( &f );
        s << texto;
        f.close();
      }
      delete t;
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Salvar en un fichero los porcentajes de error de los registros.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void TFmeRangos::SalvarPorcentajesErrorRegistros(QString NombreFichero, double PorcentajeUmbral)
    {
      QStringList *t = new QStringList();
      double percentage;
      unsigned i, j, n;
      QString Linea;

      t->append(QApplication::translate("", "Porcentajes de error de registros (evaluaci\303\263n de rangos y filtros)", 0, QApplication::UnicodeUTF8));
      if (PorcentajeUmbral > 0)
      {
      	t->append("======================================================");
	t->append(tr("Mostrando aquellos registros con un porcentaje de error mayor o igual que el") + " " + QString::number(PorcentajeUmbral, 'f', 2) + "%");
      }
      t->append("======================================================");
      t->append("");

      n = 0;
      for (i = 0; i < NumRegistros; i++)
      {
	percentage = ((double)VectorTotalesPorFilas[i] / (double)NumVariables) * 100;
	if (percentage >= PorcentajeUmbral)
	{
          Linea = "[" + QString::number(i+1, 10) + "] " + ListaIds->at(i) + ": " + QString::number(percentage, 'f', 2) + "% [" + QString::number(VectorTotalesPorFilas[i], 10) + "] {";
	  for (j = 0; j < NumVariables; j++)
	    if (!(GetTest(i, j)))
	      Linea += " " + (FmeVariablesAsociadas->GetNombreVariable(j) + " ");
            Linea += "}";
	  t->append(Linea);
	  n++;
	}
      }
      t->append("");
      t->append(tr("Registros listados") + ": " + QString::number(n, 10));

      t->append("");
      t->append("======================================================");
      t->append(QApplication::translate("", "Registros que est\303\241n excluidos", 0, QApplication::UnicodeUTF8));
      t->append("======================================================");
      t->append("");

      n = 0;
      for (i = 0; i < NumRegistros; i++)
      {
        if (RegistroExcluido(i))
        {
          percentage = ((double)VectorTotalesPorFilas[i] / (double)NumVariables) * 100;
          t->append("[" + QString::number(i+1, 10) + "] " + ListaIds->at(i) + ": " + QString::number(percentage, 'f', 2) + "% [" + QString::number(VectorTotalesPorFilas[i], 10) + "]");
          n++;
        }
      }
      t->append("");
      t->append(tr("Registros listados") + ": " + QString::number(n, 10));

      QFile f( NombreFichero );
      if ( !f.open( QIODevice::WriteOnly ) )
          QMessageBox::warning(this, "Warning", tr( "No se puede escribir en el fichero %1" ).arg( NombreFichero ), "&Ok");
      else {
        QTextStream s( &f );
        for ( QStringList::Iterator it = t->begin(); it != t->end(); ++it )
            s << *it << "\n";
        f.close();
      }
      delete t;
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Validar los rangos de las variables.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void TFmeRangos::ValidarRangos()
    {
      unsigned i;
      QString s;

      InstanteComienzo = QTime::currentTime();

      InicSistemaProgreso();

      // Resetear las listas a priori
      ResetearListasExclusionAPriori();
      // Resetear los vectores totales
      ResetearVectoresTotales();
      // Resetear los vectores de exclusion
      //ResetearVectoresExclusion();
      // Actualizar los porcentajes de exclusion
      ActualizarUmbralExclusion();

      // Asociar a las variables los valores missing validos
      FmeVariablesAsociadas->AsociarMissingValidos(FrmOpciones);

      for (i = 0; i < NumRegistros; i++)
      {
        if (ActualizarEvaluacionRegistro(i, false))          
          ;

        IncSistemaProgreso();
      }
      InicSistemaProgreso2(" 1");
      ButAplicarExclusionClick();
      IncSistemaProgreso2(" 2");
      CargarTestEnRejilla();
      IncSistemaProgreso2(" 3");
      CalcularNumRegistrosCorrectos();
      IncSistemaProgreso2(" 4");
      CalcularNumVariablesCorrectas();
      IncSistemaProgreso2(" 5");
      CalcularNumResumen();
      IncSistemaProgreso2(" 6");

      //GbxHistograma->setActiveSerieColumnas(false);
      //GbxHistograma->setActiveSerieRegistros(true);

      IncSistemaProgreso2(" 7");      
      //GbxHistograma->setTitle(QApplication::translate("", "N\303\232MERO DE ERRORES [ejeX: Ordinal de registros, ejeY: N\303\272mero de errores]", 0, QApplication::UnicodeUTF8));
      IncSistemaProgreso2(" 8");
      MostrarInfoAsociada(1, 1, true);
      IncSistemaProgreso2(" 9");
      Cargado = true;
      
      PanProgreso->hide();          
      PanContenedor->show();
      
      InstanteFinalizacion = QTime::currentTime();      
    }
    void TFmeRangos::InicSistemaProgreso2(QString tex)
    {
      PbrProgreso->setRange (0, 8);
      PbrProgreso->setValue(0);
      EdtOperacion->setText(tr("Cargando rejilla"));
      EdtPorcentaje->setText("0%");
      EdtElemento->setText("");
      QApplication::processEvents();
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Incrementar el sistema de progreso.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void TFmeRangos::IncSistemaProgreso2(QString tex)
    {
      PbrProgreso->setValue(PbrProgreso->value()+1);
      EdtElemento->setText(tex);
      EdtPorcentaje->setText(QString::number(((double)PbrProgreso->value() / (double)PbrProgreso->maximum()) * 100, 'f', 2).replace('.', ',') + "%");
      QApplication::processEvents();
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Pinta la rejilla variable.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void TFmeRangos::repintarVariable(bool filtro, bool falso)
    {
      int col = FmeVariablesAsociadas->GetIndiceAtributo("FILTRO");
      QString *v = new QString[FmeVariablesAsociadas->GetNumAtributos()];
      for (int i = 1; i < FmeVariablesAsociadas->GetNumAtributos(); i++) {
        if (VectorDatosV[i] == "False") {
          v[i] = "Red";          
        }
      }
      if (filtro) {
        if (falso) {          
          v[col] = "Red";
        } else {          
          v[col] = "Orange";
        }
      }else {        
        v[col] = "Blue";
      }
      model3->setVectorPintar(v);      
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Pinta la rejilla registro.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void TFmeRangos::repintarRegistro(int col, bool falso)
    {      
      QString *vector = new QString[NumVariables];
      for (int i = 0; i < NumVariables; i++) {
        if (i == col-1) {
          if (falso) {
            vector[i] = "Red";
          }else {
            vector[i] = "Blue";
          }
        }else {
          if (FmeVariablesAsociadas->VariableEnFiltro(i, col-1)) {
            vector[i] = "Yellow";
          }else {
            vector[i] = "Otro";
          }
        }
      }
      model2->setVectorPintar(vector);
      view2->setCurrentIndex(view2->indexAt(QPoint(view2->columnViewportPosition(col-1), view2->rowViewportPosition(0))));      
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// PULSAR EL BOTON DE APLICAR LA EXCLUSION.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void TFmeRangos::ButAplicarExclusionClick()
    {
      ActualizarUmbralExclusion();
      AplicarExclusion();
      CargarResultados();      
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// SELECCIONAR UNA VARIABLE DEL COMBOBOX DE IR A VARIABLES.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void TFmeRangos::CbxIrAVariablePorNombreCloseUp(int index)
    {      
      view->setCurrentIndex(view->indexAt(QPoint(view->columnViewportPosition(index+1), view->rowViewportPosition(view->currentIndex().row()))));
      SgrRejillaSelectCell(view->currentIndex());
      view->setFocus();
    }
    
    void TFmeRangos::CbxIrARegistroPorNombreCloseUp(int index)
    {
      view->setCurrentIndex(view->indexAt(QPoint(view->columnViewportPosition(view->currentIndex().column()), view->rowViewportPosition(index+1))));
      SgrRejillaSelectCell(view->currentIndex());
      view->setFocus();
    }
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// PULSAR UNA TECLA SOBRE EL EDIT DE IR A REGISTRO.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void TFmeRangos::EdtIrARegistroPorNumeroKeyDown()
    {
      int IndiceRegistro;

      //try
      //{
        IndiceRegistro = EdtIrARegistroPorNumero->text().toInt();
      /*}
      catch (...)
      {
        EdtIrARegistroPorNumero->setText("");
        return;
      }*/
      if ((IndiceRegistro >= 1) && (IndiceRegistro <= model->rowCount(view->currentIndex())-1)) //NumRegistros))
        view->setCurrentIndex(view->indexAt(QPoint(view->columnViewportPosition(view->currentIndex().column()), view->rowViewportPosition(IndiceRegistro))));
      EdtIrARegistroPorNumero->setText("");
      SgrRejillaSelectCell(view->currentIndex());
      view->setFocus();

    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// PULSAR UNA TECLA SOBRE EL EDIT DE IR A VARIABLE POR NUMERO.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void TFmeRangos::EdtIrAVariablePorNumeroKeyDown()
    {
      int IndiceVariable;

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
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// COPIAR EL IDENTIFICADOR DEL REGISTRO ACTUAL.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void TFmeRangos::MitCopiarIdentificadorRegistroClick()
    {
      QApplication::clipboard()->setText(model->headerData(view->currentIndex().row(), Qt::Vertical, Qt::DisplayRole).toString());
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// COPIAR EL IDENTIFICADOR DE LA VARIABLE ACTUAL.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void TFmeRangos::MitCopiarIdentificadorVariableClick()
    {      
      QApplication::clipboard()->setText(model->headerData(view->currentIndex().column(), Qt::Horizontal, Qt::DisplayRole).toString());
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// SELECCIONAR UNA CELDA DE LA REJILLA.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void TFmeRangos::SgrRejillaSelectCell(const QModelIndex& index)
    {
      if (index.model()->rowCount(index) > 0)
      {
        if ((index.row() >= 1) && (index.column() >=1))
          MostrarInfoAsociada(index.row(), index.column(), true);
        else
          LabSbrBarraEstado2->setText(tr("Registro") + " 0/" + QString::number(model->rowCount(view->currentIndex())-1, 10) + "   [" + (QString)STR0049 + " 0/" + QString::number(NumVariables, 10) + "]");
      }
    }
    void TFmeRangos::SgrRejillaSelectCellV(const int& index)
    {
      int fila = view->currentIndex().row();
      int col = 1;
      MostrarInfoAsociada(fila, col, false);
    }
    void TFmeRangos::SgrRejillaSelectCellH(const int& index)
    {
      if (view->verticalHeader()->length() > 0)
      {
          int fila = 1;
          int col = view->currentIndex().column();
          MostrarInfoAsociada(fila, col, false);
      }
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// PULSAR UNA TECLA SOBRE LA REJILLA REGISTRO.
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void TFmeRangos::SgrRejillaRegKeyDownCR()
    {
      unsigned Columna;

      Columna = BuscarVariableDerecha(view2->currentIndex().column());
      view2->clearSelection();
      view2->setCurrentIndex(view2->indexAt(QPoint(view2->columnViewportPosition(Columna), view2->rowViewportPosition(0))));
      view2->setFocus();      
    }
    void TFmeRangos::SgrRejillaRegKeyDownCL()
    {
      unsigned Columna;

      Columna = BuscarVariableIzquierda(view2->currentIndex().column());  
      view2->clearSelection();
      view2->setCurrentIndex(view2->indexAt(QPoint(view2->columnViewportPosition(Columna), view2->rowViewportPosition(0))));
      view2->setFocus();      
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// PULSAR UNA TECLA SOBRE LA REJILLA PRINCIPAL.
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void TFmeRangos::SgrRejillaKeyDownAR()
    {
      unsigned Fila, Columna;
      if (VisualizarReg->currentIndex() != 1) {
        QModelIndex index = view->currentIndex();
      //Fila = index.row();
        Fila = listaV.indexOf(model->headerData(index.row(), Qt::Vertical, Qt::DisplayRole).toString());
        Columna = BuscarVariableErrorDerecha(Fila, index.column());
        index = view->indexAt(QPoint(view->columnViewportPosition(Columna), view->rowViewportPosition(index.row())));
        view->setCurrentIndex(index);
        SgrRejillaSelectCell(view->currentIndex());
        view->setFocus();
      }
    }
    void TFmeRangos::SgrRejillaKeyDownAL()
    {
      unsigned Fila, Columna;
      if (VisualizarReg->currentIndex() != 1) {
        QModelIndex index = view->currentIndex();
      //Fila = index.row();
        Fila = listaV.indexOf(model->headerData(index.row(), Qt::Vertical, Qt::DisplayRole).toString());
        Columna = BuscarVariableErrorIzquierda(Fila, index.column());
        index = view->indexAt(QPoint(view->columnViewportPosition(Columna), view->rowViewportPosition(index.row())));
        view->setCurrentIndex(index);
        SgrRejillaSelectCell(view->currentIndex());
        view->setFocus();
      }
    }
    void TFmeRangos::SgrRejillaKeyDownAU()
    {
      unsigned Fila, Columna;
      if (VisualizarReg->currentIndex() != 1) {
        QModelIndex index = view->currentIndex();
        Columna = index.column();
        Fila = BuscarMicroDatoErrorArriba(listaV.indexOf(model->headerData(index.row(), Qt::Vertical, Qt::DisplayRole).toString()), Columna);
        Fila = model->GetcabeceraV().indexOf(listaV.at(Fila)); //FmeMicroDatosAsociados->GetIdRegistro(Fila-1));
        index = view->indexAt(QPoint(view->columnViewportPosition(Columna), view->rowViewportPosition(Fila)));
        view->setCurrentIndex(index);
        SgrRejillaSelectCell(view->currentIndex());
        view->setFocus();
      }
    }
    void TFmeRangos::SgrRejillaKeyDownAD()
    {
      unsigned Fila, Columna;

      if (VisualizarReg->currentIndex() != 1) {
        QModelIndex index = view->currentIndex();
        Columna = index.column();
        Fila = BuscarMicroDatoErrorAbajo(listaV.indexOf(model->headerData(view->currentIndex().row(), Qt::Vertical, Qt::DisplayRole).toString()), Columna);
        Fila = model->GetcabeceraV().indexOf(listaV.at(Fila));
        index = view->indexAt(QPoint(view->columnViewportPosition(Columna), view->rowViewportPosition(Fila)));
        view->setCurrentIndex(index);
        SgrRejillaSelectCell(view->currentIndex());
        view->setFocus();
      }
    }
    void TFmeRangos::SgrRejillaKeyDownCZ()
    {
      if (ModificacionMicrodato)
      {
        ActualizarInterfaceMicrodatoCambiado((int)UltimoIndiceRegistroModificado, (int)UltimoIndiceVariableModificado, UltimoMicrodatoModificado);
        QModelIndex index = view->indexAt(QPoint(view->columnViewportPosition((int)UltimoIndiceVariableModificado + 1), view->rowViewportPosition((int)UltimoIndiceRegistroModificado + 1)));
        view->setCurrentIndex(index);
        SgrRejillaSelectCell(view->currentIndex());
        view->setFocus();
      }
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// HACER DOBLE CLICK SOBRE LA REJILLA DE VARIABLE.
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void TFmeRangos::SgrRejillaVariableDblClick(const QModelIndex& index)
    {
      unsigned ColumnaActiva;

      ColumnaActiva = index.column();

      if (listaH3[ColumnaActiva] == "MAPPING")
        FmeVariablesAsociadas->ConsultarTablaMapping(VectorDatosV[ColumnaActiva]);

      if (listaH3[ColumnaActiva] == "FILTRO")
        if (!VectorDatosV[ColumnaActiva].isEmpty())
          QMessageBox::information(this, QApplication::translate("", "Informaci\303\263n", 0, QApplication::UnicodeUTF8), VectorDatosV[ColumnaActiva]);

      if (FmeVariablesAsociadas->GetCadenas_Missing()->contains(listaH3[ColumnaActiva]))
        FmeVariablesAsociadas->ConsultarTablaMissing();
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// HACER DOBLE CLICK SOBRE LA REJILLA DE REGISTRO.
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void TFmeRangos::SgrRejillaRegistroDblClick(const QModelIndex& index)
    {
      rejillaregistro = true;
      connect(FrmIrAVariable->GetButAplicar(), SIGNAL(clicked()), this, SLOT(ButAplicarIrAVariableClickR()));
      connect(FrmIrAVariable->GetButCancelar(), SIGNAL(clicked()), this, SLOT(ButCancelarIrAVariableClickR()));
      FrmIrAVariable->show();
    }    
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// PULSAR EL BOTON DE SALVAR ERROR VARIABLES.
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void TFmeRangos::ButSalvarErrorVariablesClick()
    {
      QString start = QCoreApplication::applicationDirPath();
      QString meta = QDir::convertSeparators(start + "/" + DIRECTORIO_STATS);
      QString NombreFichero = QFileDialog::getSaveFileName(this, tr("Guardar fichero stats" ), meta, "TXT (*.txt)");
      if (!NombreFichero.isEmpty())
        SalvarPorcentajesErrorVariables(NombreFichero, (double)EdtUmbralErrorVariables->value());
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// PULSAR EL BOTON DE SALVAR ERROR REGISTROS.
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void TFmeRangos::ButSalvarErrorRegistrosClick()
    {
      QString start = QCoreApplication::applicationDirPath();
      QString meta = QDir::convertSeparators(start + "/" + DIRECTORIO_STATS);
      QString NombreFichero = QFileDialog::getSaveFileName(this, tr("Guardar fichero stats" ), meta, "TXT (*.txt)");
      if (!NombreFichero.isEmpty())
        SalvarPorcentajesErrorRegistros(NombreFichero, (double)EdtUmbralErrorRegistros->value());
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// HACER DOBLE CLICK SOBRE LA REJILLA PRINCIPAL.
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void TFmeRangos::SgrRejillaDblClick(const QModelIndex& index)
    {
      if ((VisualizarReg->currentIndex() == 0) && (principal->count() < 5)) {
          connect(FrmIrAVariable->GetButAplicar(), SIGNAL(clicked()), this, SLOT(ButAplicarIrAVariableClickR()));
          connect(FrmIrAVariable->GetButCancelar(), SIGNAL(clicked()), this, SLOT(ButCancelarIrAVariableClickR()));
          rejillaregistro = false;
          FrmIrAVariable->show();
      }      
    }
    void TFmeRangos::ButAplicarIrAVariableClickR()
    {
      unsigned IndiceRegistro, IndiceVariable;
      double Valor;

      if (FrmIrAVariable->GetRbnombre()->isChecked()){
        FrmIrAVariable->SetVariableSeleccionada(FrmIrAVariable->GetCbxPorNombre()->currentIndex());
        IndiceVariable = FrmIrAVariable->GetCbxPorNombre()->currentIndex();
      }else{
        FrmIrAVariable->SetVariableSeleccionada(FrmIrAVariable->GetCbxPorNumero()->currentIndex());
        IndiceVariable = FrmIrAVariable->GetCbxPorNumero()->currentIndex();
      }

      FrmIrAVariable->hide();

      if (rejillaregistro){
        view2->setCurrentIndex(view2->indexAt(QPoint(view2->columnViewportPosition(IndiceVariable), view2->rowViewportPosition(0))));
        view2->setFocus();
      }else {
        IndiceRegistro = view->currentIndex().row() - 1;        
        Valor = FmeMicroDatosAsociados->GetValor(IndiceRegistro, IndiceVariable);
        FrmCambiarMicrodato = new TFrmCambiarMicrodato(this);
        FrmCambiarMicrodato->FijarParametros(model->headerData(IndiceVariable + 1, Qt::Horizontal, Qt::DisplayRole).toString(), IndiceRegistro+1, Valor);

        connect(FrmCambiarMicrodato->GetButAceptar(), SIGNAL(clicked()), this, SLOT(ButAceptarCambiarMicrodatoClickR()));
        connect(FrmCambiarMicrodato->GetButCancelar(), SIGNAL(clicked()), this, SLOT(ButCancelarCambiarMicrodatoClickR()));
        FrmCambiarMicrodato->show();
      }      
    }

    void TFmeRangos::ButCancelarIrAVariableClickR()
    {      
      FrmIrAVariable->hide();
    }
    void TFmeRangos::ButAceptarCambiarMicrodatoClickR()
    {
      unsigned IndiceRegistro, IndiceVariable;
      double Valor;

      IndiceRegistro = view->currentIndex().row() - 1;
      IndiceVariable = FrmIrAVariable->GetVariableSeleccionada();

      Valor = FmeMicroDatosAsociados->GetValor(IndiceRegistro, IndiceVariable);

      ActualizarInterfaceMicrodatoCambiado(IndiceRegistro, IndiceVariable, FrmCambiarMicrodato->GetValorNuevo());
      ModificacionMicrodato = true;
      UltimoMicrodatoModificado = Valor;
      UltimoIndiceRegistroModificado = IndiceRegistro;
      UltimoIndiceVariableModificado = IndiceVariable;

      FrmCambiarMicrodato->hide();      
    }

    void TFmeRangos::ButCancelarCambiarMicrodatoClickR()
    {
       FrmCambiarMicrodato->hide();
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// PINCHAR LA OPCION DE MENU DE AUMENTAR EL TAMAÑO DE LAS COLUMNAS.
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void TFmeRangos::MitAumentarColumnasClick()
    {
      FijarAnchoColumnasRejilla(view->columnWidth(2) + 50);
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// PINCHAR LA OPCION DE MENU DE DISMINUIR EL TAMAÑO DE LAS COLUMNAS.
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void TFmeRangos::MitDisminuirColumnasClick()
    {
      FijarAnchoColumnasRejilla(view->columnWidth(2) - 50);
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// VISUALIZA EL MENU CUANDO PULSAMOS CON EL BOTON DERECHO DE RATON.
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void TFmeRangos::VisualizarMenu(const QModelIndex& index)
    {
      if (view->boton())
        menu->popup(QCursor::pos());
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// CUANDO SE PULSA LOS BOTONES DE ANT Y SIG DEL HISTOGRAMA.
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void TFmeRangos::ButClick_sig()
    {
      GbxHistograma->ButClick_sig();
    }
    void TFmeRangos::ButClick_ant()
    {
      GbxHistograma->ButClick_ant();
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// MODO DE VISUALIZAR LA TABLA DE RANGOS.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void TFmeRangos::VisualizarRegCloseUp(int index)
    {
      QString **MatrizRegA;      
      QStringList listaVA;
      QStringList listaHA;
      int *editcor;
      int i, j, k;
      view->showColumn(0);
      view->showRow(0);
      if (index == 0) {   // todos los registros
          delete model;          
          model = new TablaModelR(0, MatrizTestS, listaH, listaV);          
          model->setVectorPosReg(editcor, true);
          view->setModel(model);          
          MostrarInfoAsociada(1, 1, NumRegistros, true, listaH, MatrizTestS, listaV);
          ButSalvarErrorVariables->setEnabled(true);
          ButSalvarErrorRegistros->setEnabled(true);
          ButAplicarExclusion->setEnabled(true);
          CbxIrARegistroPorNombre->clear();
          CbxIrARegistroPorNombre->addItems(*ListaIds);
          view->hideColumn(0);
          view->hideRow(0);          
      }else {
          if (index == 1) {         // registros correctos
              listaHA.clear();
              listaVA.clear();
              MatrizRegA = new QString*[NumRegistrosCorrectos+1];
              editcor = new int[NumRegistrosCorrectos+1];              
              j = 0;
              MatrizRegA[j] = new QString[NumVariables+1];              
              for (k = 0; k < NumVariables+1; k++)
              {
                MatrizRegA[j][k] = MatrizTestS[0][k];
              }
              listaVA.append(listaV.at(0));
              editcor[j] = 0;
              j++;                          
              for (i = 1; i < NumRegistros+1; i++)
              {
                 if (RegistroCorrecto(i-1))
                  {
                      MatrizRegA[j] = new QString[NumVariables+1];
                      for (k = 0; k < NumVariables+1; k++)
                      {
                          MatrizRegA[j][k] = MatrizTestS[i][k];

                      }
                      listaVA.append(listaV.at(i));
                      editcor[j] = i;
                      j++;
                  }
              }              

              listaHA.append("TOT");
              listaHA += (* FmeVariablesAsociadas->GetListaVariables());
              model->setVectorPosReg(editcor, false);              
              model->setCurrencyMap(MatrizRegA);   // cuando modifiquemos la matriz              
              model->setCurrencyCabecV(listaVA);   // cuando modifiquemos la cabeceraV
              model->setCurrencyCabecH(listaHA);              
              MostrarInfoAsociada(1, 1, NumRegistrosCorrectos, true, listaH, MatrizRegA, listaVA);              
              ButSalvarErrorVariables->setEnabled(false);
              ButSalvarErrorRegistros->setEnabled(false);
              ButAplicarExclusion->setEnabled(false);
              CbxIrARegistroPorNombre->clear();
              CbxIrARegistroPorNombre->addItems(listaVA.replaceInStrings(QRegExp("(\\|+\\s\\d+\\s\\(\\d+,\\d+%\\))"), ""));
              CbxIrARegistroPorNombre->removeItem(0);
              view->hideColumn(0);
              view->hideRow(0);              
          }else {              // registros incorrectos
              listaHA.clear();
              listaVA.clear();
              MatrizRegA = new QString*[NumRegistrosIncorrectos+1];
              editcor = new int[NumRegistrosIncorrectos+1];

              j = 0;
              MatrizRegA[j] = new QString[NumVariables+1];
              for (k = 0; k < NumVariables+1; k++)
              {
                MatrizRegA[j][k] = MatrizTestS[0][k];
              }
              listaVA.append(listaV.at(0));
              editcor[j] = 0;
              j++;              
              for (i = 1; i < NumRegistros+1; i++)
              {
                 if (!RegistroCorrecto(i-1))
                  {
                      MatrizRegA[j] = new QString[NumVariables+1];
                      for (k = 0; k < NumVariables+1; k++)
                      {
                          MatrizRegA[j][k] = MatrizTestS[i][k];

                      }
                      listaVA.append(listaV.at(i));
                      editcor[j] = i;
                      j++;
                  }
              }              
              model->setVectorPosReg(editcor, false);
              model->setCurrencyMap(MatrizRegA);   // cuando modifiquemos la matriz              
              model->setCurrencyCabecV(listaVA);   // cuando modifiquemos la cabeceraV
              model->setCurrencyCabecH(listaH);
              MostrarInfoAsociada(1, 1, NumRegistrosIncorrectos, true, listaH, MatrizRegA, listaVA);
              ButSalvarErrorVariables->setEnabled(false);
              ButSalvarErrorRegistros->setEnabled(false);
              ButAplicarExclusion->setEnabled(false);
              CbxIrARegistroPorNombre->clear();
              if (NumRegistrosIncorrectos > 0) CbxIrARegistroPorNombre->addItems(listaVA.replaceInStrings(QRegExp("(\\|+\\s\\d+\\s\\(\\d+,\\d+%\\))"), ""));
              CbxIrARegistroPorNombre->removeItem(0);
              view->hideColumn(0);
              view->hideRow(0);
          }
      }      
    }
