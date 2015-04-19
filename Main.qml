import QtQuick 2.0
import QtQuick.Controls 1.3

ApplicationWindow
{
    id: window
    visible: true
    height: 720
    width:1200
    Rectangle
    {
        anchors.fill: parent

        Loader
        {
            id:select
            visible: true
            anchors.fill: parent
            source: Skin.SelectSkin
        }

        Loader
        {
            id:player
            visible: false
            anchors.fill: parent
        }
    }

    function goPlayer()
    {
        select.visible=false
        player.source=Skin.PlayerSkin
        player.visible=true
    }

    function goSelect()
    {
        player.visible=false
        player.source=""
        select.visible=true
    }


}
