import QtQuick 2.0
import QtMultimedia 5.0
import QtQuick.Controls 1.2

Rectangle {
    id: rectangle1
    width: 500
    height: 502

    ListView
    {
        id:list
        anchors.fill:parent
        model: Data.SelectedMusic.parts
        delegate: Item {
                width: 200
                height: 200
                MouseArea
                {
                    anchors.fill: parent
                    onClicked:
                    {
                        if(!modelData.isMute)
                        {
                            image.source=modelData.offImage;
                            modelData.isMute=true;
                        }else
                        {
                            image.source=modelData.onImage;
                            modelData.isMute=false;
                        }
                    }
                }

                Image
                {
                    id:image
                 anchors.fill:parent
                 source: modelData.offImage
                }
        }



        Slider {
            id: sliderHorizontal1
            x: 8
            y: 32
            width: 608
            height: 17
            maximumValue: Data.SelectedMusic.duration
            minimumValue: 0
            value: Data.SelectedMusic.position
            onValueChanged:
            {
                Data.SelectedMusic.position = value;
            }
        }

        TextInput {
            id: text1
            x: 135
            y: 482
            width: 15
            height: 12
            text: Data.SelectedMusic.position
            font.pixelSize: 12
        }

        Button {
            id: button1
            x: 75
            y: 8
            text: qsTr("Play")
            onClicked:
            {
                Data.SelectedMusic.play();
            }
        }

    }

}

