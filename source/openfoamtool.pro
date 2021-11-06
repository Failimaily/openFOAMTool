QT += core gui opengl
QT += widgets
QT += help
QT += printsupport
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
QT_OPENGL=desktopt
CONFIG += c++11 file_copies
#QMAKE_LFLAGS += -Wl,-rpath,"'$$ORIGIN'"
# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    glwidget.cpp \
    helpWindow/helpbrowser.cpp \
    helpWindow/helpwindow.cpp \
    logger.cpp \
    main.cpp \
    mainwindow.cpp \
    modelloader.cpp \
    projectsettings.cpp \
    qCustomPlot/qcustomplot.cpp \

HEADERS += \
    Singleton.h \
    assimp/Importer.hpp \
    assimp/material.h \
    assimp/postprocess.h \
    assimp/scene.h \
    glwidget.h \
    helpWindow/helpbrowser.h \
    helpWindow/helpwindow.h \
    logger.h \
    mainwindow.h \
    modelloader.h \
    projectsettings.h \
    qCustomPlot/qcustomplot.h \

FORMS += \
    helpWindow/helpwindow.ui \
    mainwindow.ui
# Copies Help Documentation Files to build folder
COPIES += helpFiles
COPIES += presetFiles
helpFiles.files += $$files(helpContainer/*.qch)
helpFiles.files += $$files(helpContainer/*.qhc)
helpFiles.path = $$OUT_PWD/help

presetFiles.files += $$files(presets/*)
presetFiles.path = $$OUT_PWD/presets

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target




unix:!macx: LIBS += -lassimp



#win32:CONFIG(release, debug|release): LIBS += -L$$PWD/libassimp/bin/release/ -lassimp
#else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/libassimp/bin/debug/ -lassimp
#else:unix: LIBS += -L$$PWD/libassimp/bin/ -lassimp

#INCLUDEPATH += $$PWD/libassimp/bin
#DEPENDPATH += $$PWD/libassimp/bin
