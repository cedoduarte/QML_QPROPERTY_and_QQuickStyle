import QtQuick 2.9
import QtQuick.Controls 2.2
import QtQuick.Layouts 1.3

ApplicationWindow {
    id: root
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    ListView {
        anchors.fill: parent
        model: people
        delegate: RowLayout {
            spacing: 20
            width: parent.width
            height: inc_age_button.height
            Text {
                text: name
            }
            Text {
                text: age
            }
            Button {
                id: inc_age_button
                text: 'Age + 1'
                onClicked: {
                    age = age + 1;
                }
            }
            Button {
                id: dec_age_button
                text: 'Age - 1'
                onClicked: {
                    age = age - 1;
                }
            }
            TextField {
                id: name_textfield
                width: root.width / 3
                placeholderText: 'Enter name'
                Button {
                    text: 'OK'
                    width: parent.width / 5
                    anchors {
                        right: parent.right
                        top: parent.top
                        bottom: parent.bottom
                    }
                    onClicked: {
                        name = name_textfield.text;
                    }
                }
            }
        }
    }
}
