pragma Singleton
import QtQuick

// Tema visual centralizado ("Design Tokens"). Toda la UI consulta
// estos valores en vez de hardcodear colores, asi que retocar la
// paleta o la tipografia se hace en un solo lugar.
QtObject {
    // --- Paleta principal: inspirada en un circuito de carreras arcade ---
    readonly property color bgTop: "#1b1035"
    readonly property color bgBottom: "#0c0820"

    readonly property color surface: "#241a45"
    readonly property color surfaceLight: "#2f2258"
    readonly property color surfaceBorder: "#4a3a86"

    readonly property color accentRed: "#FF5F6D"
    readonly property color accentOrange: "#FFC371"
    readonly property color accentCyan: "#36D1DC"
    readonly property color accentBlue: "#5B86E5"
    readonly property color accentPurple: "#8E2DE2"
    readonly property color accentGreen: "#38ef7d"
    readonly property color accentGold: "#FFD200"

    readonly property color textPrimary: "#FFFFFF"
    readonly property color textSecondary: "#C6BEEA"
    readonly property color textMuted: "#8A80B8"

    readonly property color danger: "#FF4D6D"
    readonly property color success: "#38ef7d"

    // --- Gradientes reutilizables ---
    readonly property var gradientPrimary: [accentRed, accentOrange]
    readonly property var gradientSpeed: [accentCyan, accentBlue]
    readonly property var gradientPower: [accentPurple, accentBlue]
    readonly property var gradientGold: [accentGold, accentOrange]
    readonly property var gradientBg: [bgTop, bgBottom]

    // --- Tipografia ---
    readonly property string fontFamily: "Avenir Next, Century Gothic, Verdana, sans-serif"
    readonly property int fontHuge: 32
    readonly property int fontTitle: 22
    readonly property int fontHeading: 17
    readonly property int fontBody: 14
    readonly property int fontSmall: 12

    // --- Espaciado y forma ---
    readonly property int radiusSmall: 8
    readonly property int radiusMedium: 14
    readonly property int radiusLarge: 22
    readonly property int spacingTiny: 4
    readonly property int spacingSmall: 8
    readonly property int spacingMedium: 16
    readonly property int spacingLarge: 24
    readonly property int spacingHuge: 40

    // --- Animaciones ---
    readonly property int animFast: 140
    readonly property int animMedium: 320
    readonly property int animSlow: 620
    readonly property int easingType: Easing.OutCubic

    function statColor(ratio) {
        // De rojo (bajo) a verde (alto), pasando por dorado
        if (ratio < 0.5) return Qt.rgba(1, 0.37 + ratio * 0.5, 0.43, 1)
        return Qt.rgba(1 - (ratio - 0.5), 0.85, 0.45 + (ratio - 0.5) * 0.6, 1)
    }
}
