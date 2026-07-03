import QtQuick
import QtQuick.Controls
import MarioKartBuildAnalyzer

Item {
    id: root

    property var tabs: [
        { label: "Pilotos", model: appController.driversModel, accent: Theme.accentRed },
        { label: "Vehiculos", model: appController.bodiesModel, accent: Theme.accentCyan },
        { label: "Llantas", model: appController.tiresModel, accent: Theme.accentPurple },
        { label: "Alas", model: appController.glidersModel, accent: Theme.accentGreen }
    ]
    property int tabIndex: 0

    Column {
        anchors.fill: parent
        anchors.margins: Theme.spacingLarge
        spacing: Theme.spacingLarge

        SectionHeader {
            iconSource: "qrc:/assets/icons/icon_logo.svg"
            title: "Catalogo de componentes"
            subtitle: appController.driversModel.count + " pilotos · " + appController.bodiesModel.count +
                      " vehiculos · " + appController.tiresModel.count + " llantas · " + appController.glidersModel.count + " alas"
        }

        Row {
            spacing: Theme.spacingSmall
            Repeater {
                model: root.tabs
                delegate: Rectangle {
                    id: tabBtn
                    required property int index
                    required property var modelData
                    width: 110; height: 40
                    radius: Theme.radiusMedium
                    color: root.tabIndex === index ? modelData.accent : Theme.surfaceLight
                    border.color: modelData.accent
                    border.width: 1

                    Behavior on color { ColorAnimation { duration: Theme.animFast } }

                    Text {
                        anchors.centerIn: parent
                        text: tabBtn.modelData.label
                        color: root.tabIndex === tabBtn.index ? "#1a1030" : Theme.textSecondary
                        font.bold: true
                        font.pixelSize: Theme.fontSmall
                        font.family: Theme.fontFamily
                    }
                    MouseArea {
                        anchors.fill: parent
                        cursorShape: Qt.PointingHandCursor
                        onClicked: root.tabIndex = tabBtn.index
                    }
                }
            }
        }

        GridView {
            id: grid
            width: parent.width
            height: parent.height - 150
            clip: true
            cellWidth: (width - 4) / Math.max(1, Math.floor(width / 190))
            cellHeight: 128
            model: root.tabs[root.tabIndex].model

            delegate: Item {
                id: cell
                required property int index
                required property string name
                required property string category
                required property double score
                required property double speedGround
                required property double acceleration
                width: grid.cellWidth - Theme.spacingSmall
                height: grid.cellHeight - Theme.spacingSmall

                GlassCard {
                    anchors.fill: parent

                    Column {
                        anchors.fill: parent
                        spacing: 6

                        Row {
                            spacing: Theme.spacingSmall
                            Rectangle {
                                width: 30; height: 30
                                radius: 15
                                gradient: Gradient {
                                    GradientStop { position: 0.0; color: Qt.hsla((cell.index * 0.09) % 1.0, 0.6, 0.55, 1) }
                                    GradientStop { position: 1.0; color: Qt.hsla((cell.index * 0.09 + 0.1) % 1.0, 0.6, 0.4, 1) }
                                }
                                Text {
                                    anchors.centerIn: parent
                                    text: cell.name.length > 0 ? cell.name.charAt(0).toUpperCase() : "?"
                                    color: "#fff"; font.bold: true; font.pixelSize: 13
                                    font.family: Theme.fontFamily
                                }
                            }
                            Column {
                                width: parent.width - 38
                                Text {
                                    text: cell.name
                                    color: Theme.textPrimary
                                    font.bold: true
                                    font.pixelSize: Theme.fontSmall
                                    font.family: Theme.fontFamily
                                    elide: Text.ElideRight
                                    width: parent.width
                                }
                                Text {
                                    visible: cell.category !== ""
                                    text: cell.category
                                    color: Theme.textMuted
                                    font.pixelSize: 10
                                    font.family: Theme.fontFamily
                                }
                            }
                        }

                        Rectangle { width: parent.width; height: 1; color: Theme.surfaceBorder }

                        Row {
                            spacing: 4
                            Text { text: "VEL"; color: Theme.textMuted; font.pixelSize: 9; font.family: Theme.fontFamily }
                            Text { text: cell.speedGround.toFixed(0); color: Theme.accentCyan; font.pixelSize: 9; font.bold: true; font.family: Theme.fontFamily }
                            Text { text: "  ACEL"; color: Theme.textMuted; font.pixelSize: 9; font.family: Theme.fontFamily }
                            Text { text: cell.acceleration.toFixed(0); color: Theme.accentOrange; font.pixelSize: 9; font.bold: true; font.family: Theme.fontFamily }
                        }

                        Rectangle {
                            width: parent.width; height: 8; radius: 4
                            color: Theme.surfaceLight
                            Rectangle {
                                height: parent.height; radius: 4
                                width: parent.width * Math.min(1.0, cell.score / 8.0)
                                color: Theme.accentGold
                            }
                        }
                        Text {
                            text: "score " + cell.score.toFixed(2)
                            color: Theme.textSecondary
                            font.pixelSize: 9
                            font.family: Theme.fontFamily
                        }
                    }
                }
            }
        }
    }
}
