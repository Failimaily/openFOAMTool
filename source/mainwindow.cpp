#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setAttribute(Qt::WA_DeleteOnClose);
    ui->Mesh_Error->hide();
    ui->MeshError_Label->hide();
    //ui->Residual_Chart->hide();
    logger = new Logger(QDir::currentPath());
    //logger->writeLog("Test","Test");#
    QFile file("Blender_Directory.txt");
    if(file.open(QIODevice::ReadOnly))
    {
        QTextStream stream(&file);
        ui->BlenderDir_LineEdit->setText(stream.readAll());
    }
}

MainWindow::~MainWindow()
{
    g_pprojectsettings->Del();
    QCoreApplication::quit();
    delete helpWindow;
    delete ui;
}

//FUNCTIONS//
//This function initializes a Tree View with the given directory path.
/*!
 * Creates a QFileSystemModel specificModel with the projectpath + pathExtension as rootPath and sets the model of the specificTreeview
 * to the created QFileSystemModel \n
 * Displays a msgBox if the given projectpath + pathExtension does not exist
 * \param pathExtension is the path extension of the folder eg. "/0"
 * \param specificTreeView is the specificTreeView which should be changed eg. "IBC_TreeView"
 */
void MainWindow::SetTreeView(QString pathExtension, QTreeView * specificTreeView )
{
    QDir specificPath(projectPath.path()+pathExtension);
    if(specificPath.exists())
    {
        QFileSystemModel *specificModel = new QFileSystemModel;
        specificModel->setRootPath(specificPath.path());
        specificTreeView->setModel(specificModel);
        specificTreeView->setRootIndex(specificModel->index(specificPath.path()));
    }
    else
    {
        QMessageBox msgBox;
        msgBox.setText(pathExtension + " is missing.");
        msgBox.exec();
    }
}


/*!
 * Creates a new Folder in the Directory Dir + FolderName
 * \param FolderName reprents the name of the new Folder
 * \param Dir represents the base directory path where the new folder will be created.
 */
void MainWindow::CreateNewFolder(QString FolderName, QString Dir)
{
    QString dir(Dir + "/" +FolderName);
    if (!QDir(dir).exists()){
        QDir().mkdir(dir);
        QMessageBox msgBox;
        msgBox.setText(FolderName + " was created.");
        msgBox.exec();
    }
}


/*!
 * Displayes a message box that lets the user know a invalid directory Dir was chosen
 * \param Dir represents the invalid Directory Path
 */
void MainWindow::InvalidDir(QString Dir)
{
    QMessageBox msgBox;
    msgBox.setText(Dir + " is not a valid Directory. Please choose another Directory.");
    msgBox.exec();
}


/*!
 * Opens a given File with fileDir as path in gedit
 * \param fileDir represents the path of the File to open
 */
void MainWindow::OpenTextFile (QString fileDir)
{
    QProcess *openProcess = new QProcess();
    openProcess->start("gedit " + fileDir);
    openProcess->waitForFinished();
}

//GENERAL//
/*!
 * MainWindow::on_HelpWindow_Button_clicked checks if isHelpWindowOpen is false and \n
 * then creates and opens a new HelpWindow() and sets the isHelpWindowOpen flag to true
 */
void MainWindow::on_HelpWindow_Button_clicked()
{
    if(!isHelpWindowOpen)
    {
        helpWindow = new HelpWindow();
        connect(helpWindow,SIGNAL(destroyed(QObject*)),this,SLOT(on_HelpWindow_closed()));
        helpWindow->show();
        isHelpWindowOpen=true;
        qCritical() << "HelpWindow created";
    }
}
/*!
 * MainWindow::on_HelpWindow_closed gets called if the HelpWindow is closed and sets the flag isHelpWindowOpen to false
 */
void MainWindow::on_HelpWindow_closed()
{
    isHelpWindowOpen=false;
}
/*!
 * Calls on_HelpWindow_Button_clicked() if the F1 key is pressed.
 * \param event is a QKeyEvent which contains all the information about the key that was pressed.
 */
void MainWindow::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_F1)
    {
        on_HelpWindow_Button_clicked();
    }
}

//TAB WIDGET//
/*!
 * \brief MainWindow::on_Next_Button_clicked switches to the next tab
 */
