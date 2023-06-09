// Copyright (C) 2017 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR BSD-3-Clause

import Command.Base 1.0
import QtQuick 2.0
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.11
import org.deepin.dtk 1.0 as Dtk

Item {
    id: root

    GroupBox {
        //title: BackendObject.StaticHostname
        anchors.horizontalCenter: parent.horizontalCenter

        ColumnLayout {
            spacing: 20
            anchors.fill: parent
            anchors.horizontalCenter: parent.horizontalCenter

            Dtk.Button {
                text: BackendObject.StaticHostname
            }

            RowLayout {
                Text {
                    text: qsTr("edition: ")
                    Layout.fillWidth: true
                }

                Text {
                    text: BackendObject.edition
                }

            }

            RowLayout {
                Text {
                    text: qsTr("type: ")
                    Layout.fillWidth: true
                }

                Text {
                    text: BackendObject.cputype
                }

            }

            RowLayout {
                Text {
                    text: qsTr("processor: ")
                    Layout.fillWidth: true
                }

                Text {
                    text: BackendObject.processor
                }

            }

            RowLayout {
                Text {
                    text: qsTr("memory: ")
                    Layout.fillWidth: true
                }

                Text {
                    text: BackendObject.memory
                }

            }

            RowLayout {
                Text {
                    text: qsTr("graphicsPlatform: ")
                    Layout.fillWidth: true
                }

                Text {
                    text: BackendObject.graphicsPlatform
                }

            }

            RowLayout {
                Text {
                    text: qsTr("kernel: ")
                    Layout.fillWidth: true
                }

                Text {
                    text: BackendObject.kernel
                }

            }

        }

    }

}
