QT       += core gui network sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    OpeDB.cpp \
    main.cpp \
    mytcpserver.cpp \
    mytcpsocket.cpp \
    protocol.cpp \
    tcpserver.cpp

HEADERS += \
    OpeDB.h \
    mytcpserver.h \
    mytcpsocket.h \
    protocol.h \
    tcpserver.h

FORMS += \
    tcpserver.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    config.qrc