void MainWindow::on_Next_Button_clicked()
{
    ui->tabWidget->setCurrentIndex(ui->tabWidget->currentIndex()+1);
}
/*!
 * \brief MainWindow::on_Previous_Button_clicked switches to the previous tab
 */
void MainWindow::on_Previous_Button_clicked()
{
    ui->tabWidget->setCurrentIndex(ui->tabWidget->currentIndex()-1);
}

//SETUP TAB//
//When clicked this button gives the user the possibility of choosing the project directory
//and initializes all the TreeView's accordingly.
/*!
 * MainWindow::on_SetProjectDir_Button_clicked creates a QFileDialog, for the user to browse to
 * the project directory and saves it in the projectPath attribute.\n
 * Fills every TreeView with data.
 */
void MainWindow::on_SetProjectDir_Button_clicked()
{
    QStringList path;
    QFileDialog dialog(this);
    dialog.setFileMode(QFileDialog::Directory);
    dialog.setViewMode(QFileDialog::Detail);
    if(dialog.exec())
    {
        path = dialog.selectedFiles();
    }
    qCritical() << path;
    if(path.count() != 0)
    {
        projectPath.setPath(path.at(0));
        ui->ProjectDir_LineEdit->setText(projectPath.path());
        SetTreeView ("/constant", ui->PolyMesh_TreeView);
        SetTreeView ("/system", ui->System_TreeView);
        SetTreeView ("/0", ui->IBC_TreeView);
    }
}
//When clicked this button shows the chosen path for the project directory.
/*!
 * MainWindow::on_CheckProjectDir_Button_clicked opens a QMessageBox to show the currently saved
 * projectPath.
 */
void MainWindow::on_CheckProjectDir_Button_clicked()
{
    QMessageBox msgBox;
    msgBox.setText("Your current Project Directory is:");
    msgBox.setInformativeText(projectPath.path());
    msgBox.exec();
}
//When clicked this button gives the user the possibility of defining the path for Blender
//which will be stored in a .txt.
/*!
 * MainWindow::on_SetBleDir_Button_clicked creates a QFileDialog, for the user to browse to
 * the directory of the blender executable and saves it in the blenderPath attribute.\n
 * Saves the blenderPath into the Blender_Directory file.
 */
void MainWindow::on_SetBleDir_Button_clicked()
{
    QStringList path;
    QFileDialog dialog(this,"Open Blender executable directory","/home");
    QFile file("Blender_Directory");
    dialog.setFileMode(QFileDialog::Directory);
    dialog.setViewMode(QFileDialog::Detail);
    dialog.setOptions(QFileDialog::ShowDirsOnly);
    if(dialog.exec())
    {
        path = dialog.selectedFiles();
    }
    if(path.count() != 0)
    {
        blenderPath.setPath(path.at(0));
        ui->BlenderDir_LineEdit->setText(path.at(0));
        if(!file.open(QIODevice::WriteOnly))
        {
            qCritical() << file.errorString();
        }

        else {
            QTextStream stream(&file);
            stream << ui->BlenderDir_LineEdit->text();
            QMessageBox msgBox;
            msgBox.setText("The Blender Directory was succesfully set to: ");
            msgBox.setInformativeText(ui->BlenderDir_LineEdit->text());
            msgBox.exec();
        }
        file.close();
    }
}
//When clicked this button shows the chosen path for Blender.
/*!
 * MainWindow::on_CheckBleDir_Button_clicked opens a QMessageBox to show the currently saved
 * blenderPath in the Blender_Directory file.
 */
void MainWindow::on_CheckBleDir_Button_clicked()
{
    QFile file("Blender_Directory.txt");
    if(!file.exists())
    {
        qCritical() << "Directory not found, set a directory first";
    }

    if(!file.open(QIODevice::ReadOnly))
    {
        qCritical() << file.errorString();
    }
    QTextStream stream(&file);
    QMessageBox msgBox;
    msgBox.setText("Your current Blender Directory is:");
    msgBox.setInformativeText(stream.readAll());
    msgBox.exec();
}

