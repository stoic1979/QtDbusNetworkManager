#ifndef NWUTIL_H
#define NWUTIL_H

#include <QObject>

#include <QtCore/QDebug>
#include <QtCore/QStringList>
#include <QtDBus/QtDBus>

class NwUtil : public QObject
{
    Q_OBJECT
public:
    explicit NwUtil(QObject *parent = 0);

    void scanWifiAccessPoints();

signals:

public slots:
};

#endif // NWUTIL_H
