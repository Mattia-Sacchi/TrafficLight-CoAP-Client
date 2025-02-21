QT       += core network gui widgets coap


CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    mainwindow.cpp \
    timechooser.cpp

HEADERS += \
    Enums.h \
    LightWidget.h \
    TrafficLightWidget.h \
    mainwindow.h \
    timechooser.h

FORMS += \
    mainwindow.ui \
    timechooser.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
