import QtQuick
import QtQuick.Controls
import MarioKartBuildAnalyzer

Item {
    id: root
    property var sfx: null

    property var build: appController.currentBuild

    Flickable {
        anchors.fill: parent
        contentWidth: width
        contentHeight: mainColumn.implicitHeight + Theme.spacingLarge * 2
        clip: true

        Column {
            id: mainColumn
            width: parent.width - Theme.spacingLarge * 2
            x: Theme.spacingLarge
            y: Theme.spacingLarge
            spacing: Theme.spacingLarge

            SectionHeader {
                iconSource: "qrc:/assets/icons/icon_kart.svg"
                title: "Arma tu build"
                subtitle: "Elige piloto, vehiculo, llantas y alas"
            }

            GlassCard {
                width: parent.width
                height: pickersCol.implicitHeight + Theme.spacingMedium * 2

                Column {
                    id: pickersCol
                    width: parent.width
                    spacing: Theme.spacingMedium

                    ComponentPicker {
                        title: "PILOTO"
                        model: appController.driversModel
                        accent: Theme.accentRed
                        currentIndex: appController.selectedDriverIndex
                        width: parent.width
                        onPicked: (index) => {
                            appController.selectDriver(index)
                            if (root.sfx) root.sfx.select()
                        }
                    }
                    ComponentPicker {
                        title: "VEHICULO"
                        model: appController.bodiesModel
                        accent: Theme.accentCyan
                        currentIndex: appController.selectedBodyIndex
                        width: parent.width
                        onPicked: (index) => {
                            appController.selectBody(index)
                            if (root.sfx) root.sfx.select()
                        }
                    }
                    ComponentPicker {
                        title: "LLANTAS"
                        model: appController.tiresModel
                        accent: Theme.accentPurple
                        currentIndex: appController.selectedTireIndex
                        width: parent.width
                        onPicked: (index) => {
                            appController.selectTire(index)
                            if (root.sfx) root.sfx.select()
                        }
                    }
                    ComponentPicker {
                        title: "ALAS"
                        model: appController.glidersModel
                        accent: Theme.accentGreen
                        currentIndex: appController.selectedGliderIndex
                        width: parent.width
                        onPicked: (index) => {
                            appController.selectGlider(index)
                            if (root.sfx) root.sfx.select()
                        }
                    }
                }
            }

            Row {
                id: statsRow
                width: parent.width
                spacing: Theme.spacingLarge

                // --- Resumen de la build actual ---
                GlassCard {
                    width: (parent.width - Theme.spacingLarge) * 0.42
                    height: statsCard.height

                    Column {
                        anchors.fill: parent
                        spacing: Theme.spacingSmall

                        Text {
                            text: "TU BUILD"
                            color: Theme.textMuted
                            font.pixelSize: Theme.fontSmall
                            font.bold: true
                            font.family: Theme.fontFamily
                        }
                        Text {
                            text: root.build.ready ? root.build.driverName : "-"
                            color: Theme.textPrimary
                            font.pixelSize: Theme.fontHeading
                            font.bold: true
                            font.family: Theme.fontFamily
                        }
                        Text {
                            text: root.build.ready
                                  ? (root.build.bodyName + " · " + root.build.tireName + " · " + root.build.gliderName)
                                  : ""
                            color: Theme.textSecondary
                            font.pixelSize: Theme.fontSmall
                            font.family: Theme.fontFamily
                            width: parent.width
                            wrapMode: Text.WordWrap
                        }

                        Item { height: Theme.spacingSmall; width: 1 }

                        Text {
                            text: "PERFORMANCE SCORE"
                            color: Theme.textMuted
                            font.pixelSize: Theme.fontSmall
                            font.family: Theme.fontFamily
                        }
                        Text {
                            text: root.build.performanceScore.toFixed(2)
                            color: Theme.accentGold
                            font.pixelSize: Theme.fontHuge
                            font.bold: true
                            font.family: Theme.fontFamily
                        }

                        PrimaryButton {
                            text: "Calcular percentil"
                            colors: Theme.gradientGold
                            iconSource: "qrc:/assets/icons/icon_trophy.svg"
                            onClicked: {
                                appController.calculatePercentile()
                                if (root.sfx) root.sfx.confirm()
                            }
                        }

                        Text {
                            visible: appController.percentileReady
                            text: "★ Supera al " + appController.lastPercentile.toFixed(1) + "% de las combinaciones"
                            color: Theme.accentGreen
                            font.pixelSize: Theme.fontSmall
                            font.bold: true
                            font.family: Theme.fontFamily
                            width: parent.width
                            wrapMode: Text.WordWrap
                        }
                    }
                }

                // --- Barras de estadisticas ---
                GlassCard {
                    id: statsCard
                    width: (parent.width - Theme.spacingLarge) * 0.58
                    height: statsCol.implicitHeight + Theme.spacingMedium * 2

                    Column {
                        id: statsCol
                        anchors.fill: parent
                        spacing: Theme.spacingTiny

                        Text {
                            text: "ESTADISTICAS"
                            color: Theme.textMuted
                            font.pixelSize: Theme.fontSmall
                            font.bold: true
                            font.family: Theme.fontFamily
                        }

                        StatBar { label: "Vel. Tierra"; value: root.build.speedGround; ratio: root.build.normSpeedGround; barColor: Theme.accentCyan; width: parent.width }
                        StatBar { label: "Vel. Agua"; value: root.build.speedWater; ratio: root.build.normSpeedWater; barColor: Theme.accentCyan; width: parent.width }
                        StatBar { label: "Vel. Aire"; value: root.build.speedAir; ratio: root.build.normSpeedAir; barColor: Theme.accentCyan; width: parent.width }
                        StatBar { label: "Vel. Anti-G"; value: root.build.speedAntiG; ratio: root.build.normSpeedAntiG; barColor: Theme.accentCyan; width: parent.width }
                        StatBar { label: "Aceleracion"; value: root.build.acceleration; ratio: root.build.normAcceleration; barColor: Theme.accentOrange; width: parent.width }
                        StatBar { label: "Peso"; value: root.build.weight; ratio: root.build.normWeight; barColor: Theme.accentOrange; width: parent.width }
                        StatBar { label: "Manejo Tierra"; value: root.build.handlingGround; ratio: root.build.normHandlingGround; barColor: Theme.accentPurple; width: parent.width }
                        StatBar { label: "Manejo Agua"; value: root.build.handlingWater; ratio: root.build.normHandlingWater; barColor: Theme.accentPurple; width: parent.width }
                        StatBar { label: "Manejo Aire"; value: root.build.handlingAir; ratio: root.build.normHandlingAir; barColor: Theme.accentPurple; width: parent.width }
                        StatBar { label: "Manejo Anti-G"; value: root.build.handlingAntiG; ratio: root.build.normHandlingAntiG; barColor: Theme.accentPurple; width: parent.width }
                        StatBar { label: "Agarre"; value: root.build.traction; ratio: root.build.normTraction; barColor: Theme.accentGreen; width: parent.width }
                    }
                }
            }
        }
    }
}
