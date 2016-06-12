#include <QCoreApplication>

#include "application.h"
#include <QDebug>

int parseTime(QString time);

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    if(argc < 3)
    {
        qDebug() << "To few arguments!";
        qDebug() << "Usage: cmdtimeout [00h][00m]00[s] command [argumentlist]";
    }

    int msec = parseTime(QString(argv[1]));

    QStringList lst;
    for(int idx=0; idx < argc-3; idx++)
    {
        QString tmpString(argv[idx+3]);
        lst += tmpString;
    }

    QString cmd(argv[2]);
    Application app(cmd,lst,msec);

    return a.exec();
}


int parseTime(QString time)
{
    int res = 0;
    int tmp = 0;

    for(int idx=0; idx<time.length(); idx++)
    {
        if(time[idx].isDigit())
        {
            tmp *= 10;
            tmp += time[idx].digitValue();
        }
        else
        {
            switch(time[idx].toLower().toLatin1())
            {
                case 'h':
                    tmp *= 3600000;
                    res += tmp;
                    tmp = 0;
                    break;
                case 'm':
                    tmp *= 60000;
                    res += tmp;
                    tmp = 0;
                    break;
                case 's':
                    tmp *= 1000;
                    res += tmp;
                    tmp = 0;
                    break;
                default:
                    return res;
            }
        }
    }
    res += tmp * 1000;
    return res;
}
