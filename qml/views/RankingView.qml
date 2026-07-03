import QtQuick
import QtQuick.Controls
import MarioKartBuildAnalyzer

Item {
    id: root
    property var sfx: null

    Column {
        anchors.fill: parent
        anchors.margins: Theme.spacingLarge
        spacing: Theme.spacingLarge

        SectionHeader {
            iconSource: "qrc:/assets/icons/icon_trophy.svg"
            title: "Ranking de builds"
            subtitle: "Las mejores combinaciones de todo el catalogo"
        }

        Row {
            spacing: Theme.spacingMedium
            Text {
                text: "Mostrar top " + slider.value.toFixed(0)
                color: Theme.textSecondary
                font.pixelSize: Theme.fontBody
                font.family: Theme.fontFamily
                anchors.verticalCenter: parent.verticalCenter
            }
            Slider {
                id: slider
                from: 1; to: 20; value: 10; stepSize: 1
                width: 220
                anchors.verticalCenter: parent.verticalCenter
            }
            PrimaryButton {
                text: "Calcular ranking"
                colors: Theme.gradientSpeed
                onClicked: {
                    appController.computeRanking(slider.value)
                    if (root.sfx) root.sfx.confirm()
                }
            }
        }

        Text {
            visible: appController.rankingModel.count === 0
            text: "Toca \"Calcular ranking\" para ver el Top de builds."
            color: Theme.textMuted
            font.family: Theme.fontFamily
        }

        ListView {
            width: parent.width
            height: parent.height - 170
            clip: true
            spacing: Theme.spacingSmall
            model: appController.rankingModel

            delegate: GlassCard {
                id: rowCard
                required property int index
                required property int rank
                required property string driverName
                required property string bodyName
                required property string tireName
                required property string gliderName
                required property double score
                required property double barRatio

                width: ListView.view.width
                height: 74

                Row {
                    anchors.fill: parent
                    spacing: Theme.spacingMedium

                    Rectangle {
                        width: 40; height: 40
                        radius: 20
                        anchors.verticalCenter: parent.verticalCenter
                        color: rowCard.rank <= 3 ? Theme.accentGold : Theme.surfaceLight
                        Text {
                            anchors.centerIn: parent
                            text: "#" + rowCard.rank
                            color: rowCard.rank <= 3 ? "#3a2a00" : Theme.textPrimary
                            font.bold: true
                            font.pixelSize: 13
                            font.family: Theme.fontFamily
                        }
                    }

                    Column {
                        width: parent.width - 40 - 90 - Theme.spacingMedium * 2
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
                        Rectangle {
                            width: parent.width
                            height: 6
                            radius: 3
                            color: Theme.surfaceLight
                            Rectangle {
                                height: parent.height
                                radius: 3
                                width: parent.width * rowCard.barRatio
                                color: Theme.accentGreen
                                Behavior on width { NumberAnimation { duration: Theme.animSlow; easing.type: Theme.easingType } }
                            }
                        }
                    }

                    Text {
                        width: 90
                        anchors.verticalCenter: parent.verticalCenter
                        horizontalAlignment: Text.AlignRight
                        text: rowCard.score.toFixed(2)
                        color: Theme.accentGold
                        font.bold: true
                        font.pixelSize: Theme.fontHeading
                        font.family: Theme.fontFamily
                    }
                }
            }
        }
    }
}
