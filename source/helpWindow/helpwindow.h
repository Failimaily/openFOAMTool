#ifndef HELPWINDOW_H
#define HELPWINDOW_H
/// \cond
#include <QFrame>
#include <QTabWidget>
#include <QHelpContentWidget>
#include <QHelpIndexWidget>
/// \endcond
#include <helpWindow/helpbrowser.h>
namespace Ui {
class HelpWindow;
}

class HelpWindow : public QFrame
{
    Q_OBJECT

public:
    explicit HelpWindow(QWidget *parent = nullptr);
    ~HelpWindow();
    void close();

private:
    Ui::HelpWindow *ui;
};

#endif // HELPWINDOW_H
