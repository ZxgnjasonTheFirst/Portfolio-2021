#ifndef PARSE_H
#define PARSE_H
#include "/Users/zxgnj/Desktop/Bureau - MacBook Pro/CS 008/!include/Map_Class/map_class.h"
#include "/Users/zxgnj/Desktop/Bureau - MacBook Pro/CS 008/!include/MultiMap_Class/mmap_class.h"
#include "/Users/zxgnj/Desktop/Bureau - MacBook Pro/CS 008/!include/String_Tokenizer/stokenizer.h"
#include <stack>
#include <sstream>
#include <string>
enum keys{ZERO = 0, SELECT, MAKE, CREATE, INSERT, STAR, FROM, WHERE,
          SYMBOL, COMMA, OPERATOR, TABLE, FIELDS, VALUES, QUOTATION, ANDOR};


using namespace std;

class Parser
{
public:
    typedef Map<string, keys > map_sk;
    typedef MMap<string, string> mmap_ss;

    Parser();

    //set a new string as the input string
    void set_string(char str[]);
    Parser::mmap_ss &get_parse_tree();

    vector<string> ShuntingYard(const vector<string> tokens);



private:


    map_sk Keywords;
    mmap_ss parse_tree;

    int get_column(string str);

    //For shunting yard==============
    bool isOperand(const string &symbol);

    int priority(const string &c);

    bool isOperator(const string &c);
    //===============================

    //create table for all the tokens we will recognize
    //                      (e.g. doubles, words, etc.)
    void make_table(int _table[][MAX_COLUMNS]);

    //extract the longest string that match
    //     one of the acceptable token type.
    //---------------------------------
    vector<string> strvector;
    char _buffer[MAX_BUFFER];       //input string
    int _pos;                       //current position in the string
    static int parsetable[MAX_ROWS][MAX_COLUMNS];
};

#endif // PARSE_H
