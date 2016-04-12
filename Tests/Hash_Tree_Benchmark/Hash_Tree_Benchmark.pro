#-------------------------------------------------
#
# Project created by QtCreator 2016-04-05T20:26:02
#
#-------------------------------------------------

QT       += testlib

QT       -= gui

TARGET = tst_hash_tree_benchmarktest
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += tst_hash_tree_benchmarktest.cpp
DEFINES += SRCDIR=\\\"$$PWD/\\\"

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../../Core/release/ -lCore
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../../Core/debug/ -lCore
else:unix: LIBS += -L$$OUT_PWD/../../Core/ -lCore

INCLUDEPATH += $$PWD/../../Core
DEPENDPATH += $$PWD/../../Core
