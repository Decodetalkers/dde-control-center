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
        //title: BackendObject.StaticHostname
        anchors.horizontalCenter: parent.horizontalCenter

        ColumnLayout {
            spacing: 20
            anchors.fill: parent

            Dtk.Button {
                text: BackendObject.StaticHostname
            }
            Text {
                text: BackendObject.edition
                //visible: false
            }
            Text {
                text: BackendObject.cputype
            }
            Text {
                text: BackendObject.processor
            }
            Text {
                text: BackendObject.memory
            }
            Text {
                text: BackendObject.graphicsPlatform
            }
            Text {
                text: BackendObject.kernel
            }
        }
    }
}
