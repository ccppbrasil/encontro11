import QtQuick 2.0
import QtQuick.Controls 1.2
import QtQuick.Layouts 1.1
import QtGraphicalEffects 1.0


Rectangle {
    width: 660
    height: 600

    color: "black"

    Repeater {
        id: repeater
        model: 8

        Rectangle {
            id: rect

            visible: false
            color: "transparent"
            clip: true

            width: 285; height: 285
            x: parent.width / 2 - width / 2
            y: parent.height / 2 - height / 2

            Timer {
                id: timer
                interval: 500 * index
                running: true
                repeat: false
                onTriggered: {
                    rect.visible = true
                    animation.running = true
                }
            }

            Image {
                source: "qrc:/nebula.jpg"
                smooth: true
                x: -1 * (Math.random() * 285) >> 0
                y: -1 * (Math.random() * 285) >> 0
            }

            ParallelAnimation {
                id: animation
                running: false
                loops: Animation.Infinite

                SequentialAnimation {
                    NumberAnimation {
                        target: rect
                        property: "opacity"
                        from: .0; to: 1.0
                        duration: 3000
                    }

                    NumberAnimation {
                        target: rect
                        property: "opacity"
                        from: 1.0; to: .0
                        duration: 500
                    }
                }

                NumberAnimation {
                    target: rect
                    property: "scale"
                    from: 2.0; to: 4.0
                    duration: 4000
                }
            }
        }
    }

    ColumnLayout {
        anchors {
            fill: parent
            margins: 30
        }

        /**********************************************************/

        Button {
            objectName: "button"
            text: "C/C++ Brasil"
        }

        GridView {
            Layout.fillHeight: true
            Layout.fillWidth: true
            cellWidth: 150
            cellHeight: 150
            delegate: GridDelegate {}

            model: membersModel
        }

        /**********************************************************/
    }
}
