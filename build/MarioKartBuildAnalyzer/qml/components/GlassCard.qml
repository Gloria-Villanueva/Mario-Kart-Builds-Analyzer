import QtQuick
import QtQuick.Effects
import MarioKartBuildAnalyzer

// Tarjeta de superficie estandar de toda la app: esquinas redondeadas,
// borde sutil y sombra suave (MultiEffect) para dar profundidad tipo
// "glassmorphism" liviano, consistente con el resto del tema.
Rectangle {
    id: root
    default property alias content: contentItem.data
    property real cardOpacity: 1.0

    radius: Theme.radiusLarge
    color: Theme.surface
    border.color: Theme.surfaceBorder
    border.width: 1
    opacity: cardOpacity

    layer.enabled: true
    layer.effect: MultiEffect {
        shadowEnabled: true
        shadowColor: "#25113a"
        shadowBlur: 0.7
        shadowVerticalOffset: 6
        shadowOpacity: 0.55
    }

    Item {
        id: contentItem
        anchors.fill: parent
        anchors.margins: Theme.spacingMedium
    }
}
