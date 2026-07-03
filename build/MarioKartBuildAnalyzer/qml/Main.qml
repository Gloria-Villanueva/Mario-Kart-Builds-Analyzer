import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import MarioKartBuildAnalyzer

ApplicationWindow {
    id: window
    width: 1180
    height: 760
    minimumWidth: 900
    minimumHeight: 600
    visible: true
    title: "MK8 Build Analyzer"
    color: Theme.bgBottom

    SoundFx { id: sfx }

    property int currentSection: 0
    property var sectionTitles: ["Inicio", "Build", "Ranking", "Similares", "Estadisticas", "Catalogo"]

    Rectangle {
        anchors.fill: parent
        gradient: Gradient {
            orientation: Gradient.Vertical
            GradientStop { position: 0.0; color: Theme.bgTop }
            GradientStop { position: 1.0; color: Theme.bgBottom }
        }
    }

    // --- Pantalla de carga / error temprano ---
    Item {
        anchors.fill: parent
        visible: !appController.loaded
        z: 100

        Column {
            anchors.centerIn: parent
            spacing: Theme.spacingMedium
            Image {
                source: "qrc:/assets/icons/icon_logo.svg"
                width: 72; height: 72
                anchors.horizontalCenter: parent.horizontalCenter
                fillMode: Image.PreserveAspectFit

                RotationAnimation on rotation {
                    running: !appController.loaded && appController.errorMessage === ""
                    from: 0; to: 360
                    duration: 1400
                    loops: Animation.Infinite
                }
            }
            Text {
                text: appController.errorMessage !== "" ? "Error cargando el catalogo" : "Cargando catalogo..."
                color: Theme.textPrimary
                font.pixelSize: Theme.fontHeading
                font.family: Theme.fontFamily
                anchors.horizontalCenter: parent.horizontalCenter
            }
            Text {
                visible: appController.errorMessage !== ""
                text: appController.errorMessage
                color: Theme.danger
                font.pixelSize: Theme.fontSmall
                font.family: Theme.fontFamily
                anchors.horizontalCenter: parent.horizontalCenter
            }
        }
    }

    RowLayout {
        anchors.fill: parent
        spacing: 0
        visible: appController.loaded

        NavRail {
            id: nav
            Layout.fillHeight: true
            currentIndex: window.currentSection
            items: [
                { label: "Inicio", icon: "qrc:/assets/icons/icon_logo.svg" },
                { label: "Build", icon: "qrc:/assets/icons/icon_kart.svg" },
                { label: "Ranking", icon: "qrc:/assets/icons/icon_trophy.svg" },
                { label: "Similares", icon: "qrc:/assets/icons/icon_glider.svg" },
                { label: "Stats", icon: "qrc:/assets/icons/icon_tire.svg" },
                { label: "Catalogo", icon: "qrc:/assets/icons/icon_driver.svg" }
            ]
            onNavigate: (index) => {
                window.currentSection = index
                sfx.select()
            }
        }

        ColumnLayout {
            Layout.fillWidth: true
            Layout.fillHeight: true
            spacing: 0

            // --- Barra superior ---
            Rectangle {
                Layout.fillWidth: true
                height: 56
                color: Theme.surface
                border.color: Theme.surfaceBorder
                border.width: 1

                Text {
                    anchors.left: parent.left
                    anchors.leftMargin: Theme.spacingLarge
                    anchors.verticalCenter: parent.verticalCenter
                    text: window.sectionTitles[window.currentSection]
                    color: Theme.textPrimary
                    font.pixelSize: Theme.fontHeading
                    font.bold: true
                    font.family: Theme.fontFamily
                }

                Text {
                    anchors.right: parent.right
                    anchors.rightMargin: Theme.spacingLarge
                    anchors.verticalCenter: parent.verticalCenter
                    text: appController.currentBuild.ready
                        ? ("Score actual: " + appController.currentBuild.performanceScore.toFixed(2))
                        : ""
                    color: Theme.accentGold
                    font.bold: true
                    font.pixelSize: Theme.fontBody
                    font.family: Theme.fontFamily
                }
            }

            // --- Contenido con transicion suave entre secciones ---
            StackLayout {
                id: stack
                Layout.fillWidth: true
                Layout.fillHeight: true
                currentIndex: window.currentSection

                HomeView {
                    onNavigate: (index) => { window.currentSection = index; sfx.select() }
                }
                BuildView { sfx: sfx }
                RankingView { sfx: sfx }
                SimilarView { sfx: sfx }
                StatsView { sfx: sfx }
                CatalogView { }
            }
        }
    }

    // --- Toast de error (excepciones del QueryEngine) ---
    Rectangle {
        id: toast
        visible: opacity > 0
        opacity: 0
        width: toastText.implicitWidth + Theme.spacingLarge * 2
        height: 46
        radius: Theme.radiusMedium
        color: Theme.danger
        anchors.bottom: parent.bottom
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.bottomMargin: Theme.spacingLarge
        z: 200

        Behavior on opacity { NumberAnimation { duration: Theme.animMedium } }

        Text {
            id: toastText
            anchors.centerIn: parent
            color: "#ffffff"
            font.bold: true
            font.family: Theme.fontFamily
            font.pixelSize: Theme.fontBody
        }

        Timer {
            id: hideTimer
            interval: 3200
            onTriggered: toast.opacity = 0
        }
    }

    Connections {
        target: appController
        function onErrorChanged() {
            if (appController.errorMessage === "") return
            toastText.text = appController.errorMessage
            toast.opacity = 1
            sfx.error()
            hideTimer.restart()
        }
    }
}
