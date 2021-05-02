#include "parse.h"


int Parser::parsetable[MAX_ROWS][MAX_COLUMNS];

Parser::Parser()
{
    make_table(parsetable);
}

void Parser::set_string(char str[]){
    STokenizer stk(str);
    Token t;
    vector<string> v;
//    cout<<"here: "<<endl;
    stk>>t;
    while(stk.fail()){
        if(t.type_string() != "SPACE"){
//            cout<<"this is t.token.str(): ["<<t.token_str()<<"]"<<endl;
            v.push_back(t.token_str());
        }
        t = Token();
        stk>>t;
    }
    strvector = v;
//    for (int i = 0; i < strvector.size(); ++i) {
//        cout<<"setstring strvector["<<strvector[i]<<"]"<<endl;

//    }
}

Parser::mmap_ss& Parser::get_parse_tree(){
    int cellstate = 0;
//    int column;
    bool success = false;
    vector<string> valuequotes;
    vector<string> selectwhere;
    for(int i = 0; i < strvector.size(); ++i){
//        cout<<"Parser::get_parse_tree: here is strvector: ["<<strvector[i]<<"]"<<endl;
        int column = get_column(strvector[i]);
        cellstate = parsetable[cellstate][column];
//        cout<<"This is cellstate: "<<cellstate<<endl;
        if (cellstate == -1){
            return parse_tree = mmap_ss();
        }
        if(cellstate == 1 || cellstate == 25 || cellstate == 50){
            parse_tree["COMMAND:"] += strvector[i];
        }
        if(cellstate == 2){
            parse_tree["STAR:"] += strvector[i];
        }
        if(cellstate == 10 || cellstate == 29){
            parse_tree["FIELDS:"] += strvector[i];
        }
        if(cellstate == 4 || cellstate == 27 || cellstate == 52){
            parse_tree["TABLE:"] += strvector[i];
        }
        if(cellstate == 5){
            parse_tree["WHERE:"] += strvector[i];
        }
        if(cellstate == 6){ //field after where.
            selectwhere.push_back(strvector[i]);
        }
        if(cellstate == 7){
            selectwhere.push_back(strvector[i]);
        }
        if(cellstate == 8){
            string selwherefull;
            selectwhere.push_back(strvector[i]);
            for(int i = 0 ; i < selectwhere.size(); ++i){
                selwherefull += selectwhere[i];
            }
            parse_tree["SELWHERE:"] += selwherefull;
            selectwhere = vector<string>();
        }
        if(cellstate == 9){
            parse_tree["SELWHERE:"] += strvector[i];
        }
        if(cellstate == 54){
            parse_tree["VALUES:"] += strvector[i];
        }
        if(cellstate == 15 || cellstate == 31 || cellstate == 61){
            valuequotes.push_back(strvector[i]);
        }
        if(cellstate == 16){ //SECOND QUOTES
            string fullvalue;
            string selwherefull;
            for (int i = 0; i < valuequotes.size(); ++i) {
                fullvalue += valuequotes[i];
                if(i != valuequotes.size() - 1){
                    fullvalue += " ";
                }
            }
            selectwhere.push_back(fullvalue);
            for(int i = 0 ; i < selectwhere.size(); ++i){
                selwherefull += selectwhere[i];
            }
            parse_tree["SELWHERE:"] += selwherefull;
            selectwhere = vector<string>();
            valuequotes = vector<string>();

        }
        if(cellstate == 32 || cellstate == 62){
            string fullvalue;
            for (int i = 0; i < valuequotes.size(); ++i) {
                fullvalue += valuequotes[i];
                if(i != valuequotes.size() - 1){
                    fullvalue += " ";
                }
            }
            parse_tree["VALUES:"] += fullvalue;
            valuequotes = vector<string>();
        }


    }
    return parse_tree;
}

int Parser::get_column(string str){
    Keywords[str] = SYMBOL;
    Keywords[""] = ZERO;
    Keywords["select"] = SELECT;
    Keywords["make"] = MAKE;
    Keywords["create"] = CREATE;
    Keywords["insert"] = INSERT;
    Keywords["*"] = STAR;
    Keywords["from"] = FROM;
    Keywords["where"] = WHERE;
    Keywords["into"] = WHERE;
    Keywords[","] = COMMA;
    Keywords[">="] = OPERATOR;
    Keywords["<="] = OPERATOR;
    Keywords["="] = OPERATOR;
    Keywords[">"] = OPERATOR;
    Keywords["<"] = OPERATOR;
    Keywords["table"] = TABLE;
    Keywords["fields"] = FIELDS;
    Keywords["values"] = VALUES;
    Keywords["\""] = QUOTATION;
    Keywords["and"] = ANDOR;
    Keywords["or"] = ANDOR;

//    cout<<"Parser::get_column: here is keywords["<<str<<"]: "<<Keywords[str]<<endl;
//    Keywords[" "] = SPACEBAR;

    return Keywords[str];
}

