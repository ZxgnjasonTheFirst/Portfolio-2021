TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp

HEADERS += \
    test_tree_funcs.h \
    test_bst.h \
    z_output_main.h \
    z_work_report.h \
    ../../!include/BST_Class/bst.h \
    ../../!include/BST_Class/tree_funcs.h \
    z_output_test_tree_funcs.h \
    z_output_test_bst.h
