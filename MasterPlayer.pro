TEMPLATE = app

QT += qml quick widgets multimedia concurrent

SOURCES += main.cpp \
    partdata.cpp \
    musicdata.cpp \
    musicdatas.cpp \
    skindata.cpp \
    viewer.cpp \
    metadata.cpp \
    audio3d.cpp \
    speaker.cpp \
    instrumental.cpp \
    listener.cpp

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)

HEADERS += \
    partdata.h \
    musicdata.h \
    musicdatas.h \
    skindata.h \
    viewer.h \
    metadata.h \
    audio3d.h \
    speaker.h \
    instrumental.h \
    listener.h

QMAKE_CXXFLAGS += -std=gnu++0x


unix|win32: LIBS += -L$$PWD/openal/libs/Win32/ -lOpenAL32

INCLUDEPATH += $$PWD/openal/include
DEPENDPATH += $$PWD/openal/include

win32:!win32-g++: PRE_TARGETDEPS += $$PWD/openal/libs/Win32/OpenAL32.lib
else:unix|win32-g++: PRE_TARGETDEPS += $$PWD/openal/libs/Win32/libOpenAL32.a




unix|win32: LIBS += -L$$PWD/taglib/ -ltaglib-1

INCLUDEPATH += $$PWD/taglib
DEPENDPATH += $$PWD/taglib
