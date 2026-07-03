import QtQuick
import MarioKartBuildAnalyzer

Rectangle {
    id: root
    width: 92
    color: Theme.surface
    border.color: Theme.surfaceBorder
    border.width: 1

    property int currentIndex: 0
    property var items: []   // [{label, icon}]
    signal navigate(int index)

    Column {
        anchors.top: parent.top
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.topMargin: Theme.spacingLarge
        spacing: Theme.spacingLarge

        Image {
            source: "qrc:/assets/icons/icon_logo.svg"
            width: 40; height: 40
            anchors.horizontalCenter: parent.horizontalCenter
            fillMode: Image.PreserveAspectFit
        }

        Repeater {
            model: root.items

            delegate: Item {
                id: navItem
                required property int index
                required property var modelData

                width: 76
                height: 64

                property bool active: navItem.index === root.currentIndex

                Rectangle {
                    anchors.fill: parent
                    radius: Theme.radiusMedium
                    color: navItem.active ? Theme.surfaceLight : "transparent"
                    border.width: navItem.active ? 1 : 0
                    border.color: Theme.accentBlue

                    Behavior on color { ColorAnimation { duration: Theme.animFast } }

                    Rectangle {
                        visible: navItem.active
                        width: 3
                        height: parent.height * 0.6
                        radius: 2
                        color: Theme.accentCyan
                        anchors.left: parent.left
                        anchors.verticalCenter: parent.verticalCenter
                    }

                    Column {
                        anchors.centerIn: parent
                        spacing: 4
                        Image {
                            source: navItem.modelData.icon
                            width: 26; height: 26
                            anchors.horizontalCenter: parent.horizontalCenter
                            fillMode: Image.PreserveAspectFit
                            opacity: navItem.active ? 1.0 : 0.72
                        }
                        Text {
                            text: navItem.modelData.label
                            color: navItem.active ? Theme.textPrimary : Theme.textMuted
                            font.pixelSize: 10
                            font.bold: navItem.active
                            font.family: Theme.fontFamily
                            anchors.horizontalCenter: parent.horizontalCenter
                        }
                    }
                }

                MouseArea {
                    anchors.fill: parent
                    cursorShape: Qt.PointingHandCursor
                    onClicked: root.navigate(navItem.index)
                }
            }
        }
    }
}