//When clicked this button creates new folders and project folders
void MainWindow::on_New_Button_clicked()
{
    if (ui->New_ComboBox->currentIndex() == 0){
        bool ok;
        QString ProDir = QInputDialog::getText(this, tr("Where should be the project folder be located?"),
                                                 tr("Path:"), QLineEdit::Normal,
                                                 projectPath.path(), &ok);
        if (!QDir(ProDir).exists()){
            InvalidDir(ProDir);
            return;
        }else if (QDir(ProDir).exists() && ok){
            QString ProName = QInputDialog::getText(this, tr("Choose a Name for the Project"),
                                                     tr("Name:"), QLineEdit::Normal,
                                                     "New_Project", &ok);
            CreateNewFolder (ProName,ProDir);
            if (QDir(ProDir+"/"+ProName).exists() && ok){
                qDebug() << ProDir+ProName;
                CreateNewFolder ("/system",ProDir+"/"+ProName);
                CreateNewFolder ("/constant",ProDir+"/"+ProName);
                CreateNewFolder ("/0",ProDir+"/"+ProName);
            }
        }
    }
    if (ui->New_ComboBox->currentIndex() == 1){
        bool ok;
        QString FolderName = "/system";
        QString Dir = QInputDialog::getText(this, tr("Where should be the folder /system be located?"), tr("Path:"), QLineEdit::Normal, projectPath.path(), &ok);
        if (!QDir(Dir).exists()){
            InvalidDir(Dir);
            return; }
        if(ok)
            CreateNewFolder (FolderName,Dir);
    }
    if (ui->New_ComboBox->currentIndex() == 2){
        bool ok;
        QString FolderName = "/constant";
        QString Dir = QInputDialog::getText(this, tr("Where should be the folder /constant be located?"), tr("Path:"), QLineEdit::Normal, projectPath.path(), &ok);
        if (!QDir(Dir).exists()){
            InvalidDir(Dir);
            return; }
        if(ok)
            CreateNewFolder (FolderName,Dir);
    }
    if (ui->New_ComboBox->currentIndex() == 3){
        bool ok;
        QString FolderName = "/0";
        QString Dir = QInputDialog::getText(this, tr("Where should be the folder /0 be located?"), tr("Path:"), QLineEdit::Normal, projectPath.path(), &ok);
        if (!QDir(Dir).exists()){
            InvalidDir(Dir);
            return; }
        if(ok)
            CreateNewFolder (FolderName,Dir);
    }
}

//GEOMETRY TAB//
//Double clicking a file in the TreeView will open said file in a text editor
/*!
 * Opens the double-clicked file with QModelIndex index from the PolyMesh_TreeView
 * \param index represents the index of the double-clicked file within the QTreeModel of PolyMesh_TreeView
 */
void MainWindow::on_PolyMesh_TreeView_doubleClicked(const QModelIndex &index)
{
    QString args;
    QFileSystemModel *model = qobject_cast<QFileSystemModel*>(ui->PolyMesh_TreeView->model());
    args = model->fileInfo(index).absoluteFilePath();
    OpenTextFile(args);
}
/*!
 * MainWindow::on_ImportGeo_Button_clicked opens a FileDialog for the user to search for his geometry file(.stl/.obj)
 * it then gets copied into the triSurface folder and the GL_Widget.geometryName is set.\n
 * Also updates the GL_Widget.
 */
void MainWindow::on_ImportGeo_Button_clicked()
{
    QStringList path;
    QFileDialog dialog(this,"Select the Geometry file to load","/home",tr("STL(*.stl);;Wavefront OBJ(*.obj)"));
    QFile file("Blender_Directory.txt");
    dialog.setFileMode(QFileDialog::ExistingFile);
    dialog.setViewMode(QFileDialog::Detail);
    dialog.setOptions(QFileDialog::ShowDirsOnly);
    if(dialog.exec())
    {
        path = dialog.selectedFiles();
    }
    if(QDir(projectPath.path()+"/constant").exists())
    {
        if(QDir(projectPath.path()+"/constant"+"/triSurface").exists())
        {
            QFile::copy(path[0],projectPath.path()+"/constant"+"/triSurface"+"/"+path[0].split("/").last());
            ui->GL_Widget = new GLWidget(this,projectPath.path()+"/constant"+"/triSurface"+"/"+path[0].split("/").last());
            //ui->GL_Widget->initializeGL();
            qDebug() << projectPath.path()+"/constant"+"/triSurface"+"/"+path[0].split("/").last();
        }
        else
        {
            QDir(projectPath.path()+"/constant"+"/triSurface").mkpath(".");
            QFile::copy(path[0],projectPath.path()+"/constant"+"/triSurface"+"/"+path[0].split("/").last());
            ui->GL_Widget = new GLWidget(this,projectPath.path()+"/constant"+"/triSurface"+"/"+path[0].split("/").last());
            //ui->GL_Widget->initializeGL();
            qDebug() << projectPath.path()+"/constant"+"/triSurface"+"/"+path[0].split("/").last();
        }
    }
    else
    {
        QMessageBox msgBox;
        msgBox.setText(projectPath.path()+"does not contain a /constant directory");
        msgBox.exec();
    }
}
//Opens Belnder with the given blenderdir
/*!
 * MainWindow::on_Blender_Button_clicked rund the "./blender" command inside the blenderPath
 */
