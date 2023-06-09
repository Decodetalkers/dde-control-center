// Copyright (C) 2017 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR BSD-3-Clause

import QtQuick 2.0
import QtQuick.Layouts 1.11
import "aboutThisPc" as AboutThisPc

Item {
    id: root

    ColumnLayout {
        anchors.horizontalCenter: parent.horizontalCenter

        AboutThisPc.HostName {
            Layout.alignment: Qt.AlignHCenter
        }

        AboutThisPc.SystemInfo {
        }

    }

}
