import Command.Base 1.0
import QtQuick 2.0
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.11
import org.deepin.dtk 1.0 as Dtk

ColumnLayout {
    id: hostname

    property bool showedit: false

    RowLayout {
        visible: !hostname.showedit

        Text {
            text: BackendObject.StaticHostname
        }

        Dtk.Button {
            text: "e"
            onClicked: {
                hostname.showedit = true;
            }
        }

    }

    TextField {
        Layout.fillWidth: true
        Layout.alignment: Qt.AlignCenter | Qt.AlignBaseline
        text: BackendObject.StaticHostname
        visible: hostname.showedit
        onAccepted: {
            BackendObject.StaticHostname = text;
            hostname.showedit = false;
        }
    }

}