void MainWindow::on_Blender_Button_clicked()
{
    QStringList args;
    QProcess *blenderProc = new QProcess();
    blenderProc->setCurrentReadChannel(QProcess::StandardError);
    blenderProc->setWorkingDirectory(ui->BlenderDir_LineEdit->text());
    blenderProc->start("./blender");
    qCritical() << blenderProc->error();
    if(blenderProc->error() == 0)
    {
        QMessageBox msgBox;
        msgBox.setText(projectPath.path()+"/system/residuals does not exist! Make sure the Residuals were generated");
        msgBox.exec();
    }
}
//When clicked this button will run the blockMesh command
/*!
 * MainWindow::on_BlockMesh_Button_clicked runs the "blockMesh" command inside the projectpath
 */
void MainWindow::on_BlockMesh_Button_clicked()
{
    ui->Mesh_Output->clear();
    ui->Mesh_Error->clear();
    ui->Mesh_Error->hide(); ui->MeshError_Label->hide();
    QStringList args;
    args << "-case" << projectPath.path();
    QProcess *meshProcess = new QProcess();
    meshProcess->setCurrentReadChannel(QProcess::StandardError);
    meshProcess->start("blockMesh",args);
    connect(meshProcess,SIGNAL(readyReadStandardOutput()),this,SLOT(stream_StandardConsole_Output()));
    connect(meshProcess,SIGNAL(readyReadStandardError()),this,SLOT(stream_ErrorConsole_Output()));
    connect(meshProcess,SIGNAL(finished(int,QProcess::ExitStatus)),this,SLOT(write_Logs()));
}
//When clicked this button will run the snappyHexMesh command
/*!
 * MainWindow::on_SnappyHexMesh_Button_clicked runs the "snappyHexMesh" command inside the projectPath
 */
void MainWindow::on_SnappyHexMesh_Button_clicked()
{
    ui->Mesh_Output->clear();
    ui->Mesh_Error->clear();
    ui->Mesh_Error->hide(); ui->MeshError_Label->hide();
    QStringList args;
    args << "-case" << projectPath.path() << "-overwrite";
    QProcess *meshProcess = new QProcess();
    meshProcess->setCurrentReadChannel(QProcess::StandardError);
    meshProcess->start("snappyHexMesh",args);
    connect(meshProcess,SIGNAL(readyReadStandardOutput()),this,SLOT(stream_StandardConsole_Output()));
    connect(meshProcess,SIGNAL(readyReadStandardError()),this,SLOT(stream_ErrorConsole_Output()));
    connect(meshProcess,SIGNAL(finished(int,QProcess::ExitStatus)),this,SLOT(write_Logs()));
}
/*!
 * \brief Hides/Shows the Mesh Console Output
 * \param arg1 reprents the state of the checkbox, 0 -> 'off' and 2 -> 'on'
 */
void MainWindow::on_MeshConsole_CheckBox_stateChanged(int arg1)
{
    qCritical() << arg1;
    switch(arg1)
    {
    case 0:
        ui->MeshOutput_Label->hide();
        ui->Mesh_Output->hide();
        ui->MeshError_Label->hide();
        ui->Mesh_Error->hide();
        break;
    case 2:
        ui->MeshOutput_Label->show();
        ui->Mesh_Output->show();
        ui->MeshError_Label->show();
        ui->Mesh_Error->show();
        break;
    default: qCritical()<< "This should never happen.";
    }
}

