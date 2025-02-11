QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    MostFrequent.cpp \
    alphabetindexdisplaywindow.cpp \
    alphabetindexinputwindow.cpp \
    capacityinputwindow.cpp \
    iteminputwindow.cpp \
    knapsackproblem.cpp \
    main.cpp \
    mainwindow.cpp \
    mostfrequentwindow.cpp \
    resultwindow.cpp \
    textdisplaywindow.cpp

HEADERS += \
    Dictionary.h \
    HashTable.h \
    MostFrequent.h \
    RBTree.h \
    alphabetindex.h \
    alphabetindexdisplaywindow.h \
    alphabetindexinputwindow.h \
    capacityinputwindow.h \
    iteminputwindow.h \
    knapsackproblem.h \
    mainwindow.h \
    mostfrequentwindow.h \
    resultwindow.h \
    textdisplaywindow.h

FORMS += \
    alphabetindexdisplaywindow.ui \
    alphabetindexinputwindow.ui \
    capacityinputwindow.ui \
    iteminputwindow.ui \
    mainwindow.ui \
    mostfrequentwindow.ui \
    resultwindow.ui \
    textdisplaywindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
