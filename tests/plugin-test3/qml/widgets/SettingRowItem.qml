import QtQuick 2.0
import QtQuick.Layouts 1.11

Rectangle {
    default property alias data: row.data
    implicitWidth: row.implicitWidth
    implicitHeight: row.implicitHeight * 2
    color: "#f0f0f0"
    radius: 5
    RowLayout {
        anchors.leftMargin: 10
        anchors.rightMargin: 10
        id: row
        anchors.fill: parent
    }
}
