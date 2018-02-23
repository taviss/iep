TEMPLATE = app
TARGET = iep-server

QT = core network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

SOURCES += \
    main.cpp \
    pin.cpp \
    bcm2835_stub.cpp \
    outputpin.cpp \
    inputpin.cpp \
    pwm.cpp \
    button.cpp \
    serial.cpp \
    spi.cpp

HEADERS += \
    pin.h \
    outputpin.h \
    inputpin.h \
    bcm2835.h \
    pwm.h \
    button.h \
    serial.h \
    spi.h
