QT += core
QT -= gui

CONFIG += c++11

TARGET = cmdtimeout
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    application.cpp

HEADERS += \
    application.h
