# ----------------------------------------------------
# This file is generated by the Qt Visual Studio Add-in.
# ------------------------------------------------------

TEMPLATE = app
TARGET = SJTUFlow
QT += core opengl widgets gui
DEFINES += QT_DLL QT_OPENGL_LIB QT_WIDGETS_LIB
INCLUDEPATH += . \
    ../include
LIBS += -lopengl32 \
    -lglu32
win32{
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
}
DEPENDPATH += .
UI_DIR += ./GeneratedFiles
RCC_DIR += ./GeneratedFiles
HEADERS += ./qhorizontaltabbar.h \
    ./qhorizontaltabwidget.h \
    ./sjtuflow.h \
    ./rendersetting.h \
    ./runsetting.h \
    ./titlebar.h \
    ./codingwidget.h \
    ./displaywidget.h \
    ./codeedit.h \
    ./dllmanager.h \
    ./pysyntaxhighlighter.h \
    ./scene.h \
    ./primitive.h \
    ./scenedesignwidget.h
SOURCES += ./codeedit.cpp \
    ./codingwidget.cpp \
    ./displaywidget.cpp \
    ./dllmanager.cpp \
    ./primitive.cpp \
    ./rendersetting.cpp \
    ./runsetting.cpp \
    ./scene.cpp \
    ./main.cpp \
    ./pysyntaxhighlighter.cpp \
    ./qhorizontaltabbar.cpp \
    ./qhorizontaltabwidget.cpp \
    ./scenedesignwidget.cpp \
    ./sjtuflow.cpp \
    ./titlebar.cpp
FORMS += ./sjtuflow.ui \
    ./scenedesignwidget.ui \
    ./codingwidget.ui \
    ./displaywidget.ui \
    ./titlebar.ui \
    ./runsetting.ui \
    ./rendersetting.ui \
    ./dllmanager.ui
RESOURCES += sjtuflow.qrc