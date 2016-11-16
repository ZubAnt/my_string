TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt
QMAKE_CFLAGS += -std=C11

SOURCES += main.cpp \
    lib/my_string.cpp \
    lib/test_my_string.cpp


HEADERS += ./hash_map-master/hash_map.h \
    lib/my_string.h \
    lib/test_my_string.h


