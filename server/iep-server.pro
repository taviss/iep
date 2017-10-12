TEMPLATE = app
TARGET = iep-server

QT += core
QT += network
QT -= gui

CONFIG += c++11

CONFIG += console
CONFIG -= app_bundle

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

SOURCES += \
    main.cpp \
    server.cpp \
    thread.cpp

HEADERS += \
    server.h \
    thread.h
