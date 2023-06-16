// Copyright (C) 2017 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR BSD-3-Clause

import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.11
import "aboutThisPc" as AboutThisPc
import org.deepin.dtk 1.0 as D


Page {
    id: root
    height: column.height
    palette: D.DTK.palette

    ColumnLayout {
        id: column
        spacing: 30
        anchors.horizontalCenter: parent.horizontalCenter

        AboutThisPc.PcImage {
            Layout.alignment: Qt.AlignHCenter
            Layout.preferredWidth: 200
            Layout.preferredHeight: 200
        }

        AboutThisPc.HostName {
            Layout.alignment: Qt.AlignHCenter
        }

        AboutThisPc.SystemInfo {
            Layout.alignment: Qt.AlignHCenter
            implicitWidth: root.width
        }

    }

}
