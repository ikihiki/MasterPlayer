#include <QApplication>
#include <QUrl>
#include"viewer.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    Viewer *view = new Viewer(QUrl::fromLocalFile("C:/test"),QUrl(QStringLiteral("qrc:/MusicSelectTmp.qml")));
    view->Engine()->rootContext()->setContextProperty("Nav",view);
    view->Start();

    return app.exec();
}
