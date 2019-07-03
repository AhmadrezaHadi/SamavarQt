#-------------------------------------------------
#
# Project created by QtCreator 2019-06-28T15:15:30
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Samavar
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        MyDate.cpp \
        MyTime.cpp \
        Person.cpp \
        Match.cpp \
        Team.cpp \
        Tournament.cpp \
        Sport.cpp \
        BBVB.cpp \
        PingPong.cpp \
        Wrestling.cpp \
        StoreAndRestore.cpp \
        mainwindow.cpp \
        main.cpp \
        login.cpp \
        teamlogin.cpp \
    smtp.cpp \
    editmembers.cpp \
    editperson.cpp \
    allteamsdialog.cpp \
    teamsdetaildialog.cpp \
    adminspanel.cpp \
    adminteamspaneldialog.cpp \
    addnewteamdiag.cpp \
    addpersontoteamdiag.cpp \
    encrypt.cpp

HEADERS += \
        MyDate.h \
        MyTime.h \
        Person.h \
        Match.h \
        Sport.h \
        Team.h \
        Tournament.h \
        shit.h \
        BBVB.h \
        PingPong.h \
        Wrestling.h \
        access.h \
        StoreAndRestore.h \
        mainwindow.h \
        login.h \
        teamlogin.h \
    access2.h \
    smtp.h \
    editmembers.h \
    editperson.h \
    allteamsdialog.h \
    teamsdetaildialog.h \
    adminspanel.h \
    adminteamspaneldialog.h \
    addnewteamdiag.h \
    addpersontoteamdiag.h \
    encrypt.h

FORMS += \
        mainwindow.ui \
    login.ui \
    teamlogin.ui \
    editperson.ui \
    adminspanel.ui \
    addnewteamdiag.ui \
    addpersontoteamdiag.ui

DISTFILES += \
    ReadME.pdf \
    Samavar.pro.user

SUBDIRS += \
    Samavar.pro
