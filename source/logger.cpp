#include "logger.h"


Logger::Logger(QString path) :
    logPath(path)
{

}
/*!
 * Logger::writeLog creates the log folder structure in the given logPath. \n
 * \param logName represents the name of the log which is to be written.
 * \param logContent represents the content of the log which is to be written.
 */
void Logger::writeLog(QString logName,QString logContent)
{
    QDir logPath;
    logPath.mkpath(this->logPath.path()+"/logs/"+logName);
    QString filename =logName+" - "+QDateTime::currentDateTime().toString("dd.MM.yyyy")+" - "+QDateTime::currentDateTime().toString("hh:mm:ss")+".log";
    QFile log(this->logPath.path()+"/logs/"+logName+"/"+filename);
    if(log.open(QIODevice::ReadWrite))
    {
        qCritical() << "Log created";
        QTextStream stream(&log);
        stream << logContent << endl;
    }
}
