import QtQuick 2.0
import QtQuick.Controls 1.2
import QtQuick.Layouts 1.1
import QtGraphicalEffects 1.0

Item {
    width: 120; height: 120

    Rectangle {
        color: "#eee"
        width: parent.width
        height: parent.height

        Image {
            id: image
            cache: true
            asynchronous: true
            anchors.fill: parent
            smooth: true
            source: avatar
            visible: false
            fillMode: Image.PreserveAspectFit
        }

        OpacityMask {
            id: opacityMask
            scale: 0
            anchors.fill: image
            source: image
            //maskSource: mask

            states: State {
                name: "loaded"; when: image.status == Image.Ready
                PropertyChanges {
                    target: opacityMask
                    scale: 1
                }
            }

            transitions: Transition {
                NumberAnimation {
                    properties: "scale"
                    easing.type: Easing.Linear
                    duration: 500
                }
            }
        }

        Text {
            text: "@" + name
            color: "#ffffff"
            font.bold: true
            font.pixelSize: 16

            anchors {
                horizontalCenter: parent.horizontalCenter
                top: image.bottom
                margins: 5
            }
        }

        Image {
            source: "qrc:/busy.png"
            cache: true
            anchors.centerIn: parent
            visible: image.status != Image.Ready

            NumberAnimation on rotation {
                duration: 1200
                from: 0; to: 360
                loops: Animation.Infinite
            }
        }
    }
}
