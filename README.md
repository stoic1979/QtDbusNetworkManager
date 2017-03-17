# QtDbusNetworkManager
Qt Dbus communications with NetworkManager to get varoius network configurations, wifi access points etc.

# Checking Network Manager's dbus interfaces/apis etc
* qdbus --system org.freedesktop.NetworkManager
* qdbus --system org.freedesktop.NetworkManager /org/freedesktop/NetworkManager
* qdbus --system --literal org.freedesktop.NetworkManager /org/freedesktop/NetworkManager org.freedesktop.DBus.Properties.Get org.freedesktop.NetworkManager ActiveConnections

* dbus-send --print-reply --system \
    --dest=org.freedesktop.NetworkManager \
    /org/freedesktop/NetworkManager/Settings/0 \
    org.freedesktop.NetworkManager.Settings.Connection.GetSettings

* dbus-send --print-reply --type=method_call --system \
        --dest=org.freedesktop.NetworkManager \
        /org/freedesktop/NetworkManager/Settings \
        org.freedesktop.DBus.Properties.Get \
        string:org.freedesktop.NetworkManager.Settings \
        string:"Connections"

# References
* http://people.redhat.com/dcbw/NetworkManager/NetworkManager%20DBUS%20API.txt
* http://doc.qt.io/qt-5/qtdbus-module.html
