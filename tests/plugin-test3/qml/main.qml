// Copyright (C) 2017 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR BSD-3-Clause

import QtQuick 2.0
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.11

import org.deepin.dtk 1.0 as Dtk
import Command.Base 1.0

Item {
    id: root
    GroupBox {
        title: BackendObject.StaticHostname
        anchors.horizontalCenter: parent.horizontalCenter

        ColumnLayout {
            spacing: 20
            anchors.fill: parent

            Text {
                text: BackendObject.name
            }
            RadioButton {
                text: "First"
                checked: BackendObject.name === text
                Layout.preferredWidth : root.width * 2 / 3
                Layout.fillWidth: true
                onClicked: {
                    BackendObject.name = text
                }
            }
            RadioButton {
                text: "Second"
                checked: BackendObject.name === text 
                onClicked: {
                    BackendObject.name = text
                }
            }
            RadioButton {
                text: "Third"
                checked: BackendObject.name === text 
                onClicked: {
                    BackendObject.name = text
                }
            }
            Switch {
                checked: BackendObject.isGangdum
                onClicked : {
                    BackendObject.isGangdum = checked
                }
            }
            Dtk.Switch {
                checked: BackendObject.isGangdum
                onClicked : {
                    BackendObject.isGangdum = checked
                }
            }
        }
    }
}