//SOLVER TAB//
//Double clicking a file in the TreeView will open said file in a text editor
/*!
 * Opens the double-clicked file with QModelIndex index from the System_TreeView
 * \param index represents the index of the double-clicked file within the QTreeModel of System_TreeView
 */
void MainWindow::on_System_TreeView_doubleClicked(const QModelIndex &index)
{
    QString args;
    QFileSystemModel *model = qobject_cast<QFileSystemModel*>(ui->System_TreeView->model());
    args = model->fileInfo(index).absoluteFilePath();
    OpenTextFile(args);
}
//When clicked this button will generate a solver specific preset for the fvSolution file.
/*!
 * MainWindow::on_LoadPreset_Button_clicked appends the corresponding solver preset to fvSolution
 * if it's not already present in fvSolution
 */
void MainWindow::on_LoadPreset_Button_clicked()
{
    if(!QDir(projectPath.path()+"/system").exists()){
        QMessageBox msgBox;
        msgBox.setText("/system is missing.");
        msgBox.exec();
        return;
    }
    qDebug() << QDir::currentPath() + "/presets/" + ui->LoadPreset_ComboBox->currentText();
    QFile fvSolution(projectPath.path()+"/system/fvSolution");
    if(fvSolution.open(QIODevice::ReadWrite))
    {
        QTextStream stream(&fvSolution);
        if(!stream.readAll().contains(ui->LoadPreset_ComboBox->currentText()))
        {
            qDebug() << QApplication::applicationDirPath() + "/presets/" + ui->LoadPreset_ComboBox->currentText();
            QFile preset(QApplication::applicationDirPath()+"/presets/"+ui->LoadPreset_ComboBox->currentText());
            if(preset.open(QIODevice::ReadOnly))
            {
                QTextStream presetStream(&preset);
                stream << "\n";
                stream << presetStream.readAll();
            }
            preset.close();
        }
        else
            qDebug() << "SOLVER ALREADY DEFINED";
        fvSolution.close();
    }
}
//When clicked this button will verfy if fvSolution has a definition for all the variables contained in /0.
//REWORK
/*!
 * \brief MainWindow::on_CheckValidity_Button_clicked does not work correctly in the current Version
 * requires a complete rework
 */
void MainWindow::on_CheckValidity_Button_clicked()
{
    QDir specificPath(projectPath.path()+"/0");
    if(specificPath.exists()){
         QStringList var;
         var << specificPath.entryList();
         var.removeAll(".");
         var.removeAll("..");
         if(!QDir(projectPath.path()+"/system").exists("fvSolution")){
             QMessageBox msgBox;
             msgBox.setText("fvSolution is missing.");
             msgBox.exec();
             return;
         }
         QFile file(projectPath.path()+"/system/fvSolution");
         if(!file.open(QIODevice::ReadOnly))
         {
             qCritical() << file.errorString();
         }
         int countVal = 0;
         for (const auto& i : var){
             QTextStream in(&file);
             qDebug() << i;
             while(!in.atEnd()){
                 QString line = in.readLine();
                 line = line.simplified();
                 line.replace( " ", "" );
                 qDebug() << line;
                 if(line == i){
                     qDebug() << i << "found";
                     ++countVal;
                     break;
                 }
             }
             in.seek(0);
         }
         if (countVal == var.length()){
             QMessageBox msgBox;
             msgBox.setText("Valid");
             msgBox.exec();
             return;
         }

    }
    else{
        QMessageBox msgBox;
        msgBox.setText("/0 is missing. Please choose a valid project folder first.");
        msgBox.exec();
    }
}
//ANFANGS UND RANDBEDINGUNGEN TAB//
//Double clicking a file in the TreeView will open said file in a text editor
/*!
 * MainWindow::on_IBC_TreeView_doubleClicked Opens the double-clicked file with QModelIndex index from the IBC_TreeView
 * \param index represents the index of the double-clicked file within the QTreeModel of IBC_TreeView
 */
void MainWindow::on_IBC_TreeView_doubleClicked(const QModelIndex &index)
{
    QString args;
    QFileSystemModel *model = qobject_cast<QFileSystemModel*>(ui->IBC_TreeView->model());
    args = model->fileInfo(index).absoluteFilePath();
    OpenTextFile(args);
}
//SOLVE TAB//

