# QtDbusNetworkManager
Qt Dbus communications with NetworkManager to get varoius network configurations, wifi access points etc.

# Checking Network Manager's dbus interfaces/apis etc
* qdbus --system org.freedesktop.NetworkManager
* qdbus --system org.freedesktop.NetworkManager /org/freedesktop/NetworkManager
* qdbus --system --literal org.freedesktop.NetworkManager /org/freedesktop/NetworkManager org.freedesktop.DBus.Properties.Get org.freedesktop.NetworkManager ActiveConnections

# References
* http://people.redhat.com/dcbw/NetworkManager/NetworkManager%20DBUS%20API.txt
* http://doc.qt.io/qt-5/qtdbus-module.html
