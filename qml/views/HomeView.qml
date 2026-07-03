import QtQuick
import MarioKartBuildAnalyzer

Item {
    id: root
    signal navigate(int index)

    Flickable {
        anchors.fill: parent
        contentWidth: width
        contentHeight: col.implicitHeight + Theme.spacingLarge * 2
        clip: true

        Column {
            id: col
            width: parent.width - Theme.spacingLarge * 2
            x: Theme.spacingLarge
            y: Theme.spacingLarge
            spacing: Theme.spacingLarge

            Rectangle {
                width: parent.width
                height: 170
                radius: Theme.radiusLarge
                gradient: Gradient {
                    orientation: Gradient.Horizontal
                    GradientStop { position: 0.0; color: Theme.accentPurple }
                    GradientStop { position: 0.55; color: Theme.accentBlue }
                    GradientStop { position: 1.0; color: Theme.accentCyan }
                }

                Row {
                    anchors.fill: parent
                    anchors.margins: Theme.spacingLarge
                    spacing: Theme.spacingLarge

                    Column {
                        width: parent.width - 130
                        anchors.verticalCenter: parent.verticalCenter
                        spacing: Theme.spacingSmall
                        Text {
                            text: "MK8 BUILD ANALYZER"
                            color: "#ffffff"
                            font.pixelSize: Theme.fontHuge
                            font.bold: true
                            font.family: Theme.fontFamily
                        }
                        Text {
                            text: "Arma tu combinacion ideal de piloto, vehiculo, llantas y alas.\nCompara su rendimiento contra todo el catalogo."
                            color: "#f1eefc"
                            font.pixelSize: Theme.fontBody
                            font.family: Theme.fontFamily
                            wrapMode: Text.WordWrap
                            width: parent.width
                        }
                        PrimaryButton {
                            text: "Empezar a armar mi build"
                            outlined: true
                            colors: ["#ffffff", "#ffffff"]
                            onClicked: root.navigate(1)
                        }
                    }

                    Image {
                        source: "qrc:/assets/icons/icon_logo.svg"
                        width: 110; height: 110
                        anchors.verticalCenter: parent.verticalCenter
                        fillMode: Image.PreserveAspectFit
                        opacity: 0.9
                    }
                }
            }

            Text {
                text: "MENU PRINCIPAL"
                color: Theme.textMuted
                font.pixelSize: Theme.fontSmall
                font.bold: true
                font.family: Theme.fontFamily
            }

            Grid {
                id: menuGrid
                width: parent.width
                columns: width > 760 ? 3 : (width > 480 ? 2 : 1)
                columnSpacing: Theme.spacingLarge
                rowSpacing: Theme.spacingLarge

                Repeater {
                    model: [
                        { title: "Arma tu build", desc: "Selecciona componentes y calcula tu percentil de rendimiento.", icon: "qrc:/assets/icons/icon_kart.svg", nav: 1, colors: Theme.gradientPrimary },
                        { title: "Ranking top builds", desc: "Las mejores combinaciones posibles de todo el catalogo.", icon: "qrc:/assets/icons/icon_trophy.svg", nav: 2, colors: Theme.gradientGold },
                        { title: "Builds similares", desc: "Encuentra alternativas parecidas a tu build actual.", icon: "qrc:/assets/icons/icon_glider.svg", nav: 3, colors: Theme.gradientPower },
                        { title: "Estadisticas", desc: "Promedio / maximo / minimo de score por categoria.", icon: "qrc:/assets/icons/icon_tire.svg", nav: 4, colors: Theme.gradientSpeed },
                        { title: "Catalogo completo", desc: "Explora todos los pilotos, vehiculos, llantas y alas.", icon: "qrc:/assets/icons/icon_logo.svg", nav: 5, colors: [Theme.accentGreen, Theme.accentCyan] }
                    ]

                    delegate: GlassCard {
                        id: menuCard
                        required property var modelData
                        width: (menuGrid.width - Theme.spacingLarge * (menuGrid.columns - 1)) / menuGrid.columns
                        height: 150

                        Column {
                            anchors.fill: parent
                            spacing: Theme.spacingSmall

                            Rectangle {
                                width: 40; height: 40
                                radius: Theme.radiusSmall
                                gradient: Gradient {
                                    orientation: Gradient.Diagonal
                                    GradientStop { position: 0.0; color: menuCard.modelData.colors[0] }
                                    GradientStop { position: 1.0; color: menuCard.modelData.colors[1] }
                                }
                                Image {
                                    anchors.centerIn: parent
                                    source: menuCard.modelData.icon
                                    width: 24; height: 24
                                    fillMode: Image.PreserveAspectFit
                                }
                            }
                            Text {
                                text: menuCard.modelData.title
                                color: Theme.textPrimary
                                font.bold: true
                                font.pixelSize: Theme.fontHeading
                                font.family: Theme.fontFamily
                            }
                            Text {
                                text: menuCard.modelData.desc
                                color: Theme.textSecondary
                                font.pixelSize: Theme.fontSmall
                                font.family: Theme.fontFamily
                                wrapMode: Text.WordWrap
                                width: parent.width
                            }
                        }

                        MouseArea {
                            anchors.fill: parent
                            cursorShape: Qt.PointingHandCursor
                            onClicked: root.navigate(menuCard.modelData.nav)
                        }
                    }
                }
            }
        }
    }
}