//This Hide/Shows the Console Output on the Solve Page
//arg1 represents the state (0=OFF | 2=ON)
/*!
 * \brief Hides/Shows the Solver Console Output
 * \param arg1 reprents the state of the checkbox, 0 -> 'off' and 2 -> 'on'
 */
void MainWindow::on_SolveHideConsole_CheckBox_stateChanged(int arg1)
{
    qCritical() << arg1;
    switch(arg1)
    {
    case 0:
        ui->SolverOutput_Label->hide();
        ui->Solver_Output->hide();
        ui->SolverError_Label->hide();
        ui->Solver_Error->hide();
        ui->SolveConsole_Layout->setEnabled(false);
        break;
    case 2:
        ui->SolverOutput_Label->show();
        ui->Solver_Output->show();
        ui->SolverError_Label->show();
        ui->Solver_Error->show();
        ui->SolveConsole_Layout->setEnabled(false);
        break;
    default: qCritical()<< "This should never happen.";
    }
}

//This function uses the generated Residual Data to plot it in the UI
/*void MainWindow::on_plotResidual_Button_clicked()
{
    QFile file(projectPath.path()+"/postProcessing/residuals/0/residuals.dat");
    double n_time = 0;
    double n_res = 0;
    if(file.exists()){
        if (!file.open(QFile::ReadOnly | QFile::Text)){
            QMessageBox msgBox;
            msgBox.setText("Could not read Residuals, make sure"+projectPath.path()+"/postprocessing/Residuals/0/residuals.dat exists");
            msgBox.exec();
        }
        QString first_line = file.readLine();
        first_line = file.readLine();
        first_line.remove(0,2);
        QStringList residual_properties = first_line.split(QRegExp("\\s+"), QString::SkipEmptyParts);
        int n_residuals = residual_properties.size();
        QLineSeries* residuals [n_residuals];
        for(int i=1;i<n_residuals;i++){
            residuals[i] = new QLineSeries();
            residuals[i]->setName(residual_properties[i]);
        }
        while (!file.atEnd()) {
                QString line = file.readLine();
                QStringList l = line.split(QRegExp("\\s+"), QString::SkipEmptyParts);
                for(int i=1;i<n_residuals;i++){
                    residuals[i]->append(l[0].toDouble(),l[i].toDouble());
                    n_time = l[0].toDouble();
                    if(n_res<l[i].toDouble()){
                    n_res = l[i].toDouble();
                    }
                }
        }
        //creating a Chart and linking the Data to it
        QChart* chart = new QChart();
        for(int i=1;i<n_residuals;i++){
            chart->addSeries(residuals[i]);
        }

        //Plotting the Chart on a ChartView
        chart->setTitle("Residuals");
        QValueAxis * axisX = new QValueAxis;
        axisX->setRange(0, n_time);
        axisX->setTickCount(10);
        axisX->setLabelFormat("%.i");
        axisX->setTitleText("Time");
        axisX->setTickCount(10);
        chart->addAxis(axisX, Qt::AlignBottom);
        residuals[1]->attachAxis(axisX);
        if(ui->logarithmic_checkBox->isChecked()){
            QLogValueAxis *axisY = new QLogValueAxis();
            axisY->setTitleText("Logarithmic Residuals");
            axisY->setLabelFormat("%g");
            axisY->setBase(8.0);
            axisY->setMinorTickCount(-1);
            chart->addAxis(axisY, Qt::AlignLeft);
            for(int i =1;i<n_residuals;i++)
            residuals[i]->attachAxis(axisY);
            chart->legend()->setAlignment(Qt::AlignBottom);
            chart->legend()->setBrush(QBrush(QColor(128, 128, 128)));
            chart->legend()->setPen(QPen(QColor(192, 192, 192)));
            chart->legend()->setGeometry(QRectF(6,6,6,6));
            chart->legend()->update();
            ui->Residual_Chart->setChart(chart);
            ui->Residual_Chart->setRenderHint(QPainter::Antialiasing);
        }
        else{
            QValueAxis * axisY = new QValueAxis;
            axisY->setLabelFormat("%.2f");
            axisY->setTitleText("Residual");
            axisY->setRange(0, n_res);
            chart->addAxis(axisY, Qt::AlignLeft);
            chart->legend()->setAlignment(Qt::AlignBottom);
            chart->legend()->setBrush(QBrush(QColor(128, 128, 128)));
            chart->legend()->setPen(QPen(QColor(192, 192, 192)));
            chart->legend()->setGeometry(QRectF(6,6,6,6));
            chart->legend()->update();
            ui->Residual_Chart->setChart(chart);
            ui->Residual_Chart->setRenderHint(QPainter::Antialiasing);
        }
    }
    else{
        QMessageBox msgBox;
        msgBox.setText("Could not read Residuals, make sure"+projectPath.path()+"/postProcessing/residuals/0/residuals.dat exists");
        msgBox.exec();
    }
}
*/
/*!
 * This does nothing in the current version
 */
