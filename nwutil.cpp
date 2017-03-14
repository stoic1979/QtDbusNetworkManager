#include "nwutil.h"

NwUtil::NwUtil(QObject *parent) : QObject(parent) {}

/**
 * @brief NwUtil::scanWifiAccessPoints
 *
 * Description:
 * function scans the list available wifi networks on
 * dbus interface "org.freedesktop.NetworkManager.Device.Wireless"
 */
void NwUtil::scanWifiAccessPoints() {
    QStringList *netList = new QStringList();
    QDBusConnection bus = QDBusConnection::systemBus();

    QDBusInterface dbus_iface("org.freedesktop.NetworkManager",                     // service
                              "/org/freedesktop/NetworkManager/Devices/0",          // path
                              "org.freedesktop.NetworkManager.Device.Wireless",     // interface
                              bus);


    QDBusMessage query= dbus_iface.call("GetAccessPoints");

    if(query.type() == QDBusMessage::ReplyMessage) {

        QDBusArgument arg = query.arguments().at(0).value<QDBusArgument>();
        arg.beginArray();
        while(!arg.atEnd()) {
            QString element = qdbus_cast<QString>(arg);
            netList->append(element);
            qDebug() << element;
        }
        arg.endArray();
    } else {
        qDebug() << "[scanWifiAccessPoints] got dbus error: " << query.errorName();
        qDebug() << "[scanWifiAccessPoints] check the parameters like service, path, interface and method name !!!";
    }

}
