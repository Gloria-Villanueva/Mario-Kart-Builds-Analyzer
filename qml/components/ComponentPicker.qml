import QtQuick
import MarioKartBuildAnalyzer

// Selector horizontal de componentes (driver / body / tire / glider).
// Cada item se representa con un avatar en degradado (no usamos arte
// de personajes con copyright: el color y la inicial identifican al
// componente) mas un icono de categoria en la esquina.
Column {
    id: root
    property string title: ""
    property var model: null
    property color accent: Theme.accentCyan
    property int currentIndex: 0
    signal picked(int index)

    spacing: Theme.spacingSmall
    width: parent ? parent.width : 400

    Text {
        text: root.title
        color: Theme.textSecondary
        font.pixelSize: Theme.fontSmall
        font.bold: true
        font.family: Theme.fontFamily
        font.letterSpacing: 1
    }

    ListView {
        id: listView
        width: parent.width
        height: 118
        orientation: ListView.Horizontal
        spacing: Theme.spacingSmall
        clip: true
        model: root.model

        delegate: Item {
            id: cardRoot
            width: 96
            height: 112
            required property int index
            required property string name
            required property string category
            required property double score
            required property string icon

            property bool selected: index === root.currentIndex

            Rectangle {
                id: card
                anchors.fill: parent
                radius: Theme.radiusMedium
                color: cardRoot.selected ? Qt.darker(root.accent, 2.6) : Theme.surfaceLight
                border.width: cardRoot.selected ? 2 : 1
                border.color: cardRoot.selected ? root.accent : Theme.surfaceBorder
                scale: cardRoot.selected ? 1.04 : (ma.containsMouse ? 1.02 : 1.0)

                Behavior on scale { NumberAnimation { duration: Theme.animFast; easing.type: Easing.OutBack } }
                Behavior on color { ColorAnimation { duration: Theme.animFast } }

                Column {
                    anchors.centerIn: parent
                    spacing: 6

                    Item {
                        width: 46; height: 46
                        anchors.horizontalCenter: parent.horizontalCenter

                        Rectangle {
                            id: avatar
                            anchors.fill: parent
                            radius: width / 2
                            gradient: Gradient {
                                GradientStop { position: 0.0; color: Qt.hsla((cardRoot.index * 0.13) % 1.0, 0.65, 0.55, 1) }
                                GradientStop { position: 1.0; color: Qt.hsla((cardRoot.index * 0.13 + 0.12) % 1.0, 0.65, 0.4, 1) }
                            }
                            border.color: "#ffffff33"
                            border.width: 1
                        }
                        Text {
                            anchors.centerIn: parent
                            text: cardRoot.name.length > 0 ? cardRoot.name.charAt(0).toUpperCase() : "?"
                            color: "#ffffff"
                            font.bold: true
                            font.pixelSize: 18
                            font.family: Theme.fontFamily
                        }
                        Image {
                            source: cardRoot.icon
                            width: 18; height: 18
                            anchors.right: parent.right
                            anchors.bottom: parent.bottom
                            anchors.margins: -2
                        }
                    }

                    Text {
                        width: 84
                        horizontalAlignment: Text.AlignHCenter
                        text: cardRoot.name
                        color: Theme.textPrimary
                        font.pixelSize: 11
                        font.bold: cardRoot.selected
                        font.family: Theme.fontFamily
                        elide: Text.ElideRight
                        maximumLineCount: 1
                    }
                    Text {
                        width: 84
                        horizontalAlignment: Text.AlignHCenter
                        visible: cardRoot.category !== ""
                        text: cardRoot.category
                        color: Theme.textMuted
                        font.pixelSize: 9
                        font.family: Theme.fontFamily
                        elide: Text.ElideRight
                        maximumLineCount: 1
                    }
                }
            }

            MouseArea {
                id: ma
                anchors.fill: parent
                hoverEnabled: true
                cursorShape: Qt.PointingHandCursor
                onClicked: root.picked(cardRoot.index)
            }
        }
    }
}
