#include "nwutil.h"

QDBusConnection bus = QDBusConnection::systemBus();


NwUtil::NwUtil(QObject *parent) : QObject(parent) {}

void NwUtil::showAccessPointProperties(QString ap) {
    qDebug() << "[AccessPoint] :: " << ap;

    QDBusConnection bus = QDBusConnection::systemBus();

    QDBusInterface dbus_iface("org.freedesktop.NetworkManager",      // service
                              ap,                                    // path
                              "org.freedesktop.DBus.Properties",     // interface
                              bus);

    QList<QString> props;
    props << "Ssid" << "HwAddress";

    // getting Ssid, HwAddress
    for(int i=0; i<props.length(); i++) {


        QDBusMessage query =  dbus_iface.call("Get", "org.freedesktop.NetworkManager.AccessPoint", props[i]);

        if(query.type() == QDBusMessage::ReplyMessage) {
            qDebug() << props[i] << ": " << query.arguments().at(0).value<QDBusVariant>().variant().toString();

        } else {
            qDebug() << "[scanWifiAccessPoints] got dbus error: " << query.errorName();
            qDebug() << "[scanWifiAccessPoints] check the parameters like service, path, interface and method name !!!";
        }
    }

    // getting Strength
    QDBusMessage query =  dbus_iface.call("Get", "org.freedesktop.NetworkManager.AccessPoint", "Strength");

    if(query.type() == QDBusMessage::ReplyMessage) {
        qDebug() << " Strength: " << query.arguments().at(0).value<QDBusVariant>().variant().toUInt();

    } else {
        qDebug() << "[scanWifiAccessPoints] got dbus error: " << query.errorName();
        qDebug() << "[scanWifiAccessPoints] check the parameters like service, path, interface and method name !!!";
    }

}


/**
 * @brief NwUtil::scanWifiAccessPoints
 *
 * Description:
 * function scans the list available wifi networks on
 * dbus interface "org.freedesktop.NetworkManager.Device.Wireless"
 */
void NwUtil::scanWifiAccessPoints() {
    QStringList *netList = new QStringList();

    QDBusInterface dbus_iface("org.freedesktop.NetworkManager",                     // service
                              "/org/freedesktop/NetworkManager/Devices/0",          // path
                              "org.freedesktop.NetworkManager.Device.Wireless",     // interface
                              bus);


    QDBusMessage query = dbus_iface.call("GetAccessPoints");

    if(query.type() == QDBusMessage::ReplyMessage) {

        QDBusArgument arg = query.arguments().at(0).value<QDBusArgument>();
        arg.beginArray();
        while(!arg.atEnd()) {
            QString element = qdbus_cast<QString>(arg);
            netList->append(element);
            showAccessPointProperties(element);
        }
        arg.endArray();
    } else {
        qDebug() << "[scanWifiAccessPoints] got dbus error: " << query.errorName();
        qDebug() << "[scanWifiAccessPoints] check the parameters like service, path, interface and method name !!!";
    }

}
