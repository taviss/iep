TEMPLATE = app
TARGET = iep-server

QT = core network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

SOURCES += \
    main.cpp \
    pin.cpp \
    bcm2835_stub.cpp \
    outputpin.cpp \
    inputpin.cpp

HEADERS += \
    pin.h \
    outputpin.h \
    inputpin.h \
    bcm2835.h
