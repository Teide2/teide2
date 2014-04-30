TEMPLATE = app

RC_FILE = myapp.rc
unix {
    LIBS += -L/home/salome/Qt/qwt-6.1.0/lib/
    LIBS += -lqwt
    INCLUDEPATH += /home/salome/Qt/qwt-6.1.0/src/
}
TRANSLATIONS = teide2tr_ing2.ts
win32 { 
    WINDRES += -I \
    CONFIG += uic \
        3D \
        staticlib \
        dll    
    #CONFIG -= debug_and_release
    #CONFIG += release
    #CONFIG += debug
    QMAKE_YACC = bison
    QMAKE_LEX = flex
    LIBS += -LC:\Qt\qwt-6.1.0MinGW32\lib
    DebugBuild {
      LIBS += -lqwtd
    }
    ReleaseBuild {
      LIBS += -lqwt
    }
    CONFIG += embed_manifest_exe
    CONFIG -= embed_manifest_dll
    INCLUDEPATH += C:\Qt\qwt-6.1.0MinGW32\src
}

QT += xml \
    sql \
    gui \
    core \
    widgets
#QMAKE_CFLAGS += -g \    -pg
#QMAKE_CXXFLAGS += -g \    -pg
#QMAKE_LFLAGS += -pg
#QMAKE_CC = icc
#QMAKE_CXX = icpc
#QMAKE_CXXFLAGS += -fast #-parallel
#QMAKE_LINK = icpc
#QMAKE_LFLAGS += -parallel
QMAKE_CXXFLAGS += -fpermissive -fexceptions
CONFIG += warn_off
HEADERS += AvisoFiltro.h \
    AbrirMetafile.h \
    AyudaChequear.h  \
    CambiarMicrodato.h \
    CheckPoblacion.h \
    DatosChequeo.h  \
    DatosOracle.h \
    Edits.h \
    EntradaDatos.h \
    Estadisticas.h \
    ExpAna.h \
    Global.h \
   # histogram_item.h \
    Imputacion.h \
    IrAVariable.h \
    MicroDatos.h \
    NuevoMetafile.h \
    Opciones.h \
    PedirExpresion.h \
    Rangos.h \
    RanAna.h \
    RegAna.h \
    scrollarea.h \
    TablaModel.h \
    TablaModelE.h \
    TablaModelI.h \
    TablaModelInfo.h \
    TablaModelInfoR.h \
    TablaModelR.h \
    TablaModelT.h \
    TablaModelV.h \
    TareasComunes.h \
    Teide2.h \
    Test.h \
    Variables.h \
    VariablesDeEdits.h \
    Flash.h \    
    MostrarMapping.h \
    #pintar.h \
    MiTabla.h   \
    ficheroXML.h \
    AyudaOrigenDatos.h \
    MiBox.h \
    lib.h \
    lib2.h   \
    MensajeCarga.h
SOURCES += main.cpp \
    AvisoFiltro.cpp \
    AbrirMetafile.cpp \
    AyudaChequear.cpp  \
    CambiarMicrodato.cpp \
    CheckPoblacion.cpp \
    DatosChequeo.cpp   \
    DatosOracle.cpp \
    Edits.cpp \
    EntradaDatos.cpp \
    Estadisticas.cpp \
    ExpLex.cpp \
    ExpSin.cpp \
 #   histogram_item.cpp \
    Imputacion.cpp \
    IrAVariable.cpp \
    MicroDatos.cpp \
    NuevoMetafile.cpp \
    Opciones.cpp \
    PedirExpresion.cpp \
    Rangos.cpp \
    RanLex.cpp \
    RanSin.cpp \
    RegLex.cpp \
    RegSin.cpp \
    scrollarea.cpp \
    TablaModel.cpp \
    TablaModelE.cpp \
    TablaModelI.cpp \
    TablaModelInfo.cpp \
    TablaModelInfoR.cpp \
    TablaModelR.cpp \
    TablaModelT.cpp \
    TablaModelV.cpp \
    TareasComunes.cpp \
    Teide2.cpp \
    Test.cpp \
    Variables.cpp \
    VariablesDeEdits.cpp \
    MensajeCarga.cpp    \
    MiTabla.cpp




