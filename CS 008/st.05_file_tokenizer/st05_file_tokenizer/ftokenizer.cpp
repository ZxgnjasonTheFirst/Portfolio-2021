#include "ftokenizer.h"

FTokenizer::FTokenizer(char* fname)
{
    _more = true;
    _f.open(fname);
    if(_f.fail()){
            cout<<"******File not found*****"<<endl;
            exit(0);
    }


}

Token FTokenizer::next_token(){
    Token t;
//    cout<<"HERE I AM"<<endl;
    if(_stk.done()){
        if(!get_new_block()){
            _more = false;
            return t;
        }
    }
    else
        _stk>>t;
//    cout<<"HERE I AM TOO"<<endl;
    return t;
}

bool FTokenizer::more(){ //returns the current value of _more
    return _more;
}

int FTokenizer::pos(){ //returns the value of _pos
    return _pos;
}

int FTokenizer::block_pos(){ //returns the value of _blockPos
    return _blockPos;
}

FTokenizer& operator >> (FTokenizer& f, Token& t){
    t = f.next_token();
    return f;
}

bool FTokenizer::get_new_block(){
    char _block[MAX_BLOCK+1];


//    cout<<"here"<<endl;
    _f.read(_block, MAX_BLOCK);
//    cout<<"here is gcount: "<<_f.gcount()<<endl;
    _block[_f.gcount()]='\0';
    _blockPos = MAX_BLOCK + 1;
    STokenizer str(_block);
    _stk = str;


    if(_f.gcount() > 0){
//        cout<<"get new block is true!"<<endl;
        return true;
    }
    else{
//        cout<<"get new block is false!"<<endl;
        return false;
    }
}
