import QtQuick 2.7
import QtQuick.Window 2.2
import QtQuick.Controls 2.0
import QtQuick.Controls 1.2
import QtQuick.Layouts 1.1

Window {
    id: root
    visible: true
    width: 1280
    height: 400
    color: "#1d1d35"

    CarValue{
        id: carvalue
    }

    ColumnLayout{
        anchors.centerIn: parent
        spacing: 10
        RowLayout{
            Layout.fillWidth: true
            spacing: 20
            RadialBarShape{
                id: fuel
                value: carvalue.fuel
                valueunit: " fuel"
                maxValue: 280
            }
            RadialBarShape{
                id: speed
                value: carvalue.kph
                valueunit: " kph"
                maxValue: 280
                implicitWidth: 300
                implicitHeight: 300
            }
            RadialBarShape{
                id: rpm
                value: carvalue.rpm
                valueunit: " rpm"
                maxValue: 280
            }
        }

        RowLayout{
            Layout.fillWidth: true
            spacing: 20
            RadialBarShape{
                id: gear
                value: carvalue.gear
                valueunit: " gear"
                maxValue: 280
            }
            RadialBarShape{
                id: time
                value: carvalue.time
                valueunit: " time"
            }
        }
    }
}
