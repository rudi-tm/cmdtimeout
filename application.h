#ifndef APPLICATION_H
#define APPLICATION_H

#include <QObject>

#include <QProcess>
#include <QTimer>
#include <QString>
#include <QStringList>

class Application : public QObject
{
    Q_OBJECT
public:
    explicit Application(QObject *parent = 0);
    Application(QString& cmd, QStringList& arg, int msec, QObject *parent=0);
private:
    QProcess *mCmd;
    QTimer   *mTimer;

signals:

public slots:
    void timeout();
    void finished(int code);
};

#endif // APPLICATION_H
