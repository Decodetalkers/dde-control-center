// Copyright (C) 2017 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR BSD-3-Clause

import QtQuick 2.0
import QtQuick.Layouts 1.11
import "aboutThisPc" as AboutThisPc

ScrollabelPage {
    id: root

    ColumnLayout {
        //anchors.fill: parent
        anchors.horizontalCenter: parent.horizontalCenter

        AboutThisPc.PcImage {
            Layout.alignment: Qt.AlignHCenter
            Layout.preferredWidth: 280
            Layout.preferredHeight: 280
        }

        AboutThisPc.HostName {
            Layout.alignment: Qt.AlignHCenter
        }

        AboutThisPc.SystemInfo {
            Layout.alignment: Qt.AlignHCenter
            implicitWidth: root.width - 60 > 1000 ? 1000 : root.width - 60
        }

    }

}
