import Command.Base 1.0
import QtQuick 2.0

Image {
    source: BackendObject.isLaptop ? "qrc:/resources/icon_about_laptop.svg" : "qrc:/resources/icon_about_pc.svg"
}
