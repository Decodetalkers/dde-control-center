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
            icon.name: "dcc_edit"
            Layout.preferredWidth: 30
            Layout.preferredHeight: 30
            onClicked: {
                hostname.showedit = true;
            }
        }

    }

    TextField {
        Layout.alignment: Qt.AlignCenter | Qt.AlignBaseline
        text: BackendObject.StaticHostname
        visible: hostname.showedit
        focus: hostname.showedit
        onAccepted: {
            BackendObject.StaticHostname = text;
            hostname.showedit = false;
        }
    }

}
