TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    line.cpp \
    page.cpp \
    tmp.cpp

HEADERS += \
    line.h \
    page.h

QMAKE_CXXFLAGS += -fno-elide-constructors #不省略构造函数
#QMAKE_CXXFLAGS += -std=c++03
