#-------------------------------------------------
#
# Project created by QtCreator 2013-04-04T23:11:38
#
#-------------------------------------------------

QT       += gui-private

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += plugin

TARGET = WildscVirtualKeyboard
TEMPLATE = lib

DEFINES += WILDSCVIRTUALKEYBOARD_LIBRARY

INSTALLS += target

HEADERS += \
    wildscplatforminputcontextplugin.h \
    wildscVKB_global.h \
    wildscInputcontext.h \
    wildscinputcontextprivate.h \
    wildsckeyeventdispatcher.h \
    inputpanel.h \
    clickedlabel.h

SOURCES += \
    wildscplatforminputcontextplugin.cpp \
    wildscinputcontextprivate.cpp \
    wildsckeyeventdispatcher.cpp \
    wildscInputcontext.cpp \
    inputpanel.cpp \
    clickedlabel.cpp

FORMS += \
    inputpanel.ui

RESOURCES += \
    skins.qrc
