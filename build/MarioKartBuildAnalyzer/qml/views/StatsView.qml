import QtQuick
import QtQuick.Controls
import MarioKartBuildAnalyzer

Item {
    id: root
    property var sfx: null

    property string filterType: "driver_size"
    property string filterValue: appController.driverSizes.length > 0 ? appController.driverSizes[0] : ""
    property string operation: "promedio"
    property real result: 0
    property bool hasResult: false

    Column {
        anchors.fill: parent
        anchors.margins: Theme.spacingLarge
        spacing: Theme.spacingLarge

        SectionHeader {
            iconSource: "qrc:/assets/icons/icon_tire.svg"
            title: "Estadisticas por categoria"
            subtitle: "Promedio / maximo / minimo de score, filtrado"
        }

        GlassCard {
            width: parent.width
            height: content.implicitHeight + Theme.spacingMedium * 2

            Column {
                id: content
                anchors.fill: parent
                spacing: Theme.spacingLarge

                Column {
                    spacing: Theme.spacingSmall
                    width: parent.width
                    Text { text: "Filtrar por"; color: Theme.textMuted; font.pixelSize: Theme.fontSmall; font.family: Theme.fontFamily }
                    Row {
                        spacing: Theme.spacingSmall
                        PrimaryButton {
                            text: "Tamano de piloto"
                            outlined: root.filterType !== "driver_size"
                            colors: Theme.gradientPrimary
                            onClicked: {
                                root.filterType = "driver_size"
                                root.filterValue = appController.driverSizes.length > 0 ? appController.driverSizes[0] : ""
                                root.hasResult = false
                            }
                        }
                        PrimaryButton {
                            text: "Tipo de vehiculo"
                            outlined: root.filterType !== "body_type"
                            colors: Theme.gradientSpeed
                            onClicked: {
                                root.filterType = "body_type"
                                root.filterValue = appController.bodyTypes.length > 0 ? appController.bodyTypes[0] : ""
                                root.hasResult = false
                            }
                        }
                    }
                }

                Column {
                    spacing: Theme.spacingSmall
                    width: parent.width
                    Text { text: "Valor"; color: Theme.textMuted; font.pixelSize: Theme.fontSmall; font.family: Theme.fontFamily }
                    Flow {
                        width: parent.width
                        spacing: Theme.spacingSmall
                        Repeater {
                            model: root.filterType === "driver_size" ? appController.driverSizes : appController.bodyTypes
                            delegate: PrimaryButton {
                                required property string modelData
                                text: modelData
                                outlined: root.filterValue !== modelData
                                colors: Theme.gradientPower
                                onClicked: { root.filterValue = modelData; root.hasResult = false }
                            }
                        }
                    }
                }

                Column {
                    spacing: Theme.spacingSmall
                    width: parent.width
                    Text { text: "Operacion"; color: Theme.textMuted; font.pixelSize: Theme.fontSmall; font.family: Theme.fontFamily }
                    Row {
                        spacing: Theme.spacingSmall
                        PrimaryButton { text: "Promedio"; outlined: root.operation !== "promedio"; colors: Theme.gradientGold
                            onClicked: { root.operation = "promedio"; root.hasResult = false } }
                        PrimaryButton { text: "Maximo"; outlined: root.operation !== "maximo"; colors: Theme.gradientGold
                            onClicked: { root.operation = "maximo"; root.hasResult = false } }
                        PrimaryButton { text: "Minimo"; outlined: root.operation !== "minimo"; colors: Theme.gradientGold
                            onClicked: { root.operation = "minimo"; root.hasResult = false } }
                    }
                }

                PrimaryButton {
                    text: "Calcular"
                    colors: Theme.gradientPrimary
                    onClicked: {
                        root.result = appController.computeAggregation(root.filterType, root.filterValue, root.operation)
                        root.hasResult = true
                        if (root.sfx) root.sfx.confirm()
                    }
                }
            }
        }

        GlassCard {
            visible: root.hasResult
            width: parent.width
            height: 120
            Column {
                anchors.centerIn: parent
                spacing: Theme.spacingSmall
                Text {
                    anchors.horizontalCenter: parent.horizontalCenter
                    text: root.operation + " de score · " + root.filterType + " = \"" + root.filterValue + "\""
                    color: Theme.textSecondary
                    font.pixelSize: Theme.fontSmall
                    font.family: Theme.fontFamily
                }
                Text {
                    anchors.horizontalCenter: parent.horizontalCenter
                    text: root.result.toFixed(2)
                    color: Theme.accentGold
                    font.pixelSize: Theme.fontHuge
                    font.bold: true
                    font.family: Theme.fontFamily
                }
            }
        }
    }
}
