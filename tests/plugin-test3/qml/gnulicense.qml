// Copyright (C) 2017 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR BSD-3-Clause

import Command.Base 1.0
import QtQuick 2.0
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.11

ScrollabelPage {
    id: root
    height: column.height
    ColumnLayout {
        id: column
        spacing: 50
        anchors.horizontalCenter: parent.horizontalCenter

        Text {
            text: LicenseObject.gnuLicenseTitle
        }
        Text {
            text: LicenseObject.gnuLicense
            wrapMode: Text.Wrap
        }

    }
}
