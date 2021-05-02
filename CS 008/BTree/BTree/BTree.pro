TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp \

HEADERS += \
    ../../!include/BTree_Class/btree_funcs.h \
    ../../!include/Array_Funcs/array_funcs.h \
    ../../!include/Map_Class/map_class.h \
    ../../!include/MultiMap_Class/mmap_class.h \
    ../../!include/Pair_Class/pair_class.h \
    ../../!include/MPair_Class/mpair_class.h \
    z_output_main.h \
    z_work_report.h
