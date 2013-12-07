# ----------------------------------------------------
# This file is generated by the Qt Visual Studio Add-in.
# ------------------------------------------------------

TEMPLATE = app
TARGET = SJTUFlow
QT += core opengl widgets gui xml
DEFINES += QT_DLL QT_OPENGL_LIB QT_WIDGETS_LIB QT_XML_LIB
INCLUDEPATH += . \
    ../include
win32{
    LIBS += -lopengl32 \
        -lglu32
    CONFIG(debug, debug|release){
        LIBS += -L../lib/ -lQGLViewerd2
        DESTDIR = ../Win32/Debug
        MOC_DIR += ./GeneratedFiles/debug
        OBJECTS_DIR += debug
    }else{
        LIBS += -L../lib/ -lQGLViewer2
        DESTDIR = ../Win32/Release
        MOC_DIR += ./GeneratedFiles/release
        OBJECTS_DIR += release
    }
    RC_FILE = SJTUFlow.rc
}macx{
    CONFIG(debug, debug|release){
        LIBS += -L../lib/ -lQGLViewerd.2.4.0
        DESTDIR = ../Mac/Debug
        MOC_DIR += ./GeneratedFiles/debug
        OBJECTS_DIR += debug
    }else{
        LIBS += -L../lib/ -lQGLViewer.2.4.0
        DESTDIR = ../Mac/Release
        MOC_DIR += ./GeneratedFiles/release
        OBJECTS_DIR += release
    }
}
DEPENDPATH += .
UI_DIR += ./GeneratedFiles
RCC_DIR += ./GeneratedFiles
HEADERS += ./qhorizontaltabbar.h \
    ./qhorizontaltabwidget.h \
    ./sjtuflow.h \
    ./titlebar.h \
    ./codingwidget.h \
    ./displaywidget.h \
    ./codeedit.h \
    ./pysyntaxhighlighter.h \
    ./scene.h \
    ./primitive.h \
    ./scenedesignwidget.h \
    ./setting.h \
    ./objloader.h
SOURCES += ./codeedit.cpp \
    ./codingwidget.cpp \
    ./displaywidget.cpp \
    ./primitive.cpp \
    ./scene.cpp \
    ./main.cpp \
    ./pysyntaxhighlighter.cpp \
    ./qhorizontaltabbar.cpp \
    ./qhorizontaltabwidget.cpp \
    ./scenedesignwidget.cpp \
    ./sjtuflow.cpp \
    ./titlebar.cpp \
    ./setting.cpp \
    ./objloader.cpp
FORMS += ./sjtuflow.ui \
    ./scenedesignwidget.ui \
    ./codingwidget.ui \
    ./displaywidget.ui \
    ./titlebar.ui \
    ./setting.ui
RESOURCES += sjtuflow.qrc
