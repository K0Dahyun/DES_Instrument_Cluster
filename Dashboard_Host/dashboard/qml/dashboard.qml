/****************************************************************************
**
** Copyright (C) 2016 The Qt Company Ltd.
** Contact: https://www.qt.io/licensing/
**
** This file is part of the examples of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:BSD$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see https://www.qt.io/terms-conditions. For further
** information use the contact form at https://www.qt.io/contact-us.
**
** BSD License Usage
** Alternatively, you may use this file under the terms of the BSD license
** as follows:
**
** "Redistribution and use in source and binary forms, with or without
** modification, are permitted provided that the following conditions are
** met:
**   * Redistributions of source code must retain the above copyright
**     notice, this list of conditions and the following disclaimer.
**   * Redistributions in binary form must reproduce the above copyright
**     notice, this list of conditions and the following disclaimer in
**     the documentation and/or other materials provided with the
**     distribution.
**   * Neither the name of The Qt Company Ltd nor the names of its
**     contributors may be used to endorse or promote products derived
**     from this software without specific prior written permission.
**
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE."
**
** $QT_END_LICENSE$
**
****************************************************************************/

import QtQuick 2.2
import QtQuick.Window 2.1
import QtQuick.Controls 1.4
import QtQuick.Controls.Styles 1.4
import QtQuick.Extras 1.4

Window {
    id: root
    visible: true
    width: 1280
    height: 400
    //visibility: Window.FullScreen
    color: "#161616"
    title: "INSTRUMENT CLUSTER"

    Image {
        id: background
        width: 1280
        height: 400
        source: "qrc:/images/images.jpg"
    }

    ValueSource {
        id: valueSource
    }

    // Dashboards are typically in a landscape orientation, so we need to ensure
    // our height is never greater than our width.
    Item {
        id: container
        width: root.width
        height: Math.min(root.width, root.height)
        anchors.centerIn: parent

        Row {
            id: gaugeRow
            spacing: container.width * 0.02
            anchors.centerIn: parent

            Item {
                width: height
                height: container.height * 0.25 - gaugeRow.spacing
                anchors.verticalCenter: parent.verticalCenter

                CircularGauge {
                    id: fuelGauge
                    value: valueSource.fuel
                    minimumValue: 0
                    maximumValue: 100
                    y: parent.height / 2 - height / 2 - container.height * 0.01
                    width: parent.width*1
                    height: parent.height *1

                    style: IconGaugeStyle {
                        icon: "qrc:/images/battery.png"
                        minWarningColor: Qt.rgba(0.5, 0, 0, 1)
                    }

                    Behavior on value {
                        NumberAnimation {
                        duration: 200
                        //easing.type: Easing.OutQuad
                        }
                    }
                }
            }

            CircularGauge {
                id: speedometers
                value: valueSource.kph
                anchors.verticalCenter: parent.verticalCenter
                maximumValue: 100
                width: height
                height: container.height * 0.5

                style: DashboardGaugeStyle {}

                Behavior on value {
                    NumberAnimation {
                    duration: 200
                    }
                }

            }

            CircularGauge {
                id: tachometer
                width: height
                height: container.height * 0.25 - gaugeRow.spacing
                value: valueSource.rpm
                maximumValue: 8
                anchors.verticalCenter: parent.verticalCenter

                style: TachometerStyle {}

                Behavior on value {
                    NumberAnimation {
                    duration: 200
                    }
                }
            }

        }

        Connections {
            target: car // This assumes you've set a "car" context property from C++.
            onCanFail: {
                timeoutText.visible = true // Show the message when the signal is received.
            }
            onCanRestored: {
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
}
