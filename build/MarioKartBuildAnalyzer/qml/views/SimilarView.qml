import QtQuick
import QtQuick.Controls
import MarioKartBuildAnalyzer

Item {
    id: root
    property var sfx: null
    property var build: appController.currentBuild

    Column {
        anchors.fill: parent
        anchors.margins: Theme.spacingLarge
        spacing: Theme.spacingLarge

        SectionHeader {
            iconSource: "qrc:/assets/icons/icon_glider.svg"
            title: "Builds similares"
            subtitle: "Combinaciones mas parecidas a tu build actual (pestana \"Build\")"
        }

        GlassCard {
            width: parent.width
            height: 56
            Row {
                anchors.fill: parent
                spacing: Theme.spacingSmall
                Text {
                    anchors.verticalCenter: parent.verticalCenter
                    text: "Referencia: "
                    color: Theme.textMuted
                    font.family: Theme.fontFamily
                }
                Text {
                    anchors.verticalCenter: parent.verticalCenter
                    text: root.build.ready
                        ? (root.build.driverName + " · " + root.build.bodyName + " · " + root.build.tireName + " · " + root.build.gliderName)
                        : "-"
                    color: Theme.textPrimary
                    font.bold: true
                    font.family: Theme.fontFamily
                    elide: Text.ElideRight
                    width: parent.width - 120
                }
            }
        }

        Row {
            spacing: Theme.spacingMedium
            Text {
                text: "Cuantos builds: " + slider.value.toFixed(0)
                color: Theme.textSecondary
                font.pixelSize: Theme.fontBody
                font.family: Theme.fontFamily
                anchors.verticalCenter: parent.verticalCenter
            }
            Slider {
                id: slider
                from: 1; to: 10; value: 5; stepSize: 1
                width: 220
                anchors.verticalCenter: parent.verticalCenter
            }
            PrimaryButton {
                text: "Buscar similares"
                colors: Theme.gradientPower
                onClicked: {
                    appController.computeSimilar(slider.value)
                    if (root.sfx) root.sfx.confirm()
                }
            }
        }

        Text {
            visible: appController.similarModel.count === 0
            text: "Toca \"Buscar similares\" para comparar contra tu build."
            color: Theme.textMuted
            font.family: Theme.fontFamily
        }

        ListView {
            width: parent.width
            height: parent.height - 226
            clip: true
            spacing: Theme.spacingSmall
            model: appController.similarModel

            delegate: GlassCard {
                id: rowCard
                required property int index
                required property int rank
                required property string driverName
                required property string bodyName
                required property string tireName
                required property string gliderName
                required property double score
                required property double distance

                width: ListView.view.width
                height: 70

                Row {
                    anchors.fill: parent
                    spacing: Theme.spacingMedium

                    Rectangle {
                        width: 40; height: 40
                        radius: 20
                        anchors.verticalCenter: parent.verticalCenter
                        color: Theme.surfaceLight
                        Text {
                            anchors.centerIn: parent
                            text: "#" + rowCard.rank
                            color: Theme.textPrimary
                            font.bold: true
                            font.pixelSize: 13
                            font.family: Theme.fontFamily
                        }
                    }

                    Column {
                        width: parent.width - 40 - 100 - Theme.spacingMedium * 2
                        anchors.verticalCenter: parent.verticalCenter
                        spacing: 3
                        Text {
                            text: rowCard.driverName
                            color: Theme.textPrimary
                            font.bold: true
                            font.pixelSize: Theme.fontBody
                            font.family: Theme.fontFamily
                        }
                        Text {
                            text: rowCard.bodyName + " · " + rowCard.tireName + " · " + rowCard.gliderName
                            color: Theme.textSecondary
                            font.pixelSize: Theme.fontSmall
                            font.family: Theme.fontFamily
                            elide: Text.ElideRight
                            width: parent.width
                        }
                    }

                    Column {
                        width: 100
                        anchors.verticalCenter: parent.verticalCenter
                        Text {
                            width: parent.width
                            horizontalAlignment: Text.AlignRight
                            text: "score " + rowCard.score.toFixed(2)
                            color: Theme.accentGold
                            font.bold: true
                            font.pixelSize: Theme.fontBody
                            font.family: Theme.fontFamily
                        }
                        Text {
                            width: parent.width
                            horizontalAlignment: Text.AlignRight
                            text: "dist " + rowCard.distance.toFixed(2)
                            color: Theme.textMuted
                            font.pixelSize: Theme.fontSmall
                            font.family: Theme.fontFamily
                        }
                    }
                }
            }
        }
    }
}
