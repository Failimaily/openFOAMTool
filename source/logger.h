#ifndef LOGGER_H
#define LOGGER_H
/// \cond
#include <QString>
#include <QFile>
#include <QDateTime>
#include <QDir>
#include <QTextStream>
#include <QDebug>
/// \endcond
class Logger
{
public:
    Logger(QString path);
    void writeLog(QString logName,QString logContent);
    QDir logPath;

private:

};

#endif // LOGGER_H
