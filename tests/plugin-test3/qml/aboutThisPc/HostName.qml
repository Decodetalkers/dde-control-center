import Command.Base 1.0
import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.11
import org.deepin.dtk 1.0 as Dtk

ColumnLayout {
    id: hostname

    property bool showedit: false

    RowLayout {
        visible: !hostname.showedit

        Text {
            text: AboutMyPc.StaticHostname
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
        text: AboutMyPc.StaticHostname
        visible: hostname.showedit
        focus: hostname.showedit
        onAccepted: {
            AboutMyPc.StaticHostname = text;
            hostname.showedit = false;
        }
    }

}
