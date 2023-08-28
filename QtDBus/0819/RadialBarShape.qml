import QtQuick 2.15
import QtQuick.Shapes 1.15

Item {
    id: control

    implicitWidth: 150
    implicitHeight: 150

    property real startAngle: 225
    property real spanAngle: 270
    property real minValue: 0
    property real maxValue: 100
    property real value: 0
    property string valueunit: ""
    property int dialWidth: 10
    property int penStyle: Qt.RoundCap

    QtObject {
        id: internals
        property real baseRadius: Math.min(control.width / 2, control.height / 2)
        property real radiusOffset: control.dialWidth / 2
        property real actualSpanAngle: control.spanAngle
    }

    Shape {
        id: gradientDial
        anchors.fill: parent

        ShapePath {
            strokeWidth: control.dialWidth
            capStyle: control.penStyle
            strokeGradient: progressGradient
            fillColor: "transparent"

            PathAngleArc {
                radiusX: internals.baseRadius - internals.radiusOffset
                radiusY: internals.baseRadius - internals.radiusOffset
                centerX: parent.width / 2
                centerY: parent.height / 2
                startAngle: control.startAngle - 90
                sweepAngle: control.spanAngle
            }
        }
    }

    Shape {
        id: progressShape
        anchors.fill: parent

        ShapePath {
            strokeWidth: control.dialWidth
            capStyle: control.penStyle
            strokeColor: "black"
            fillColor: "transparent"

            PathAngleArc {
                radiusX: internals.baseRadius - internals.radiusOffset
                radiusY: internals.baseRadius - internals.radiusOffset
                centerX: parent.width / 2
                centerY: parent.height / 2
                startAngle: control.startAngle - 90
                sweepAngle: (internals.actualSpanAngle / control.maxValue * control.value)
            }
        }
    }

    Gradient {
        id: progressGradient
        GradientStop {
           position: 0.000
           color: Qt.rgba(1, 0, 0, 1)
        }
        GradientStop {
           position: 0.167
           color: Qt.rgba(1, 1, 0, 1)
        }
        GradientStop {
           position: 0.333
           color: Qt.rgba(0, 1, 0, 1)
        }
        GradientStop {
           position: 0.500
           color: Qt.rgba(0, 1, 1, 1)
        }
        GradientStop {
           position: 0.667
           color: Qt.rgba(0, 0, 1, 1)
        }
        GradientStop {
           position: 0.833
           color: Qt.rgba(1, 0, 1, 1)
        }
        GradientStop {
           position: 1.000
           color: Qt.rgba(1, 0, 0, 1)
        }
    }

    Text {
        anchors.centerIn: parent
        text: control.value.toFixed(0) + control.valueunit
        font.pixelSize: 24
        color: "white"
    }
}