void MainWindow::on_hide_show_clicked(){}
/*!
 * MainWindow::on_Solve_Button_clicked resets plotIdent,plotValues,indices,currentTime \n
 * Starts a new process with the indicated solver (eg. "simpleFoam). and \n
 * connects the readyReadStandardOutput() and readyReadStandardError() to
 * stream_StandardConsole_Output() and stream_ErrorConsole_Output() respectively
 */
void MainWindow::on_Solve_Button_clicked()
{
    plotIdent = QStringList();
    plotValues = QList<QList<double>>();
    indices = -1;
    currentTime = -1;
    ui->CustomPlot->clearGraphs();
    ui->Solver_Output->clear();
    ui->Solver_Error->clear();
    ui->Solver_Error->hide(); ui->SolverError_Label->hide();
    QDir solvePath(projectPath.path()+"/system");
    if(solvePath.exists())
    {
        QStringList args;
        args << "-case" << projectPath.path();
        QProcess *solveProcess = new QProcess();
        solveProcess->setCurrentReadChannel(QProcess::StandardOutput);
        solveProcess->setProgram(ui->solver_comboBox->currentText());
        solveProcess->setArguments(args);
        solveProcess->start();
        solveProcess->waitForStarted();
        connect(solveProcess,SIGNAL(readyReadStandardOutput()),this,SLOT(stream_StandardConsole_Output()));
        connect(solveProcess,SIGNAL(readyReadStandardError()),this,SLOT(stream_ErrorConsole_Output()));
        connect(solveProcess,SIGNAL(finished(int,QProcess::ExitStatus)),this,SLOT(write_Logs()));
        connect(ui->AbortSim_Button,SIGNAL(clicked()),solveProcess,SLOT(kill()));
    }
    else{
        QMessageBox msgBox;
        msgBox.setText("There was some problem with: "+projectPath.path()+"/system. Make sure it exists");
        msgBox.exec();
    }

}
/*!
 * Runs paraFoam inside project folder
 */
void MainWindow::on_paraFoam_Button_clicked()
{
    QProcess *paraFoam = new QProcess();
    QStringList args;
    args << "-case" << projectPath.path();
    paraFoam->setCurrentReadChannel(QProcess::StandardError);
    paraFoam->start("paraFoam",args);
    paraFoam->waitForFinished();
}
/*!
 * Gets called when solveProcess from on_Solve_Button_clicked() emits readyReadStandardOutput() or meshProcess from on_BlockMesh_Button_clicked() emits readyReadStandardOutput()\n
 * Streams the Console Output from OpenFOAM into the Solver_Output on the mainwindow \n
 * Also parses the Console Output and plots it in the QCustomPlot on the mainwindow this is ignored if the process that called is any meshProcess.
 */
