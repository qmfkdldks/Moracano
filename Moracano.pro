#-------------------------------------------------
#
# Project created by QtCreator 2016-05-23T21:08:36
#
#-------------------------------------------------

QT       += core gui webkit webkitwidgets widgets

CONFIG += c++11

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Moracano
TEMPLATE = app

INCLUDEPATH += TextEditor GUI

SOURCES += main.cpp\
        mainwindow.cpp \
    moracanoengine.cpp \
    searchpart.cpp \
    data.cpp \
    sitepart.cpp \
    site.cpp \
    cutter.cpp \
    GUI/meaningselector.cpp \
    TextEditor/mrichtextedit.cpp \
    TextEditor/mtextedit.cpp \
    Lib/autosearchmanager.cpp \
    GUI/autosearchwidget.cpp \
    GUI/texteditor.cpp

HEADERS  += mainwindow.h \
    moracanoengine.h \
    searchpart.h \
    data.h \
    sitepart.h \
    site.h \
    cutter.h \
    GUI/meaningselector.h \
    TextEditor/mrichtextedit.h \
    TextEditor/mtextedit.h \
    Lib/autosearchmanager.h \
    GUI/autosearchwidget.h \
    GUI/texteditor.h

FORMS    += mainwindow.ui \
    TextEditor/mrichtextedit.ui \
    GUI/autosearchwidget.ui \
    GUI/texteditor.ui

SUBDIRS += \
    TextEditor/MRichTextEditor.pro
