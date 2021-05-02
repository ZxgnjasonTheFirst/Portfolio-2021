#include "token.h"

Token::Token():_token(""),_type(0){}

Token::Token(string str, int type){
    _token = str;
    _type = type;
}

ostream& operator <<(ostream& outs, const Token& t){
    outs<<"|"<<t._token<<"|";
    return outs;
}

int Token::type(){
    return _type;
}

string Token::type_string(){
    if(_type == TYPE_NUM){
        return "NUMBER";
    }
    else if(_type == TYPE_SPACE){
        return "SPACE";
    }
    else if(_type == TYPE_PUNC){
        return "PUNC";
    }
    else if(_type == TYPE_ALPHA){
        return "ALPHA";
    }
    else if(_type == TYPE_UNKNOWN){
        return "UNKNOWN";
    }
}

string Token::token_str(){
    return _token;
}
