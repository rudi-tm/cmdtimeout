#include "application.h"

#include <QCoreApplication>

Application::Application(QObject *parent) : QObject(parent)
{

}

Application::Application(QString &cmd, QStringList &arg, int msec, QObject *parent) : QObject(parent)
{
    mCmd = new QProcess();
    mCmd->setProcessChannelMode(QProcess::ForwardedChannels);
    connect(mCmd,SIGNAL(finished(int)),this,SLOT(finished(int)));
    mCmd->start(cmd,arg);

    mTimer = new QTimer();
    mTimer->singleShot(msec,this,SLOT(timeout()));
}

void Application::timeout()
{
    if(NULL != mCmd)
    {
        if(mCmd->Running)
        {
            mCmd->kill();
        }
    }
}

void Application::finished(int core)
{
    QCoreApplication::quit();
}
