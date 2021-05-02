#include "stokenizer.h"

int STokenizer::_table[MAX_ROWS][MAX_COLUMNS];

//Default CTOR
STokenizer::STokenizer(){
//    _buffer = new char[MAX_BUFFER]();
    for(int i = 0 ; i < MAX_BUFFER; ++i){
        _buffer[i] = 0;
    }
    init_table(_table);
    _pos = 0;
}

//-- big three -- <---- DO NOT NEED
//STokenizer::~STokenizer(){
//    _pos = 0;
//    delete [] _buffer;

//}

//CTOR
STokenizer::STokenizer(char str[]){
    for(int i = 0 ; i < MAX_BUFFER; ++i){
        _buffer[i] = 0;
    }
    make_table(_table);
    set_string(str);
    _pos = 0;
}

//STokenizer& STokenizer::operator=(const STokenizer& rhs){
//    if(this != &rhs){
//        delete [] _buffer;
//        _pos = 0;
//        _buffer = new char [MAX_BUFFER]();
//        for(int i = 0; i < MAX_BUFFER; ++i){
//            _buffer[i] = rhs._buffer[i];
//        }
//        _pos = rhs._pos;
//    }
//    return *this;
//}
//---------------

bool STokenizer::done(){ //true: there are no more tokens
    return _pos > strlen(_buffer);

}

bool STokenizer::fail(){ //true: there are more tokens
    return !done();
}

//extract one token (very similar to the way cin >> works)

STokenizer& operator >> (STokenizer& s, Token& t){ //**ORDER MATTERS** THE HIGHER LVL IT IS IN IF ELSE
    string token;                                  //**STATEMENT THE MORE STATES IT SHOULD HAVE
    int type = -1;                                 //**EXAMPLE: I.P. ADDRESS VS NUMBER

//    cout<<"HERE I AM THREE"<<endl;
    if(s.get_tokens(START_NUM, token))
        type = TYPE_NUM;
    else if(s.get_tokens(START_SPACE, token))
        type = TYPE_SPACE;
    else if(s.get_tokens(START_PUNC, token))
        type = TYPE_PUNC;
    else if(s.get_tokens(START_ALPHA, token))
        type = TYPE_ALPHA;
    else{
        token = s._buffer[s._pos];
        ++s._pos;
        type = TYPE_UNKNOWN;
    }
//    cout<<"HERE I AM FOUR"<<endl;
    Token tok(token, type);
    t = tok;
    return s;

}

//set a new string as the input string
void STokenizer::set_string(char str[]){
    for(size_t i = 0; i < strlen(str); ++i){
        _buffer[i] = str[i];
    }
}

//create table for all the tokens we will recognize
//                      (e.g. doubles, words, etc.)
void STokenizer::make_table(int _table[][MAX_COLUMNS]){
    init_table(_table);

//    print_table(table);
//    cout<<endl;

    //doubles:
    mark_fail(_table, 0);            //Mark states 0 and 2 as fail states

    mark_success(_table, 1);         //Mark states 1 and 3 as success states
    mark_fail(_table, 2);
    mark_success(_table, 3);


    mark_success(_table, 5);        //Marks states 5, 10, 15 as success states
    mark_success(_table, 10);       //(SPACE, PUNC, & ALPHA respectively)
    mark_success(_table, 15);

//    cout<<endl;
//    print_table(table);
//    cout<<endl;

    //DIGITS AND '.' STATE MACHINES
    mark_cells(0, _table, DIGITS, 1);    //state [0] --- DIGITS ---> [1]
    mark_cells(1, _table, DIGITS, 1);    //state [1] --- DIGITS ---> [1]
    mark_cells(1, _table, '.', '.', 2);  //state [1] --- '.' ------> [2]
    mark_cells(2, _table, DIGITS, 3);    //state [2] --- DIGITS ---> [3]
    mark_cells(3, _table, DIGITS, 3);    //state [3] --- DIGITS ---> [3]
    //SPACE
    mark_cells(5, _table, SPACE, 5);
    //PUNC
    mark_cells(10, _table, PUNC, 10);
    //ALPHA
    mark_cells(15, _table, ALPHA, 15);

//    cout<<endl;
//    print_table(_table);           //PRINT TABLE **WARNING HARD ON THE EYES** (COMMAND+'-' TO ZOOM OUT)
//    cout<<endl;

}

//extract the longest string that match
//     one of the acceptable token types
bool STokenizer::get_tokens(int start_state, string& token){
    return get_token(_buffer, _pos, _table, start_state, token);
}
