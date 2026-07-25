QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    abstractmap.cpp \
    bigtown.cpp \
    city.cpp \
    dialogaddcity.cpp \
    dijkstra.cpp \
    main.cpp \
    mainwindow.cpp \
    map.cpp \
    mapio.cpp \
    mapiofileinput.cpp \
    mapionrw.cpp \
    smalltown.cpp \
    street.cpp

HEADERS += \
    abstractmap.h \
    bigtown.h \
    city.h \
    dialogaddcity.h \
    dijkstra.h \
    mainwindow.h \
    map.h \
    mapio.h \
    mapiofileinput.h \
    mapionrw.h \
    smalltown.h \
    street.h

FORMS += \
    dialogaddcity.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

QMAKE_CXXFLAGS += -Wno-error=implicit-function-declaration
# Unterdrueckt eine harmlose Warnung aus Qt-eigenen Headern (qyieldcpu.h, __yield):
QMAKE_CXXFLAGS += -Wno-implicit-function-declaration

DISTFILES += \
    Doxyfile