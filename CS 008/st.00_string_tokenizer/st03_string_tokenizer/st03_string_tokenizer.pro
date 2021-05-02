TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp \
    state_machine.cpp \
    token.cpp \
    stokenizer.cpp \

HEADERS += \
    state_machine.h \
    token.h \
    stokenizer.h \
    z_output.h \
    z_work_report.h
