/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.11
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QTreeView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "glwidget.h"
#include "qCustomPlot/qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QHBoxLayout *navigationKeys_HLayout;
    QPushButton *Previous_Button;
    QPushButton *HelpWindow_Button;
    QPushButton *Next_Button;
    QTabWidget *tabWidget;
    QWidget *Setup_Tab;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout_7;
    QComboBox *New_ComboBox;
    QPushButton *New_Button;
    QGridLayout *Project;
    QLineEdit *ProjectDir_LineEdit;
    QPushButton *SetProjectDir_Button;
    QPushButton *CheckProjectDir_Button;
    QLabel *ProjectDir_Label;
    QGridLayout *Blender;
    QLabel *BlenderDir_Label;
    QLineEdit *BlenderDir_LineEdit;
    QPushButton *SetBleDir_Button;
    QPushButton *CheckBleDir_Button;
    QSpacerItem *verticalSpacer;
    QWidget *Mesh_Tab;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout;
    QCheckBox *MeshConsole_CheckBox;
    QPushButton *ImportGeo_Button;
    QPushButton *Blender_Button;
    QTreeView *PolyMesh_TreeView;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *BlockMesh_Button;
    QPushButton *SnappyHexMesh_Button;
    QVBoxLayout *verticalLayout_2;
    QLabel *MeshOutput_Label;
    QTextBrowser *Mesh_Output;
    QLabel *MeshError_Label;
    QTextBrowser *Mesh_Error;
    QWidget *Solver_Tab;
    QGridLayout *gridLayout_3;
    QHBoxLayout *horizontalLayout_2;
    QTreeView *System_TreeView;
    QVBoxLayout *verticalLayout_4;
    QVBoxLayout *verticalLayout_6;
    QLabel *Preset_Label;
    QComboBox *LoadPreset_ComboBox;
    QPushButton *LoadPreset_Button;
    QSpacerItem *verticalSpacer_2;
    QPushButton *CheckValidity_Button;
    QWidget *ARBedingungen_Tab;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_8;
    QTreeView *IBC_TreeView;
    GLWidget *GL_Widget;
    QWidget *Solve_Tab;
    QHBoxLayout *horizontalLayout_4;
    QVBoxLayout *SolveButton_Layout;
    QCheckBox *SolveHideConsole_CheckBox;
    QVBoxLayout *verticalLayout_3;
    QLabel *nrOfTests_Label;
    QSpinBox *nrOfTests_Button;
    QHBoxLayout *horizontalLayout_6;
    QComboBox *solver_comboBox;
    QPushButton *Solve_Button;
    QPushButton *paraFoam_Button;
    QPushButton *AbortSim_Button;
    QHBoxLayout *horizontalLayout_71;
    QLabel *label;
    QCheckBox *logarithmic_checkBox;
    QCustomPlot *CustomPlot;
    QVBoxLayout *SolveConsole_Layout;
    QLabel *SolverOutput_Label;
    QTextBrowser *Solver_Output;
    QLabel *SolverError_Label;
    QTextBrowser *Solver_Error;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1270, 720);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        navigationKeys_HLayout = new QHBoxLayout();
        navigationKeys_HLayout->setObjectName(QString::fromUtf8("navigationKeys_HLayout"));
        Previous_Button = new QPushButton(centralwidget);
        Previous_Button->setObjectName(QString::fromUtf8("Previous_Button"));

        navigationKeys_HLayout->addWidget(Previous_Button);

        HelpWindow_Button = new QPushButton(centralwidget);
        HelpWindow_Button->setObjectName(QString::fromUtf8("HelpWindow_Button"));
        HelpWindow_Button->setEnabled(true);
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(HelpWindow_Button->sizePolicy().hasHeightForWidth());
        HelpWindow_Button->setSizePolicy(sizePolicy1);
        HelpWindow_Button->setMaximumSize(QSize(500, 25));
        HelpWindow_Button->setIconSize(QSize(4, 4));

        navigationKeys_HLayout->addWidget(HelpWindow_Button);

        Next_Button = new QPushButton(centralwidget);
        Next_Button->setObjectName(QString::fromUtf8("Next_Button"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(Next_Button->sizePolicy().hasHeightForWidth());
        Next_Button->setSizePolicy(sizePolicy2);

        navigationKeys_HLayout->addWidget(Next_Button);

        navigationKeys_HLayout->setStretch(0, 2);
        navigationKeys_HLayout->setStretch(1, 5);
        navigationKeys_HLayout->setStretch(2, 2);

        gridLayout->addLayout(navigationKeys_HLayout, 1, 0, 1, 1);

        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setEnabled(true);
        tabWidget->setAutoFillBackground(true);
        Setup_Tab = new QWidget();
        Setup_Tab->setObjectName(QString::fromUtf8("Setup_Tab"));
        verticalLayout_5 = new QVBoxLayout(Setup_Tab);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        New_ComboBox = new QComboBox(Setup_Tab);
        New_ComboBox->addItem(QString());
        New_ComboBox->addItem(QString());
        New_ComboBox->addItem(QString());
        New_ComboBox->addItem(QString());
        New_ComboBox->setObjectName(QString::fromUtf8("New_ComboBox"));

        horizontalLayout_7->addWidget(New_ComboBox);

        New_Button = new QPushButton(Setup_Tab);
        New_Button->setObjectName(QString::fromUtf8("New_Button"));

        horizontalLayout_7->addWidget(New_Button);


        verticalLayout_5->addLayout(horizontalLayout_7);

        Project = new QGridLayout();
        Project->setObjectName(QString::fromUtf8("Project"));
        ProjectDir_LineEdit = new QLineEdit(Setup_Tab);
        ProjectDir_LineEdit->setObjectName(QString::fromUtf8("ProjectDir_LineEdit"));

        Project->addWidget(ProjectDir_LineEdit, 2, 0, 1, 1);

        SetProjectDir_Button = new QPushButton(Setup_Tab);
        SetProjectDir_Button->setObjectName(QString::fromUtf8("SetProjectDir_Button"));

        Project->addWidget(SetProjectDir_Button, 2, 1, 1, 1);

        CheckProjectDir_Button = new QPushButton(Setup_Tab);
        CheckProjectDir_Button->setObjectName(QString::fromUtf8("CheckProjectDir_Button"));

        Project->addWidget(CheckProjectDir_Button, 2, 2, 1, 1);

        ProjectDir_Label = new QLabel(Setup_Tab);
        ProjectDir_Label->setObjectName(QString::fromUtf8("ProjectDir_Label"));

        Project->addWidget(ProjectDir_Label, 1, 0, 1, 1);


        verticalLayout_5->addLayout(Project);

        Blender = new QGridLayout();
        Blender->setObjectName(QString::fromUtf8("Blender"));
        BlenderDir_Label = new QLabel(Setup_Tab);
        BlenderDir_Label->setObjectName(QString::fromUtf8("BlenderDir_Label"));

        Blender->addWidget(BlenderDir_Label, 0, 0, 1, 1);

        BlenderDir_LineEdit = new QLineEdit(Setup_Tab);
        BlenderDir_LineEdit->setObjectName(QString::fromUtf8("BlenderDir_LineEdit"));

        Blender->addWidget(BlenderDir_LineEdit, 1, 0, 1, 1);

        SetBleDir_Button = new QPushButton(Setup_Tab);
        SetBleDir_Button->setObjectName(QString::fromUtf8("SetBleDir_Button"));

        Blender->addWidget(SetBleDir_Button, 1, 1, 1, 1);

        CheckBleDir_Button = new QPushButton(Setup_Tab);
        CheckBleDir_Button->setObjectName(QString::fromUtf8("CheckBleDir_Button"));

        Blender->addWidget(CheckBleDir_Button, 1, 2, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        Blender->addItem(verticalSpacer, 2, 0, 1, 1);


        verticalLayout_5->addLayout(Blender);

        tabWidget->addTab(Setup_Tab, QString());
        Mesh_Tab = new QWidget();
        Mesh_Tab->setObjectName(QString::fromUtf8("Mesh_Tab"));
        horizontalLayout_3 = new QHBoxLayout(Mesh_Tab);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        MeshConsole_CheckBox = new QCheckBox(Mesh_Tab);
        MeshConsole_CheckBox->setObjectName(QString::fromUtf8("MeshConsole_CheckBox"));
        MeshConsole_CheckBox->setChecked(true);

        verticalLayout->addWidget(MeshConsole_CheckBox, 0, Qt::AlignRight);

        ImportGeo_Button = new QPushButton(Mesh_Tab);
        ImportGeo_Button->setObjectName(QString::fromUtf8("ImportGeo_Button"));

        verticalLayout->addWidget(ImportGeo_Button);

        Blender_Button = new QPushButton(Mesh_Tab);
        Blender_Button->setObjectName(QString::fromUtf8("Blender_Button"));

        verticalLayout->addWidget(Blender_Button);

        PolyMesh_TreeView = new QTreeView(Mesh_Tab);
        PolyMesh_TreeView->setObjectName(QString::fromUtf8("PolyMesh_TreeView"));

        verticalLayout->addWidget(PolyMesh_TreeView);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        BlockMesh_Button = new QPushButton(Mesh_Tab);
        BlockMesh_Button->setObjectName(QString::fromUtf8("BlockMesh_Button"));

        horizontalLayout_5->addWidget(BlockMesh_Button);

        SnappyHexMesh_Button = new QPushButton(Mesh_Tab);
        SnappyHexMesh_Button->setObjectName(QString::fromUtf8("SnappyHexMesh_Button"));

        horizontalLayout_5->addWidget(SnappyHexMesh_Button);


        verticalLayout->addLayout(horizontalLayout_5);


        horizontalLayout_3->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        MeshOutput_Label = new QLabel(Mesh_Tab);
        MeshOutput_Label->setObjectName(QString::fromUtf8("MeshOutput_Label"));

        verticalLayout_2->addWidget(MeshOutput_Label);

        Mesh_Output = new QTextBrowser(Mesh_Tab);
        Mesh_Output->setObjectName(QString::fromUtf8("Mesh_Output"));

        verticalLayout_2->addWidget(Mesh_Output);

        MeshError_Label = new QLabel(Mesh_Tab);
        MeshError_Label->setObjectName(QString::fromUtf8("MeshError_Label"));

        verticalLayout_2->addWidget(MeshError_Label);

        Mesh_Error = new QTextBrowser(Mesh_Tab);
        Mesh_Error->setObjectName(QString::fromUtf8("Mesh_Error"));

        verticalLayout_2->addWidget(Mesh_Error);


        horizontalLayout_3->addLayout(verticalLayout_2);

        tabWidget->addTab(Mesh_Tab, QString());
        Solver_Tab = new QWidget();
        Solver_Tab->setObjectName(QString::fromUtf8("Solver_Tab"));
        gridLayout_3 = new QGridLayout(Solver_Tab);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        System_TreeView = new QTreeView(Solver_Tab);
        System_TreeView->setObjectName(QString::fromUtf8("System_TreeView"));

        horizontalLayout_2->addWidget(System_TreeView);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        Preset_Label = new QLabel(Solver_Tab);
        Preset_Label->setObjectName(QString::fromUtf8("Preset_Label"));

        verticalLayout_6->addWidget(Preset_Label);

        LoadPreset_ComboBox = new QComboBox(Solver_Tab);
        LoadPreset_ComboBox->addItem(QString());
        LoadPreset_ComboBox->addItem(QString());
        LoadPreset_ComboBox->setObjectName(QString::fromUtf8("LoadPreset_ComboBox"));

        verticalLayout_6->addWidget(LoadPreset_ComboBox);

        LoadPreset_Button = new QPushButton(Solver_Tab);
        LoadPreset_Button->setObjectName(QString::fromUtf8("LoadPreset_Button"));

        verticalLayout_6->addWidget(LoadPreset_Button);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_6->addItem(verticalSpacer_2);


        verticalLayout_4->addLayout(verticalLayout_6);

        CheckValidity_Button = new QPushButton(Solver_Tab);
        CheckValidity_Button->setObjectName(QString::fromUtf8("CheckValidity_Button"));

        verticalLayout_4->addWidget(CheckValidity_Button);


        horizontalLayout_2->addLayout(verticalLayout_4);

        horizontalLayout_2->setStretch(0, 4);
        horizontalLayout_2->setStretch(1, 1);

        gridLayout_3->addLayout(horizontalLayout_2, 0, 0, 1, 1);

        tabWidget->addTab(Solver_Tab, QString());
        ARBedingungen_Tab = new QWidget();
        ARBedingungen_Tab->setObjectName(QString::fromUtf8("ARBedingungen_Tab"));
        horizontalLayout = new QHBoxLayout(ARBedingungen_Tab);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        IBC_TreeView = new QTreeView(ARBedingungen_Tab);
        IBC_TreeView->setObjectName(QString::fromUtf8("IBC_TreeView"));

        verticalLayout_8->addWidget(IBC_TreeView);


        horizontalLayout->addLayout(verticalLayout_8);

        GL_Widget = new GLWidget(ARBedingungen_Tab);
        GL_Widget->setObjectName(QString::fromUtf8("GL_Widget"));

        horizontalLayout->addWidget(GL_Widget);

        horizontalLayout->setStretch(0, 1);
        horizontalLayout->setStretch(1, 1);
        tabWidget->addTab(ARBedingungen_Tab, QString());
        Solve_Tab = new QWidget();
        Solve_Tab->setObjectName(QString::fromUtf8("Solve_Tab"));
        horizontalLayout_4 = new QHBoxLayout(Solve_Tab);
        horizontalLayout_4->setSpacing(8);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        SolveButton_Layout = new QVBoxLayout();
        SolveButton_Layout->setObjectName(QString::fromUtf8("SolveButton_Layout"));
        SolveHideConsole_CheckBox = new QCheckBox(Solve_Tab);
        SolveHideConsole_CheckBox->setObjectName(QString::fromUtf8("SolveHideConsole_CheckBox"));
        SolveHideConsole_CheckBox->setChecked(true);
        SolveHideConsole_CheckBox->setTristate(false);

        SolveButton_Layout->addWidget(SolveHideConsole_CheckBox, 0, Qt::AlignRight);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        nrOfTests_Label = new QLabel(Solve_Tab);
        nrOfTests_Label->setObjectName(QString::fromUtf8("nrOfTests_Label"));

        verticalLayout_3->addWidget(nrOfTests_Label);

        nrOfTests_Button = new QSpinBox(Solve_Tab);
        nrOfTests_Button->setObjectName(QString::fromUtf8("nrOfTests_Button"));

        verticalLayout_3->addWidget(nrOfTests_Button);


        SolveButton_Layout->addLayout(verticalLayout_3);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        solver_comboBox = new QComboBox(Solve_Tab);
        solver_comboBox->addItem(QString());
        solver_comboBox->addItem(QString());
        solver_comboBox->setObjectName(QString::fromUtf8("solver_comboBox"));

        horizontalLayout_6->addWidget(solver_comboBox);

        Solve_Button = new QPushButton(Solve_Tab);
        Solve_Button->setObjectName(QString::fromUtf8("Solve_Button"));

        horizontalLayout_6->addWidget(Solve_Button);


        SolveButton_Layout->addLayout(horizontalLayout_6);

        paraFoam_Button = new QPushButton(Solve_Tab);
        paraFoam_Button->setObjectName(QString::fromUtf8("paraFoam_Button"));

        SolveButton_Layout->addWidget(paraFoam_Button);

        AbortSim_Button = new QPushButton(Solve_Tab);
        AbortSim_Button->setObjectName(QString::fromUtf8("AbortSim_Button"));

        SolveButton_Layout->addWidget(AbortSim_Button);

        horizontalLayout_71 = new QHBoxLayout();
        horizontalLayout_71->setObjectName(QString::fromUtf8("horizontalLayout_71"));
        label = new QLabel(Solve_Tab);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_71->addWidget(label);

        logarithmic_checkBox = new QCheckBox(Solve_Tab);
        logarithmic_checkBox->setObjectName(QString::fromUtf8("logarithmic_checkBox"));

        horizontalLayout_71->addWidget(logarithmic_checkBox, 0, Qt::AlignRight);


        SolveButton_Layout->addLayout(horizontalLayout_71);

        CustomPlot = new QCustomPlot(Solve_Tab);
        CustomPlot->setObjectName(QString::fromUtf8("CustomPlot"));

        SolveButton_Layout->addWidget(CustomPlot);

        SolveButton_Layout->setStretch(6, 1);

        horizontalLayout_4->addLayout(SolveButton_Layout);

        SolveConsole_Layout = new QVBoxLayout();
        SolveConsole_Layout->setObjectName(QString::fromUtf8("SolveConsole_Layout"));
        SolverOutput_Label = new QLabel(Solve_Tab);
        SolverOutput_Label->setObjectName(QString::fromUtf8("SolverOutput_Label"));

        SolveConsole_Layout->addWidget(SolverOutput_Label, 0, Qt::AlignLeft);

        Solver_Output = new QTextBrowser(Solve_Tab);
        Solver_Output->setObjectName(QString::fromUtf8("Solver_Output"));

        SolveConsole_Layout->addWidget(Solver_Output);

        SolverError_Label = new QLabel(Solve_Tab);
        SolverError_Label->setObjectName(QString::fromUtf8("SolverError_Label"));

        SolveConsole_Layout->addWidget(SolverError_Label, 0, Qt::AlignLeft);

        Solver_Error = new QTextBrowser(Solve_Tab);
        Solver_Error->setObjectName(QString::fromUtf8("Solver_Error"));

        SolveConsole_Layout->addWidget(Solver_Error);


        horizontalLayout_4->addLayout(SolveConsole_Layout);

        horizontalLayout_4->setStretch(0, 1);
        horizontalLayout_4->setStretch(1, 1);
        tabWidget->addTab(Solve_Tab, QString());

        gridLayout->addWidget(tabWidget, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(3);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "OpenFOAM GUI", nullptr));
        Previous_Button->setText(QApplication::translate("MainWindow", "Previous", nullptr));
        HelpWindow_Button->setText(QApplication::translate("MainWindow", "Open Help", nullptr));
        Next_Button->setText(QApplication::translate("MainWindow", "Next", nullptr));
        New_ComboBox->setItemText(0, QApplication::translate("MainWindow", "New Project Folder", nullptr));
        New_ComboBox->setItemText(1, QApplication::translate("MainWindow", "/system", nullptr));
        New_ComboBox->setItemText(2, QApplication::translate("MainWindow", "/constant", nullptr));
        New_ComboBox->setItemText(3, QApplication::translate("MainWindow", "/0", nullptr));

        New_Button->setText(QApplication::translate("MainWindow", "Create", nullptr));
        SetProjectDir_Button->setText(QApplication::translate("MainWindow", "Set Directory", nullptr));
        CheckProjectDir_Button->setText(QApplication::translate("MainWindow", "Check Directory", nullptr));
        ProjectDir_Label->setText(QApplication::translate("MainWindow", "Enter Path to Project Directory", nullptr));
        BlenderDir_Label->setText(QApplication::translate("MainWindow", "Enter Path to Blender Directory", nullptr));
        SetBleDir_Button->setText(QApplication::translate("MainWindow", "Set Directory", nullptr));
        CheckBleDir_Button->setText(QApplication::translate("MainWindow", "Check Directory", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(Setup_Tab), QApplication::translate("MainWindow", "Setup", nullptr));
        MeshConsole_CheckBox->setText(QApplication::translate("MainWindow", "Toggle Console", nullptr));
        ImportGeo_Button->setText(QApplication::translate("MainWindow", "Import Geometry", nullptr));
        Blender_Button->setText(QApplication::translate("MainWindow", "Open Blender", nullptr));
        BlockMesh_Button->setText(QApplication::translate("MainWindow", "BlockMesh", nullptr));
        SnappyHexMesh_Button->setText(QApplication::translate("MainWindow", "SnappyHexMesh", nullptr));
        MeshOutput_Label->setText(QApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" font-weight:600;\">Output:</span></p></body></html>", nullptr));
        MeshError_Label->setText(QApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" font-weight:600;\">Error:</span></p></body></html>", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(Mesh_Tab), QApplication::translate("MainWindow", "Geometry/Mesh", nullptr));
        Preset_Label->setText(QApplication::translate("MainWindow", "Preset:", nullptr));
        LoadPreset_ComboBox->setItemText(0, QApplication::translate("MainWindow", "SIMPLE", nullptr));
        LoadPreset_ComboBox->setItemText(1, QApplication::translate("MainWindow", "PISO", nullptr));

        LoadPreset_Button->setText(QApplication::translate("MainWindow", "Load Preset", nullptr));
        CheckValidity_Button->setText(QApplication::translate("MainWindow", "Check Validity", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(Solver_Tab), QApplication::translate("MainWindow", "Solver", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(ARBedingungen_Tab), QApplication::translate("MainWindow", "Initial/Boundary Conditions", nullptr));
        SolveHideConsole_CheckBox->setText(QApplication::translate("MainWindow", "Toggle Console", nullptr));
        nrOfTests_Label->setText(QApplication::translate("MainWindow", "Number of Runs", nullptr));
        solver_comboBox->setItemText(0, QApplication::translate("MainWindow", "simpleFoam", nullptr));
        solver_comboBox->setItemText(1, QApplication::translate("MainWindow", "pisoFoam", nullptr));

        Solve_Button->setText(QApplication::translate("MainWindow", "Solve", nullptr));
        paraFoam_Button->setText(QApplication::translate("MainWindow", "Open in Paraview", nullptr));
        AbortSim_Button->setText(QApplication::translate("MainWindow", "Abort Simulation", nullptr));
        label->setText(QApplication::translate("MainWindow", "Residual Plot:", nullptr));
        logarithmic_checkBox->setText(QApplication::translate("MainWindow", "log()", nullptr));
        SolverOutput_Label->setText(QApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" font-weight:600;\">Output:</span></p></body></html>", nullptr));
        SolverError_Label->setText(QApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" font-weight:600;\">Error:</span></p></body></html>", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(Solve_Tab), QApplication::translate("MainWindow", "Solve", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
