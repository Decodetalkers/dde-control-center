// Copyright (C) 2017 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR BSD-3-Clause

import "../widgets" as DCCWidget
import Command.Base 1.0
import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.11

GroupBox {
    ColumnLayout {
        spacing: 1
        anchors.fill: parent
        anchors.horizontalCenter: parent.horizontalCenter

        DCCWidget.SettingRowItem {
            Layout.fillWidth: true

            Text {
                text: qsTr("edition: ")
                Layout.fillWidth: true
            }

            Text {
                text: AboutMyPc.edition
            }

        }

        DCCWidget.SettingRowItem {
            Layout.fillWidth: true

            Text {
                text: qsTr("type: ")
                Layout.fillWidth: true
            }

            Text {
                text: AboutMyPc.cputype
            }

        }

        DCCWidget.SettingRowItem {
            Layout.fillWidth: true

            Text {
                text: qsTr("processor: ")
                Layout.fillWidth: true
            }

            Text {
                text: AboutMyPc.processor
            }

        }

        DCCWidget.SettingRowItem {
            Layout.fillWidth: true

            Text {
                text: qsTr("memory: ")
                Layout.fillWidth: true
            }

            Text {
                text: AboutMyPc.memory
            }

        }

        DCCWidget.SettingRowItem {
            Layout.fillWidth: true

            Text {
                text: qsTr("Graphics Platform: ")
                Layout.fillWidth: true
            }

            Text {
                text: AboutMyPc.graphicsPlatform
            }

        }

        DCCWidget.SettingRowItem {
            Layout.fillWidth: true

            Text {
                text: qsTr("kernel: ")
                Layout.fillWidth: true
            }

            Text {
                text: AboutMyPc.kernel
            }

        }

    }

    background: Rectangle {
        radius: 5
        color: "transparent"
    }

}
