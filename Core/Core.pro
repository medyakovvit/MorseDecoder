#-------------------------------------------------
#
# Project created by QtCreator 2016-03-29T20:00:50
#
#-------------------------------------------------

QT       -= gui

TARGET = Core
TEMPLATE = lib

DEFINES += CORE_LIBRARY

SOURCES += core.cpp \
    numbercoder.cpp \
    symbolcoder.cpp \
    englishcharcoder.cpp \
    abstracttranslator.cpp \
    engtomorsetranslator.cpp \
    morsetoenglishtranslator.cpp \
    morsecodenode.cpp \
    morsecodetree.cpp \
    txtfileloader.cpp \
    fileloader.cpp \
    translatorfactory.cpp \
    filewriter.cpp \
    txtfilewriter.cpp

HEADERS += core.h\
        core_global.h \
    numbercoder.h \
    symbolcoder.h \
    englishcharcoder.h \
    abstracttranslator.h \
    engtomorsetranslator.h \
    morsetoenglishtranslator.h \
    morsecodenode.h \
    morsecodetree.h \
    txtfileloader.h \
    fileloader.h \
    translatorfactory.h \
    filewriter.h \
    txtfilewriter.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}
