#-------------------------------------------------
#
# Project created by QtCreator 2016-03-30T18:15:04
#
#-------------------------------------------------

QT       += testlib

QT       -= gui

TARGET = tst_txtfileloadertest
CONFIG   += console testcase
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += tst_txtfileloadertest.cpp
DEFINES += SRCDIR=\\\"$$PWD/\\\"

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../../Core/release/ -lCore
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../../Core/debug/ -lCore
else:unix: LIBS += -L$$OUT_PWD/../../Core/ -lCore

INCLUDEPATH += $$PWD/../../Core
DEPENDPATH += $$PWD/../../Core
