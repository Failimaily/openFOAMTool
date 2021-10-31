#ifndef HELPBROWSER_H
#define HELPBROWSER_H
/// \cond
#include <QTextBrowser>
#include <QHelpEngine>
/// \endcond
/*!
 * The HelpBrowser class is a QTextBrowser which also contains a QHelpEngine.
 *
 */
class HelpBrowser : public QTextBrowser
{
    public:
        HelpBrowser(QHelpEngine* helpEngine, QWidget* parent = 0);
        QVariant loadResource (int type, const QUrl& name);
        QHelpEngine* helpEngine;
    private:


};

#endif // HELPBROWSER_H
