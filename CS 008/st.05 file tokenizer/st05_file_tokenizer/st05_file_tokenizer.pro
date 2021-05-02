TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp \
    ftokenizer.cpp \
    ../../st.00_string_tokenizer/st03_string_tokenizer/state_machine.cpp \
    ../../st.00_string_tokenizer/st03_string_tokenizer/stokenizer.cpp \
    ../../st.00_string_tokenizer/st03_string_tokenizer/token.cpp

HEADERS += \
    ftokenizer.h \
    ../../st.00_string_tokenizer/st03_string_tokenizer/state_machine.h \
    ../../st.00_string_tokenizer/st03_string_tokenizer/stokenizer.h \
    ../../st.00_string_tokenizer/st03_string_tokenizer/token.h
