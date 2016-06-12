#include <QCoreApplication>

#include "application.h"
#include <QDebug>

int parseTime(QString time);

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

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
