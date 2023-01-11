QT -= gui
QT += widgets
QT += xml
QT += network

CONFIG += c++17 console
CONFIG -= app_bundle

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        aboutview.cpp \
        box.cpp \
        container.cpp \
        containercaretaker.cpp \
        containerfactory.cpp \
        containerlist.cpp \
        containermemento.cpp \
        cylinder.cpp \
        helpview.cpp \
        main.cpp \
        mainclient.cpp \
        mainwidget.cpp \
        pallet.cpp \
        palletlist.cpp \
        tcpconnection.cpp \
        xmlwriter.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    aboutview.h \
    box.h \
    container.h \
    containercaretaker.h \
    containerfactory.h \
    containerlist.h \
    containermemento.h \
    cylinder.h \
    helpview.h \
    mainclient.h \
    mainwidget.h \
    pallet.h \
    palletlist.h \
    tcpconnection.h \
    xmlwriter.h

RESOURCES += \
    Resources.qrc
