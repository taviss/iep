TEMPLATE = app
TARGET = iep-server

QT = core network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

SOURCES += \
    main.cpp
