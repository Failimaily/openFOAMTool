#include "helpwindow.h"
#include "ui_helpwindow.h"
/*!
 * Creates the specified ui in helpWindow.ui \n
 * Creates a new helpEngine with the help container path specified. \n
 * helpEngine reads out the data and fills the qTabWidget with the Contents.
 * \param parent represents the QWidget which created HelpWindow
 */
HelpWindow::HelpWindow(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::HelpWindow)
{
    ui->setupUi(this);
    this->setAttribute(Qt::WA_DeleteOnClose);
    QHelpEngine *helpEngine = new QHelpEngine(QApplication::applicationDirPath()+"/help/OpenFOAM Docs.qhc",this);
    helpEngine->setupData();

    QTabWidget *tWidget = new QTabWidget(this);
    tWidget->setMaximumWidth(200);
    tWidget->setMinimumWidth(200);
    tWidget->addTab(helpEngine->contentWidget(),"Contents");;

    HelpBrowser *textViewer = new HelpBrowser(helpEngine,this);
    textViewer->setSource(QUrl("qthelp://openfoamdocs/doc/Setup.html"));
    HelpWindow::layout()->addWidget(tWidget);
    HelpWindow::layout()->addWidget(textViewer);

    connect(helpEngine->contentWidget(),SIGNAL(linkActivated(QUrl)),textViewer,SLOT(setSource(QUrl)));

}
/*!
 * Deletes the ui and deallocates the memory.
 */
HelpWindow::~HelpWindow()
{
    delete ui;
}

