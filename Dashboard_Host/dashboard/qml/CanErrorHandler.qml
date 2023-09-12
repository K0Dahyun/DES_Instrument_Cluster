import QtQuick 2.2

Item {
    id: carStatus

    property var car: null

    Connections {
        target: carStatus.car // This assumes you've set a "car" context property from C++.
        onCandisconnected: {
            cantimeoutText.visible = true
            speedtimeoutText.visible = false
            rpmtimeoutText.visible = false
            batterytimeoutText.visible = false
        }
        onCanconnected: {
            cantimeoutText.visible = false
        }
        onSpeeddisconnected: {
            speedtimeoutText.visible = true
        }
        onSpeedChanged:{
            speedtimeoutText.visible = false
        }
        onRpmdisconnected: {
            rpmtimeoutText.visible = true
        }
        onRpmChanged: {
            rpmtimeoutText.visible = false
        }
        onBatterydisconnected: {
            batterytimeoutText.visible = true
        }
        onBatteryChanged: {
            batterytimeoutText.visible = false
        }
    }

    Text {
        id: cantimeoutText
        anchors.top: parent.top
        anchors.horizontalCenter: parent.horizontalCenter
        text: "CAN"
        color: "white"
        visible: false // Initially, the text is hidden.
        anchors.topMargin: 50
    }


    Text {
        id: speedtimeoutText
        x:600
        y:200
        anchors.top: cantimeoutText.bottom
        anchors.horizontalCenter: parent.horizontalCenter
        text: "Speed"
        color: "white"
        visible: false // Initially, the text is hidden.
        anchors.margins: 5 // Adjust this value as needed for spacing
    }

    Text {
        id: rpmtimeoutText
        anchors.top: speedtimeoutText.bottom
        anchors.horizontalCenter: parent.horizontalCenter
        text: "RPM"
        color: "white"
        visible: false // Initially, the text is hidden.
        anchors.margins: 5 // Adjust this value as needed for spacing
    }

    Text {
        id: batterytimeoutText
        anchors.top: rpmtimeoutText.bottom
        anchors.horizontalCenter: parent.horizontalCenter
        text: "Battery"
        color: "white"
        visible: false // Initially, the text is hidden.
        anchors.margins: 5 // Adjust this value as needed for spacing
    }
}
