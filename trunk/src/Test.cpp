/*******************************************************************************
** Test.cpp: contiene todo lo necesario para trabajar con la solapa
**           eval. de reglas.
**
** author: M-S Hernández-García
*******************************************************************************/

#include "Test.h"


TFmeTest::TFmeTest(QWidget* parent, const char* name, Qt::WindowFlags fl, TFmeRangos *FmeRangosAsociados, TFrmIrAVariable *FrmIrAVariable, TFrmCambiarMicrodato *FrmCambiarMicrodato, TFrmOpciones *FrmOpciones, QTabWidget *Frmprincipal, QStringList *ListaIds)
    {
      setGeometry(0, 0, parent->width()-2, parent->height()-15);

      if (this->objectName().isEmpty())
        this->setObjectName(("TFmeTest"));
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
      PanInfo = new QFrame(PanContenedor);
      PanInfo->setObjectName(("PanInfo"));
      PanInfo->setGeometry(QRect(1, SbrBarraEstado->y()-2-43, PanContenedor->width()-1, 43));
      PanInfo->setFrameShape(QFrame::Box);
      PanInfo->setFrameShadow(QFrame::Raised);

      LabIrARegistroPorNumero = new QLabel(PanInfo);
      LabIrARegistroPorNumero->setObjectName(("LabIrARegistroPorNumero"));
      LabIrARegistroPorNumero->setGeometry(QRect(8, 14, 90, 18));
      EdtIrARegistroPorNumero = new QLineEdit(PanInfo);
      EdtIrARegistroPorNumero->setObjectName(("EdtIrARegistroPorNumero"));
      EdtIrARegistroPorNumero->setGeometry(QRect(100, 10, 33, 23));

      LabIrARegistroPorNombre = new QLabel(PanInfo);
      LabIrARegistroPorNombre->setObjectName(("LabIrARegistroPorNombre"));
      LabIrARegistroPorNombre->setGeometry(QRect(140, 14, 90, 18));
      CbxIrARegistroPorNombre = new QComboBox(PanInfo);
      CbxIrARegistroPorNombre->setObjectName(("CbxIrARegistroPorNombre"));
      CbxIrARegistroPorNombre->setGeometry(QRect(240, 10, 145, 23));
      CbxIrARegistroPorNombre->setEditable(true);

      LabIrAEdit = new QLabel(PanInfo);
      LabIrAEdit->setObjectName(("LabIrAEdit"));
      LabIrAEdit->setGeometry(QRect(395, 14, 62, 18));
      EdtIrAEdit = new QLineEdit(PanInfo);
      EdtIrAEdit->setObjectName(("EdtIrAEdit"));
      EdtIrAEdit->setGeometry(QRect(462, 10, 33, 23));

      SbrBarraEditActual = new QFrame(PanInfo);
      SbrBarraEditActual->setObjectName(("SbrBarraEditActual"));
      SbrBarraEditActual->setGeometry(QRect(505, 0, PanContenedor->width()-505, 43));
      SbrBarraEditActual->setFrameShape(QFrame::Box);
      SbrBarraEditActual->setFrameShadow(QFrame::Raised);
      LabEditActual = new QLabel(SbrBarraEditActual);
      LabEditActual->setObjectName(("LabEditActual"));
      LabEditActual->setGeometry(QRect(5, 14, 75, 18));
      EdtEdit = new QLineEdit(SbrBarraEditActual);
      EdtEdit->setObjectName(("EdtEdit"));
      EdtEdit->setGeometry(QRect(85, 10, 641, 23));
      EdtEdit->setReadOnly(true);
      QPalette palette( QApplication::palette() );
      palette.setColor( QPalette::Active, QPalette::Base, Qt::gray );
      EdtEdit->setPalette(palette);

      view2 = new MiTabla(PanContenedor);
      view2->setGeometry(QRect(1, PanInfo->y()-2-65, PanContenedor->width()-1, 65));
      GbxHistograma = new MiBox(PanContenedor, PanContenedor->width()-1, this);
      GbxHistograma->setObjectName(("GbxHistograma"));
      GbxHistograma->setGeometry(QRect(1, view2->y()-2-171, PanContenedor->width()-1, 171));
      SplSeparador = new QFrame(PanContenedor);
      SplSeparador->setObjectName(("SplSeparador"));
      SplSeparador->setGeometry(QRect(1, GbxHistograma->y()-1-5, PanContenedor->width()-1, 5));
      SplSeparador->setMinimumSize(QSize(16, 4));
      SplSeparador->setFrameShape(QFrame::HLine);
      SplSeparador->setFrameShadow(QFrame::Raised);
      SplSeparador->setLineWidth(4);
      PanExclusion = new QFrame(PanContenedor);
      PanExclusion->setObjectName(("PanExclusion"));
      PanExclusion->setGeometry(QRect(1, SplSeparador->y()-1-30, PanContenedor->width()-1, 30));
      PanExclusion->setFrameShape(QFrame::Box);
      PanExclusion->setFrameShadow(QFrame::Raised);
      LabExclusionRegistros = new QLabel(PanExclusion);
      LabExclusionRegistros->setObjectName(("LabExclusionRegistros"));
      LabExclusionRegistros->setGeometry(QRect(8, 8, 303, 18));
      LabExclusionEdits = new QLabel(PanExclusion);
      LabExclusionEdits->setObjectName(("LabExclusionEdits"));
      LabExclusionEdits->setGeometry(QRect(382, 8, 291, 18));
      EdtExclusionRegistros = new QLineEdit(PanExclusion);
      EdtExclusionRegistros->setObjectName(("EdtExclusionRegistros"));
      EdtExclusionRegistros->setGeometry(QRect(317, 4, 41, 23));
      EdtExclusionEdits = new QLineEdit(PanExclusion);
      EdtExclusionEdits->setObjectName(("EdtExclusionEdits"));
      EdtExclusionEdits->setGeometry(QRect(680, 4, 41, 23));
      ButAplicarExclusion = new QPushButton(PanExclusion);
      ButAplicarExclusion->setObjectName(("ButAplicarExclusion"));
      ButAplicarExclusion->setGeometry(QRect(740, 4, 273, 25));
    
      view = new MiTabla(PanContenedor);
      view->setGeometry(QRect(1, 42, PanContenedor->width()-1, PanExclusion->y()-2-42));
      view->verticalHeader()->setDefaultSectionSize(21);
      PanSalvarPorcentajesError = new QFrame(PanContenedor);
      PanSalvarPorcentajesError->setObjectName(("PanSalvarPorcentajesError"));
      PanSalvarPorcentajesError->setGeometry(QRect(1, 0, PanContenedor->width()-1, 41));
      PanSalvarPorcentajesError->setFrameShape(QFrame::WinPanel);
      PanSalvarPorcentajesError->setFrameShadow(QFrame::Raised);
      LabUmbralErrorEdits = new QLabel(PanSalvarPorcentajesError);
      LabUmbralErrorEdits->setObjectName(("LabUmbralErrorEdits"));
      LabUmbralErrorEdits->setGeometry(QRect(248, 13, 161, 18));
      Label1 = new QLabel(PanSalvarPorcentajesError);
      Label1->setObjectName(("Label1"));
      Label1->setGeometry(QRect(463, 13, 15, 18));
      LabUmbralErrorRegistros = new QLabel(PanSalvarPorcentajesError);
      LabUmbralErrorRegistros->setObjectName(("LabUmbralErrorRegistros"));
      LabUmbralErrorRegistros->setGeometry(QRect(540, 13, 161, 18));
      Label3 = new QLabel(PanSalvarPorcentajesError);
      Label3->setObjectName(("Label3"));
      Label3->setGeometry(QRect(760, 13, 15, 18));
      ButSalvarErrorEdits = new QPushButton(PanSalvarPorcentajesError);
      ButSalvarErrorEdits->setObjectName(("ButSalvarerrorEdits"));
      ButSalvarErrorEdits->setGeometry(QRect(8, 8, 225, 25));
      ButSalvarErrorRegistros = new QPushButton(PanSalvarPorcentajesError);
      ButSalvarErrorRegistros->setObjectName(("ButSalvarErrorRegistros"));
      ButSalvarErrorRegistros->setGeometry(QRect(784, 8, 238, 25));
      EdtUmbralErrorEdits = new QSpinBox(PanSalvarPorcentajesError);
      EdtUmbralErrorEdits->setObjectName(("EdtUmbralErrorEdits"));
      EdtUmbralErrorEdits->setGeometry(QRect(410, 10, 46, 23));
      EdtUmbralErrorEdits->setSingleStep(5);
      EdtUmbralErrorRegistros = new QSpinBox(PanSalvarPorcentajesError);
      EdtUmbralErrorRegistros->setObjectName(("EdtUmbralErrorRegistros"));
      EdtUmbralErrorRegistros->setGeometry(QRect(710, 10, 46, 23));
      EdtUmbralErrorRegistros->setSingleStep(5);
      PanProgreso = new QLineEdit(this);
      PanProgreso->setObjectName(("PanProgreso"));
      PanProgreso->setGeometry(QRect(0, 0, this->width(), 90));
     
      QColor color = Qt::green;
      color.setRgb(0, 218, 160);
      color.setHsv (164, 255, 218);
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
      EdtOperacion->setGeometry(QRect(8, 27, 345, 23));
      palette.setColor( QPalette::Active, QPalette::Base, Qt::white );
      EdtOperacion->setPalette(palette);
      PbrProgreso = new QProgressBar(PanProgreso);
      PbrProgreso->setObjectName(("PbrProgreso"));
      PbrProgreso->setGeometry(QRect(2, 73, PanProgreso->width()-2, 15));
      PbrProgreso->setValue(0);
      PbrProgreso->setTextVisible(false);
      EdtPorcentaje = new QLineEdit(PanProgreso);
      EdtPorcentaje->setObjectName(("EdtPorcentaje"));
      EdtPorcentaje->setGeometry(QRect(368, 27, 73, 23));
      EdtPorcentaje->setReadOnly(true);
      EdtPorcentaje->setPalette(palette);
      EdtElemento = new QLineEdit(PanProgreso);
      EdtElemento->setObjectName(("EdtElemento"));
      EdtElemento->setGeometry(QRect(483, 27, 113, 23));
      EdtElemento->setReadOnly(true);
      EdtElemento->setPalette(palette);

      menu = new QMenu( this);
      menu->addAction( QObject::tr("Copiar identificador de registro..."), this, SLOT(MitCopiarIdentificadorRegistroClick()));
      menu->addAction( QObject::tr("Copiar identificador de regla..."), this, SLOT(MitCopiarIdentificadorEditClick()));
      menu->addSeparator();
      menu->addAction( QObject::tr("Aumentar el ancho de las columnas..."), this, SLOT(MitAumentarColumnasClick()));
      menu->addAction( QObject::tr("Disminuir el ancho de las columnas..."), this, SLOT(MitDisminuirColumnasClick()));

      this->setWindowTitle(QApplication::translate("TFmeTest", "Form", 0, QApplication::UnicodeUTF8));
      PanExclusion->setToolTip(QApplication::translate("TFmeTest", "Panel de exclusi\303\263n.", 0, QApplication::UnicodeUTF8));
      LabExclusionRegistros->setText(QApplication::translate("TFmeTest", "Excluir REGISTROS con n\303\272mero de errores mayor de", 0, QApplication::UnicodeUTF8));
      LabExclusionEdits->setText(QApplication::translate("TFmeTest", "Excluir REGLAS con n\303\272mero de errores mayor de", 0, QApplication::UnicodeUTF8));
      EdtExclusionRegistros->setToolTip(QApplication::translate("TFmeTest", "Porcentaje de exclusi\303\263n por encima del cual se excluir\303\241n los registros que superen esta cifra.", 0, QApplication::UnicodeUTF8));
      EdtExclusionRegistros->setText(QApplication::translate("TFmeTest", "0", 0, QApplication::UnicodeUTF8));
      EdtExclusionEdits->setToolTip(QApplication::translate("TFmeTest", "Porcentaje de exclusi\303\263n por encima del cual se excluir\303\241n las reglas que superen esta cifra.", 0, QApplication::UnicodeUTF8));
      EdtExclusionEdits->setText(QApplication::translate("TFmeTest", "0", 0, QApplication::UnicodeUTF8));
      ButAplicarExclusion->setText(QApplication::translate("TFmeTest", "Aplicar Exclusi\303\263n", 0, QApplication::UnicodeUTF8));
      ButAplicarExclusion->setToolTip(QApplication::translate("TFmeTest", "Pulse aqu\303\255 para aplicar la exclusi\303\263n.", 0, QApplication::UnicodeUTF8));
      view2->setToolTip(QApplication::translate("TFmeTest", "Informaci\303\263n del registro activo.(CTRL)", 0, QApplication::UnicodeUTF8));
      view->setToolTip(QApplication::translate("TFmeTest", "Rejilla de visualizaci\303\263n de los resultados de la evaluaci\303\263n.(ALT)", 0, QApplication::UnicodeUTF8));
      view->verticalHeader()->setToolTip(QApplication::translate("TFmeTest", "ID registro || Total errores", 0, QApplication::UnicodeUTF8));
      view->horizontalHeader()->setToolTip(QApplication::translate("TFmeTest", "ID regla\nTotal errores", 0, QApplication::UnicodeUTF8));
      LabBarraEstado1->setText("");
      LabBarraEstado2->setText("");
      LabIrARegistroPorNumero->setText(QApplication::translate("TFmeTest", "Ir a reg. (num)", 0, QApplication::UnicodeUTF8));
      LabIrARegistroPorNombre->setText(QApplication::translate("TFmeTest", "Ir a reg. (nom)", 0, QApplication::UnicodeUTF8));
      LabIrAEdit->setText(QApplication::translate("TFmeTest", "Ir a regla", 0, QApplication::UnicodeUTF8));
      LabEditActual->setText(QApplication::translate("TFmeTest", "Regla actual", 0, QApplication::UnicodeUTF8));
      EdtEdit->setToolTip(QApplication::translate("TFmeTest", "Regla activa.", 0, QApplication::UnicodeUTF8));
      EdtIrARegistroPorNumero->setToolTip(QApplication::translate("TFmeTest", "Indique el n\303\272mero de registro y pulse enter para ir a \303\251l.", 0, QApplication::UnicodeUTF8));
      CbxIrARegistroPorNombre->setToolTip(QApplication::translate("TFmeTest", "Seleccione el registro que desea visualizar.", 0, QApplication::UnicodeUTF8));
      EdtIrAEdit->setToolTip(QApplication::translate("TFmeTest", "Indique un n\303\272mero de regla y pulse ENTER parar ir a ella.", 0, QApplication::UnicodeUTF8));
      GbxHistograma->setTitle(QApplication::translate("TFmeTest", "Porcentajes de error", 0, QApplication::UnicodeUTF8));
      LabUmbralErrorEdits->setText(QApplication::translate("TFmeTest", "Porcentaje umbral de error", 0, QApplication::UnicodeUTF8));
      Label1->setText(QApplication::translate("TFmeTest", "%", 0, QApplication::UnicodeUTF8));
      LabUmbralErrorRegistros->setText(QApplication::translate("TFmeTest", "Porcentaje umbral de error", 0, QApplication::UnicodeUTF8));
      Label3->setText(QApplication::translate("TFmeTest", "%", 0, QApplication::UnicodeUTF8));
      ButSalvarErrorEdits->setText(QApplication::translate("TFmeTest", "Salvar porcentajes de error de reglas", 0, QApplication::UnicodeUTF8));
      ButSalvarErrorRegistros->setText(QApplication::translate("TFmeTest", "Salvar porcentajes de error de registros", 0, QApplication::UnicodeUTF8));
      ButSalvarErrorEdits->setToolTip(QApplication::translate("TFmeTest", "Salvar porcentajes de error de reglas en fichero", 0, QApplication::UnicodeUTF8));
      ButSalvarErrorRegistros->setToolTip(QApplication::translate("TFmeTest", "Salvar porcentajes de error de registros en fichero", 0, QApplication::UnicodeUTF8));
      EdtUmbralErrorEdits->setToolTip(QApplication::translate("TFmeTest", "Umbral para salvar reglas con un porcentaje de error", 0, QApplication::UnicodeUTF8));
      EdtUmbralErrorRegistros->setToolTip(QApplication::translate("TFmeTest", "Umbral para salvar registros con un porcentaje de error", 0, QApplication::UnicodeUTF8));
      LabOperacion->setText(QApplication::translate("TFmeTest", "Operaci\303\263n en curso", 0, QApplication::UnicodeUTF8));
      LabProgreso->setText(QApplication::translate("TFmeTest", "Progreso de la operaci\303\263n", 0, QApplication::UnicodeUTF8));
      LabPorcentaje->setText(QApplication::translate("TFmeTest", "% completado", 0, QApplication::UnicodeUTF8));
      LabElemento->setText(QApplication::translate("TFmeTest", "# completado", 0, QApplication::UnicodeUTF8));
      EdtOperacion->setToolTip(QApplication::translate("TFmeTest", "Nombre de la operaci\303\263n que esta siendo ejecutada actualmente.", 0, QApplication::UnicodeUTF8));
      EdtOperacion->setText(QApplication::translate("TFmeTest", "Evaluaci\303\263n de las reglas expl\303\255citas sobre los microdatos.", 0, QApplication::UnicodeUTF8));
      PbrProgreso->setToolTip(QApplication::translate("TFmeTest", "Muestra del progreso de la operaci\303\263n.", 0, QApplication::UnicodeUTF8));
      EdtPorcentaje->setToolTip(QApplication::translate("TFmeTest", "Porcentaje completado de la operaci\303\263n.", 0, QApplication::UnicodeUTF8));
      EdtElemento->setToolTip(QApplication::translate("TFmeTest", "Elemento actual en proceso / N\303\272mero total de elementos a procesar", 0, QApplication::UnicodeUTF8));
      VisualizarReg->setToolTip(QApplication::translate("TFmeTest", "Seleccione el modo de vizualizaci\303\263n de los registros.", 0, QApplication::UnicodeUTF8));
      VisualizarReg->addItem(QApplication::translate("TFmeTest", "Visualizar todos", 0, QApplication::UnicodeUTF8));
      VisualizarReg->addItem(QApplication::translate("TFmeTest", "Visualizar registros correctos", 0, QApplication::UnicodeUTF8));
      VisualizarReg->addItem(QApplication::translate("TFmeTest", "Visualizar registros incorrectos", 0, QApplication::UnicodeUTF8));

      QObject::connect(ButAplicarExclusion, SIGNAL(clicked()), this, SLOT(ButAplicarExclusionClick()));
      QObject::connect(view2, SIGNAL(doubleClicked(const QModelIndex&)), this, SLOT(SgrRejillaRegistroDblClick(const QModelIndex&)));
      QObject::connect(view, SIGNAL(doubleClicked(const QModelIndex&)), this, SLOT(SgrRejillaDblClick(const QModelIndex&)));
      QObject::connect(view, SIGNAL(clicked(const QModelIndex&)), this, SLOT(SgrRejillaSelectCell(const QModelIndex&)));
      QObject::connect(view->verticalHeader(), SIGNAL(sectionClicked ( const int & )), this, SLOT(SgrRejillaSelectCellV(const int &)));
      QObject::connect(view->horizontalHeader(), SIGNAL(sectionClicked ( const int & )), this, SLOT(SgrRejillaSelectCellH(const int &)));
      QObject::connect(view, SIGNAL(pressed ( const QModelIndex& )), this, SLOT(VisualizarMenu(const QModelIndex&)));
      QObject::connect(EdtEdit, SIGNAL(returnPressed()), this, SLOT(EdtEditClick()));
      QObject::connect(EdtIrARegistroPorNumero, SIGNAL(returnPressed()), this, SLOT(EdtIrARegistroPorNumeroKeyDown()));
      QObject::connect(EdtIrAEdit, SIGNAL(returnPressed()), this, SLOT(EdtIrAEditKeyDown()));
      QObject::connect(CbxIrARegistroPorNombre, SIGNAL(activated ( const int & )), this, SLOT(CbxIrARegistroPorNombreCloseUp(const int &)));
      QObject::connect(ButSalvarErrorEdits, SIGNAL(clicked()), this, SLOT(ButSalvarErrorEditsClick()));
      QObject::connect(ButSalvarErrorRegistros, SIGNAL(clicked()), this, SLOT(ButSalvarErrorRegistrosClick()));
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

      // Asociar las clases
      AsociarClases(FmeRangosAsociados);
      this->FrmIrAVariable = FrmIrAVariable;
      this->FrmCambiarMicrodato = FrmCambiarMicrodato;
      this->FrmOpciones = FrmOpciones;
      this->principal = Frmprincipal;

      connect(FrmCambiarMicrodato->GetButAceptar(), SIGNAL(clicked()), this, SLOT(ButAceptarCambiarMicrodatoClick()));
      connect(FrmCambiarMicrodato->GetButCancelar(), SIGNAL(clicked()), this, SLOT(ButCancelarCambiarMicrodatoClick()));
      connect(FrmIrAVariable->GetButAplicar(), SIGNAL(clicked()), this, SLOT(ButAplicarIrAVariableClick()));
      connect(FrmIrAVariable->GetButCancelar(), SIGNAL(clicked()), this, SLOT(ButCancelarIrAVariableClick()));
      

      MemLogs->append(QApplication::translate("", "Creando la clase de evaluaci\303\263n de reglas generales", 0, QApplication::UnicodeUTF8));
      QApplication::processEvents();

      // Fijamos un nombre
      this->Name = "FmeTest" + FmeEditsAsociados->GetNombreTabla();
      this->ListaIds = ListaIds;
      // Fijar la cantidad de datos
      FijarCantidadDatos();  
      //MemLogs->append("q pasa1");
      //QApplication::processEvents();
      CargarEnLista();
      //MemLogs->append("q pasa2");
      //QApplication::processEvents();
      // Fijar la lista de variables
      ListaVariables = FmeVariablesAsociadas->GetListaVariables();

      //MemLogs->append("q pasa3");
      //QApplication::processEvents();
    }
    void TFmeTest::ajustarSize()
    {
        setGeometry(0, 0, parentWidget()->width()-2, parentWidget()->height()-15);

        PanContenedor->setGeometry(QRect(0, 0, this->width(), this->height()-50));

        VisualizarReg->setGeometry(PanContenedor->width()-220, 0, 200, 25);

        SbrBarraEstado->setGeometry(QRect(1, PanContenedor->height()-2-22, PanContenedor->width()-1, 22));

        SbrBarraEstado1->setGeometry(QRect(0, 0, SbrBarraEstado->width()/2, 19));

        LabBarraEstado1->setGeometry(QRect(0, 0, SbrBarraEstado1->width(), 19));

        SbrBarraEstado2->setGeometry(QRect(SbrBarraEstado1->width()+1, 0, SbrBarraEstado1->width()-1, 19));

        LabBarraEstado2->setGeometry(QRect(3, 0, SbrBarraEstado2->width(), 19));

        PanInfo->setGeometry(QRect(1, SbrBarraEstado->y()-2-43, PanContenedor->width()-1, 43));

        SbrBarraEditActual->setGeometry(QRect(505, 0, PanContenedor->width()-505, 43));

        view2->setGeometry(QRect(1, PanInfo->y()-2-65, PanContenedor->width()-1, 65));

        GbxHistograma->setGeometry(QRect(1, view2->y()-2-171, PanContenedor->width()-1, 171));

        SplSeparador->setGeometry(QRect(1, GbxHistograma->y()-1-5, PanContenedor->width()-1, 5));

        PanExclusion->setGeometry(QRect(1, SplSeparador->y()-1-30, PanContenedor->width()-1, 30));

        view->setGeometry(QRect(1, 42, PanContenedor->width()-1, PanExclusion->y()-2-42));

        PanSalvarPorcentajesError->setGeometry(QRect(1, 0, PanContenedor->width()-1, 41));
    }
    bool TFmeTest::EvaluacionEditRegistro(unsigned IndiceRegistro, unsigned IndiceEdit) { return MatrizTest[IndiceRegistro][IndiceEdit]; }
    bool TFmeTest::EstaCargado() { return Cargado; }
    bool TFmeTest::EditCorrecto(unsigned IndiceEdit) { return ((VectorTotalesPorColumnas[IndiceEdit] == 0) && !(EditExcluido(IndiceEdit))); }
    bool TFmeTest::EditExcluido(unsigned IndiceEdit) { return VectorExclusionEdits[IndiceEdit]; }
    double TFmeTest::GetPorcentajeErrorEdit(unsigned IndiceEdit) { return ((double)VectorTotalesPorColumnas[IndiceEdit] / (double)NumRegistros) * 100; }
    double TFmeTest::GetPorcentajeErrorRegistro(unsigned IndiceRegistro) { return ((double)VectorTotalesPorFilas[IndiceRegistro] / (double)NumEdits) * 100; }
    unsigned TFmeTest::GetNumeroErrorEdit(unsigned IndiceEdit) { return VectorTotalesPorColumnas[IndiceEdit]; }
    unsigned TFmeTest::GetNumeroErrorRegistro(unsigned IndiceRegistro) { return VectorTotalesPorFilas[IndiceRegistro]; }
    TFmeRangos *TFmeTest::GetRangosAsociados() { return FmeRangosAsociados; }
    bool TFmeTest::GetTestEdit(unsigned IndiceRegistro, unsigned IndiceEdit) { return MatrizTest[IndiceRegistro][IndiceEdit]; }
    unsigned TFmeTest::GetUmbralExclusionRegistros() { return UmbralExclusionRegistros; }
    unsigned TFmeTest::GetUmbralExclusionEdits() { return UmbralExclusionEdits; }
    double TFmeTest::GetTiempoProcesoSegundos() { return (double)InstanteComienzo.secsTo(InstanteFinalizacion); }
    double TFmeTest::GetTiempoProcesoMilisengudos() { return (double)InstanteComienzo.msecsTo(InstanteFinalizacion); }
    unsigned TFmeTest::GetNumRegistrosCorrectos() { return NumRegistrosCorrectos; }
    unsigned TFmeTest::GetNumRegistrosIncorrectos() { return NumRegistrosIncorrectos; }
    unsigned TFmeTest::GetNumRegistrosExcluidosAPriori() { return NumRegistrosExcluidosAPriori; }
    unsigned TFmeTest::GetNumRegistrosExcluidos() { return NumRegistrosExcluidos; }
    unsigned TFmeTest::GetNumEditsCorrectos() { return NumEditsCorrectos; }
    unsigned TFmeTest::GetNumEditsIncorrectos() { return NumEditsIncorrectos; }
    unsigned TFmeTest::GetNumEditsExcluidosAPriori() { return NumEditsExcluidosAPriori; }
    unsigned TFmeTest::GetNumEditsExcluidos() { return NumEditsExcluidos; }
    bool TFmeTest::RegistroCorrecto(unsigned IndiceRegistro) { return ((VectorTotalesPorFilas[IndiceRegistro] == 0) && !(RegistroExcluido(IndiceRegistro))); }
    bool TFmeTest::RegistroExcluido(unsigned IndiceRegistro) { return VectorExclusionRegistros[IndiceRegistro]; }

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Asociar las clases provenientes de etapas anteriores.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void TFmeTest::AsociarClases(TFmeRangos *FmeRangosAsociados)
    {
      this->FmeRangosAsociados = FmeRangosAsociados;
      this->FmeEditsAsociados = FmeRangosAsociados->GetEditsAsociados();
      this->FmeMicroDatosAsociados = FmeEditsAsociados->GetMicroDatosAsociados();
      this->FmeVariablesAsociadas = FmeMicroDatosAsociados->GetVariablesAsociadas();
      this->MemLogs = FmeVariablesAsociadas->GetMemLogs();
    }

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Actualizar los porcentajes de exclusion.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void TFmeTest::ActualizarUmbralExclusion()
    {

      //try
      //{
        UmbralExclusionRegistros = (unsigned)EdtExclusionRegistros->text().toInt();
      /*}
      catch(...)
      {
        UmbralExclusionRegistros = (unsigned)(PORCENTAJE_INICIAL_EXCLUSION_REG_TEST * NumEdits);
      }*/

      //try
      //{
        UmbralExclusionEdits = (unsigned)EdtExclusionEdits->text().toInt();
      /*}
      catch(...)
      {
        UmbralExclusionEdits = (unsigned)(PORCENTAJE_INICIAL_EXCLUSION_EDITS * NumRegistros);
      }*/

      if (UmbralExclusionRegistros > NumEdits)
        UmbralExclusionRegistros = (unsigned)(PORCENTAJE_INICIAL_EXCLUSION_REG_TEST * NumEdits);

      if (UmbralExclusionEdits > NumRegistros)
        UmbralExclusionEdits = (unsigned)(PORCENTAJE_INICIAL_EXCLUSION_EDITS * NumRegistros);

      EdtExclusionRegistros->setText(QString::number(UmbralExclusionRegistros, 10));
      EdtExclusionEdits->setText(QString::number(UmbralExclusionEdits, 10));
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Actualizar la evaluacion y toda la interface despues de haber modificado un microdato concreto.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void TFmeTest::ActualizarInterfaceMicrodatoCambiado(unsigned IndiceRegistro, unsigned IndiceVariable, double Valor)
    {
      unsigned j;
      bool RegOK_0, RegOK_1;

      RegOK_0 = RegistroCorrecto(IndiceRegistro);

      FmeRangosAsociados->ActualizarInterfaceMicrodatoCambiado(IndiceRegistro, IndiceVariable, Valor);
      for (j = 0; j < (unsigned)FmeMicroDatosAsociados->GetNumVariables(); j++)
        VectorTestR[j] = FmeMicroDatosAsociados->GetValorS(IndiceRegistro, j);
      model2->setCurrencyMap(VectorTestR);

      if (ActualizarEvaluacionRegistro(IndiceRegistro, true))
        ;

      // Copia de los vectores originales
      for (j = 0; j < NumEdits; j++)
        VectorTotalesPorColumnas[j] = VectorTotalesPorColumnasOriginal[j];
      VectorTotalesPorFilas[IndiceRegistro] = VectorTotalesPorFilasOriginal[IndiceRegistro];
      model->setVectorTotalesPorFilas(VectorTotalesPorFilas);
      
      // actualizar las interfaces de usuario
      CargarTestRegistroEnRejilla(IndiceRegistro);

      CargarResultadosRegistro(IndiceRegistro);


      for (j = 0; j < NumEdits; j++)
      {
        CargarResultadosEdit(j);
      }
      model->setCurrencyCabec(listaH, listaV);
      RegOK_1 = RegistroCorrecto(IndiceRegistro);

      // calcular numeros de resumen
      if (RegOK_0 && !RegOK_1)
        NumRegistrosCorrectos--;
      else
        if (!RegOK_0 && RegOK_1)
          NumRegistrosCorrectos++;

      CalcularNumEditsCorrectos();
      CalcularNumResumen();      
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Aplicar los porcentajes de exclusion y recalcular los resultados.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void TFmeTest::AplicarExclusion()
    {
      CrearCopiaVectoresTotales();
      ResetearVectoresExclusion();
      ResetearListasExclusion();

      ExcluirRegistrosAPriori();
      ExcluirEditsAPriori();
      ExcluirRegistros();
      ExcluirEdits();

      CalcularNumResumen();
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Actualizar los datos de la evaluacion del registro.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    bool TFmeTest::ActualizarEvaluacionRegistro(unsigned IndiceRegistro, bool MicrodatoModificado)
    {
      unsigned j;
      bool ResultadoTest;
      bool ExcluirRegistro = false;
      int h;
      QMap <QString, double> *mapp;
      QMap <QString, double> mappM;
      
      if (!FrmOpciones->GetIgnorarEdits())
      {
        for (j = 0; j < NumEdits; j++)
        {
          mapp = FmeMicroDatosAsociados->GetMapRegistro(IndiceRegistro);
          mappM = FmeVariablesAsociadas->GetMapMissing();
          if (!EvaluarExpresion(FmeEditsAsociados->GetEdit(j).toLatin1().data(), mapp, &mappM))
            ResultadoTest = false;
          else
            ResultadoTest = true;

          h = 0;

          if (!MicrodatoModificado)
          {
            if (!ResultadoTest)
              h = 1;
          }
          else
          {
            if (!(MatrizTest[IndiceRegistro][j]) && (ResultadoTest))
              h = -1;
            else
              if ((MatrizTest[IndiceRegistro][j]) && !(ResultadoTest))
                h = 1;
          }

          MatrizTest[IndiceRegistro][j] = ResultadoTest;
          VectorTotalesPorFilasOriginal[IndiceRegistro] += h;
          VectorTotalesPorColumnasOriginal[j] += h;

          if (!ResultadoTest)
          {
            if (FmeEditsAsociados->EditWarning(j))
              ExcluirRegistro = true;
          }
        }
      }
      else
      {
        for (j = 0; j < NumEdits; j++)
          MatrizTest[IndiceRegistro][j] = true;
      }
      return ExcluirRegistro;
    }

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Buscar la siguiente variable de la rejilla registro del edit seleccionado.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    unsigned TFmeTest::BuscarVariableDerecha(unsigned ColumnaOrigen)
    {
      unsigned j;

      QModelIndex index = view->currentIndex();
      if (ColumnaOrigen == (unsigned)(FmeMicroDatosAsociados->GetNumVariables()))
        return ColumnaOrigen;
      for (j = ColumnaOrigen + 1; j < (unsigned)FmeMicroDatosAsociados->GetNumVariables(); j++)
        if (FmeEditsAsociados->VariableEnEdit(j, index.column()-1))
          return (j);
      if (ColumnaOrigen == 0)
        return ColumnaOrigen;
      else
        return (ColumnaOrigen);
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Buscar la anterior variable de la rejilla registro del edit seleccionado.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    unsigned TFmeTest::BuscarVariableIzquierda(unsigned ColumnaOrigen)
    {
      int j;
      QModelIndex index = view->currentIndex();
      if (ColumnaOrigen == 0)
        return ColumnaOrigen;
      for (j = ColumnaOrigen - 1; j >= 0; j--)
        if (FmeEditsAsociados->VariableEnEdit(j, index.column()-1))
          return (j);
      if (ColumnaOrigen == (unsigned)FmeMicroDatosAsociados->GetNumVariables())
        return ColumnaOrigen;
      else
        return (ColumnaOrigen);
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Buscar el siguiente edit con error hacia la derecha.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    unsigned TFmeTest::BuscarEditErrorDerecha(unsigned FilaOrigen, unsigned ColumnaOrigen)
    {
      unsigned j;

      if (ColumnaOrigen == (unsigned)(NumEdits))
        return ColumnaOrigen;
      for (j = ColumnaOrigen + 1; j < (unsigned)NumEdits + 1; j++)
        if (!MatrizTest[FilaOrigen - 1][j - 1])
          return (j);
      if (ColumnaOrigen == 1)
        return ColumnaOrigen;
      else
        return (ColumnaOrigen);
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Buscar el  con error hacia la izquierda.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    unsigned TFmeTest::BuscarEditErrorIzquierda(unsigned FilaOrigen, unsigned ColumnaOrigen)
    {
      int j;

      if (ColumnaOrigen == 0)
        return ColumnaOrigen;
      for (j = ColumnaOrigen - 1; j > 0; j--)
        if (!MatrizTest[FilaOrigen - 1][j - 1])
          return (j);
      if (ColumnaOrigen == (unsigned)NumEdits)
        return ColumnaOrigen;
      else
        return (ColumnaOrigen);
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Buscar el siguiente microdato erroneo hacia arriba.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    unsigned TFmeTest::BuscarMicroDatoErrorArriba(unsigned FilaOrigen, unsigned ColumnaOrigen)
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
    unsigned TFmeTest::BuscarMicroDatoErrorAbajo(unsigned FilaOrigen, unsigned ColumnaOrigen)
    {
      unsigned i;

      if (FilaOrigen == unsigned(NumRegistros))
        return FilaOrigen;
      for (i = FilaOrigen + 1; i < (unsigned)NumRegistros +1; i++)
        if (!MatrizTest[i - 1][ColumnaOrigen - 1])
          return (i);
      if (FilaOrigen == 1)
        return FilaOrigen;
      else
        return (FilaOrigen);
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Cargar el test del registro en la rejilla de visualizacion.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void TFmeTest::CargarTestRegistroEnRejilla(unsigned IndiceRegistro)
    {
      unsigned i, j;

      i = IndiceRegistro + 1;
      for (j = 1; j < (unsigned)NumEdits + 1; j++)
        if (MatrizTest[i - 1][j - 1]) {
          MatrizTestS[i][j] = "True";
        }else {
          MatrizTestS[i][j] = "False";
        }
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void TFmeTest::CargarEnLista()
    {
      CbxIrARegistroPorNombre->setDuplicatesEnabled(true);
      //MemLogs->append("q pasa12");
      //QApplication::processEvents();
      CbxIrARegistroPorNombre->insertItems(0, *ListaIds);
      //MemLogs->append("q pasa13");
      //QApplication::processEvents();
      CbxIrARegistroPorNombre->setCurrentIndex(0);
      CbxIrARegistroPorNombre->setInsertPolicy(QComboBox::NoInsert);
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Cargar el test en la rejilla de visualizacion.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void TFmeTest::CargarTestEnRejilla()
    {
      unsigned i, j;

      // Cargamos los resultados
      for (i = 1; i < (unsigned)NumRegistros + 1; i++)
        for (j = 1; j < (unsigned)NumEdits + 1; j++)
          if (MatrizTest[i - 1][j - 1]) {
            MatrizTestS[i][j] = "True";
          } else {
            MatrizTestS[i][j] = "False";
          }          
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Cargar porcentajes en la rejilla y en las series de datos.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void TFmeTest::CargarResultados()
    {
      unsigned i, j;

      // Cargamos los totales por filas
      GbxHistograma->setNumColumnas(NumEdits);
      GbxHistograma->setNumRegistros(NumRegistros);
      GbxHistograma->setVectorTotalesPorFilas(VectorTotalesPorFilas);
      GbxHistograma->setVectorTotalesPorColumnas(VectorTotalesPorColumnas);
      GbxHistograma->setVariables(false);
      GbxHistograma->inicializar();
      model->setVectorExclusionRegistros(VectorExclusionRegistros);
      model->setVectorExclusionEdits(VectorExclusionEdits);
      for (i = 0; i < NumRegistros; i++) {
        CargarResultadosRegistro(i);        
      }
      // Cargamos los totales por columnas
      for (j = 0; j < NumEdits; j++) {
        CargarResultadosEdit(j);        
      }
      model->setCurrencyCabec(listaH, listaV);
      view->hideColumn(0);
      view->hideRow(0);      
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Cargar porcentajes en la rejilla y en las series de datos para el registro especificado.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void TFmeTest::CargarResultadosRegistro(unsigned IndiceRegistro)
    {
      unsigned i;
      double Porcentaje;

      i = IndiceRegistro;
      Porcentaje = ((double)VectorTotalesPorFilas[i] / (double)NumEdits) * 100;
      MatrizTestS[i+1][0] = QString::number(VectorTotalesPorFilas[i], 10) + " (" + QString::number(Porcentaje, 'f', 2).replace('.', ',') + "%)";
      listaV[i+1] = ListaIds->at(i) + " || " + QString::number(VectorTotalesPorFilas[i], 10) + " (" + QString::number(Porcentaje, 'f', 2).replace('.', ',') + "%)";
    }

    QString TFmeTest::SustCaracter(QString Cadena, char CarABuscar, char CarSustitucion)
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
// Cargar porcentajes en la rejilla y en las series de datos para el edit especificado.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void TFmeTest::CargarResultadosEdit(unsigned IndiceEdit)
    {
      unsigned j, i;
      double Porcentaje;

      j = IndiceEdit;
      Porcentaje = (VectorTotalesPorColumnas[j] / (double)NumRegistros) * 100;
      MatrizTestS[0][j+1] = QString::number(VectorTotalesPorColumnas[j], 10) + " (" + QString::number(Porcentaje, 'f', 2).replace('.', ',') + "%)";
      listaH[j+1] = QString::number(FmeEditsAsociados->GetIdEdit(j), 10) + "\n" + QString::number(VectorTotalesPorColumnas[j], 10) + " (" + QString::number(Porcentaje, 'f', 2).replace('.', ',') + "%)";
      if (EditExcluido(j)) {
        ;
      }else {
        for (i = 1; i < NumRegistros + 1; i++) {
          if (!RegistroExcluido(i-1)) {
            repintar(i, j+1);
          }
        }
      }
      QApplication::processEvents();      
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Copiar el vector de totales originales en el vector de totales temporal.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void TFmeTest::CrearCopiaVectoresTotales()
    {
      unsigned i, j;

      for (i = 0; i < NumRegistros; i++)
        VectorTotalesPorFilas[i] = VectorTotalesPorFilasOriginal[i];
      model->setVectorTotalesPorFilas(VectorTotalesPorFilas);
      for (j = 0; j < NumEdits; j++)
        VectorTotalesPorColumnas[j] = VectorTotalesPorColumnasOriginal[j];
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Calcular numero de edits correctos.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    unsigned TFmeTest::CalcularNumEditsCorrectos()
    {
      unsigned j;
      NumEditsCorrectos = 0;

      for (j = 0; j < NumEdits; j++)
        if (EditCorrecto(j))
          NumEditsCorrectos++;

      return NumEditsCorrectos;
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Calcular n?mero de registros correctos.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    unsigned TFmeTest::CalcularNumRegistrosCorrectos()
    {
      unsigned i;
      NumRegistrosCorrectos = 0;

      for (i = 0; i < NumRegistros; i++)
        if (RegistroCorrecto(i))
          NumRegistrosCorrectos++;

      return NumRegistrosCorrectos;
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Calcular numeros de resumen.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void TFmeTest::CalcularNumResumen()
    {
      unsigned i, j;

      NumRegistrosCorrectos = 0;
      NumEditsCorrectos = 0;

      for (i = 0; i < NumRegistros; i++)
        if (RegistroCorrecto(i))
          NumRegistrosCorrectos++;
      for (j = 0; j < NumEdits; j++)
        if (EditCorrecto(j))
          NumEditsCorrectos++;

      NumRegistrosExcluidosAPriori = RegistrosExcluidosAPriori.size();
      NumRegistrosExcluidos = RegistrosExcluidos.size();
      NumEditsExcluidosAPriori = EditsExcluidosAPriori.size();
      NumEditsExcluidos = EditsExcluidos.size();

      NumRegistrosIncorrectos = NumRegistros - NumRegistrosCorrectos - NumRegistrosExcluidos;
      NumEditsIncorrectos = NumEdits - NumEditsCorrectos - NumEditsExcluidos;
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Evaluar el registro que se pasa por parametros.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    bool TFmeTest::VarModEdit(QSet<unsigned> VarEdit, QSet<unsigned> VarModificadas)
    {
        QSet<unsigned>::const_iterator i = VarEdit.constBegin();
        while (i != VarEdit.constEnd()) {
          QString var = FmeVariablesAsociadas->GetNombreVariable(*i);
          if (VarModificadas.contains(*i)) return true;
          ++i;
        }
        return false;
    }
    bool TFmeTest::EvaluarRegistro(unsigned IndiceRegistro, QSet<unsigned> VariablesModificadas, QMap<QString,double> *MapTest)
    {
      unsigned j;
      bool RegistroCorrecto = true;
      bool ResultadoTest;
      QSet<unsigned> VariablesEdit;
      QMap<QString,double> mappM;
      if (FrmOpciones->GetIgnorarEdits())
        return true;

      for (j = 0; j < NumEdits; j++)
      {
        if (!EditExcluido(j))
        {
          // Chequeo de variables
          VariablesEdit = FmeEditsAsociados->GetVariablesEdits(j);
          if (VarModEdit(VariablesEdit, VariablesModificadas)) 
          {
            mappM = FmeVariablesAsociadas->GetMapMissing();
            if (!EvaluarExpresion(FmeEditsAsociados->GetEdit(j).toLatin1().data(), MapTest, &mappM))
              ResultadoTest = false;
            else
              ResultadoTest = true;
          }
          else
            ResultadoTest = GetTestEdit(IndiceRegistro, j);
          RegistroCorrecto = (RegistroCorrecto && ResultadoTest);

          if (!RegistroCorrecto)
            return false;
        }
      }
      return (RegistroCorrecto);
    }
    bool TFmeTest::EvaluarRegistro2(unsigned IndiceRegistro, QSet<unsigned> VariablesModificadas, QMap<QString,double> *MapTest)
    {
      unsigned j;
      bool RegistroCorrecto = true;
      bool ResultadoTest;
      QSet<unsigned> VariablesEdit;
      QMap<QString,double> mappM;
      if (FrmOpciones->GetIgnorarEdits())
        return true;
    
      for (j = 0; j < NumEdits; j++)
      {
        if (!EditExcluido(j))
        {
          // Chequeo de variables
          VariablesEdit = FmeEditsAsociados->GetVariablesEdits(j);
          if (VarModEdit(VariablesEdit, VariablesModificadas)) 
          {
            mappM = FmeVariablesAsociadas->GetMapMissing();
            if (!EvaluarExpresion(FmeEditsAsociados->GetEdit(j).toLatin1().data(), MapTest, &mappM))
              ResultadoTest = false;
            else
              ResultadoTest = true;
          }
          else
            ResultadoTest = true; 
          RegistroCorrecto = (RegistroCorrecto && ResultadoTest);

          if (!RegistroCorrecto)
            return false;
        }
      }
      return (RegistroCorrecto);
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Excluir el registro por parametros.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void TFmeTest::ExcluirRegistro(unsigned IndiceRegistro)
    {
      VectorExclusionRegistros[IndiceRegistro] = true;
      RegistrosExcluidos.insert(IndiceRegistro);
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Excluir el edit por parametros.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void TFmeTest::ExcluirEdit(unsigned IndiceEdit)
    {
      VectorExclusionEdits[IndiceEdit] = true;
      EditsExcluidos.insert(IndiceEdit);
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Excluir los registros que estan por encima del umbral especificado.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void TFmeTest::ExcluirRegistros()
    {
      unsigned i;

      for (i = 0; i < NumRegistros; i++)
        if ((VectorTotalesPorFilas[i] > UmbralExclusionRegistros) && (!RegistroExcluido(i)))
          ExcluirRegistro(i);
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Excluir las variables que estan por encima del umbral especificado.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void TFmeTest::ExcluirEdits()
    {
      unsigned j;

      for (j = 0; j < NumEdits; j++)
        if ((VectorTotalesPorColumnas[j] > UmbralExclusionEdits) && (!EditExcluido(j))) 
          ExcluirEdit(j);
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Excluir los registros a priori.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void TFmeTest::ExcluirRegistrosAPriori()
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
// Excluir los edits a priori.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void TFmeTest::ExcluirEditsAPriori()
    {
      QSet<unsigned>::iterator Puntero;

      Puntero = EditsExcluidosAPriori.begin();
      while (Puntero != EditsExcluidosAPriori.end())
      {
        ExcluirEdit((*Puntero));
        ++Puntero;
      }
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Determina si el edit contiene alguna variable excluida.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    bool TFmeTest::EditConVariableExcluida(unsigned IndiceEdit)
    {
      QSet<unsigned> Variables;
      QSet<unsigned>::iterator Puntero;

      Variables = FmeEditsAsociados->GetVariablesEdits(IndiceEdit);    
      Puntero = Variables.begin();
      while (Puntero != Variables.end())
      {
        if (FmeRangosAsociados->VariableExcluida(*Puntero))
          return true;
        ++Puntero;
      }
      return false;
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Fijar la cantidad de datos que intervienen en el proceso.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void TFmeTest::FijarCantidadDatos()
    {
      NumRegistros = FmeMicroDatosAsociados->GetNumRegistros();
      NumEdits = FmeEditsAsociados->GetNumEdits();
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Fijar el ancho de las columnas de la rejilla registro.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void TFmeTest::FijarAnchoColumnasRejillaRegistro(unsigned ancho)
    {
      unsigned j;

      for (j = 0; j < (unsigned)FmeMicroDatosAsociados->GetNumVariables(); j++)
	view2->setColumnWidth(j, ancho);
    }
 //////////////////////////////////////////////////////////////7
    TablaModelT *TFmeTest::GetTablaModel()
    {
      return model;
    }
 /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    QComboBox *TFmeTest::GetVisualizarReg()
    {
        return VisualizarReg;
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Inicializar la rejilla de visualizacion general.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void TFmeTest::InicializarRejilla()
    {
      unsigned i, j;

      // Establecemos el numero de filas y columnas
      MatrizTestS = new QString*[NumRegistros + 1];
      listaH.append("TOT");
      listaV.append("TOT");
      // Cargamos los titulos
      MatrizTestS[0] = new QString[NumEdits+1];
      for (i = 1; i < (unsigned)NumRegistros + 1; i++) {
        listaV.append(ListaIds->at(i - 1));
        MatrizTestS[i] = new QString[NumEdits+1];
        view->setRowHeight(i, 5);
      }
      view->setColumnWidth(0, ANCHO_COLUMNA_ESTANDAR);
      for (j = 1; j < (unsigned)NumEdits+1; j++) {
        listaH.append(QString::number(FmeEditsAsociados->GetIdEdit(j - 1), 10));
        view->setColumnWidth(j, ANCHO_COLUMNA_ESTANDAR);
      }  
      MatrizTestS[0][0] = "----";
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Inicializar la rejilla de visualizacion de registros.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void TFmeTest::InicializarRejillaRegistro()
    {
      unsigned j;

      // Establecemos el numero de filas y columnas
      VectorTestR = new QString[FmeMicroDatosAsociados->GetNumVariables()];
      // Establecemos los titulos en la primera fila
      for (j = 0; j < (unsigned)FmeMicroDatosAsociados->GetNumVariables(); j++)
      {
        listaH2.append(FmeMicroDatosAsociados->GetTablaModel()->headerData(j, Qt::Horizontal, Qt::DisplayRole).toString());
      }
      listaV2.append("");
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Inicializar la matriz de test.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void TFmeTest::InicializarMatrizTest()
    {
      unsigned i, j;

      MatrizTest = new bool*[NumRegistros];
      for (i = 0; i < NumRegistros; i++)
      {
        MatrizTest[i] = new bool[NumEdits];
        for (j = 0; j < NumEdits; j++)
          MatrizTest[i][j] = false;
      }
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Inicializar los vectores totales.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void TFmeTest::InicializarVectoresTotales()
    {
      VectorTotalesPorFilas = new unsigned[NumRegistros];
      VectorTotalesPorColumnas = new unsigned[NumEdits];
      VectorTotalesPorFilasOriginal = new unsigned[NumRegistros];
      VectorTotalesPorColumnasOriginal = new unsigned[NumEdits];
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Inicializar los vectores de exclusion.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void TFmeTest::InicializarVectoresExclusion()
    {
      VectorExclusionRegistros = new bool[NumRegistros];
      VectorExclusionEdits = new bool[NumEdits];
      ResetearVectoresExclusion();
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Inicializar los cuadros de exclusion.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void TFmeTest::InicializarCuadrosExclusion()
    {
      EdtExclusionRegistros->setText(QString::number((int)(PORCENTAJE_INICIAL_EXCLUSION_REG_TEST * NumEdits), 10));
      EdtExclusionEdits->setText(QString::number((int)(PORCENTAJE_INICIAL_EXCLUSION_EDITS * NumRegistros), 10));
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Inicializar el sistema de progreso.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void TFmeTest::InicSistemaProgreso()
    {
      PbrProgreso->setRange (0, NumRegistros);
      PbrProgreso->setValue(0);
      EdtPorcentaje->setText("0%");
      EdtElemento->setText("(" + QString::number(PbrProgreso->value(), 10) + "/" + QString::number(PbrProgreso->maximum(), 10) + ")");
      QApplication::processEvents();
    }
    
    void TFmeTest::InicSistemaProgreso2()
    {
      PbrProgreso->setRange (0, 7);
      PbrProgreso->setValue(0);
      EdtPorcentaje->setText("0%");
      EdtElemento->setText("(" + QString::number(PbrProgreso->value(), 10) + "/" + QString::number(PbrProgreso->maximum(), 10) + ")");
      QApplication::processEvents();
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Incrementar el sistema de progreso.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void TFmeTest::IncSistemaProgreso()
    {
      PbrProgreso->setValue(PbrProgreso->value()+1);
      EdtElemento->setText("(" + QString::number(PbrProgreso->value(), 10) + "/" + QString::number(PbrProgreso->maximum(), 10) + ")");
      EdtPorcentaje->setText(QString::number(((double)PbrProgreso->value() / (double)PbrProgreso->maximum()) * 100, 'f', 2).replace('.', ',') + "%");
      QApplication::processEvents();
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Mostrar la informacion asociada a la fila y a la columna.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void TFmeTest::MostrarInfoAsociada(unsigned Fila, unsigned Columna, bool Fijar)
    {
      static unsigned UltimaFila = 0, UltimaColumna = 0;
      unsigned FilaS = listaV.indexOf(model->headerData(Fila, Qt::Vertical, Qt::DisplayRole).toString());
      LabBarraEstado2->setText("[" + tr("Registro: ") + QString::number(Fila, 10) + ", " + QApplication::translate("", "Regla: ") + QString::number(Columna, 10) + "]");
      if ((Columna != UltimaColumna) || Fijar)
        EdtEdit->setText(FmeEditsAsociados->GetEdit(Columna-1));
      if ((FilaS != UltimaFila) || Fijar) {
        for (int i = 0; i < FmeMicroDatosAsociados->GetNumVariables(); i++)
          VectorTestR[i] = FmeMicroDatosAsociados->GetValorS(FilaS - 1, i);
        listaV2[0] = FmeMicroDatosAsociados->GetTablaModel()->headerData(FilaS - 1, Qt::Vertical, Qt::DisplayRole).toString();
        model2->setCabeceraV(listaV2);
        model2->setHeaderData(0, Qt::Vertical, QVariant(), Qt::DisplayRole);
      }

      QPalette palette2( QApplication::palette() );
      if (!MatrizTest[FilaS - 1][Columna - 1]) {
        palette2.setColor( QPalette::Active, QPalette::Base, CL_FALSE );
        EdtEdit->setPalette(palette2);
      }else {
        palette2.setColor( QPalette::Active, QPalette::Base, Qt::gray );
        EdtEdit->setPalette(palette2);
      }
      if (Fijar) {
        view->setCurrentIndex(view->indexAt(QPoint(view->columnViewportPosition(Columna), view->rowViewportPosition(Fila))));
        QColor rojo = view->currentIndex().model()->data(view->currentIndex(), Qt::BackgroundRole).value<QColor>();
        QString color = rojo.name();
        setStyleSheet("selection-color: black;selection-background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 " + color + ", stop: 1 gray);");
      }
      // Forzamos a repintar la rejilla de registro
      repintarRegistro(Columna);

      UltimaFila = FilaS;
      UltimaColumna = Columna;      
    }
    void TFmeTest::MostrarInfoAsociada(unsigned Fila, unsigned Columna, unsigned numreg, bool Fijar, QStringList listah, QString **matriz, QStringList listav)
    {
     if (numreg == 0)
            LabBarraEstado2->setText(tr("[Registro: 0, Regla: 0]"));
      else {
      static unsigned UltimaFila = 0, UltimaColumna = 0;
      unsigned FilaS = listaV.indexOf(listav.at(Fila));
      LabBarraEstado2->setText("[" + tr("Registro: ") + QString::number(Fila, 10) + ", " + QApplication::translate("", "Regla: ") + QString::number(Columna, 10) + "]");
      if ((Columna != UltimaColumna) || Fijar)
        EdtEdit->setText(FmeEditsAsociados->GetEdit(Columna-1));
      if ((FilaS != UltimaFila) || Fijar) {
        for (int i = 0; i < FmeMicroDatosAsociados->GetNumVariables(); i++)
          VectorTestR[i] = FmeMicroDatosAsociados->GetValorS(FilaS - 1, i);
        listaV2[0] = FmeMicroDatosAsociados->GetTablaModel()->headerData(FilaS - 1, Qt::Vertical, Qt::DisplayRole).toString();
        model2->setCabeceraV(listaV2);
        model2->setHeaderData(0, Qt::Vertical, QVariant(), Qt::DisplayRole);
      }

      QPalette palette2( QApplication::palette() );
      if (!MatrizTest[FilaS - 1][Columna - 1]) {
        palette2.setColor( QPalette::Active, QPalette::Base, CL_FALSE );
        EdtEdit->setPalette(palette2);
      }else {
        palette2.setColor( QPalette::Active, QPalette::Base, Qt::gray );
        EdtEdit->setPalette(palette2);
      }
      if (Fijar) {
        view->setCurrentIndex(view->indexAt(QPoint(view->columnViewportPosition(Columna), view->rowViewportPosition(Fila))));
        QColor rojo = view->currentIndex().model()->data(view->currentIndex(), Qt::BackgroundRole).value<QColor>();
        QString color = rojo.name();
        setStyleSheet("selection-color: black;selection-background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 " + color + ", stop: 1 gray);");
      }
      // Forzamos a repintar la rejilla de registro
      repintarRegistro(Columna);

      UltimaFila = FilaS;
      UltimaColumna = Columna;
      }
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Resetear los vectores totales.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void TFmeTest::ResetearVectoresTotales()
    {
      unsigned i, j;

      for (i = 0; i < NumRegistros; i++)
        VectorTotalesPorFilasOriginal[i] = 0;
      for (j = 0; j < NumEdits; j++)
        VectorTotalesPorColumnasOriginal[j] = 0;
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Resetear los vectores de exclusion.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void TFmeTest::InicializarListasExclusionAPriori()
    {
      unsigned i, j;

      for (i = 0; i < NumRegistros; i++)
        if (FmeRangosAsociados->RegistroExcluido(i))
          RegistrosExcluidosAPriori.insert(i);

      for (j = 0; j < NumEdits; j++)
        if (EditConVariableExcluida(j))  
          EditsExcluidosAPriori.insert(j);
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Resetear los vectores de exclusion.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void TFmeTest::ResetearVectoresExclusion()
    {
      unsigned i, j;

      for (i = 0; i < NumRegistros; i++)
        VectorExclusionRegistros[i] = false;

      for (j = 0; j < NumEdits; j++)
        VectorExclusionEdits[j] = false;
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Resetear las listas de exclusion.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void TFmeTest::ResetearListasExclusion()
    {
      EditsExcluidos.clear();
      RegistrosExcluidos.clear();
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Resetear las listas de exclusion a priori.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void TFmeTest::ResetearListasExclusionAPriori()
    {
      EditsExcluidosAPriori.clear();
      RegistrosExcluidosAPriori.clear();
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Salvar en un fichero los porcentajes de error de los edits.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void TFmeTest::SalvarPorcentajesErrorEdits(QString NombreFichero, double PorcentajeUmbral)
    {
      QStringList *t = new QStringList();
      double percentage;
      unsigned i, j, n = 0;
      QString Linea;

      t->append(tr("Porcentajes de error de reglas"));
      if (PorcentajeUmbral > 0)
      {
        t->append("======================================================");
        t->append(tr("Mostrando aquellas reglas con un porcentaje de error mayor o igual que el") + " " + QString::number(PorcentajeUmbral, 'f', 2) + "%");
      }
      t->append("=================================");
      for (j = 0; j < NumEdits; j++)
      {
        percentage = ((double)VectorTotalesPorColumnas[j] / (double)NumRegistros) * 100;
        if (percentage >= PorcentajeUmbral)
        {
          Linea = "E" + QString::number(j + 1, 10) + ": " + QString::number(percentage, 'f', 2) + "% [" + QString::number(VectorTotalesPorColumnas[j], 10) + "] {";
          for (i = 0; i < NumRegistros; i++)
            if (!(GetTestEdit(i, j)))
              Linea += " R" + QString::number((i+1), 10);
          Linea += "}";
          t->append(Linea);
          n++;
        }
      }
      t->append("");
      t->append(tr("Reglas listadas") + " : " + QString::number(n, 10));

      t->append("");
      t->append("======================================================");
      t->append(QApplication::translate("", "Reglas que est\303\241n excluidas", 0, QApplication::UnicodeUTF8));
      t->append("======================================================");
      t->append("");

      n = 0;
      for (j = 0; j < NumEdits; j++)
      {
        if (EditExcluido(j))
        {
          percentage = ((double)VectorTotalesPorColumnas[j] / (double)NumRegistros) * 100;
          t->append("E" + QString::number(j + 1, 10) + ": " + QString::number(percentage, 'f', 2) + "% [" + QString::number(VectorTotalesPorColumnas[j], 10) + "]");
          n++;
        }
      }
      t->append("");
      t->append(tr("Reglas listadas") + " : " + QString::number(n, 10));

      QString texto = t->join(QString('\n'));
      QFile f( NombreFichero );
      if ( !f.open( QIODevice::WriteOnly ) )
          QMessageBox::warning(this, "Warning", tr( "No se puede escribir en el fichero %1" ).arg( NombreFichero ), "&Ok");
      else {
        QTextStream s( &f );
        s << texto;
        f.close();
      }      
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Salvar en un fichero los porcentajes de error de los registros.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void TFmeTest::SalvarPorcentajesErrorRegistros(QString NombreFichero, double PorcentajeUmbral)
    {
      QStringList *t = new QStringList();
      double percentage;
      unsigned i, j, n = 0;
      QString Linea;

      t->append(QApplication::translate("", "Porcentajes de error de registros (evaluaci\303\263n de reglas)", 0, QApplication::UnicodeUTF8));
      if (PorcentajeUmbral > 0)
      {
        t->append("======================================================");
        t->append(tr("Mostrando aquellos registros con un porcentaje de error mayor o igual que el") + " " + QString::number(PorcentajeUmbral, 'f', 2) + "%");
      }
      t->append("======================================================");
      for (i = 0; i < NumRegistros; i++)
      {
	percentage = ((double)VectorTotalesPorFilas[i] / (double)NumEdits) * 100;
	if (percentage >= PorcentajeUmbral)
	{
          Linea = ListaIds->at(i) + ": " + QString::number(percentage, 'f', 2) + "% [" + QString::number(VectorTotalesPorFilas[i], 10) + "] { ";
  	  for (j = 0; j < NumEdits; j++)
	    if (!(GetTestEdit(i, j)))
	      Linea += ("E" + QString::number(j + 1, 10) + " ");
    	  Linea += "}";
	  t->append(Linea);
  	  n++;
	}
      }
      t->append("");
      t->append(tr("Registros listados") + ": " + QString::number(n));

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
	  percentage = ((double)VectorTotalesPorFilas[i] / (double)NumEdits) * 100;
          t->append("[" + QString::number(i+1, 10) + "] " + ListaIds->at(i) + ": " + QString::number(percentage, 'f', 2) + "% [" + QString::number(VectorTotalesPorFilas[i], 10) + "]");
          n++;
	}
      }
      t->append("");
      t->append(tr("Registros listados") + ": " + QString::number(n));

      QString text = t->join(QString('\n'));
      QFile f( NombreFichero );
      if ( !f.open( QIODevice::WriteOnly ) )
        QMessageBox::warning(this, "Warning", tr( "No se puede escribir en el fichero %1" ).arg( NombreFichero ), "&Ok");
      else {
        QTextStream s( &f );
        s << text;
        f.close();
      }
      delete t;
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Testear los MicroDatos con los Edits.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void TFmeTest::TestearMicroDatos()
    {
      unsigned i;
      
      FijarCantidadDatos();
      PanProgreso->show();
      InicSistemaProgreso();

      // Resetear las listas de exclusion a priori
      ResetearListasExclusionAPriori();
      // Resetear los vectores totales
      ResetearVectoresTotales();
      // Inicializar las listas de exclusion a priori
      InicializarListasExclusionAPriori();
      // Actualizar los porcentajes de exclusion
      ActualizarUmbralExclusion();

      for (i = 0; i < NumRegistros; i++)
      {
        if (ActualizarEvaluacionRegistro(i, false))          
          ;

        IncSistemaProgreso();
      }

      ButAplicarExclusionClick();

      CargarTestEnRejilla();

      /*GbxHistograma->setActiveSerieColumnas(false);
      GbxHistograma->setActiveSerieRegistros(true);
      GbxHistograma->setTitle(QApplication::translate("", "N\303\232MERO DE ERRORES [ejeX: Ordinal de registros, ejeY: N\303\272mero de errores]", 0, QApplication::UnicodeUTF8));
*/
      MostrarInfoAsociada(1, 1, true);
      Cargado = true;

      PanProgreso->hide();

      PanContenedor->show();      

      InstanteFinalizacion = QTime::currentTime();
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Preparar la interface por si han habido cambios en el numero de edits.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void TFmeTest::PrepararInterface()
    {
      InstanteComienzo = QTime::currentTime();
      
      PanProgreso->show();
      InicSistemaProgreso2();
      // Fijar la cantidad de datos
      FijarCantidadDatos();
      IncSistemaProgreso();
      // Inicializamos las rejillas
      InicializarRejilla();
      IncSistemaProgreso();
      
      InicializarRejillaRegistro();
      model2 = new TablaModelInfoR(0, VectorTestR, listaH2, listaV2);
      view2->setModel(model2);

      IncSistemaProgreso();

      model = new TablaModelT(0, MatrizTestS, listaH, listaV);
      view->setModel(model);

      // Inicializar la matriz de test
      InicializarMatrizTest();
      IncSistemaProgreso();
      // Inicializar los vectores totales
      InicializarVectoresTotales();
      IncSistemaProgreso();
      // Inicializar los vectores de exclusion
      InicializarVectoresExclusion();
      IncSistemaProgreso();
      // Inicializar los cuadros de exlusion colocando en ellos el numero de errores por defecto
      InicializarCuadrosExclusion();
      IncSistemaProgreso();
      PanProgreso->hide();
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Pinta la rejilla principal.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void TFmeTest::repintar(int i, int j)
    {}
    void TFmeTest::repintar(int i, int j, QString texto)
    {}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Pinta la rejilla registro.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void TFmeTest::repintarRegistro(int col)
    {      
      QString *v = new QString[FmeMicroDatosAsociados->GetNumVariables()];
      for (int i = 0; i < FmeMicroDatosAsociados->GetNumVariables(); i++) {
        if (FmeEditsAsociados->VariableEnEdit(i, col - 1)) {
           v[i] = "Yellow";           
        }else {
           v[i] = "Otro";           
        }
      }
      model2->setVectorPintar(v);     
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Fijar el ancho de las columnas de la rejilla principal y rejilla registro.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void TFmeTest::FijarAnchoColumnasRejilla(unsigned ancho)
    {
      unsigned j;
      
      for (j = 0; j < NumEdits + 1; j++)
      {
	view->setColumnWidth(j, ancho);	
      }
    }

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// PULSAR EL BOTON DE APLICAR LA EXCLUSION.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void TFmeTest::ButAplicarExclusionClick()
    {
      ActualizarUmbralExclusion();      
      AplicarExclusion();      
      CargarResultados();      
    }
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// HACER DOBLE CLICK SOBRE EL EDIT DE EDITS.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void TFmeTest::EdtEditClick()
    {
      QMessageBox::information(this, QApplication::translate("", "Informaci\303\263n", 0, QApplication::UnicodeUTF8),  EdtEdit->text(), "&Ok");
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// PULSAR UNA TECLA EN EL EDIT DE IR A REGISTRO.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void TFmeTest::EdtIrARegistroPorNumeroKeyDown()
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
      if ((IndiceRegistro >= 1) && (IndiceRegistro <= model->rowCount(view->currentIndex())))
        view->setCurrentIndex(view->indexAt(QPoint(view->columnViewportPosition(view->currentIndex().column()), view->rowViewportPosition(IndiceRegistro))));
      EdtIrARegistroPorNumero->setText("");      
      SgrRejillaSelectCell(view->currentIndex());
      view->setFocus();
    }
    void TFmeTest::CbxIrARegistroPorNombreCloseUp(int index)
    {      
      view->setCurrentIndex(view->indexAt(QPoint(view->columnViewportPosition(view->currentIndex().column()), view->rowViewportPosition(index+1))));
      SgrRejillaSelectCell(view->currentIndex());
      view->setFocus();
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// PULSAR UNA TECLA EN EL EDIT DE IR A EDIT.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void TFmeTest::EdtIrAEditKeyDown()
    {
      int IndiceEdit;

      //try
      //{
        IndiceEdit = EdtIrAEdit->text().toInt();
      /*}
      catch (...)
      {
        EdtIrAEdit->setText("");
        return;
      }*/
      if ((IndiceEdit >= 1) && (IndiceEdit <= NumEdits))
        view->setCurrentIndex(view->indexAt(QPoint(view->columnViewportPosition(IndiceEdit), view->rowViewportPosition(view->currentIndex().row()))));
      EdtIrAEdit->setText("");      
      SgrRejillaSelectCell(view->currentIndex());
      view->setFocus();
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// SELECCIONAR UNA CELDA DE LA REJILLA.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void TFmeTest::SgrRejillaSelectCell(const QModelIndex& index)
    {
      if (index.model()->rowCount(index) > 0)
      {
        if ((index.row() >= 1) && (index.column() >=1))
          MostrarInfoAsociada(index.row(), index.column(), true);
        else
          LabBarraEstado2->setText("[" + tr("Registro") + ": 0, Regla: 0]");
      }
    }
    void TFmeTest::SgrRejillaSelectCellV(const int& index)
    {
      int fila = view->currentIndex().row();
      int col = 1;
      MostrarInfoAsociada(fila, col, false);
    }
    void TFmeTest::SgrRejillaSelectCellH(const int& index)
    {
      if (view->verticalHeader()->length() > 0)
      {
        int fila = 1;
        int col = view->currentIndex().column();
        MostrarInfoAsociada(fila, col, false);
      }
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// COPIAR EL IDENTIFICADOR DEL REGISTRO ACTUAL.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void TFmeTest::MitCopiarIdentificadorRegistroClick()
    {
      QApplication::clipboard()->setText(listaV.at(view->currentIndex().row()));      
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// COPIAR EL IDENTIFICADOR DE LA VARIABLE ACTUAL.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void TFmeTest::MitCopiarIdentificadorEditClick()
    {
      QApplication::clipboard()->setText(listaH.at(view->currentIndex().column()));       
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// PULSAR UNA TECLA SOBRE LA REJILLA REGISTRO.
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void TFmeTest::SgrRejillaRegKeyDownCR()
    {
      unsigned Columna;
      
      Columna = BuscarVariableDerecha(view2->currentIndex().column());      
      view2->clearSelection();
      view2->setCurrentIndex(view2->indexAt(QPoint(view2->columnViewportPosition(Columna), view2->rowViewportPosition(0))));
      view2->setFocus();
    }
    void TFmeTest::SgrRejillaRegKeyDownCL()
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
    void TFmeTest::SgrRejillaKeyDownAR()
    {
      unsigned Fila, Columna;      

      if (VisualizarReg->currentIndex() != 1) {
        QModelIndex index = view->currentIndex();

        Fila = listaV.indexOf(model->headerData(index.row(), Qt::Vertical, Qt::DisplayRole).toString());
        Columna = BuscarEditErrorDerecha(Fila, index.column());
        index = view->indexAt(QPoint(view->columnViewportPosition(Columna), view->rowViewportPosition(index.row())));
        view->setCurrentIndex(index);
        SgrRejillaSelectCell(view->currentIndex());
        view->setFocus();
      }
    }
    void TFmeTest::SgrRejillaKeyDownAL()
    {
      unsigned Fila, Columna;

      if (VisualizarReg->currentIndex() != 1) {
        QModelIndex index = view->currentIndex();

        Fila = listaV.indexOf(model->headerData(index.row(), Qt::Vertical, Qt::DisplayRole).toString());
        Columna = BuscarEditErrorIzquierda(Fila, index.column());
        index = view->indexAt(QPoint(view->columnViewportPosition(Columna), view->rowViewportPosition(index.row())));
        view->setCurrentIndex(index);
        SgrRejillaSelectCell(view->currentIndex());
        view->setFocus();
      }
    }
    void TFmeTest::SgrRejillaKeyDownAU()
    {
      unsigned Fila, Columna;      

      if (VisualizarReg->currentIndex() != 1) {
        QModelIndex index = view->currentIndex();
        Columna = index.column();      
        Fila = BuscarMicroDatoErrorArriba(listaV.indexOf(model->headerData(index.row(), Qt::Vertical, Qt::DisplayRole).toString()), Columna);
        Fila = model->GetcabeceraV().indexOf(listaV.at(Fila));
        index = view->indexAt(QPoint(view->columnViewportPosition(Columna), view->rowViewportPosition(Fila)));
        view->setCurrentIndex(index);
        SgrRejillaSelectCell(view->currentIndex());
        view->setFocus();
      }
    }
    void TFmeTest::SgrRejillaKeyDownAD()
    {
      unsigned Fila, Columna;      

      if (VisualizarReg->currentIndex() != 1) {
        QModelIndex index = view->currentIndex();
        Columna = index.column();

        Fila = BuscarMicroDatoErrorAbajo(listaV.indexOf(model->headerData(view->currentIndex().row(), Qt::Vertical, Qt::DisplayRole).toString()), Columna);
        Fila = model->GetcabeceraV().indexOf(listaV.at(Fila)); //FmeMicroDatosAsociados->GetIdRegistro(Fila-1));
        index = view->indexAt(QPoint(view->columnViewportPosition(Columna), view->rowViewportPosition(Fila)));
        view->setCurrentIndex(index);
        SgrRejillaSelectCell(view->currentIndex());
        view->setFocus();
      }
    }
    void TFmeTest::SgrRejillaKeyDownCZ()
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
// HACER DOBLE CLICK SOBRE LA REJILLA DE REGISTRO.
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void TFmeTest::SgrRejillaRegistroDblClick(const QModelIndex& index)
    {
      rejillaregistro = true;
      connect(FrmIrAVariable->GetButAplicar(), SIGNAL(clicked()), this, SLOT(ButAplicarIrAVariableClick()));
      connect(FrmIrAVariable->GetButCancelar(), SIGNAL(clicked()), this, SLOT(ButCancelarIrAVariableClick()));
      FrmIrAVariable->show();
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// PULSAR EL BOTON DE SALVAR ERROR EDITS.
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void TFmeTest::ButSalvarErrorEditsClick()
    {
      QString start = QCoreApplication::applicationDirPath();
      QString meta = QDir::convertSeparators(start + "/" + DIRECTORIO_STATS);
      QString NombreFichero = QFileDialog::getSaveFileName(this, tr("Guardar fichero stats"), meta, "TXT (*.txt)");
      if (!NombreFichero.isEmpty())
        SalvarPorcentajesErrorEdits(NombreFichero, (double)EdtUmbralErrorEdits->value());      
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// PULSAR EL BOTON DE SALVAR ERROR REGISTROS.
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void TFmeTest::ButSalvarErrorRegistrosClick()
    {
      QString start = QCoreApplication::applicationDirPath();
      QString meta = QDir::convertSeparators(start + "/" + DIRECTORIO_STATS);
      QString NombreFichero = QFileDialog::getSaveFileName(this, tr("Guardar fichero stats"), meta, "TXT (*.txt)");
      if (!NombreFichero.isEmpty())
        SalvarPorcentajesErrorRegistros(NombreFichero, (double)EdtUmbralErrorRegistros->value());      
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// DOBLE CLICK SOBRE LA REJILLA DE EVALUACION.
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void TFmeTest::SgrRejillaDblClick(const QModelIndex& index)
    {
      if ((VisualizarReg->currentIndex() == 0) && (principal->count() < 6)) {
          rejillaregistro = false;
          FrmIrAVariable->show();
      }      
    }
    void TFmeTest::ButAplicarIrAVariableClick()
    {
      unsigned IndiceRegistro, IndiceVariable;
      double Valor;

      if (FrmIrAVariable->GetRbnombre()->isChecked())
        FrmIrAVariable->SetVariableSeleccionada(FrmIrAVariable->GetCbxPorNombre()->currentIndex());
      else
        FrmIrAVariable->SetVariableSeleccionada(FrmIrAVariable->GetCbxPorNumero()->currentIndex());
      FrmIrAVariable->hide();
      IndiceVariable = FrmIrAVariable->GetVariableSeleccionada();
      if (rejillaregistro){
        view2->setCurrentIndex(view2->indexAt(QPoint(view2->columnViewportPosition(IndiceVariable), view2->rowViewportPosition(0))));
        view2->setFocus();        
      }else {
        IndiceRegistro = view->currentIndex().row() - 1;

        Valor = FmeMicroDatosAsociados->GetValor(IndiceRegistro, IndiceVariable);
        FrmCambiarMicrodato->FijarParametros(FmeRangosAsociados->GetTablaModel()->headerData(IndiceVariable + 1, Qt::Horizontal, Qt::DisplayRole).toString(), IndiceRegistro+1, Valor);

        FrmCambiarMicrodato->show();
      }      
    }

    void TFmeTest::ButCancelarIrAVariableClick()
    {      
      FrmIrAVariable->hide();
    }
    void TFmeTest::ButAceptarCambiarMicrodatoClick()
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

    void TFmeTest::ButCancelarCambiarMicrodatoClick()
    {
       FrmCambiarMicrodato->hide();
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// PINCHAR LA OPCION DE MENU DE AUMENTAR EL TAMAO DE LAS COLUMNAS.
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void TFmeTest::MitAumentarColumnasClick()
    {
      FijarAnchoColumnasRejilla(view->columnWidth(2) + 50);
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// PINCHAR LA OPCION DE MENU DE DISMINUIR EL TAMANNO DE LAS COLUMNAS.
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void TFmeTest::MitDisminuirColumnasClick()
    {
      FijarAnchoColumnasRejilla(view->columnWidth(2) - 50);
    }

    void TFmeTest::VisualizarMenu(const QModelIndex& index)
    {
      if (view->boton()) 
        menu->popup(QCursor::pos());
    }
 /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
 // PINCHAR SOBRE LOS BOTONES ANT Y SIG DEL HISTOGRAMA.
 //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
     void TFmeTest::ButClick_sig()
    {
      GbxHistograma->ButClick_sig();
    }
    void TFmeTest::ButClick_ant()
    {
      GbxHistograma->ButClick_ant();
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// MODO DE VISUALIZAR LA TABLA DE TEST.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void TFmeTest::VisualizarRegCloseUp(int index)
    {
      QString **MatrizRegA;
      //QStringList listaHA;
      QStringList listaVA;
      QStringList listaHA;
      int *editcor;
      int i, j, k;
      view->showColumn(0);
      view->showRow(0);
      if (index == 0) {
          delete model;          
          model = new TablaModelT(0, MatrizTestS, listaH, listaV);          
          model->setVectorPosReg(editcor, true);
          view->setModel(model);
          MostrarInfoAsociada(1, 1, NumRegistros, true, listaH, MatrizTestS, listaV);
          ButSalvarErrorEdits->setEnabled(true);
          ButSalvarErrorRegistros->setEnabled(true);
          ButAplicarExclusion->setEnabled(true);
          CbxIrARegistroPorNombre->clear();
          CbxIrARegistroPorNombre->addItems(*ListaIds);
          view->hideColumn(0);
          view->hideRow(0);          
      }else {
          if (index == 1) {              
              listaHA.clear();
              listaVA.clear();
              MatrizRegA = new QString*[NumRegistrosCorrectos+1];
              editcor = new int[NumRegistrosCorrectos+1];
              j = 0;
              MatrizRegA[j] = new QString[NumEdits+1];
              for (k = 0; k < NumEdits+1; k++)
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
                      MatrizRegA[j] = new QString[NumEdits+1];
                      for (k = 0; k < NumEdits+1; k++)
                      {
                          MatrizRegA[j][k] = MatrizTestS[i][k];

                      }
                      listaVA.append(listaV.at(i));
                      editcor[j] = i;
                      j++;
                  }
              }              
              listaHA = listaH;
              listaHA.replaceInStrings(QRegExp("(\\s\\d+\\s\\(\\d+,\\d+%\\))"), "");
              model->setVectorPosReg(editcor, false);              
              model->setCurrencyMap(MatrizRegA);   // cuando modifiquemos la matriz
              model->setCurrencyCabecV(listaVA);   // cuando modifiquemos la cabeceraV
              model->setCurrencyCabecH(listaHA);
              MostrarInfoAsociada(1, 1, NumRegistrosCorrectos, true, listaH, MatrizRegA, listaVA);
              ButSalvarErrorEdits->setEnabled(false);
              ButSalvarErrorRegistros->setEnabled(false);
              ButAplicarExclusion->setEnabled(false);
              CbxIrARegistroPorNombre->clear();
              CbxIrARegistroPorNombre->addItems(listaVA.replaceInStrings(QRegExp("(\\|+\\s\\d+\\s\\(\\d+,\\d+%\\))"), ""));
              CbxIrARegistroPorNombre->removeItem(0);
              view->hideColumn(0);
              view->hideRow(0);
          }else {              
              listaHA.clear();
              listaVA.clear();
              MatrizRegA = new QString*[NumRegistrosIncorrectos+1];
              editcor = new int[NumRegistrosIncorrectos+1];
              j = 0;
              MatrizRegA[j] = new QString[NumEdits+1];
              for (k = 0; k < NumEdits+1; k++)
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
                      MatrizRegA[j] = new QString[NumEdits+1];
                      for (k = 0; k < NumEdits+1; k++)
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
              ButSalvarErrorEdits->setEnabled(false);
              ButSalvarErrorRegistros->setEnabled(false);
              ButAplicarExclusion->setEnabled(false);
              CbxIrARegistroPorNombre->clear();
              CbxIrARegistroPorNombre->addItems(listaVA.replaceInStrings(QRegExp("(\\|+\\s\\d+\\s\\(\\d+,\\d+%\\))"), ""));
              CbxIrARegistroPorNombre->removeItem(0);
              view->hideColumn(0);
              view->hideRow(0);
          }
      }      
    }
