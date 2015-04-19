import QtQuick 2.0
import QtMultimedia 5.0
import AudioSystem 1.0
import QtQuick.Controls 1.2

Rectangle {
    id: rectangle1
    width: 100
    height: 62

    signal play()

    Speaker
    {
        id:inst
        source: Data.SelectedMusic.Instrumental
        position: sliderHorizontal1.value
        onPositionChanged:
        {
            sliderHorizontal1.minimumValue=0;
            sliderHorizontal1.value=inst.position
        }
    }

    ListView
    {
        id:list
        anchors.fill:parent
        model: Data.SelectedMusic.Parts
        delegate: Item {
                width: 200
                height: 200
                property bool playing: false
                MouseArea
                {
                    anchors.fill: parent
                    onClicked:
                    {
                        if(playing)
                        {
                            image.source=modelData.OffImage;
                            speaker.isMute=true;
                            playing=false;
                        }else
                        {
                            image.source=modelData.OnImage;
                            inst.play();

                            speaker.play();
                            speaker.isMute=false;
                            playing=true;
                        }
                    }
                }

                Image
                {
                    id:image
                 anchors.fill:parent
                 source: modelData.OffImage
                }
                Speaker
                {
                    id:speaker
                    source:modelData.Vocal
                    position: inst.position+10
                    isPlaying: inst.isPlaying
                }
                Text {
                    id: a
                    text: speaker.position-inst.position
                }
        }



        Slider {
            id: sliderHorizontal1
            x: 8
            y: 32
            width: 608
            height: 17
            value: inst.position
            maximumValue: inst.duration

            Text {
                id: text2
                x: 73
                y: 17
                text: sliderHorizontal1.maximumValue
                font.pixelSize: 12
            }
        }

        Text {
            id: text1
            x: 0
            y: 55
            text: sliderHorizontal1.value
            font.pixelSize: 12
        }
    }

}

