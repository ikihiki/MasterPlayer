import QtQuick 2.4
import QtQuick.Controls 1.3
import QtQuick.Layouts 1.1
import QtMultimedia 5.4


Rectangle {  
    ListView {
        id: listView1
        x: 241
        y: 126
        width: 222
        height: 160
        orientation: ListView.Horizontal
        flickableDirection: Flickable.HorizontalFlick
        delegate: Item {
            x: 5
            width: 80
            height: 40
            MouseArea
            {
                anchors.fill: parent
                onClicked:
                {
                    modelData.selectMusic()
                    Nav.goPlayer()
                    console.log(audio.metaData.metaData.coverArtUrlSmall)
                }
            }

            Audio
            {
                id:audio
                source:modelData.Instrumental
            }

            Column {
                id: row1
                spacing: 10
                Image {
                    width: 40
                    height: 40
                    source: audio.metaData.coverArtImage
                }

                Text {
                    text: audio.metaData.title
                    font.bold: true
                }

            }
        }
        model: Data.Musics
    }
}

