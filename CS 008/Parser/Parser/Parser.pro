TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        ../../!include/Parse_Class/parse.cpp \
        ../../!include/State_Machine/state_machine.cpp \
        ../../!include/String_Tokenizer/stokenizer.cpp \
        ../../!include/String_Tokenizer/token.cpp \
        main.cpp

HEADERS += \
    ../../!include/Array_Funcs/array_funcs.h \
    ../../!include/BPlusTree_Class/bplustree_funcs.h \
    ../../!include/Linked_List_Stack_Queue_Class/linkedlistfuncs.h \
    ../../!include/Linked_List_Stack_Queue_Class/list.h \
    ../../!include/Linked_List_Stack_Queue_Class/queue.h \
    ../../!include/Linked_List_Stack_Queue_Class/stack.h \
    ../../!include/MPair_Class/mpair_class.h \
    ../../!include/Map_Class/map_class.h \
    ../../!include/MultiMap_Class/mmap_class.h \
    ../../!include/Pair_Class/pair_class.h \
    ../../!include/Parse_Class/parse.h \
    ../../!include/State_Machine/state_machine.h \
    ../../!include/String_Tokenizer/stokenizer.h \
    ../../!include/String_Tokenizer/token.h \
