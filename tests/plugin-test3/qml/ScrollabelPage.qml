// Copyright (C) 2017 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR BSD-3-Clause

// NOTE: is use in PageModule, use it
import QtQuick 2.15
import QtQuick.Controls 2.15

Page {
    id: page

    default property alias content: pane.contentItem

    Flickable {
        anchors.fill: parent
        contentHeight: pane.implicitHeight
        flickableDirection: Flickable.AutoFlickIfNeeded

        Pane {
            id: pane

            width: parent.width
        }

        ScrollIndicator.vertical: ScrollIndicator {
        }

    }

}
