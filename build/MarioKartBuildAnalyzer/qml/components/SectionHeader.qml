import QtQuick
import MarioKartBuildAnalyzer

Row {
    id: root
    property string iconSource: ""
    property string title: ""
    property string subtitle: ""
    spacing: Theme.spacingMedium

    Rectangle {
        visible: root.iconSource != ""
        width: 46; height: 46
        radius: Theme.radiusMedium
        anchors.verticalCenter: parent.verticalCenter
        gradient: Gradient {
            orientation: Gradient.Diagonal
            GradientStop { position: 0.0; color: Theme.accentPurple }
            GradientStop { position: 1.0; color: Theme.accentBlue }
        }
        Image {
            anchors.centerIn: parent
            source: root.iconSource
            width: 28; height: 28
            fillMode: Image.PreserveAspectFit
        }
    }

    Column {
        anchors.verticalCenter: parent.verticalCenter
        spacing: 2
        Text {
            text: root.title
            color: Theme.textPrimary
            font.pixelSize: Theme.fontTitle
            font.bold: true
            font.family: Theme.fontFamily
        }
        Text {
            visible: root.subtitle != ""
            text: root.subtitle
            color: Theme.textSecondary
            font.pixelSize: Theme.fontBody
            font.family: Theme.fontFamily
        }
    }
}
