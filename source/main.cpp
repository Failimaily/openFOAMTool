/*! \mainpage A OpenFOAM Toolbox
 *  \section Overview
 *  This software toolbox was created for OpenFOAM v6. \n
 *  This software includes common OpenFOAM functions, such as blockMesh, snappyHexMesh and simpleFoam and pisoFoam.
 *  There are also some custom features not directly included from OpenFOAM, such as a residual plot, and a modelViewer.
 *  \section build How to build
 *  \subsection step1  1.Qt Framework
 *  First you need to install Qt 5.12.11 from <a href="https://www.qt.io/offline-installers">here</a> and follow the instructions.
 *  Do not forget to install the QT Charts Addon from the installer. \n
 *  Do not forget to add the /<qt-installation>/5.12.11/gcc_64/bin to the $PATH variable.
 *  \subsection step2 2.Assimp
 *  Secondly you need to install the Open Asset Import Library (assimp) from
 *  <a href="https://github.com/assimp/assimp/blob/master/Build.md"> here</a> and follow the instructions listed there. \n
 *  Do not forget to copy the library files in assimp/bin to usr/lib/
 *  \subsection step3 3.Build
 *  If you have installed Qt and Assimp correctly you should now be able to execute the following commands. \n
 *  1. mkdir build \n
 *  2. cd build \n
 *  3. qmake ../source/openfoamtool.pro \n
 *  4. make \n
 *  5. make clean
 *  \subsection step4 4.Finishing touches
 *  You may need to add "export MESA_GL_VERSION_OVERRIDE=3.3" to your ~/.bashrc if you encounter an openGL version error. \n
*/

#include "mainwindow.h"
#include <QApplication>
#include "projectsettings.h"
int main(int argc, char *argv[])
{
    g_pprojectsettings->Init();
    qDebug() << g_pprojectsettings->modelName;
    QApplication a(argc, argv);
    a.setAttribute(Qt::AA_UseDesktopOpenGL);
    QSurfaceFormat f;
    f.setVersion(3,3);
    f.setProfile(QSurfaceFormat::CoreProfile);
    QSurfaceFormat::setDefaultFormat(f);
    MainWindow w;
    w.show();
    return a.exec();
}
