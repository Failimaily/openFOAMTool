#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QMessageBox>
#include <QLineEdit>
#include <QFile>
#include <QList>
#include <QTextStream>
#include <QProcess>
#include <QDir>
#include <QDebug>
#include <QFileSystemModel>
#include <QFileDialog>
#include <QDateTime>
#include <QKeyEvent>
#include <QRandomGenerator>
#include "helpWindow/helpwindow.h"
#include "logger.h"
#include "qCustomPlot/qcustomplot.h"
#include "cmath"
#include "glwidget.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE
/*!
 * The MainWindow class represents most of the UI. It contains all the Slots of the used ui elements defined in mainwindow.ui
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    /*!
     * \brief projectPath saves the choosen project path, set in on_SetProjectDir_Button_clicked()
     */
    QDir projectPath;
    /*!
     * \brief blenderPath saves the blender path, set by on_SetBleDir_Button_clicked()
     */
    QDir blenderPath;
    /*!
     * \brief isHelpWindowOpen keeps track if a helpWindow is already open
     */
    bool isHelpWindowOpen=false;
    /*!
     * \brief currentTime is the value of the current time Step of the simulation
     */
    double currentTime=-1;
    /*!
     * \brief plotIdent is a QStringList of names for every plotted residual name
     */
    QStringList plotIdent;
    /*!
     * \brief indices is a integer that keeps the current index of plotValues
     */
    int indices=-1;
    /*!
     * \brief plotValues is a QList of QLists of double values for every plotted residual
     */
    QList<QList<double>> plotValues;
public slots:

    //GENERAL
    void on_System_TreeView_doubleClicked(const QModelIndex &index);
    void on_HelpWindow_Button_clicked();
    void on_HelpWindow_closed();
    void stream_StandardConsole_Output();
    void stream_ErrorConsole_Output();
    void write_Logs();

    //TAB WIDGET
    void on_Previous_Button_clicked();
    void on_Next_Button_clicked();

    //SETUP TAB
    void on_CheckProjectDir_Button_clicked();
    void on_SetProjectDir_Button_clicked();
    void on_CheckBleDir_Button_clicked();
    void on_SetBleDir_Button_clicked();
    void on_New_Button_clicked();

    //GEOMETRY MESH TAB
    void on_PolyMesh_TreeView_doubleClicked(const QModelIndex &index);
    void on_SnappyHexMesh_Button_clicked();
    void on_BlockMesh_Button_clicked();
    void on_MeshConsole_CheckBox_stateChanged(int arg1);

    //SOLVER TAB
    void on_CheckValidity_Button_clicked();
    void on_LoadPreset_Button_clicked();

    //ANFANGS UND RANDBEDINGUNGEN
    void on_IBC_TreeView_doubleClicked(const QModelIndex &index);

    //SOLVE TAB
    void on_SolveHideConsole_CheckBox_stateChanged(int arg1);
    void on_paraFoam_Button_clicked();
    void on_Solve_Button_clicked();
    void on_hide_show_clicked();
    void on_Blender_Button_clicked();
    void on_logarithmic_checkBox_stateChanged(int arg1);

private slots:
    void on_ImportGeo_Button_clicked();

private:
    Ui::MainWindow *ui;
    HelpWindow *helpWindow;
    Logger *logger;
    void keyPressEvent(QKeyEvent *event);
    void SetTreeView(QString pathExtension, QTreeView *specificTreeView);
    void CreateNewFolder(QString FolderName, QString Dir);
    void InvalidDir(QString Dir);
    void OpenTextFile(QString args);
};
#endif // MAINWINDOW_H
