TEMPLATE = lib
TARGET = MassDelivery
QT += declarative xml webkit core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets webkitwidgets

CONFIG += qt plugin c++11
QMAKE_CXXFLAGS += -std=c++11

TARGET = $$qtLibraryTarget($$TARGET)
uri = org.huggle.extension.qt

# Input
SOURCES += \
    massdelivery.cpp \
    deliveryform.cpp

HEADERS += \
    massdelivery.h \
    deliveryform.h


FORMS += \
    deliveryform.ui

INCLUDEPATH += $$PWD/../../../

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/ -lcore
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/ -lcored

INCLUDEPATH += $$PWD/
DEPENDPATH += $$PWD/
