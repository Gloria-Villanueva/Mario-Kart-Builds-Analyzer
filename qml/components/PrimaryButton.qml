import QtQuick
import MarioKartBuildAnalyzer

// Boton con degradado, sombra y micro-animaciones de hover/press.
// Estilo "arcade": se infla ligeramente al pasar el mouse y se
// comprime al presionar, dando sensacion de feedback tactil.
Item {
    id: root
    signal clicked()

    property string text: "Boton"
    property var colors: Theme.gradientPrimary
    property bool enabled: true
    property bool outlined: false
    property real iconSize: 0
    property url iconSource: ""

    implicitWidth: label.implicitWidth + (iconSource != "" ? 34 : 0) + 44
    implicitHeight: 46

    scale: mouse.pressed ? 0.96 : (mouse.containsMouse ? 1.035 : 1.0)
    opacity: root.enabled ? 1.0 : 0.45

    Behavior on scale { NumberAnimation { duration: Theme.animFast; easing.type: Easing.OutBack } }

    Rectangle {
        anchors.fill: parent
        radius: Theme.radiusMedium
        border.width: root.outlined ? 2 : 0
        border.color: root.colors[0]
        color: root.outlined ? "transparent" : root.colors[0]

        gradient: root.outlined ? null : Gradient {
            orientation: Gradient.Horizontal
            GradientStop { position: 0.0; color: root.colors[0] }
            GradientStop { position: 1.0; color: root.colors[1] }
        }

        Rectangle {
            // brillo superior
            visible: !root.outlined
            width: parent.width
            height: parent.height * 0.5
            radius: parent.radius
            color: "#ffffff"
            opacity: mouse.containsMouse ? 0.22 : 0.12
            Behavior on opacity { NumberAnimation { duration: Theme.animFast } }
        }
    }

    Row {
        anchors.centerIn: parent
        spacing: 8

        Image {
            visible: root.iconSource != ""
            source: root.iconSource
            width: 20; height: 20
            anchors.verticalCenter: parent.verticalCenter
            fillMode: Image.PreserveAspectFit
        }

        Text {
            id: label
            text: root.text
            color: root.outlined ? root.colors[0] : Theme.textPrimary
            font.pixelSize: Theme.fontBody
            font.bold: true
            font.family: Theme.fontFamily
            anchors.verticalCenter: parent.verticalCenter
        }
    }

    MouseArea {
        id: mouse
        anchors.fill: parent
        hoverEnabled: true
        cursorShape: root.enabled ? Qt.PointingHandCursor : Qt.ArrowCursor
        enabled: root.enabled
        onClicked: root.clicked()
    }
}
