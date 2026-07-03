import QtQuick
import MarioKartBuildAnalyzer

// Barra de estadistica animada. `ratio` va de 0.0 a 1.0 y anima
// suavemente cada vez que cambia (al cambiar de componente en el build).
Item {
    id: root
    property string label: ""
    property real value: 0
    property real ratio: 0            // 0..1, ya normalizado
    property color barColor: Theme.accentCyan
    property bool showValue: true

    implicitHeight: 34
    implicitWidth: 260

    Behavior on ratio {
        NumberAnimation { duration: Theme.animSlow; easing.type: Theme.easingType }
    }

    Row {
        width: parent.width
        spacing: Theme.spacingSmall

        Text {
            width: 118
            text: root.label
            color: Theme.textSecondary
            font.pixelSize: Theme.fontSmall
            font.family: Theme.fontFamily
            elide: Text.ElideRight
            anchors.verticalCenter: parent.verticalCenter
        }

        Item {
            width: parent.width - 118 - (root.showValue ? 40 : 0) - Theme.spacingSmall * 2
            height: 14
            anchors.verticalCenter: parent.verticalCenter

            Rectangle {
                anchors.fill: parent
                radius: height / 2
                color: Theme.surfaceLight
                border.color: Theme.surfaceBorder
                border.width: 1
            }

            Rectangle {
                id: fill
                height: parent.height
                radius: height / 2
                width: Math.max(height, parent.width * root.ratio)
                gradient: Gradient {
                    orientation: Gradient.Horizontal
                    GradientStop { position: 0.0; color: root.barColor }
                    GradientStop { position: 1.0; color: Qt.lighter(root.barColor, 1.35) }
                }

                Rectangle {
                    // brillo superior sutil, look "arcade"
                    width: parent.width
                    height: parent.height * 0.45
                    radius: parent.radius
                    color: "#ffffff"
                    opacity: 0.18
                    anchors.top: parent.top
                }
            }
        }

        Text {
            visible: root.showValue
            width: 40
            text: root.value.toFixed(1)
            color: Theme.textPrimary
            font.pixelSize: Theme.fontSmall
            font.bold: true
            font.family: Theme.fontFamily
            horizontalAlignment: Text.AlignRight
            anchors.verticalCenter: parent.verticalCenter
        }
    }
}
