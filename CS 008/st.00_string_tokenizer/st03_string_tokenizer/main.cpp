#include <iostream>
#include "stokenizer.h"
using namespace std;
void test_stokenizer();
/*
 * Name: Jason Pambuena
 * Project: stokenizer
 * Purpose: Uses a state machine to read a string inputted by a user and return each string with a
 * token (a part of the string) and the type of token (WORD NUMBER ALPHA etc)
 * Notes: **MAX_BUFFER must be > # of char you're passing in or else there is going to be MEMORY CORRUPTION.
 *
 * **IN EXTRACTION OPERATOR THE HIGHER THE MACHINE IS IN IF ELSE STATEMENT IT TAKES HIGHER PRIORITY WHICH
 * **MEANS THAT THE MACHINE WITH THE SAME TYPE OF CHARACTER AND MORE FAIL STATES WOULD NEED TO BE HIGHER
 * **IN STATEMENT. EXAMPLE: NUMBER VS I.P. ADDRESS.
 *
 */
int main()
{
    test_stokenizer();
    return 0;
}

void test_stokenizer(){
    char s[] = "I am smart.3.14+-=_."; //string that is being passed in.
    STokenizer stk(s);
    Token t;
    //The all too familiar golden while loop:
    stk>>t; //this takes the first token and enters the loop.
    while(stk.fail()){
        //process token here...
        cout<<setw(10)<<t.type_string()<<setw(10)<<t<<endl;


        t = Token(); //cleans up the token.
        stk>>t;
    }
}
