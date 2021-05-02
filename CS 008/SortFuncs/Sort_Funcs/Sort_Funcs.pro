TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp \
    ../../!include/Random_Class/random.cpp \

HEADERS += \
    ../../!include/Sort_Class/sort_funcs.h \
    z_output_main.h \
    z_work_report.h \
    ../../!include/Time_Class/time.h \
    ../../!include/Random_Class/random.h \
    ../../!include/Heap_Class/heap_class.h \
