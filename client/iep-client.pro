TEMPLATE = app
TARGET = iep-client

QT += core
QT += network
QT += gui

CONFIG += c++11

CONFIG += console
CONFIG -= app_bundle

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

SOURCES += \
    main.cpp \
    client.cpp

HEADERS += \
    client.h