void Parser::make_table(int _table[][MAX_COLUMNS]){
    init_table(_table);

    mark_success(_table, 4);
    mark_success(_table, 8);
    mark_success(_table, 16);
    //+===============SELECT=================+
    mark_cell(0, _table, get_column("select"), 1);
    mark_cell(1, _table, get_column("*"), 2);
    //==================specific fields to select:
//    //With quotations.
//    mark_cell(1, _table, get_column("\""), 11);
//    mark_cell(11, _table, SYMBOL, 12);
//    mark_cell(12, _table, SYMBOL, 12);
//    mark_cell(12, _table, get_column("\""), 13);
//    mark_cell(13, _table, get_column(","), 1);
//    mark_cell(12, _table, get_column("from"), 3);
    //No quotations.
    mark_cell(1, _table, SYMBOL, 10);
    mark_cell(10, _table, get_column("from"), 3);
    mark_cell(10, _table, get_column(","), 11);
    mark_cell(11, _table, SYMBOL, 10);
    //==================
    mark_cell(2, _table, get_column("from"), 3);
    mark_cell(3, _table, SYMBOL, 4);
    mark_cell(4, _table, get_column("where"), 5);
    mark_cell(5, _table, SYMBOL, 6);
    mark_cell(6, _table, OPERATOR, 7);
    //With quotations.
    mark_cell(7, _table, get_column("\""), 14);
    mark_cell(14, _table, SYMBOL, 15);
    mark_cell(15, _table, SYMBOL, 15);
    mark_cell(15, _table, get_column("\""), 16);
    //"and/or"
    mark_cell(16, _table, ANDOR, 9);
    //No quotations.
    mark_cell(7, _table, SYMBOL, 8);
    //"and/or"
    mark_cell(8, _table, ANDOR, 9);
    mark_cell(9, _table, SYMBOL, 6);

    mark_success(_table, 29);
    mark_success(_table, 32);
    //+===============CREATE/MAKE=================+
    mark_cell(0, _table, get_column("create"), 25);
    mark_cell(0, _table, get_column("make"), 25);
    mark_cell(25, _table, get_column("table"), 26);
    mark_cell(26, _table, SYMBOL, 27);
    mark_cell(27, _table, get_column("fields"), 28);
//    //With quotations.
//    mark_cell(28, _table, get_column("\""), 30);
//    mark_cell(30, _table, SYMBOL, 31);
//    mark_cell(31, _table, SYMBOL, 31);
//    mark_cell(31, _table, get_column("\""), 32);
//    mark_cell(32, _table, get_column(","), 28);
    //No quotations.
    mark_cell(28, _table, SYMBOL, 29);
    mark_cell(29, _table, get_column(","), 28);

    mark_success(_table, 54);
    mark_success(_table, 62);
    //+===============INSERT=================+
    mark_cell(0, _table, get_column("insert"), 50);
    mark_cell(50, _table, get_column("into"), 51);
    mark_cell(51, _table, SYMBOL, 52);
    mark_cell(52, _table, get_column("values"), 53);
    mark_cell(53, _table, SYMBOL, 54);
    mark_cell(54, _table, get_column(","), 53);
    //With quotations.
    mark_cell(53, _table, get_column("\""), 60);
    mark_cell(60, _table, SYMBOL, 61);
    mark_cell(61, _table, SYMBOL, 61);
    mark_cell(61, _table, get_column("\""), 62);
    mark_cell(62, _table, get_column(","), 53);

}

vector<string> Parser::ShuntingYard(const vector<string> tokens){
    const bool debug = false;
    vector<string> outputList;//output vector **GOES IN COMMAND
    stack<string> s;//main stack

    //operator: +, -, *, /, ^, ()
    //operands: 1234567890
    for(unsigned int i = 0; i < tokens.size(); i++)  //read from right to left
    {
        if(debug)
            cout<<"NOW ON TOKEN["<<i<<"]: "<<tokens[i]<<endl;
        if(isOperand(tokens[i]))
        {
            outputList.push_back(tokens[i]);
        }
        if(isOperator(tokens[i]) == true)
        {
            while(!s.empty() && priority(s.top()) >= priority(tokens[i]))
            {
                outputList.push_back(s.top());
                s.pop();
            }
            s.push(tokens[i]);
        }
        if(tokens[i] == "\"")
        {
            s.push(tokens[i]);
        }
        if(tokens[i] == "\"")
        {
            while(!s.empty() && s.top() != "\"")
            {
                outputList.push_back(s.top());
                s.pop();
            }
            s.pop();
        }
    }
    //pop any remaining operators from the stack and insert to outputlist
    while(!s.empty())
    {
        outputList.push_back(s.top());
        s.pop();
    }
    if(debug){
        cout<<outputList<<endl;
    }
    return outputList;
}

bool Parser::isOperand(const string &symbol){
    return !isOperator(symbol);
}
int Parser::priority(const string &c){
    if(c == "and")
    {
        return 2;
    }
    if(c== "or")
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
bool Parser::isOperator(const string &c)
{
    return (c == "and" || c == "or");
}


