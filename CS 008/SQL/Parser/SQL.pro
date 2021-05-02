TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        ../../!include/File_Tokenizer/ftokenizer.cpp \
        ../../!include/Parse_Class/parse.cpp \
        ../../!include/Record_Class/record.cpp \
        ../../!include/SQL_Class/sql.cpp \
        ../../!include/State_Machine/state_machine.cpp \
        ../../!include/String_Tokenizer/stokenizer.cpp \
        ../../!include/String_Tokenizer/token.cpp \
        ../../!include/Table_Class/table.cpp \
        main.cpp

HEADERS += \
    ../../!include/Array_Funcs/array_funcs.h \
    ../../!include/BPlusTree_Class/bplustree_funcs.h \
    ../../!include/File_Tokenizer/ftokenizer.h \
    ../../!include/MPair_Class/mpair_class.h \
    ../../!include/Map_Class/map_class.h \
    ../../!include/MultiMap_Class/mmap_class.h \
    ../../!include/Pair_Class/pair_class.h \
    ../../!include/Parse_Class/parse.h \
    ../../!include/Record_Class/record.h \
    ../../!include/SQL_Class/sql.h \
    ../../!include/State_Machine/state_machine.h \
    ../../!include/String_Tokenizer/stokenizer.h \
    ../../!include/String_Tokenizer/token.h \ \
    ../../!include/Table_Class/table.h \
    z_output_main.h \
    z_work_report.h
