import QtQuick 1.1
import "../../Controls"

Panel
{
    signal exitClicked()

    property Panel configPanel
    property Panel workerPanel
    property Panel playerPanel

    id: mainPanel
    title: qsTr("Main Menu")
    delegate: MultiDelegate { }
    model:
        [
          ModelObject { text: qsTr("Start Work"); onNoArgModelSignal: stack.addPanel(workerPanel);},
        ModelObject { text: qsTr("Config"); onNoArgModelSignal: stack.addPanel(configPanel); },
        ModelObject { text: qsTr("Play"); onNoArgModelSignal: stack.addPanel(playerPanel);}
//        ModelObject { text: qsTr("Record"); onNoArgModelSignal: stack.addPanel(recordPanel);}
    ]

    PushButton
    {
        id: btnExit
        buttonText: qsTr("Quit Application")
        buttonDefaultIcon: "../../icons/Menu-Button-Normal.png"
        buttonActiveIcon: "../../icons/Menu-Button-Pressed.png"
        width: 150
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.bottom: parent.bottom
        anchors.margins: 10
        onItemClicked:
        {
            mainPanel.exitClicked()
        }
    }
}
