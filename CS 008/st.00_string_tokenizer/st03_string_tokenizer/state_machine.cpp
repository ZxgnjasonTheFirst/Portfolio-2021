#include "state_machine.h"

using namespace std;

//Fill all cells of the array with -1
void init_table(int _table[][MAX_COLUMNS]){
    for(int i = 0; i < MAX_ROWS; ++i){
        for(int j = 0; j < MAX_COLUMNS; ++j){
            _table[i][0] = 0;
            _table[i][j] = -1;
        }
    }
}

//Mark this state (row) with a 1 (success)
void mark_success(int _table[][MAX_COLUMNS], int state){
    _table[state][0] = 1;
}

//Mark this state (row) with a 0 (fail)
void mark_fail(int _table[][MAX_COLUMNS], int state){
    _table[state][0] = 0;
}

//true if state is a success state
bool is_success(int _table[][MAX_COLUMNS], int state){
    if(_table[state][0] == 1){
        return true;
    }
    else if(_table[state][0] == 0){
        return false;
    }
}

//Mark a range of cells in the array.
void mark_cells(int row, int _table[][MAX_COLUMNS], int from, int to, int state){
    for(int i = from; i <= to; ++i)
        _table[row][from] = state;
}

//Mark columns represented by the string columns[] for this row
void mark_cells(int row, int _table[][MAX_COLUMNS], const char columns[], int state){
    int i = 0;
    do{
        int ascii = columns[i];
        _table[row][ascii] = state;
        ++i;
    }while(columns[i] != '\0');
}

//Mark this row and column
void mark_cell(int row, int _table[][MAX_COLUMNS], int column, int state){
    _table[row][column] = state;
}

//This can realistically be used on a small table
void print_table(int _table[][MAX_COLUMNS]){
    for(int k = 0; k < 128 ; ++k){
        if(k < 100)
            cout<<setw(3)<<k;
        else
            cout<<setw(3)<<(k % 100);
    }
    cout<<endl;
    for(int i = 0; i < MAX_ROWS; ++i){
        for(int j = 0; j < MAX_COLUMNS; ++j){
            cout<<setw(3)<<_table[i][j];
        }
        cout<<endl;
    }
}

//show string s and mark this position on the string:
//hello world   pos: 7
//       ^
void show_string(char s[], int &_pos){
    cout<<s<<endl;
    for(int i = 0; i < _pos; i++)
        cout<<" ";
    cout<<"^"<<endl;


}

//Main part of program (HARDEST) extracts a token from a string.
bool get_token(char input[], int &pos,
                 int _table[][MAX_COLUMNS],
                 int start_state, string &token){ //START STATE IS WHICH ROW

    bool DEBUG = false; //set true for DEBUG

    string subst(input);
    int successpos = 0;
    bool success = false;
    int startpos = pos;
    int cellstate;
    int ascii = input[startpos];
    if(ascii < 0){
        cellstate = -1;
    }
    else
        cellstate = _table[start_state][ascii]; //decides whether or not the function will enter the while loop.


    if(DEBUG){
        cout<<"cellstate: "<<cellstate<<endl;
        show_string(input,pos);
    }

    while(input[pos] != '\0' && cellstate != -1){ //sees if the string has ended and whether or not the character is invalid
                                                  //in the machine.

        if(DEBUG)
            cout<<"THIS IS INPUT being considered in pos "<<pos<<" : "<<input[pos]<<endl;

        if(_table[cellstate][0] == 1){ //whether or not it is in a success state or not if it is in a success state once
                                       //it means that there is a token.

            if(DEBUG){
                cout<<"^^^^^^ IN SUCCESS STATE || In State: "<<cellstate<<endl;
            }

            successpos = pos; //records last successful position
            success = true;  //if it is in a success state once
                             //it means that there is a token.
        }
        else if (_table[cellstate][0] == 0){ //technically not neccessary but I use it for DEBUGGING

            if(DEBUG){
                cout<<"^^^^IN FAIL STATE || In State: "<<cellstate<<endl;
            }
//            success = false;
        }

        if(DEBUG){
            cout<<"Success during loop: "<<success<<endl;
            cout<<"==================================="<<endl;
        }

        ++pos;

        if(DEBUG)
            cout<<"++pos! pos: "<<pos<<endl;

        ascii = input[pos];                    //GETS THE ASCII VALUE OF THE CHARACTER IN POSITION
        cellstate = _table[cellstate][ascii];  //MOVES THE MACHINE TO THE NEXT STATE

        if(DEBUG){
            cout<<"Cell state: "<<cellstate<<endl;
            show_string(input, pos);
        }


    }

    if(DEBUG)
        cout<<"Success after loop: "<<success<<endl;

    if(!success){           //CHECKS IF THERE IS A VALID TOKEN.
        pos = startpos;     //IF YES, MOVE POSITION TO LAST SUCCESS POSITION + 1
        if(DEBUG){          //IF NOT AT ALL (NO SUCCESS STATE), RESET POSITION
            cout<<"Position at end:"<<pos<<endl;
            show_string(input, pos);
        }
    }
    else{
        pos = successpos + 1;
        if(DEBUG){
            cout<<"Position at end:"<<pos<<endl;
            show_string(input, pos);
        }
        token = subst.substr(startpos, abs(startpos - pos));
    }
        return success;
}


