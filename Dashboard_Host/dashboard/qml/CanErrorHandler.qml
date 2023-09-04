import QtQuick 2.2

Item {

    Connections {
        target: car // This assumes you've set a "car" context property from C++.
        onCandisconnected: {
            timeoutText.visible = true // Show the message when the signal is received.
        }
        onCanConnected: {
            timeoutText.visible = false
        }
        onDbusdisconnected: {
            timeoutText.visible = false
        }
    }

    Text {
        id: timeoutText
        anchors.centerIn: parent
        text: "CAN Signal Timeout"
        color: "white"
        visible: false // Initially, the text is hidden.
    }
}
