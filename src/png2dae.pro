TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    heightmap.cpp \
    libtrix.cpp \
    stb_image.cpp \
    png2stl.cpp

HEADERS += \
    heightmap.h \
    stb_image.h \
    libtrix.h \
    png2stl.h