void MainWindow::stream_StandardConsole_Output()
{
    QProcess *proc = qobject_cast<QProcess*>(sender());
    QString output = proc->readAllStandardOutput();
    auto parts = output.split("\n");
    double _currentTime=currentTime;
    //int _indices=indices;
    for(int i=0;i<parts.count() && proc->program()!="blockMesh";i++)
    {
        if(parts[i].contains("Time = ") && !parts[i].contains("ExecutionTime"))
        {
                _currentTime=parts[i].split("Time = ")[1].toFloat();
                if(!(currentTime == _currentTime))
                {
                    currentTime = _currentTime;
                    indices = indices + 1;
                }
        }
        if(parts[i].contains("Solving for "))
        {
            QString name = parts[i].split("Solving for ")[1].split(",")[0];
            if(plotIdent.isEmpty() || !plotIdent.contains(name))
            {

                plotIdent.append(name);
                ui->CustomPlot->addGraph();
                ui->CustomPlot->graph(plotIdent.indexOf(name))->setName(name);
                ui->CustomPlot->graph(plotIdent.indexOf(name))->setPen(QPen(QColor::fromHslF(std::fmod((plotIdent.indexOf(name)*0.618033988749895),1),1.0,0.5)));
            }
            QString value = parts[i].split("Initial residual = ")[1].split(",")[0];
            if(plotValues.count() < plotIdent.count())
            {
                plotValues.append(QList<double>());
            }
            plotValues[plotIdent.indexOf(name)].append(value.toDouble());
        }

    }
    qCritical() << currentTime << "currentime";
    for(int i=0;i<plotIdent.length() && i<plotValues.length();i++)
    {
        if(indices > 0 && !plotValues.empty() && plotValues[i].length()>indices)
            ui->CustomPlot->graph(i)->addData(currentTime,plotValues[i][indices-1]);
    }
    ui->CustomPlot->axisRect()->setupFullAxesBox();
    ui->CustomPlot->xAxis->setRange(0,currentTime);
    ui->CustomPlot->yAxis->setRange(0,1);
    if(ui->logarithmic_checkBox->isChecked())
        ui->CustomPlot->yAxis->setScaleType(QCPAxis::stLogarithmic);
    else
        ui->CustomPlot->yAxis->setScaleType(QCPAxis::stLinear);
    ui->CustomPlot->legend->setVisible(true);
    ui->CustomPlot->legend->setBrush(QBrush(QColor(255,255,255,150)));
    ui->CustomPlot->axisRect()->insetLayout()->setInsetAlignment(0,Qt::AlignRight|Qt::AlignTop);
    ui->CustomPlot->replot();

    if(proc->program() == "blockMesh" || proc->program() == "snappyHexMesh" )
       ui->Mesh_Output->append(output);
    else
        ui->Solver_Output->append(output);
}
/*!
 * Gets called when solveProcess from on_Solve_Button_clicked() emits readyReadStandardError() or meshProcess from on_BlockMesh_Button_clicked() emits readyReadStandardError()\n
 * Streams the Console Error Output from OpenFOAM into the Solver_Error on the mainwindow
 */
void MainWindow::stream_ErrorConsole_Output()
{
    QProcess *proc = qobject_cast<QProcess*>(sender());
    if(proc->program() == "blockMesh" || proc->program() == "snappyHexMesh" )
    {
        ui->Mesh_Error->append(proc->readAllStandardError());
        ui->Mesh_Error->show(); ui->MeshError_Label->show();
    }
    else
    {
        ui->Solver_Error->append(proc->readAllStandardError());
        ui->Solver_Error->show(); ui->SolverError_Label->show();
    }
}
/*!
 * Gets called when solveProcess from on_Solve_Button_clicked() emits finished() or meshProcess from on_BlockMesh_Button_clicked() emits finished()\n
 * Reads out the Process Output and Error Output and writes it into a file stored in the project folder /projectfolder/logs/<process>/<LogName + TimeStamp>.
 */
void MainWindow::write_Logs()
{
    QProcess *proc = qobject_cast<QProcess*>(sender());
    logger->logPath = projectPath;
    if(proc->program() == "blockMesh" || proc->program() == "snappyHexMesh" )
    {
        logger->writeLog(proc->program(),ui->Mesh_Output->toPlainText()+ui->Mesh_Error->toPlainText());
    }
    else
    {
        logger->writeLog(proc->program(),ui->Solver_Output->toPlainText()+ui->Solver_Error->toPlainText());
    }
}
/*!
 * \brief Switches the y-axis scale of the QCustomPlot from Mainwindow between logarithmic scale and linear scale
 * \param arg1 reprents the state of the checkbox, 0 -> 'off' and 2 -> 'on'
 */
void MainWindow::on_logarithmic_checkBox_stateChanged(int arg1)
{
    switch(arg1)
    {
    case 0:
        ui->CustomPlot->yAxis->setScaleType(QCPAxis::stLinear);
        ui->CustomPlot->replot();
        break;
    case 2:
        ui->CustomPlot->yAxis->setScaleType(QCPAxis::stLogarithmic);
        ui->CustomPlot->replot();
        break;
    default:
        qCritical() << "This should never happen";
        break;
    }
}




