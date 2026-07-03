import QtQuick
import QtMultimedia

// Centraliza los efectos de sonido de la interfaz. Los tonos son
// sintetizados y originales (no son audio de ningun juego), pensados
// como feedback discreto de UI: seleccionar, confirmar, volver, error.
QtObject {
    id: root
    property real volume: 0.5
    property bool muted: false

    property SoundEffect _select: SoundEffect {
        source: "qrc:/assets/sounds/select.wav"
        volume: root.muted ? 0 : root.volume
    }
    property SoundEffect _confirm: SoundEffect {
        source: "qrc:/assets/sounds/confirm.wav"
        volume: root.muted ? 0 : root.volume
    }
    property SoundEffect _back: SoundEffect {
        source: "qrc:/assets/sounds/back.wav"
        volume: root.muted ? 0 : root.volume
    }
    property SoundEffect _error: SoundEffect {
        source: "qrc:/assets/sounds/error.wav"
        volume: root.muted ? 0 : root.volume
    }

    function select() { _select.play() }
    function confirm() { _confirm.play() }
    function back() { _back.play() }
    function error() { _error.play() }
}
