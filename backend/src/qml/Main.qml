import QtQuick
import QtQuick.Controls

Window {
    width: 640
    height: 480
    visible: true
    title: "Solver"

    Rectangle {
        width: 200
        height: 200
        color: "red"

        Rectangle {
            x: 100
            y: 100
            width: 100
            height: 100
            color: "blue"

            Rectangle {
                width: 50
                height: 50
                color: "green"
            }
        }
    }

    // Column {
    //     id: column
    //     width: 125
    //     height: 70
    //     anchors.centerIn: parent

    //     TextField {
    //         id: textField
    //         placeholderText: "Enter some text"
    //     }

    //     Button {
    //         id: button
    //         text: "Click me"
    //         onClicked: {
    //             myPopup.open()
    //         }
    //     }
    // }

    // Popup {
    //     id: myPopup
    //     anchors.centerIn: parent
    //     width: 150
    //     height: 75
    //     closePolicy: "CloseOnEscape"

    //     Column {
    //         anchors.centerIn: parent
    //         spacing: 10
    //         Text {
    //             text: textField.text
    //         }

    //         Button {
    //             text: "Close"
    //             width: 100
    //             onClicked: {
    //                 myPopup.close()
    //             }
    //         }
    //     }
    // }
}
